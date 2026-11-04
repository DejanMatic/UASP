#include <iostream>
#include <vector>

int main ()
{
    int n = 10;

    std::vector<int> a(n);

    // 1. nacin
    // for (int i = 0; i < n; i++) {
    //     std::cout << a[i] << " ";
    // }
    // std::cout << "\n";

    // 2. nacin
    // for (int x : a) {
    //     std::cout << x << " ";
    // }
    // std::cout << "\n";

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    // 3. nacin
    auto begin = a.begin();
    auto end = a.end();
    end--;
    std::cout << *end << "\n";

    while (begin != a.end()) {
        std::cout << *begin << " ";
        begin++;
    }
    std::cout << "\n";


    auto rbegin = a.rbegin();
    auto rend = a.rend();

    while (rbegin != rend) {
        std::cout << *rbegin << " ";
        rbegin++;
    }
    std::cout << "\n";


    std::cout << a.size() << "\n";

    std::cout << a.capacity() << "\n";

    std::vector<int> b(n);
    std::vector<float> c(n);
    std::vector<double> d(n);

    std::cout << b.max_size() << "\n";
    std::cout << c.max_size() << "\n";
    std::cout << d.max_size() << "\n";

    std::vector<int> niz;

    for (int i = 0; i < n; i++) {
        // std::cin >> niz[i]; // Ovo ne moze ako nije alociran prostor

        // Ovo realocira memmoriju ako je potrebno i smesta element na kraj niza
        niz.push_back(i + 1);
    }

    for (int x : niz) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}