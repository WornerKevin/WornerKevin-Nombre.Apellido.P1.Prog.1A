/*
2. Crear una función que se llame reemplazarCaracteres que reciba una cadena de caracteres como primer parámetro,
 un carácter como segundo y otro carácter  como tercero,  la misma deberá reemplazar cada ocurrencia
del segundo parámetro por el tercero y devolver la cantidad de veces que se reemplazo ese carácter  en la cadena
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5
struct{
    int id;
    char nombre[20];
    char tipo;
    float efectividad;
    int isEmpty;

}typedef eVacuna;
float aplicarAumento(float precio);
int sortVacuna(eVacuna* list, int tam);
int reemplazarCaracteres(char* cadena[], char caracter1, char caracter2);
int main()
{
    eVacuna vacuna[TAM] = {
    {0, "Pfizer", 'P', 93.07, 0},
    {1, "Moderna", 'B', 99.05, 0},
    {2, "Astrazeneca", 'G', 40.07, 0},
    {3, "Sputnik", 'P', 96.07, 0},
    {4, "Johnson&Johnson", 'P', 74.07, 0}
    };
    float precio = 1500;
    float precioFinal = 0;
    char cadena[20] = "Maquina";
    char caracterUno = 'a';
    char caracterDos = 'n';
    int contador = 0 ;
    sortVacuna(vacuna, TAM);
    for(int i = 0; i<TAM; i++)
    {
        if(vacuna[i].isEmpty == 0)
        {
                   printf(" %d |          %10s               |     %c       |   %.2f\n",
               vacuna[i].id,
               vacuna[i].nombre,
               vacuna[i].tipo,
               vacuna[i].efectividad);
        }

    }
    precioFinal = aplicarAumento(precio);
    printf("\nPRECIO FINAL ES: %.2f", precioFinal);

    contador = reemplazarCaracteres(&cadena, caracterUno, caracterDos);
    printf("\nLa cadena quedo: %s  e itero %d veces", cadena, contador);

    return 0;
}
float aplicarAumento(float precio)
{
    float aumento;
    float cuenta;
    if(precio > 0)
    {
        aumento = precio * 0.05;
        cuenta = precio + aumento;
    }
    return cuenta;
}

int sortVacuna(eVacuna* list, int tam)
{
    int ret = -1;
    eVacuna aux;
    int j;
    int i;
    if(list != NULL && tam > 0)
    {
        for(i = 0; i < tam -1; i++)
        {
            for(j = i+1; j < tam; j++)
            {
                if(list[i].isEmpty == 0 && list[j].isEmpty == 0)
                {
                    if((list[i].tipo == list[j].tipo && list[i].efectividad > list[j].efectividad) || list[i].tipo > list[j].tipo)
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                }
            }
        }
        ret = 0;
    }
    return ret;
}

/*
2. Crear una función que se llame reemplazarCaracteres que reciba una cadena de caracteres como primer parámetro,
 un carácter como segundo y otro carácter  como tercero,  la misma deberá reemplazar cada ocurrencia
del segundo parámetro por el tercero y devolver la cantidad de veces que se reemplazo ese carácter  en la cadena
*/
int reemplazarCaracteres(char* cadena[], char caracter1, char caracter2)
{
    int tamCadena;
    int contador = 0;
    if(cadena != NULL )
    {
        tamCadena = strlen(cadena);
        for(int i = 0; i < tamCadena ;i++)
        {
            if(cadena[i] == caracter1)
            {
                cadena[i] = caracter2;
                contador++;
            }
        }
    }

    return contador;
}
