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
