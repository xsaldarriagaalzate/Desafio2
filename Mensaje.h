#ifndef MENSAJE_H
#define MENSAJE_H

#include <iostream>
#include "Fecha.h"

// Mensaje enviado de un usuario a un amigo.
// Guarda emisor, receptor y texto como cadenas dinámicas propias (sin std::string),
// por eso se aplica la regla de los tres: destructor, constructor de copia y operator=.
// Es compatible con Lista<Mensaje> (tiene constructor por defecto y operator=).
class Mensaje {
public:
    static const int MAX_TEXTO = 512;

private:
    char* emisor;
    char* receptor;
    char* texto;
    Fecha fecha;
    bool leido;

    static int longitud(const char* s);
    static char* duplicar(const char* s);   // copia dinámica (nullptr -> cadena vacía)

public:
    Mensaje();
    Mensaje(const char* emisor, const char* receptor, const char* texto,
            const Fecha& fecha, bool leido = false);
    Mensaje(const Mensaje& otro);
    Mensaje& operator=(const Mensaje& otro);
    ~Mensaje();

    // Regla del enunciado: no vacío y máximo 512 caracteres.
    static bool textoValido(const char* texto);

    // Getters (por referencia constante: sin copias innecesarias)
    const char* getEmisor() const;
    const char* getReceptor() const;
    const char* getTexto() const;
    const Fecha& getFecha() const;
    bool estaLeido() const;

    // Setters
    void marcarLeido();
    void setLeido(bool valor);

    // Memoria total del mensaje: el objeto + cada cadena dinámica (con su '\0').
    unsigned long memoria() const;

    void mostrar() const;

    // Sobrecarga de operadores: ordenar por fecha de envío.
    bool operator<(const Mensaje& otro) const;
    bool operator==(const Mensaje& otro) const;

    friend std::ostream& operator<<(std::ostream& os, const Mensaje& m);
};

#endif // MENSAJE_H
