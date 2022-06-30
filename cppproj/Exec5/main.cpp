#include <iostream>

using namespace std;

int main()
{
    int x;

    //Listing 5.3
    //значения выражений
    /*cout << (x=100) << endl;
    cout << (x<3) << endl;
    cout << (x>3) << endl;
    cout.setf(ios_base::boolalpha);
    cout << (x<3) << endl;
    cout << (x>3) << endl;*/

    //Listing 5.8
    //использование блока
    double number;
    double sum = 0.0;
    for (int i = 1; i <=5; i++)
    {
        cout << "Value " << i << ": ";
        cin >> number;
        sum += number;
    }

    cout << sum << " " << sum/5 << endl;


    return 0;
}
