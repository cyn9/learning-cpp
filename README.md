# learning-cpp

### __Repository For Learning C++__


__++1: Exceptions:++__
* _01-Exception-Basics.cpp:_ Catching the error based on the type of the variable (`int`, `const char*` or `std::string`) in a function whenever the function is called.
* _02-Standard-Exceptions.cpp:_ Standard exceptions are derived from `std::exception` base class that has virtual class functions. Each derived standard exception class (`std::bad_alloc` in this example) has already implemented virtual `what()` function. A custom exception class that inherits from `std::exception` can be created and virtual member functions can be implemented.
