#include <iostream>
#include <vector>

void foo(int *x) {
    *x = 23;
}

void bar(int &x) {
    x = 12;
}

void vector_reference(std::vector<int> &a)
{
    // for (int x : a) {
    //     x = 23; // <=> x' = 23
    //     // std::cout << x << " ";
    // }
    // std::cout << "\n";

    for (int i = 0; i < a.size(); i++) {
        a[i] = 23; // <=> *(a + i) = 23
    }
}

int main ()
{
    // int x = 42;

    // bar(x);

    // std::cout << x << "\n";

    // int x = 42;

    // int y = 23;

    // // OVO MOZE
    // int *p = &x;
    // std::cout << *p << "\n";
    // p = &y;
    // std::cout << *p << "\n";

    // // OVO NE MOZE
    // int &q = x;
    // q = y;

    std::vector<int> a(10, 42);

    vector_reference(a);

    for (int x : a) {
        std::cout << x << " ";
    }
    std::cout << "\n";


    return 0;
}