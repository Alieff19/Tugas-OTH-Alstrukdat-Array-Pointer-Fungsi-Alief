#include <stdio.h>
#include <string.h>
// M ALIEF ALFARIDZI

// Fungsi untuk menukar posisi dua kartu
void tukar(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Fungsi untuk mengurutkan kartu
int sortCards(int n, char cards[]) {
    int i, j, minIndex, exchange = 0;

    // Menggunakan selection sort untuk mengurutkan kartu
    for (i = 0; i < n-1; i++) {
        minIndex = i;
        for (j = i+1; j < n; j++) {
            if (cards[j] < cards[minIndex])
                minIndex = j;
        }
        if (minIndex != i) {
            tukar(&cards[i], &cards[minIndex]);
            exchange++;
        }
    }

    return exchange;
}

int main() {
    int n;
    char cards[100];

    // Membaca jumlah kartu
    scanf("%d", &n);

    // Membaca nilai kartu
    for (int i = 0; i < n; i++) {
        scanf(" %c", &cards[i]);
    }

    // Mengurutkan kartu dan mendapatkan jumlah minimal langkah pertukaran
    int minTukar = sortCards(n, cards);

    // Menampilkan jumlah minimal langkah pertukaran
    printf("%d\n", minTukar);

    return 0;
}