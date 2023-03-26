#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int i, n,catalyst, degree, error;
    int num_binary, num_decimal;
    char check[28];
    printf("Quantity: \n");
    scanf("%d", &n);
    int bin[n], dec[n];
    printf("Binary numbers: (one by one)\n");
    for(i = 0; i < n; i++){
        error = 0;
        scanf("%s", &check);
        for(int j = 0; j < strlen(check) ; j++){
            catalyst = check[j];
            if(catalyst < 48 || catalyst > 49){
                error = 1;
            }

        }
        if(error != 1) {
            num_binary = atoi(check);
            bin[i] = num_binary;
            num_decimal = 0;
            degree = 0;
            while (num_binary > 0) { /* in this loop we are turning binary numbers into decimal numbers */
                num_decimal += pow(2, degree) * (num_binary % 2);
                degree += 1;
                num_binary /= 10;
            }
            dec[i] = num_decimal;
        }
        else {
            printf("Try again.\n");
            i -= 1;
        }
    }

    printf("Binary: \n");
    for(i = 0; i < n; i++) {
        printf("%d ", bin[i]);
    }
    printf("\nDecimal: \n");
    for(i = 0; i < n; i++) {
        printf("%d ", dec[i]);
    }
    return 0;
}