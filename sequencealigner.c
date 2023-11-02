char* find_snps(char* input, char* ref, unsigned int len){
    for (int i = 0; i < len; i++){
        if (input[i] != ref[i]){
            printf("There is a %c to %c mutation at BP %d\n", 
            ref[i], input[i], i+1);
        }
    }
    return;
}