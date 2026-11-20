
#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

void simplify_fraction(int *numerator, int *denominator)
{
    int divisor;

    if (*denominator == 0)
    {
        printf("Invalid denominator!\n");
        return;
    }

    divisor = gcd(*numerator, *denominator);

    *numerator = *numerator / divisor;
    *denominator = *denominator / divisor;

    if (*denominator < 0)
    {
        *numerator = -*numerator;
        *denominator = -*denominator;
    }
}

int main()
{
    int numerator, denominator;

    printf("Enter numerator: ");
    scanf("%d", &numerator);

    printf("Enter denominator: ");
    scanf("%d", &denominator);

    simplify_fraction(&numerator, &denominator);

    if (denominator != 0)
    {
        printf("Simplified Fraction: %d/%d\n",
               numerator, denominator);
    }

    return 0;
}
