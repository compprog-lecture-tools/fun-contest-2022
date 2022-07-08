input = input().split()
n = input[0] 
k = input[1]

vals = list(map(lambda orientation : 0 if orientation == 'up' else 1, input().split()))

print(len(vals), flush=False)

for i in range(len(vals) - 1):
    if vals[i] != vals[i + 1]:
        print(str(i + 1),end=' ', flush=False)
