#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get card number
    long Num = get_long("Card Number: ");

    // Count length
    int i = 0;
    long card_no = Num;
    while (card_no > 0)
    {
        card_no = card_no / 10;
        i++;
    }

    // Check if length is valid
    if (i != 13 && i != 15 && i != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // Calculate checksum
    int sum1 = 0;
    int sum2 = 0;
    long x = Num;
    while (x > 0)
    {
        sum1 += x % 10;
        x /= 10;

        int digit = 2 * (x % 10);
        sum2 += digit / 10 + digit % 10;
        x /= 10;
    }

    int total = sum1 + sum2;

    // Check if checksum is valid
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Determine card type
    if ((Num >= 340000000000000 && Num < 350000000000000) || (Num >= 370000000000000 && Num < 380000000000000))
    {
        printf("AMEX\n");
    }
    else if (Num >= 5100000000000000 && Num < 5600000000000000)
    {
        printf("MASTERCARD\n");
    }
    else if ((Num >= 4000000000000 && Num < 5000000000000) || (Num >= 4000000000000000 && Num < 5000000000000000))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
