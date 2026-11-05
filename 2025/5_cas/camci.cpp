#include <iostream>
#include <vector>
#include <algorithm>

int camci(std::vector<int> &a, int x)
{
    std::sort(a.begin(), a.end());

    int i = 0, j = a.size() - 1, br = 0;

    while (i <= j) {
        if (i == j) {
            br++;
            break;
        }

        if (a[i] + a[j] > x) {
            j--;
            br++;
        }
        else {
            i++;
            j--;
            br++;
        }
    }

    return br;
}

int main ()
{
    int n, x;

    std::cin >> n >> x;

    std::vector<int> a(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    camci(a, x);

    return 0;
}