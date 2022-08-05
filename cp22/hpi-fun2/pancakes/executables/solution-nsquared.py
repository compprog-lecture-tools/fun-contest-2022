n = int(input())

vals = list(map(lambda orientation : 0 if orientation == 'u' else 1, input()))

turn_counter = 0
turn_counter2 = 0
for i in range(len(vals) - 1):
    for j in range(len(vals) - 1):
        if vals[i] != vals[i + 1]:
            turn_counter2 += 1
    if vals[i] != vals[i + 1]:
            turn_counter += 1
if vals[-1] == 1:
    # edge cases where last is turned down an therefore all pancakes need to be turned at the end.
    turn_counter += 1
print(turn_counter,  flush=False)
for i in range(len(vals) - 1):
    if vals[i] != vals[i + 1]:
        print(str(i + 1),end=' ', flush=False)
if vals[-1] == 1:
    # edge cases where last is turned down an therefore all pancakes need to be turned at the end.
     print(len(vals),end=' ', flush=False)
