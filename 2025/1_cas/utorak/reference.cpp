#include <iostream>
#include <vector>

// void foo(const std::vector<int> &a) {
//     a[0] = 10;
// }

void f(int *p) {
    *p = 23;
    std::cout << *p << "\n";
    std::cout << "f: " << p << "\n";

}

void g(int x) {
    x = 23;
    std::cout << &x << "\n";
}

void h(int &x) {
    x = 100;

    // NEMA REASSIGN-a NAD REFERENCOM!!!
    // int y = 200;
    // x = &y;
}

int main ()
{
    int x = 42;

    g(x);

    std::cout << "main: " << &x << "\n";

    f(&x);

    std::cout << x << "\n";

    h(x);

    std::cout << x << "\n";


    int y = 100;
    int *p = &x;
    p = &y;

    return 0;
}