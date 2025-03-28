#include <stdio.h>
#include <string.h>

#define MAX_ALMACEN 30
#define MAX_STOCK 10000

int main() {
    int id = 0, stock_q = 0, q, opcion;
    float pu = 0, total_ganancia = 0, v;
    char nombre[30];

    do {
        printf("\n------- Menu de opciones -------\n");
        printf("1. Ingresar Producto\n");
        printf("2. Vender Producto\n");
        printf("3. Reabastecer Producto\n");
        printf("4. Mostrar Informacion\n");
        printf("5. Mostrar Total Ganancias\n");
        printf("6. Mostrar Info Almacen\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar();

        if (opcion == 7) {
            printf("Saliendo del programa...\n");
            break;
        }

        switch (opcion) {
            case 1:
                do {
                    printf("\nIngrese el ID del producto: ");
                    scanf("%d", &id);
                    getchar();

                    printf("\nIngrese el nombre del producto: ");
                    fgets(nombre, 30, stdin);

                    do {
                        printf("\nIngrese la cantidad en stock (max %d): ", MAX_STOCK);
                        scanf("%d", &stock_q);
                        if (stock_q <= 0 || stock_q > MAX_STOCK) {
                            printf("Error: La cantidad debe ser mayor que 0 y menor o igual a %d.\n", MAX_STOCK);
                        }
                    } while (stock_q <= 0 || stock_q > MAX_STOCK);

                    do {
                        printf("\nIngrese el precio unitario: ");
                        scanf("%f", &pu);
                        if (pu <= 0) {
                            printf("Error: El precio debe ser mayor que 0.\n");
                        }
                    } while (pu <= 0);

                    printf("\nProducto registrado exitosamente.\n");
                    printf("Presione 0 para volver al menu: ");
                    scanf("%d", &q);
                } while (q != 0);
                break;

            case 2:
                if (stock_q == 0) {
                    printf("\nNo hay stock disponible para la venta.\n");
                    break;
                }

                do {
                    printf("\nIngrese la cantidad a vender: ");
                    scanf("%d", &q);

                    if (q <= 0) {
                        printf("\nError: No se pueden vender cantidades negativas o cero.\n");
                    } else if (q > stock_q) {
                        printf("\nError: Stock insuficiente para la venta.\n");
                    } else {
                        v = q * pu;
                        total_ganancia += v;
                        stock_q -= q;
                        printf("\nVenta realizada con exito. Total: $%.2f\n", v);
                        printf("Stock actualizado: %d\n", stock_q);
                        if (stock_q == 0) {
                            printf("\nEl stock del producto se ha agotado, reabastezca.\n");
                        }
                    }
                    printf("Presione 0 para volver al menu: ");
                    scanf("%d", &q);
                } while (q != 0);
                break;

            case 3:
                do {
                    printf("\nIngrese la cantidad a agregar: ");
                    scanf("%d", &q);

                    if (q <= 0) {
                        printf("Error: No puede agregar una cantidad negativa o cero.\n");
                    } else if (stock_q + q > MAX_STOCK) {
                        printf("Error: No se puede superar el stock maximo de %d unidades.\n", MAX_STOCK);
                    } else {
                        stock_q += q;
                        printf("Reabastecimiento exitoso. Nuevo stock: %d\n", stock_q);
                    }
                    printf("Presione 0 para volver al menu: ");
                    scanf("%d", &q);
                } while (q != 0);
                break;

            case 4:
                do {
                    printf("\nIngrese el ID del producto: ");
                    scanf("%d", &id);
                    getchar();

                    printf("\n---- Informacion del Producto ----\n");
                    printf("ID: %d\n", id);
                    printf("Nombre: %s", nombre);
                    printf("Stock Disponible: %d\n", stock_q);
                    printf("Precio Unitario: %.2f\n", pu);
                    printf("Presione 0 para volver al menu: ");
                    scanf("%d", &q);
                } while (q != 0);
                break;

            case 5:
                do {
                    printf("\nTotal de ganancias acumuladas: $%.2f\n", total_ganancia);
                    printf("Presione 0 para volver al menu: ");
                    scanf("%d", &q);
                } while (q != 0);
                break;

            case 6:
                do {
                    printf("\n------ Informacion del Almacen ------\n");
                    printf("Capacidad total: %d Productos\n", MAX_ALMACEN);
                    printf("Stock Maximo: 10000 unidades\n", stock_q);
                    printf("Stock actual: %d unidades\n", stock_q);
                    printf("Presione 0 para volver al menu: ");
                    scanf("%d", &q);
                } while (q != 0);
                break;

            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }

    } while (1);

    return 0;
}