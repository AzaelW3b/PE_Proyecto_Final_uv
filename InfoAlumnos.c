#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool MostrarMenu(bool agregar_alumnos);
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

        default:
            printf("Error, opcion invalida!\n");
            break;
        }
    }
}