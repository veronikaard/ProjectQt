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
#include "names_st.h"           //��������� ������������� �����
#include <stdarg.h>
#define JUST_CHECKING
//_Static_assert(CHAR_BIT == 16, "�������� �������������� 16-������� ��� char");
#define LIMIT 4
#define SIZE 10
#define PR(X, ...) printf("��������� " #X ": "__VA_ARGS__)
#define MYTYPE(X) _Generic((X),\
    int: "int",\
    float: "float",\
    double: "double",\
    default: "other"\
)
#define J SIZE*SIZE

#define RAD_TO_DEG (180/(4*atan(1)))

//���������� ������� ���������� ������ ����, ��������� � ��������
#define SIN(X) _Generic((X),\
    float: sinf((X)/RAD_TO_DEG),\
    long double: sinl((X)/RAD_TO_DEG),\
    default: sin((X)/RAD_TO_DEG)\
    )
//���������� ������� ���������� ����������� �����
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

_Static_assert(sizeof(double)==2*sizeof(int), "double �� ����� �������"
                                              "������ int");

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
    //������� � ���������� ������ ����������
    /*double x = 48;
    double y;

    y = sqrt(x);
    PR(1, "x = %g\n", x);
    PR(2, "x = %.2f, y = %.4f\n", x, y);*/

    //Listing 16.8
    //������������� ��������� names_st
    /*names candidate;
    get_names(&candidate);
    printf("����� ���������� � ���������, ");
    show_names(&candidate);
    printf("!\n");*/

    //Listing 16.9
    //������������� �������� �����������
    /*int i;
    int total = 0;
    for (i = 1; i <= LIMIT; i++)
    {
        total += 2*i*i + 1;
#ifdef JUST_CHECKING
        printf("i = %d, ������������� ����� = %d\n", i, total);
#endif
    }
    printf("�������� ����� = %d\n", total);*/

    //Listing 16.12
    //���������������� ��������������
//#line 1 "cool.h"
/*#if __STDC_VERSION__ != 201112L
#error �������������� C11
#endif
    printf("����: %s.\n", __FILE__);
    printf("����: %s.\n", __DATE__);
    printf("�����: %s.\n", __TIME__);
    printf("������: %ld.\n", __STDC_VERSION__);
    printf("��� ������: %d.\n", __LINE__);
    printf("��� �������: %s.\n", __func__);*/

    //Listing 16.13
    //���������� �����
    /*int d = 5;
    printf("%s\n", MYTYPE(5));
    printf("%s\n", MYTYPE(2.0*d));
    printf("%s\n", MYTYPE(3L));
    printf("%s\n", MYTYPE(&d));*/

    //Listing 16.14
    //����������� ������������� ���������� � ��������
    /*Rect_V input;
    Polar_V result;

    puts("������� ���������� x � y; ������� q ��� ������:");

    while(scanf("%lf %lf", &input.x, &input.y) == 2)
    {
        result = rect_to_polar(input);
        printf("������ = %0.2f, ���� = %0.2f\n", result.magnitude,
               result.angle);
    }
    puts("��������� ���������!");*/

    //Listing 16.15
    //����������� ���������� ��������
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
    // ������ ���������� atexit()
    /*int n;

    atexit(sign_off); //����������� �-� sign_off()
    puts("������� ����� �����:");
    if (scanf("%d", &n) != 1)
    {
        puts("��� �� ����� �����!");
        atexit(too_bad);
        exit(EXIT_FAILURE);
    }

    printf("%d �������� %s.\n", n, (n % 2 == 0)? "������" : "��������");*/

    //Listing 16.17
    //������������� ������� ���������� ��� ������������ ����� �����
    /*double vals[NUM];
    fillarray(vals, NUM);
    puts("������ ��������� �����:");
    showarray(vals, NUM);
    qsort(vals, NUM, sizeof(double), mycomp);
    puts("��������������� ������:");
    showarray(vals, NUM);*/

    //Listing 16.18
    //������������� assert()
    /*double x, y, z;

    puts("������� ���� ����� (0 0 ��� ����������):");
    while(scanf("%lf%lf", &x, &y) == 2 && (x != 0 || y != 0))
    {
        z = x*x - y*y;
        assert(z>=0);
        printf("����������� �������� %f\n", sqrt(z));
        puts("������� ��������� ���� �����: ");
    }

    puts("��������� ���������.");*/

    //Listing 16.19
    //puts("��� char ����� 16 �����.");

    //Listing 16.20
    //������������� ������� memcpy() � memmove()
    /*int values[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target[SIZE];
    double curious[SIZE/2] = {2.0, 2.0e5, 2.0e10, 2.0e20, 5.0e30};

    puts("������������� memcpy():");
    puts("�������� (�������� ������):");
    show_array(values, SIZE);
    memcpy(target, values, SIZE*sizeof(int));
    puts("������� ������ (����� ��������):");
    show_array(target, SIZE);

    puts("\n������������� memmove() c ���������������� ���������:");
    memmove(values+2, values, 5*sizeof(int));
    puts("�������� -- �������� 0-5 ����������� � �������� 2-7:");
    show_array(values, SIZE);

    puts("������������� memcpy() ��� ����������� double � int:");
    memcpy(target, curious, (SIZE/2)*sizeof(double));
    puts("������� ������ 5 �������� double � 10 �������� int):");
    show_array(target, SIZE/2);
    show_array(target+5, SIZE/2);*/

    //Listing 16.21
    //������������� ����������� ����� ����������
    double s,t;
    s = sum(3, 1.1, 2.5, 13.3);
    t = sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1);
    printf("%d\n", J);
    printf("������������ �������� sum s  = %g\n", s);
    printf("������������ �������� sum t  = %g\n", t);

    return 0;
}

double sum(int lim, ...)
{
    va_list ap;         //���������� ������� ��� �������� ����������
    double tot = 0;
    int i;

    va_start(ap, lim);      //������������� ap ������� ����������
    for (i = 0; i < lim; i++)
        tot+=va_arg(ap, double);    //������ � ������� �������� � ������ ����������
    va_end(ap);                     //�������
    return tot;
}

void show_array(const int ar[], int n)
{
    int i;
    for (i=0; i<n; i++)
        printf("%d ", ar[i]);
    putchar('\n');
}

//���������� �� �����������
int mycomp(const void *p1, const void *p2)
{
    //��� ������� � ��������� ���������� ������������ ��������� �� double
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
    puts("���������� ������ ��������� ������������� ��������� ��");
    puts("SeeSaw Software!");
}

void too_bad()
{
    puts("SeeSaw Software �������� ��������� ��������������");
    puts("� ����� � ������� ���������.");
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

/*����������� �������*/
void get_names(names *pn)
{
    printf("������� ���� ���:\n");
    s_gets(pn->first, SLEN);
    printf("������� ���� �������:\n");
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
