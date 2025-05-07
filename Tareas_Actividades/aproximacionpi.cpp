#include <iostream>     // Sirve para usar std::cout (salida de texto en pantalla)
#include <cmath>        // Para usar funciones matematicas como std::pow() y la constante M_PI
#include <iomanip>      // Para usar std::setprecision y manipular el formato de salida

// Es la función que aproxima el valor de π usando la fórmula de Bailey–Borwein–Plouffe
double pi_aprox(int n) {
    double sum = 0.0;  // Esta variable acumula la suma de todos los terminos

    // Ciclo que debe recorrer desde k = 0 hasta k = n
    for (int k = 0; k <= n; k++) {
        // Calculamos el termino individual de la serie
        double term = 1.0 / std::pow(16, k);  // Primero se calcula 1 / 16^k
        term *= (4.0 / (8 * k + 1)            // Luego se multiplica por el gran parentesis
                - 2.0 / (8 * k + 4)
                - 1.0 / (8 * k + 5)
                - 1.0 / (8 * k + 6));

        sum += term;  // Se va sumando cada termino al total
    }

    return sum;  // Se retorna la aproximacion de pi
}

int main() {
    // Configura el número de decimales y la notacion cientifica en la salida
    std::cout.precision(16);                   // Precision de 16 cifras decimales
    std::cout.setf(std::ios::scientific);      // Muestra los números en notacion cientifica

    // Imprimo una cabecera para que los datos tengan orden, que se vea mas bonito
    std::cout << "n\tAproximacion\t\tError Relativo\n";
    std::cout << "------------------------------------------------------\n";

    // Ciclo que va de 1 a 20, como lo piden las instrucciones, por eso coloque el <=
    for (int n = 1; n <= 20; n++) {
        double aprox = pi_aprox(n);                 // Llamo la funcion y guarda el valor de π aprox
        double error_relativo = std::abs(1 - aprox / M_PI); // Calcula el error relativo

        // Imprime los resultados por fila: n, π(n) y el error relativo
        std::cout << n << "\t" << aprox << "\t" << error_relativo << "\n";
    }

    return 0; 
}
