/*
Mehdi NAOUI
B3 + L CNAM
21/11/2025
ESEITT
*/
int somme = 0;

#include <stdio.h>

int main(){
    //Itère 1000 fois.

    for(int i=0;i<999;i++){

        printf("i= %d\n",i);
        printf("somme= %d\n",somme);

        //Vérifie 5 | i
        if(i%5==0){
            somme += i;

        }
        //Vérifie 7 | i

        if(i%7==0){
            somme += i;

        }

        if (i%11==0)
            continue;
        

        if(somme>=5000){
            break;
        }    
    }
    

    printf("Sum: %d",somme);
}