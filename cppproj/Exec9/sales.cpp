#include "sales.h"
#include <iostream>

namespace SALES
{
    using std::cout;
    using std::cin;
    using std::endl;

    void setSales(Sales &s, const double ar[], int n)
    {

        double max = ar[0];
        double min = ar[0];
        double total = 0;
        //Очищаем массив
        for (int i = 0; i < QUARTERS; i++)
            s.sales[i] = 0;

        for (int i = 0; i < n; i++)
        {
            s.sales[i] = ar[i];
            if (ar[i] > max)
                max = ar[i];
            if (ar[i] < min)
                min = ar[i];
            total += ar[i];
        }
        s.average = total/n;
        s.max = max;
        s.min = min;
    }



    void setSales(Sales &s)
    {
        cout << "Enter value for forty quartas:\n";
        for (int i = 0; i < QUARTERS; i++)
        {
            cin >> s.sales[i];
        }

        double max = s.sales[0];
        double min = s.sales[0];
        double total = 0;

        for (int i = 0; i < QUARTERS; i++)
        {
            if (s.sales[i] > max)
                max = s.sales[i];
            if (s.sales[i] < min)
                min = s.sales[i];
            total += s.sales[i];
        }
        s.average = total/QUARTERS;
        s.max = max;
        s.min = min;

    }

    void showSales(const Sales &s)
    {
        cout << "Sales:\n" << "sales = " << s.sales[0] << " "
             << s.sales[1] << " " << s.sales[2] << " " << s.sales[3] << endl;
        cout << "average = " << s.average << ", max = " << s.max << ", min = "
             << s.min << endl;
    }
}

