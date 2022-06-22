#include <string.h>
#ifndef NAMES_H_
#define NAMES_H_

/*константы*/
#define SLEN 32

/*объ€влени€ структур*/
struct names_st
{
    char first[SLEN];
    char last[SLEN];
};

/*определени€ типов*/
typedef struct names_st names;

/*прототипы функций*/
void get_names(names*pn);
void show_names(const names *pn);
char * s_gets(char *st, int n);

#endif
