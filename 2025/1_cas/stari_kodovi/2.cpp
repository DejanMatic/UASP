#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main ()
{
    std::vector<int> a = {1,2,3,4,5};
    
    std::cout << std::accumulate(a.begin(), a.end(), a[0], [](int acc, int x){ return acc < x ? acc : x; }) << "\n";

    return 0;
}