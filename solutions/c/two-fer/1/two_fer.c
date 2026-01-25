#include "two_fer.h"

static void addcadena(char *buffer, int *posicion, const char *cadena)
{
    int avance;

    avance = 0;
    while (cadena[avance] != '\0')
    {
        buffer[*posicion] = cadena[avance];
        avance++;
        (*posicion)++;
    }
}

void two_fer(char *buffer, const char *name)
{
    int num;
    char *uno = "One for ";
    char *dos = ", one for me.";

    num = 0;
    addcadena(buffer, &num, uno);
    if ((name == NULL) || (name[0] == '\0'))
        addcadena(buffer, &num, "you");
    else
        addcadena(buffer, &num, name);
    addcadena(buffer, &num, dos);
    buffer[num] = '\0';
}