#include <iostream>
#include <vector>

int main ()
{
    int n = 10;

    std::vector<int> niz(n);

    for (int i = 0; i < n; i++) {
        niz[i] = i + 1;
    }

    // 1. nacin
    // for (int i = 0; i < 10; i++) {
    //     std::cout << niz[i] << " ";
    // }
    // std::cout << "\n";

    // 2. nacin
    // for (int x : niz) {
    //     std::cout << x << " ";
    //     x = 23;
    // }
    // std::cout << "\n";

    std::vector<int>::iterator begin = niz.begin();
    std::vector<int>::iterator end = niz.end();

    while (begin != end) {
        std::cout << *begin << " ";
        begin++;
    }
    std::cout << "\n";

    // DODATNO
    // int *p = (*begin);

    auto rbegin = niz.rbegin();
    auto rend = niz.rend();

    while (rbegin != rend) {
        std::cout << *rbegin << " ";
        rbegin++;
    }
    std::cout << "\n";

    n = niz.size();

    std::vector<int> a(10);

    for (int i = 0; i < n; i++) {
        // std::cin >> a[i];
        // a[i] = i + 1;
        a.push_back(i + 1);
    }

    return 0;
}