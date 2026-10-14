#include <iostream>
#include <fstream>
#include "UdeABook.h"

using namespace std;

int main()
{
    UdeABook app;
    if (!app.cargarDatos()) {
        cout << "Error al cargar datos\n";
        return 1;
    }
    app.verificarCarga();   // temporal: imprime lo que quedó en memoria
    return 0;
}
