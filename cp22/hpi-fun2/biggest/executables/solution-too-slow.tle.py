n = int(input())

vals = list(map(int, input().split()))

for val in vals:
    for val2 in vals:
        if val == val2:
            continue

print(max(vals))
