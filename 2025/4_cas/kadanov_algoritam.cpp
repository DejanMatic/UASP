#include <iostream>
#include <vector>

int maksimalan_zbir(const std::vector<int> &niz)
{
    // Pocetni max je jednak prvom elementu niza jer za prvi element nemamo segment pre njega sa kojim mozemo da vrsimo poredjenje
    // za maksimalnu sumu
    int max = niz[0];
    // I trenutni zbir je jednak tome, jer ponovo nemamo neki podniz pre prvog elementa i to je specijalan slucaj
    int trenutni_zbir = max;
    int n = niz.size();

    // Krecemo od elementa na poziciji 1. Element na poziciji 0 je vec obradjen
    for (int i = 1; i < n; i++) {
        // Maksimalan zbir segmenta koji se zavrsava na poziciji i je jednak ili jednoclanom segmentu niz[i] ili zbiru elementa niz[i]
        // i prethodnog maksimalnog zbira podnizova.
        trenutni_zbir = std::max(niz[i], trenutni_zbir + niz[i]);

        // Ako je maksimalan zbir segmenta koji se zavrsava na poziciji i veci od maksimuma
        if (trenutni_zbir > max) {
            // azuriramo globalni maksimum
            max = trenutni_zbir;
        }
    }

    // Na kraju, kada smo nasli globalni max, samo ga i vratimo
    return max;
}

int main ()
{
    std::vector<int> niz = {1, -3, 2, 1, -1};

    std::cout << maksimalan_zbir(niz) << "\n";

    return 0;
}