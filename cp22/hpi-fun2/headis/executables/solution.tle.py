# Should exceed time limit if someone is trying a prime-factorization

prod = int(input())
def prime_factorization(n):
  p = 2
  factors = []
  while p*p < n:
    while n % p == 0:
      factors.append(p)
      n = n/p
    p += 1
  return factors.append(p)
prime_factorization(prod)
print(str(input()[-1]))
