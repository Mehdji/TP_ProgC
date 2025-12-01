/*
Mehdi NAOUI
B3 + L CNAM
01/12/2025
ESEITT
Génération de la Suite de Fibonacci en C
*/

#include <stdio.h>

int main() {
    // Déclaration des variables
    int n = 7;          // Nombre de termes à afficher (exemple: 7)
    int u0 = 0;         // U0 = 0
    int u1 = 1;         // U1 = 1
    int un;             // Un = Un-1 + Un-2
    int i;              // Variable de boucle
    
    printf("Génération de la suite de Fibonacci pour n = %d\n", n);
    printf("Suite de Fibonacci: ");
    
    // Cas particuliers pour n = 0 et n = 1
    if (n >= 0) {
        printf("%d", u0);       // Affichage de U0
    }
    
    if (n >= 1) {
        printf(", %d", u1);     // Affichage de U1
    }
    
    // Génération des termes suivants avec une boucle
    for (i = 2; i <= n; i++) {
        un = u0 + u1;           // Un = Un-1 + Un-2
        printf(", %d", un);     // Affichage de Un
        
        // Mise à jour pour l'itération suivante
        u0 = u1;                // L'ancien U1 devient le nouveau U0
        u1 = un;                // L'ancien Un devient le nouveau U1
    }
    
    printf("\n\n");
    
    // Affichage détaillé du processus de calcul
    printf("--- Détail du calcul ---\n");
    u0 = 0;
    u1 = 1;
    
    printf("U0 = %d\n", u0);
    if (n >= 1) {
        printf("U1 = %d\n", u1);
    }
    
    for (i = 2; i <= n; i++) {
        un = u0 + u1;
        printf("U%d = U%d + U%d = %d + %d = %d\n", i, i-2, i-1, u0, u1, un);
        u0 = u1;
        u1 = un;
    }
    
    // Test avec d'autres valeurs de n
    printf("\n--- Tests supplémentaires ---\n");
    
    // Test avec n = 10
    int n_test = 10;
    u0 = 0;
    u1 = 1;
    
    printf("Fibonacci pour n = %d: ", n_test);
    if (n_test >= 0) printf("%d", u0);
    if (n_test >= 1) printf(", %d", u1);
    
    for (i = 2; i <= n_test; i++) {
        un = u0 + u1;
        printf(", %d", un);
        u0 = u1;
        u1 = un;
    }
    printf("\n");
    
    // Test avec n = 0
    printf("Fibonacci pour n = 0: 0\n");
    
    return 0;
}
