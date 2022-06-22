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
        printf("�������������: %s ���_�����\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp=fopen(argv[1], "r")) == NULL)
    {
        printf("�� ������� ������� %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp))!=EOF)
    {
        putc(ch, stdout);
        count++;
    }

    fclose(fp);
    printf("\n���� %s �������� %lu ��������\n", argv[1], count);*/

    //Listing 13.2
    /*FILE *in, *out;
    int ch;
    int LEN = 0;
    int count = 0;

    if (argc < 2)
    {
        fprintf(stderr, "�������������: %s ���_�����\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((in = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "�� ������� ������� ���� \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    LEN = strlen(argv[1]);

    char name[LEN];

    strncpy(name, argv[1], LEN - 4);
    name[LEN-4] = '\0';
    strcat(name, ".red");

    if ((out = fopen(name, "w")) == NULL)
    {
        fprintf(stderr, "�� ������� ������� �������� ����.\n");
        exit(3);
    }

    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);

    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "������ ��� �������� ������.\n");*/

    //Listing 13.3
    /*FILE *fp;
    char words[MAX];

    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stdout, "�� ������� ������� ���� \"wordy\".\n");
        exit(EXIT_FAILURE);
    }

    puts("������� ����� ��� ���������� � ����; ��� ���������� "
         "������� ������ # � ������ ������.");
    while ((fscanf(stdin, "%40s", words)  ==  1) && (words[0] != '#'))
        fprintf(fp, "%s\n", words);
    puts("���������� �����:");
    rewind(fp);
    while (fscanf(fp, "%s", words) == 1)
        puts(words);
    puts("������!");
    if (fclose(fp) != 0)
        fprintf(stderr, "������ ��� �������� �����\n");*/

    //Listing 13.4
    /*char file[SLEN];
    char ch;
    FILE *fp;
    long count, last;

    puts("������� ��� ����� ��� ���������:");
    scanf("%80s", file);
    if ((fp = fopen(file, "rb")) == NULL)
    {
        printf("��������� �� ������� ������� %s\n", file);
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0L, SEEK_END);
    last = ftell(fp);

    for (count = 1L; count <= last; count ++)
    {
        fseek(fp, -count, SEEK_END); //��������� � ��� �����������
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
    puts("������� ��� ����� ����������:");
    s_gets(file_app, SLEN);
    if ((fa = fopen(file_app,"a+")) == NULL)
    {
        fprintf(stderr, "�� ������� ������� %s.\n", file_app);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("�� ������� ������� �������� �����\n", stderr);
        exit(EXIT_FAILURE);
    }
    puts("������� ��� ������� ��������� ����� (��� ������ ������ "
         "��� ����������):");
    while (s_gets(file_src, SLEN) && file_src[0] != '\0')
    {
        if (strcmp(file_src, file_app)==0)
            fputs("�������� ���� � ����� ������ ���� ����������\n", stderr);
        else if ((fs = fopen(file_src, "r")) == NULL)
            fprintf(stderr, "�� ������� ������� %s\n", file_src);
        else
        {
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fputs("�� ������� ������� ������� �����\n", stderr);
                continue;
            }
            append(fs, fa);
            if (ferror(fs) != 0)
                fprintf(stderr, "������ ��� ������ ����� %s.\n", file_src);
            if (ferror(fa) != 0)
                fprintf(stderr,"������ ��� ������ ����� %s.\n", file_app);
            fclose(fs);
            files++;
            printf("���������� ����� %s ���������.\n", file_src);
            puts("������� ��� ���������� ����� (��� ������ "
                 "������ ��� ����������):");
        }
    }
    printf("���������� ���������. ���������� ����������� ������: %d.\n", files);
    rewind(fa);

    printf("���������� %s:\n", file_app);
    while ((ch = getc(fa)) != EOF)
        putchar(ch);
    puts("����������� ���������.");
    fclose(fa);*/

    //Listing 13.6
    /*double numbers[ARSIZE];
    double value;
    const char *file = "numbers.dat";
    int i;
    long pos;
    FILE *iofile;

    //�������� ������ �������� double
    for (i = 0; i < ARSIZE; i++)
        numbers[i] = 100.0 * i; //+ 1.0/(i+1);

    //������� ������� ����
    if ((iofile = fopen(file, "wb")) == NULL)
    {
        fprintf(stderr, "�� ������� ������� ���� %s ��� ������.\n", file);
        exit(EXIT_FAILURE);
    }

    //������ � ���� ������� � �������� �������
    fwrite(numbers, sizeof(double), ARSIZE, iofile);
    fclose(iofile);
    if ((iofile = fopen(file, "rb")) == NULL)
    {
        fprintf(stderr, "�� ������� ������� ���� %s ��� ������������� "
                        "�������.\n", file);
        exit(EXIT_FAILURE);
    }

    //������ ��������� ��������� �� �����
    printf("������� ������ � ��������� 0-%d.\n", ARSIZE-1);
    while (scanf("%d", &i) == 1 && i >= 0 && i < ARSIZE)
    {
        pos = (long) i * sizeof(double); //���������� ��������
        fseek(iofile, pos, SEEK_SET);    //������� � ������ �������
        fread(&value, sizeof(double), 1, iofile);
        printf("�� ����� ������� ��������� �������� %f.\n", value);
        printf("������� ��������� ������ (��� �������� �� ��������� "
               "��������� ��� ����������):\n");
    }

    //����������
    fclose(iofile);
    puts("��������� ���������.");*/

    //TEST #4    
    /*FILE *fp;
    long pos;
    double value;

    if (argc < 2)
    {
        //����� ���� � ����������
        char number[SLEN];
        double values;
        double sum = 0.0;
        int i = 0;

        puts("������� ����� (��� ������ ������ ��� ������ �� ���������:)");
        while (s_gets(number, SLEN) && number[0]!= '\0')
        {
            values = atof(number);
            i++;
            sum += values;
            printf("%f\n", values);
        }

        if (i > 0)
            printf("������� ��������������: %f\n", sum/i);

    }
    else if (argc == 2)
    {
        //����� ���� �� �����
        printf("�������������: ��� ����� %s\n", argv[1]);
        if ((fp = fopen(argv[1], "rb")) == NULL)
        {
            fprintf(stderr, "�� ������� ������� ���� %s ��� ������������� "
                            "�������.\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        for(int i = 0; i < 10; i++)
        {
            pos = (long) i * sizeof(double); //���������� ��������
            fseek(fp, pos, SEEK_SET);    //������� � ������ �������
            fread(&value, sizeof(double), 1, fp);
            printf("%d\t %f.\n", i, value);
            sum +=value;
        }
        if (i > 0)
            printf("������� ��������������: %f", sum/10);
        fclose(fp);
    }
    else
    {
        printf("���� �����������.\n");
    }*/

    //TEST #5
    /* ��������  ���������,  �������  ���������  ���  ���������  ���������  ������.
    ������ ���������� �������� ������, � ������ � ��� �����.  ��������� ����
�� �������� �� ����� ������ �� ������,  ������� �������� ��������� ������.
    ������ ����� ���������������� �������� ����� ������  ' \ � '. �����������, ��� �� ����
�� ����� �� ����� �� ��������� 256 ��������. ��������, ����������� ������������ ���
���� fgets().*/

    /*FILE *fp;
    char ch;
    char line[BUF];

    if (argc == 3)
    {
        ch = argv[1][0];
        printf("�������������: ��� ����� %s\n", argv[2]);
        if ((fp = fopen(argv[2], "r")) == NULL)
        {
            fprintf(stderr, "�� ������� ������� ���� %s ��� ������������� "
                            "�������.\n", argv[2]);
            exit(EXIT_FAILURE);
        }

        printf("���� ������ %c � ������� ����� %s.\n", argv[1][0], argv[2]);

        while (fgets(line, BUF, fp) != NULL) //��������� ������
        {
            if (has_ch(ch, line))
                fputs(line, stdout);
        }
        fclose(fp);
    }*/

    //���������� 1
    /*� � � � � � � � � � � � �  ��������� � �������� 13.1, ����� ��� ���������� ����������
� �  ������ ��� ����� � ������ ��� ����� ������ ������������� ���������� ��
������� ������.*/

    /*int ch;
    char file[BUF];
    FILE *fp;
    unsigned long count = 0;

    printf("������� ��� �����:\n");
    scanf("%80s", file);

    if ((fp=fopen(file, "r")) == NULL)
    {
        printf("�� ������� ������� %s\n", file);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp))!=EOF)
    {
        putc(ch, stdout);
        count++;
    }

    fclose(fp);
    printf("\n���� %s �������� %lu ��������\n", file, count);*/

    //���������� 2
    /* � � � � � � � �  ��������� ����������� ������, ������� �������� ��� ���������
����� � ��� ����� �� ��������� ������. ����������� ����������� ����-�����
� �������� �����, ���� ��� ��������.*/

    /*FILE *fa, *fs;
    int ch;

    if (argc < 3)
    {
        printf("���� ���������� � ������: ���_������_����� ���_��������_�����\n");
        exit(EXIT_FAILURE);
    }

    if ((fa = fopen(argv[2],"a+")) == NULL)
    {
        fprintf(stderr, "�� ������� ������� %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("�� ������� ������� �������� �����\n", stderr);
        exit(EXIT_FAILURE);
    }
    puts("������� ��� ��������� ����� (��� ������ ������ "
         "��� ����������):");

    if (strcmp(argv[1], argv[2])==0)
        fputs("�������� ���� � ����� ������ ���� ����������\n", stderr);
    else if ((fs = fopen(argv[1], "r")) == NULL)
        fprintf(stderr, "�� ������� ������� %s\n", argv[1]);
    else
    {
        if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
        {
            fputs("�� ������� ������� ������� �����\n", stderr);
        }
        append(fs, fa);
        if (ferror(fs) != 0)
            fprintf(stderr, "������ ��� ������ ����� %s.\n", argv[1]);
        if (ferror(fa) != 0)
            fprintf(stderr,"������ ��� ������ ����� %s.\n", argv[2]);
        fclose(fs);
        printf("���������� ����� %s ���������.\n", argv[1]);
    }
    rewind(fa);

    printf("���������� %s:\n", argv[1]);
    while ((ch = getc(fa)) != EOF)
        putchar(ch);
    puts("����������� ���������.");
    fclose(fa);*/

    //���������� 3
    /* � � � � � � � �  ��������� ����������� ������, ������� ���������� ������������
������ ��� ���������� �����. ������������ � ���� ���������, � ��� �����
���� �����. �� � � ����� ������ ������������ � � � � � � �  toupper ()  �� ctype. h
��� �������� ������ � ������� ������� �� ����� ��� ������ � �������� ����.
� � � ������� ����������� ����-����� � ��������� �����.*/

    /*FILE *in, *out;
    int files = 0;
    char file_out[SLEN];
    char file_in[SLEN];
    int ch;
    puts("������� ��� ����� ����������:"); //� ������� ������������ ���-�
    s_gets(file_out, SLEN);
    if ((out = fopen(file_out,"w+")) == NULL)
    {
        fprintf(stderr, "�� ������� ������� %s.\n", file_out);
        exit(EXIT_FAILURE);
    }

    puts("������� ��� ��������� ����� (��� ������ ������ "
         "��� ����������):");
    s_gets(file_in, SLEN);
    if (strcmp(file_in, file_out)==0)
        fputs("�������� ���� � ����� ������ ���� ����������\n", stderr);
    else if ((in = fopen(file_in, "r")) == NULL)
        fprintf(stderr, "�� ������� ������� %s\n", file_in);
    else
    {
        while ((ch = getc(in)) != EOF)
                putc(toupper(ch), out);

        fclose(in);

        printf("���������� ����� %s ���������.\n", file_in);
    }

    rewind(out);

    printf("���������� %s:\n", file_out);
    while ((ch = getc(out)) != EOF)
        putchar(ch);
    puts("\n����������� ���������.");
    fclose(out);*/

    //���������� 4
    /* � � � � � � � �  ���������, ������� ��������������� �����^���� �� ������ �������
��� ���� ������, ������������� � ��������� ������. ��� ���������� ������
����������� argc.*/

    /*FILE *file;
    char ch;

    if(argc < 2)
    {
        printf("������������ ����������: ���_�����1 ���_�����2 ���_�����3 ...\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            if ((file = fopen(argv[i],"r")) == NULL)
            {
                fprintf(stderr, "�� ������� ������� %s.\n", argv[i]);
                exit(EXIT_FAILURE);
            }

            printf("���������� %s:\n", argv[i]);
            while ((ch = getc(file)) != EOF)
                putchar(ch);
            putchar('\n');

            fclose(file);
        }
    }*/

    //���������� 5
    /* � � � � � � � � � � � � �  ��������� � �������� 13.6, ����� ������ �������������� � � �
�������� ��� ������������ ��������� ��������� ������.*/

    /*int size = atoi(argv[1]) ;
    if (size <= 0)
    {
        printf("�������: ��������_int ������_int1 ������_int2 ������_int3 ...\n");
        printf("��������_int ������ ���� > 0");
        exit(EXIT_FAILURE);
    }

    double numbers[size];
    double value;
    const char *file = "numbers.dat";
    int i;
    int ind = 0;
    long pos;
    FILE *iofile;

    //�������� ������ �������� double
    for (i = 0; i < size; i++)
        numbers[i] = 100.0 * i; //+ 1.0/(i+1);

    //������� ������� ����
    if ((iofile = fopen(file, "wb")) == NULL)
    {
        fprintf(stderr, "�� ������� ������� ���� %s ��� ������.\n", file);
        exit(EXIT_FAILURE);
    }

    //������ � ���� ������� � �������� �������
    fwrite(numbers, sizeof(double), size, iofile);
    fclose(iofile);
    if ((iofile = fopen(file, "rb")) == NULL)
    {
        fprintf(stderr, "�� ������� ������� ���� %s ��� ������������� "
                        "�������.\n", file);
        exit(EXIT_FAILURE);
    }

    //������ ��������� ��������� �� �����
    //printf("������� ������ � ��������� 0-%d.\n", size-1);

    for (int i = 2; i < argc; i++)
    {
        ind = atoi(argv[i]);
        if (ind <= 0 || ind >= size)
        {
            printf("�������� ������� %s �����������\n", argv[i]);
            continue;
        }

        pos = (long) ind * sizeof(double); //���������� ��������
        fseek(iofile, pos, SEEK_SET);    //������� � ������ �������
        fread(&value, sizeof(double), 1, iofile);
        printf("�� ����� ������� ��������� �������� %f.\n", value);
    }

    //����������
    fclose(iofile);
    puts("��������� ���������.");*/

    //���������� 6
    /*���������, ���������� � ����������� ��������� ������, ���������� �� ��,
��� ������������ ������, ��� �� ��������� ���������. � � � � � � � � � �  ���������
�� �������� 13.2 ���, ����� ������ ������������� ���������� ��������� ���<)-
�� ��� ���������� ������������ ������ ����������� ����������.*/

    /*FILE *in, *out;
    char file[SLEN];
    int ch;
    int LEN = 0;
    int count = 0;

    printf("������� ��� �����:\n");
    s_gets(file, SLEN);

    if ((in = fopen(file, "r")) == NULL)
    {
        fprintf(stderr, "�� ������� ������� ���� \"%s\"\n", file);
        exit(EXIT_FAILURE);
    }

    LEN = strlen(file);

    char name[LEN];

    strncpy(name, file, LEN - 4);
    name[LEN-4] = '\0';
    strcat(name, ".red");

    if ((out = fopen(name, "w")) == NULL)
    {
        fprintf(stderr, "�� ������� ������� �������� ����.\n");
        exit(3);
    }

    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);

    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "������ ��� �������� ������.\n");
    printf("��������� ���������!\n");*/

    //���������� 7
    /* � � � � � � � �  ���������, ������� ��������� ��� �����. �������� ����� ������
� � � � �  ���� ����� ��������� ������, ���� ��������� ������������ ������ ��.
�. �������� ���, ����� ��� ��������� �������� ������ 1 ������� �����, ������ 1
������� �����, ������ 2 ������� �����, ������ 2 ������� ����� � �.�., ���� ��
����� �������� ��������� ������ ����� �������� (�� ���������� �����) �����.
�. � � � � � � � � � � � � �  ��������� ���, ����� ������ � ����� � ��� � �  ������� � � �
�������� � ����� �������� ������.*/

    /*FILE *file1, *file2;
    char line1[BUF], line2[BUF];

    if (argc < 3)
    {
        printf("������������ ����������: ���_�����1 ���_�����2\n");
        exit(EXIT_FAILURE);
    }

    if ((file1 = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "�� ������� ������� ���� \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((file2 = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "�� ������� ������� ���� \"%s\"\n", argv[2]);
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

    //���������� 8
    /* � � � � � � � �  ���������, ������� ��������� � �������� ���������� ���������
������ ������ � ���� ��� ����� ���� ������. ���� �� �������� �� ������� ��
�������, ��������� ������ ������ ����������� ����. �  ��������� ������ ���
������ ��������� ������ ���� �� ������� � ��������, ������� ��� � ��� �����-
������ ��������� ������. ������ � ����������� ������� �������� � � � � � �  ����
������� ��� ����� � ��� ������. ������������� �������� �������� ������,
����������� �������� ������������ ���������� ���������� � ����������� ��
������ ������. ���� ����  �� ����� ���� ������, ��������� ������ ��������
�� ���� ����� � ���������� � ��������� ���������� �����.*/

    /*FILE *fp;
    char ch, find;
    int count = 0;
    char file[SLEN];

    if (argc < 3)
    {
        //������ ����������� ����
        printf("������� ��� �����:\n");
        s_gets(file, SLEN);
        find = argv[1][0];
        if ((fp = fopen(file, "r")) == NULL)
        {
            fprintf(stderr, "�� ������� ������� ���� %s ��� ������������� "
                            "�������.\n", file);
            exit(EXIT_FAILURE);
        }

        printf("���� ������ %c � ������� ����� %s.\n", argv[1][0], file);


        while ((ch = getc(fp))!=EOF)
        {
            if (ch == find)
                count++;
        }

        printf("������ %c ����������� � ����� %s %d ���(�)\n", argv[1][0], file, count);
        count = 0;

        fclose(fp);
    }
    else
    {
        find = argv[1][0];
        for (int i = 2; i < argc; i++)
        {
            printf("�������������: ��� ����� %s\n", argv[i]);
            if ((fp = fopen(argv[i], "r")) == NULL)
            {
                fprintf(stderr, "�� ������� ������� ���� %s ��� ������������� "
                                "�������.\n", argv[i]);
                exit(EXIT_FAILURE);
            }

            printf("���� ������ %c � ������� ����� %s.\n", argv[1][0], argv[i]);


            while ((ch = getc(fp))!=EOF)
            {
                if (ch == find)
                    count++;
            }

            printf("������ %c ����������� � ����� %s %d ���(�)\n", argv[1][0], argv[i], count);
            count = 0;
        }

        fclose(fp);
    }*/

    //���������� 9
    /* � � � � � � � � � � � � �  ��������� � �������� 13.3, ����� ������ �����
���� ������������� � ������������ � �������� ��� ���������� � ������, ������� � 1.
������������ � ���, ����� ��� ������ ������� ��������� ����� ���������
���� ���������� � ���� �����, ��� ���� ��������� ��������� ��� ����������
�������.*/
    /*FILE *fp, *save;
    char words[MAX];
    int count = 0;
    const char *file = "count.dat";

    //������� ������� ����
    if ((save = fopen(file, "rb")) == NULL)
    {
        fprintf(stderr, "�� ������� ������� ���� %s ��� ������.\n", file);
        exit(EXIT_FAILURE);
    }

    //������ �� �����
    //pos = (long) 0 * sizeof(double); //���������� ��������
    fseek(save, 0L, SEEK_SET);    //������� � ������ �������
    fread(&count, sizeof(int), 1, save);

    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stdout, "�� ������� ������� ���� \"wordy\".\n");
        exit(EXIT_FAILURE);
    }

    puts("������� ����� ��� ���������� � ����; ��� ���������� "
         "������� ������ # � ������ ������.");
    while ((fscanf(stdin, "%40s", words)  ==  1) && (words[0] != '#'))
    {
        fprintf(fp, "%d %s\n", count, words);
        count ++;
    }
    //������ � ����
    if ((save = fopen(file, "wb")) == NULL)
    {
        fprintf(stderr, "�� ������� ������� ���� %s ��� ������������� "
                        "�������.\n", file);
        exit(EXIT_FAILURE);
    }
    fwrite(&count, sizeof(int), 1, save);
    fclose(save);

    puts("���������� �����:");
    rewind(fp);
    while (fscanf(fp, "%s", words) == 1)
        puts(words);
    puts("������!");
    if (fclose(fp) != 0)
        fprintf(stderr, "������ ��� �������� �����\n");*/

    //���������� 10
    /*� � � � � � � �  ���������, � � � � � � � � � � �  ��������� ����, ��� �������� ����������
������������. ����������� ����, ������� ���������� ������������ ������ ��
� � � � �  � �����. ����� ��������� ������ ������� ����� �����, ������� � ����
������� � ���������� �� � � �� � � �  �������� ����� ������. � � � �  ����� ������
����������� ��� ����� �������������� ��� ����������� ��������.*/

    /*FILE *fp;
    char file[SLEN];
    int ind;
    long pos;
    char buffer[BUF];
    char *find;

    printf("������� ��� �����:\n");
    s_gets(file, SLEN);

    if ((fp = fopen(file, "r")) == NULL)
    {
        printf("�� ������� ������� ���� %s.\n", file);
        exit(EXIT_FAILURE);
    }

    printf("������� ������� � �����:\n");

    scanf("%d", &ind);

    if (ind < 0)
    {
        printf("�������� ������� �����������\n");
        exit(EXIT_FAILURE);
    }

    pos = (long) ind * sizeof(char); //���������� ��������
    fseek(fp, pos, SEEK_SET);    //������� � ������ �������
    fread(buffer, sizeof(char), BUF, fp);

    find = strchr(buffer, '\n');
    if (find)
        *find = '\0';

    fputs(buffer, stdout);

    fclose(fp);*/

    //���������� 11
    /* � � � � � � � �  ���������, ������� ��������� ��� ��������� ��������� ������.
� � � � � �  �������� -  ��� ������, � ������ -  ��� �����. � �������� ������ ��
���� � ����� � �������� ��� ������, ���������� ���������. ��������� ����
�� ������������� �� ������, � �� �� �������, ����������� � � � � � � �  fgets ()
������ getc (). ��� ������ ������, ���������� ��������, ���������� �������
strstr ()  (������ ��������� � ���������� 7 �� ����� 11) �� ����������� ���
������� �.*/

    /*FILE *fp;
    char line[BUF];

    if (argc < 3)
    {
        printf("������������ ���������� ��������� ������:\n");
        printf(" ������ ���_�����.\n");
        printf("��������� ���������!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        if ((fp = fopen(argv[2], "r")) == NULL)
        {
            printf("�� ������� ������� ���� %s.\n", argv[2]);
            exit(EXIT_FAILURE);
        }

        while (fgets(line, BUF, fp) != NULL)
            if (strstr(line, argv[1]))
                fputs(line, stdout);
    }*/

    //���������� 12
    /*  �������� ��������� ����, ��������� �� 20 ����� �� 30 ����� �����. � � � � �  ���
����� � � � � � �  ������� � �������� �� � �� 9 � ���������� ���� �� ����� �������
��. ���� �������� � � � � � � � �  �������������� �����������, ��� ���� ��������
�� � �� 9 ������������� ������������ ������ �������. � � � � � � � �  ���������,
������� ������ ���������� ����� ����� � ������ ��������� int � �������� 20
�� 30. � � �  ������ ������� � �������������� ������ ��������� �������������
� ����������� ��������� ������ ������������ �������� �� ����� ������� ���
������������� ������� ��������� char � �������� 20 �� 31. � � �  ���� � ����
��������� ������� �������, 1 -  ������� ����� � �.�.; ������� �������� ��������
������ ��������, � � � � � � � � � �  � � � � � � �  �������. ��������, ������ # �����
�������������� ��� ������������� �������� 9. ��������� ������ (31-�) � ���
��� ������ ������ ���� �������, ������� � ����� ������ �� 20 �����. ���������
������ ���������� �������������� ����������� (�.�. ������� ������) � �����
��������� ��������� � ��������� �����. ��������, �����������, ��� �������
� � �  ������ �������� ���:*/

    /*int data[20][30];
    FILE *in, *out;
    char ch;

    const char * name = "im.txt";

    if ((in = fopen(name, "r")) == NULL)
    {
        printf("������ �������� ����� %s.\n", name);
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
        printf("������ �������� ����� %s.\n", "out.txt");
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

    //���������� 13
    /* ��������� ���������� 12, ��������� ������� ���������� � � � � �  ������ ����
������� ��������.*/

    int data[20][30];
    FILE *in, *out;
    char ch;

    const char * name = "im.txt";

    if ((in = fopen(name, "r")) == NULL)
    {
        printf("������ �������� ����� %s.\n", name);
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
        printf("������ �������� ����� %s.\n", "out.txt");
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

    //���������� 14

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







