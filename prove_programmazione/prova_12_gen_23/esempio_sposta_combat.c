#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char fighters[] = "*-*";
    int length = strlen(fighters);

    // Move fighters up by two positions if the next two positions are free
    for (int i = length - 1; i >= 0; i--) {
        if (i >= 2 && fighters[i - 1] == '-' && fighters[i - 2] == '-') {
            fighters[i] = fighters[i - 2];
            fighters[i - 2] = '*';
        }
    }

    // Move fighters to the highest available position if the next two positions are not free
    for (int i = length - 1; i >= 0; i--) {
        if (fighters[i] == '-') {
            int j = i - 1;
            while (j >= 0 && fighters[j] == '-') {
                j--;
            }
            if (j >= 0) {
                fighters[i] = fighters[j];
                fighters[j] = '-';
            }
        }
    }

    printf("%s\n", fighters);
    return 0;
}


//can you show me how to do the same thing but instad of two positions, f position? (f is a input by user).
// Path: prove_programmazione/prova_12_gen_23/example_1.c.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char fighters[] = "*-*";
    int length = strlen(fighters);
    int f = 0;
    printf("Insert f: ");
    scanf("%d", &f);

    // Move fighters up by f positions if the next f positions are free
    for (int i = length - 1; i >= 0; i--) {
        if (i >= f && fighters[i - 1] == '-' && fighters[i - 2] == '-') {
            fighters[i] = fighters[i - f];
            fighters[i - f] = '*';
        }
    }

    // Move fighters to the highest available position if the next f positions are not free
    for (int i = length - 1; i >= 0; i--) {
        if (fighters[i] == '-') {
            int j = i - 1;
            while (j >= 0 && fighters[j] == '-') {
                j--;
            }
            if (j >= 0) {
                fighters[i] = fighters[j];
                fighters[j] = '-';
            }
        }
    }

    printf("%s\n", fighters);
    return 0;
}

