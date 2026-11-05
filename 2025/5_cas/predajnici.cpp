#include <iostream>
#include <vector>
#include <algorithm>

int predajnici(std::vector<int> &a, int d) {

    std::sort(a.begin(), a.end());

    int i = 0, j = 0, n = a.size(), max = 0;

    while (i < n) {
        while (a[i] - a[j] > d) {
            j++;
        }

        if (a[i] - a[j] > max) {
            max = a[i] - a[j];
        }

        i++;
    }

    return max;
}

int main ()
{
    int n, d;

    std::cin >> n >> d;

    std::vector<int> a(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::cout << predajnici(a, d) << "\n";

    return 0;
}