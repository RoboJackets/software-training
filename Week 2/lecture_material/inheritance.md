## Inheritance

**You will be using inheritance.cpp in `/src`**

Like Java, C++ also has the ability to inherit from a base class to cut down on code reuse
and help make your code more modular.

The syntax for this is a `class Child : Parent1, Parent2, ...`

However, C++'s classes are much more rough around the edges. They offer dangerous features like the ability to inherit from multiple parents, the ability to completely
ignore polymorphism by not using the `virtual` keyword, and have no formal concept
abstract classes or interfaces. 

Despite this, you can still make abstract classes in C++. Simply preface the function
with `virtual` and append a `= 0` to the end. This can be seen in `Animal`'s `getNumberOfLegs()` function. **These functions must be overriden in children, and the base class can no longer be instantiated!**

#### 1. Try uncommenting out line 27 and running

#### 2. Why does this not work?

#### 3. Run the file normally, verify that the output makes sense

#### 4. Notice that despite the `Moose` object on line 29 getting no params, it still defaults to a specific leg value. Why is this?

#### 5. Write a function to get the number of antlers times the number of legs

#### 6. Verify your function works by printing the number in main like is currently done on line 30 with the number of legs

