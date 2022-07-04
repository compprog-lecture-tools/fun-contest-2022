t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    mx = 0
    stair = (k**2 + k) // 2
    for i in range(1, n + 1):
        if i**2 > n:
            break
        if n % i:
            continue
        for d in (i, n // i):
            if stair * d <= n:
                mx = max(mx, d)
    if not mx:
        print(-1)
        continue
    for i in range(k - 1):
        print((i + 1) * mx, end=' ')
    print(n - (stair - k) * mx)
