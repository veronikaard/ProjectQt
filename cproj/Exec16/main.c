#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include <stdbool.h>
#include <stdalign.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
//#define NDEBUG
#include <assert.h>
#include "names_st.h"           //включение заголовочного файла
#include <stdarg.h>
#define JUST_CHECKING
//_Static_assert(CHAR_BIT == 16, "Ошибочно предполагается 16-битовый тип char");
#define LIMIT 4
#define SIZE 10
#define PR(X, ...) printf("Сообщение " #X ": "__VA_ARGS__)
#define MYTYPE(X) _Generic((X),\
    int: "int",\
    float: "float",\
    double: "double",\
    default: "other"\
)
#define J SIZE*SIZE

#define RAD_TO_DEG (180/(4*atan(1)))

//обобщенная функция вычисления синуса угла, заданного в градусах
#define SIN(X) _Generic((X),\
    float: sinf((X)/RAD_TO_DEG),\
    long double: sinl((X)/RAD_TO_DEG),\
    default: sin((X)/RAD_TO_DEG)\
    )
//обобщенная функция извлечения квадратного корня
#define SQRT(X) _Generic((X),\
    float: sqrtf,\
    long double: sqrtl,\
    default: sqrt\
    )(X)

void sign_off(void);
void too_bad(void);

#define NUM 40
void fillarray(double ar[], int n);
void showarray(const double ar[], int n);
void show_array(const int ar[], int n);
int mycomp(const void *p1, const void *p2);

_Static_assert(sizeof(double)==2*sizeof(int), "double не имеет двойной"
                                              "размер int");

double sum(int, ...);

typedef struct polar_v
{
    double magnitude;
    double angle;
}Polar_V;

typedef struct rect_v
{
    double x;
    double y;
}Rect_V;

Polar_V rect_to_polar(Rect_V);

int main()
{
    setlocale(LC_ALL, "Rus");

    //Listing 16.5
    //макросы с переменным числом аргументов
    /*double x = 48;
    double y;

    y = sqrt(x);
    PR(1, "x = %g\n", x);
    PR(2, "x = %.2f, y = %.4f\n", x, y);*/

    //Listing 16.8
    //использование структуры names_st
    /*names candidate;
    get_names(&candidate);
    printf("Добро пожаловать в программу, ");
    show_names(&candidate);
    printf("!\n");*/

    //Listing 16.9
    //использование условной компилляции
    /*int i;
    int total = 0;
    for (i = 1; i <= LIMIT; i++)
    {
        total += 2*i*i + 1;
#ifdef JUST_CHECKING
        printf("i = %d, промежуточная сумма = %d\n", i, total);
#endif
    }
    printf("Итоговая сумма = %d\n", total);*/

    //Listing 16.12
    //предопределенные идентификаторы
//#line 1 "cool.h"
/*#if __STDC_VERSION__ != 201112L
#error Несоответствие C11
#endif
    printf("Файл: %s.\n", __FILE__);
    printf("Дата: %s.\n", __DATE__);
    printf("Время: %s.\n", __TIME__);
    printf("Версия: %ld.\n", __STDC_VERSION__);
    printf("Это строка: %d.\n", __LINE__);
    printf("Это функция: %s.\n", __func__);*/

    //Listing 16.13
    //обобщенный выбор
    /*int d = 5;
    printf("%s\n", MYTYPE(5));
    printf("%s\n", MYTYPE(2.0*d));
    printf("%s\n", MYTYPE(3L));
    printf("%s\n", MYTYPE(&d));*/

    //Listing 16.14
    //преобразует прямоугольные координаты в полярные
    /*Rect_V input;
    Polar_V result;

    puts("Введите координаты x и y; введите q для выхода:");

    while(scanf("%lf %lf", &input.x, &input.y) == 2)
    {
        result = rect_to_polar(input);
        printf("модуль = %0.2f, угол = %0.2f\n", result.magnitude,
               result.angle);
    }
    puts("Программа завершена!");*/

    //Listing 16.15
    //определение обобщенных макросов
    /*float x = 45.0f;
    double xx = 45.0;
    long double xxx = 45.0L;



    long double y = SQRT(x);
    long double yy = SQRT(xx);
    long double yyy = SQRT(xxx);

    __mingw_printf("%.17Lf\n", y);
    __mingw_printf("%.17Lf\n", yy);
    __mingw_printf("%.17Lf\n", yyy);

    int i = 45;
    yy = SQRT(i);
    __mingw_printf("%.17Lf\n", yy);

    yyy = SIN(xxx);
    __mingw_printf("%.17Lf\n", yyy);*/

    //Listing 16.16
    // пример применения atexit()
    /*int n;

    atexit(sign_off); //регистрация ф-и sign_off()
    puts("Введите целое число:");
    if (scanf("%d", &n) != 1)
    {
        puts("Это не целое число!");
        atexit(too_bad);
        exit(EXIT_FAILURE);
    }

    printf("%d является %s.\n", n, (n % 2 == 0)? "четным" : "нечетным");*/

    //Listing 16.17
    //использование быстрой сортировки для упорядочения групп чисел
    /*double vals[NUM];
    fillarray(vals, NUM);
    puts("Список случайных чисел:");
    showarray(vals, NUM);
    qsort(vals, NUM, sizeof(double), mycomp);
    puts("Отсортированный список:");
    showarray(vals, NUM);*/

    //Listing 16.18
    //использование assert()
    /*double x, y, z;

    puts("Введите пару чисел (0 0 для завершения):");
    while(scanf("%lf%lf", &x, &y) == 2 && (x != 0 || y != 0))
    {
        z = x*x - y*y;
        assert(z>=0);
        printf("Результатом является %f\n", sqrt(z));
        puts("Введите следующую пару чисел: ");
    }

    puts("Программа завершена.");*/

    //Listing 16.19
    //puts("Тип char имеет 16 битов.");

    //Listing 16.20
    //использование функций memcpy() и memmove()
    /*int values[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target[SIZE];
    double curious[SIZE/2] = {2.0, 2.0e5, 2.0e10, 2.0e20, 5.0e30};

    puts("Использование memcpy():");
    puts("Значения (исходные данные):");
    show_array(values, SIZE);
    memcpy(target, values, SIZE*sizeof(int));
    puts("Целевые данные (копия знвчений):");
    show_array(target, SIZE);

    puts("\nИспользование memmove() c перекрывающимися областями:");
    memmove(values+2, values, 5*sizeof(int));
    puts("значения -- элементы 0-5 скопированы в элементы 2-7:");
    show_array(values, SIZE);

    puts("Использование memcpy() для копирования double в int:");
    memcpy(target, curious, (SIZE/2)*sizeof(double));
    puts("Целевые данные 5 значений double в 10 позициях int):");
    show_array(target, SIZE/2);
    show_array(target+5, SIZE/2);*/

    //Listing 16.21
    //использование переменного числа аргументов
    double s,t;
    s = sum(3, 1.1, 2.5, 13.3);
    t = sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1);
    printf("%d\n", J);
    printf("Возвращаемое значение sum s  = %g\n", s);
    printf("Возвращаемое значение sum t  = %g\n", t);

    return 0;
}

