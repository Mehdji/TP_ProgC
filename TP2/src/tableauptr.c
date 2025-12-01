/*
Mehdi NAOUI
B3 + L CNAM
01/12/2025
ESEITT
Manipulation de Tableaux avec des Pointeurs
IMPORTANT: Aucune notation indicielle utilisée (pas de tableau[i])
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonction pour afficher un tableau d'entiers avec des pointeurs
void afficher_tableau_int(int* ptr, int taille, const char* nom) {
    printf("%s:\n", nom);
    
    int* ptr_courant = ptr;  // Pointeur de parcours
    for (int i = 0; i < taille; i++) {
        if (i > 0) printf(", ");
        printf("%d", *ptr_courant);  // Déréférencement du pointeur
        ptr_courant++;               // Arithmétique de pointeur
    }
    printf("\n\n");
}

// Fonction pour afficher un tableau de flottants avec des pointeurs
void afficher_tableau_float(float* ptr, int taille, const char* nom) {
    printf("%s:\n", nom);
    
    float* ptr_courant = ptr;  // Pointeur de parcours
    for (int i = 0; i < taille; i++) {
        if (i > 0) printf(", ");
        printf("%.2f", *ptr_courant);  // Déréférencement du pointeur
        ptr_courant++;                 // Arithmétique de pointeur
    }
    printf("\n\n");
}

// Fonction pour remplir un tableau d'entiers avec des valeurs aléatoires
void remplir_tableau_int(int* ptr, int taille) {
    int* ptr_courant = ptr;
    for (int i = 0; i < taille; i++) {
        *ptr_courant = rand() % 150 + 1;  // Valeurs entre 1 et 150
        ptr_courant++;
    }
}

// Fonction pour remplir un tableau de flottants avec des valeurs aléatoires
void remplir_tableau_float(float* ptr, int taille) {
    float* ptr_courant = ptr;
    for (int i = 0; i < taille; i++) {
        *ptr_courant = (float)(rand() % 1000) / 100.0f;  // Valeurs entre 0.00 et 9.99
        ptr_courant++;
    }
}

// Fonction pour multiplier par 3 les éléments dont l'indice est divisible par 2
void multiplier_indices_pairs_int(int* ptr, int taille) {
    int* ptr_courant = ptr;
    for (int i = 0; i < taille; i++) {
        if (i % 2 == 0) {  // Indice divisible par 2 (0, 2, 4, 6...)
            *ptr_courant = *ptr_courant * 3;
        }
        ptr_courant++;
    }
}

// Fonction pour multiplier par 3 les éléments dont l'indice est divisible par 2
void multiplier_indices_pairs_float(float* ptr, int taille) {
    float* ptr_courant = ptr;
    for (int i = 0; i < taille; i++) {
        if (i % 2 == 0) {  // Indice divisible par 2 (0, 2, 4, 6...)
            *ptr_courant = *ptr_courant * 3.0f;
        }
        ptr_courant++;
    }
}

// Fonction alternative utilisant l'astuce *(s+i)
void multiplier_avec_astuce_int(int* s, int taille) {
    for (int i = 0; i < taille; i++) {
        if (i % 2 == 0) {
            *(s + i) = *(s + i) * 3;  // Utilisation de l'astuce *(s+i)
        }
    }
}

void multiplier_avec_astuce_float(float* s, int taille) {
    for (int i = 0; i < taille; i++) {
        if (i % 2 == 0) {
            *(s + i) = *(s + i) * 3.0f;  // Utilisation de l'astuce *(s+i)
        }
    }
}

int main() {
    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));
    
    printf("=== MANIPULATION DE TABLEAUX AVEC POINTEURS ===\n\n");
    printf("RÈGLE IMPORTANTE: Aucune notation indicielle (tableau[i]) utilisée!\n");
    printf("Seuls les pointeurs et l'arithmétique de pointeurs sont utilisés.\n\n");
    
    // Déclaration des tableaux
    const int TAILLE = 11;  // Comme dans l'exemple (11 éléments)
    int tableau_entiers[TAILLE];
    float tableau_flottants[TAILLE];
    
    // Déclaration des pointeurs vers les tableaux
    int* ptr_entiers = tableau_entiers;
    float* ptr_flottants = tableau_flottants;
    
    printf("Taille des tableaux: %d éléments\n\n", TAILLE);
    
    // Remplissage des tableaux avec des valeurs aléatoires
    printf("=== REMPLISSAGE AVEC VALEURS ALÉATOIRES ===\n");
    remplir_tableau_int(ptr_entiers, TAILLE);
    remplir_tableau_float(ptr_flottants, TAILLE);
    
    // Affichage AVANT la multiplication par 3
    printf("=== AVANT LA MULTIPLICATION PAR 3 ===\n");
    afficher_tableau_int(ptr_entiers, TAILLE, "Tableau d'entiers (avant la multiplication par 3)");
    afficher_tableau_float(ptr_flottants, TAILLE, "Tableau de nombres à virgule flottante (avant la multiplication par 3)");
    
    // Indication des indices qui seront multipliés
    printf("Indices qui seront multipliés par 3 (divisibles par 2): ");
    for (int i = 0; i < TAILLE; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
        }
    }
    printf("\n\n");
    
    // Multiplication par 3 des éléments dont l'indice est divisible par 2
    printf("=== MULTIPLICATION EN COURS ===\n");
    printf("Multiplication par 3 des éléments aux indices pairs...\n\n");
    
    multiplier_indices_pairs_int(ptr_entiers, TAILLE);
    multiplier_indices_pairs_float(ptr_flottants, TAILLE);
    
    // Affichage APRÈS la multiplication par 3
    printf("=== APRÈS LA MULTIPLICATION PAR 3 ===\n");
    afficher_tableau_int(ptr_entiers, TAILLE, "Tableau d'entiers (après la multiplication par 3)");
    afficher_tableau_float(ptr_flottants, TAILLE, "Tableau de nombres à virgule flottante (après la multiplication par 3)");
    
    // Démonstration de l'astuce *(s+i)
    printf("=== DÉMONSTRATION DE L'ASTUCE *(s+i) ===\n");
    printf("Création de nouveaux tableaux pour démonstration...\n\n");
    
    int demo_int[5] = {10, 20, 30, 40, 50};
    float demo_float[5] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    
    printf("Tableaux de démonstration AVANT *(s+i):\n");
    afficher_tableau_int(demo_int, 5, "Demo entiers");
    afficher_tableau_float(demo_float, 5, "Demo flottants");
    
    printf("Application de l'astuce *(s+i) pour multiplier les indices pairs...\n");
    multiplier_avec_astuce_int(demo_int, 5);
    multiplier_avec_astuce_float(demo_float, 5);
    
    printf("Tableaux de démonstration APRÈS *(s+i):\n");
    afficher_tableau_int(demo_int, 5, "Demo entiers (avec astuce)");
    afficher_tableau_float(demo_float, 5, "Demo flottants (avec astuce)");
    
    // Analyse des modifications
    printf("=== ANALYSE DES MODIFICATIONS ===\n");
    printf("Méthodes utilisées pour parcourir les tableaux:\n");
    printf("1. Pointeur + incrémentation: ptr++\n");
    printf("2. Arithmétique de pointeur: *(ptr + i)\n");
    printf("3. Déréférencement direct: *ptr_courant\n\n");
    
    printf("Modifications effectuées:\n");
    printf("- Index 0: multiplié par 3 (0 %% 2 == 0)\n");
    printf("- Index 1: inchangé (1 %% 2 != 0)\n");
    printf("- Index 2: multiplié par 3 (2 %% 2 == 0)\n");
    printf("- Index 3: inchangé (3 %% 2 != 0)\n");
    printf("- Index 4: multiplié par 3 (4 %% 2 == 0)\n");
    printf("- Et ainsi de suite...\n\n");
    
    // Vérification que nous n'avons utilisé aucune notation indicielle
    printf("=== VÉRIFICATION TECHNIQUE ===\n");
    printf("✅ Aucune notation tableau[i] utilisée\n");
    printf("✅ Utilisation exclusive de pointeurs\n");
    printf("✅ Arithmétique de pointeurs: ptr++, ptr+i, *ptr\n");
    printf("✅ Déréférencement: *ptr_courant, *(s+i)\n");
    printf("✅ Génération aléatoire avec srand(time(NULL))\n");
    printf("✅ Multiplication conditionnelle (indice %% 2 == 0)\n\n");
    
    printf("Programme terminé avec succès!\n");
    
    return 0;
}
