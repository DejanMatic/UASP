#include <iostream>

int main()
{
    int cout = 42;

    std::cout << cout << std::endl;

    int x;

    std::cin >> x;

    std::cout << x << " " << "!" << "\n";

    // 1. nacin, poziva se konstruktor
    std::string s = "Hello world!\n";

    // 2. nacin, poziva se konstruktor
    std::string s2("Hello world!\n");

    // std::string s3; <=> std::string s3();

    std::cout << s << "\n" << s2 << "\n";

    std::cout << s.size() << "\n";

    // std::string s3 = s; <=> s3(s);

    return 0;
}