#include <iostream> // Libreria para entrada y salida estandar (std::cin, std::cout, etc.)
#include <string>
#include <cmath> // Libreria para trabajar con strings (necesaria para std::stol)

// Declaracion de la funcion que encontrara el mayor factor primo de un numero
long second_largest_prime_factor (long n);
bool is_prime(long n);

int main (int argc, char **argv) {
    
    // Verifica si se paso al menos un argumento (ademas del nombre del programa)
    if (argc <= 1) {
        std:: cerr << "Por favor ingrese un número como argumento.\n"; // Mensaje de error
        return 1; // Codigo de salida no exitoso
    }
    
    // Convierte el argumento ingresado (tipo string) a tipo long
    long num = std::stol(argv[1]);

    int k = 3;
    // Llama a la funcion 'largest_prime_factor' para obtener el mayor factor primo
    long result = second_largest_prime_factor(num);


    if (result !=-1) { //evita imprimir -1 en caso de error, lo cual mejora el acabado del programa. Y Si el resultado es válido (diferente de -1), se imprime en consola
        std::cout << result << "\n"; 
    } 
    else {
        std::cerr << "No se encontro un segundo numero primo menor que" << num << ".\n";
    }
    return 0;

}
bool is_prime(long n) {
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

// Implementacion de la función que calcula el mayor factor primo
long second_largest_prime_factor (long n, int k) { 
    long largest = 0; // Variable para guardar el mayor factor primo
    long ii= 2; // Comenzamos a dividir desde el menor primo: 2
    

    // Verificacion de entrada: el numero debe ser mayor que 1
    if (n <= 2) {
        std::cerr << "Numero no valido: debe ser mayor que 2.\n";
        return -1; // Devuelve -1 como indicador de error
    }

    int count = 0;

    for (long i = n - 1; i >= 2; --i){
        if (is_prime(i)){
            ++count;
            if (count == k){
                return i;
            }
            
        }
        
    }
    return -1; // Devuelve el mayor factor primo encontrado
}