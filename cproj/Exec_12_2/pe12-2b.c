#include <locale.h>
#include <windows.h>
#include <stdio.h>

#include "pe12-2a.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    int mode;
    printf("������� 0 ��� ������������ ������ � 1 ��� ������������� ������: ");
    scanf("%d", &mode);

    while (mode >= 0)
    {
        set_mode(mode);
        get_info();
        show_info();
        printf("������� 0 ��� ������������ ������ � 1 ��� ������������� ������: ");
        printf("(-1 ��� ����������):");
        scanf("%d", &mode);
    }
    printf("��������� ���������.\n");

    return 0;
}
