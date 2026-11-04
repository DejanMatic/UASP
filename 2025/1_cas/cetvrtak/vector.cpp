#include <iostream>
#include <vector>

int main ()
{
    int n = 10;

    std::vector<int> a(n);

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        // std::cin >> a[i];
    }

    std::cout << a.size() << "\n";

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

    // 3. nacin
    // auto begin = a.begin();
    // auto end = a.end();

    // while (begin != end) {
    //     std::cout << *begin << " ";
    //     begin++;
    // }
    // std::cout << "\n";

    // auto rbegin = a.rbegin();
    // auto rend = a.rend();

    // while (rbegin != rend) {
    //     std::cout << *rbegin << " ";
    //     rbegin++;
    // }
    // std::cout << "\n";

    std::vector<int> b;

    for (int i = 0; i < n; i++) {
        b.push_back(i + 1);
    }

    for (int x : b) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    std::cout << b.front() << " " << b.back() << "\n";

    std::cout << b.max_size() << "\n";

    std::vector<int> c;
    std::vector<float> d;
    std::vector<double> e;
    std::vector<long long> f;
    std::vector<short> g;

    std::cout << c.max_size() << "\n";
    std::cout << d.max_size() << "\n";
    std::cout << e.max_size() << "\n";
    std::cout << f.max_size() << "\n";
    std::cout << g.max_size() << "\n";

    return 0;
}