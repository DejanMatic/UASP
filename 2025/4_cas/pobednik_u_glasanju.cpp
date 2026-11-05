#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

void apsolutni_pobednik_v1(const std::vector<int> &glasovi)
{
    // Glasove za svakog kandidata mozemo cuvati u mapi kao parove [kandidat, broj glasova]
    std::unordered_map<int, int> mapa_glasova;

    int n = glasovi.size();

    // Prolazimo kroz sve glasove
    for (int glas : glasovi) {
        // Za svaki glas za kandidata (kljuc u mapi) povecavamo brojac (vrednost u mapi) za 1
        mapa_glasova[glas]++;
    }

    // Prolazimo kroz celu mapu. Kako radimo sa mapom, svi elementi su parovi, prvi element je redni broj kandidata, a drugi broj glasova za njega
    for (auto glasovi_u_mapi : mapa_glasova) {
        // Ako neki kandidat ima vise od n / 2 glasova, on je apsolutni pobednik
        if (glasovi_u_mapi.second > n / 2) {
            std::cout << glasovi_u_mapi.first << "\n";
            // Odmah zavrsavamo funkciju, nema potrebe ici dalje
            return ;
        }
    }

    // Ako nismo nasli kandidata sa vise od n / 2 glasova, ispisujemo poruku
    std::cout << "Nema\n";
}

void apsolutni_pobednik_v2(std::vector<int> glasovi)
{
    // Prvo sortiramo niz glasova
    std::sort(glasovi.begin(), glasovi.end());

    int n = glasovi.size();
    // Na pocetku kazemo da istih elemenata za redom ima samo 1
    int istih = 1;

    // Krecemo se kroz ceo niz
    for (int i = 1; i < n; i++) {
        // Dok god je trenutni element jednak prethodnom, idemo dalje.
        // Kad se razbije ovaj uslov, prebrojali smo sve glasove za jednog kandidata
        if (glasovi[i] != glasovi[i - 1]) {
            // Ako je broj glasova veci od n / 2, on je apsolutni pobednik
            if (istih > n / 2) {
                // Ispisujemo glasovi[i - 1] jer na poziciji i vec krecu glasovi novog kadnidata koji se razlikuju od onog koji je
                // apsolutni pobednik
                std::cout << glasovi[i - 1] << "\n";
                // Odmah zavrsavamo funkciju, nema potrebe ici dalje
                return ;
            }
            // Ako je samo doslo do rusenja uslova, a kandidat nije apsolutni pobednik, azuriramo vrednost promenljive koja broji glasove
            // kandidata, jer je ovo prvi glas za novog kandidata
            istih = 1;
        }
        // Ako je trenutni jednak prethodnom, samo nastavljamo da brojimo glasove trenutnog kandidata
        else {
            istih++;
        }
    }

    // Ako se desi da je apsolutni pobednik na kraju, nikada necemo uci u else granu u petlji, i necemo proveriti da li je kandidat
    // apsolutni pobednik, pa je potrebno proveru za kraj niza izvrsiti posebno
    if (istih > n / 2) {
        std::cout << glasovi[n - 1] << "\n";
        return ;
    }

    // Ako nismo nasli kandidata sa vise od n / 2 glasova, ispisujemo poruku
    std::cout << "Nema\n";
}

void apsolutni_pobednik_v3(std::vector<int> glasovi)
{
    // Prvo sortiramo niz glasova
    std::sort(glasovi.begin(), glasovi.end());

    int n = glasovi.size();
    // Ako postoji apsolutni pobednik, on mora da se nalazi na polovini niza sigurno, jer njegovih glasova ima vise od n / 2 u nizu
    // Nakon soritranja niza, element koji se javlja vise od pola puta, mora da se nalazi na sredini niza sigurno, pa je element koji
    // se nakon sortiranja nalazi na polovini niza kandidat za apsolutnog pobednika
    int kandidat = glasovi[n / 2];

    // Njegov broj pojavljivanja je 0 na pocetku
    int broj_pojavljivanja = 0;

    // broj_pojavljivanja = std::count(glasovi.begin(), glasovi.end(), kandidat);

    // Prolazimo kroz sve glasove
    for (int glas : glasovi) {
        // Kad naidjemo na kandidata
        if (glas == kandidat) {
            // Povecavamo broj pojavljivanja
            broj_pojavljivanja++;
        }
    }

    // Ako kandidat ima vise od n / 2 pojavljivanja (glasova), ispisujemo poruku
    if (broj_pojavljivanja > n / 2) {
        std::cout << kandidat << "\n";
    }
    // Ako ne, pisemo da nema apsolutnog pobednika
    else {
        std::cout << "Nema\n";
    }
}

int main ()
{
    // std::vector<int> glasovi = {342, 123, 342, 756, 123, 756, 123, 756, 756, 756};

    std::vector<int> glasovi = {342, 123, 342, 756, 123, 756, 123, 756, 756, 756, 342, 756, 756};

    apsolutni_pobednik_v1(glasovi);

    apsolutni_pobednik_v2(glasovi);

    apsolutni_pobednik_v3(glasovi);

    return 0;
}