n = int(input())

vals = list(map(lambda orientation : 0 if orientation == 'u' else 1, input()))

print(len(vals), flush=False)

for i in range(len(vals) - 1):
    if vals[i] != vals[i + 1]:
        print(str(i + 1),end=' ', flush=False)
