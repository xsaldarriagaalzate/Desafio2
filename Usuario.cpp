#include <iostream>
#include "Usuario.h"

using namespace std;

void Usuario::mostrar() const {
    cout << "[" << nombreUsuario << "] [" << clave << "] [" << correo << "] [" << fechaNacimiento << "]\n"
              << "  foto: [" << rutaFotoPerfil << "]\n"
              << "  [" << ciudad << "] [" << pais << "] [" << fechaInscripcion << "]\n";
}
