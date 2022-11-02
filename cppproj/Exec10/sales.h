#ifndef SALES_H
#define SALES_H

#include <iostream>

namespace SALES
{
    class Sales
    {
    private:
        static const int QUARTERS = 4;

        double sales[QUARTERS];
        double average;
        double Max;
        double Min;
    public:
        Sales(const double ar[], int n);
        void setSales();
        void showSales()const;
    };
}


#endif // SALES_H
