n = int(input())
vals = input().split()
digits = input()

vals = [int("".join(str(digits.index(c)) for c in val)) for val in vals]

print("YES" if sorted(vals) == vals else "NO")