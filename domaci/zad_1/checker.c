#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    char korisnikov_ulaz_fajl[] = "korisnikov_ulaz.txt";
    char tacan_izlaz_fajl[] = "tacan_izlaz.txt";
    char korisnikov_izlaz_fajl[] = "korisnikov_izlaz.txt";

    FILE *tacan_izlaz = fopen(tacan_izlaz_fajl, "r");
    FILE *korisnikov_izlaz = fopen(korisnikov_izlaz_fajl, "r");

    if (tacan_izlaz == NULL || tacan_izlaz == NULL) {
        printf("Nije moguce otvoriti fajlove.\n");
        return 1;
    }

    double kor_rez, tacan_rez;

    fscanf(korisnikov_izlaz, "%lf", &kor_rez);
    fscanf(tacan_izlaz, "%lf", &tacan_rez);
    if(fabs(kor_rez - tacan_rez) < 1e-9) {
        fprintf(stderr, "translate:success (1)");
    } else if(fabs(kor_rez - tacan_rez) > 1e-9  && fabs(kor_rez - tacan_rez) < 1) {
        fprintf(stderr, "translate:partial (0.5)");
    } else {
        fprintf(stderr, "translate:wrong (0)");
    }

    fclose(tacan_izlaz);
    fclose(korisnikov_izlaz);

    return 0;
}

