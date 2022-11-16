#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define max 50/*Se define una constante que indica el máximo de carácteres para las cadenas*/
struct registroNom{ /*Registro que sirve para almacenar el nombre de cada usuario*/
    char nombre[max];
};
int aleatorio(int desde, int hasta){/*Función que otorga un número aleatorio dándole dos números que son el rango que abarca*/
    int a;
    a = rand() % hasta + desde;
    return a;
}
void pideNombres(struct registroNom *a){/*Función que solicita los nombres y los almacena en un registro*/
    printf("*El máximo número de carácteres puede ingresar es de 50*\n\nPrimer jugador ingrese su nombre: ");
    fgets(a[0].nombre, max, stdin);
    printf("Segundo jugador ingrese su nombre: ");
    fgets(a[1].nombre, max, stdin);
}
void muestraPregunta(int opcion, char *country){ /*Muestra la pregunta de forma aleatoria de acuerdo a un número generado en main con aleatorio*/
    switch (opcion){
    case 1:printf("\n¿Cuál es la ciudad de -%s-?\n\tA continuación se muestran las posibles respuestas:\n", country);break;
    case 2:printf("\n¿Cuál es la capital de -%s-?\n\tA continuación se muestran las posibles respuestas:\n", country);break;
    case 3:printf("\n¿Cuál es el idioma de -%s-?\n\tA continuación se muestran las posibles respuestas:\n", country);break;
    default:;break;
    }
}
void posResp(int preg, int n, char lista[][n][max]){ /*Muestra las posibles respuestas de dos formas distintas a la correcta*/
    int aleat= aleatorio(1, 2),f, j;
    if (aleat == 1)/*Se imprimen las posibles respuestas del último al primero*/
        for (f = n - 1; f >= 0; f--)
            printf("\t\t%s\n", lista[preg - 1][f]);
    else{/*Se imprimen las posibles respuestas de dos en dos, imprimiendo primero la primera y la última respuesta, y así sucesivamente hasta que coincidan en número en ese momento se detiene*/
        if (n % 2 != 0){
            f = 0;
            j = n - 1;
            while (f < n && j > 0){
                if (f != j){
                    printf("\t\t%s\n", lista[preg - 1][f]);
                    printf("\t\t%s\n", lista[preg - 1][j]);
                }
                else{
                    printf("\t\t%s\n", lista[preg - 1][f]);
                    f = n;
                    j = 0;
                }
                f = f + 1;
                j = j - 1;
            }
        }
        else{
            j = n - 1;
            for (f = 0; f < n / 2; f++){
                if (f != j){
                    printf("\t\t%s\n", lista[preg - 1][f]);
                    printf("\t\t%s\n", lista[preg - 1][j]);
                    j = j - 1;
                }
                else
                    f = n;
            }
        }
    }
}
void cambiaPuntos(int sumaresta, int *puntos){ /*Función que lleva el control de puntos de los jugadores según ciertas circunstancias*/
    switch (sumaresta){
    case 0:printf("\n\t¡Felicidades has ganado 10 puntos\n");
        *puntos = *puntos + 10;break;
    case 1:printf("\n\t¡Qué mala suerte no has podido adivinar así que pierdes 4 puntos!\n");
        *puntos = *puntos - 4;break;
    default:;break;
    }
}
void muestraResp(int pos, int n, char *count, char res[][n][max]){ /*Esta función se encarga de imprimir los datos correspondientes a un país en cada iteración*/
    printf("\nSe muestran los datos correctos de esta iteración:\n\tPais\tCiudad\tCapital\tIdioma\n\t%s\t%s\t%s\t%s\n", count, res[0][pos], res[1][pos], res[2][pos]);
}
int main(void){
    int i, turno, n = 1, num = 0, quest,/*i es el contador universal, su uso principal es para llevar control del juego, turno indica quien tiene el control, n indica los espacios que malloc usa para reservar memoria, num guarda el número de países con los que se jugarán*/
                  pj1 = 0, pj2 = 0;/*Estas variables almacenan los puntajes de los jugadores*/
    srand(time(NULL)); /*Se inicia la semilla para el rand*/
    char paises[][max] = {"Irán", "China", "India", "México", "México", "Francia", "Irán", "Francia", "Tanzania"},
         ciudades[][max] = {"Ardebil", "Cantón", "Chennai", "Tasquillo", "Puebla", "Niza", "Hamadán", "Normandía", "Iringa"},
         capitales[][max] = {"Teherán", "Pekín", "Nueva_Dehli", "Ciudad_de_México", "Ciudad_de_México", "París", "Teherán", "París", "Dodoma"},
         idiomas[][max] = {"Persa", "Cantonés", "Tamilés", "Otomí", "Español", "Francés", "Persa", "Normando", "Bantú"},
         resp[max], *r = resp, marcar[] = {"+"}, *m = marcar;/*resp almacena las respuestas con ayuda del apuntador r, marcar y el apuntador m ayudan a marcar la respuesta correcta*/
    struct registroNom *nom;/*Aquí se almacenan los nombres*/
    nom = (struct registroNom *)malloc(n * sizeof(struct registroNom)); /*Se solicita espacio en memoria al compilador y al OS para los registros de nombres*/
    pideNombres(nom);
    printf("\nIngrese el número de países con los que quieren jugar (Máximo número permitido {9} ): ");
    scanf("%d", &num);
    char tabla[3][num][max];/*Se declara una matriz cuyo tamaño varía dependiendo de lo que indique el usuario*/
    for (i = 0; i < num; i++){
        strcpy(tabla[0][i], ciudades[i]);
        strcpy(tabla[1][i], capitales[i]);
        strcpy(tabla[2][i], idiomas[i]);
    }
    turno = aleatorio(1, 2);/*Se muestra quien tiene el turno, esto se elige de manera aleatoria*/
    if (turno == 1){
        printf("\nEmpieza el jugador ");
        fputs(nom[turno - 1].nombre, stdout);
        printf("\n");
    }
    else{
        printf("\nEmpieza el jugador ");
        fputs(nom[turno - 1].nombre, stdout);
        printf("\n");
    }
    i = 0;
    while (i != num){ /*Se empieza el juego, este no termina sino hasta que se haya llegado al número de países que indicó el usuario, o hasta que un jugador acumule 70 puntos o más*/
        if (turno == 1){
            quest = aleatorio(1, 3);/*Aquí se elige que pregunta se le hace al usuario*/
            muestraPregunta(quest, paises[i]);/*Se le muestra la pregunta de acuerdo al número generado en la instrucción anterior*/
            posResp(quest, num, tabla);/*Se muestran las posibles respuestas de acuerdo a la pregunta que se ha hecho*/
            printf("\nIngrese su respuesta: ");/*Se solicita la respuesta y se almacena en el apuntador -r-*/
            scanf("%s", r);
            if (strcmp(tabla[quest - 1][i], r) == 0){
                cambiaPuntos(0, &pj1); /*Si lo ingresado coincide con la respuesta se le añaden puntos, eso es lo que indica la orden 0 en la función cambiaPuntos*/
                strcat(tabla[quest - 1][i], m); /*Se marca la respuesta una vez adivinada mediante una concatenación*/
                muestraResp(i, num, paises[i], tabla); /*Se muestran los datos correspondientes del país en turno */
                turno = turno + 1; /*Se asigna el turno al otro jugador*/
                printf("\nAhora es el turno del jugador %s\n", nom[turno - 1].nombre); /*Se indica quien posee el turno*/
                i = i + 1; /*Se avanza al otro país sumando uno al contador*/
            }
            else{
                cambiaPuntos(1, &pj1); /*En caso de no haber adivinado se le restan puntos, eso es lo que indica la orden 1 en la función cambiaPuntos*/
                printf("\nAhora el jugador %s debe adivinar\n\nIngrese su respuesta: ", nom[turno].nombre);/*Se le da la oportunidad al otro jugador y se repite el mismo proceso*/
                scanf("%s", r);
                if (strcmp(tabla[quest - 1][i], r) == 0){
                    cambiaPuntos(0, &pj2);
                    strcat(tabla[quest - 1][i], m);
                    muestraResp(i, num, paises[i], tabla);
                    printf("\nAhora es el turno del jugador %s\n", nom[turno - 1].nombre);
                    i = i + 1;
                }
                else{ /*Si nadie logra adivinar entonces se les indica y se muestran los datos correspondientes del país en turno*/
                    cambiaPuntos(1, &pj2);
                    printf("Ninguno pudo adivinar\n");
                    muestraResp(i, num, paises[i], tabla);
                    printf("\nAhora es el turno del jugador %s\n", nom[turno - 1].nombre);/*Se le da el turno al otro jugador y se avanza al siguiente país*/
                    i = i + 1;
                }
            }
        }
        else if (turno == 2){ /*Ocurre prácticamente lo mismo que en caso de que el turno hubiese sido 1*/
            quest = aleatorio(1, 3);
            muestraPregunta(quest, paises[i]);
            posResp(quest, num, tabla);
            printf("\nIngrese su respuesta: ");
            scanf("%s", r);
            if (strcmp(tabla[quest - 1][i], r) == 0){
                cambiaPuntos(0, &pj2);
                strcat(tabla[quest - 1][i], m); /*Se marca la respuesta una vez adivinada*/
                muestraResp(i, num, paises[i], tabla);
                turno = turno - 1;
                printf("\nAhora es el turno del jugador %s\n", nom[turno - 1].nombre);
                i = i + 1;
            }
            else{
                cambiaPuntos(1, &pj2);
                printf("\nAhora el jugador %s debe adivinar\n\nIngrese su respuesta: ", nom[turno - 2].nombre);
                scanf("%s", r);
                if (strcmp(tabla[quest - 1][i], r) == 0){
                    cambiaPuntos(0, &pj1);
                    strcat(tabla[quest - 1][i], m);
                    muestraResp(i, num, paises[i], tabla);
                    printf("\nAhora es el turno del jugador %s\n", nom[turno - 1].nombre);
                    i = i + 1;
                }
                else{
                    cambiaPuntos(1, &pj1);
                    printf("Ninguno pudo adivinar\n");
                    muestraResp(i, num, paises[i], tabla);
                    printf("\nAhora es el turno del jugador %s\n", nom[turno - 1].nombre);
                    i = i + 1;
                }
            }
        }
        if (pj1 >= 70 || pj2 >= 70){ /*Si se llega a los 70 puntos acumulados se finaliza la ejecución del juego*/
            printf("Un jugador ha llegado al máximo número de puntos en este juego, así que termina el juego\n");i = num;
        }
    }
    if (pj1 <= 0 && pj2 <= 0) /*Se muestra quien es el que ha ganado al final del juego y los puntos que acumuló cada jugador*/
        printf("\n¿Cómo es posible?\t¡Ha ganado la ignorancia!\n");
    else if (pj1 > pj2)
        printf("\nHa ganado el jugador %s\n", nom[0].nombre);
    else if (pj2 > pj1)
        printf("\nHa ganado el jugador %s\n", nom[1].nombre);
    else if (pj1 == pj2)
        printf("¡Vaya suerte!\n¡Han quedado empatados!\n");
    printf("\nTotal de puntos:\nJugador 1: %d\tJugador 2: %d\n", pj1, pj2);
    return 0;
}