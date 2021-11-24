#include <iostream>

struct JustThreeChars {
    char c1 = 0;
    char c2 = 0;
    char c3 = 0;
};

struct Foo {
    char c = 0;
    // padding
    int i = 0;
};

struct Bar {
    int i = 0;
    char c = 0;
    // padding
};

int main() {
    std::cout << sizeof(JustThreeChars) << " " << alignof(JustThreeChars)
              << "\n";

    Foo f;
    std::cout << sizeof(Foo) << " " << sizeof(f.c) << " " << sizeof(f.i)
              << "\n";
    std::cout << alignof(Foo) << " " << alignof(f.c) << " " << alignof(f.i)
              << "\n";
    std::cout << static_cast<void *>(&f.c) << "\n";
    // std::cout << &f.c << "\n";
    std::cout << &f.i << "\n";

    // For arrays
    static_assert(sizeof(Foo) % alignof(Foo) == 0);
    static_assert(sizeof(Bar) % alignof(Bar) == 0);

    std::cout << sizeof(Bar) << "\n";
    Bar b[2];
    std::cout << &b[0].i << "\n";
    std::cout << static_cast<void *>(&b[0].c) << "\n";
    std::cout << &b[1].i << "\n";
    std::cout << static_cast<void *>(&b[1].c) << "\n";
}
