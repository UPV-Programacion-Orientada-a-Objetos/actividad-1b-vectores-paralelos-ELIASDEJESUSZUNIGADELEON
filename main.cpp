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

// Muestra el menu principal
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
            case 1:
                // Consultar un producto
                break;
            case 2:
                // Actualizar inventario
                break;
            case 3:
                // Generar reporte completo
                break;
            case 4:
                // Encontrar el producto mas caro
                break;
            case 5:
                // Salir del sistema
                std::cout << "Fin del sistema" << std::endl;
                break;
            default:
                // Opción invalida
                std::cout << "Opcion inválida. Intente de nuevo." << std::endl;
                break;
        }
        std::cout << std::endl;
    } while (opcion != 5);
    return 0;
}
