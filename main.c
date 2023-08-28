#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to evaluate polynomial
int polynomial(int hidings[], int length) {
    int coefficients[] = {7, 0, 1}; // Example coefficients
    int result = 0;
    for (int i = 0; i < length; ++i) {
        result += hidings[i] * coefficients[i];
    }
    return result;
}

int main() {
    srand(time(NULL));

    int p = 23;
    int g = 5; // Assuming 5 is a generator of G_p
    int d = 3; // Degree of the polynomial
    int alpha = rand() % (p - 1) + 1;
    int s = rand() % (p - 1) + 1;

    int hidings_g[d+1];
    int hidings_alpha_g[d+1];

    // Compute the hidings for Bob
    for (int i = 0; i <= d; ++i) {
        hidings_g[i] = (int)pow(s, i) * g % p;
        hidings_alpha_g[i] = (int)pow(s, i) * alpha * g % p;
    }

    // Alice's computation using elements sent by Bob
    int a = polynomial(hidings_g, d+1) % p;
    int b = polynomial(hidings_alpha_g, d+1) % p;

    // Bob checks if b = alpha * a
    if (b == (alpha * a % p)) {
        printf("Bob accepts\n");
    } else {
        printf("Bob does not accept\n");
    }

    return 0;
}
