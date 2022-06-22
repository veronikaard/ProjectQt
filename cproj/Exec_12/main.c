#include <stdio.h>
#include <locale.h>
#include <windows.h>

int critic(int);

int main()
{
    setlocale(LC_ALL, "Russian");
    int units = 0;

    printf("Сколько футов весит маленький бочонок масла?\n");
    scanf("%d", &units);
    while (units!=56)    
        units = critic(units);

    printf("Вы знали это!\n");

    return 0;
}

int critic(int units)
{
    printf("Вам не повезло. Попробуйте еще раз.\n");
    scanf("%d", &units);
    return units;
}
