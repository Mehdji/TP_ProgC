/*
Mehdi NAOUI
B3 + L CNAM
01/12/2025
ESEITT
Calcul de la Puissance en C
*/

#include <stdio.h>

int main() {
    // Déclaration des variables
    int a = 2;      // Base
    int b = 3;      // Exposant
    int resultat = 1;   // Variable pour stocker le résultat
    int i;          // Variable de boucle
    
    printf("Calcul de %d à la puissance %d\n", a, b);
    
    // Cas particulier : exposant = 0
    if (b == 0) {
        resultat = 1;
    }
    // Cas particulier : exposant négatif
    else if (b < 0) {
        printf("Erreur : Exposant négatif non supporté\n");
        return 1;
    }
    // Calcul de la puissance avec une boucle for
    else {
        for (i = 0; i < b; i++) {
            resultat = resultat * a;
            printf("Étape %d: %d\n", i + 1, resultat);
        }
    }
    
    // Affichage du résultat final
    printf("\nRésultat : %d^%d = %d\n", a, b, resultat);
    
    // Test avec d'autres valeurs
    printf("\n--- Tests supplémentaires ---\n");
    
    // Test 2: 5^4
    a = 5;
    b = 4;
    resultat = 1;
    
    for (i = 0; i < b; i++) {
        resultat *= a;
    }
    printf("%d^%d = %d\n", a, b, resultat);
    
    // Test 3: 3^0
    a = 3;
    b = 0;
    resultat = 1;
    printf("%d^%d = %d\n", a, b, resultat);
    
    return 0;
}
