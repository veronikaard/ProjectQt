#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*Напишите программу со следующим поведением. Сначала она запрашивает ко­
личество слов, которые ьужно ввести. Затем она предлагает ввести слова, после
чего их отображает. Воспользуйтесь malloc () и ответом на первый запрос (ко­
личество слов), чтобы создать динамический массив с подходящим количеством
указателей на char. (Обратите внимание, что поскольку каждый элемент в мас­
сиве является указателем на char, возвращаемое значение функции malloc ()
должно сохраняться в указателе на указатель на char.) П р и чтении строки про­
грамма должна читать слово во временный массив элементов char, с помощью malloc()
выделять пространство, достаточное для хранения слова, и помещать
адрес в массив указателей на char. Далее программа должна копировать слово
из временного массива в выделенное пространство памяти.*/
char * s_gets(char *st, int n);

int main(void)
{
    setlocale(LC_ALL, "Rus");
    char temp[50];
    char *pt;
    pt = temp;
    int size = 30;

    int count_word;

    //int i = 0;

    //printf("Сколько слов вы хотите ввести? ");
    //scanf("%d", &count_word);

    //printf("Теперь введите %d слов:\n", count_word);
    count_word = 3;
    char (*ptd)[count_word];

    ptd = (char *)malloc(count_word * size * sizeof(char));

    if (ptd==NULL)
    {
        puts("Не удалось выделить память. Програма завершена.\n");
        exit(EXIT_FAILURE);
    }

    s_gets(temp, 50);
    puts(temp);


    //char k;

    /*for (int i = 0, j = 0, t = 0; i < strlen(temp), j < count_word; i++, t++)
    {
        k = temp[i];
        if (temp[i] == ' ')
        {
            ptd[j][t+1] = '\0';
            j++;
            t = 0;
        }


        ptd[j][t] = temp[i];
    }*/

    int i = 0;
    int j = 0;
    int k = 0;

    while (pt++)
    {
        if (*pt != " ")
        {
            ptd[i][j++] = pt;
        }
        else
        {
            j = 0;
            ptd[i++][j] = pt;
        }

        if (i == count_word-1)
            break;

    }


    int p = 0;
    while (p < count_word) {
        puts(ptd[i]);
        p++;
    }

    free(ptd);


    return 0;
}

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
