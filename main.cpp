#include <iostream>
#include <string>

// Constante para el tamaño maximo de productos
const int max = 100;
// Cantidad inicial de productos cargados
const int num = 5;

// Arreglos paralelos para almacenar los datos de los productos
int codigos[max] = {101, 102, 103, 104, 105};
std::string nombres[max] = {
    "Martillo de bola",
    "Destornillador",
    "Cinta metrica",
    "Llave inglesa",
    "Taladro inalambrico"
};
int stock[max] = {50, 120, 75, 45, 10};
float precios[max] = {15.50f, 8.75f, 20.00f, 25.99f, 120.00f};

// Variable para llevar la cuenta de productos registrados
int numProductos = num;

// Mostrar el menu principal
void mostrarMenu() {
    std::cout << "--- Bienvenido al Sistema de Inventario de \"El Martillo\" ---" << std::endl;
    std::cout << std::endl;
    std::cout << "Seleccione una opcion:" << std::endl;
    std::cout << "1. Consultar un producto" << std::endl;
    std::cout << "2. Actualizar inventario" << std::endl;
    std::cout << "3. Generar reporte completo" << std::endl;
    std::cout << "4. Encontrar el producto mas caro" << std::endl;
    std::cout << "5. Salir" << std::endl;
    std::cout << std::endl;
    std::cout << "Opcion seleccionada: ";
}

int main() {
    int opcion = 0;
    do {
        mostrarMenu();
        std::cin >> opcion;
        // Validar entrada aun falta
        switch (opcion) {
            case 1: {
                // Consultar un producto
                int Buscar;
                std::cout << "Ingrese el codigo del producto a consultar: ";
                std::cin >> Buscar;
                bool encontrado = false;
                for (int i = 0; i < num; ++i) {
                    if (codigos[i] == Buscar) {
                        std::cout << "Informacion del Producto:" << std::endl;
                        std::cout << "Codigo: " << codigos[i] << std::endl;
                        std::cout << "Nombre: " << nombres[i] << std::endl;
                        std::cout << "Cantidad en stock: " << stock[i] << std::endl;
                        std::cout << "Precio unitario: $" << precios[i] << std::endl;
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    std::cout << "Error: El producto con codigo " << Buscar << " no existe." << std::endl;
                }
                break;
            }
            case 2: {
                // Actualizar inventario
                int Actualizar;
                std::cout << "Ingrese el codigo del producto a actualizar: ";
                std::cin >> Actualizar;
                bool encontrado = false;
                for (int i = 0; i < num; ++i) {
                    if (codigos[i] == Actualizar) {
                        int cantidad;
                        std::cout << "Ingrese la cantidad a modificar (puede ser negativa para restar): ";
                        std::cin >> cantidad;
                        if (stock[i] + cantidad < 0) {
                            std::cout << "Error: No se puede dejar el stock en negativo." << std::endl;
                        } else {
                            stock[i] += cantidad;
                            std::cout << "Stock actualizado correctamente. Nuevo stock: " << stock[i] << std::endl;
                        }
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    std::cout << "Error: El producto con codigo " << Actualizar << " no existe." << std::endl;
                }
                break;
            }
            case 3:{
                // Generar reporte completo
                std::cout << "--- Reporte de Inventario ---" << std::endl;
                std::cout << "Codigo    | Nombre               | Stock | Precio" << std::endl;
                std::cout << "-------------------------------------------------" << std::endl;
                for (int i = 0; i < num; ++i) {
                    std::cout << codigos[i] << "       | "
                              << nombres[i];
                    // Espacios para alinear nombres pequeños
                    int espacios = 20 - nombres[i].length();
                    for (int e = 0; e < espacios; ++e) std::cout << " ";
                        std::cout << "| " << stock[i]
                                 << "    | $" << precios[i] << std::endl;
                    }
                std::cout << "-------------------------------------------------" << std::endl;
                std::cout << "--- Fin del Reporte ---" << std::endl;
                break;
            }
            case 4: {
            // Encontrar el producto mas caro
            int Productocaro = 0;
            for (int i = 1; i < num; ++i) {
                if (precios[i] > precios[Productocaro]) {
                    Productocaro = i;
                }
            }
            std::cout << "El producto mas caro es: " << nombres[Productocaro] << " con un precio de $" << precios[Productocaro] << std::endl;
                break;
            }
            case 5:
                std::cout << "Fin del sistema" << std::endl;
                break;
            default:
                std::cout << "Opcion inválida. Intente de nuevo." << std::endl;
                break;
        }
        std::cout << std::endl;
    } while (opcion != 5);
    return 0;
}
