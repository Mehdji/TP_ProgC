/*
Mehdi NAOUI
B3 + L CNAM
21/11/2025
ESEITT
Convert an int to a binary value
*/

#include <stdio.h>
#define MAXVALUE 100000



int int_to_bin(int in,char s[]);
void print_reverse(char s[]);

int main(int argc, char const *argv[])
{
 /*boucle for
 dévlarevariable int
 affiche int en binaire

 dév code pour int-> binaire
 */
    int a = 16; //Value to convert in binary
    char result[MAXVALUE] ={0};

    int_to_bin(a,result);

    print_reverse(result);
    
    return 0;
}


int int_to_bin(int in,char s[]){
    
    /*
    si valeur j !=0
    modulo valeur /2
    divisé valeur /2
    store résultat modulo valeur dans char[i]
    incémenter i
    store résultat div dans j
    revenir au début

    */
    
    int i=0,j=0,modulo = 0;
    int div = in;

    while (div!=0)
    {
        
        printf("iteration: %d\n",i+1);

        modulo = div % 2;
        printf("modulo %d modulo 2 : %d\n",div,modulo);
        div = div /2;
        printf("division: %d\n",div);

        s[i] = modulo + '0';  // ✅ Convertir en caractère '0' ou '1'
        printf("s[%d] = %c\n", i, s[i]);  // Debug
        i++;
    }
    
    s[i] = '\0';  // Terminer la chaîne
  

        
    return 0;
}

void print_reverse(char s[]){
    int length =0;
    for (int i=0;i< MAXVALUE && s[i]!='\0';i++){
        length=i;
    }

    for(int j= length; j>0;j--){
        printf("%c",s[j]);
    }
}