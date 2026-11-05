#include <iostream>
#include <vector>

int most_water(const std::vector<int> &a)
{
    int i = 0, j = a.size() - 1;
    int max = 0, current;

    while (i < j) {
        current = (j - i) * std::min(a[i], a[j]);

        if (current > max) { // max = std::max(current, max)
            max = current;
        }

        if (a[i] < a[j]) {
            i++;
        }
        else {
            j--;
        }
    }

    return max;
}

int main ()
{
    std::vector<int> a = {3, 1, 2, 4, 5};

    std::cout << most_water(a) << "\n";
    return 0;
}