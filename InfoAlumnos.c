#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define CANTIDAD 2

struct info_alumnos
{
    char matricula[25];
    char nombre[20];
    char apellido_paterno[20];
    char apellido_materno[20];
    int edad;
    char carrera[20];
    char grupo[15];
    float calificacion;

};

struct info_alumnos alumnos[CANTIDAD]={};
bool MostrarMenu(bool agregar_alumnos);
void alta_alumnos();
int main(int argc, char const *argv[])
{
    
    bool mostrar_menu = true;
    //función que inicia el programa
    MostrarMenu(mostrar_menu);

    system("pause");
    return 0;
}

bool MostrarMenu(bool mostrar_menu)
{
    int opciones;
    //mientras mostrar_menu sea verdadero se va a ir mostrando el menu
    while (mostrar_menu)
    {
        printf("Ingresa una de las siguientes opciones\n1.- Alta Alumnos\n2.- Busqueda alumnos\n3.- Consulta general\n 4.- Modificaciones\n5.- Bajas\n6.- Promedio general\n7.- Imprimir reporte\n8.- Salir\n");
        scanf("%d", &opciones);

        switch (opciones)
        {
        case 1:
            alta_alumnos();
            break;
        case 2:

            break;

        case 3:

            break;

        case 4:

            break;

        case 5:

            break;

        case 6:

            break;
        case 7:

            break;
        case 8:
            //termina la ejecución del programa
            return mostrar_menu;
            break;
        default:
            printf("Error, opcion invalida!\n");
            break;
        }
    }
}

void alta_alumnos()
{
    int i;
    for (i = 0; i < CANTIDAD; i++)
    {
        printf("Ingresa la matricula del alumno %d\n", (i + 1));
        scanf(" %[^\n]",alumnos[i].matricula);
        printf("Ingresa el nombre del alumno %d\n", (i + 1));
        scanf(" %[^\n]",alumnos[i].nombre);
        printf("Ingresa el apellido paterno del alumno %d\n", (i + 1));
        scanf(" %[^\n]",alumnos[i].apellido_paterno);
        printf("Ingresa el apellido materno del alumno %d\n", (i + 1));
        scanf(" %[^\n]",alumnos[i].apellido_materno);
        printf("Ingresa la edad del alumno %d\n", (i + 1));
        scanf("%d",&alumnos[i].edad);
        printf("Ingresa la carrera del alumno %d\n", (i + 1));
        scanf(" %[^\n]",alumnos[i].carrera);
        printf("Ingresa el grupo del alumno %d\n", (i + 1));
        scanf(" %[^\n]",alumnos[i].grupo);
        printf("Ingresa la calificacion del alumno %d\n", (i + 1));
        scanf("%f",&alumnos[i].calificacion);
    }
}