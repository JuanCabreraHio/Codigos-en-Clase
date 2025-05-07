#include <iostream> // Libreria para entrada y salida estandar (std::cin, std::cout, etc.)
#include <string> // Libreria para trabajar con strings (necesaria para std::stol)

// Declaracion de la funcion que encontrara el mayor factor primo de un numero
long largest_prime_factor (long n);
int main (int argc, char **argv) {
    
    // Verifica si se paso al menos un argumento (ademas del nombre del programa)
    if (argc <= 1) {
        std:: cerr << "Por favor ingrese un número como argumento.\n"; // Mensaje de error
        return 1; // Codigo de salida no exitoso
    }
    
    // Convierte el argumento ingresado (tipo string) a tipo long
    long numvalue = std::stol(argv[1]);
    // Llama a la funcion 'largest_prime_factor' para obtener el mayor factor primo
    long result = largest_prime_factor(numvalue);


    if (result !=-1) { //evita imprimir -1 en caso de error, lo cual mejora el acabado del programa. Y Si el resultado es válido (diferente de -1), se imprime en consola
        std::cout << result << "\n"; 
    }
    return 0;

}

// Implementacion de la función que calcula el mayor factor primo
long largest_prime_factor (long n) { 
    long largest = 0; // Variable para guardar el mayor factor primo
    long ii= 2; // Comenzamos a dividir desde el menor primo: 2
    
    // Verificacion de entrada: el numero debe ser mayor que 1
    if (n <= 1) {
        std::cerr << "Numero no valido: debe ser mayor que 1.\n";
        return -1; // Devuelve -1 como indicador de error
    }

    while (n > 1) { 
        if (n%ii == 0){ // Si ii divide a n sin residuo...
            n = n/ii;   // ...dividimos n entre ii
            largest = ii; // ...y guardamos ii como ultimo factor primo encontrado
        } else { 
            ii++; // Si no divide, probamos con el siguiente numero
        }
    }
    return largest; // Devuelve el mayor factor primo encontrado
}