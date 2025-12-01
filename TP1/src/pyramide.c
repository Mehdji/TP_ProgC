/*
Mehdi NAOUI
B3 + L CNAM
21/11/2025
ESEITT
Génération d'une pyramide de nombres
*/

#include <stdio.h>

int main() {
    // 1. Déclaration des variables
    int n = 5;  // Hauteur de la pyramide
    int i, j;   // Variables pour les boucles imbriquées
    
    printf("Génération d'une pyramide de hauteur %d :\n\n", n);
    
    // 3. Boucle de génération de la pyramide
    for (i = 1; i <= n; i++) {
        
        // Affichage des espaces pour centrer
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }
        
        // Affichage des nombres croissants (1 à i)
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }
        
        // Affichage des nombres décroissants (i-1 à 1)
        for (j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }
        
        // 4. Passage à la ligne suivante
        printf("\n");
    }
    
    // 5. Message de terminaison
    printf("\nGénération de la pyramide terminée!\n");
    
    return 0;
}
