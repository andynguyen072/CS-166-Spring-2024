#include <stdio.h>

unsigned char S[255];
unsigned char K[255];
unsigned char key[7] = {0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F, 0x77};
int i, j, t = 0;

void swap(unsigned char *i, unsigned char *j){
    unsigned char temp = *i;
    *i = *j;
    *j = temp;
}

void RC4Initiation(){
    for (i = 0; i < 256; i++) {
        S[i] = i;
        K[i] = key[i % (sizeof(key) / sizeof(key[0]))]; // mods the size of key array
    }

    for (i = 0; i < 256; i++) {
        j = (j + S[i] + K[i]) % 256;
        swap(&S[i], &S[j]);
    }

    i = j = 0;
}

unsigned char RC4KeystreamByte(){
    i = (i + 1) % 256;
    j = (j + S[i]) % 256;
    swap(&S[i], &S[j]);
    t = (S[i] + S[j]) % 256;
    return S[t];
}

int main(){
    RC4Initiation();

    // PART A

    // Print permutation after intialization
    printf("Permutation array S:\n");
    for (int a = 0; a < 16; a++) {
        for (int b = 0; b < 16; b++) {
            printf("%02X ", S[a * 16 + b]);
        }
        printf("\n");
    }

    // Print indices i and j after initialization
    printf("\ni = %d, j = %d\n", i, j);

    // PART B

    // Call method Keystream 100 times
    for (int a = 0; a < 100; a++) {
        //printf("%02X ", RC4KeystreamByte());
        RC4KeystreamByte();
    }

    printf("\n\n");

    // Print permutation after calling method Keystream 100 times
    printf("Permutation array S After Keystream 100:\n");
    for (int a = 0; a < 16; a++) {
        for (int b = 0; b < 16; b++) {
            printf("%02X ", S[a * 16 + b]);
        }
        printf("\n");
    }

    // Print indices i and j after creating keystream
    printf("\ni = %d, j = %d\n", i, j);

    // PART C

    // Call method Keystream 900 more times for a total of 1000 times
    for (int a = 0; a < 900; a++) {
        //printf("%02X ", RC4KeystreamByte());
        RC4KeystreamByte();
    }

    printf("\n\n");

    // Print permutation after calling method Keystream 900 times
    printf("Permutation array S After Keystream 1000:\n");
    for (int a = 0; a < 16; a++) {
        for (int b = 0; b < 16; b++) {
            printf("%02X ", S[a * 16 + b]);
        }
        printf("\n");
    }

    // Print indices i and j after creating keystream
    printf("\ni = %d, j = %d\n", i, j);

    return 0;
}