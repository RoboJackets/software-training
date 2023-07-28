## Class Structure

**You will be using proper_structure.cpp in `/src` and proper_structure.hpp in `/include`**

C++ and Java have probably looked pretty similar up until this point. While the synax of the two languages are
quite similar, the format of them is not. Up until now we have simply used a bad-practice form of C++ for simplicity.

While Java simply has a single `.java` file for every class, C++ works a little different. In order to squeeze every ounce of performance
out of compilation, C++ forces you to use two files for a class: `.cpp` and `.hpp`

### Header or `.hpp` files define what class is. They contain...
- Actual class definition
- Public/private assignments
- The names, parameters, and return types of all functions
- Any member variables

### `.cpp` files define what a class can do. They contain...
- The actual code associated with all functions declared in the header


In addition to `.hpp` and `.cpp` files, classes should be bundled in a namespace to prevent potential issues when using multiple classes at once.
Imagine a situation where you have two functions representing getting a number in two different places, both defined as `getNum()`. If you call `getNum()`,
your compiler won't be able to resolve which one you are talking about.

Namespaces are a way of resolving this error, and work similar to the concept of modules seen in languages like Python and Java. Instead of the same function
name being duplicated, you would have `namespace1::getNum()` and `namespace2::getNum()` to choose from.

Namespaces are best practice even when not necessary in C++. You should normally wrap everything in your header file in a namespace for that specific class.


#### 1. Add another parameter `int num3` to the constructor and as a `private` member variable. Remember all the places to update the code!

#### 2. Write a function to find the largest out of `num1`, `num2`, and `num3`

#### 3. Write a function taking in an `int <param_name>` that returns a `std::vector` of all numbers `<= <param_name>` that are divisible by 4 or 9

#### 4. Write a function to return whether or not `num1`, `num2`, or `num3` are prime