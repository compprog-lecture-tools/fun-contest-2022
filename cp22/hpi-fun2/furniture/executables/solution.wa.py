n = int(input()) + 1

furniture = list(map(int, input().split()))

m = int(input())
g = [[0]]*n

count = [0] * n


for i in range(m):
    current = tuple(map(int, input().split()))
    print(current)
    g[current[0]].append(current[1])
    count[current[1]] += 1

print(sum(furniture))
