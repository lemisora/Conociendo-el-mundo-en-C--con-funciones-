#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define max 50

struct registroNom/*Registro que sirve para almacenar el nombre de cada usuario*/
{
    char nombre[max];
};

int aleatorio(int desde, int hasta)/*Función que otorga un número aleatorio dándole dos números que son el rango que abarca*/
{
    int a;
    a=rand()%hasta+desde;
    return a;
}

void pideNombres(struct registroNom *a)/*Función que solicita los nombres*/
{
    printf("Primer jugador ingrese su nombre:\n");
    scanf("%s",a[0].nombre);
    printf("Segundo jugador ingrese su nombre:\n");
    scanf("%s",a[1].nombre);
}

void muestraPregunta(int opcion, char *country)/*Muestra la pregunta de forma aleatoria de acuerdo a un número generado en main con aleatorio*/
{
    switch (opcion)
    {
        case 1:
            printf("\n¿Cuál es la ciudad de -%s-?\n",country);break;
        case 2:
            printf("\n¿Cuál es la capital de -%s-?\n",country);break;
        case 3:
            printf("\n¿Cuál es el idioma de -%s-?\n",country);break;
    }
}

void cambiaPuntos(int ch,int puntos)/*Función que lleva el control de puntos de los jugadores según ciertas circunstancias*/
{
    switch (ch)
    {
        case 0:
            puntos=puntos+10;
            printf("¡Felicidades has ganado 10 puntos");break;
        case 1:
            puntos=puntos-4;
            printf("¡Qué mala suerte no has podido adivinar así que pierdes 4 puntos!\n");break;
    }
}

int main(void)
{
    int i,turno=0,n=2,num=0,quest,
    pj1=0,pj2=0;
    srand(time(NULL));
    printf("Ingrese el número de países con los que quiere jugar:\n");
    scanf("%d",&num);
    char paises[][max]={"Irán","China","India","México","México","Francia","Irán","Francia","Tanzania"},
        ciudades[][max]={"Ardebil","Cantón","Chennai","Tasquillo","Puebla","Niza","Hamadán","Normandía","Iringa"},
        capitales[][max]={"Teherán","Pekín","Nueva Dehli","Ciudad de México","Ciudad de México","París","Teherán","París","Dodoma"},
        idiomas[][max]={"Persa","Cantonés","Tamilés","Otomí","Español","Francés","Persa","Normando","Bantú"},
        resp[max], *r=resp;

    char tabla[3][num][max];

    struct registroNom *nom;
    nom=(struct registroNom*)malloc(n*sizeof(struct registroNom));/*Se solicita espacio en memoria al compilador y al OS para los registros de nombres*/
    pideNombres(nom);
    for (i=0;i<num;i++)
    {
        strcpy(tabla[0][i],ciudades[i]);
        strcpy(tabla[1][i],capitales[i]);
        strcpy(tabla[2][i],idiomas[i]);
    }

    turno=aleatorio(1,2);
    if(turno==1)
        printf("\nEmpieza el jugador %s\n",nom[turno-1].nombre);
    else
        printf("\nEmpieza el jugador %s\n",nom[turno-1].nombre);
    
    i=0;
    while (i!=num)
    {
        if(turno==1)
        {
            quest=aleatorio(1,3);
            muestraPregunta(quest,paises[i]);
            
            i=i+1;
        }
        else if(turno==2)
        {
            quest=aleatorio(3,1);
            muestraPregunta(quest,paises[i]);
            i=i+1;
        }
        if (pj1>=70||pj2>=70)/*Si se llega a los 70 puntos acumulados se finaliza la ejecución del juego*/
        {
            printf("Un jugador ha llegado al máximo número de puntos en este juego, así que termina el juego\n");
            i=num;
        }
    }

    if (pj1<=0&&pj2<=0)/*Se muestra quien es el que ha ganado al final del juego y los puntos que acumuló cada jugador*/
        printf("\n¿Cómo es posible?\t¡Ha ganado la ignorancia!\n");
    else if (pj1>pj2)
        printf("\nHa ganado el jugador %s\n",nom[0].nombre);
    else if (pj2>pj1)
        printf("\nHa ganado el jugador %s\n",nom[1].nombre);
    else if (pj1==pj2)
        printf("¡Vaya suerte!\n¡Han quedado empatados!\n");
    printf("\nTotal de puntos:\nJugador 1: %d\tJugador 2: %d\n",pj1,pj2);
    return 0;
}