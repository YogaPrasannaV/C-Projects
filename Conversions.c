#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

// Function prototypes
void decimalToBinary(int);
void binaryToDecimal(char[]);
void decimalToOctal(int);
void octalToDecimal(char[]);
void hexToBinary(char[]);
void binaryToHex(char[]);

// Main menu
int main() {
    int choice;
    char input[100];
    int num;

    while (1) {
        printf("\n===YOGA's Number System Converter ===\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Decimal to Octal\n");
        printf("4. Octal to Decimal\n");
        printf("5. Hexadecimal to Binary\n");
        printf("6. Binary to Hexadecimal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter Decimal Number: ");
            scanf("%d", &num);
            decimalToBinary(num);
            break;
        case 2:
            printf("Enter Binary Number: ");
            scanf("%s", input);
            binaryToDecimal(input);
            break;
        case 3:
            printf("Enter Decimal Number: ");
            scanf("%d", &num);
            decimalToOctal(num);
            break;
        case 4:
            printf("Enter Octal Number: ");
            scanf("%s", input);
            octalToDecimal(input);
            break;
        case 5:
            printf("Enter Hexadecimal Number: ");
            scanf("%s", input);
            hexToBinary(input);
            break;
        case 6:
            printf("Enter Binary Number: ");
            scanf("%s", input);
            binaryToHex(input);
            break;
        case 7:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}

// Decimal to Binary
void decimalToBinary(int n) {
    int binary[32], i = 0;
    if (n == 0) {
        printf("Binary: 0\n");
        return;
    }
    while (n > 0) {
        binary[i++] = n % 2;
        n /= 2;
    }
    printf("Binary: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binary[j]);
    printf("\n");
}

// Binary to Decimal
void binaryToDecimal(char bin[]) {
    int len = strlen(bin), decimal = 0;
    for (int i = 0; i < len; i++) {
        if (bin[i] == '1')
            decimal += pow(2, len - i - 1);
        else if (bin[i] != '0') {
            printf("Invalid Binary Input!\n");
            return;
        }
    }
    printf("Decimal: %d\n", decimal);
}

// Decimal to Octal
void decimalToOctal(int n) {
    int octal[32], i = 0;
    if (n == 0) {
        printf("Octal: 0\n");
        return;
    }
    while (n > 0) {
        octal[i++] = n % 8;
        n /= 8;
    }
    printf("Octal: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", octal[j]);
    printf("\n");
}

// Octal to Decimal
void octalToDecimal(char oct[]) {
    int len = strlen(oct), decimal = 0;
    for (int i = 0; i < len; i++) {
        if (oct[i] >= '0' && oct[i] <= '7')
            decimal += (oct[i] - '0') * pow(8, len - i - 1);
        else {
            printf("Invalid Octal Input!\n");
            return;
        }
    }
    printf("Decimal: %d\n", decimal);
}

// Hexadecimal to Binary
void hexToBinary(char hex[]) {
    printf("Binary: ");
    for (int i = 0; hex[i] != '\0'; i++) {
        switch (toupper(hex[i])) {
            case '0': printf("0000"); break;
            case '1': printf("0001"); break;
            case '2': printf("0010"); break;
            case '3': printf("0011"); break;
            case '4': printf("0100"); break;
            case '5': printf("0101"); break;
            case '6': printf("0110"); break;
            case '7': printf("0111"); break;
            case '8': printf("1000"); break;
            case '9': printf("1001"); break;
            case 'A': printf("1010"); break;
            case 'B': printf("1011"); break;
            case 'C': printf("1100"); break;
            case 'D': printf("1101"); break;
            case 'E': printf("1110"); break;
            case 'F': printf("1111"); break;
            default: printf("\nInvalid Hexadecimal Digit!\n"); return;
        }
    }
    printf("\n");
}

// Binary to Hexadecimal
void binaryToHex(char bin[]) {
    int len = strlen(bin);
    int padding = 4 - len % 4;
    if (padding != 4) {
        for (int i = len; i >= 0; i--)
            bin[i + padding] = bin[i];
        for (int i = 0; i < padding; i++)
            bin[i] = '0';
        len += padding;
    }
    bin[len] = '\0';

    printf("Hexadecimal: ");
    for (int i = 0; i < len; i += 4) {
        int val = 0;
        for (int j = 0; j < 4; j++)
            val = val * 2 + (bin[i + j] - '0');
        if (val < 10)
            printf("%d", val);
        else
            printf("%c", 'A' + val - 10);
    }
    printf("\n");
}

