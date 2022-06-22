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
void stsrt(char *strings[], int num); /*������� ���������� �����*/
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

    printf("����� \"Hello!\": %p \n", "Hello!");
    printf("����� ar: %p\n", ar);
    printf("����� pt: %p\n", pt);
    printf("����� MSG: %p\n", MSG);
    printf("����� \"Hello!\": %p \n", "Hello!");*/

    //Listing 11.4
    /*const char *my[LIM] = {
        "Hi", "my", "best", "frend"
    };

    char your[LIM][SLEN] = {
        "No", "I", "dont", "best", "frend"
    };

    puts("������� ������:");
    printf("%-52s %-25s\n", "Vasiliy", "Petr");
    for (int i = 0; i < LIM; i++)
        printf("%-52s %-25s\n", my[i], your[i]);

    printf("\n������ my: %d, ������ your: %d\n", sizeof(my), sizeof(your));*/

    //Listing 11.5
    /*const char * mesg = "�� ���������� ���� ��������!";
    const char * copy;

    copy = mesg;
    printf("%s\n", copy);
    printf("mesg = %s; &mesg = %p; value = %p\n", mesg, &mesg, mesg);
    printf("copy = %s; &copy = %p; value = %p\n", copy, &copy, copy);*/

    //Listing 11.6, 11.7
    /*char arr[STLEN];
    puts("������� ������.");
    fgets(arr, STLEN, stdin);
    //gets(arr);
    printf("���� ������, ���������� ������:\n");
    //printf("%s\n", arr);
    puts(arr);
    fputs(arr, stdout);
    puts("������� ��� ���� ������.");
    fgets(arr, STLEN, stdin);
    printf("���� ������, ���������� ������:\n");
    puts(arr);
    fputs(arr, stdout);
    puts("������.");*/

    //Listing 11.8
    /*char words[STLEN];
    puts("������� ������ (��� ������ ������ ��� ������ �� ���������):");
    while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
        fputs(words, stdout);
    puts("������.");*/

    //Listing 11.9
    /*char words[STLEN];
    int i;
    puts("������� ������ (��� ������ ������ ��� ������ �� ���������):");
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

    puts("������.");*/

    //Listing 11.11
    /*char name1[11], name2[11];
    int count;
    printf("������� ��� �����.\n");
    count = scanf("%5s %10s", name1, name2);
    printf("��������� %d �����: %s � %s.\n", count, name1, name2);*/

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

    puts("����� � ��� ������� ������?");
    s_gets(flower, SIZE);

    if ((strlen(addon) + strlen(flower) + 1) <= SIZE)
        strcat(flower, addon);

    puts(flower);

    puts("����� � ��� ������� ���������?");
    s_gets(bug, BUGSIZE);
    available = BUGSIZE - strlen(bug) - 1;
    strncat(bug, addon, available);
    puts(bug);

    puts("��������� ���������.");*/

    //Listing 11.20
    /*char trym[SIZE];
    puts("��� ��������� � ������ ������?");
    s_gets(trym, SIZE);

    ToUpper(trym);

    while (strcmp(trym, ANSWER))
    {
        puts("�����������! �o��������� ��� ���.");
        s_gets(trym, SIZE);
    }

    puts("������ ���������!");*/

    //Listing 11.23
    /*char input[LIM][SIZE];
    int ct = 0;
    printf("������� �� %d ����� (��� quit ��� ����������):\n", LIM);
    while (ct<LIM && s_gets(input[ct], SIZE) != NULL &&
           strcmp(input[ct], STOP) != 0 )
        ct++;
    printf("������� %d �����(�)\n", ct);*/

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
            printf("�������: %s\n", list[i]);
            count++;
        }

    printf("���������� ���� � ������, ������������ "
           "� astro: %d\n", count);*/

    //Listing 11.25
    /*char qwords[LIM][SIZE];
    char temp[SIZE];
    int i = 0;

    printf("������� %d ����, ������� ���������� � ����� k:\n", LIM);
    while (i < LIM && s_gets(temp, SIZE))
    {
        if (temp[0] != 'k')
            printf("%s �� ���������� � ����� k!\n", temp);
        else
        {
            strcpy(qwords[i], temp);
            i++;
        }
    }

    puts("������ �������� ����:");
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

    printf("������� %d ����, ������� ���������� � ����� k:\n", LIM);
    while (i < LIM && s_gets(temp, SIZE))
    {
        if (temp[0] != 'k')
            printf("%s �� ���������� � ����� k!\n", temp);
        else
        {
            strncpy(qwords[i], temp, TARGSIZE-1);
            qwords[i][TARGSIZE-1] = '\0';
            i++;
        }
    }

    puts("������ �������� ����:");
    for (i=0; i< LIM; i++)
        puts(qwords[i]);*/

    //Listing 11.29
    //���������� ����� � ���������� �������
    /*char input[LIM][SIZE];
    char *ptstr[LIM];
    int ct = 0;
    int k;

    printf("������� �� %d �����, � ��� ����� �������������.\n", LIM);
    printf("����� ����������� ����, ������� ������� Enter � ������ ������.\n");
    while (ct < LIM && s_gets(input[ct], SIZE) != NULL &&
           input[ct][0] != '\0')
    {
        ptstr[ct] = input[ct];
        ct++;
    }

    stsrt(ptstr, ct);
    puts("\n��������������� ������:\n");
    for(k=0; k < ct; k++)
        puts(ptstr[k]);*/

    //Listing 11.30
    /*char line[LIMIT];
    char * find;

    puts("������� ������:");
    fgets(line, LIMIT, stdin);
    find = strchr(line, '\n');
    if (find)
        *find = '\0';
    ToUpper(line);
    puts(line);
    printf("��� ������ �������� %d ������ ����������.\n", PunctCount(line));*/

    //Listing 11.31
    /*int count;
    printf("���������� ����������, ��������� � ��������� ������: %d\n", argc - 1);
    for (count = 1; count < argc; count++)
        printf("%d: %s\n", count, argv[count]);
    printf("\n");*/

    //Listing 11.32
    /*int i, times;
    if (argc<2 || (times=atoi(argv[1])) <1)
        printf("�������������: %s ������������� �����\n", argv[0]);
    else
        for (i=0; i < times; i++)
            puts("�������� ���!");*/

    //Listing 11.33
    /*char number[LIM];
    char *end;
    long value;

    puts("������� ����� (��� ������ ������ ��� ������ �� ���������:)");
    while (s_gets(number, LIM) && number[0]!= '\0')
    {
        value = strtol(number, &end, 10);
        printf("���������� ����, ���������� �����: %ld, ���������"
               " �� %s (%d)\n", value, end, *end);
        value = strtol(number, &end, 16);
        printf("����������������� ����, ����������������� �����: %ld, ���������"
               " �� %s (%d)\n", value, end, *end);
    }

    char * M3 = "chat";
    while (*M3)
        puts(M3++);

    puts(--M3);
    puts(--M3);

    printf("���������� ��������: %d\n", s_strlen(ANSWER));

    char *temp;
    temp = func_12(ANSWER);
    printf("%s\n", temp);*/


    //���������� 1
    /*������������ � ������������� �������, ������� ��������� �� ����� ���������
    n �������� (������� ������� �������, ��������� � ����� ������), ��������
    ���������� � �������, ����� �������� ���������� � �������� ���������.*/

    /*char in[STLEN]; //������ ��� �������� ���� �����
    memset(in, 0x00, sizeof(in));
    func_exec_1(STLEN, in);
    fputs(in, stdout);
    puts("\n������.");*/

    //���������� 2
    /*������������� � ������������� ������� �� ���������� 1, ��������� � ���
    ����������� ����� ����� n �������� ���� ��� ���������� ������� �������
    �������, ��������� ��� ����� ������, � ����������� �� ����, ��� ����������
    ������. (�� ��������������� ������ �������������� scanf ().)*/

    /*char in[STLEN];
    //memset(in, 0x00, sizeof(in));
    puts("������� �����:");
    func_exec_2(STLEN, in);
    fputs(in, stdout);
    puts("\n������.");*/

    //���������� 3
    /*������������ � ������������� �������, ������� ������ ������ ����� �� ������
    ����� � ������ � ����������� ��^������� ����� ������. ������� ������ ������
    ���� ������� ���������� �������. ���������� ����� ��� ������������������
    ��������, �� ���������� �������� �������, ��������� ��� ����� ������.
    ����������� ������� getchar (), � �� scanf ().*/

    /*char in[STLEN];
    //memset(in, 0x00, sizeof(in));
    puts("������� �����:");
    func_exec_3(STLEN, in);
    fputs(in, stdout);
    puts("\n������.");*/

    //���������� 4
    /*������������ � ������������� �������, �������� ��������� � ���������� 3,
    �� ����������� ����, ��� ��� ��������� ������ ��������, ����������� �����
    ������� ���������� ��������, ������� ����� ���� ���������.*/
    //(func_exec_3();)

    //���������� 5
    /*������������ � ������������� �������, ������� ���� � ���������� � ������
��������� ������ ������ ��������� �������, ��������� �� ������ ���������.
������� ������ ���������� ��������� �� ���� ������, ���� �� ������, � ����
� ��������� ������. (��������� ���� ������� ��������� ������ ������������
������� strchr ().) ������������� ������� � ����������� ���������, ����
��� ���������� ���� ��� �������� ������� �������� ��������� �������.*/

    /*char *str1 = "Hello world!";
    puts(str1);
    //char *find;
    //find = find_sym(str1, ' ');

    for (int i = 0; i < 10; i++)
    {
        puts(find_sym(str1, ' '+i));
    }*/

    //���������� 6
    /*�������� ������� �� ����� is_within (), ������� � �������� ���� ����� ��
�������� ��������� ������ � ��������� �� ������. ������� ������ ����������
��������� ��������, ���� �������� ������ ���������� � ������, � ���� � ���
������ ������. ������������� ������� � ����������� ���������, ������� ��
�������� ���� ��� �������� ������� �������� ��������� �������.*/

    /*char *str1 = "Hello world!";
    puts(str1);
    //char *find;
    //find = find_sym(str1, ' ');

    for (int i = 0; i < 10; i++)
    {
        //puts(is_within(str1, ' '+i));
        printf("%d\n", is_within(str1, 'n'+i));
    }*/

    //���������� 7
    /*������� strncpy ( s1, s2, n) �������� � �������� n �������� �� ������ s2 �
������ sl, ��� ������������� ������ s2 ��� �������� �� �������� �������
��. ������� ������ ����� �� ��������� ������������ �������� �������, ����
����� ������ s2 ����� ��� ������ n. ������� ���������� ������ sl. ��������
���� ������ ���� ������� � �������� �� mystrncpy (). ������������� ����
��� � ����������� ���������, ������� ���������� ���� ��� �������� �������
�������� ��������� �������.*/

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

    //���������� 8
    /*�������� ������� string_in (), ������� ��������� � �������� ����������
��� ��������� �� ������. ���� ������ ������ ���������� ������ ������, �������
������ ���������� �����, � �������� ���������� ������ ������ � ������ ������.
��������, ����� string_in ( "������", "��") ��������� ����� ������� � �
������ ������. � ��������� ������ ������� ������ ���������� ������� �����
����. ������������� ������� � ����������� ���������, ������� ����������
���� ��� �������� ������� �������� ��������� �������.*/

    /*char *str1 = "Hello world!";
    char *str2 = "k";
    puts(str1);
    //char *find;
    //find = find_sym(str1, ' ');

    puts(string_in(str1, str2));*/

    //���������� 9
    /* �������� �������, ������� �������� ���������� ��������� ������ ���� ��
�������, �� � �������� �������� ���������� ��������. ������������� ����
��� � ����������� ���������, ������� ���������� ���� ��� �������� �������
�������� ��������� �������.*/

    /*char str1[] = "Hello world!";
    char str2[strlen(str1)+1];

    //char *out;
    puts(str1);
    obr_str(str1, str2);
    puts(str2);*/

    //���������� 10
    /*�������� �������, ������� ��������� ������ � �������� ��������� � ������
�� �� ��� ��� �������. ������������� ��� ������� � ���������, ������� ��
�������� ���� ��� ������ ����� �� ��� ���, ���� �� ����� ������� ������ ������.
��������� ������ ��������� ��� ������� � ������ ������� ������ � ������
���� ���������.*/

    /*char in[50] = "Fuyteu jrgufg erug urgyi!";

    puts(in);
    func_exec_10(in);
    puts(in);*/

    /*while (fgets(in, 50, stdin) != '\0') {
        fputs(in, stdout);
    }*/

    //���������� 11
    /*�������� ���������, ������� ������ �� 10 ����� � ��� �� ��������� EOF, �
����������� �� ����, ��� ���������� ������. ������� ������ ����������
������������ ���� � ����� ����������: ����� ��������� ������ �����, �����
����� �������� ������������������ ������������� ASCII, ����� ����� � �������
����������� �����, ����� ����� � ������� ����������� ����� ������� �����
� ������ � ����� �� ���������. � � � � ������ ������������ �� ��� ���, ����
������������ �� ������� ������� ������ �� ���������. ��������� ������
������������� ��������� ����������� ��������.*/

    /*char input[LIM][SIZE];
    char *ptstr[LIM];
    int ct = 0;
    int k;
    int ans = 0;

    printf("������� �� %d �����\n", LIM);
    printf("����� ����������� ����, ������� ������� Enter � ������ ������.\n");
    while (ct < LIM && s_gets(input[ct], SIZE) != NULL &&
           input[ct][0] != '\0')
    {
        ptstr[ct] = input[ct];
        ct++;
    }

    //stsrt(ptstr, ct);
    //puts("\n��������������� ������:\n");

    puts("������ �������. �������� ��������:\n");
    puts("\t1 ����� ��������� ������ �����\n");
    puts("\t2 ����� ����� �������� ������������������ ������������� ASCII\n");
    puts("\t3 ����� ����� � ������� ����������� �����\n");
    puts("\t4 ����� ����� � ������� ����������� ����� ������� �����\n");
    puts("\t5 ����� �� ���������\n");

    scanf("%d", &ans);

    switch (ans) {
    case 1:
        for(k=0; k < ct; k++)
            puts(ptstr[k]);
        break;
    case 2:
        stsrt_11(ptstr, ct);
        puts("����� ����� �������� ������������������ ������������� ASCII");

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
        puts("����� ����� � ������� ����������� �����");
        puts("��������������� ������:");
        for(k=0; k < ct; k++)
            puts(ptstr[k]);
        break;
    case 4:
        stsrt_12(ptstr, ct);
        puts("����� ����� � ������� ����������� ����� ������� �����");
        puts("��������������� ������:");
        for(k=0; k < ct; k++)
            puts(ptstr[k]);

        break;
    case 5:
        puts("��������� ���������!\n");
        break;
    default:
        break;
    }*/

    //���������� 12
    /*�������� ���������, ������� ������ ������� ������ �� ��� ���, ���� �� �����
����� EOF, � ������� ���������� ����, ���������� ��������� ����, ����������
�������� ����, ���������� ������ ���������� � ����������-����. �����������
��������� ������� ctype. h.*/

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

    printf("���������� ���� - %d,\n", cnt_wrds );
    printf("���������� ��������� ���� - %d,\n", cnt_prps );
    printf("���������� �������� ���� - %d,\n", cnt_str  );
    printf("���������� ������ ���������� - %d,\n", cnt_pnkt );
    printf("���������� ���� - %d.", cnt_num );*/

    //���������� 13
    /*�������� ���������, ������� ��������� �� ������ ��������� ��������� ����
�� � �������� �������. ������� �������, ���� ����������� ��������� ������
�������� �� ������� ��������, ������ ��������� ������ ������� �� �����
�������� ������� ��.*/

    /*int count;
    printf("���������� ����������, ��������� � ��������� ������: %d\n", argc - 1);
    for (count = argc-1; count > 0; count--)
        printf("%s ", argv[count]);
    printf("\n");*/

    //���������� 14
    /*�������� ��������� ���������� ��������� �����������, ������� �������� ��
������ ��������� ������. ������ ���������� ��������� ������ ������ ����
����� ���� do^le, ���������� � ������������ �������, � ������ ���������� -
������������� ���������� �������.*/

    /*int step;
    double num, result;

    printf("���������� ����������, ��������� � ��������� ������: %d\n", argc - 1);
    for (int i=1; i < argc; i++)
        printf("%s\n", argv[i]);

    num = atof(argv[1]);
    step = atoi(argv[2]);
    result = pow(num,step);


    printf("%f � ������� %d = %f\n", num, step, result);*/

    //���������� 15
    /*��� ���������� ���������� ������� atoi () ����������� ������� ����������
��� ��������. ��� ������ ������ ���������� �������� �, ���� ������ ����� ��
�������� ��������� ��������.*/

    /*char in[SIZE];
    s_gets(in, SIZE);

    printf("%d\n", my_atoi(in));*/

    //���������� 16
    /*�������� ���������, ������� ������ ������� ������ �� ��� ���, ���� �� �����
����� EOF, � ������� �� �� �����. ��������� ������ ������������ � ����������
���� ��������� ��������� ��������� ������:
-� ����� ������� ������ � ��� ����, ��� ����.
-u �������������� ������� ������ � ������� �������.
-1 �������������� ������� ������ � ������ �������.
����� ����, ���� �������� ������� ������ �� ������, ��������� ������ �����
���� ���, ��� ���� �� ��� ����� �������� -�.*/

    /*if (!strcmp(argv[1], "-p"))
    {
        int i = 2;
        printf("����� ������� ������ � ��� ����, ��� ����.\n");
        while (i < argc)
            printf("%s ", argv[i++]);
    }

    if (!strcmp(argv[1], "-u"))
    {
        int i = 2;
        printf("�������������� ������� ������ � ������� �������.\n");
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
        printf("�������������� ������� ������ � ������ �������.\n");
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
        printf("��������� ���������!\n");*/

    //����� 12. ���������� 9
    /*�������� ��������� �� ��������� ����������. ������� ��� ����������� ��
�������� ����, ������� ����� ������. ����� ��� ���������� ������ �����, �����
���� �� ����������. �������������� malloc () � ������� �� ������ ������ (��
�������� ����), ����� ������� ������������ ������ � ���������� �����������
���������� �� char. (�������� ��������, ��� ��������� ������ ������� � ���
���� �������� ���������� �� char, ������������ �������� ������� malloc ()
������ ����������� � ��������� �� ��������� �� char.) � � � ������ ������ ���
������ ������ ������ ����� �� ��������� ������ ��������� char, � �������
malloc () �������� ������������, ����������� ��� �������� �����, � ��������
����� � ������ ���������� �� char. ����� ��������� ������ ���������� �����
�� ���������� ������� � ���������� ������������ ������. ����� �������, �
����� ��^^����� ������ ���������� �� char, ������ �� ������� ��������� ��
������ � ��������, ����������� ��� �������� ����������� �����. ����������
�������� ������� ������ ��������� ��������� �������:
������� ���� �� ������ ������? 5
������ ������� 5 ����:
��� ����������� ��������� ��� ^���^�������
��� ��������� ���� �����:
���
�����������
���������
���
����������*/

    int cnt_wrd = 0;
    int ct = 0;
    char temp[100];

    puts("����� ���������� ���� ���������� ������?");

    if (scanf("%d", &cnt_wrd)!=1)
    {
        puts("���������� ������� ����������� -- ��������� ���������.");
        exit(EXIT_FAILURE);
    }

    char (*ptstr)[cnt_wrd];

    ptstr = (char *) malloc(cnt_wrd * SIZE * sizeof(char));

    if (ptstr == NULL)
    {
        puts("�� ������� �������� ������. ��������� ���������.");
        exit(EXIT_FAILURE);
    }

    printf("������� %d ����:", cnt_wrd);

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

    //printf("����� ����������� ����, ������� ������� Enter � ������ ������.\n");
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
    /*����� ����� � ������� ����������� ����� ������� �����*/

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
    /*����� ����� � ������� ����������� �����*/
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

/*������� ������ ��� ���������� ������� \n */
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
    puts("������� �����:");
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
