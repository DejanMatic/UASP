#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// Ovde NE SMEMO da koristimo const referencu. Sortiranje radi u mestu, odnosno menja originalni niz i ako bismo imali const, dobili
// bismo compilation error. Alternative su ili & bez const pri cemu treba voditi racuna da ce originalni niz biti izmenjen, pa ako to
// ne zelimo, imamo drugu opciju. Mozemo da kopiramo niz u neku lokalnu promenljivu i onda da vrsimo sort.
int h_indeks(std::vector<int> citati)
{
    std::sort(citati.begin(), citati.end(), std::greater<int>());

    int n = citati.size();

    int h_indeks = 0;
    while (h_indeks < n && citati[h_indeks] > h_indeks) {
        h_indeks++;
    }

    return h_indeks;
}

int h_index(std::vector<int> &a)
{
    std::sort(a.begin(), a.end(), std::greater<int>());

    int n = a.size();

    int index = n;

    for (int i = 0; i < n; i++) {
        if (a[i] <= i) {
            index = i;
            break;
        }
    }

    return index;
}

int main ()
{
    std::vector<int> citati = {3, 5, 12, 7, 5, 9, 0, 17};

    std::cout << h_indeks(citati) << "\n";
    std::cout << h_index(citati) << "\n";

    return 0;
}