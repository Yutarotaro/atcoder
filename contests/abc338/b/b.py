from collections import Counter

# Example input
s = input()

# Count the frequency of each character in the string
char_freq = Counter(s)

# Find the character(s) with the highest frequency
max_freq = max(char_freq.values())
most_common_chars = [char for char, freq in char_freq.items() if freq == max_freq]

# Sort the characters alphabetically and pick the first one
answer = sorted(most_common_chars)[0]

print(answer)