#include <iostream>     // Para entrada y salida estándar (std::cout, std::endl)
#include <cmath>        // Para funciones matemáticas como log10, pow, M_PI
#include <string>       // Para manejar cadenas, necesario para std::stod
#include <iomanip>      // Para manipular formato de salida (std::setprecision)

// Declaración de funciones que se usan en el programa
double calcular_perimetro(double radio);                           // Calcula el perímetro del círculo
double calcular_area(double radio);                                // Calcula el área del círculo
double error_area(double radio, double incert_radio);              // Calcula la incertidumbre del área
double error_perimetro(double incert_radio);                       // Calcula la incertidumbre del perímetro
double redondear_incertidumbre(double valor, double incertidumbre);// Redondea la incertidumbre a 1 cifra significativa
double redondear_valor(double valor, double incertidumbre);        // Redondea el valor para que coincida con la precisión de la incertidumbre
int calcular_decimales(double incertidumbre);                      // Calcula cuántos decimales se deben mostrar

int main(int argc, char **argv){
    // Convierte los argumentos de línea de comandos a números (radio e incertidumbre)
    double radio = std::stod(argv[1]);         // Primer argumento: radio del círculo
    double incert_radio = std::stod(argv[2]);  // Segundo argumento: incertidumbre del radio

    // Cálculos iniciales
    double area = calcular_area(radio);                       // Calcula área del círculo
    double incert_area = error_area(radio, incert_radio);     // Calcula incertidumbre del área
    double perimetro = calcular_perimetro(radio);             // Calcula perímetro del círculo
    double incert_perimetro = error_perimetro(incert_radio);  // Calcula incertidumbre del perímetro

    // Redondear resultados según su incertidumbre
    area = redondear_valor(area, incert_area);                         // Redondea área con precisión acorde a su incertidumbre
    incert_area = redondear_incertidumbre(incert_area, incert_area);  // Redondea incertidumbre del área a 1 cifra significativa

    perimetro = redondear_valor(perimetro, incert_perimetro);               // Redondea perímetro
    incert_perimetro = redondear_incertidumbre(incert_perimetro, incert_perimetro); // Redondea incertidumbre del perímetro

    // Imprimir área con su incertidumbre
    int precision_area = calcular_decimales(incert_area);           // Obtiene cuántos decimales debe tener el área
    std::cout << std::fixed << std::setprecision(precision_area);   // Establece precisión en la salida
    std::cout << "Area: " << area << " +/- " << incert_area << std::endl;

    // Imprimir perímetro con su incertidumbre
    int precision_perimetro = calcular_decimales(incert_perimetro); // Lo mismo, pero para perímetro
    std::cout << std::fixed << std::setprecision(precision_perimetro);
    std::cout << "Perimetro: " << perimetro << " +/- " << incert_perimetro << std::endl;

    return 0; // Fin del programa
}

// ---------- FUNCIONES DEFINIDAS ABAJO ----------

double calcular_perimetro(double radio){
    return 2 * M_PI * radio; // Fórmula del perímetro de un círculo
}

double calcular_area(double radio){
    return M_PI * std::pow(radio, 2); // Fórmula del área de un círculo: πr²
}

double error_area(double radio, double incert_radio){
    return 2 * M_PI * radio * incert_radio; // Propagación de errores para área (derivada de πr²)
}

double error_perimetro(double incert_radio){
    return 2 * M_PI * incert_radio; // Propagación de errores para perímetro (derivada de 2πr)
}

double redondear_incertidumbre(double valor, double incertidumbre){
    // Redondea incertidumbre a 1 cifra significativa
    int orden = std::floor(std::log10(incertidumbre));      // Encuentra el orden de magnitud (ej. si es 0.0342 → -2)
    double factor = std::pow(10, orden);                     // Factor de escala (ej. 0.01)
    return std::round(valor / factor) * factor;              // Redondea al valor más cercano usando el factor
}

double redondear_valor(double valor, double incertidumbre){
    // Redondea el valor principal con la misma precisión que su incertidumbre
    int orden = std::floor(std::log10(incertidumbre));       // Igual que arriba
    double factor = std::pow(10, orden);
    return std::round(valor / factor) * factor;
}

int calcular_decimales(double incertidumbre){
    // Devuelve cuántos decimales hay que mostrar, según el orden de magnitud de la incertidumbre
    int orden = std::floor(std::log10(incertidumbre));
    return (orden < 0) ? -orden : 0; // Si es negativo, devuelve número positivo de decimales
}
/* 
area = Valor de Area
incert_area = Incertidumbre del area
perimetro = Valor del perimetro
incert_perimetro = Incerdidumbre del perimetro
incert_radio = Incertidumbre del radio
redondear_incertidumbre = Redondea la incertidumbre
redondear_valor = Redondea el valor principal
calcular_decimales = Calcula cuantos decimales hay que mostrar


*/