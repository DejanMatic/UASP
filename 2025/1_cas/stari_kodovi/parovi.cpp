#include <iostream>
#include <vector>

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

std::ostream& operator <<(std::ostream &out, const std::pair<int, int> &p) 
{
    out << p.first << " " << p.second;

    return out;
}

std::ostream& operator <<(std::ostream &out, const std::pair<std::string, std::vector<int>> &p) 
{
    out << p.first << " " << p.second;

    return out;
}

int main ()
{
    // Par se deklarise pomocu std::pair<prvi argument, drugi argument> ime promenljive
    std::pair<int, int> p;
    
    // Elementima se pristupa sa first i second
    p.first = 1;
    p.second = 2;

    std::cout << p << "\n";

    // Par se moze kreirati i pomocu funkcije make_pair, gde se kao argumenti navode odgovarajuci prvi i drugi element para redom
    std::pair<int ,int> p1 = std::make_pair(3,4);

    std::cout << p1 << "\n";

    // Elementi para ne moraju biti istog tipa i mogu biti bilo sta
    std::pair<std::string, std::vector<int>> par;

    std::string s = "Ovo je neki cudan par";
    std::vector<int> niz = {1, 2, 3};

    par.first = s;
    par.second = niz;

    std::cout << par << "\n";

    return 0;
}   
