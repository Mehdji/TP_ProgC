
/*
Mehdi NAOUI
B3 + L CNAM
21/11/2025
ESEITT
*/
#include <stdio.h>
int num1 = 2 ;
int num2 = 4 ;
char op = '-';

int main(int argc, char const *argv[])
{
    switch(op)
{
    case ('+'):
    printf("Somme de %d + %d = %d",num1,num2,num1 + num2);
    break;
    case ('-'):
    printf("Somme de %d - %d = %d",num1,num2,num1 - num2);
    break;
    case ('/'):
    printf("Somme de %d / %d = %d",num1,num2,num1 / num2);
    break;
    case ('*'):
    printf("Somme de %d * %d = %d",num1,num2,num1 * num2);
    break;



default:
    break;
}


    return 0;
}

