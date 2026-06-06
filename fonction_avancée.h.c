#ifndef CALCULATRICE_AVANCEE_H
#define CALCULATRICE_AVANCEE_H

double evaluer_expression(const char *expression);
int est_operateur(char c);
double appliquer_operation(double a, double b, char op);
int priorite_operation(char op);
double calculer_puissance(double base, double exposant);

#endif