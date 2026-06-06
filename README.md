# CALCULATRICE-EN-C
## Description

Ce projet implémente une calculatrice scientifique complète en langage C capable d'évaluer des expressions mathématiques complexes. Elle supporte les opérations arithmétiques de base, la puissance, et les parenthèses avec respect des priorités opératoires.

## Fonctionnalités

- Addition (+)
- Soustraction (-)
- Multiplication (*)
- Division (/)
- Puissance (^)
- Parenthèses pour grouper les expressions
- Gestion des espaces dans les expressions
- Interface en ligne de commande
- Calcul avec des nombres décimaux
- Priorité des opérateurs (PEMDAS)

## Prérequis

- Compilateur C (gcc recommandé)
- Bibliothèque mathématique (libm)

## Installation

### 1. Téléchargement des fichiers

Créez un répertoire pour le projet et copiez-y les fichiers suivants:

- `calculatrice_avancee.h` - Fichier d'en-tête
- `calculatrice_avancee.c` - Implémentation des fonctions
- `main.c` - Interface utilisateur
- `Makefile` - Script de compilation (optionnel)

### 2. Compilation

#### Avec Makefile:
```bash
gcc -o calculatrice main.c calculatrice_avancee.c -lm
Exemples d'expressions valides
> 2 + 3
2 + 3 = 5

> 2 + 3 * 4
2 + 3 * 4 = 14

> (2 + 3) * 4
(2 + 3) * 4 = 20

> 10 / 2 + 3
10 / 2 + 3 = 8

> 2 ^ 3
2 ^ 3 = 8

> 10 - 3 * 2 + 5
10 - 3 * 2 + 5 = 9

> (10 - 3) * (2 + 5)
(10 - 3) * (2 + 5) = 49

> 3.5 * 2 + 1.5
3.5 * 2 + 1.5 = 8.5
make
calculatrice/
├── calculatrice_avancee.h    # Prototypes des fonctions
├── calculatrice_avancee.c    # Implémentation du moteur de calcul
├── main.c                     # Interface utilisateur
├── Makefile                   # Script de compilation
└── README.md                  # Documentation
