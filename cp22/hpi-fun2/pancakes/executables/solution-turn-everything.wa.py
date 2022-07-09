[n, k] = input().split()

vals = list(map(lambda orientation : 0 if orientation == 'up' else 1, input().split()))

print(len(vals), flush=False)

for i in range(len(vals) - 1):
    if vals[i] != vals[i + 1]:
        print(str(i + 1),end=' ', flush=False)
