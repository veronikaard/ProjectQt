#include <iostream>

using namespace std;
const int ArSize = 8;

int sum_arr(int arr[], int n);
int main()
{
    //Listing 7.5
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};
    cout << cookies << endl;
    cout << sizeof cookies << endl;

    int sum = sum_arr(cookies, ArSize);
    cout << "sum = " << sum << endl;

    return 0;
}

int sum_arr(int arr[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];
    return total;
}
