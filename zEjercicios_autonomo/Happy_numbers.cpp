#include <iostream>     // Incluye la librería para entrada y salida estándar (como std::cout)
#include <string>       // Incluye la librería para trabajar con strings (necesaria para std::stoi)

int happy_number(int n);   // Declaración anticipada de la función que evalúa si un número es feliz


int main(int argc, char **argv){    // argc es el número de argumentos, argv es el arreglo de argumentos en texto
    int valor = std::stoi(argv[1]); // Convierte el argumento recibido (en texto) a entero. argv[0] es "./a.out", argv[1] es el número.

    if (happy_number(valor)){       // Llama a la función happy_number. Si devuelve 1 (true), entra aquí
        std::cout << "Es un numero feliz \n";  // Muestra mensaje si el número es feliz
    }
    else{ 
        std::cout << "No es un numero feliz \n";  // Muestra mensaje si el número no es feliz
    }    
}


int suma_de_cuadrados(int n){
    int suma = 0;                // Inicializa la suma
    while (n > 0){               // Mientras haya dígitos por procesar
        int d = n % 10;          // Obtiene el último dígito de n
        suma += d * d;           // Agrega el cuadrado del dígito a la suma
        n /= 10;                 // Elimina el último dígito (divide entre 10)
    }
    return suma;                 // Retorna la suma de los cuadrados
}

int happy_number(int n){
    int vistos [1000];         // Arreglo para guardar los números intermedios ya vistos (para detectar ciclos)
    int num_vistos = 0;        // Contador de cuántos números hemos guardado

    while (true){              // Bucle infinito: se rompe con un return (al llegar a 1 o repetir ciclo)

        if (n == 1){           // Caso base: si llega a 1, es feliz
            return 1;
        }

        // Verifica si ya hemos visto este número antes (ciclo)
        for(int ii= 0; ii < num_vistos ; ++ii){
            if(vistos[ii] == n){
                return 0;      // Si ya vimos este número, hay un ciclo => no es feliz
            }
        }

        // Si no lo hemos visto, lo guardamos
        vistos[num_vistos++] = n;

        // Calculamos la siguiente suma de cuadrados
        n = suma_de_cuadrados(n);
    }
}
