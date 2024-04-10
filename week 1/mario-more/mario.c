#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompting the user for height
    int height;
    do
    {
        height = get_int("height of the pyramid: ");
    }
    while (height < 1 || height > 8);

    // print pyramid
    for (int rows = 0; rows < height; rows++)
    {
        // print spaces
        for (int spaces = 0; spaces < height - rows - 1; spaces++)
        {
            printf(" ");
        }

        // print blocks
        for (int columns = 0; columns <= rows; columns++)
        {
            printf("#");
        }

        // prints spaces
        printf("  ");

        // prints blocks
        for (int columns = 0; columns <= rows; columns++)
        {
            printf("#");
        }

        // moves to new line
        printf("\n");
    }
}
