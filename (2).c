#include "calculatrice_avancee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int est_operateur(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int priorite_operation(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

double appliquer_operation(double a, double b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b != 0) return a / b;
            printf("Erreur: division par zero\n");
            return 0;
        case '^': return pow(a, b);
        default: return 0;
    }
}

double calculer_puissance(double base, double exposant) {
    return pow(base, exposant);
}

static double traiter_parenthese(const char **expr) {
    double resultat;
    (*expr)++;
    char temp[256];
    int i = 0;
    int parentheses = 1;
    
    while (**expr && parentheses > 0) {
        if (**expr == '(') parentheses++;
        if (**expr == ')') parentheses--;
        if (parentheses > 0) {
            temp[i++] = **expr;
        }
        (*expr)++;
    }
    temp[i] = '\0';
    
    resultat = evaluer_expression(temp);
    return resultat;
}

static double lire_nombre(const char **expr) {
    char nombre_str[64];
    int i = 0;
    
    while (**expr && (isdigit(**expr) || **expr == '.')) {
        nombre_str[i++] = **expr;
        (*expr)++;
    }
    nombre_str[i] = '\0';
    
    return atof(nombre_str);
}

double evaluer_expression(const char *expression) {
    double valeurs[100];
    char operateurs[100];
    int val_index = 0;
    int op_index = 0;
    int i = 0;
    double nombre_courant;
    char c;
    
    while ((c = expression[i]) != '\0') {
        if (isspace(c)) {
            i++;
            continue;
        }
        
        if (isdigit(c) || c == '.') {
            char nombre_str[64];
            int j = 0;
            
            while (isdigit(expression[i]) || expression[i] == '.') {
                nombre_str[j++] = expression[i++];
            }
            nombre_str[j] = '\0';
            nombre_courant = atof(nombre_str);
            valeurs[val_index++] = nombre_courant;
            continue;
        }
        
        if (c == '(') {
            const char *ptr = expression + i;
            double val_parenthese = traiter_parenthese(&ptr);
            valeurs[val_index++] = val_parenthese;
            i = ptr - expression;
            continue;
        }
        
        if (est_operateur(c)) {
            while (op_index > 0 && 
                   priorite_operation(operateurs[op_index-1]) >= priorite_operation(c)) {
                double b = valeurs[--val_index];
                double a = valeurs[--val_index];
                char op = operateurs[--op_index];
                valeurs[val_index++] = appliquer_operation(a, b, op);
            }
            operateurs[op_index++] = c;
            i++;
            continue;
        }
        
        i++;
    }
    
    while (op_index > 0) {
        double b = valeurs[--val_index];
        double a = valeurs[--val_index];
        char op = operateurs[--op_index];
        valeurs[val_index++] = appliquer_operation(a, b, op);
    }
    
    if (val_index > 0) {
        return valeurs[0];
    }
    
    return 0;
}