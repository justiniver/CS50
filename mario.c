#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int height, r, c, s;
    do
    {
    height = get_int ("Enter height here: ");
    }
    while (height < 1 || height > 8);

    for (r = 0; r < height; r++)
    {
        for (s = 0; s < height - r - 1; s++)
        {
            printf(" ");
        }
        for (c = 0; c <= r ; c++)
        {
            printf("#");
        }
        printf("\n");
    }
}
