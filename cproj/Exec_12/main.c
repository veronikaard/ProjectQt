#include <stdio.h>
#include <locale.h>
#include <windows.h>

int critic(int);

int main()
{
    setlocale(LC_ALL, "Russian");
    int units = 0;

    printf("������� ����� ����� ��������� ������� �����?\n");
    scanf("%d", &units);
    while (units!=56)    
        units = critic(units);

    printf("�� ����� ���!\n");

    return 0;
}

int critic(int units)
{
    printf("��� �� �������. ���������� ��� ���.\n");
    scanf("%d", &units);
    return units;
}
