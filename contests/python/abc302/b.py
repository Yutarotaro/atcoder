H, W = map(int, input().split())

s = [input() for i in range(H)]

print(s[0])

ans = ['s', 'n', 'u', 'k', 'e']

dx = [1, 1, 0, -1, -1, -1, 0, 1]
dy = [0, 1, 1, 1, 0, -1, -1, -1]


for i in range(H):
    for j in range(W):
        for x, y in zip(dx, dy):
            tmp_ = []
            for k in range(5):
                if i + x * (k + 1) < 0 or i + x * (k + 1)  >= H or j + y * (k + 1)  < 0 or j + y * (k + 1)  >= W:
                    break
                tmp_.append(s[i+x * (k + 1) ][j+y * (k + 1) ])
            if tmp_ == ans:
                for k in range(5):
                    print(i+x * (k + 1) + 1, j+y * (k + 1) + 1 )

                

        
"""

#縦
for i in range(H - 5 + 1):
    for j in range(W):
        tmp_ = []
        for k in range(5):
            tmp_.append(s[i + k][j])

        if tmp_ == ans:
            for l in range(5):
                print(i + k + 1, j + 1)
                
        tmp_ = []
        for k in range(5):
            tmp_.append(s[i - k + 4][j])

        if tmp_ == ans:
            for l in range(5):
                print(i - k + 5, j + 1)



#横
for i in range(W - 5 + 1):
    for j in range(H):
        tmp_ = []
        for k in range(5):
            tmp_.append(s[i + k][j])

        if tmp_ == ans:
            for l in range(5):
                print(i + k + 1, j + 1)
                
        tmp_ = []
        for k in range(5):
            tmp_.append(s[i - k + 4][j])

        if tmp_ == ans:
            for l in range(5):
                print(i + k + 1, j + 1)



"""
