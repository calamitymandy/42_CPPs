# 42_CPPs

## CPP 02
### Ex00:

1. OCF stands for Orthodox Canonical Form (also called Canonical Class Form in C++).
It’s a standard structure that every well-designed C++ class should follow when it manages resources or data that need proper copying or destruction.

It defines four special member functions that together ensure your class behaves correctly in all situations.

| Function                     | Purpose                                                         | When It’s Called                                                          |
| ---------------------------- | --------------------------------------------------------------- | ------------------------------------------------------------------------- |
| **Default Constructor**      | Initializes a new object with default values.                   | When you write `Fixed a;`                                                 |
| **Copy Constructor**         | Creates a new object as a copy of another one.                  | When you write `Fixed b(a);` or `Fixed b = a;`                            |
| **Copy Assignment Operator** | Replaces the contents of an existing object with another one’s. | When you write `c = b;`                                                   |
| **Destructor**               | Cleans up before the object is destroyed.                       | When the object goes out of scope (end of program, end of function, etc.) |
