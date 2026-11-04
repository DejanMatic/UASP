// input output stream (nesto kao stdio u C-u)
#include <iostream>
// ako se koriste biblioteke iz C-a, onda se ime navodi cime_biblioteke (cstdio, cstdlib, cmath...)
#include <cmath>

// Ukoliko ne zelimo da za sve sto se nalazi u standardnoj biblioteci pisemo std::ime mozemo da iskoristimo using namespace std i onda prefiks std:: nije potreban
using namespace std;

int main ()
{
    // Deklaracija promenljivih
    int x, y;

    // Ucitavanje, std::cin je stream za ucitavanje vrednosti sa standardnog ulaza. Nakon ucitavanja jedne vrednosti imamo i dalje stream u koji mozemo da ucitavamo, pa samim tim mozemo dalje da koristimo >>
    std::cin >> x >> y;

    // Ispis, std::cout je stream za ispis vrednosti na standardni izlaz. Funkcionise na isti nacin kao std::cin pa mozemo nadovezivati vise ispisa sa <<
    std::cout << "Ispisujemo vrednosti x i y " << x << " " << y << std::endl;

    
    return 0;
}
