
for i in [2,1,3,2]:
    print(f'? insert {i}')

answer = ''
for i in range(3):
    print(f'? remove')
    answer += input()

solutions = {
    "213": "queue",
    "231": "stack",
    "123": "set",
    "122": "pq",
}

print(f"! {solutions[answer]}")

