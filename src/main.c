#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/base.h"
#include "../headers/branchs.h"
#include "../headers/ints.h"
#include "../headers/prims.h"
#include "../headers/mem.h"
#include "../headers/blocks.h"
#include "../headers/atoms.h"

/*
@requires n > 0 the size of t
@assigns nothing
@ensures display the content of t line by line with the index
*/
void print_tab_ligne(value* t, int n) {
    for (int i = 0 ; i<n ; i++) 
        printf("%d %ld\n",i,t[i]);
}


/*
@requires s a well formed stack, *index < length(codes)
@assigns s, acc, index, values
@ensures Check in which category inst is, then executes it
*/
void etape(Stack* s, int* codes, value* values, value* acc, int* index, int inst, value** arr_atomes) {
        // Base
        if (inst <= 20)
            base(s,acc,index,codes,inst);
        
        // Branchements
        if (inst >= 84 && inst <= 88)
            branchements(acc,index,codes,inst);
        
        // Entiers
        if (inst >= 99 && inst <= 140 && inst != 128)
            entiers(s,acc,index,codes,inst);

        // Primitives
        if (inst == 93) {
            c_call1(codes[*index + 1],acc);
            *index += 1;
        }
        if (inst == 94) {
            value v = pop(s);
            c_call2(codes[*index + 1],v,acc);
            *index += 1;
        }

        // Memoire globale
        if (inst == 53 || inst == 54 || inst == 57) {
            memory(s,codes,values,acc,index,inst);
            *index += 1;
        }

        // Creation de blocs
        if (inst >= 62 && inst <= 65)
            blocks_creation(s,codes,acc,index,inst);

        // Acces et écriture dans les blocs
        if ((inst >= 67 && inst <= 81) || inst == 55 || inst == 56 || inst == 128)
            acces_blocs(s,codes,values,index,acc,inst);

        // Atomes
        if (inst >= 58 && inst <= 61) {
            atomes(s,codes,acc,index,inst,arr_atomes);
        }

        *index += 1;
}

/* Fonction main */

int main(int argc, char* argv[]) {
    // Vérification du nombre d'arguments
    if (argc != 2 && argc != 3) {
        fprintf(stderr,"usage: %s <file> [--print-end-machine]\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    // Activation de l'affichage de la machine à la fin
    int print_end = 0;
    if (argc >= 3 && strcmp(argv[2],"--print-end-machine") == 0)
        print_end = 1;

    char* file = argv[1];

    // Ouverture du fichier
    FILE* f = fopen(file,"r");
    if (f == NULL) {
        perror("[fopen]");
        exit(2);
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), f); // lit "SOBF"
    
    int nbcodes;
    int nbval;
    fgets(buffer, sizeof(buffer), f); // lit "[nb codes] [nb valeurs]"
    sscanf(buffer,"%d %d",&nbcodes,&nbval);

    // lit les différentes instructions du code et les stocke dans le tableau "codes"
    int codes[nbcodes];
    fread(codes,sizeof(int),nbcodes,f);

    // lit les différentes valeurs du code et les stocke dans le tableau "values"
    value values[nbval];
    fread(values,sizeof(value),nbval,f);

    // Initialise la pile
    Stack* s = initialiser_pile();

    // Initialise le tableau d'atomes
    value* arr_atomes[256];
    for (int i = 0 ; i < 256 ; i++)
        arr_atomes[i] = malloc(0);

    int index = 0;
    value acc = 1;

    while (index <= nbcodes) {
        int inst = codes[index];
        // Arrêt du programme
        if (inst == 143) break;

        // Execution de l'instruction en cours
        etape(s,codes,values,&acc,&index,inst,arr_atomes);
    }

    // Affichage de la machine
    printf("\n");
    if (print_end == 1) {
        printf("Index: %d\n",index);
        printf("Accumulator: %ld\n",acc);
        printf("Stack:\n");
        print_stack(*s);
        printf("Global:\n");
        print_tab_ligne(values,nbval);
    }

    // On ferme le flux et on vide la pile pour liberer l'espace alloué
    fclose(f);
    while (!est_vide(*s))
        pop(s);
    return EXIT_SUCCESS;
}