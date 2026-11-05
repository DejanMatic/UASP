#include <iostream>
#include <vector>
#include <algorithm>

void print(int x) {
    std::cout << x << " ";
}

// int compare(int x) {
//     return x > y;
// }

int main ()
{
    std::vector<int> a = {1,2,3,4,5,6,7,8,9,10};

    // std::for_each(a.begin() + 2, a.end() - 3, print); // [)

    // std::for_each(a.begin() + 2, a.end() - 3, [](int x) {
    //     std::cout << x << " ";
    // }); // [)

    // auto it = std::max_element(a.begin(), a.end());

    // std::cout << (it - a.begin()) << "\n";


    // it = std::min_element(a.begin(), a.end());

    // std::cout << (it - a.begin()) << "\n";

    // int counter = std::count(a.begin(), a.end(), 2);

    // int counter = std::count_if(a.begin(), a.end(),
    // [](int x){ return x % 2 != 0; });

    // std::cout << counter << "\n";

    // auto it = std::find(a.begin(), a.end(), 2);

    // if (it != a.end()) {
    //     std::cout << *it << "\n";
    // }
    // else {
    //     std::cout << "Element ne postoji!\n";
    // }

    // int y = 7;

    // auto it = std::find_if(a.begin(), a.end(),
    // [y](int x){ return x > y; });

    // std::cout << *it << " " << y << "\n";

    // a.erase(std::remove(a.begin(), a.end(), 2), a.end());

    // std::for_each(a.begin(), a.end(), print);

    // a.erase(std::remove_if(a.begin(), a.end(),
    // [](int x){ return x % 2 == 0; }), a.end());

    // std::for_each(a.begin(), a.end(), print);

    auto it = std::lower_bound(a.begin(), a.end(), 4); // >= 4

    std::cout << *it << "\n";

    it = std::upper_bound(a.begin(), a.end(), 4); // > 4

    std::cout << *it << "\n";

    return 0;
}