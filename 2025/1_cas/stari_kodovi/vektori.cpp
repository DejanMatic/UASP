#include <iostream>
// Ukljucujemo biblioteku za rad sa vektorima
#include <vector>

int main ()
{
    // Kao sablonski argument navodimo kog tipa su elementi niza. U ovom slucaju hocemo niz celobrojnih vrednosti
    // Ovde imamo samo deklaraciju niza, i nije alocirana memorija za njega
    std::vector<int> niz;

    // Metod capacity() nam daje informaciju o tome koliko je memorije alocirano za niz, ali ne vraca velicinu u bajtovima, nego broj elemenata koji mogu da stanu u niz
    std::cout << "Kapacitet niza: " << niz.capacity() << "\n";

    // Metod size() daje broj elemenata u nizu
    // Metod capacity() nam daje 100, a metod size() 0 jer nemamo nijedan element u nizu, samo imamo alociran prostor za 100 promenljivih tipa int
    std::cout << "Broj elemenata niza (velicina niza): " << niz.size() << std::endl;

    // Metod max_size() daje informaciju o tome koliko maksimalno elemenata moze da ima niz odredjenog tipa
    // Promeniti sablonski argument u deklaraciji niza <int> na <float>, <long long int>, <double> i videti rezultate poziva ove funkcije
    std::cout << niz.max_size() << "\n";

    // Iteratori na pocetak i kraj kolekcije
    // Iteratori su pokazivaci na prvi odnosno poslednji element u kolekciji
    // Kljucna rec auto postoji od standarda C++11 i kaze da je tip promenljive bilo koji, tj zakljucuje se u fazi kompilacije na osnovu izraza sa desne strane =, tj drugog argumenta pri inicijalizaciji
    auto begin = niz.begin();
    auto end = niz.end();

    // Pre ubacivanja bilo kog elementa, pocetak i kraj su isti
    if (begin == end)
        std::cout << "Pocetak i kraj su isti\n";
    else
        std::cout << "Pocetak i kraj nisu isti\n";

    // Metod push_back() dodaje element na kraj niza. Ako ima dovoljno memorije element ce biti dodat, ako nema prostora izvrsice se realokacija memorije
    for (int i = 0; i < 10; i++)
        niz.push_back(i);

    // Broj elemenata niza nakon ubacivanja
    std::cout << niz.size() << "\n";

    // Kolekcijska petlja, oblika for (tip promenljive koja prolazi kroz kolekciju : kolekcija kroz koju se prolazi)
    // Samo ispisujemo elemente niza
    for (int x : niz)
        std::cout << x << " ";    
    std::cout << std::endl;

    // Promena pocetka i kraja na nove iteratore
    begin = niz.begin();
    end = niz.end();

    // Sada su oni razlicti
    if (begin == end)
        std::cout << "Pocetak i kraj su isti\n";
    else
        std::cout << "Pocetak i kraj nisu isti\n";

    // Pomocu [i] pristupamo i-tom elementu niza
    // Pristup 5. elementu niza
    std::cout << "6. element niza je " << niz[5] << "\n";

    // Metod data() daje pokazivac na prvi element vektora i omogucava da se kroz kolekciju krecemo slicno kao u C-u
    int *a = niz.data();
    std::cout << "4 element niza je " << *(a + 3) << "\n";

    // Metod at() daje element na poziciji koja se navodi kao njegov argument, npr niz.at(10) daje element na poziciji 10
    std::cout << "4 element niza je " << niz.at(3) << "\n";

    // Funkcija std::advance prima iterator i vrednost i pomera iterator za k pozicija, gde je k vrednost koja se navodi kao drugi argument
    std::advance(begin, 3);
    std::cout << "4 element niza je " << *begin << "\n";

    begin = niz.begin();

    // Petlja gde idemo kroz ceo niz, dok god je iterator begin razlicit od iteratora end.
    // Obratiti paznju na iterator end, on nije pokazivac na poslednji element kolekcije, vec pokazivac na 1 element iza kraja kolekcije.
    // Dakle ako imamo niz vektor 1, 2, 3, 4, 5 end ne pokazuje na 5, vec iza njega
    // 1, 2, 3, 4, 5 iterator_end
    //               ^
    //               
    while (begin != end) {
        std::cout << *begin << " ";
        begin++;
    }
    std::cout << "\n";
 
    // Kako bismo ispisali poslednji element kolekcije moramo end da "vratimo" za 1 poziciju   
    end--;
    std::cout << "Poslednji element vektora: " << *end << "\n";
    
    // Ispis kolekcije unazad
    // rbegin (reverse begin) je zapravo iterator na poslednji element, dok je rend (reverse end) pokazivac na prvi element kolekcije 
    auto rend = niz.rend();
    for (auto rbegin = niz.rbegin(); rbegin != rend; rbegin++)
        std::cout << *rbegin << " "; 

    std::cout << "\n";

    end = niz.end();
    end--;
    std::cout << "Poslednji element pre uklanjanja poslednjeg " << *end << "\n";
    std::cout << "Broj elemenata vektora pre uklanjanja poslednjeg " << niz.size() << "\n";
 
    niz.pop_back();

    end = niz.end();
    end--;
    std::cout << "Poslednji element pre uklanjanja poslednjeg " << *end << "\n";
    std::cout << "Broj elemenata vektora nakon uklanjanja poslednjeg " << niz.size() << "\n";

    // Funkcija resize menja velicinu vektora na vrednost koja se navodi kao argument, nesto slicno funkciji realloc u C-u
    niz.resize(5);

    // Kreiramo vektor sa 3 elementa i svi su 100
    std::vector<int> v1 (3, 100);

    // Kreiramo vektor sa 5 elementa i svi su 300
    std::vector<int> v2 (5, 300);

    std::cout << "Kapacitet v1: " << v1.capacity() << " \nKapacitet v2: " << v2.capacity() << "\n";

    // Menja sadrzaj vektora nad kojim se poziva metod i vektora koji se navodi kao argument
    v1.swap(v2);

    std::cout << "Kapacitet v1: " << v1.capacity() << " \nKapacitet v2: " << v2.capacity() << "\n";

    return 0;
}
