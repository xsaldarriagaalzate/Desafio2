#ifndef FECHA_H
#define FECHA_H

#include <iostream>

// Fecha calendario (dd/mm/aaaa). Sin memoria dinámica: son 3 enteros,
// por lo que copiar una Fecha es barato y no requiere constructor de copia propio.
class Fecha {
private:
    int dia;
    int mes;
    int anio;

    static bool esBisiesto(int a);
    static int diasEnMes(int m, int a);

public:
    Fecha();                              // 01/01/2000 por defecto
    Fecha(int dia, int mes, int anio);

    // Getters / setters
    int getDia() const;
    int getMes() const;
    int getAnio() const;
    void setFecha(int d, int m, int a);

    bool esValida() const;

    // Entero comparable aaaammdd (ej: 05/10/2026 -> 20261005).
    // Permite comparar y ordenar fechas con una sola comparación de enteros.
    long clave() const;

    // Lee "dd/mm/aaaa" (formato usado en los archivos). Devuelve false si el formato es malo.
    bool desdeTexto(const char* texto);

    // Memoria que ocupa el objeto (para la medición de recursos).
    static unsigned long memoria();

    // Sobrecarga de operadores
    bool operator==(const Fecha& o) const;
    bool operator!=(const Fecha& o) const;
    bool operator<(const Fecha& o) const;
    bool operator<=(const Fecha& o) const;
    bool operator>(const Fecha& o) const;
    bool operator>=(const Fecha& o) const;

    friend std::ostream& operator<<(std::ostream& os, const Fecha& f);
};

#endif // FECHA_H
