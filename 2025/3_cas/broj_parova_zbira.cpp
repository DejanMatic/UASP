#include <iostream>
#include <vector>
#include <algorithm>

// Ovde NE SMEMO da koristimo const referencu. Sortiranje radi u mestu, odnosno menja originalni niz i ako bismo imali const, dobili
// bismo compilation error. Alternative su ili & bez const pri cemu treba voditi racuna da ce originalni niz biti izmenjen, pa ako to
// ne zelimo, imamo drugu opciju. Mozemo da kopiramo niz u neku lokalnu promenljivu i onda da vrsimo sort.
int broj_parova(std::vector<int> niz, int s)
{
    // Soritramo niz rastuce
    std::sort(niz.begin(), niz.end());

    // Promenljiva koja broji koliko ima parova elemenata koji u zbiru daju s
    int brojac = 0;

    int n = niz.size();

    // Kako treba da vrsimo pretragu u ostatku niza, uslov izlaska je i < n - 1 da ne bi doslo do segmentation fault-a
    for (int i = 0; i < n - 1; i++) {
        // Za svaki element, proveravamo da li u ostatku niza postoji element koji je jednak s - trenutni_element
        // Ukoliko postoji takav element, uvecavaom brojac
        if (std::binary_search(niz.begin() + i + 1, niz.end(), s - niz[i])) {
            brojac++;
        }
    }

    // Na kraju samo vratimo vrednost brojaca
    return brojac;
}

int main ()
{
    std::vector<int> niz = {6, 1, 4, 3, 8, -1};
    int s = 7;

    std::cout << broj_parova(niz, s) << "\n";

    return 0;
}
