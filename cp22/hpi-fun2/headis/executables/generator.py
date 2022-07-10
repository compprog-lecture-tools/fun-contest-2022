import random
from pathlib import Path
from Crypto.Util import number
import numpy as np

random.seed(-5128704985903725171)


def write_testcase(name, desc, prime_product, bitstring):
    Path(name + '.in').write_text(str(prime_product) + '\n' + bitstring + '\n')
    Path(name + '.desc').write_text(desc + '\n')


def generate_set_1(winner, n_points):
    return winner * n_points

def generate_set_2(winner, n_points):
    if winner == "3":
        loser = "7"
    else:
        loser = "3"
    points = [winner] * (n_points-1) + [loser] * random.randint(0, n_points-1)
    np.random.shuffle(points)
    points += [winner]
    return "".join(points)

def generate_random_bitstring2(a, b):
    if random.choice([True, False]):
        set_winners = ["3"] * (b-1) + ["7"] * random.randint(0, b-1)
        winner = "3"
    else:
        set_winners = ["7"] * (b-1) + ["3"] * random.randint(0, b-1)
        winner = "7"
    np.random.shuffle(set_winners)
    set_winners += [winner]

    generator = random.choice([generate_set_1, generate_set_2])
    bitstring = [generator(winner, a) for winner in set_winners]
    return "".join(bitstring)

def random_testcase(n):
    p1 = number.getPrime(n)
    p2 = number.getPrime(n)
    a = min(p1 % 10**2, p2 % 10**2)
    b = max(p1 % 10**2, p2 % 10**2)


    return (p1*p2, generate_random_bitstring2(a, b))

write_testcase('sample1', 'Sample 1', 6, "373337373")
write_testcase('sample2', 'Sample 2', 10, generate_random_bitstring2(2, 5))
write_testcase('min', 'Sample 2', 4, "3333")

for i in range(1, 5+1):
    prod, bitstring = random_testcase(2)
    write_testcase('random_small'+str(i), 'random example with smaller prime-numbers', prod, bitstring)

for i in range(1, 5+1):
    prod, bitstring = random_testcase(31)
    write_testcase('random_large'+str(i), 'random example with larger prime-numbers', prod, bitstring)
