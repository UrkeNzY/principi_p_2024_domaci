#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long suma_kvadrata(int *brojevi, int N) {
    unsigned long long suma = 0;
    for (int i = 0; i < N; i++) {
        suma += (unsigned long long)brojevi[i] * brojevi[i];
    }
    return suma;
}

void generisi_test_sume_kvadrata(FILE *ulaz, FILE *izlaz, int N) {
    fprintf(ulaz, "%d\n", N);
    int brojevi[N];
    for (int i = 0; i < N; i++) {
        brojevi[i] = rand() % 100;
        fprintf(ulaz, "%d ", brojevi[i]);
    }

    unsigned long long rezultat = suma_kvadrata(brojevi, N);
    fprintf(izlaz, "%llu\n", rezultat);
}

void generisi_test_sume_kvadrata_float(FILE *ulaz, FILE *izlaz, int N) {
    fprintf(ulaz, "%d\n", N);
    float brojevi[N];
    for (int i = 0; i < N; i++) {
        brojevi[i] = (float)rand() / RAND_MAX * 100.0;
        fprintf(ulaz, "%.2f ", brojevi[i]);
    }

    float suma = 0;
    for (int i = 0; i < N; i++) {
        suma += brojevi[i] * brojevi[i];
    }
    fprintf(izlaz, "%.2f\n", suma);
}

int main() {
    srand(time(NULL));

    int broj_test_primjera;
    printf("Unesite broj test primjera: ");
    scanf("%d", &broj_test_primjera);

    int podzadatak;
    printf("Izaberite podzadatak: \n%s \n%s \n", "1) Suma cijelih brojeva", "2) Suma realnih brojeva");
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
            generisi_test_sume_kvadrata(ulaz, izlaz, broj_brojeva);
        } else {
            generisi_test_sume_kvadrata_float(ulaz, izlaz, broj_brojeva);
        }

        fclose(ulaz);
        fclose(izlaz);
    }

    printf("Test primjeri su uspjesno generisani!\n");

    return 0;
}
