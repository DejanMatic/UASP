#include <iostream>
#include <vector>

int najduza_serija_v1(const std::vector<int> &rezultati)
{
    // Promenljiva koja nam govori da li su u nekom segmentu sve pobede
    bool sve_pobede;
    // Na pocetku, maksimalan broj pobeda tima je 0, a kako vreme bude prolazilo, azuriracemo ovu vrednost po potrebi
    int max_pobeda = 0;
    // Duzinu vektora cuvamo u promenljivoj
    int n = rezultati.size();

    // Razmatramo sve moguce segmente svih mogucih duzina
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Pretpostavimo da u segmentu ima samo pobeda
            sve_pobede = true;
            // Prolazimo kroz svaki moguci segment i proveravamo da li su u njemu sve pobede
            for (int k = i; k <= j; k++) {
                // Ako naidjemo na neki rezultat koji nije pobeda, puca nam pretpostavka da su sve pobede pa to i kazemo
                if (rezultati[k] == -1) {
                    // Kazemo da u segmentu nisu sve pobede
                    sve_pobede = false;
                    // Odmah izlazimo iz petlje, ovaj segment nam nije zanimljiv
                    break;
                }
            }

            // Nakon sto smo izasli iz segmenta (prosli kroz ceo jer su sve bile pobede ili naisli na poraz pa breakovali)
            // proverimo prvo da li su u segmentu bile sve pobede, i ako jesu da li je duzina segmenta duza od do sada maksimalnog
            // niza pobeda
            // Zbog lenjog izracunavanja ce se odmah narusiti uslov u if-u ako se desi da sve_pobede nema vrednost true
            if (sve_pobede && j - i + 1 > max_pobeda) {
                // Ako treba, azuriramo vrednost promenljive max_pobeda
                max_pobeda = j - i + 1;
            }
        }
    }

    // Vracamo najduzi niz pobeda u nizu
    return max_pobeda;
}

int najduza_serija_v2(const std::vector<int> &rezultati)
{
    // Na pocetku, maksimalan broj pobeda tima je 0, a kako vreme bude prolazilo, azuriracemo ovu vrednost po potrebi
    int max_pobeda = 0;
    // Duzinu vektora cuvamo u promenljivoj
    int n = rezultati.size();

    int i, j;
    // Fiksiramo levi kraj niza
    for (i = 0; i < n; i++) {
        // I od njega prolazimo kroz sve podnizove dok god imamo seriju pobeda
        for (j = i; j < n; j++) {
            // Ako naidjemo na neki rezultat koji nije pobeda, dosli smo do kraja podniza u kome su bile sve pobede
            if (rezultati[j] == -1) {
                // Odmah izlazimo iz petlje, jer smo ustanovili da je tim izgubio j-tu utakmicu (j-tu u odnosu na pocetak segmenta i)
                break;
            }
        }

        // Ako je duzina segmenta u kome je tim pobedjivao veca od max_pobeda, azuriramo vrednost max_pobeda
        if (j - i > max_pobeda) {
            max_pobeda = j - i;
        }
    }

    // Vracamo najduzi niz pobeda u nizu
    return max_pobeda;
}

int najduza_serija_v3(const std::vector<int> &rezultati)
{
    // Na pocetku tim nema pobeda pa je to i maksimalna vrednost pobeda
    int max_pobeda = 0;
    int n = rezultati.size();

    int i = 0;
    // Kazemo da tim na pocetku nema nijednu pobedu
    int trenutno_pobeda = 0;

    // Krecemo se kroz niz pobeda
    while (i < n) {
        // Ako je u pitanju jos jedna pobeda
        if (rezultati[i] == 1) {
            // uvecavamo brojac
            trenutno_pobeda++;
        }
        // Ako je tim izgubio, treba reci da mu je trenutni niz pobeda 0, ali prethodno proveriti da li je trenutni niz pobeda
        // veci od maksimalnog niza pobeda tima
        else {
            // Ako jeste, azuriramo vrednost maksimalnog niza pobeda
            if (trenutno_pobeda > max_pobeda) {
                max_pobeda = trenutno_pobeda;
            }
            // Kazemo da tim trenutno nema pobeda
            trenutno_pobeda = 0;
        }
        i++;
    }

    // Ovo je vrlo vazna provera!!! Ako se desi da je najduzi niz pobeda na kraju samog niza, ako nemamo ovu proveru, desice se da
    // ne dobijemo tacan rezultat. Zapravo nikada necemo uci u else granu i azurirati max_pobeda.
    if (trenutno_pobeda > max_pobeda) {
        max_pobeda = trenutno_pobeda;
    }

    // Vracamo koliko je tim imao maksimalno pobeda u nizu
    return max_pobeda;
}

int main ()
{
    std::vector<int> rezultati = {1,-1,1,-1,1,1,1,1,-1,1,1,1,1,1,1,1,1};

    std::cout << "Najduza serija: " << najduza_serija_v1(rezultati) << "\n";

    std::cout << "Najduza serija: " << najduza_serija_v2(rezultati) << "\n";

    std::cout << "Najduza serija: " << najduza_serija_v3(rezultati) << "\n";

    return 0;
}
