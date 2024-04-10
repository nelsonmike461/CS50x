while True:
    try:
        height = int(input("Height of the pyramid: "))
        if 1 <= height <= 8:
            break
    except ValueError:
        print("Invalid input. Please enter a number between 1 and 8.")

for rows in range(height):
    # print spaces
    for spaces in range(height - rows - 1):
        print(" ", end="")

    # print blocks
    for columns in range(rows + 1):
        print("#", end="")

    # prints spaces
    print("  ", end="")

    # prints blocks
    for columns in range(rows + 1):
        print("#", end="")

    # moves to a new line
    print()
