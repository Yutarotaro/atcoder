N, M, D = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

a.sort()
b.sort()

l = 0
r = D + 1

while r - l > 1:
    mid = (l + r) // 2

    
