#include <iostream> // Para std::cout y std::cerr
#include <string> // Para std::stol

// Declaracion de la funcion que suma los términos impares de Fibonacci hasta un limite n
long sumaFibonacciImpares (long n);

int main (int argc, char **argv) {
    // Verifica si se ha pasado un argumento por consola   
    if (argc <= 1) {
        std:: cerr << "Por favor ingrese un numero como argumento.\n";
        return 1; // Retorna codigo de error
    }
    
    // Convierte el argumento de cadena a numero largo (long)
    long numvalue = std::stol(argv[1]);

    // Llama a la funcion y guarda el resultado
    long result = sumaFibonacciImpares(numvalue);

    // Si el resultado es valido (distinto de -1), lo imprime
    if (result !=-1) {
        std::cout << result << "\n";    
    }
    return 0; // Fin exitoso del programa

}

// Implementacion de la funcion que calcula la suma de los numeros impares de Fibonacci hasta n
long sumaFibonacciImpares (long n) { 
    long a = 1; 
    long b = 2;
    long suma = 0;     
    
     // Validacion: n debe ser mayor o igual a 1
    if (n < 1) {
        std::cerr <<"Numero no valido: debe ser mayor o igual que 1.\n";
        return -1;
    }

    // Genera la secuencia de Fibonacci hasta que a sobrepase a n
    while (a <= n) {
        // Si el numero actual de Fibonacci es impar, se suma
        if (a % 2 != 0) {
            suma += a;
        }

        // Avanza a la siguiente pareja de numeros de Fibonacci
        long temp = a + b;
        a = b;
        b = temp;
    }
    // Retorna la suma de los impares encontrados
    return suma;    
}