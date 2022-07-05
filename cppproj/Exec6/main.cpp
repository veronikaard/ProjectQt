#include <iostream>

using namespace std;
bool is_int(double);
int main()
{
    /*char ch;
    std::cin.get(ch);

    while (ch != '.')
    {
        if (ch == '\n')
            std::cout << ch;
        else
            std::cout << ch+1;
        std::cin.get(ch);
    };*/

    //Listing 6.7
    //использование логической операции "НЕ"
    double num;
    cin >> num;
    while (!is_int(num))
    {
        cout << "Out of range -- please try again: ";
        cin >> num;
    }
    int val = int (num);
    cout << val << endl;

    return 0;
}

bool is_int(double x)
{
    if (x <= INT_MAX && x >= INT_MIN)
        return true;
    else
        return false;
}
