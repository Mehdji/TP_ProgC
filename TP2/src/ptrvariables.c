/*
Mehdi NAOUI
B3 + L CNAM
01/12/2025
ESEITT
Manipulation des Variables de Types de Base avec des Pointeurs
*/

#include <stdio.h>
#include <stdint.h>

// Fonction pour afficher une variable en hexadécimal avec son pointeur
void afficher_variable_hex(const char* nom, void* ptr, size_t taille, const char* type) {
    printf("%-15s: Adresse: %p, Valeur: ", nom, ptr);
    
    // Affichage de la valeur en hexadécimal octet par octet (little-endian)
    unsigned char* bytes = (unsigned char*)ptr;
    for (int i = taille - 1; i >= 0; i--) {
        printf("%02x", bytes[i]);
    }
    printf(" (%s)\n", type);
}

int main() {
    printf("=== MANIPULATION DES VARIABLES AVEC DES POINTEURS ===\n\n");
    
    // Déclaration des variables de types de base (comme dans variables.c)
    char a = 'A';                    // 65 en ASCII
    short b = 1234;
    int c = 0x12345678;
    long int d = 0x87654321L;
    long long int e = 0x123456789ABCDEFLL;
    float f = 2.5f;
    double g = 3.14159;
    long double h = 2.718281828L;
    
    // Déclaration des pointeurs pour chaque type
    char* ptr_a = &a;
    short* ptr_b = &b;
    int* ptr_c = &c;
    long int* ptr_d = &d;
    long long int* ptr_e = &e;
    float* ptr_f = &f;
    double* ptr_g = &g;
    long double* ptr_h = &h;
    
    printf("Variables initiales et leurs pointeurs :\n");
    printf("char a = '%c' (0x%02x)\n", a, a);
    printf("short b = %d (0x%04x)\n", b, b);
    printf("int c = %d (0x%08x)\n", c, c);
    printf("long int d = %ld (0x%08lx)\n", d, d);
    printf("long long int e = %lld (0x%016llx)\n", e, e);
    printf("float f = %.2f\n", f);
    printf("double g = %.5f\n", g);
    printf("long double h = %.9Lf\n", h);
    printf("\n");
    
    // AVANT LA MANIPULATION
    printf("=== AVANT LA MANIPULATION ===\n");
    afficher_variable_hex("char a", ptr_a, sizeof(char), "char");
    afficher_variable_hex("short b", ptr_b, sizeof(short), "short");
    afficher_variable_hex("int c", ptr_c, sizeof(int), "int");
    afficher_variable_hex("long int d", ptr_d, sizeof(long int), "long int");
    afficher_variable_hex("long long e", ptr_e, sizeof(long long int), "long long");
    afficher_variable_hex("float f", ptr_f, sizeof(float), "float");
    afficher_variable_hex("double g", ptr_g, sizeof(double), "double");
    afficher_variable_hex("long double h", ptr_h, sizeof(long double), "long double");
    printf("\n");
    
    // MANIPULATION DES VARIABLES VIA LES POINTEURS
    printf("=== MANIPULATION VIA LES POINTEURS ===\n");
    
    // Modification via les pointeurs
    *ptr_a = 'Z';                    // 'A' -> 'Z'
    *ptr_b = 5678;                   // 1234 -> 5678
    *ptr_c = 0x87654321;             // Nouvelle valeur
    *ptr_d = 0x12345678L;            // Nouvelle valeur
    *ptr_e = 0xFEDCBA9876543210LL;   // Nouvelle valeur
    *ptr_f = 1.5f;                   // 2.5 -> 1.5
    *ptr_g = 2.71828;                // π -> e
    *ptr_h = 1.41421356L;            // e -> √2
    
    printf("Modifications effectuées :\n");
    printf("*ptr_a = '%c'\n", *ptr_a);
    printf("*ptr_b = %d\n", *ptr_b);
    printf("*ptr_c = 0x%08x\n", *ptr_c);
    printf("*ptr_d = 0x%08lx\n", *ptr_d);
    printf("*ptr_e = 0x%016llx\n", *ptr_e);
    printf("*ptr_f = %.2f\n", *ptr_f);
    printf("*ptr_g = %.5f\n", *ptr_g);
    printf("*ptr_h = %.8Lf\n", *ptr_h);
    printf("\n");
    
    // APRÈS LA MANIPULATION
    printf("=== APRÈS LA MANIPULATION ===\n");
    afficher_variable_hex("char a", ptr_a, sizeof(char), "char");
    afficher_variable_hex("short b", ptr_b, sizeof(short), "short");
    afficher_variable_hex("int c", ptr_c, sizeof(int), "int");
    afficher_variable_hex("long int d", ptr_d, sizeof(long int), "long int");
    afficher_variable_hex("long long e", ptr_e, sizeof(long long int), "long long");
    afficher_variable_hex("float f", ptr_f, sizeof(float), "float");
    afficher_variable_hex("double g", ptr_g, sizeof(double), "double");
    afficher_variable_hex("long double h", ptr_h, sizeof(long double), "long double");
    printf("\n");
    
    // DÉMONSTRATION D'ARITHMÉTIQUE DE POINTEURS
    printf("=== DÉMONSTRATION D'ARITHMÉTIQUE DE POINTEURS ===\n");
    
    // Déclaration d'un tableau pour démontrer l'arithmétique
    int tableau[5] = {10, 20, 30, 40, 50};
    int* ptr_tableau = tableau;  // Pointeur vers le premier élément
    
    printf("Tableau initial : [%d, %d, %d, %d, %d]\n", 
           tableau[0], tableau[1], tableau[2], tableau[3], tableau[4]);
    
    printf("Accès via arithmétique de pointeurs :\n");
    for (int i = 0; i < 5; i++) {
        printf("*(ptr_tableau + %d) = %d, Adresse: %p\n", 
               i, *(ptr_tableau + i), (ptr_tableau + i));
    }
    
    // Modification via arithmétique de pointeurs
    *(ptr_tableau + 0) = 100;  // tableau[0] = 100
    *(ptr_tableau + 2) = 300;  // tableau[2] = 300
    *(ptr_tableau + 4) = 500;  // tableau[4] = 500
    
    printf("\nAprès modification via pointeurs :\n");
    printf("Tableau modifié : [%d, %d, %d, %d, %d]\n", 
           *ptr_tableau, *(ptr_tableau+1), *(ptr_tableau+2), 
           *(ptr_tableau+3), *(ptr_tableau+4));
    printf("\n");
    
    // COMPARAISON AVEC L'EXEMPLE DONNÉ
    printf("=== EXEMPLE CONFORME AU FORMAT DEMANDÉ ===\n");
    
    int i = 0xa47865ff;
    float ff = 2.0f;  // 0x40000000 en IEEE 754
    
    printf("Avant la manipulation :\n");
    printf("Adresse de i : %p, Valeur de i : %08x\n", &i, i);
    printf("Adresse de f : %p, Valeur de f : %08x\n", &ff, *(uint32_t*)&ff);
    
    // Manipulation
    i = 0xa47865fe;  // Décrémentation de 1
    ff = 1.0f;       // 0x3f800000 en IEEE 754
    
    printf("\nAprès la manipulation :\n");
    printf("Adresse de i : %p, Valeur de i : %08x\n", &i, i);
    printf("Adresse de f : %p, Valeur de f : %08x\n", &ff, *(uint32_t*)&ff);
    
    // INFORMATIONS SUR LES POINTEURS
    printf("\n=== INFORMATIONS SUR LES POINTEURS ===\n");
    printf("Taille d'un pointeur : %zu bytes\n", sizeof(void*));
    printf("Adresse du pointeur ptr_c : %p\n", &ptr_c);
    printf("Valeur du pointeur ptr_c : %p\n", ptr_c);
    printf("Valeur pointée par ptr_c : %d\n", *ptr_c);
    
    return 0;
}
