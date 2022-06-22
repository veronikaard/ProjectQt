#include <iostream>
#include <climits>
#define ZERO 0

using namespace std;

int main()
{
    //Listing 3.1
    //некоторые ограничения целых чисел
    /*int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;

    cout << "int is " << sizeof(int) << " bytes." << endl;
    cout << "short is " << sizeof n_short << " bytes." << endl;
    cout << "long is " << sizeof n_long << " bytes." << endl;
    cout << "long long is " << sizeof n_llong << " bytes." << endl;
    cout << endl;

    cout << "Maximum values:" << endl;
    cout << "int: " << n_int << endl;
    cout << "short: " << n_short << endl;
    cout << "long: " << n_long << endl;
    cout << "long long: " << n_llong << endl;

    cout << "Minimum int value = " << INT_MIN << endl;
    cout << "Bits per byte = " << CHAR_BIT << endl;*/

    //Listing 3.2
    //выход за пределы для некоторых целочисленных чисел
    /*short sam = SHRT_MAX;
    unsigned short sue = sam;
    cout << sam << " " << sue << endl;
    sam += 1;
    sue += 1;
    cout << sam << " " << sue << endl;
    sam = ZERO;
    sue = ZERO;
    cout << sam << " " << sue << endl;
    sam -= 1;
    sue -= 1;
    cout << sam << " " << sue << endl;*/

    //Listing 3.4
    //показывает шестнадцатеричные и восьмеричные литералы
    /*int chest   = 42;
    int waist   = 0x42;
    int inseam  = 042;
    cout << chest  << " " << hex
         << waist  << " " << oct
         << inseam << dec << endl;*/

    //Listing 3.5
    //тип char
    /*char ch;
    cin >> ch;
    cout << ch << endl;*/

    //Listing 3.6
    //сравнение типов char и int
    /*char ch = 'M';
    int i = ch;
    cout << ch << " " << i << endl;

    ch += 1;
    i = ch;
    cout << ch << " " << i << endl;
    cout.put(ch);
    cout.put('!');*/

    //Listing 3.7
    //использование управляющих последовательностей
    /*cout << "\aOperation \"HyperHype\" is now activated!\n";
    cout << "Enter your agent code:________\b\b\b\b\b\b\b\b";
    long code;
    cin >> code;
    cout << "\aYou entered " << code << "...\n";
    cout << "\aCode verified! Proceed with Plan Z3!\n";*/

    //Listing 3.8
    //типы с плавающей точкой
    /*cout.setf(ios_base::fixed, ios_base::floatfield);
    float tub = 10.0 / 3.0;
    double mint = 10.0 / 3.0;
    const float million = 1.0e6;
    cout << tub << " " << million*tub << " " << 10*million*tub << endl;
    cout << mint << " " << million*mint << endl;
    float a = 2.34E+22f;
    float b = a + 1.0f;
    cout << a << " " << b-a << endl;*/

    //Listing 3.11
    /*cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << 9/5 << " " << 9.0/5.0 << " ";
    cout << 9.0/5 << endl;
    cout << 1e7/9.0 << " " << 1e7f/9.0f << endl;*/

    //Listing 3.12
    /*const int Lbs_per_stn = 14;
    int lbs;
    cin >> lbs;
    int stone = lbs / Lbs_per_stn;
    int pounds = lbs % Lbs_per_stn;
    cout << lbs << " " << stone << " " << pounds << endl;*/

    return 0;
}







