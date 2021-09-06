# learning-cpp

## __Repository For Learning C++__

### __<ins>0: Basics:</ins>__
* _Copy\_Elision.cpp:_ Copy elision refers a compiler optimization technique that eliminates unnecessary copying of objects. As defined by cppreference.com, copy elision omits copy and move constructors, resulting in zero-copy pass-by-value semantics.
* _Default\_Constructor.cpp:_ This example includes explicitly defaulted no-arg and copy constructors. Another constructor (single-arg constructor) exists, therefore, for `Test` class `Test::Test()` needs to be implemented or declared explicitly.
* _Functions\_Auto.cpp:_ This example demostrates `decltype` can replace the return type of a function when the return type of some other function is known. Also, it is possible to replace the return type of a function with `auto` and the return type can be specified using arrow operator `->` after specifying the function input parameter list.
* _Initializer\_List.cpp:_ From standard C++ library, `std::initializer_list` can be used to provide a set of values that can further be used to initialize an array, vector or other data structure that is a private or public member of a class.
* _Static\_Members.cpp:_ Demonstrates the usage of a `static` member in a class. As an example, it is good to visualize the usage of a static member in the presence of delegating constructors to see how many times the constructors are called and how the value of a static member varies accordingly.
* _Types.cpp:_ Usage of `typeid` from `<typeinfo>` header. Also includes the usage of `decltype` as well.

### __<ins>1: Exceptions:</ins>__
* _01-Exception-Basics.cpp:_ Catching the error based on the type of the variable (`int`, `const char*` or `std::string`) in a function whenever the function is called.
* _02-Standard-Exceptions.cpp:_ Standard exceptions are derived from `std::exception` base class that has virtual class functions. Each derived standard exception class (`std::bad_alloc` in this example) has already implemented virtual `what()` function. A custom exception class that inherits from `std::exception` can be created and virtual member functions can be implemented.
* _03-Custom-Exception.cpp:_ Custom exception class that inherits from `std::exception` can be implemented.
* _04-Exception-Catch-Order.cpp:_ Exception catch order is important. The order should follow for proper error throw: First, throw exception classes that are derived from the base class (`std::exception` in this case). Then, `std::exception` must be thrown. There could be a problem throwing the correct exception due to the fact that there is a polymorphic relationship between derived exception class and base `std::exception` class.

### __<ins>2: Files:</ins>__
* 01-Writing-to-Files:
    * _test.cpp:_ Creates and opens a text file using `std::ofstream`. Writes a basic string and an integer to the file.
    * _stream\_test.cpp:_ Switched from `std::ofstream` to `std::fstream`. This is basically the same thing if an extra argument (`std::ios::out`) to the `open()` function.
* 02-Writing-Example:
    * _test.cpp:_ Given the number of lines `N`, a text file is created and opened. Integer numbers starting from `1` to `N` are written to the text file.
* 03-Reading-Text-Files:
    * _test.cpp:_ A file can be read using `std::fstream` along with passing `std::ios::in` to the `open()` function. When the file is open (can be checked via `is_open()` function), a `while` loop can be used to read the file content into a `std::string`. The termination condition for the while loop is the end of the file flag (EOF). It can be checked via `eof()` function.
* 04-Parsing-Text-Files:
    * _parse.cpp:_ `std::getline` can be used to read a line from a file. A delimiter can also be passed into the getline function to separate different entities such as a `std::string` and an integer. To discard the newline character, `std::ws` can be used.
* 05-Struct-Padding:
    * _test.cpp:_ A pragma preprocessor can be used to align the data with byte boundaries. If the data is stored in a `struct`, that particular struct implementation is surrounded by the `#pragma` directive in order to prevent struct padding. This example writes data to a file in binary by OR-ing `std::ios::binary | std::ios::out` in `open()` function. To check if everything is correct, the file is read afterwards. Also, this example demonstrates a C++20 style "designated initializers" when initializing a struct.

### __<ins>3: STL:</ins>__
* 01-Vectors:
    * _test.cpp:_ Tests the very basic usage of a `std::vector` with `push_back()` function. Displays the content using a iterator-based for loop.
    * _vector\_sort.cpp:_ A test class implemented with a `std::string` that holds a name, and an integer for ID. Uses `emplace_back()` to call the class constructor directly and pushes objects into the vector. The with `std::sort()` function, the objects are sorted. A `printVector()` function is used to display the vector content using a range-based for loop. The sorting is basically done in accordance with the alphabetical order in the `std::string` member variable.
    *_vector\_sort\_fp.cpp:_ A different version of _vector\_sort.cpp:_ example where a function pointer is passed to `std::sort()` function. This example sorts the vector data based on the ID member variable.
* 02-Vector-Capacity:
    * _test.cpp:_ An example showing how the vector capacity changes when new elements are added to the vector. Showing example usage and differences between `V.size()`, `V.capacity()` and `sizeof(V)` functions. Also, it is possible to discard vector elements using `V.resize()` function. Final remark is that the vector capacity can initially be set using `V.reserve()` function, thus, up until that much size, the vector is constantly be filled. When the vector capacity is reached to the maximum, new capacity is set to the twice of the original vector capacity.
* 03-2D-Vectors:
    * _test.cpp:_ Demonstrates how to implement a M-by-N matrix using a vector of vectors.
* 04-List-Basics:
    * _test.cpp:_ Demonstrates how to use `std::list` which is a container that supports constant time insertion and removal of elements from anywhere in the container.
* 05-Map-Basics:
    * _test.cpp:_ A map is an associative container that containes sorted key-value pairs with unique keys. This is a simple example showing how to use `std::map`. It is possible to use `find()` function to return an iterator to an element equivalent to key. When not found, the result is `.end()` iterator. Also, an element can be inserted to a map using `std::pair<A, B>` and `insert()` function. An alternative to this is to use `std::make_pair()` function that can directly insert a pair into the map.
    * _custom\_objects.cpp:_ A class object can be `value` in the map.
    * _custom\_objects\_2.cpp:_ A class object can be `value` in the map. Here, it is possible to overload comparison operator (`operator<`) to make a suitable ordering for key values in the map that are of `string` variable in `Person` class. Although the names are the same, since the ages are different, then the keys are also different.
    * _multimap\_test.cpp:_ Multimap is also an associative container with a sorted key-value pairs. It permits multiple entries with the same key.
    * _cdt\_test.cpp:_ An example program for testing complex data types as key and/or value pairs. Here, key is of `std::string` while value is of `std::vector<int>`.
* 06-Sets:
    * _set_test.cpp:_ A simple example program for `std::set`. A set is a container that contains a sorted unique objects or values of type `T`.
* 07-Stacks-and-Queues:
    * _test.cpp:_ Important to know that Stack = LIFO and Queue = FIFO. Stacks are not iterable. Last added value should be popped out of the container using `pop()` function. Adding an element is done via `push()` function. Also, a reference to the topmost element in the stack can be returned by calling `top()` function. Once the topmost element is popped from the stack, the reference variable to that element is invalidated.