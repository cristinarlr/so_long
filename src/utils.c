#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

/* PARA PRINTEAR Y TESTEAR */

void print_string(char *s)
{
    int i = 0;
    int count = 1;

    printf("Veamos la string:\n");
    while(s[i])
    {
        printf("s[%i] = %c; count: %i\n", i, s[i], count);
        i++;
        count++;
    }
    printf("s[%i] = NULL; count: %i\n", i, count);
}


// ESTA FUNCION ESTA DANDO SEGFAULT
void print_map(char **arr)
{
    int i = 0;
    int j = 0;
    int count = 1;

    printf("Veamos el arr:\n");
    while(arr[i])
    {
        while(arr[i][j])
        {
            printf("arr[%i][%i] = %c; count: %i\n", i, j, arr[i][j], count);
            j++;
        }
        i++;
        count++;
    }
    printf("s[%i] = NULL; count: %i\n", i, count);
}