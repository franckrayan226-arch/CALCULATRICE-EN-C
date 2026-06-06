#include <stdio.h>
#include <string.h>
#include "calculatrice_avancee.h"

int main(void) {
    char input[512];
    double resultat;
    
    printf("========================================\n");
    printf("CALCULATRICE SCIENTIFIQUE AVANCEE\n");
    printf("========================================\n");
    printf("Operations supportees:\n");
    printf("  +  : addition\n");
    printf("  -  : soustraction\n");
    printf("  *  : multiplication\n");
    printf("  /  : division\n");
    printf("  ^  : puissance\n");
    printf("  () : parentheses\n");
    printf("\n");
    printf("Exemples:\n");
    printf("  2 + 3 * 4\n");
    printf("  (2 + 3) * 4\n");
    printf("  2 ^ 3\n");
    printf("  10 / 2 + 3\n");
    printf("\n");
    printf("Tapez 'quitter' pour fermer le programme\n");
    printf("========================================\n\n");
    
    while (1) {
        printf("> ");
        fflush(stdout);
        
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }
        
        input[strcspn(input, "\n")] = '\0';
        
        if (strcmp(input, "quitter") == 0 || strcmp(input, "quit") == 0 || 
            strcmp(input, "exit") == 0 || strcmp(input, "q") == 0) {
            printf("Fermeture de la calculatrice.\n");
            break;
        }
        
        if (strlen(input) == 0) {
            continue;
        }
        
        resultat = evaluer_expression(input);
        printf("%s = %.10g\n\n", input, resultat);
    }
    
    return 0;
}