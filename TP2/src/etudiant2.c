/*
Mehdi NAOUI
B3 + L CNAM
01/12/2025
ESEITT
Gestion des Données d'Étudiant.e.s en C avec des Structures
*/

#include <stdio.h>
#include <string.h>

// Définition de la structure Etudiant
struct Etudiant {
    char nom[50];
    char prenom[50];
    char adresse[150];
    float note_programmation;
    float note_systeme;
    float moyenne;
};

// Fonction pour calculer la moyenne d'un étudiant
void calculer_moyenne(struct Etudiant *etudiant) {
    etudiant->moyenne = (etudiant->note_programmation + etudiant->note_systeme) / 2.0;
}

// Fonction pour afficher les informations d'un étudiant
void afficher_etudiant(struct Etudiant etudiant, int numero) {
    printf("Étudiant.e %d :\n", numero);
    printf("  Nom     : %s\n", etudiant.nom);
    printf("  Prénom  : %s\n", etudiant.prenom);
    printf("  Adresse : %s\n", etudiant.adresse);
    printf("  Note 1  : %.1f/20 (Programmation C)\n", etudiant.note_programmation);
    printf("  Note 2  : %.1f/20 (Système d'exploitation)\n", etudiant.note_systeme);
    printf("  Moyenne : %.1f/20", etudiant.moyenne);
    
    // Affichage de la mention
    if (etudiant.moyenne >= 16.0) {
        printf(" (Très Bien)\n");
    } else if (etudiant.moyenne >= 14.0) {
        printf(" (Bien)\n");
    } else if (etudiant.moyenne >= 12.0) {
        printf(" (Assez Bien)\n");
    } else if (etudiant.moyenne >= 10.0) {
        printf(" (Passable)\n");
    } else {
        printf(" (Insuffisant)\n");
    }
    printf("\n");
}

// Fonction pour initialiser un étudiant
void initialiser_etudiant(struct Etudiant *etudiant, char *nom, char *prenom, 
                         char *adresse, float note_prog, float note_sys) {
    strcpy(etudiant->nom, nom);
    strcpy(etudiant->prenom, prenom);
    strcpy(etudiant->adresse, adresse);
    etudiant->note_programmation = note_prog;
    etudiant->note_systeme = note_sys;
    calculer_moyenne(etudiant);
}

int main() {
    // Création d'un tableau de 5 structures Etudiant
    struct Etudiant etudiants[5];
    const int NB_ETUDIANTS = 5;
    
    printf("=== GESTION DES DONNÉES ÉTUDIANTES AVEC STRUCTURES ===\n\n");
    
    // Initialisation des données des étudiants avec strcpy
    initialiser_etudiant(&etudiants[0], "Dupont", "Marie", 
                        "20, Boulevard Niels Bohr, Lyon", 16.5, 12.1);
    
    initialiser_etudiant(&etudiants[1], "Martin", "Pierre", 
                        "22, Boulevard Niels Bohr, Lyon", 14.0, 14.1);
    
    initialiser_etudiant(&etudiants[2], "Durand", "Sophie", 
                        "15, Rue des Sciences, Paris", 18.5, 16.0);
    
    initialiser_etudiant(&etudiants[3], "Bernard", "Lucas", 
                        "30, Avenue Einstein, Toulouse", 12.0, 10.5);
    
    initialiser_etudiant(&etudiants[4], "Petit", "Emma", 
                        "8, Place Curie, Marseille", 15.5, 13.8);
    
    // Affichage des données de tous les étudiants
    printf("Liste des %d étudiant.e.s :\n\n", NB_ETUDIANTS);
    
    for (int i = 0; i < NB_ETUDIANTS; i++) {
        afficher_etudiant(etudiants[i], i + 1);
    }
    
    // Calcul des statistiques avec les structures
    printf("=== STATISTIQUES AVEC STRUCTURES ===\n");
    
    float somme_prog = 0, somme_sys = 0, somme_moyennes = 0;
    float max_moyenne = etudiants[0].moyenne;
    float min_moyenne = etudiants[0].moyenne;
    int index_meilleur = 0, index_moins_bon = 0;
    
    for (int i = 0; i < NB_ETUDIANTS; i++) {
        somme_prog += etudiants[i].note_programmation;
        somme_sys += etudiants[i].note_systeme;
        somme_moyennes += etudiants[i].moyenne;
        
        if (etudiants[i].moyenne > max_moyenne) {
            max_moyenne = etudiants[i].moyenne;
            index_meilleur = i;
        }
        
        if (etudiants[i].moyenne < min_moyenne) {
            min_moyenne = etudiants[i].moyenne;
            index_moins_bon = i;
        }
    }
    
    printf("Moyennes de classe :\n");
    printf("  Programmation C       : %.1f/20\n", somme_prog / NB_ETUDIANTS);
    printf("  Système d'exploitation: %.1f/20\n", somme_sys / NB_ETUDIANTS);
    printf("  Moyenne générale      : %.1f/20\n", somme_moyennes / NB_ETUDIANTS);
    printf("\n");
    
    printf("Meilleur.e étudiant.e : %s %s (%.1f/20)\n", 
           etudiants[index_meilleur].prenom, etudiants[index_meilleur].nom, max_moyenne);
    
    printf("Étudiant.e en difficulté : %s %s (%.1f/20)\n", 
           etudiants[index_moins_bon].prenom, etudiants[index_moins_bon].nom, min_moyenne);
    
    // Classement par moyenne décroissante
    printf("\n=== CLASSEMENT PAR MOYENNE ===\n");
    
    // Copie du tableau pour le tri (préservation de l'original)
    struct Etudiant etudiants_tries[5];
    for (int i = 0; i < NB_ETUDIANTS; i++) {
        etudiants_tries[i] = etudiants[i];
    }
    
    // Tri par sélection (par moyenne décroissante)
    for (int i = 0; i < NB_ETUDIANTS - 1; i++) {
        int max_index = i;
        for (int j = i + 1; j < NB_ETUDIANTS; j++) {
            if (etudiants_tries[j].moyenne > etudiants_tries[max_index].moyenne) {
                max_index = j;
            }
        }
        
        // Échange des structures complètes
        if (max_index != i) {
            struct Etudiant temp = etudiants_tries[i];
            etudiants_tries[i] = etudiants_tries[max_index];
            etudiants_tries[max_index] = temp;
        }
    }
    
    // Affichage du classement
    for (int i = 0; i < NB_ETUDIANTS; i++) {
        printf("%d. %s %s - %.1f/20\n", 
               i + 1, etudiants_tries[i].prenom, etudiants_tries[i].nom, 
               etudiants_tries[i].moyenne);
    }
    
    // Démonstration de l'accès aux membres de structure
    printf("\n=== DÉMONSTRATION D'ACCÈS AUX STRUCTURES ===\n");
    printf("Accès direct aux données du premier étudiant :\n");
    printf("  etudiants[0].nom = \"%s\"\n", etudiants[0].nom);
    printf("  etudiants[0].prenom = \"%s\"\n", etudiants[0].prenom);
    printf("  etudiants[0].note_programmation = %.1f\n", etudiants[0].note_programmation);
    printf("  etudiants[0].moyenne = %.1f\n", etudiants[0].moyenne);
    
    return 0;
}
