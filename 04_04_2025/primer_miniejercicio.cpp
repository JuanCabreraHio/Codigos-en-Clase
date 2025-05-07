#include <iostream> //Proporciona funcionalidades para la entrada y salida de datos, como la lectura desde el teclado y la escritura en la pantalla
#include <string> // Permite trabajar con cadenas de caracteres más sencilla y seguras que los caracteres tradicionales de C. 

int main(void) { // "int" indica que la función devuelve un valor entero al finalizar. "void" significa que la función no recibe ningun argumento.
    
    std::string nombre; // Declara una variable llamada "nombre" y esta variable se utilizará para almacenar la cadena de caracteres que el usuario ingrese como su nombre 
    std::cout <<"Ingrese su nombre: "; // Utiliza "std::cout" (Objeto de salida estandar) para mostrar un mensaje en la pantalla, en este caso le pide al usuario que ingrese su nombre
    //std::cin >> nombre; // lee hasta el primer espacio, por ejemplo: Si si nombre es Juan Daniel. La función solo leera "Juan"
    std:: getline(std::cin, nombre); // Se usa la función "std::getline" de la biblioteca string para leer una línea completa de texto desde la entrada estandar.
    std::cout << "Hola," << nombre << "\n"; // Utiliza "std::cout" para mostrar un saludo en la pantalla. En donde se conectará la cadena literal "Hola", el valor almacenado en la variable "nombre" y un salto de linea ("\n") para que la siguiente salida aparezca en una nueva línea.
    return 0; // Indica que la función main ha finalizado con éxito. El valor 0 se devuellve al sistema operativo.

}