/*
Mehdi NAOUI
B3 + L CNAM
01/12/2025
ESEITT
Gestion des Couleurs en Format RGBA avec des Structures
*/

#include <stdio.h>
#include <stdint.h>

// Définition de la structure pour une couleur RGBA
struct CouleurRGBA {
    uint8_t rouge;    // Composant rouge (0-255)
    uint8_t vert;     // Composant vert (0-255)
    uint8_t bleu;     // Composant bleu (0-255)
    uint8_t alpha;    // Composant alpha/transparence (0-255)
};

// Fonction pour afficher une couleur
void afficher_couleur(struct CouleurRGBA couleur, int numero) {
    printf("Couleur %d :\n", numero);
    printf("  Rouge : %d\n", couleur.rouge);
    printf("  Vert  : %d\n", couleur.vert);
    printf("  Bleu  : %d\n", couleur.bleu);
    printf("  Alpha : %d\n", couleur.alpha);
    printf("\n");
}

// Fonction pour afficher une couleur avec notation hexadécimale
void afficher_couleur_hex(struct CouleurRGBA couleur, int numero) {
    printf("Couleur %d (hex) : R=0x%02x G=0x%02x B=0x%02x A=0x%02x\n", 
           numero, couleur.rouge, couleur.vert, couleur.bleu, couleur.alpha);
}

// Fonction pour créer une couleur RGBA
struct CouleurRGBA creer_couleur(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    struct CouleurRGBA couleur;
    couleur.rouge = r;
    couleur.vert = g;
    couleur.bleu = b;
    couleur.alpha = a;
    return couleur;
}

// Fonction pour afficher une palette de couleurs avec barres colorées ASCII
void afficher_barre_couleur(struct CouleurRGBA couleur) {
    // Approximation ASCII basée sur la luminosité
    int luminosite = (couleur.rouge * 299 + couleur.vert * 587 + couleur.bleu * 114) / 1000;
    
    printf("  [");
    for (int i = 0; i < 20; i++) {
        if (luminosite > 200) printf("█");
        else if (luminosite > 150) printf("▓");
        else if (luminosite > 100) printf("▒");
        else if (luminosite > 50) printf("░");
        else printf(" ");
    }
    printf("] ");
}

