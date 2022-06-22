#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#define MSG "Hello world!"
#define SLEN 40
#define LIM 10
#define HALT ""
#define STOP "quit"
#define STLEN 15
#define SIZE 30
#define BUGSIZE 13
#define ANSWER "LENIN"
#define LISTSIZE 7
#define TARGSIZE 7
#define LIMIT 81


char * func_12(char *st);
char * s_gets(char *st, int n);

void func_exec_1(int n, char words[]);
void func_exec_2(int n, char words[]);
void func_exec_3(int n, char words[]);

int s_strlen(char *str);

void put1(const char *string);
int put2(const char *string);
void fit(char *, unsigned int);
void stsrt(char *strings[], int num); /*функция сортировки строк*/
void stsrt_11(char *strings[], int num);
void stsrt_12(char *strings[], int num);

char * find_sym(const char *str, char sym);
int is_within(char *str, char sym);
char *mystrncpy(char *str1, char *str2, int n);
char *string_in(const char *str1, const char *str2);
void *obr_str(char *str1, char *str2);
int my_atoi(char *in);

void func_exec_10(char *str);

void ToUpper(char *);
int PunctCount(const char *);

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Rus");

    //Listing 11.3
    /*char ar[] = MSG;
    const char *pt = MSG;

    printf("Адрес \"Hello!\": %p \n", "Hello!");
    printf("Адрес ar: %p\n", ar);
    printf("Адрес pt: %p\n", pt);
    printf("Адрес MSG: %p\n", MSG);
    printf("Адрес \"Hello!\": %p \n", "Hello!");*/

    //Listing 11.4
    /*const char *my[LIM] = {
        "Hi", "my", "best", "frend"
    };

    char your[LIM][SLEN] = {
        "No", "I", "dont", "best", "frend"
    };

    puts("Выведем строки:");
    printf("%-52s %-25s\n", "Vasiliy", "Petr");
    for (int i = 0; i < LIM; i++)
        printf("%-52s %-25s\n", my[i], your[i]);

    printf("\nРазмер my: %d, размер your: %d\n", sizeof(my), sizeof(your));*/

    //Listing 11.5
    /*const char * mesg = "Не позволяйте себя запутать!";
    const char * copy;

    copy = mesg;
    printf("%s\n", copy);
    printf("mesg = %s; &mesg = %p; value = %p\n", mesg, &mesg, mesg);
    printf("copy = %s; &copy = %p; value = %p\n", copy, &copy, copy);*/

    //Listing 11.6, 11.7
    /*char arr[STLEN];
    puts("Введите строку.");
    fgets(arr, STLEN, stdin);
    //gets(arr);
    printf("Ваша строка, выведенная дважды:\n");
    //printf("%s\n", arr);
    puts(arr);
    fputs(arr, stdout);
    puts("Введите еще одну строку.");
    fgets(arr, STLEN, stdin);
    printf("Ваша строка, выведенная дважды:\n");
    puts(arr);
    fputs(arr, stdout);
    puts("Готово.");*/

    //Listing 11.8
    /*char words[STLEN];
    puts("Введите строки (или пустую строку для выхода из программы):");
    while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
        fputs(words, stdout);
    puts("Готово.");*/

    //Listing 11.9
    /*char words[STLEN];
    int i;
    puts("Введите строки (или пустую строку для выхода из программы):");
    while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
    {
        i=0;
        while (words[i]!='\n' && words[i] != '\0')
            i++;
        if (words[i] == '\n') words[i] == '\0';
        else
            while (getchar() != '\n')
                continue;

        puts(words);
    }

    puts("Готово.");*/

    //Listing 11.11
    /*char name1[11], name2[11];
    int count;
    printf("Введите два имени.\n");
    count = scanf("%5s %10s", name1, name2);
    printf("Прочитано %d имени: %s и %s.\n", count, name1, name2);*/

    /*put1("Hello\nworld!");
    printf("%d ", put2("Hello\nworld!"));*/

    //Listing 11.17
    /*char mesg[] = "Hello world, how are you?";
    puts(mesg);
    fit(mesg, 10);
    puts(mesg);
    puts("See yet some strings.");
    puts(mesg+13);*/

    //Listing 11.18, 11.19
    /*char flower[SIZE];
    char addon[] = " beatiful.";
    char bug[BUGSIZE];
    int available;

    puts("Какой у вас любимый цветок?");
    s_gets(flower, SIZE);

    if ((strlen(addon) + strlen(flower) + 1) <= SIZE)
        strcat(flower, addon);

    puts(flower);

    puts("Какое у вас любимое насекомое?");
    s_gets(bug, BUGSIZE);
    available = BUGSIZE - strlen(bug) - 1;
    strncat(bug, addon, available);
    puts(bug);

    puts("Программа завершена.");*/

    //Listing 11.20
    /*char trym[SIZE];
    puts("Кто похоронен в могиле Ленина?");
    s_gets(trym, SIZE);

    ToUpper(trym);

    while (strcmp(trym, ANSWER))
    {
        puts("Неправильно! Пoпытайтесь еще раз.");
        s_gets(trym, SIZE);
    }

    puts("Теперь правильно!");*/

    //Listing 11.23
    /*char input[LIM][SIZE];
    int ct = 0;
    printf("Введите до %d строк (или quit для завершения):\n", LIM);
    while (ct<LIM && s_gets(input[ct], SIZE) != NULL &&
           strcmp(input[ct], STOP) != 0 )
        ct++;
    printf("Введено %d строк(и)\n", ct);*/

    //Listing 11.24
    /*const char *list[LISTSIZE] =
    {
        "astronom", "astatism", "astrofisika",
        "ostrakism", "asterism", "astrolabia"
    };
    int count =0;
    int i;

    for (i = 0; i < LISTSIZE; i++)
        if (strncmp(list[i], "astro", 5)==0)
        {
            printf("Найдено: %s\n", list[i]);
            count++;
        }

    printf("Количество слов в списке, начинающихся "
           "с astro: %d\n", count);*/

    //Listing 11.25
    /*char qwords[LIM][SIZE];
    char temp[SIZE];
    int i = 0;

    printf("Введите %d слов, которые начинаются с буквы k:\n", LIM);
    while (i < LIM && s_gets(temp, SIZE))
    {
        if (temp[0] != 'k')
            printf("%s не начинается с буквы k!\n", temp);
        else
        {
            strcpy(qwords[i], temp);
            i++;
        }
    }

    puts("Список принятых слов:");
    for (i=0; i< LIM; i++)
        puts(qwords[i]);*/

    //Listing 11.26
    /*const char *orig = ANSWER;
    char copy[SIZE] = "Hello world, happy day";
    char *ps;

    puts(orig);
    puts(copy);
    ps = strcpy(copy+7, orig);
    puts(copy);
    puts(ps);*/

    //Listing 11.27
    /*char qwords[LIM][TARGSIZE];
    char temp[SIZE];
    int i = 0;

    printf("Введите %d слов, которые начинаются с буквы k:\n", LIM);
    while (i < LIM && s_gets(temp, SIZE))
    {
        if (temp[0] != 'k')
            printf("%s не начинается с буквы k!\n", temp);
        else
        {
            strncpy(qwords[i], temp, TARGSIZE-1);
            qwords[i][TARGSIZE-1] = '\0';
            i++;
        }
    }

    puts("Список принятых слов:");
    for (i=0; i< LIM; i++)
        puts(qwords[i]);*/

    //Listing 11.29
    //Сортировка строк в алфавитном порядке
    /*char input[LIM][SIZE];
    char *ptstr[LIM];
    int ct = 0;
    int k;

    printf("Введите до %d строк, и они будут отсортированы.\n", LIM);
    printf("Чтобы остановиить ввод, нажмите клавишу Enter в начале строки.\n");
    while (ct < LIM && s_gets(input[ct], SIZE) != NULL &&
           input[ct][0] != '\0')
    {
        ptstr[ct] = input[ct];
        ct++;
    }

    stsrt(ptstr, ct);
    puts("\nОтсортированный список:\n");
    for(k=0; k < ct; k++)
        puts(ptstr[k]);*/

    //Listing 11.30
    /*char line[LIMIT];
    char * find;

    puts("Введите строку:");
    fgets(line, LIMIT, stdin);
    find = strchr(line, '\n');
    if (find)
        *find = '\0';
    ToUpper(line);
    puts(line);
    printf("Эта строка содержит %d знаков препинания.\n", PunctCount(line));*/

    //Listing 11.31
    /*int count;
    printf("Количество аргументов, указанных в командной строке: %d\n", argc - 1);
    for (count = 1; count < argc; count++)
        printf("%d: %s\n", count, argv[count]);
    printf("\n");*/

    //Listing 11.32
    /*int i, times;
    if (argc<2 || (times=atoi(argv[1])) <1)
        printf("Использование: %s положительное число\n", argv[0]);
    else
        for (i=0; i < times; i++)
            puts("Хорошего дня!");*/

    //Listing 11.33
    /*char number[LIM];
    char *end;
    long value;

    puts("Введите число (или пустую строку для выхода из программы:)");
    while (s_gets(number, LIM) && number[0]!= '\0')
    {
        value = strtol(number, &end, 10);
        printf("десятичный ввод, десятичный вывод: %ld, прекращен"
               " на %s (%d)\n", value, end, *end);
        value = strtol(number, &end, 16);
        printf("шестнадцатеричный ввод, шестнадцатеричный вывод: %ld, прекращен"
               " на %s (%d)\n", value, end, *end);
    }

    char * M3 = "chat";
    while (*M3)
        puts(M3++);

    puts(--M3);
    puts(--M3);

    printf("Количество символов: %d\n", s_strlen(ANSWER));

    char *temp;
    temp = func_12(ANSWER);
    printf("%s\n", temp);*/


    //Упражнение 1
    /*Разработайте и протестируйте функцию, которая извлекает из ввода следующие
    n символов (включая символы пробела, табуляции и новой строки), сохраняя
    результаты в массиве, адрес которого передается в качестве аргумента.*/

    /*char in[STLEN]; //Массив для хранения элем ввода
    memset(in, 0x00, sizeof(in));
    func_exec_1(STLEN, in);
    fputs(in, stdout);
    puts("\nГотово.");*/

    //Упражнение 2
    /*Модифицируйте и протестируйте функцию из упражнения 1, обеспечив в ней
    прекращение ввода после n символов либо при достижении первого символа
    пробела, табуляции или новой строки, в зависимости от того, что произойдет
    раньше. (Не ограничивайтесь только использованием scanf ().)*/

    /*char in[STLEN];
    //memset(in, 0x00, sizeof(in));
    puts("Введите текст:");
    func_exec_2(STLEN, in);
    fputs(in, stdout);
    puts("\nГотово.");*/

    //Упражнение 3
    /*Разработайте и протестируйте функцию, которая читает первое слово из строки
    ввода в массив и отбрасывает ос^тальную часть строки. Функция должна пропус­
    кать ведущие пробельные символы. Определите слово как последовательность
    символов, не содержащую символов пробела, табуляции или новой строки.
    Используйте функцию getchar (), а не scanf ().*/

    /*char in[STLEN];
    //memset(in, 0x00, sizeof(in));
    puts("Введите текст:");
    func_exec_3(STLEN, in);
    fputs(in, stdout);
    puts("\nГотово.");*/

    //Упражнение 4
    /*Разработайте и протестируйте функцию, подобную описанной в упражнении 3,
    за исключением того, что она принимает второй параметр, указывающий макси­
    мальное количество символов, которые могут быть прочитаны.*/
    //(func_exec_3();)

    //Упражнение 5
    /*Разработайте и протестируйте функцию, которая ищет в переданной в первом
параметре строке первое вхождение символа, заданного во втором параметре.
Функция должна возвратить указатель на этот символ, если он найден, и ноль
в противном случае. (Поведение этой функции дублирует работу библиотечной
функции strchr ().) Протестируйте функцию в завершенной программе, кото­
рая использует цикл для передачи входных значений созданной функции.*/

    /*char *str1 = "Hello world!";
    puts(str1);
    //char *find;
    //find = find_sym(str1, ' ');

    for (int i = 0; i < 10; i++)
    {
        puts(find_sym(str1, ' '+i));
    }*/

    //Упражнение 6
    /*Напишите функцию по имени is_within (), которая в качестве двух своих па­
раметров принимает символ и указатель на строку. Функция должна возвращать
ненулевое значение, если заданный символ содержится в строке, и ноль в про­
тивном случае. Протестируйте функцию в завершенной программе, которая ис­
пользует цикл для передачи входных значений созданной функции.*/

    /*char *str1 = "Hello world!";
    puts(str1);
    //char *find;
    //find = find_sym(str1, ' ');

    for (int i = 0; i < 10; i++)
    {
        //puts(is_within(str1, ' '+i));
        printf("%d\n", is_within(str1, 'n'+i));
    }*/

    //Упражнение 7
    /*Функция strncpy ( s1, s2, n) копирует в точности n символов из строки s2 в
строку sl, при необходимости усекая s2 или дополняя ее нулевыми символа­
ми. Целевая строка может не содержать завершающего нулевого символа, если
длина строки s2 равна или больше n. Функция возвращает строку sl. Напишите
свою версию этой функции и назовите ее mystrncpy (). Протестируйте функ­
цию в завершенной программе, которая использует цикл для передачи входных
значений созданной функции.*/

    /*char str1[] = "Hello world!";
    char *str2 = "I love you.";
    puts(str1);
    //char *find;
    //find = find_sym(str1, ' ');

    puts(mystrncpy((str1+5), str2, strlen(str2)));
    for (int i = 0; i < 10; i++)
    {
        puts(mystrncpy(str1 + i, str2, strlen(str2)));
        //printf("%d\n", mystrncpy(str1, 'n'+i));
    }*/

    //Упражнение 8
    /*Напишите функцию string_in (), которая принимает в качестве аргументов
два указателя на строки. Если вторая строка содержится внутри первой, функция
должна возвратить адрес, с которого начинается вторая строка в первой строке.
Например, вызов string_in ( "данные", "ан") возвратит адрес символа а в
строке данные. В противном случае функция должна возвратить нулевой указа­
тель. Протестируйте функцию в завершенной программе, которая использует
цикл для передачи входных значений созданной функции.*/

    /*char *str1 = "Hello world!";
    char *str2 = "k";
    puts(str1);
    //char *find;
    //find = find_sym(str1, ' ');

    puts(string_in(str1, str2));*/

    //Упражнение 9
    /* Напишите функцию, которая заменяет содержимое указанной строки этой же
строкой, но с обратным порядком следования символов. Протестируйте функ­
цию в завершенной программе, которая использует цикл для передачи входных
значений созданной функции.*/

    /*char str1[] = "Hello world!";
    char str2[strlen(str1)+1];

    //char *out;
    puts(str1);
    obr_str(str1, str2);
    puts(str2);*/

    //Упражнение 10
    /*Напишите функцию, которая принимает строку в качестве аргумента и удаля­
ет из нее все пробелы. Протестируйте эту функцию в программе, которая ис­
пользует цикл для чтения строк до тех пор, пока не будет введена пустая строка.
Программа должна применять эгу функцию к каждой входной строке и отобра­
жать результат.*/

    /*char in[50] = "Fuyteu jrgufg erug urgyi!";

    puts(in);
    func_exec_10(in);
    puts(in);*/

    /*while (fgets(in, 50, stdin) != '\0') {
        fputs(in, stdout);
    }*/

    //Упражнение 11
    /*Напишите программу, которая читает до 10 строк и или до появления EOF, в
зависимости от того, что произойдет раньше. Функция должна предложить
пользователю меню с пятью вариантами: вывод исходного списка строк, вывод
строк согласно последовательности сопостааления ASCII, вывод строк в порядке
возрастания длины, вывод строк в порядке возрастания длины первого слова
в строке и выход из программы. М е н ю должно отображаться до тех пор, пока
пользователь не выберет вариант выхода из программы. Программа должна
действительно выполнять запрошенные действия.*/

    /*char input[LIM][SIZE];
    char *ptstr[LIM];
    int ct = 0;
    int k;
    int ans = 0;

    printf("Введите до %d строк\n", LIM);
    printf("Чтобы остановиить ввод, нажмите клавишу Enter в начале строки.\n");
    while (ct < LIM && s_gets(input[ct], SIZE) != NULL &&
           input[ct][0] != '\0')
    {
        ptstr[ct] = input[ct];
        ct++;
    }

    //stsrt(ptstr, ct);
    //puts("\nОтсортированный список:\n");

    puts("Строки введены. Выберите действие:\n");
    puts("\t1 Вывод исходного списка строк\n");
    puts("\t2 Вывод строк согласно последовательности сопоставления ASCII\n");
    puts("\t3 Вывод строк в порядке возрастания длины\n");
    puts("\t4 Вывод строк в порядке возрастания длины первого слова\n");
    puts("\t5 Выход из программы\n");

    scanf("%d", &ans);

    switch (ans) {
    case 1:
        for(k=0; k < ct; k++)
            puts(ptstr[k]);
        break;
    case 2:
        stsrt_11(ptstr, ct);
        puts("Вывод строк согласно последовательности сопоставления ASCII");

        for(k=0; k < ct; k++)
        {
            for (int i = 0; i < strlen(ptstr[k]); i++)
                printf("%d ", ptstr[k][i]);
            printf("\n");
        }
        break;
        break;
    case 3:
        stsrt_11(ptstr, ct);
        puts("Вывод строк в порядке возрастания длины");
        puts("Отсортированный список:");
        for(k=0; k < ct; k++)
            puts(ptstr[k]);
        break;
    case 4:
        stsrt_12(ptstr, ct);
        puts("Вывод строк в порядке возрастания длины первого слова");
        puts("Отсортированный список:");
        for(k=0; k < ct; k++)
            puts(ptstr[k]);

        break;
    case 5:
        puts("Программа завершена!\n");
        break;
    default:
        break;
    }*/

    //Упражнение 12
    /*Напишите программу, которая читает входные данные до тех пор, пока нс встре­
тится EOF, и выводит количество слов, количество прописных букв, количество
строчных букв, количество знаков препинания и количество-цифр. Используйте
семейство функций ctype. h.*/

    /*int cnt_wrds = 1;
    int cnt_prps = 0;
    int cnt_str  = 0;
    int cnt_pnkt = 0;
    int cnt_num  = 0;

    char ch;

    while ((ch = getchar()) != '\n')
    {
        if (isspace(ch))
            cnt_wrds++;

        if (isupper(ch))
            cnt_prps++;

        if (islower(ch))
            cnt_str++;

        if (ispunct(ch))
            cnt_pnkt++;

        if (isdigit(ch))
            cnt_num++;
    }

    printf("Количество слов - %d,\n", cnt_wrds );
    printf("количество прописных букв - %d,\n", cnt_prps );
    printf("количество строчных букв - %d,\n", cnt_str  );
    printf("количество знаков препинания - %d,\n", cnt_pnkt );
    printf("количество цифр - %d.", cnt_num );*/

    //Упражнение 13
    /*Напишите программу, которая повторяет на экране аргументы командной стро­
ки в обратном порядке. Другими словами, если аргументами командной строки
являются до скорого свидания, данная программа должна вывести на экран
свидания скорого до.*/

    /*int count;
    printf("Количество аргументов, указанных в командной строке: %d\n", argc - 1);
    for (count = argc-1; count > 0; count--)
        printf("%s ", argv[count]);
    printf("\n");*/

    //Упражнение 14
    /*Напишите программу реализации степенной зависимости, которая работает на
основе командной строки. Первым аргументом командной строки должно быть
число типа do^le, возводимое в определенную степень, а вторым аргументом -
целочисленный показатель степени.*/

    /*int step;
    double num, result;

    printf("Количество аргументов, указанных в командной строке: %d\n", argc - 1);
    for (int i=1; i < argc; i++)
        printf("%s\n", argv[i]);

    num = atof(argv[1]);
    step = atoi(argv[2]);
    result = pow(num,step);


    printf("%f в степени %d = %f\n", num, step, result);*/

    //Упражнение 15
    /*Дня подготовки реализации функции atoi () используйте функции классифика­
ции символов. Эта версия должна возвращать значение О, сели строка ввода не
является полностью числовой.*/

    /*char in[SIZE];
    s_gets(in, SIZE);

    printf("%d\n", my_atoi(in));*/

    //Упражнение 16
    /*Напишите программу, которая читает входные данные до тех пор, пока не встре­
тится EOF, и выводит их на экран. Программа должна распознавать и реализовы­
вать следующие аргументы командной строки:
-р Вывод входных данных в том виде, как есть.
-u Преобразование входных данных в верхний регистр.
-1 Преобразование входных данных в нижний регистр.
Кроме того, сели аргумент входной строки нс указан, программа должна вести
себя так, как сели бы был задан аргумент -р.*/

    /*if (!strcmp(argv[1], "-p"))
    {
        int i = 2;
        printf("Вывод входных данных в том виде, как есть.\n");
        while (i < argc)
            printf("%s ", argv[i++]);
    }

    if (!strcmp(argv[1], "-u"))
    {
        int i = 2;
        printf("Преобразование входных данных в верхний регистр.\n");
        while (i < argc)
        {
            for (int j = 0; j < strlen(argv[i]); j++)
                putchar(toupper(argv[i][j]));

            printf(" ");
            i++;
        }
    }

    if (!strcmp(argv[1], "-l"))
    {
        int i = 2;
        printf("Преобразование входных данных в нижний регистр.\n");
        while (i < argc)
        {
            for (int j = 0; j < strlen(argv[i]); j++)
                putchar(tolower(argv[i][j]));

            printf(" ");
            i++;
        }
    }

    if (strcmp(argv[1], "-p") && strcmp(argv[1], "-u") && strcmp(argv[1], "-l"))
    {
        int i = 1;
        while (i < argc)
            printf("%s ", argv[i++]);
    }

    if (argc <1)
        printf("Программа завершена!\n");*/

    //Глава 12. Упражнение 9
    /*Напишите программу со следующим поведением. Сначала она запрашивает ко­
личество слов, которые ьужно ввести. Затем она предлагает ввести слова, после
чего их отображает. Воспользуйтесь malloc () и ответом на первый запрос (ко­
личество слов), чтобы создать динамический массив с подходящим количеством
указателей на char. (Обратите внимание, что поскольку каждый элемент в мас­
сиве является указателем на char, возвращаемое значение функции malloc ()
должно сохраняться в указателе на указатель на char.) П р и чтении строки про­
грамма должна читать слово во временный массив элементов char, с помощью
malloc () выделять пространство, достаточное для хранения слова, и помещать
адрес в массив указателей на char. Далее программа должна копировать слово
из временного массива в выделенное пространство памяти. Таким образом, в
итоге по^^ается массив указателей на char, каждый из которых ссылается на
объект с размером, необходимым для хранения конкретного слова. Результаты
пробного запуска должны выглядеть следующим образом:
Сколько слов вы хотите ввести? 5
Теперь введите 5 слов:
Мне понравилось выполнять это ^упр^ажненяе
Вот введенные вами слова:
Мне
понравилось
ВЫПОЛНЯТЬ
это
упражнение*/

    int cnt_wrd = 0;
    int ct = 0;
    char temp[100];

    puts("Какое количество слов необходимо ввести?");

    if (scanf("%d", &cnt_wrd)!=1)
    {
        puts("Количество введено некорректно -- программа завершена.");
        exit(EXIT_FAILURE);
    }

    char (*ptstr)[cnt_wrd];

    ptstr = (char *) malloc(cnt_wrd * SIZE * sizeof(char));

    if (ptstr == NULL)
    {
        puts("Не удалось выделить память. Программа завершена.");
        exit(EXIT_FAILURE);
    }

    printf("Введите %d слов:", cnt_wrd);

    s_gets(temp, 100);
    puts(temp);

    int i = 0, j = 0;
    char ch;
    /*while (ch = getchar()!= "\n")
    {
        if (ch == " ")
        {
            i++; j=0;
        }

        ptstr[i][j] = ch;
        j++;
    }*/
    /*char ch;
    for (int i = 0; i < cnt_wrd; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (ch = getchar())
        }
    }

    for (int i = 0; i < cnt_wrd; i++)
    {
         s_gets(ptstr[i], SIZE);
    }*/

    //printf("Чтобы остановиить ввод, нажмите клавишу Enter в начале строки.\n");
    /*while (ct < cnt_wrd && s_gets(input[ct], SIZE) != NULL &&
           input[ct][0] != '\0')
    {
        ptstr[ct] = input[ct];
    }*/

    free(ptstr);

    return 0;
}

