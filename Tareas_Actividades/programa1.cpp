#include <iostream> // Para entrada y salida estandar (std::cout, std::cerr)
#include <cmath> // Para operaciones matematicas como std::sqrt
#include <string> // Para usar std::stol, que convierte cadenas a numeros largos


// Declaracion de funcion que verifica si un numero es primo
bool isprime (long n);

int main (int argc, char **argv) {
    
    // Convertimos el argumento de la linea de comandos a tipo long
    // std::stol convierte un string a long; argv[1] es el numero ingresado por el usuario
    long numvalue = std::stol(argv[1]);
    
    long sum = 0; // Inicializamos la suma de primos en 0

    // Iteramos desde 2 hasta el numero ingresado (inclusive)
    // 1 no se considera primo, por eso empezamos en 2
    for (long ii = 2; ii <= numvalue; ++ii) {
        // Si el numero actual es primo, lo agregamos a la suma
        if (isprime(ii) == true) {
            sum += ii;
        }
    }
    // Imprimimos la suma total de los numeros primos menores o iguales a numvalue
    std::cout << sum << "\n";

    return 0;
 }

 // implementation
bool isprime(long n) {
    // precondition checks
    // do something if n <= 1
    if (n <= 1) {
        std::cerr << "Out of range number: " << n << "\n";
        return false;
    }

    // suppose it is prime
    bool flag = true; 

    if (n == 2) {
        return true;
    }

    // find divisors
    for (long ii = 2; ii <= std::sqrt(n) + 1; ii++) {
        if (n%ii == 0) { // ii is divisor
            flag = false;
            break; // end, at least one divisor
        }
    }

    return flag;
}