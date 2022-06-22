#include <pe12-2a.h>

int MODE = 0;
float dist = 0, fuel = 0;

void set_mode(int mode)
{
    if (mode==0 || mode==1)
        MODE = mode;
    else
    {
        printf("Указан недопустимый режим. Используется режим %d.", MODE);
        set_mode(MODE);
    }
}

void get_info(void)
{
    switch (MODE) {
    case MODE_M:
        printf("Введите пройденное расстояние в километрах: ");
        scanf("%f", &dist);
        printf("Введите объем израсходованного топлива в литрах: ");
        scanf("%f", &fuel);
        break;
    case MODE_A:
        printf("Введите пройденное расстояние в милях: ");
        scanf("%f", &dist);
        printf("Введите объем израсходованного топлива в галлонах: ");
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
        printf("Расход топлива составляет %f литров на 100 км\n", fuel/dist * 100);
        break;
    case MODE_A:
        printf("Расход топлива составляет %f галлон на милю\n", dist/fuel);
        break;
    default:
        break;
    }
}
