# fourmi-de-langton
Ce projet est une version console du célèbre automate cellulaire imaginé par Langton.

## Introduction

La fourmi de Langton est un modèle mathématique fascinant qui simule l'évolution d'une fourmi sur une grille en fonction de règles simples. Chaque cellule peut être dans l'un des deux états : pleine ou vide. Les cellules évoluent en fonction du passage de la fourmi, le déplacement de la fourmi évolu, lui, en fonction de l'état des cellules.

## Fonctionnalités

  Interface conviviale : Visualisez facilement l'état de la grille dans la console.
  Simulation automatique : Laissez le jeu évoluer automatiquement selon les règles prédéfinies.

## Comment utiliser

  Clonez le repository sur votre machine locale.
  Construisez l'executable :
    `make`
  
  L'expérience est meilleure en nettoyant la console :
  	`clear`
  
  Exécutez l'exécutable généré :
  	`./bin/fourmi2langton [SEED]`

## Règles de la fourmmi de Langton

Les règles du jeu sont simples :

  - Grille : La grille est composée de cellules qui peuvent être dans deux états : pleine (noire) ou vide (blanche).
  - Fourmi : La fourmi se déplace sur la grille selon les règles suivantes :
      - Si la cellule sur laquelle se trouve la fourmi est vide (blanche), la fourmi la remplit (noire) et tourne de 90 degrés à droite.
      - Si la cellule sur laquelle se trouve la fourmi est pleine (noire), la fourmi la vide (blanche) et tourne de 90 degrés à gauche.
  - Déplacement : Après avoir tourné, la fourmi avance d'une cellule dans la direction vers laquelle elle fait face.

## Contribution

Si vous avez des idées pour améliorer le jeu ou corriger des bugs, n'hésitez pas à contribuer.

## Licence

Ce projet est sous licence MIT. Consultez le fichier LICENSE pour plus de détails.
