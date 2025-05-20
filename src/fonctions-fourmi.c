#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// #define _USE_MATH_DEFINES
#define M_PI 3.141563

#include "fonctions-fourmi.h"

void move_ant(int ant[3])
 {
    
    double theta_rad = ant[2] * M_PI / 180.0;

    int dx = (int)round(cos(theta_rad));
    int dy = (int)round(sin(theta_rad));

    ant[0] += dx;
    ant[1] += dy;
}

void turn_ant(int ant[3], int dtheta)
 {
    
    ant[2] += dtheta;

    // modulo 360° pour éviter les dépassement mémoire
    ant[2] = (ant[2] % 360 + 360) % 360;
}

struct matrice* matrice_create(int largeur, int hauteur)
{

    struct matrice *res = malloc(sizeof(struct matrice));
    
    if (res != NULL)
    {
        res->largeur = largeur;
        res->hauteur = hauteur;
        res->cellules = calloc(largeur*hauteur, sizeof(int));
        
        if (res->cellules == NULL)
        {
            free(res);
            return NULL;
        }
    }
    
    return res;
}

void make_random_matrice(struct matrice *self, long int seed)
{
    
    if (self == NULL)
    {
        return;
    }

    srand(seed);

    for (int y=0; y<self->hauteur; ++y)
    {
        for (int x=0; x<self->largeur; ++x)
        {
            if (rand()%2 == 0)
            {
                set_etat_cellule(self, x, y, 1);
            }
        }
    }
}

void make_zero_matrice(struct matrice *self)
{
    if (self == NULL)
    {
        return;
    }

    for (int y = 0; y<self->hauteur; ++y)
    {
        for (int x = 0; x<self->largeur; ++x)
        {
            set_etat_cellule(self, x, y, 0);
        }
    }
}

void free_matrice(struct matrice *self)
{
    free(self->cellules);
    free(self);
}

int get_etat_cellule(struct matrice *self, int x, int y)
{
    return self->cellules[y*self->largeur+x];
}

void set_etat_cellule(struct matrice *self, int x, int y, int etat)
{
    self->cellules[y*self->largeur+x] = etat;
}

void update(struct matrice *self, int ant[3])
{
    if (self == NULL || ant == NULL)
    {
        return;
    }

    int x = ant[0];
    int y = ant[1];

    if (1 == get_etat_cellule(self, x, y))
    {
        set_etat_cellule(self, x, y, 0);
        turn_ant(ant, -90);
    } else
    {
        set_etat_cellule(self, x, y, 1);
        turn_ant(ant, 90);
    }
    
    move_ant(ant);
}
