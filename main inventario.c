#include <string.h>
#include "inventario.h"
#define maxCant 100
#define NombreMax 40
int main()
{
    char nombres[maxCant][NombreMax];
    char caducidad[maxCant][NombreMax];
    int cantidad[maxCant];
    float precio[maxCant];
    int chocolates = 0;
    int opción;
    do {
        printf("1. Ingresar Chocolates\n");
        printf("2. Editar Chocolates\n");
        printf("3. Eliminar Chocolates\n");
        printf("4. Mostrar inventario\n");
        printf("5. Salir del inventario\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opción);

        switch (opción) {
            case 1:
                IngresarChocolates(nombres, caducidad, cantidad, precio, &chocolates);
                break;
            case 2:
                EditarChocolate(nombres, caducidad, cantidad, precio, chocolates);
                break;
            case 3:
                EliminarChocolate(nombres, caducidad, cantidad, precio, &chocolates);
                break;
            case 4:
                ListarChocolates(nombres, caducidad, cantidad, precio, chocolates);
                break;
            case 5:
                printf("Saliendo del inventario\n");
                break;
            default:
                printf("Opción no válida.\n");
                break;
        }
    } while (opción != 5);

    return 0;
}
