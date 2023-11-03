unsigned int* find_snps(char* input, char* ref, unsigned int* snplen);
void print_snps(char* input, char* ref);
unsigned int contains_start_codon(char* input, char* ref);
unsigned int find_start_codon(char* input, char* ref);
void find_nonsense(char* input, char* ref, unsigned int len);
double percent_homology(char* input, char* ref);
void print_homology(char* input, char* ref);
