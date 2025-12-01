/*
Mehdi NAOUI
B3 + L CNAM
01/12/2025
ESEITT
Gestion des Données Étudiantes en C
*/

#include <stdio.h>
#include <string.h>

int main() {
    // Déclaration des tableaux pour 5 étudiants
    const int NB_ETUDIANTS = 5;
    
    // Tableaux pour les noms et prénoms (combinés)
    char noms_prenoms[5][100] = {
        "Dupont Marie",
        "Martin Pierre", 
        "Durand Sophie",
        "Bernard Lucas",
        "Petit Emma"
    };
    
    // Tableau pour les adresses
    char adresses[5][150] = {
        "20, Boulevard Niels Bohr, Lyon",
        "22, Boulevard Niels Bohr, Lyon",
        "15, Rue des Sciences, Paris",
        "30, Avenue Einstein, Toulouse",
        "8, Place Curie, Marseille"
    };
    
    // Tableaux pour les notes
    float notes_programmation[5] = {16.5, 14.0, 18.5, 12.0, 15.5};
    float notes_systeme[5] = {12.1, 14.1, 16.0, 10.5, 13.8};
    
    printf("=== GESTION DES DONNÉES ÉTUDIANTES ===\n\n");
    printf("Nombre d'étudiants: %d\n\n", NB_ETUDIANTS);
    
    // Affichage des informations avec une boucle
    for (int i = 0; i < NB_ETUDIANTS; i++) {
        printf("Étudiant.e %d :\n", i + 1);
        printf("  Nom et Prénom : %s\n", noms_prenoms[i]);
        printf("  Adresse       : %s\n", adresses[i]);
        printf("  Note Programmation C : %.1f/20\n", notes_programmation[i]);
        printf("  Note Système Exploit.: %.1f/20\n", notes_systeme[i]);
        
        // Calcul de la moyenne
        float moyenne = (notes_programmation[i] + notes_systeme[i]) / 2.0;
        printf("  Moyenne générale     : %.1f/20", moyenne);
        
        // Mention
        if (moyenne >= 16.0) {
            printf(" (Très Bien)\n");
        } else if (moyenne >= 14.0) {
            printf(" (Bien)\n");
        } else if (moyenne >= 12.0) {
            printf(" (Assez Bien)\n");
        } else if (moyenne >= 10.0) {
            printf(" (Passable)\n");
        } else {
            printf(" (Insuffisant)\n");
        }
        
        printf("\n");
    }
    
    // Statistiques générales
    printf("=== STATISTIQUES GÉNÉRALES ===\n");
    
    float somme_prog = 0, somme_sys = 0;
    float max_prog = notes_programmation[0], min_prog = notes_programmation[0];
    float max_sys = notes_systeme[0], min_sys = notes_systeme[0];
    
    for (int i = 0; i < NB_ETUDIANTS; i++) {
        somme_prog += notes_programmation[i];
        somme_sys += notes_systeme[i];
        
        // Min/Max pour Programmation
        if (notes_programmation[i] > max_prog) max_prog = notes_programmation[i];
        if (notes_programmation[i] < min_prog) min_prog = notes_programmation[i];
        
        // Min/Max pour Système
        if (notes_systeme[i] > max_sys) max_sys = notes_systeme[i];
        if (notes_systeme[i] < min_sys) min_sys = notes_systeme[i];
    }
    
    printf("Programmation en C :\n");
    printf("  Moyenne de classe : %.1f/20\n", somme_prog / NB_ETUDIANTS);
    printf("  Note maximale     : %.1f/20\n", max_prog);
    printf("  Note minimale     : %.1f/20\n", min_prog);
    
    printf("\nSystème d'exploitation :\n");
    printf("  Moyenne de classe : %.1f/20\n", somme_sys / NB_ETUDIANTS);
    printf("  Note maximale     : %.1f/20\n", max_sys);
    printf("  Note minimale     : %.1f/20\n", min_sys);
    
    printf("\nMoyenne générale de classe : %.1f/20\n", (somme_prog + somme_sys) / (2 * NB_ETUDIANTS));
    
    // Recherche des meilleurs étudiants
    printf("\n=== CLASSEMENT ===\n");
    
    // Calcul des moyennes individuelles
    float moyennes[5];
    for (int i = 0; i < NB_ETUDIANTS; i++) {
        moyennes[i] = (notes_programmation[i] + notes_systeme[i]) / 2.0;
    }
    
    // Affichage du classement (simple tri par insertion pour l'affichage)
    int indices[5] = {0, 1, 2, 3, 4};
    
    // Tri des indices par moyenne décroissante
    for (int i = 0; i < NB_ETUDIANTS - 1; i++) {
        for (int j = i + 1; j < NB_ETUDIANTS; j++) {
            if (moyennes[indices[i]] < moyennes[indices[j]]) {
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }
    
    for (int i = 0; i < NB_ETUDIANTS; i++) {
        int idx = indices[i];
        printf("%d. %s - Moyenne: %.1f/20\n", 
               i + 1, noms_prenoms[idx], moyennes[idx]);
    }
    
    return 0;
}
