# Input string
s = input()

# Initialize flag as True
flag = True

# Check if first character is uppercase
flag &= ('A' <= s[0] and s[0] <= 'Z')

# Check if the rest of the characters are lowercase
for i in range(1, len(s)):
    flag &= ('a' <= s[i] and s[i] <= 'z')

print('Yes' if flag else 'No')
