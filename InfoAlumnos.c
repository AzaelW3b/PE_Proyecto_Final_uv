#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
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

//arreglo de los alumnos
struct info_alumnos alumnos[CANTIDAD] = {};
bool MostrarMenu(bool agregar_alumnos);
void alta_alumnos();
void buscar_alumno();
void consulta_general();
void imprimir_reporte();
char mostrar_informacion(char matricula[25]);

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
        printf("Ingresa una de las siguientes opciones\n1.- Alta Alumnos\n2.- Busqueda alumnos\n3.- Consulta general\n4.- Modificaciones\n5.- Bajas\n6.- Promedio general\n7.- Imprimir reporte\n8.- Salir\n");
        scanf("%d", &opciones);

        switch (opciones)
        {
        case 1:
            alta_alumnos();
            break;
        case 2:
            buscar_alumno();
            break;

        case 3:
            consulta_general();
            break;

        case 4:

            break;

        case 5:

            break;

        case 6:

            break;
        case 7:
            imprimir_reporte();
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
        scanf(" %[^\n]", alumnos[i].matricula);
        printf("Ingresa el nombre del alumno %d\n", (i + 1));
        scanf(" %[^\n]", alumnos[i].nombre);
        printf("Ingresa el apellido paterno del alumno %d\n", (i + 1));
        scanf(" %[^\n]", alumnos[i].apellido_paterno);
        printf("Ingresa el apellido materno del alumno %d\n", (i + 1));
        scanf(" %[^\n]", alumnos[i].apellido_materno);
        printf("Ingresa la edad del alumno %d\n", (i + 1));
        scanf("%d", &alumnos[i].edad);
        printf("Ingresa la carrera del alumno %d\n", (i + 1));
        scanf(" %[^\n]", alumnos[i].carrera);
        printf("Ingresa el grupo del alumno %d\n", (i + 1));
        scanf(" %[^\n]", alumnos[i].grupo);
        printf("Ingresa la calificacion del alumno %d\n", (i + 1));
        scanf("%f", &alumnos[i].calificacion);
    }
}

void buscar_alumno()
{
    int i, j;
    char matricula_buscar[25];
    int cantidad_buscar;
    int bandera = 0; //nombre no encontrado

    printf("Ingresa la cantidad de alumnos a buscar\n");
    scanf("%d", &cantidad_buscar);

    for (i = 0; i < cantidad_buscar; i++)
    {
        printf("Ingresa la matricula del alumno a buscar\n");
        scanf("%s", matricula_buscar);

        for (j = 0; j < CANTIDAD; j++)
        {
            if (!strcmp(matricula_buscar, alumnos[j].matricula))
            { //nombre encontrado
                bandera = 1;
            }
        }
        if (bandera == 1)
        {
            printf("Alumno encontrado:\n\n");
            mostrar_informacion(matricula_buscar);
        }
        else
        {
            printf("Alumno no encontrado...\n\n");
        }
    }
}

void consulta_general()
{
    //mostramos todas las altas
    int i, j,x;
    char auxiliar[25];
    printf("--- Todos los alumnos registrados ---\n");
    for (i = 0; i < CANTIDAD; i++)
    {
        // ordenamos
        for (j = 0; j < CANTIDAD - 1; j++)
        {
            int siguiente_posicion = i + 1;

            if (strcmp(alumnos[j].matricula, alumnos[siguiente_posicion].matricula) < 0)
            {   x = j;
                strcpy(auxiliar, alumnos[j].matricula);
            }
        }
        strcpy(alumnos[x].matricula, alumnos[i].matricula);
        strcpy(alumnos[i].matricula, auxiliar);
       
    }
    int l;
    for(l = 0; l < CANTIDAD; l++){
         printf("Matricula: %s\n", alumnos[j].matricula);
        printf("Nombre: %s\n", alumnos[i].nombre);
        printf("Apellido Paterno: %s\n", alumnos[i].apellido_paterno);
        printf("Apellido Materno: %s\n", alumnos[i].apellido_materno);
        printf("Edad: %d\n", alumnos[i].edad);
        printf("Carrera: %s\n", alumnos[i].carrera);
        printf("Grupo: %s\n", alumnos[i].grupo);
        printf("Calificacion %f\n\n", alumnos[i].calificacion);
        printf("----------------------------------------------------\n");
    }
}

void imprimir_reporte()
{
    //creación del archivo
    FILE *archivo;
    archivo = fopen("alumnos.txt", "w");

    if (archivo == NULL)
    {
        fprintf(stderr, "\n No es posible crear el archivo de alumnos....");
        exit(1);
    }

    //escribimos en el archivo
    int i;
    for (i = 0; i < CANTIDAD; i++)
    {
        fwrite(&alumnos[i], sizeof(struct info_alumnos), 1, archivo);

        if (feof(archivo))
        {
            printf("Error al escribir en el archivo \n");
            return;
        }
        printf("Archivo creado correctamente... \n");
    }
    fclose(archivo);
}

char mostrar_informacion(char matricula[25])
{
    int j;

    for (j = 0; j < CANTIDAD; j++)
    {
        if (!strcmp(matricula, alumnos[j].matricula))
        {
            printf("Matricula: %s\n", alumnos[j].matricula);
            printf("Nombre: %s\n", alumnos[j].nombre);
            printf("Apellido Paterno: %s\n", alumnos[j].apellido_paterno);
            printf("Apellido Materno: %s\n", alumnos[j].apellido_materno);
            printf("Edad: %d\n", alumnos[j].edad);
            printf("Carrera: %s\n", alumnos[j].carrera);
            printf("Grupo: %s\n", alumnos[j].grupo);
            printf("Calificacion %f\n\n", alumnos[j].calificacion);
        }
    }
}