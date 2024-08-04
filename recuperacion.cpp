//fecha: 03/08/24
////Autor: Lopez Quiroz Wagner
//Implementación de un Sistema de Gestión de Inventario de Productos utilizando Estructuras, Búsqueda y Ordenamiento
#include <iostream>
#include <string>

using namespace std;

struct Producto {
    string codigo; 
    string nombreProducto;
    double precioCompra;
    double precioVenta;
    int stock;
};

// Esta función permite ingresar un nuevo producto al arreglo de productos.
// Se solicitan al usuario los datos del producto y se almacenan en el arreglo.
void ingresarProducto(Producto productos[], int &n) {
    cout << "Ingrese el código del producto: ";
    cin >> productos[n].codigo;
    cout << "Ingrese el nombre del producto: ";
    cin.ignore(); // Para evitar problemas con getline después de cin
    getline(cin, productos[n].nombreProducto);
    cout << "Ingrese el precio de compra: ";
    cin >> productos[n].precioCompra;
    cout << "Ingrese el precio de venta: ";
    cin >> productos[n].precioVenta;
    cout << "Ingrese el stock: ";
    cin >> productos[n].stock;
    n++; // Incrementa el contador de productos ingresados
}

// Esta función busca un producto en el arreglo utilizando su código.
// Si el producto se encuentra, se muestran sus detalles. De lo contrario, se informa que no se encontró.
void buscarProductoPorCodigo(Producto productos[], int n, const string &codigo) {
    bool encontrado = false;
    for (int i = 0; i < n; i++) {
        if (productos[i].codigo == codigo) {
            cout << "Producto encontrado: " << endl;
            cout << "Código: " << productos[i].codigo << endl;
            cout << "Nombre: " << productos[i].nombreProducto << endl;
            cout << "Precio de compra: " << productos[i].precioCompra << endl;
            cout << "Precio de venta: " << productos[i].precioVenta << endl;
            cout << "Stock: " << productos[i].stock << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Producto no encontrado." << endl;
    }
}

// Esta función ordena el arreglo de productos alfabéticamente por el nombre del producto.
// Utiliza el algoritmo de ordenamiento de burbuja.
void ordenarPorNombre(Producto productos[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (productos[j].nombreProducto > productos[j + 1].nombreProducto) {
                // Intercambiar productos
                Producto temp = productos[j];
                productos[j] = productos[j + 1];
                productos[j + 1] = temp;
            }
        }
    }
    cout << "Productos ordenados por nombre." << endl;
}

// Esta función ordena el arreglo de productos por el precio de compra en orden descendente.
// Utiliza el algoritmo de ordenamiento de burbuja.
void ordenarPorPrecioCompraDescendente(Producto productos[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (productos[j].precioCompra < productos[j + 1].precioCompra) {
                // Intercambiar productos
                Producto temp = productos[j];
                productos[j] = productos[j + 1];
                productos[j + 1] = temp;
            }
        }
    }
    cout << "Productos ordenados por precio de compra (descendente)." << endl;
}

int main() {
    const int MAX_PRODUCTOS = 100; // Máximo número de productos permitidos
    Producto productos[MAX_PRODUCTOS]; // Arreglo de productos
    int n = 0; // Contador de productos ingresados
    int opcion; // Opción del menú
    string codigoBusqueda; // Código de producto para búsqueda

    do {
        // Menú de opciones
        cout << "\nMenú de opciones:" << endl;
        cout << "1. Ingresar producto" << endl;
        cout << "2. Buscar producto por código" << endl;
        cout << "3. Ordenar productos por nombre" << endl;
        cout << "4. Ordenar productos por precio de compra (descendente)" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        // Procesar la opción seleccionada
        switch (opcion) {
            case 1:
                if (n < MAX_PRODUCTOS) {
                    ingresarProducto(productos, n);
                } else {
                    cout << "No se pueden ingresar más productos." << endl;
                }
                break;
            case 2:
                cout << "Ingrese el código del producto que desea buscar: ";
                cin >> codigoBusqueda;
                buscarProductoPorCodigo(productos, n, codigoBusqueda);
                break;
            case 3:
                ordenarPorNombre(productos, n);
                break;
            case 4:
                ordenarPorPrecioCompraDescendente(productos, n);
                break;
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
        }

    } while (opcion != 5); // Continuar el ciclo hasta que el usuario decida salir

    return 0;
}


