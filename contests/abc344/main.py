#!/usr/bin/env python3


# Generated by 2.13.0 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
def main():
    N = int(input())
    A = list(map(int, input().split()))
    concatenated_list = {}
    for i in range(len(A)):
        if i == 0:
            concatenated_list[A[i]] = [-1, A[i + 1]]
        elif i == len(A) - 1:
            concatenated_list[A[i]] = [A[i - 1], -1]
        else:
            concatenated_list[A[i]] = [A[i - 1], A[i + 1]]
    Q = int(input())
    for _ in range(Q):
        query = list(map(int, input().split()))
        q = query[0]
        if q == 1:
            x, y = query[1], query[2]
            prev_x, next_x = concatenated_list[x]
            concatenated_list[y] = [x, next_x]
            concatenated_list[x] = [prev_x, y]
        elif q == 2:
            x = query[1]
            prev_x, next_x = concatenated_list[x]
            if prev_x == -1:
                concatenated_list[next_x][0] = prev_x
            elif next_x == -1:
                concatenated_list[prev_x][1] = next_x
            else:
                concatenated_list[prev_x][1] = next_x
                concatenated_list[next_x][0] = prev_x

    start = -1
    for x, (prev, next) in concatenated_list.items():
        if prev == -1:
            start = x
            break
    while start != -1:
        print(start, end=" ")
        prev, next = concatenated_list[start]
        start = next


if __name__ == "__main__":
    main()
