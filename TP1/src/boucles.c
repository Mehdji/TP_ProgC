#include <stdio.h>

int main(){
    int compteur = 10;

    for(int i=0; i<compteur;i++){

        for(int j=0;j<i;j++){
            if((i==3&&j==1)||(i==4&&j==1)||(i==4&&j==2)){
                printf("#"); 
            }else{
               printf("*"); 
            }
            

        }
        printf("\n");

    }
}
