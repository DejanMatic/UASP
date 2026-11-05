#include <iostream>
#include <vector>

int f(const std::vector<int> &a, const std::vector<int> &b)
{
    int brojac = 0, suma_a = 0, suma_b = 0;

    int n = a.size();

    for (int i = 0; i < n; i++) {
        suma_a += a[i];
        suma_b += b[n - 1 - i];
        if (suma_a == suma_b) {
            brojac++;
        }
    }

    return brojac;
}

int main ()
{
    // std::vector<int> a = {1, 2, 5, 6, 3, 7};
    // std::vector<int> b = {9, 3, 4, 7, 3, 0};
    std::vector<int> a = {7, 8, 3, 1, 2, 5};
    std::vector<int> b = {4, 3, 1, 5, 4, 9};

    std::cout << f(a, b) << "\n";
    return 0;
}