int main() {
    // Création d'un tableau de 10 couleurs RGBA
    struct CouleurRGBA couleurs[10];
    const int NB_COULEURS = 10;
    
    printf("=== GESTION DES COULEURS RGBA AVEC STRUCTURES ===\n\n");
    
    // Initialisation des couleurs avec notation hexadécimale
    couleurs[0] = creer_couleur(0xef, 0x78, 0x12, 0xff);  // Orange vif
    couleurs[1] = creer_couleur(0x2c, 0xc8, 0x64, 0xff);  // Vert
    couleurs[2] = creer_couleur(0x3b, 0x82, 0xf6, 0xff);  // Bleu
    couleurs[3] = creer_couleur(0xf5, 0x59, 0x42, 0xff);  // Rouge corail
    couleurs[4] = creer_couleur(0x8b, 0x5c, 0xf6, 0xff);  // Violet
    couleurs[5] = creer_couleur(0xf5, 0x9e, 0x0b, 0xff);  // Jaune orange
    couleurs[6] = creer_couleur(0x06, 0xb6, 0xd4, 0xff);  // Cyan
    couleurs[7] = creer_couleur(0xec, 0x48, 0x99, 0xff);  // Rose
    couleurs[8] = creer_couleur(0x64, 0x74, 0x8b, 0x80);  // Gris semi-transparent
    couleurs[9] = creer_couleur(0x00, 0x00, 0x00, 0x00);  // Transparent
    
    // Affichage des couleurs selon l'exemple demandé
    printf("Liste des %d couleurs :\n\n", NB_COULEURS);
    
    for (int i = 0; i < NB_COULEURS; i++) {
        afficher_couleur(couleurs[i], i + 1);
    }
    
    // Affichage avec notation hexadécimale
    printf("=== AFFICHAGE AVEC NOTATION HEXADÉCIMALE ===\n");
    for (int i = 0; i < NB_COULEURS; i++) {
        afficher_couleur_hex(couleurs[i], i + 1);
    }
    printf("\n");
    
    // Palette de couleurs avec visualisation ASCII
    printf("=== PALETTE DE COULEURS (APPROXIMATION ASCII) ===\n");
    for (int i = 0; i < NB_COULEURS; i++) {
        printf("Couleur %2d : ", i + 1);
        afficher_barre_couleur(couleurs[i]);
        printf("R:%3d G:%3d B:%3d A:%3d\n", 
               couleurs[i].rouge, couleurs[i].vert, 
               couleurs[i].bleu, couleurs[i].alpha);
    }
    printf("\n");
    
    // Analyse des couleurs
    printf("=== ANALYSE DES COULEURS ===\n");
    
    int couleurs_opaques = 0;
    int couleurs_transparentes = 0;
    struct CouleurRGBA couleur_plus_claire = couleurs[0];
    struct CouleurRGBA couleur_plus_sombre = couleurs[0];
    
    for (int i = 0; i < NB_COULEURS; i++) {
        // Comptage opacité
        if (couleurs[i].alpha == 0xff) {
            couleurs_opaques++;
        } else if (couleurs[i].alpha == 0x00) {
            couleurs_transparentes++;
        }
        
        // Calcul de la luminosité (formule standard)
        int luminosite_actuelle = (couleurs[i].rouge * 299 + 
                                  couleurs[i].vert * 587 + 
                                  couleurs[i].bleu * 114) / 1000;
        
        int luminosite_claire = (couleur_plus_claire.rouge * 299 + 
                                couleur_plus_claire.vert * 587 + 
                                couleur_plus_claire.bleu * 114) / 1000;
        
        int luminosite_sombre = (couleur_plus_sombre.rouge * 299 + 
                                couleur_plus_sombre.vert * 587 + 
                                couleur_plus_sombre.bleu * 114) / 1000;
        
        if (luminosite_actuelle > luminosite_claire) {
            couleur_plus_claire = couleurs[i];
        }
        
        if (luminosite_actuelle < luminosite_sombre) {
            couleur_plus_sombre = couleurs[i];
        }
    }
    
    printf("Couleurs complètement opaques : %d\n", couleurs_opaques);
    printf("Couleurs complètement transparentes : %d\n", couleurs_transparentes);
    printf("Couleurs semi-transparentes : %d\n", 
           NB_COULEURS - couleurs_opaques - couleurs_transparentes);
    
    printf("\nCouleur la plus claire : R:%d G:%d B:%d\n", 
           couleur_plus_claire.rouge, couleur_plus_claire.vert, couleur_plus_claire.bleu);
    printf("Couleur la plus sombre : R:%d G:%d B:%d\n", 
           couleur_plus_sombre.rouge, couleur_plus_sombre.vert, couleur_plus_sombre.bleu);
    
    // Démonstration de manipulation des structures
    printf("\n=== MANIPULATION DES STRUCTURES ===\n");
    
    // Modification d'une couleur
    printf("Modification de la couleur 1 :\n");
    printf("Avant : R:%d G:%d B:%d A:%d\n", 
           couleurs[0].rouge, couleurs[0].vert, couleurs[0].bleu, couleurs[0].alpha);
    
    couleurs[0].rouge = 0x80;
    couleurs[0].vert = 0x40;
    couleurs[0].bleu = 0x20;
    
    printf("Après : R:%d G:%d B:%d A:%d\n", 
           couleurs[0].rouge, couleurs[0].vert, couleurs[0].bleu, couleurs[0].alpha);
    
    // Copie de structure
    struct CouleurRGBA couleur_copie = couleurs[2];
    printf("\nCopie de la couleur 3 :\n");
    printf("Original : R:%d G:%d B:%d A:%d\n", 
           couleurs[2].rouge, couleurs[2].vert, couleurs[2].bleu, couleurs[2].alpha);
    printf("Copie    : R:%d G:%d B:%d A:%d\n", 
           couleur_copie.rouge, couleur_copie.vert, couleur_copie.bleu, couleur_copie.alpha);
    
    return 0;
}
