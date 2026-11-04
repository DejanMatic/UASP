#include <iostream>

void f(int *x) {
    *x = 23;
    std::cout << "f: " << *x << "\n";
}

// REFERENCE NE SMEJU I NE MOGU DA SE REASSIGNUJU (PREUSMERAVAJU)
void g(int &x) {
    x = 23;
    std::cout << "g: " << x << "\n";
}

int main ()
{
    int x = 42;
    int y = 23;

    // std::cout << "main: " << &x << "\n";

    // f(&x);

    g(x);

    std::cout << "main: " << x << "\n";

    int *p = &x;
    p = &y;

    return 0;
}