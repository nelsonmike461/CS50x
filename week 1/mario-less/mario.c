#include <cs50.h>
#include <stdio.h>

// prompting the user for height
int main(void)
{
    // prompt user
    int h;
    do
    {
        h = get_int("height of the pyramid: ");
    }
    while (h < 1 || h > 8);

    // print pyramid
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < h - i - 1; j++)
        {
            printf(" ");
        }

        // print blocks
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        // move to next line
        printf("\n");
    }

    return 0;
}
