#include <iostream>

using namespace std;

int main()
{
    char ch;
    std::cin.get(ch);

    while (ch != '.')
    {
        if (ch == '\n')
            std::cout << ch;
        else
            std::cout << ch+1;
        std::cin.get(ch);
    };

    return 0;
}