double sum(int lim, ...)
{
    va_list ap;         //объявление объекта для хранения аргументов
    double tot = 0;
    int i;

    va_start(ap, lim);      //инициализация ap списком аргументов
    for (i = 0; i < lim; i++)
        tot+=va_arg(ap, double);    //доступ к каждому элементу в списке аргументов
    va_end(ap);                     //очистка
    return tot;
}

void show_array(const int ar[], int n)
{
    int i;
    for (i=0; i<n; i++)
        printf("%d ", ar[i]);
    putchar('\n');
}

//сортировка по возрастанию
int mycomp(const void *p1, const void *p2)
{
    //для доступа к значениям необходимо использовать указатели на double
    const double *a1 = (const double *)p1;
    const double *a2 = (const double *)p2;

    if (*a1 < *a2)
        return -1;
    else if (*a1 == *a2)
        return 0;
    else
        return 1;

}

void showarray(const double ar[], int n)
{
    int index;
    for (index = 0; index < n; index++)
    {
        printf("%9.4f ", ar[index]);
        if (index % 6 == 5)
            putchar('\n');
    }
    if (index % 6 != 0)
        putchar('\n');
}

void fillarray(double ar[], int n)
{
    int index;
    for (index = 0; index < n; index++)
        ar[index] = (double)rand()/((double)rand()+0.1);
}

void sign_off()
{
    puts("Завершение работы очередной замечательной программы от");
    puts("SeeSaw Software!");
}

void too_bad()
{
    puts("SeeSaw Software приносит искренние соболезнования");
    puts("в связи с отказом программы.");
}

Polar_V rect_to_polar(Rect_V rv)
{
    Polar_V pv;
    pv.magnitude = sqrt(rv.x * rv.x + rv.y * rv.y);
    if (pv.magnitude == 0)
        pv.angle = 0.0;
    else
        pv.angle = RAD_TO_DEG * atan2(rv.y, rv.x);
    return pv;
}

/*определения функций*/
void get_names(names *pn)
{
    printf("Введите свое имя:\n");
    s_gets(pn->first, SLEN);
    printf("Введите свою фамилию:\n");
    s_gets(pn->last, SLEN);

}

void show_names(const names *pn)
{
    printf("%s %s", pn->first, pn->last);
}

char * s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
