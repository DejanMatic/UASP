#include <iostream>
#include <list>

int main()
{
    // std::ios::sync_with_stdio(false);
    // std::cerr.tie(nullptr);

    // std::cout << "Hello world! " << 42 << " " << 3.14 << std::endl;
    // std::cerr << "Hello world from stderr!\n";

    // int x, y, z;

    // std::cin >> x >> y >> z;

    // std::cout << x << " " << y << " " << z << "\n";

    std::string s = "Created hello world!\n";

    std::string s2("Hello world from constructor!\n");

    std::string s3; // Poziva se default konstruktor!!!

    std::cout << s << s2;

    // std::string prvi = "Hello ";
    // std::string drugi = "world ceo!\n";

    // std::string ceo = prvi + drugi;
    // std::cout << ceo;

    std::string prvi = "Hello ";
    std::string drugi = "world +=!\n";

    prvi += drugi;
    std::cout << prvi;

    std::cout << prvi.size() << "\n";

    return 0;
}