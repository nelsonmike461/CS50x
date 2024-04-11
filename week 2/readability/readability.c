#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int spaces = 0;
    int letters = 0;
    int words = 0;
    int sentence = 0;

    string text = get_string("Text: ");

    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (isspace(text[i]))
        {
            spaces++;
        }
        else if (isalpha(text[i]))
        {
            letters++;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentence++;
        }
    }
    words = spaces + 1;

    float L = ((float) letters / (float) words) * 100;
    float S = ((float) sentence / (float) words) * 100;
    float subindex = 0.0588 * L - 0.296 * S - 15.8;
    int index = round(subindex);

    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
