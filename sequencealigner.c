#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 

/*need to establish spot in memory for out parameter-- not facile to ask user to
 input space for outparameter*/
unsigned int snpslen;
unsigned int* find_snps(char* input, char* ref, unsigned int* snplen){
    /*Initializing a snpslen variable to track length of snps array*/
    unsigned int snpslen = 0;
    /*Iterating through once to measure snpslen*/
    unsigned int i = 0;
    while (input[i]){
        if (input[i] != ref[i]){
            snpslen++;
        }
        i++;
    }
    /*mallocing snpslocs array*/
    unsigned int* snpslocs;
    snpslocs = malloc(sizeof(unsigned int) * snpslen);
    unsigned int count = 0;
    /*appending to snpslocs array-- change to while loop because string*/
    unsigned int j = 0;
    while (ref[j]){
        if (input[j] != ref[j]){
            snpslocs[count] = j;
            count++;
        }
        j++;
    }
    
    if (j != i){
        fprintf(stderr, "find_snps: input and ref are of different lengths, please input sequences of the same length");
        exit(1);
    }
    /*setting out parameter equal to snpslen*/
    *snplen = snpslen;
    return snpslocs;
}

void print_snps(char* input, char* ref){
    /*Iterating through once to measure print*/
    /*what I really want to do here is pass find_snps to print_snps 
    (this would be much quicker, and would save me having to check lengths 
    again) but that requires me to solve the out parameter problem first*/
    /*Note that for the time being there is no failsafe for mismatch lengths
     in this function*/
    unsigned int i = 0;
    while (input[i]){
        if (input[i] != ref[i]){
            printf("There is a %c to %c mutation at BP %d\n", 
            ref[i], input[i], i+1);
        }
        i++;
    }
}

// unsigned int contains_start_codon(char* input, char* ref){
//     /*fix toupper syntax*/
//     char* input1 = toupper(input);
//     char* ref1 = toupper(ref);
//     unsigned int i = 0;
//     while(ref1[i+2]){
//         if (ref1[i] == 'A' && ref1[i+1] == 'U' && ref1[i+2] == 'G'){
//             return 1;
//         }
//         i++;
//     }
//     return 0;
// }

// unsigned int find_start_codon(char* input, char* ref){
//     if (!contains_start_codon(input, ref)){
//         fprintf(stderr, "find_start_codon: no start codon exists in sequence");
//         exit(1);
//     }
//     unsigned int i = 0;
//     while(ref[i+2]){
//         if (ref[i] == 'A' && ref[i+1] == 'U' && ref[i+2] == 'G'){
//             return i;
//         }
//         i++;
//     }
// }

// void find_nonsense(char* input, char* ref, unsigned int len){
//     /*acquire snpslocs*/
//     /*this is an issue because whether or not something is nonsense depends 
//     entirely on where start codon is-- maybe search for start codon in sequence,
//      otherwise fail? come back later...*/
//     unsigned int snplen;
//     unsigned int* snpsloc = snpslocs(input, ref, len, &snplen);
//     for (int i = 0; i < snplen; i++){
//         /*do switch statements here*/
//     }

// }

double percent_homology(char* input, char* ref){
    unsigned int snplen1;
    unsigned int* muts = find_snps(input, ref, &snplen1);
    int totallen = 0;
    while (input[totallen]){
        totallen++;
    }
    return (snplen1 / (double) totallen) * 100.00;
    free(muts);
}

void print_homology(char* input, char* ref){
    double hom = percent_homology(input, ref);
    printf("The sequences are %f percent homologous.\n", hom);
    return;
}

int main(int argc, char** argv){
    // int x = 0;
    // int y = 0;
    // while(argv[x]){
    //     x++;
    //     while (argv[x][y]){
    //         if (argv[x][y] != ("A" || "G" || "C" || "T")){
    //             fprintf(stderr, "main: arguments not of correct type\n");
    //             exit(1);
    //         }
    //         y++;
    //     }
    // }
    printf("SNPS:\n");
    print_snps(argv[1], argv[2]);
    printf("Homology:\n");
    print_homology(argv[1], argv[2]);
    return 1;
}