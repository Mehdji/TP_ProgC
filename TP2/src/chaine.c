/*
Mehdi NAOUI
B3 + L CNAM
01/12/2025
ESEITT
Manipulation de Chaînes de Caractères en C
*/

#include <stdio.h>

// Fonction pour calculer la longueur d'une chaîne
int ma_strlen(char chaine[]) {
    int longueur = 0;
    int i = 0;
    
    // Parcourir la chaîne jusqu'au caractère nul '\0'
    while (chaine[i] != '\0') {
        longueur++;
        i++;
    }
    
    return longueur;
}

// Fonction pour copier une chaîne dans une autre
void ma_strcpy(char destination[], char source[]) {
    int i = 0;
    
    // Copier caractère par caractère
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    
    // Ajouter le caractère de fin de chaîne
    destination[i] = '\0';
}

// Fonction pour concaténer deux chaînes
void ma_strcat(char destination[], char source[]) {
    int i = 0;
    int j = 0;
    
    // Trouver la fin de la première chaîne
    while (destination[i] != '\0') {
        i++;
    }
    
    // Ajouter les caractères de la deuxième chaîne
    while (source[j] != '\0') {
        destination[i] = source[j];
        i++;
        j++;
    }
    
    // Ajouter le caractère de fin de chaîne
    destination[i] = '\0';
}

int main() {
    // Déclaration des chaînes de test
    char chaine1[] = "Hello";
    char chaine2[] = " World!";
    char copie[50];           // Pour la copie
    char concatenee[100];     // Pour la concaténation
    
    printf("=== Manipulation de Chaînes de Caractères ===\n\n");
    
    // 1. Calcul de la longueur
    printf("1. Calcul de longueur :\n");
    printf("   Chaîne 1 : \"%s\"\n", chaine1);
    printf("   Longueur : %d caractères\n", ma_strlen(chaine1));
    
    printf("   Chaîne 2 : \"%s\"\n", chaine2);
    printf("   Longueur : %d caractères\n", ma_strlen(chaine2));
    printf("\n");
    
    // 2. Copie de chaîne
    printf("2. Copie de chaîne :\n");
    printf("   Chaîne source : \"%s\"\n", chaine1);
    ma_strcpy(copie, chaine1);
    printf("   Chaîne copiée : \"%s\"\n", copie);
    printf("   Longueur de la copie : %d caractères\n", ma_strlen(copie));
    printf("\n");
    
    // 3. Concaténation de chaînes
    printf("3. Concaténation de chaînes :\n");
    printf("   Chaîne 1 : \"%s\"\n", chaine1);
    printf("   Chaîne 2 : \"%s\"\n", chaine2);
    
    // Copier la première chaîne dans le résultat
    ma_strcpy(concatenee, chaine1);
    printf("   Après copie de la chaîne 1 : \"%s\"\n", concatenee);
    
    // Concaténer la deuxième chaîne
    ma_strcat(concatenee, chaine2);
    printf("   Après concaténation : \"%s\"\n", concatenee);
    printf("   Longueur totale : %d caractères\n", ma_strlen(concatenee));
    printf("\n");
    
    // Tests supplémentaires
    printf("=== Tests supplémentaires ===\n");
    
    // Test avec chaîne vide
    char vide[] = "";
    printf("Longueur chaîne vide : %d\n", ma_strlen(vide));
    
    // Test avec caractères spéciaux
    char speciale[] = "Bonjour! 123 @#$";
    char copie_speciale[50];
    printf("Chaîne spéciale : \"%s\" (longueur: %d)\n", speciale, ma_strlen(speciale));
    ma_strcpy(copie_speciale, speciale);
    printf("Copie spéciale : \"%s\"\n", copie_speciale);
    
    // Test de concaténation multiple
    char multi[100] = "C";
    char ajout1[] = " est";
    char ajout2[] = " génial!";
    
    printf("\nConcaténation multiple :\n");
    printf("Début : \"%s\"\n", multi);
    ma_strcat(multi, ajout1);
    printf("+ \"%s\" = \"%s\"\n", ajout1, multi);
    ma_strcat(multi, ajout2);
    printf("+ \"%s\" = \"%s\"\n", ajout2, multi);
    
    return 0;
}
