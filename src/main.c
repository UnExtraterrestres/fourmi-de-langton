#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include "fonctions-fourmi.h"
#include "sig-console.h"

#define NB_TOUR 11500

void afficher_matrice(struct ecran *ecran, struct matrice *matrice)
{

    /**
     * @brief Affiche une matrice sur un écran.
     *
     * Cette fonction parcourt chaque cellule de la matrice donnée.
     *  Si l'état de la cellule est 1,
     *      elle place un pixel à la position correspondante sur l'écran.
     *  Si l'état de la cellule est 0,
     *      elle retire le pixel à la position correspondante sur l'écran.
     * Enfin, elle affiche l'écran.
     *
     * @param ecran Un pointeur vers la structure ecran où la matrice doit être affichée.
     * @param matrice Un pointeur vers la structure matrice qui contient les données à afficher.
    */

    for (int y=0; y<matrice->hauteur; ++y)
    {
        for (int x=0; x<matrice->largeur; ++x)
        {
            if (get_etat_cellule(matrice, x, y) == 1)
            {
                placer_pixel_from(ecran, x, y);
            } else {
                retirer_pixel_from(ecran, x, y);
            }
        }
    }

    afficher(ecran);
}

int main(int argc, char *argv[])
{

    int width = get_screen_width();
    int height = get_screen_height();

    struct ecran *ecran = ecran_create(width, height);
    struct matrice *matrice = matrice_create(ecran->largeur, ecran->hauteur);
    
    int mid_x_screen = width / 2;
    int mid_y_screen = height / 2;
    int ant[3] = {mid_x_screen, mid_y_screen, 270};

    make_zero_matrice(matrice);

    // Boucle principale du jeu de la vie
    long int tour = 0;
    while (NB_TOUR >= tour)
    {
        update(matrice, ant);
        afficher_matrice(ecran, matrice);

        // printf("Tour %ld\n", tour);
        // attente pour le prochain tour
        // Ctrl+C pour quitter
        // getchar();

        tour++;
    }

    free_matrice(matrice);
    free_ecran(ecran);

    return 0;
}
