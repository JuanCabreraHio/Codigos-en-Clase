#include <iostream>
#include<cstdio>

void contar (int n);

int main(int argc, char **argv) {
    int numero = std::stoi(argv[1]);

    contar(numero);
    
    char buffer[5];
    sprintf(buffer, "%04d", numero);
    printf("%c %c %c %c\n", buffer[0], buffer[1], buffer[2], buffer[3]);

    return 0; 

}

void contar (int n){
    if(n < 0){
        std:: cerr << "Negative number. Ignoring \n";
        exit(1);
    
    }
    else if (n > 9999) {
        std:: cerr << "Number has more than 4 digits. Ignoring \n";
        exit(1);
     }
}