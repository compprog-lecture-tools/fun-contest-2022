def find_sol(s, k):
    if k*(k+1)//2 > s:
        return None
    return list(range(1, k)) + [s-(k-1)*k//2]
        

def solve():
    n, k = map(int, input().split())
    
    best_sol = None
    i = 1
    while i*i<=n:
        if n%i == 0:
            sol = find_sol(i, k)
            if sol is not None:
                print(*[x*(n//i) for x in sol])
                return
            sol = find_sol(n//i, k)
            if sol is not None:
                best_sol = [x*i for x in sol]
                
        i += 1
    if best_sol is not None:
        print(*best_sol)
    else:
        print(-1)
t = int(input())

for _ in range(t):
    solve()
                
