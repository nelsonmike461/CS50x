import string
import math

# Get text
text = input("Text: ")

# Count spaces, letters, words, and sentences
spaces = text.count(" ")
letters = len([char for char in text if char.isalpha()])
sentence = text.count(".") + text.count("?") + text.count("!")
words = spaces + 1

# Calculate L, S, and index
L = (letters / words) * 100
S = (sentence / words) * 100
subindex = 0.0588 * L - 0.296 * S - 15.8
index = round(subindex)

# Print grade
if index > 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {index}")
