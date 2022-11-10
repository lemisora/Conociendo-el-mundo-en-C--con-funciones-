#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define max 50

struct registroNom/*Registro que sirve para almacenar el nombre de cada usuario*/
{
    char nombre[max];
};

void pideNombres(struct registroNom *a)/*Función que solicita los nombres*/
{
    printf("Primer jugador ingrese su nombre:\n");
    scanf("%s",a[0].nombre);
    printf("Segundo jugador ingrese su nombre:\n");
    scanf("%s",a[1].nombre);
}

int main()
{
    int i,num=0;
    printf("Ingrese el número de países con los que quiere jugar:\n");
    scanf("%d",&num);
    char paises[][max]={"Irán","China","India","México","México","Francia","Irán","Francia","Tanzania"},
        ciudades[][max]={"Ardebil","Cantón","Chennai","Tasquillo","Puebla","Niza","Hamadán","Normandía","Iringa"},
        capitales[][max]={"Teherán","Pekín","Nueva Dehli","Ciudad de México","Ciudad de México","París","Teherán","París","Dodoma"},
        idiomas[][max]={"Persa","Cantonés","Tamilés","Otomí","Español","Francés","Persa","Normando","Bantú"};

    char tabla[3][num][max];

    struct registroNom nom;
    pideNombres(&nom);
    for (i=0;i<num;i++)
    {
        strcpy(tabla[0][i],ciudades[i]);
        strcpy(tabla[1][i],capitales[i]);
        strcpy(tabla[2][i],idiomas[i]);
    }

    
    
    return 0;
}
