#include <iostream>

// Order:
// 1. Name resolution. Output: "overload set".
// 2. Overload resolution. Output: a single overload.
// 3. Access check.
// 4. Call, can be virtual or non-virtual.

struct Base {
    void foo() {
        std::cout << "no args\n";
    }
    void foo(int) {
        std::cout << "int\n";
    }
};

struct Derived : Base {};

struct SubDerived : Derived {
    void foo(double) {
        std::cout << "double\n";
    }

    // Will hide, no compilation error.
    // void foo(int) { std::cout << "SubDerived int\n"; }

    // Introduce members of Base/Derived called 'foo' into the definition.
    // using Derived::foo;
    // using Base::foo;
};

struct SubSubDerived : SubDerived {  // Has the same overloads as Derived
};

int main() {
    Base b;
    b.foo(1);    // int
    b.foo(1.2);  // int
    b.foo();     // no args

    SubDerived sd;
    sd.foo(1.2);  // double
    sd.foo(1);    // double :(
    sd.foo();     // compilation error?
    // Rule: if the derived class has a method called `foo`, do not look at
    //       base's methods, "hide" them.

    Derived &d = sd;
    d.foo(1);    // int
    d.foo(1.2);  // int
}