int my_atoi(char *in)
{
    int Snum = 0;
    int num;
    int i, j;
    for (i = strlen(in)-1, j = 0; i > -1; i--, j++)
    {
        if (isalpha(in[i]) || ispunct(in[i]))
            return 0;
        else if (isdigit(in[i]))
        {
            num = in[i] - '0';
            Snum += num * pow(10, j);
        }
    }

    return Snum;
}

void stsrt_12(char *strings[], int num)
{
    /*Вывод строк в порядке возрастания длины первого слова*/

    char *temp;
    int top, seek;
    int count_t = 0;
    int count_s = 0;
    for (top=0; top < num-1; top++)
        for (seek=top+1; seek<num;seek++)
        {
            for (int i = 0; i < strlen(strings[top]); i++)
                if (strings[top][i] != ' ')
                    count_t++;
                else break;

            for (int i = 0; i < strlen(strings[seek]); i++)
                if (strings[seek][i] != ' ')
                    count_s++;
                else break;

            if (count_s < count_t)
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
            count_t = 0;
            count_s = 0;
        }


}

void func_exec_10(char *str)
{
    char *pt;
    //const char tokseps[] = " ";
    pt = strtok(str, " ");

    while (pt) {
        //puts(pt);
        pt = strtok(NULL, " ");
        if (pt)
            str = strcat(str, pt);
    }
}

