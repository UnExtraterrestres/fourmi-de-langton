#ifndef FONCTIONSFOURMI_H
#define FONCTIONSFOURMI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/**
 * @file fonctions-fourmi.h
 * @brief Fichier d'en-tête contenant les déclarations des fonctions pour le jeu de la fourmi de Langton.
 */

/**
 * @brief Déplace la fourmi en fonction de son angle actuel.
 *
 * @param ant Tableau représentant la fourmi [x, y, theta].
 */
 void move_ant(int ant[3]);

/**
 * @brief Tourne la fourmi en ajoutant un incrément d'angle.
 *
 * @param ant Tableau représentant la fourmi [x, y, theta].
 * @param dtheta Incrément d'angle en degrés.
 */
 void turn_ant(int ant[3], int dtheta);

/**
 * @struct matrice
 * @brief Structure représentant une matrice.
 */
struct matrice
{
    int largeur;    /**< Largeur de la matrice. */
    int hauteur;    /**< Hauteur de la matrice. */
    int *cellules;  /**< Tableau représentant les cellules de la matrice. */
};

/**
 * @brief Crée une nouvelle matrice avec les dimensions spécifiées.
 * 
 * @param largeur Largeur de la matrice.
 * @param hauteur Hauteur de la matrice.
 * @return Pointeur vers la nouvelle matrice créée.
 */
struct matrice* matrice_create(int largeur, int hauteur);

/**
 * @brief Remplit la matrice avec des valeurs aléatoires (0 ou 1).
 * 
 * @param self Pointeur vers la matrice à remplir.
 * @param seed Graine d'initialisation pour le générateur de pseudo-aléatoire
 */
void make_random_matrice(struct matrice *self, long int seed);

/**
 * @brief Remplit la matrice avec la valeur 0
 * 
 * @param self Pointeur vers la matrice à remplir.
 */
 void make_zero_matrice(struct matrice *self);

/**
 * @brief Libère la mémoire allouée pour une matrice.
 * 
 * @param self Pointeur vers la matrice à libérer.
 */
void free_matrice(struct matrice *self);

/**
 * @brief Récupère l'état de la cellule aux coordonnées spécifiées dans la matrice.
 * 
 * @param self Pointeur vers la matrice.
 * @param x Coordonnée X de la cellule.
 * @param y Coordonnée Y de la cellule.
 * @return État de la cellule (0 ou 1).
 */
int get_etat_cellule(struct matrice *self, int x, int y);

/**
 * @brief Définit l'état d'une cellule aux coordonnées spécifiées dans la matrice.
 * 
 * @param self Pointeur vers la matrice.
 * @param x Coordonnée X de la cellule.
 * @param y Coordonnée Y de la cellule.
 * @param etat Nouvel état de la cellule (0 ou 1).
 */
void set_etat_cellule(struct matrice *self, int x, int y, int etat);

/**
 * @brief Met à jour la matrice selon les règles du jeu de la vie.
 * 
 * @param self Pointeur vers la matrice à mettre à jour.
 */
void update(struct matrice *self, int ant[3]);

#endif /* FONCTIONSFOURMI_H */
// Path: fonctions-fourmi.c
