# Get card number
Num = int(input("Card Number: "))

# Count length
i = 0
card_no = Num
while card_no > 0:
    card_no = card_no // 10
    i += 1

# Check if length is valid
if i != 13 and i != 15 and i != 16:
    print("INVALID")
else:
    # Calculate checksum
    sum1 = 0
    sum2 = 0
    x = Num
    while x > 0:
        sum1 += x % 10
        x //= 10

        digit = 2 * (x % 10)
        sum2 += digit // 10 + digit % 10
        x //= 10

    total = sum1 + sum2

    # Check if checksum is valid
    if total % 10 != 0:
        print("INVALID")
    else:
        # Determine card type
        if (Num >= 340000000000000 and Num < 350000000000000) or (
            Num >= 370000000000000 and Num < 380000000000000
        ):
            print("AMEX")
        elif Num >= 5100000000000000 and Num < 5600000000000000:
            print("MASTERCARD")
        elif (Num >= 4000000000000 and Num < 5000000000000) or (
            Num >= 4000000000000000 and Num < 5000000000000000
        ):
            print("VISA")
        else:
            print("INVALID")
