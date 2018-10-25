#include <stdio.h>
#include <math.h>
#include "somme.h"

double delta(double, double, double); // definition prototype de fonction delta
double racine_nieme(int a, int n, int k); //definition prototype de fonction racine_carree
double pi_leibniz(int n);
double soustraction(double a, double b);
double multiplication(double a, double b);
double division(double a, double b);
double exposant(double a, double e);

int main() {

    int A, k, n, choix;
    double a, b, c, e;
    double resultat;
    double x1, x2;

    printf("Choisir calcul : \n\n");
    printf("1: Somme\n");
    printf("2: Soustraction\n");
    printf("3: Multiplication\n");
    printf("4: Division\n");
    printf("5: Exposant7\n");
    printf("6: Calcul delta\n");
    printf("7: Calcul racine a partir d'un exposant\n");
    printf("8: Pi\n");

    scanf("%d", &choix);

    if (choix == 1) {
        printf("Inserer deux nombres pour les additionner\n");
        scanf("%lf", &a);
        scanf("%lf", &b);
        printf("%lf", somme(a, b));
    }

    if (choix == 2) {
        printf("Inserer deux nombres pour les soustraire\n");
        scanf("%lf", &a);
        scanf("%lf", &b);
        printf("%lf", soustraction(a, b));
    }

    if (choix == 3) {
        printf("Inserer deux nombres pour les multiplier\n");
        scanf("%lf", &a);
        scanf("%lf", &b);
        printf("%lf", multiplication(a, b));
    }

    if (choix == 4) {
        printf("Inserer deux nombres pour les diviser\n");
        scanf("%lf", &a);
        scanf("%lf", &b);
        printf("%lf", division(a, b));
    }

    if (choix == 5) {
        printf("Inserer nombre a et e son exposant\n");
        scanf("%lf", &a);
        scanf("%lf", &e);
        printf("%lf", exposant(a, e));
    }

    if (choix == 6) {
        printf("Saisir a, b, c");
        scanf("%lf", &a);
        scanf("%lf", &b);
        scanf("%lf", &c);
        resultat = delta(a, b, c);
        if (resultat > 0) {
            x1 = (-b - sqrt(resultat)) / (2 * b);
            x2 = (-b + sqrt(resultat)) / (2 * b);
            printf("2 solutions: {%lf;%lf}", x1, x2);
        }
        if (resultat == 0) {
            x1 = (-b / (2 * a));
            printf("1 solution: {%lf}", x1);
        }
        if (resultat < 0) {
            printf("Pas de solution");
        }
    }

    if (choix == 7) {
        printf("Inserer le nombre dont on veut la racine carree\n");
        scanf("%d", &A);
        printf("Inserer le nombre d'iterations\n");
        scanf("%d", &k);
        printf("Inserer l'exposant de la racine\n");
        scanf("%d", &n);
        printf("%lf", racine_nieme(A, k, n));
    }

    if (choix == 8) {
        printf("Inserer degre de sensibilite 'n' ");
        scanf("%d", &n);
        printf("Calcul de pi %lf \n", pi_leibniz(n));
        return 0;
    }
    return 0;
}

double soustraction(double a, double b) {
    double soustraction_nombres;

    soustraction_nombres = (a - b);

    return soustraction_nombres;
}

double multiplication(double a, double b) {
    double multiplication_nombres;

    multiplication_nombres = (a * b);

    return multiplication_nombres;
}

double division(double a, double b) {
    double division_nombres;

    division_nombres = (a / b);

    return division_nombres;
}

double exposant(double a, double e) {
    double exposant_nombres;

    exposant_nombres = pow(a, e);

    return exposant_nombres;
}

double racine_nieme(int A, int k, int n) {
    double uk;
    uk = 1;

    for (int i = 0; i < k; i++) {
        uk = (1.0 / n) * ((n - 1.0) * uk + (A / (pow(uk, n - 1))));
    }
    return uk;
}

double delta(double a, double b, double c) { // fonction delta

    return ((b * b) - 4 * a * c);

}

double pi_leibniz(int n) { // Au bout de 120
    double resultat;
    for (int i = 0; i <= n; i++) {
        resultat += ((pow(-1.0, i)) / (2.0 * i + 1.0)) * 4;

    }
    return resultat;

}