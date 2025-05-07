#include<iostream>
#include<cstdio>

//* Escriba un programa que lea un número entero y:Si tiene menos de 4 dígitos, imprima los dígitos precedidos por ceros. Luego imprima cuántos dígitos son pares y cuántos impares.

void contar(int n, int& par, int& impar){
    while (n>0){
        int digito = n%10;
        if (digito %2 == 0){
            par += 1;
        }
        else {
            impar += 1; 
        }
        n = n/10;
    }
}

int main (){
    int n;
    std:: cin >> n;

    printf("%04d\n",n);

    int par = 0, impar = 0;

    contar (n, par, impar);

    std::cout << "Pares: " << par << std::endl;
    std::cout << "Impares: " << impar << std::endl;

    return 0;
}