void *obr_str(char *str1, char *str2)
{
    int n = strlen(str1);

    while (*str1)
        *str1++;

    int i = 0;

    do {
        *--str1;
        str2[i] = *str1;
        i++;

    }while (i<n);

    str2[n] = '\0';
}

char *string_in(const char * str1, const char * str2)
{
    char *temp = str2;
    char *ret_val;

    int len_str = strlen(str2);

    if (strlen(str1)<strlen(str2))
        return NULL;

    int count = 0;

    while (*str1++)
    {
        if (*(str1) != *(str2))
            continue;

        while (*str2)
        {
            if (*(str1) == *(str2))
                count++;
            else
            {
                str2 = temp;
                count = 0;
                break;
            }

            if (count == 1)
                ret_val = str1;

            str2++;
            str1++;

            if (count == len_str)
                return ret_val;
        }

    }
    return NULL;
}

char *mystrncpy(char *str1, char *str2, int n)
{
    if (strlen(str1) < strlen(str2))
        n = strlen(str1);

    for (int i = 0; i < n; i++)
    {
        *(str1+i) = *(str2+i);
    }

    return str1;
}

int is_within(char *str, char sym)
{
    while (*str++)
        if (*str == sym)
            return str;
    return 0;
}

char *find_sym(const char *str, char sym)
{
    while (*str++)
        if (*str == sym)
            return str;
    return NULL;
}

