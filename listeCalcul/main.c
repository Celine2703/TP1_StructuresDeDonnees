#include "listeCalcule.h"

int main()
{
    LargeNumber num1;
    LargeNumber num2;
    LargeNumber *sum;
    initializeLargeNumber(&num1, 96789543216);
    initializeLargeNumber(&num2, 55555555555);
    printf("num1: ");
    afficher(&num1);
    printf("num2: ");
    afficher(&num2);

    sum = sumNumber(&num1, &num2);
    afficher_inverse(sum);

    libererMemoire(&num1);
    libererMemoire(&num2);
    return 0;
}
