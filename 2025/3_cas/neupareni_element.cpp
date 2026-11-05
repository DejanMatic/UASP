#include <iostream>
#include <vector>
#include <algorithm>

// Ovde NE SMEMO da koristimo const referencu. Sortiranje radi u mestu, odnosno menja originalni niz i ako bismo imali const, dobili
// bismo compilation error. Alternative su ili & bez const pri cemu treba voditi racuna da ce originalni niz biti izmenjen, pa ako to
// ne zelimo, imamo drugu opciju. Mozemo da kopiramo niz u neku lokalnu promenljivu i onda da vrsimo sort.
int neupareni_element(std::vector<int> niz)
{
    // Prvo sortiramo niz elemenata
    std::sort(niz.begin(), niz.end());

    int n = niz.size();

    // Prolazimo kroz elemente niza poredeci svaka 2 susedna, ali skacuci za 2. Na ovaj nacin smo pokrili slucaj da najmanji element
    //  nema para, a skakanjem za 2 omogucavamo da preskacemo parove istih elemenata. 
    for (int i = 0; i < n - 1; i += 2) {
        // Ako se 2 susedna elementa razlikuju, jedini koji nema para je bas i-ti element
        if (niz[i] != niz[i + 1]) {
            return niz[i];
        }
    }

    // Prethodnom petljom nije pokriven slucaj poslednjeg elementa koji nema para, pa to moramo rucno da obradimo.
    // Ako smo dosli do ove naredbe, znaci da nikad nismo iskocili iz petlje pomocu return naredbe u istoj, i jedini
    // element koji moze da nema parnjaka je poslednji
    return niz[n - 1];
}

// Alternativno, mozda intuitivnije resenje
// Za svaki element, poredimo njega sa prethodnim i narednim. Ako nije jednak ni prethodnom ni narednom, onda je sigurno jedinstven
// Prvo sortiramo niz kao i u prethodnoj varijanti
int neupareni_element_v2(std::vector<int> niz)
{
    // Prvo sortiramo niz elemenata
    std::sort(niz.begin(), niz.end());

    int n = niz.size();

    // U ovoj implementaciji, rucno mora da se obradi i prvi element, jer petlja krece od 1
    if (niz[0] != niz[1])
        return niz[0];
        
    // Prolazimo kroz elemente niza redom i trenutni element proveravamo sa prethodnim i narednim 
    for (int i = 1; i < n - 1; i++) {
        // Ako nije jednak nijednom, to mora da bude element koji nema para
        if (niz[i] != niz[i - 1] && niz[i] != niz[i + 1]) {
            return niz[i];
        }
    }

    // Prethodnom petljom nije pokriven slucaj poslednjeg elementa koji nema para, pa to moramo rucno da obradimo.
    // Ako smo dosli do ove naredbe, znaci da nikad nismo iskocili iz petlje pomocu return naredbe u istoj, i jedini
    // element koji moze da nema parnjaka je poslednji
    return niz[n - 1];
}
int main ()
{
    std::vector<int> niz = {3, 2, 1, 4, 2, 5, 1, 3, 4};

    std::cout << neupareni_element(niz) << "\n";

    std::cout << neupareni_element_v2(niz) << "\n";

    return 0;
}