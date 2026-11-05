#include <iostream>
#include <vector>

std::vector<int> izracunaj_prefiksne_sume(const std::vector<int> &a)
{
    int n = a.size();

    std::vector<int> prefiksne_sume(n);

    prefiksne_sume[0] = a[0];

    for (int i = 1; i < n; i++) {
        prefiksne_sume[i] = prefiksne_sume[i - 1] + a[i];
    }

    return prefiksne_sume;
}

int suma(const std::vector<int> &prefiksne_sume, int l, int r)
{
    if (l == 0) {
        return prefiksne_sume[r];
    }

    return prefiksne_sume[r] - prefiksne_sume[l - 1];
}

int main ()
{
    std::vector<int> a = {2, 5, 7, 6, 3, 1};

    std::vector<int> prefiksne_sume = izracunaj_prefiksne_sume(a);

    std::cout << "Suma: " << suma(prefiksne_sume, 2, 5) << "\n";

    std::cout << "Suma: " << suma(prefiksne_sume, 0, 2) << "\n";

    std::cout << "Suma: " << suma(prefiksne_sume, 1, 3) << "\n";

    return 0;
}