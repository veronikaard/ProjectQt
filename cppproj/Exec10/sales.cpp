#include "sales.h"

namespace SALES
{
    Sales::Sales(const double ar[], int n)
    {
        double max = ar[0];
        double min = ar[0];
        double total = 0;
        //Очищаем массив
        for (int i = 0; i < QUARTERS; i++)
            sales[i] = 0;

        for (int i = 0; i < n; i++)
        {
            sales[i] = ar[i];
            if (ar[i] > max)
                max = ar[i];
            if (ar[i] < min)
                min = ar[i];
            total += ar[i];
        }
        average = total/n;
        Max = max;
        Min = min;
    }

    void Sales::setSales()
    {
        using std::cout;
        using std::cin;
        using std::endl;
        cout << "Enter value for forty quartas:\n";
        for (int i = 0; i < QUARTERS; i++)
        {
            cin >> sales[i];
        }

        double max = sales[0];
        double min = sales[0];
        double total = 0;

        for (int i = 0; i < QUARTERS; i++)
        {
            if (sales[i] > max)
                max = sales[i];
            if (sales[i] < min)
                min = sales[i];
            total += sales[i];
        }
        average = total/QUARTERS;
        Max = max;
        Min = min;
    }

    void Sales::showSales() const
    {
        using std::cout;
        using std::endl;
        cout << "Sales:\n" << "sales = " << sales[0] << " "
             << sales[1] << " " << sales[2] << " " << sales[3] << endl;
        cout << "average = " << average << ", max = " << Max << ", min = "
             << Min << endl;
    }

}

