#include <iostream>
#include <vector>
#include <tuple>

// OVERLOAD operatora, dodatno gradivo koje nije neophodno za ispit, ako nekoga zanima moze se ili javiti mailom, ili pitati na casu
// Takodje, mozete procitati na https://en.cppreference.com/w/cpp/language/operators
std::ostream& operator <<(std::ostream &out, const std::vector<int> &niz) 
{
    out << "[";
    
    int i;

    for (i = 0; i < niz.size() - 1; i++)
        out << niz[i] << ", ";

    out << niz[i] << "]";

    return out;
}

std::ostream& operator <<(std::ostream &out, const std::tuple<int, int, int, int> &t) 
{
    out << std::get<0>(t) << " " << std::get<1>(t) << " " << std::get<2>(t) << " " << std::get<3>(t);

    return out;
}

std::ostream& operator <<(std::ostream &out, const std::tuple<std::string, std::string, std::vector<int>> &t) 
{
    out << std::get<0>(t) << " -> " << std::get<1>(t) << " -> " << std::get<2>(t);

    return out;
}

int main ()
{
    // Torka se deklarise pomocu std::tuple<prvi argument, drugi argument, ..., n-ti argument> ime promenljive
    std::tuple<int, int, int, int> t;
    
    // Elementima se pristupa sa get<redni broj elementa>(ime torke)
    std::get<0>(t) = 1;
    std::get<1>(t) = 2;
    std::get<2>(t) = 3;
    std::get<3>(t) = 4;

    std::cout << t << "\n";

    // Torka se moze kreirati i pomocu funkcije make_tuple, gde se kao argumenti navode odgovarajuci elementi torke redom
    std::tuple<int, int, int, int> t1 = std::make_tuple(3, 4, 5, 6);

    std::cout << t1 << "\n";

    // Elementi torke ne moraju biti istog tipa i mogu biti bilo sta
    std::tuple<std::string, std::string, std::vector<int>> torka;

    std::string s = "Ovo su ocene studenta";
    std::string ime = "Nekog studenta";
    std::vector<int> niz = {9, 10, 9, 9, 10, 10};

    std::get<0>(torka) = s;
    std::get<1>(torka) = ime;
    std::get<2>(torka) = niz;

    std::cout << torka << "\n";

    return 0;
}   
