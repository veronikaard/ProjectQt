#include <iostream>
#include "stock00.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    Stock fluffy_the_cat("Nanosmart", 20, 12.5);
    fluffy_the_cat.show();
    //fluffy_the_cat.acquare("Nanosmart", 20, 12.5);
    //fluffy_the_cat.show();
    //fluffy_the_cat.buy(15, 18.125);
    //fluffy_the_cat.show();
    //fluffy_the_cat.sell(400, 20.0);
    //fluffy_the_cat.show();
    //fluffy_the_cat.buy(300000, 40.125);
    //fluffy_the_cat.show();
    //fluffy_the_cat.sell(300000, 0.125);
    //fluffy_the_cat.show();

    Stock food = Stock("World Cabbage", 250, 1.25);
    food.show();

    food = fluffy_the_cat;
    food.show();

    Stock *cloth = new Stock("Zara", 50, 2.35);
    cloth->show();
    delete cloth;

    food = Stock("hjdj", 10, 0.2);
    food.show();

    Stock harry;
    harry.show();

    return 0;
}
