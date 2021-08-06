// Ring buffer implementation with nested template classes
// that are iterable.

#include <iostream>
#include <string>

template <typename T>
class Ring {
    private:
        int m_currentPos;
        std::size_t m_size;
        T *m_container;
    
    public:
        class iterator;

    public:
        Ring() : Ring(0) {}
        Ring(std::size_t size) : m_currentPos {0}, 
                                 m_size {size}, 
                                 m_container {nullptr} {
            // Make sure the container is empty.
            assert(m_container == nullptr);
            m_container = new T[m_size];
        }

        ~Ring() { delete[] m_container; }
    
        std::size_t getSize() const { return this->m_size; }

        void add(T t) {
            m_container[m_currentPos++] = t;
            
            if (m_currentPos == m_size) {
                m_currentPos = 0;
            }
        }

        T& get(std::size_t pos) const {
            return m_container[pos];
        }

        // Iterator functions:
        // Pass this pointer to convey the Ring class reference.
        iterator begin() { return iterator(0, *this); }
        iterator end()   { return iterator(m_size, *this); }
};

template <typename T> 
class Ring<T>::iterator {
    private:
        std::size_t m_iterPos;
        Ring &m_ring;

    public:
        iterator(std::size_t pos, Ring &buf) : m_iterPos{pos}, m_ring{buf} {}

        // Overloading postfix operator
        iterator & operator++() { 
            m_iterPos++;
            return *this;
        }

        // Overloading prefix operator
        iterator & operator++(int) { 
            m_iterPos++;
            return *this;
        }

        // Overloading dereferencing operator
        T & operator*() const {
            return m_ring.get(m_iterPos);
        }

        // Overloading not-equals operator
        bool operator!=(const iterator &rhs) const {
            return m_iterPos != rhs.m_iterPos;
        }
};

template <typename T> void printRingBuffer(const Ring<T> &);

int main() {
    Ring<std::string> ring_test(4);

    ring_test.add("one");
    ring_test.add("two");
    ring_test.add("three");
    ring_test.add("four");
    ring_test.add("five");

    // Print with the classic for loop:
    printRingBuffer(ring_test);

    std::cout << '\n';

    // Print with iterators:
    for (Ring<std::string>::iterator it = ring_test.begin(); it != ring_test.end(); ++it) {
        std::cout << *it << '\n';
    }

    std::cout << std::endl;

    // Print with range-based for loop:
    for (const auto &e: ring_test) {
        std::cout << e << '\n';
    }
    
    return 0;
}

template <typename T>
void printRingBuffer(const Ring<T> &buffer) {
    for (auto i = 0; i < buffer.getSize(); ++i) {
        std::cout << i+1 << ": " << buffer.get(i) << '\n';
    }
}
