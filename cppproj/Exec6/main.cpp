#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
bool is_int(double);

const int Max = 5;
const int SIZE = 60;

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
    /*double num;
    cin >> num;
    while (!is_int(num))
    {
        cout << "Out of range -- please try again: ";
        cin >> num;
    }
    int val = int (num);
    cout << val << endl;*/

    //Listing 6.13
    //нечисловой ввод прекращает выполнение цикла
    /*double fish[Max];
    cout << "Weight fish #1: ";
    int i = 0;
    while (i < Max && cin >> fish[i])
    {
        if (++i < Max)
            cout << "fish #" << i+1 << ": ";
    };

    double total = 0.0;
    for (int j = 0; j < i; j++)
        total+=fish[j];

    if (i == 0)
        cout << "No fish\n";
    else
        cout << total/i << " = average weight of "
             << i << " fish\n";
    cout << "Done.\n";*/

    //Listing 6.14
    //нечисловой ввод пропускается
    /*int golf[Max];
    int i;
    for (i = 0; i < Max; i++)
    {
        cout << "round #" << i+1 << ": ";
        while (!(cin >>golf[i]))
        {
            cin.clear();
            while (cin.get() != '\n' )
                continue;
            cout << "Please enter a number: ";
        }
    }

    double total = 0.0;
    for (int j = 0; j < i; j++)
        total+=golf[j];

    if (i == 0)
        cout << "No golf\n";
    else
        cout << total/i << " = average score of "
             << i << " golf\n";
    cout << "Done.\n";*/

    //Listing 6.15
    //запись в файл
    /*char automobile[50];
    int year;
    double a_price;
    double d_price;
    ofstream outFile;
    outFile.open("carinfo.txt");
    cout << "Enter the make and model of automobile: ";
    cin.getline(automobile, 50);
    cout << "Enter the model year: ";
    cin >> year;
    cout << "Enter the original asking price: ";
    cin >> a_price;
    d_price = 0.913 * a_price;

    cout << fixed;
    cout.precision(2);
    cout.setf(ios_base::showpoint);
    cout << automobile << endl;
    cout << year << endl;
    cout << "$ was " << a_price << endl;
    cout << "$ now " << d_price << endl;

    outFile << fixed;
    outFile.precision(2);
    outFile.setf(ios_base::showpoint);
    outFile << automobile << endl;
    outFile << year << endl;
    outFile << "$ was " << a_price << endl;
    outFile << "$ now " << d_price << endl;
    outFile.close();*/

    //Listing 6.16
    //чтение файла
    char filename[SIZE];
    ifstream inFile;
    cout << "Enter name of data file: ";
    cin.getline(filename, SIZE);
    inFile.open(filename);
    if (!inFile.is_open())
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }

    double value;
    double sum = 0.0;
    int count = 0;
    inFile >> value;

    while (inFile.good()) {
        ++count;
        sum += value;
        inFile >> value;
    };

    if (inFile.eof())
        cout << "End of file\n";
    else if (inFile.fail())
        cout << "Input terminated by data mismatch\n";
    else
        cout << "Input terminated for unknown\n";

    if (count == 0)
        cout << "No data processed\n";
    else
    {
        cout << "Items rea: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << sum/count << endl;
    }

    inFile.close();

    return 0;
}

bool is_int(double x)
{
    if (x <= INT_MAX && x >= INT_MIN)
        return true;
    else
        return false;
}
