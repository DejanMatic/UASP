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

std::vector<int> izracunaj_sufiksne_sume(const std::vector<int> &a)
{
    int n = a.size();

    std::vector<int> sufiksne_sume(n);

    sufiksne_sume[n - 1] = a[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        sufiksne_sume[i] = sufiksne_sume[i + 1] + a[i];
    }

    return sufiksne_sume;
}

int main ()
{
    std::vector<int> a = {1, 7, 6, 4, 2};
    std::vector<int> b = {9, 2, 8, 5, 3};

    std::vector<int> sume_a = izracunaj_prefiksne_sume(a);
    std::vector<int> sume_b = izracunaj_sufiksne_sume(b);

    int n = a.size();
    int brojac = 0;

    for (int i = 0; i < n; i++) {
        if (sume_a[i] == sume_b[n - 1 - i]) {
            brojac++;
        }
    }

    std::cout << "Rezultat je : " << brojac << "\n";

    return 0;
}