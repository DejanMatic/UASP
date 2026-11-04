#include <iostream>

int main()
{
    std::cout << "Hello world\n";

    int x;

    std::cin >> x;

    std::cout << "x je " << x << "\n";

    // std::string s; <=> std::string s();

    // std::string s("Danas.\n") <=> std::string s = "Danas.\n";

    std::string s = "Danas je utorak.";

    std::string s2 = s; // <=> s2(s)

    std::cout << s << "\n";

    std::cout << s2 << "\n";

    std::cout << s.size() << "\n";

    std::string s3 = s + s2;

    s += "Novi string";

    std::cout << s3 << "\n";

    std::cout << s << "\n";

    return 0;
}