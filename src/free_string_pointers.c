#include <stdlib.h>

void    free_string_pointers(char **pointers)
{
    int i;

    i = 0;
    while (pointers[i] != NULL)
    {
        free(pointers[i]);
        i++;
    }
    free(pointers);
}
