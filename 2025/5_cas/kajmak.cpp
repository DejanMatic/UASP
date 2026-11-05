#include <iostream>
#include <vector>

int kajmak(const std::vector<int> &a, int t)
{
    int max = 0;
    int sum = 0;
    int i = 0, j = 0, n = a.size();

    // while(j < n) {
    //     if (j > i) {
    //         j++;
    //         continue;
    //     }
    //     if (sum >= t) {
    //         sum -= a[i];
    //         i++;
    //     }
    //     else {
    //         if (sum > max) {
    //             max = sum;
    //         }
    //         sum += a[j++];
    //     }
    // }

    while (i < n) {
        sum += a[i];

        while (sum >= t && j <= i) {
            sum -= a[j];
            j++;
        }

        if (sum > max) {
            max = sum;
        }

        i++;
    }

    return max;
}

int main ()
{
    int n, t;
    std::cin >> n >> t;

    std::vector<int> a(n);

    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::cout << kajmak(a, t) << "\n";

    return 0;
}