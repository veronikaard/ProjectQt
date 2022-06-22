#include <pe12-2a.h>

int MODE = 0;
float dist = 0, fuel = 0;

void set_mode(int mode)
{
    if (mode==0 || mode==1)
        MODE = mode;
    else
    {
        printf("������ ������������ �����. ������������ ����� %d.", MODE);
        set_mode(MODE);
    }
}

void get_info(void)
{
    switch (MODE) {
    case MODE_M:
        printf("������� ���������� ���������� � ����������: ");
        scanf("%f", &dist);
        printf("������� ����� ���������������� ������� � ������: ");
        scanf("%f", &fuel);
        break;
    case MODE_A:
        printf("������� ���������� ���������� � �����: ");
        scanf("%f", &dist);
        printf("������� ����� ���������������� ������� � ��������: ");
        scanf("%f", &fuel);
        break;
    default:
        break;
    }
}

void show_info(void)
{
    switch (MODE) {
    case MODE_M:
        printf("������ ������� ���������� %f ������ �� 100 ��\n", fuel/dist * 100);
        break;
    case MODE_A:
        printf("������ ������� ���������� %f ������ �� ����\n", dist/fuel);
        break;
    default:
        break;
    }
}
