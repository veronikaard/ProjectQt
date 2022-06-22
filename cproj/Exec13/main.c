#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#define CNTL_Z '\032'
#define SLEN 81
#define MAX 41
#define BUFSIZE 4096
#define ARSIZE 10
#define BUF 256

void append(FILE *source, FILE *dest);
char *s_gets(char *st, int n);

int has_ch(char ch, const char *line);
int has_ch_count(char ch, const char *line);
int charToInt(char ch);
char table(int val);

//int main()
int main(int argc, char *argv[])
{
    //Listing 13.1
    setlocale(LC_ALL, "Rus");
    /*int ch;
    FILE *fp;
    unsigned long count = 0;

    if (argc != 2)
    {
        printf("Использование: %s имя_файла\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp=fopen(argv[1], "r")) == NULL)
    {
        printf("Не удается открыть %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp))!=EOF)
    {
        putc(ch, stdout);
        count++;
    }

    fclose(fp);
    printf("\nФайл %s содержит %lu символов\n", argv[1], count);*/

    //Listing 13.2
    /*FILE *in, *out;
    int ch;
    int LEN = 0;
    int count = 0;

    if (argc < 2)
    {
        fprintf(stderr, "Использование: %s имя_файла\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((in = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Не удается открыть файл \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    LEN = strlen(argv[1]);

    char name[LEN];

    strncpy(name, argv[1], LEN - 4);
    name[LEN-4] = '\0';
    strcat(name, ".red");

    if ((out = fopen(name, "w")) == NULL)
    {
        fprintf(stderr, "Не удается создать выходной файл.\n");
        exit(3);
    }

    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);

    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Ошибка при закрытии файлов.\n");*/

    //Listing 13.3
    /*FILE *fp;
    char words[MAX];

    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stdout, "Не удается открыть файл \"wordy\".\n");
        exit(EXIT_FAILURE);
    }

    puts("Введите слова для добавления в файл; для завершения "
         "введите символ # в начале строки.");
    while ((fscanf(stdin, "%40s", words)  ==  1) && (words[0] != '#'))
        fprintf(fp, "%s\n", words);
    puts("Содержимое файла:");
    rewind(fp);
    while (fscanf(fp, "%s", words) == 1)
        puts(words);
    puts("Готово!");
    if (fclose(fp) != 0)
        fprintf(stderr, "Ошибка при закрытии файла\n");*/

    //Listing 13.4
    /*char file[SLEN];
    char ch;
    FILE *fp;
    long count, last;

    puts("Введите имя файла для обработки:");
    scanf("%80s", file);
    if ((fp = fopen(file, "rb")) == NULL)
    {
        printf("Программе не удается открыть %s\n", file);
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0L, SEEK_END);
    last = ftell(fp);

    for (count = 1L; count <= last; count ++)
    {
        fseek(fp, -count, SEEK_END); //двигаться в обр направлении
        ch = getc(fp);
        if (ch != CNTL_Z && ch != '\r')
            putchar(ch);
    }

    putchar('\n');
    fclose(fp);*/

    //Listing 13.5
    /*FILE *fa, *fs;
    int files = 0;
    char file_app[SLEN];
    char file_src[SLEN];
    int ch;
    puts("Введите имя файла назначения:");
    s_gets(file_app, SLEN);
    if ((fa = fopen(file_app,"a+")) == NULL)
    {
        fprintf(stderr, "Не удается открыть %s.\n", file_app);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Не удается создать выходной буфер\n", stderr);
        exit(EXIT_FAILURE);
    }
    puts("Введите имя первого исходного файла (или пустую строку "
         "для завершения):");
    while (s_gets(file_src, SLEN) && file_src[0] != '\0')
    {
        if (strcmp(file_src, file_app)==0)
            fputs("Добавить файл в конец самого себя невозможно\n", stderr);
        else if ((fs = fopen(file_src, "r")) == NULL)
            fprintf(stderr, "Не удается открыть %s\n", file_src);
        else
        {
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fputs("Не удается создать входной буфер\n", stderr);
                continue;
            }
            append(fs, fa);
            if (ferror(fs) != 0)
                fprintf(stderr, "Ошибка при чтении файла %s.\n", file_src);
            if (ferror(fa) != 0)
                fprintf(stderr,"Ошибка при записи файла %s.\n", file_app);
            fclose(fs);
            files++;
            printf("Содержимое файла %s добавлено.\n", file_src);
            puts("Введите имя следующего файла (или пустую "
                 "строку для завершения):");
        }
    }
    printf("Добавление завершено. Количество добавленных файлов: %d.\n", files);
    rewind(fa);

    printf("Содержимое %s:\n", file_app);
    while ((ch = getc(fa)) != EOF)
        putchar(ch);
    puts("Отображение завершено.");
    fclose(fa);*/

    //Listing 13.6
    /*double numbers[ARSIZE];
    double value;
    const char *file = "numbers.dat";
    int i;
    long pos;
    FILE *iofile;

    //Создание набора значений double
    for (i = 0; i < ARSIZE; i++)
        numbers[i] = 100.0 * i; //+ 1.0/(i+1);

    //Попытка открыть файл
    if ((iofile = fopen(file, "wb")) == NULL)
    {
        fprintf(stderr, "Не удается открыть файл %s для вывода.\n", file);
        exit(EXIT_FAILURE);
    }

    //Запись в файл массива в двоичном формате
    fwrite(numbers, sizeof(double), ARSIZE, iofile);
    fclose(iofile);
    if ((iofile = fopen(file, "rb")) == NULL)
    {
        fprintf(stderr, "Не удается открыть файл %s для произвольного "
                        "доступа.\n", file);
        exit(EXIT_FAILURE);
    }

    //Чтение избранных элементов из файла
    printf("ВВедите индекс в диапазоне 0-%d.\n", ARSIZE-1);
    while (scanf("%d", &i) == 1 && i >= 0 && i < ARSIZE)
    {
        pos = (long) i * sizeof(double); //вычисление сьещения
        fseek(iofile, pos, SEEK_SET);    //переход в нужную позицию
        fread(&value, sizeof(double), 1, iofile);
        printf("По этому индексу находится значение %f.\n", value);
        printf("Введите следующий индекс (или значение за пределами "
               "диапазона для завершения):\n");
    }

    //завершение
    fclose(iofile);
    puts("Программа завершена.");*/

    //TEST #4    
    /*FILE *fp;
    long pos;
    double value;

    if (argc < 2)
    {
        //Берем ввод с клавиатуры
        char number[SLEN];
        double values;
        double sum = 0.0;
        int i = 0;

        puts("Введите число (или пустую строку для выхода из программы:)");
        while (s_gets(number, SLEN) && number[0]!= '\0')
        {
            values = atof(number);
            i++;
            sum += values;
            printf("%f\n", values);
        }

        if (i > 0)
            printf("Среднее арифметическое: %f\n", sum/i);

    }
    else if (argc == 2)
    {
        //Берем ввод из файла
        printf("Использование: имя файла %s\n", argv[1]);
        if ((fp = fopen(argv[1], "rb")) == NULL)
        {
            fprintf(stderr, "Не удается открыть файл %s для произвольного "
                            "доступа.\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        for(int i = 0; i < 10; i++)
        {
            pos = (long) i * sizeof(double); //вычисление сьещения
            fseek(fp, pos, SEEK_SET);    //переход в нужную позицию
            fread(&value, sizeof(double), 1, fp);
            printf("%d\t %f.\n", i, value);
            sum +=value;
        }
        if (i > 0)
            printf("Среднее арифметическое: %f", sum/10);
        fclose(fp);
    }
    else
    {
        printf("Ввод некорректен.\n");
    }*/

    //TEST #5
    /* Напишите  программу,  которая  принимает  два  аргумента  командной  строки.
    Первым аргументом является символ, а вторым — имя файла.  Программа долж­
на выводить из файла только те строки,  которые содержат указанный символ.
    Строки файла идентифицируются символом новой строки  ' \ п '. Предположим, что ни одна
из строк по длине не превышает 256 символов. Возможно, потребуется использовать фун­
кцию fgets().*/

    /*FILE *fp;
    char ch;
    char line[BUF];

    if (argc == 3)
    {
        ch = argv[1][0];
        printf("Использование: имя файла %s\n", argv[2]);
        if ((fp = fopen(argv[2], "r")) == NULL)
        {
            fprintf(stderr, "Не удается открыть файл %s для произвольного "
                            "доступа.\n", argv[2]);
            exit(EXIT_FAILURE);
        }

        printf("Ищем символ %c в строках файла %s.\n", argv[1][0], argv[2]);

        while (fgets(line, BUF, fp) != NULL) //Выделение строки
        {
            if (has_ch(ch, line))
                fputs(line, stdout);
        }
        fclose(fp);
    }*/

    //Упражнение 1
    /*М о д и ф и ц и р у й т е  программу в листинге 13.1, чтобы она предлагала пользовате­
л ю  ввести имя файла и читала его ответ вместе использования аргументов ко­
мандной строки.*/

    /*int ch;
    char file[BUF];
    FILE *fp;
    unsigned long count = 0;

    printf("Введите имя файла:\n");
    scanf("%80s", file);

    if ((fp=fopen(file, "r")) == NULL)
    {
        printf("Не удается открыть %s\n", file);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp))!=EOF)
    {
        putc(ch, stdout);
        count++;
    }

    fclose(fp);
    printf("\nФайл %s содержит %lu символов\n", file, count);*/

    //Упражнение 2
    /* Н а п и ш и т е  программу копирования файлов, которая получает имя исходного
файла и имя копии из командной строки. Используйте стандартный ввод-вывод
и двоичный режим, если это возможно.*/

    /*FILE *fa, *fs;
    int ch;

    if (argc < 3)
    {
        printf("Мало параметров в строке: имя_исходн_файла имя_копируем_файла\n");
        exit(EXIT_FAILURE);
    }

    if ((fa = fopen(argv[2],"a+")) == NULL)
    {
        fprintf(stderr, "Не удается открыть %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Не удается создать выходной буфер\n", stderr);
        exit(EXIT_FAILURE);
    }
    puts("Введите имя исходного файла (или пустую строку "
         "для завершения):");

    if (strcmp(argv[1], argv[2])==0)
        fputs("Добавить файл в конец самого себя невозможно\n", stderr);
    else if ((fs = fopen(argv[1], "r")) == NULL)
        fprintf(stderr, "Не удается открыть %s\n", argv[1]);
    else
    {
        if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
        {
            fputs("Не удается создать входной буфер\n", stderr);
        }
        append(fs, fa);
        if (ferror(fs) != 0)
            fprintf(stderr, "Ошибка при чтении файла %s.\n", argv[1]);
        if (ferror(fa) != 0)
            fprintf(stderr,"Ошибка при записи файла %s.\n", argv[2]);
        fclose(fs);
        printf("Содержимое файла %s добавлено.\n", argv[1]);
    }
    rewind(fa);

    printf("Содержимое %s:\n", argv[1]);
    while ((ch = getc(fa)) != EOF)
        putchar(ch);
    puts("Отображение завершено.");
    fclose(fa);*/

    //Упражнение 3
    /* Н а п и ш и т е  программу копирования файлов, которая предлагает пользователю
ввести имя текстового файла. выступающего в роли исходного, и имя выход­
ного файла. Пр о г рамма должна использовать ф у н к ц и ю  toupper ()  из ctype. h
для перевода текста в верхний регистр во время его записи в выходной файл.
П р и меняйте стандартный ввод-вывод и текстовый режим.*/

    /*FILE *in, *out;
    int files = 0;
    char file_out[SLEN];
    char file_in[SLEN];
    int ch;
    puts("Введите имя файла назначения:"); //В который записывается инф-я
    s_gets(file_out, SLEN);
    if ((out = fopen(file_out,"w+")) == NULL)
    {
        fprintf(stderr, "Не удается открыть %s.\n", file_out);
        exit(EXIT_FAILURE);
    }

    puts("Введите имя исходного файла (или пустую строку "
         "для завершения):");
    s_gets(file_in, SLEN);
    if (strcmp(file_in, file_out)==0)
        fputs("Добавить файл в конец самого себя невозможно\n", stderr);
    else if ((in = fopen(file_in, "r")) == NULL)
        fprintf(stderr, "Не удается открыть %s\n", file_in);
    else
    {
        while ((ch = getc(in)) != EOF)
                putc(toupper(ch), out);

        fclose(in);

        printf("Содержимое файла %s добавлено.\n", file_in);
    }

    rewind(out);

    printf("Содержимое %s:\n", file_out);
    while ((ch = getc(out)) != EOF)
        putchar(ch);
    puts("\nОтображение завершено.");
    fclose(out);*/

    //Упражнение 4
    /* Н а п и ш и т е  программу, которая последовательно отобр^кает на экране содержи­
мое всех файлов, перечисленных в командной строке. Для управления циклом
используйте argc.*/

    /*FILE *file;
    char ch;

    if(argc < 2)
    {
        printf("Недостаточно аргументов: имя_файла1 имя_файла2 имя_файла3 ...\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            if ((file = fopen(argv[i],"r")) == NULL)
            {
                fprintf(stderr, "Не удается открыть %s.\n", argv[i]);
                exit(EXIT_FAILURE);
            }

            printf("Содержимое %s:\n", argv[i]);
            while ((ch = getc(file)) != EOF)
                putchar(ch);
            putchar('\n');

            fclose(file);
        }
    }*/

    //Упражнение 5
    /* М о д и ф и ц и р у й т е  программу в листинге 13.6, чтобы вместо интерактивного и н ­
терфейса она использовала интерфейс командной строки.*/

    /*int size = atoi(argv[1]) ;
    if (size <= 0)
    {
        printf("Введите: диапазон_int индекс_int1 индекс_int2 индекс_int3 ...\n");
        printf("диапазон_int должен быть > 0");
        exit(EXIT_FAILURE);
    }

    double numbers[size];
    double value;
    const char *file = "numbers.dat";
    int i;
    int ind = 0;
    long pos;
    FILE *iofile;

    //Создание набора значений double
    for (i = 0; i < size; i++)
        numbers[i] = 100.0 * i; //+ 1.0/(i+1);

    //Попытка открыть файл
    if ((iofile = fopen(file, "wb")) == NULL)
    {
        fprintf(stderr, "Не удается открыть файл %s для вывода.\n", file);
        exit(EXIT_FAILURE);
    }

    //Запись в файл массива в двоичном формате
    fwrite(numbers, sizeof(double), size, iofile);
    fclose(iofile);
    if ((iofile = fopen(file, "rb")) == NULL)
    {
        fprintf(stderr, "Не удается открыть файл %s для произвольного "
                        "доступа.\n", file);
        exit(EXIT_FAILURE);
    }

    //Чтение избранных элементов из файла
    //printf("ВВедите индекс в диапазоне 0-%d.\n", size-1);

    for (int i = 2; i < argc; i++)
    {
        ind = atoi(argv[i]);
        if (ind <= 0 || ind >= size)
        {
            printf("Значение индекса %s некорректно\n", argv[i]);
            continue;
        }

        pos = (long) ind * sizeof(double); //вычисление сьещения
        fseek(iofile, pos, SEEK_SET);    //переход в нужную позицию
        fread(&value, sizeof(double), 1, iofile);
        printf("По этому индексу находится значение %f.\n", value);
    }

    //завершение
    fclose(iofile);
    puts("Программа завершена.");*/

    //Упражнение 6
    /*Программы, работающие с аргументами командной строки, полагаются на то,
что пользователь помнит, как их правильно запускать. П е р е п и ш и т е  программу
из листинга 13.2 так, чтобы вместо использования аргументов командной стр<)-
ки она предлагала пользователю ввести необходимую информацию.*/

    /*FILE *in, *out;
    char file[SLEN];
    int ch;
    int LEN = 0;
    int count = 0;

    printf("Введите имя файла:\n");
    s_gets(file, SLEN);

    if ((in = fopen(file, "r")) == NULL)
    {
        fprintf(stderr, "Не удается открыть файл \"%s\"\n", file);
        exit(EXIT_FAILURE);
    }

    LEN = strlen(file);

    char name[LEN];

    strncpy(name, file, LEN - 4);
    name[LEN-4] = '\0';
    strcat(name, ".red");

    if ((out = fopen(name, "w")) == NULL)
    {
        fprintf(stderr, "Не удается создать выходной файл.\n");
        exit(3);
    }

    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);

    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Ошибка при закрытии файлов.\n");
    printf("Программа завершена!\n");*/

    //Упражнение 7
    /* Н а п и ш и т е  программу, которая открывает два файла. Получать имена файлов
м о ж н о  либо через командную строку, либо предложив пользователю ввести их.
а. Сделайте так, чтобы эта программа выводила строку 1 первого файла, строку 1
второго файла, строку 2 первого файла, строку 2 второго файла и т.д., пока нс
будет выведена последняя строка более длинного (по количеству строк) файла.
б. М о д и ф и ц и р у й т е  программу так, чтобы строки с одним и тем ж е  номером в ы ­
водились в одной экранной строке.*/

    /*FILE *file1, *file2;
    char line1[BUF], line2[BUF];

    if (argc < 3)
    {
        printf("Недостаточно аргументов: имя_файла1 имя_файла2\n");
        exit(EXIT_FAILURE);
    }

    if ((file1 = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Не удается открыть файл \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((file2 = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Не удается открыть файл \"%s\"\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    int ok1, ok2;
    int count1 = 0, count2 = 0;
    char *find1, *find2;

    while ((ok1 = !feof(file1)) || (ok2 = !feof(file2)))
    {
        if (ok1)
        {
            fgets(line1, BUF, file1);
            find1 = strchr(line1, '\n');
            if (find1)
                *find1 = '\0';

            printf("**FILE1 %d*** ", count1);
            fputs(line1, stdout);
            count1++;
            //if (feof(file1))
            //    printf("\n");
        }

        if (ok2)
        {
            fgets(line2, BUF, file2);
            find2 = strchr(line2, '\n');
            if (find2)
                *find2 = '\0';
            printf("***FILE2 %d*** ", count2);
            fputs(line2, stdout);
            count2++;
            //if (feof(file1))
            //    printf("\n");
        }

        printf("\n");

    }
    fclose(file1);
    fclose(file2);*/

    //Упражнение 8
    /* Н а п и ш и т е  программу, которая принимает в качестве аргументов командной
строки символ и ноль или более имен файлов. Если за символом не следуют ар­
гументы, программа должна читать стандартный ввод. В  противном случае она
должна открывать каждый файл по очереди и сообщать, сколько раз в нем ветре-
чается указанный символ. Вместе с результатом каждого подсчета д о л ж н ы  быть
указаны имя файла и сам символ. Предусмотрите средства проверки ошибок,
позволяющие выяснить корректность количества аргументов и возможность от­
крытия файлов. Если файл  не может быть открыт, программа должна сообщать
об этом факте и переходить к обработке следующего файла.*/

    /*FILE *fp;
    char ch, find;
    int count = 0;
    char file[SLEN];

    if (argc < 3)
    {
        //Читаем стандартный ввод
        printf("Введите имя файла:\n");
        s_gets(file, SLEN);
        find = argv[1][0];
        if ((fp = fopen(file, "r")) == NULL)
        {
            fprintf(stderr, "Не удается открыть файл %s для произвольного "
                            "доступа.\n", file);
            exit(EXIT_FAILURE);
        }

        printf("Ищем символ %c в строках файла %s.\n", argv[1][0], file);


        while ((ch = getc(fp))!=EOF)
        {
            if (ch == find)
                count++;
        }

        printf("Символ %c встречается в файле %s %d раз(а)\n", argv[1][0], file, count);
        count = 0;

        fclose(fp);
    }
    else
    {
        find = argv[1][0];
        for (int i = 2; i < argc; i++)
        {
            printf("Использование: имя файла %s\n", argv[i]);
            if ((fp = fopen(argv[i], "r")) == NULL)
            {
                fprintf(stderr, "Не удается открыть файл %s для произвольного "
                                "доступа.\n", argv[i]);
                exit(EXIT_FAILURE);
            }

            printf("Ищем символ %c в строках файла %s.\n", argv[1][0], argv[i]);


            while ((ch = getc(fp))!=EOF)
            {
                if (ch == find)
                    count++;
            }

            printf("Символ %c встречается в файле %s %d раз(а)\n", argv[1][0], argv[i], count);
            count = 0;
        }

        fclose(fp);
    }*/

    //Упражнение 9
    /* М о д и ф и ц и р у й т е  программу в листинге 13.3, чтобы каждое слово
было про­нумеровано в соответствии с порядком его добавления в список, начиная с 1.
Позаботьтесь о том, чтобы при втором запуске программы новая нумерация
слов начиналась с того места, где была закончена пумерация при предыдущем
запуске.*/
    /*FILE *fp, *save;
    char words[MAX];
    int count = 0;
    const char *file = "count.dat";

    //Попытка открыть файл
    if ((save = fopen(file, "rb")) == NULL)
    {
        fprintf(stderr, "Не удается открыть файл %s для вывода.\n", file);
        exit(EXIT_FAILURE);
    }

    //Чтение из файла
    //pos = (long) 0 * sizeof(double); //вычисление сьещения
    fseek(save, 0L, SEEK_SET);    //переход в нужную позицию
    fread(&count, sizeof(int), 1, save);

    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stdout, "Не удается открыть файл \"wordy\".\n");
        exit(EXIT_FAILURE);
    }

    puts("Введите слова для добавления в файл; для завершения "
         "введите символ # в начале строки.");
    while ((fscanf(stdin, "%40s", words)  ==  1) && (words[0] != '#'))
    {
        fprintf(fp, "%d %s\n", count, words);
        count ++;
    }
    //Запись в файл
    if ((save = fopen(file, "wb")) == NULL)
    {
        fprintf(stderr, "Не удается открыть файл %s для произвольного "
                        "доступа.\n", file);
        exit(EXIT_FAILURE);
    }
    fwrite(&count, sizeof(int), 1, save);
    fclose(save);

    puts("Содержимое файла:");
    rewind(fp);
    while (fscanf(fp, "%s", words) == 1)
        puts(words);
    puts("Готово!");
    if (fclose(fp) != 0)
        fprintf(stderr, "Ошибка при закрытии файла\n");*/

    //Упражнение 10
    /*Н а п и ш и т е  программу, о т к р ы в а ю щ у ю  текстовый файл, имя которого получается
интерактивно. Организуйте цикл, который предлагает пользователю ввести по­
з и ц и ю  в файле. Затем программа должна вывести часть файла, начиная с этой
позиции и заканчивая сл е д ую щ и м  символом новой строки. Ц и к л  ввода должен
завершаться при вводе отрицательного дли нечислового значения.*/

    /*FILE *fp;
    char file[SLEN];
    int ind;
    long pos;
    char buffer[BUF];
    char *find;

    printf("Введите имя файла:\n");
    s_gets(file, SLEN);

    if ((fp = fopen(file, "r")) == NULL)
    {
        printf("Не удается открыть файл %s.\n", file);
        exit(EXIT_FAILURE);
    }

    printf("Введите позицию в файле:\n");

    scanf("%d", &ind);

    if (ind < 0)
    {
        printf("Значение индекса некорректно\n");
        exit(EXIT_FAILURE);
    }

    pos = (long) ind * sizeof(char); //вычисление сьещения
    fseek(fp, pos, SEEK_SET);    //переход в нужную позицию
    fread(buffer, sizeof(char), BUF, fp);

    find = strchr(buffer, '\n');
    if (find)
        *find = '\0';

    fputs(buffer, stdout);

    fclose(fp);*/

    //Упражнение 11
    /* Н а п и ш и т е  программу, которая принимает два аргумента командной строки.
П е р в ы й  аргумент -  это строка, а второй -  имя файла. П рограмма должна ис­
кать в файле и выводить все строки, содержащие указанную. Поскольку зада­
ча ориентирована на строки, а не на символы, используйте ф у н к ц и ю  fgets ()
вместо getc (). Для поиска строки, содержащей заданную, применяйте функцию
strstr ()  (кратко описанную в упражнении 7 из главы 11) из стандартной биб­
лиотеки С.*/

    /*FILE *fp;
    char line[BUF];

    if (argc < 3)
    {
        printf("Недостаточно аргументов командной строки:\n");
        printf(" строка имя_файла.\n");
        printf("Программа завершена!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        if ((fp = fopen(argv[2], "r")) == NULL)
        {
            printf("Не удается открыть файл %s.\n", argv[2]);
            exit(EXIT_FAILURE);
        }

        while (fgets(line, BUF, fp) != NULL)
            if (strstr(line, argv[1]))
                fputs(line, stdout);
    }*/

    //Упражнение 12
    /*  Создайте текстовый файл, состоящий из 20 строк по 30 целых чисел. Ц е л ы е  зна­
чения д о л ж н ы  входить в диапазон от О до 9 и отделяться друг от друга пробела­
ми. Файл является ц и ф р о в ы м  представлением изображения, при этом значения
от О до 9 воспроизводят возрастающие уровни темноты. Н а п и ш и т е  программу,
которая читает содержимое этого файла в массив элементов int с размером 20
на 30. П р и  грубом подходе к преобразованию такого цифрового представления
в изображение программа должна использовать значения из этого массива для
инициализации массива элементов char с размером 20 на 31. П р и  этом О соот­
ветствует символу пробела, 1 -  символу точки и т.д.; большее значение представ­
ляется символом, з а н и м а ю щ и м  б о л ь ш у ю  площадь. Например, символ # может
использоваться для представления значения 9. Последний символ (31-й) в каж­
дой строке должен быть нулевым, образуя в итоге массив из 20 строк. Программа
должна отобразить результирующее изображение (т.е. вывести строки) и также
сохранить результат в текстовом файле. Например, предположим, что началь­
н ы е  данные выглядят так:*/

    /*int data[20][30];
    FILE *in, *out;
    char ch;

    const char * name = "im.txt";

    if ((in = fopen(name, "r")) == NULL)
    {
        printf("Ошибка открытия файла %s.\n", name);
        exit(EXIT_FAILURE);
    }

    int i = 0, j = 0;

    while (((ch = fgetc(in)) != EOF) && i < 20 && j < 30)
    {
        //fputc(ch, stdout);
        if (isdigit(ch))
        {
            data[i][j] = charToInt(ch);
            j++;
            if (j == 30)
            {
                i++;
                j = 0;
            }
        }
    }

    fclose(in);

    if ((out = fopen("out.txt", "w")) == NULL)
    {
        printf("Ошибка открытия файла %s.\n", "out.txt");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            ch = table(data[i][j]);
            printf("%c ", ch);
            fputc(ch, out);
            fputc(' ', out);
        }

        printf("\n");
        fputc('\n', out);
    }


    fclose(out);*/

    //Упражнение 13
    /* Выполните упражнение 12, используя массивы переменной д л и н ы  вместо стан­
дартных массивов.*/

    int data[20][30];
    FILE *in, *out;
    char ch;

    const char * name = "im.txt";

    if ((in = fopen(name, "r")) == NULL)
    {
        printf("Ошибка открытия файла %s.\n", name);
        exit(EXIT_FAILURE);
    }

    int i = 0, j = 0;

    while (((ch = fgetc(in)) != EOF) && i < 20 && j < 30)
    {
        //fputc(ch, stdout);
        if (isdigit(ch))
        {
            data[i][j] = charToInt(ch);
            j++;
            if (j == 30)
            {
                i++;
                j = 0;
            }
        }
    }

    fclose(in);

    if ((out = fopen("out.txt", "w")) == NULL)
    {
        printf("Ошибка открытия файла %s.\n", "out.txt");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            ch = table(data[i][j]);
            printf("%c ", ch);
            fputc(ch, out);
            fputc(' ', out);
        }

        printf("\n");
        fputc('\n', out);
    }


    fclose(out);

    //Упражнение 14

    return 0;
}

char table(int val)
{
    char ch;
    switch (val) {
    case 0: ch = ' '; break;
    case 1: ch = '*'; break;
    case 2: ch = '+'; break;
    case 3: ch = '$'; break;
    case 4: ch = '@'; break;
    case 5: ch = '%'; break;
    case 6: ch = '~'; break;
    case 7: ch = '|'; break;
    case 8: ch = ')'; break;
    case 9: ch = '#'; break;

    default:
        break;
    }

    return ch;
}

int charToInt(char ch)
{
    char test[3];
    int val = 0;
    test[0] = ch;
    test[1] = '\0';
    val = atoi(test);

    return val;
}

int has_ch(char ch, const char *line)
{
    while (*line)
        if (ch == *line++)
            return(1);
    return 0;
}

void append(FILE *source, FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZE];
    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
        fwrite(temp, sizeof(char), bytes, dest);
}

char *s_gets(char *st, int n)
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







