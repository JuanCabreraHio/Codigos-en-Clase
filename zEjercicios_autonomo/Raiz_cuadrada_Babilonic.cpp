#include <iostream>   // Permite usar entrada/salida estándar (std::cout, std::cerr, etc.)
#include <string>     // Permite usar std::string y funciones como std::stoi

// Prototipo de la función que implementa el método babilónico para √2
double babilonic(int n);

int main(int argc, char **argv) {
    // Configura la salida para que imprima números en notación científica
    std::cout.setf(std::ios::scientific);
    // Establece la precisión a 15 cifras decimales
    std::cout.precision(15);

    // Convierte el primer argumento de la línea de comandos (argv[1]) a un entero
    // Se espera que el usuario pase el número de iteraciones como argumento
    int n = std::stoi(argv[1]);

    // Llama a la función babilonic con 'n' iteraciones
    double result = babilonic(n);

    // Imprime el número de iteraciones seguido del resultado en formato científico
    std::cout << n << " " << result << std::endl;
    return 0;
}

// Función que implementa el método babilónico para aproximar √2
// Recibe un entero 'n' que representa el número de iteraciones a realizar
double babilonic(int n) {
    double x = 1.0;  // Valor inicial de la estimación
    double s = 2;    // Número del cual se quiere calcular la raíz cuadrada

    // Realiza n iteraciones del método babilónico:
    // Fórmula: x = (x + s/x) / 2
    for (int i = 0; i < n ; ++i){
        x = ((x + (s / x)) / 2);
    }

    // Retorna la estimación final de la raíz cuadrada de 2
    return x;
}