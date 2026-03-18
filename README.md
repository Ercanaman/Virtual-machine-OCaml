# Virtual-machine-OCaml

Un projet consistant à écrire du code C permettant de lire et d'éxécuter (en partie) du bytecode généré par le compilateur OCaml.

# La machine virtuelle

Le compilateur OCaml produit du bytecode lors de l'exécution de la commande `ocamlc`.
Il peut ensuite être exécuté avec un interpréteur.

Le but ici est de le coder en partie pour pouvoir exécuter le bytecode.

## Principe

Notre machine virtuelle sera constituée de 5 éléments
- Un tableau de code, contenant la liste des instructions.
- Un indice indiquant quelle case du tableau lire.
- Un accumulateur, qui contiendra une valeur qui servira aux instructions.
- Une pile d'éxécution, contenant une liste de valeurs.
- Un tableau de valeurs globales.

On commence à l'indice 0 et avec 1 dans l'accumulateur, puis on exécute l'instruction courante avant d'incrémenter l'indice de 1, sauf si l'instruction change l'indice autrement.

Les instructions Caml sont listées dans ce document : [Instructions Caml](https://cadmium.x9c.fr/distrib/caml-instructions.pdf).

## Le fichier bytecode

Pour le moment, nous nous contenterons d'utiliser une version simplifiée des fichiers bytecode sous forme de fichier `.sobf`.
Le fichier contiendra le nombre d'instructions et de valeurs globales, ainsi que la liste des instructions et la liste des valeurs globales.
Cela permet l'initialisation de la machine virtuelle.

# Documentation du code

Le code est divisé en plusieurs parties : des parties implémentants des instructions OCaml, et une partie implémentant les piles pour la pile d'éxécution.

## Piles (stack.h)

Les piles seront implémentés avec des listes chaînées dans `stack.c`.

```c
struct Cell {
    value val;
    Stack next;
};
```

Les fonctions définies sont présentes dans `stack.h`.
En particulier, pour l'affichage des piles, elles seront affichées sous cette forme :

```[1]->[2]->[3]->[4]->[]```

## Implémentation de la machine virtuelle

Les codes du tableau de code seront des éléments de type `int`, tandis que les valeurs de l'accumulateur, de la pile et du tableau de valeurs globales seront des éléments de type `long int`.
Les valeurs pourront être des adresses mémoire ou des entiers. Pour les différencier, les entiers seront encodés par des entiers impairs, et ainsi, n sera représenté par 2*n + 1.
L'indice sera également un élément de type `int`.

## Instructions

Les instructions seront réparties en plusieurs fichiers, selon leur catégorie.
- `base.c` : Instructions de base (ajout d'élément dans la pile, accès dans la pile etc.).
- `branchs.c` : Changement de l'indice courant (parfois sous condition).
- `ints.c` : Opérations sur les entiers (addition, comparaisons, parité etc.).
- `mem.c` : Accès dans le tableau de valeurs globales.
- `blocks.c` : Création et opérations sur les tableaux.
- `prims.c` : Implémentation de primitives.
- `atoms.c` : Implémentation d'atomes (adresses mémoire sans contenu accessible).

# Les tests disponible dans le Makefile

Vous avez à votre disposition quelques commandes du Makefile pour ce programme.
- `make` : pour créer l'exécutable
- `make clean` : supprime le contenu des répertoires obj et bin
- `make test` : exécute quelques fichiers de test avec l'option --print-end-machine
- `make prims` : exécute le fichier prims.sobf (demande à l'utilisateur d'écrire un caractère et imprime celui-ci)
- `make fact` : exécute le fichier fact.sobf (calcule la factorielle d'un nombre entre 0 et 20 donné par l'utilisateur)
- `make pinetree` : exécute le fichier pinetree.sobf (affiche un demi sapin de taille donné par l'utilisateur)
- `make wumpus` : exécute le fichier wumpus.sobf (permet de jouer au jeu du wumpus)

Les tests peuvent également se faire manuellement avec la commande suivante :

```
./bin/vm_ocaml <fichier .sobf> [--print-end-machine]
```

L'option --print-end-machine affiche l'état de la machine virtuelle à la fin de l'exécution.