#include <cs50.h>
#include <stdio.h>

long card_length(long l);

int main(void)
{
    //Initialising values.

    long N, x, z;
    long a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;
    int digit = 0;

    //Asking the user for number.
    do
    {
        N = get_long("Number: ");
    }
    while (N < 1);

    x = N;
    while (x >= 100)
    {
        x = x / 10;
    }

    z = N;
    while (z >= 10)
    {
        z = z / 10;
    }

    int length = card_length(N); //Getting the length of card.


    // Calculation on the Basis of Luhn Algoritm.
    a = ((N % 10000000000000000) / 1000000000000000) * 2;
    b = ((N % 100000000000000) / 10000000000000) * 2;
    c = ((N % 1000000000000) / 100000000000) * 2;
    d = ((N % 10000000000) / 1000000000) * 2;
    e = ((N % 100000000) / 10000000) * 2;
    f = ((N % 1000000) / 100000) * 2;
    g = ((N % 10000) / 1000) * 2;
    h = ((N % 100) / 10) * 2;

    int sum1 = ((a / 10) + a % 10) + ((b / 10) + b % 10) + ((c / 10) + c % 10) + ((d / 10) + d % 10) + ((e / 10) + e % 10) +
               ((f / 10) + f % 10) + ((g / 10) + g % 10) + ((h / 10) + h % 10);

    i = ((N % 1000000000000000) / 100000000000000);
    j = ((N % 10000000000000) / 1000000000000);
    k = ((N % 100000000000) / 10000000000);
    l = ((N % 1000000000) / 100000000);
    m = ((N % 10000000) / 1000000);
    n = ((N % 100000) / 10000);
    o = ((N % 1000) / 100);
    p = (N % 10);

    int sum2 = i + j + k + l + m + n + o + p;
    int check_sum = sum1 + sum2; //Sum of digits (luhn's algorithm).

    if (check_sum % 10 == 0)
    {
        //Checking the parameters of cards and printing the value.
        if ((x == 34 || x == 37) && length == 15)
        {
            printf("AMEX\n"); //for American Master Card.
        }
        else if ((x == 51 || x == 52 || x == 53 || x == 54 || x == 55) && length == 16)
        {
            printf("MASTERCARD\n"); //for MasterCard.
        }
        else if (z == 4 && (length == 13 || length == 16))
        {
            printf("VISA\n"); //for VISA
        }
        else
        {
            printf("INVALID\n"); // If the parameter doesn't satisfy according to question than printing INVALID.
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

long card_length(long l)
{
    int digit = 0;
    while (l > 0)
    {
        l = l / 10;
        digit++;
    }
    return digit;
}
