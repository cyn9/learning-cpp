# learning-cpp

## __Repository For Learning C++__

### __<ins>1: Exceptions:</ins>__
* _01-Exception-Basics.cpp:_ Catching the error based on the type of the variable (`int`, `const char*` or `std::string`) in a function whenever the function is called.
* _02-Standard-Exceptions.cpp:_ Standard exceptions are derived from `std::exception` base class that has virtual class functions. Each derived standard exception class (`std::bad_alloc` in this example) has already implemented virtual `what()` function. A custom exception class that inherits from `std::exception` can be created and virtual member functions can be implemented.
* _03-Custom-Exception.cpp:_ Custom exception class that inherits from `std::exception` can be implemented.
* _04-Exception-Catch-Order.cpp:_ Exception catch order is important. The order should follow for proper error throw: First, throw exception classes that are derived from the base class (`std::exception` in this case). Then, `std::exception` must be thrown. There could be a problem throwing the correct exception due to the fact that there is a polymorphic relationship between derived exception class and base `std::exception` class.

### __<ins>2: Files:</ins>__
* _01-Writing-to-Files 
    * _test.cpp:_ Creates and opens a text file using `std::ofstream`. Writes a basic string and an integer to the file.
    * _stream\_test.cpp:_ Switched from `std::ofstream` to `std::fstream`. This is basically the same thing if an extra argument (`std::ios::out`) to the `open()` function.
