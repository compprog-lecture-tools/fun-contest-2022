import random
from pathlib import Path
import math

random.seed(5221489538229539538)


def write_testcase(name: str, desc: str, valuesVertices: list[int], edges: list[tuple[int, int]]):
    text = str(len(valuesVertices)) + '\n' + ' '.join(map(str, valuesVertices)) + '\n'
    text += str(len(edges)) + '\n'
    for i in range(len(edges)):
        text += str(edges[i][0]) + ' ' + str(edges[i][1]) + '\n'

    Path(name + '.in').write_text(text)
    Path(name + '.desc').write_text(desc + '\n')


write_testcase('sample1', 'Easy first sample', [10, 12, 3, 9], [(1, 2), (1, 4), (2, 3), (4, 3)])
write_testcase('sample2', 'Easy second example, two starting points', [7, 9, 2], [(1, 3), (2, 3)])

MAX_N = 10 ** 4
MAX_Value = 100

write_testcase('biggest', 'One long line with highest values',
               [MAX_Value for i in range(MAX_N)], [(i, i + 1) for i in range(1, MAX_N)])
write_testcase('biggest2', 'Max value vertices with highest value each connected to last',
               [MAX_Value for i in range(MAX_N)], [(i, MAX_N) for i in range(1, MAX_N)])
write_testcase('one_big', 'Big test case where all vertices have value 1 except for one',
               [1 for i in range(MAX_N - 1)] + [MAX_Value], [(i, MAX_N) for i in range(1, MAX_N)])
write_testcase('small', 'Smallest test case', [1, 1], [(1, 2)])


def random_arr(n: int):
    vals = random.choices(range(1, MAX_Value + 1), k=n)
    return vals


def generate_random_two_split_testcase(number: int):
    first_half = random.randrange(1, number)
    edges = [(1, i) for i in range(2, number)]
    edges += [(i, first_half) for i in range(2, first_half)]
    edges += [(i, number - 1) for i in range(first_half + 1, number)]
    edges.append((number - 1, number))
    edges.append((first_half, number))
    return edges


def generate_random_testcase(number: int):
    split = math.ceil(number / 3 * 2) + 1
    edges = [(i - 1, i) for i in range(2, split)]
    j = 1
    for i in range(split, number + 1):
        edges += [(j, i)]
        edges += [(i, j + 2)]
        j += 2
    return edges


for i in range(1, 3):
    n = random.randrange(1, MAX_N + 1)
    vertices_values = random_arr(n)
    edges = generate_random_two_split_testcase(n)
    write_testcase(f'random_two_split{i}', 'Random test case which splits into two parts',
                   valuesVertices=vertices_values, edges=edges)

for i in range(1, 5):
    n = random.randrange(4, MAX_N + 1)
    vertices_values_two = random_arr(n)
    edges_two = generate_random_testcase(n)
    write_testcase(f'random_skip_one{i}', 'Random test case which for one third of vertices skips one to parallelize',
                   valuesVertices=vertices_values_two, edges=edges_two)
