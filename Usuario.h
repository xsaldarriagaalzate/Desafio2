#ifndef USUARIO_H
#define USUARIO_H

class Usuario {
private:
    char* nombreUsuario;
    char* clave;
    char* correo;
    char* fechaNacimiento;
    char* rutaFotoPerfil;
    char* ciudad;
    char* pais;
    char* fechaInscripcion;

public:
    Usuario();
    Usuario(const char* nombreUsuario, const char* clave, const char* correo,const char* fechaNacimiento,
            const char* rutaFotoPerfil,
            const char* ciudad, const char* pais, const char* fechaInscripcion);

    void mostrar() const;
};

#endif // USUARIO_H