char *func_12(char *st) /*test 12*/
{
    char *ret_val;

    ret_val = strchr(st, ' ');

    if (!ret_val)
        return NULL;

    return ret_val;
}

int s_strlen(char *str)
{
    int count = 0;
    while (*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}

void ToUpper(char *str)
{
    while (*str++)
        *str = toupper(*str);
}

int PunctCount(const char *str)
{
    int ct=0;
    while (*str)
    {
        if (ispunct(*str))
            ct++;
        str++;
    }
    return ct;
}

void stsrt(char *strings[], int num)
{
    char *temp;
    int top, seek;
    for (top=0; top < num-1; top++)
        for (seek=top+1; seek<num;seek++)
            if (strcmp(strings[top], strings[seek])>0)
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
}

void stsrt_11(char *strings[], int num)
{
    /*Вывод строк в порядке возрастания длины*/
    char *temp;
    int top, seek;
    for (top=0; top < num-1; top++)
        for (seek=top+1; seek<num;seek++)
            if (strlen(strings[top]) > strlen(strings[seek]))
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
}

void fit(char *string, unsigned int size)
{
    if (strlen(string) > size)
        string[size] = '\0';
}

/*Выводит строку без добавления символа \n */
void put1(const char *string)
{
    while (*string)   //(*string)
        putchar(*string++);
}

int put2(const char *string)
{
    int count = 0;

    while (*string)
    {
        putchar(*string++);
        count++;
    }

    putchar('\n');
    return count;
}

/*char * s_gets(char *st, int n)
{
    char * ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val) // ret_val != NULL
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}*/

char * s_gets(char *st, int n)
{
    char *ret_val;
    char *temp;

    ret_val = fgets(st, n, stdin);

    if (ret_val)
    {
        temp = strchr(st, '\n');
        if (temp)
            *temp = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    /*if (ret_val) // ret_val != NULL
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }*/

    return ret_val;
}

void func_exec_1(int n, char words[])
{
    puts("Введите текст:");
    fgets(words, n, stdin);
}

void func_exec_2(int n, char words[])
{
    fgets(words, n, stdin);

    for (int i = 0; i < n; i++)
    {
        if (words[i] == ' ' || words[i] == '\t'
                || words[i] == '\n')
            words[i] = '\0';
    }

}

void func_exec_3(int n, char words[])
{
    char *temp;
    temp = fgets(words, n, stdin);

    if (temp)
    {
        while (*temp++)
        {
            if (*temp == ' ' || *temp == '\t' || *temp == '\n')
                *temp = '\0';
        }

    }

    /*while (getchar() != '\n')
        continue;*/
}
