/*
    Password Generator
    ~~~~~~~~~~~~~~~~~~
    author: rxxbyy
    date: april 23, 2022
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/* defining ascii ranges for every type of char */
    /* ascii limits for lowercase */
#define MIN_ASCII_LOWERCASE 97
#define MAX_ASCII_LOWERCASE 122
    
    /* ascii limits for uppercase */
#define MIN_ASCII_UPPERCASE 65
#define MAX_ASCII_UPPERCASE 90
    
    /* ascii limits for special */
#define MIN_ASCII_SPECIAL 33
#define MAX_ASCII_SPECIAL 47
    
    /* ascii limits for numbers */
#define MIN_ASCII_NUMS 48
#define MAX_ASCII_NUMS 57

/* prototypes */
int generateRandomNum(const int min, const int max);
char generateChar(bool inUpper, bool inSpecial, bool inNum);

int main(void)
{
    srand(time(NULL)); /* seed for pseudorandom values */

    int includeUppercase = 0;
    int includeSpecial = 0;
    int includeNum = 0;

    int passLen;
    int i;

    puts("P A S S W O R D  G E N E R A T O R");
    char *menu[3] = {"Include uppercase", "Include special", "Include numbers"};

    for (i = 0; i < 3; i++) printf("[1, 0]: %4s\n", menu[i]);

    printf("Include: ");
    scanf("%d%d%d", &includeUppercase, &includeSpecial, &includeNum);

    printf("Enter the length for your password: ");
    scanf("%d", &passLen);

    char password[passLen];

    for (i = 0; i < passLen; i++) {
        password[i] = generateChar(includeUppercase, includeSpecial, includeNum);
    }

    password[i] = '\0';

    printf("\nYour password:\n%4s\n", password);

    return 0;
}

/* Generates a random char using ascii values */
int generateRandomNum(const int min, const int max)
{
    return (rand() % (max - min + 1) + min);
}

char generateChar(bool inUpper, bool inSpecial, bool inNum)
{
    char selection;
    int selectOrder = inUpper + inSpecial + inNum;
    int i = 0;

    char selections[selectOrder];

    selections[i] = 'l';
    i++;

    if (inUpper) {
        selections[i] = 'u';
        i++;
    }

    if (inSpecial) {
        selections[i] = 's';
        i++;
    }

    if (inNum) {
        selections[i] = 'n';
        i++;
    }

    selections[i] = '\0';

    selection = selections[generateRandomNum(0, selectOrder)];

    switch (selection) {
        case 'l':
            return generateRandomNum(MIN_ASCII_LOWERCASE, MAX_ASCII_LOWERCASE);
            break;
        
        case 'u':
            return generateRandomNum(MIN_ASCII_UPPERCASE, MAX_ASCII_UPPERCASE);
            break;
        
        case 's':
            return generateRandomNum(MIN_ASCII_SPECIAL, MAX_ASCII_SPECIAL);
            break;
        
        case 'n':
            return generateRandomNum(MIN_ASCII_NUMS, MAX_ASCII_NUMS);
            break;
    }
}
