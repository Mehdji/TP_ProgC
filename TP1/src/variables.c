/*
Mehdi NAOUI
B3 + L CNAM
21/11/2025
ESEITT
*/

#include <stdio.h>

int main(){
    int a = 1 ;
    unsigned int aa = 1;
    char c = 'a';
    unsigned char cc = 'b' ;
    float d = 1.1 ;
    long int e = -123456L ;
    unsigned long int ee = 123456L ;
    long long int f = -9876543210LL ;
    unsigned long long int ff = 9876543210LL ;
    double h = 3.14159 ;
    long double i = 2.718281828L ;

    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of unsigned int: %zu bytes\n", sizeof(unsigned int));
    printf("Size of char: %zu bytes\n", sizeof(char));
    printf("Size of unsigned char: %zu bytes\n", sizeof(unsigned char));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of long int: %zu bytes\n", sizeof(long int));
    printf("Size of unsigned long int: %zu bytes\n", sizeof(unsigned long int));
    printf("Size of long long int: %zu bytes\n", sizeof(long long int));
    printf("Size of unsigned long long int: %zu bytes\n", sizeof(unsigned long long int));
    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Size of long double: %zu bytes\n", sizeof(long double));
    
    // Affichage des valeurs des variables
    printf("\nValues of variables:\n");
    printf("a (int) = %d\n", a);
    printf("aa (unsigned int) = %u\n", aa);
    printf("c (char) = %c\n", c);
    printf("cc (unsigned char) = %c\n", cc);
    printf("d (float) = %.2f\n", d);
    printf("e (long int) = %ld\n", e);
    printf("ee (unsigned long int) = %lu\n", ee);
    printf("f (long long int) = %lld\n", f);
    printf("ff (unsigned long long int) = %llu\n", ff);
    printf("h (double) = %.5f\n", h);
    printf("i (long double) = %.9Lf\n", i);
    
   
   

    return 0;
}
    