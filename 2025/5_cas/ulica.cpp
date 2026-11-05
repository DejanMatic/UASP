#include <iostream>
#include <vector>
#include <algorithm>

int main ()
{
    int n, k;

    std::cin >> n >> k;

    std::vector<int> a(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    int l = 0, r = k - 1;

    int res = std::numeric_limits<int>::max();

    while (r < n) {
        res = std::min(res, a[r] - a[l]);
        l++;
        r++;
    }

    std::cout << res << "\n";

    return 0;
}