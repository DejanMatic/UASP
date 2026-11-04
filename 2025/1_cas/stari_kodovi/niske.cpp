#include <iostream>
#include <string>

int main ()
{
    // Deklaracija niske
    std::string s;

    // Dodela se moze vrsiti operatorom =
    s = "Ovo je neka niska";

    std::cout << s << "\n";

    // i-tom karakteru niske mozemo pristupiti pomocu [i]
    std::cout << "3. karakter ove niske je " << s[2] << "\n";
    
    // Duzina niske se racuna pomocu length()
    std::cout << s.length() << "\n";

    // Operatori +, += su dozvoljeni u radu sa niskama (slicno kao u Javi)
    s = "Danas je";       
    std::string s1 = " lep dan";

    std::cout << s + s1 << "\n";

    s+= s1;

    std::cout << s << "\n";
    
    // Niska je niz karaktera, vecina metoda koja postoji za vector postoji i za string. Isprobati kod kuce
    return 0;
}
