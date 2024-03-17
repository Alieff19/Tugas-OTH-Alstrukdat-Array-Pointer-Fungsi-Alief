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
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (cards[j] < cards[minIndex])
                minIndex = j;
        }
        if (minIndex != i) {
            tukar(&cards[i], &cards[minIndex]);
            exchange++;

            // Tampilkan kartu setelah setiap pertukaran
            printf("Pertukaran %d: ", exchange);
            for (int k = 0; k < n; k++) {
                if (cards[k] >= 1 && cards[k] <= 9) {
                    printf("%c ", cards[k] + '0');
                } else if (cards[k] == 10) {
                    printf("10 ");
                } else if (cards[k] == 11) {
                    printf("J ");
                } else if (cards[k] == 12) {
                    printf("Q ");
                } else if (cards[k] == 13) {
                    printf("K ");
                }
            }
            printf("\n");
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
        char c;
        scanf(" %c", &c);
        if (c == 'J') {
            cards[i] = 11;
        } else if (c == 'Q') {
            cards[i] = 12;
        } else if (c == 'K') {
            cards[i] = 13;
        } else if (c == '1') {
            // Periksa kasus khusus '10'
            char nextChar;
            scanf(" %c", &nextChar);
            if (nextChar == '0') {
                cards[i] = 10;
            } else {
                cards[i] = c - '0';
            }
        } else {
            cards[i] = c - '0';
        }
    }

    // Mengurutkan kartu dan mendapatkan jumlah minimal langkah pertukaran
    int minTukar = sortCards(n, cards);

    // Menampilkan jumlah minimal langkah pertukaran
    printf("Jumlah minimal langkah pertukaran: %d\n", minTukar);

    return 0;
}