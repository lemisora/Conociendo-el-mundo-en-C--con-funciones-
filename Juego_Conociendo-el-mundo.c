#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define max 50

struct registroNom/*Registro que sirve para almacenar el nombre de cada usuario*/
{
    char nombre[max];
};

void pideNombres(struct registroNom *a)
{
    printf("Ingrese su nombre el primer jugador:\n");
    scanf("%s",a[0].nombre);
    printf("Ingrese su nombre el segundo jugador:\n");
    scanf("%s",a[1].nombre);
}

int main()
{
    struct registroNom p;
    pideNombres(&p);
    return 0;
}