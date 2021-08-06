// Ring buffer implementation.

#include <iostream>
#include <string>

template <typename T>
class Ring {
    private:
        int m_currentPos;
        std::size_t m_size;
        T *m_container;
    
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
};

template <typename T> void printRingBuffer(const Ring<T> &);

int main() {
    Ring<std::string> ring_test(4);

    ring_test.add("one");
    ring_test.add("two");
    ring_test.add("three");
    ring_test.add("four");
    ring_test.add("five");

    printRingBuffer(ring_test);

    return 0;
}

template <typename T>
void printRingBuffer(const Ring<T> &buffer) {
    for (auto i = 0; i < buffer.getSize(); ++i) {
        std::cout << i+1 << ": " << buffer.get(i) << std::endl;
    }
}
