#include <stdio.h>
#define maxCant 100
#define NombreMax 40
void IngresarChocolates(char nombres[][NombreMax], char caducidad[][NombreMax], int cantidad[], float precio[], int *chocolates)
{
    if (*chocolates >= maxCant)
    {
        printf("El inventario ya está lleno\n");
        return;
    }
    printf("Ingrese el nombre del chocolate: ");
    scanf("%s", nombres[*chocolates]);
    printf("Ingrese la cantidad de chocolates: ");
    scanf("%d", &cantidad[*chocolates]);
    printf("Ingrese el precio del chocolate: ");
    scanf("%f", &precio[*chocolates]);
    printf("Ingrese la fecha de caducidad del chocolate: ");
    scanf("%s", caducidad[*chocolates]);
    printf("El chocolate ya se ingresó\n");
    (*chocolates)++;
}
void EditarChocolate(char nombres[][NombreMax], char caducidad[][NombreMax], int cantidad[], float precio[], int chocolates)
{
    char nombre[NombreMax];
    printf("Ingrese el nombre del chocolate que desea editar: ");
    scanf("%s", nombre);
    int index = BuscarChocolate(nombres, chocolates, nombre);
    if (index == -1)
    {
        printf("El chocolate no se encontró \n");
        return;
    }
    printf("Ingrese la nueva cantidad del chocolate: ");
    scanf("%d", &cantidad[index]);
    printf("Ingrese el nuevo precio del chocolate: ");
    scanf("%f", &precio[index]);
    printf("Ingrese la nueva fecha de caducidad: ");
    scanf("%s", caducidad[index]);
    printf("El chocolate ya fue editado\n");
}

void EliminarChocolate(char nombres[][NombreMax], char caducidad[][NombreMax], int cantidad[], float precio[], int *chocolates)
{
    char nombre[NombreMax];
    printf("Ingrese el nombre del chocolate que desea eliminar: ");
    scanf("%s", nombre);

    int index = BuscarChocolate(nombres, *chocolates, nombre);
    if (index == -1)
    {
        printf("El chocolate no se encontró.\n");
        return;
    }

    for (int i = index; i < *chocolates - 1; i++)
    {
        strcpy(nombres[i], nombres[i + 1]);
        strcpy(caducidad[i], caducidad[i + 1]);
        cantidad[i] = cantidad[i + 1];
        precio[i] = precio[i + 1];
    }
    (*chocolates)--;
    printf("El chocolate ya se eliminó \n");
}

void ListarChocolates(char nombres[][NombreMax], char caducidad[][NombreMax], int cantidad[], float precio[], int chocolates)
{
    if (chocolates == 0)
    {
        printf("No hay chocolates en el inventario.\n");
        return;
    }
    printf("%-10s %-10s %-10s %-10s\n", "Nombre", "Cantidad", "Precio", "Fecha de caducidad");
  printf("---------------------------------------------------\n");
  
  
    for (int i = 0; i < chocolates; i++)
    {
      printf("%-10s %-10d %-10.2f %-10s\n", nombres[i], cantidad[i], precio[i], caducidad[i]);
    }
}

int BuscarChocolate(char nombres[][NombreMax], int chocolates, char nombre[])
{
    for (int i = 0; i < chocolates; i++)
    {
        if (strcmp(nombres[i], nombre) == 0)
        {
            return i;
        }
    }
    return -1;
}