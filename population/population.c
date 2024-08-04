#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x, y;
    // TODO: Prompt for start size
    do
    {
        x = get_int("Start size: ");
    }
    while (x < 9);
    // TODO: Prompt for end size
    do
    {
        y = get_int("End size: ");
    }
    while (y < x);
    // TODO: Calculate number of years until we reach threshold
    int a = x;
    int b = 0;
    while (a < y)
    {
        a = a + (a / 3) - (a / 4);
        b++;
    }
    // TODO: Print number of years
    printf("Years: %i\n", b);
}
