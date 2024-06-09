#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generisi_cijeli_broj(int min, int maks) {
    return min > 0 ? min + rand() % (maks - min + 1) : rand() % (2 * maks + 1) - maks;
}

void generisi_test_glavna(FILE *ulaz, FILE *izlaz, int maks_dim, int maks) {
    int n = generisi_cijeli_broj(2, maks_dim);

    fprintf(ulaz, "%d\n", n);

    int a[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
           int x = generisi_cijeli_broj(0, maks);
           a[i][j] = x;
           fprintf(ulaz, "%d ", x);
        }
        fprintf(ulaz, "\n");
    }

    int suma = 0;

    for(int i = 0; i < n; i++) {
        suma += a[i][i];
    }

    fprintf(izlaz, "%d\n", suma);
}

void generisi_test_sporedna(FILE *ulaz, FILE *izlaz, int maks_dim, int maks) {
    int n = generisi_cijeli_broj(2, maks_dim);

    fprintf(ulaz, "%d\n", n);

    int a[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
           int x = generisi_cijeli_broj(0, maks);
           a[i][j] = x;
           fprintf(ulaz, "%d ", x);
        }
        fprintf(ulaz, "\n");
    }

    int suma = 0;

    for(int i = 0; i < n; i++) {
        suma += a[i][n - i - 1];
    }

    fprintf(izlaz, "%d\n", suma);
}

int main()
{
    srand(time(NULL));

    int broj_test_primjera;
    printf("Unesite broj test primjera: ");
    scanf("%d", &broj_test_primjera);

    int podzadatak;
    printf("Izaberite podzadatak: \n%s \n%s \n", "1) Suma elemenata glavne dijagonale", "2) Suma elemenata sporedne dijagonale");
    scanf("%d", &podzadatak);

    if (podzadatak != 1 && podzadatak != 2) {
        printf("Niste unijeli validan podzadatak.\n");
        return 1;
    }

    for (int i = 0; i < broj_test_primjera; i++) {
        char ime_ulaznog_fajla[50];
        char ime_izlaznog_fajla[50];
        sprintf(ime_ulaznog_fajla, "ulaz_%d_%d.txt", podzadatak, i);
        sprintf(ime_izlaznog_fajla, "izlaz_%d_%d.txt", podzadatak, i);

        FILE *ulaz = fopen(ime_ulaznog_fajla, "w");
        FILE *izlaz = fopen(ime_izlaznog_fajla, "w");

        int broj_brojeva = rand() % 10 + 1;
        if (podzadatak == 1) {
            generisi_test_glavna(ulaz, izlaz, 10, 100);
        } else {
            generisi_test_sporedna(ulaz, izlaz, 10, 100);
        }

        fclose(ulaz);
        fclose(izlaz);
    }

    printf("Test primjeri su uspjesno generisani!\n");

    return 0;
}
