import random
from pathlib import Path

random.seed(-6653597241841577263)


def write_testcase(name, desc, numbers, newNumberOrdering):
    Path(name + '.in').write_text(
        str(len(numbers)) + '\n' + ' '.join(map(str, numbers)) + '\n' + str(newNumberOrdering))
    Path(name + '.desc').write_text(desc + '\n')


write_testcase('sample1', 'Sample 1 easy', [1, 3, 3, 8], '0123456789')
write_testcase('sample1b', 'Sample 2 easy', [8, 6, 6, 1], 9876543210)
write_testcase('sample2', 'Sample 2 easy', [82, 53, 10], 9876543210)
write_testcase('sample3', 'Sample 3', [47, 40, 99], 2164783059)
write_testcase('sample4', 'Sample 4', [0, 40, 99], '0164783259')
write_testcase('sample_wrong_order', 'wrong order', [7, 1], 2164783059)
write_testcase('wrong_order_0', 'wrong order including 0', [7, 2], 2164783059)
write_testcase('sample_same_values', 'numbers are the same', [6, 6], 2164783059)
write_testcase('different_lengths', 'values have different lengths', [0, 0000], 1234567890)
write_testcase('different_lengths2', 'values have different lengths', [515111, 23333, 85666666], 1234567890)

MAX_N = 2 * 10 ** 5
MAX_VAL_LEN = 9

write_testcase('max_input', 'Max n, max vals', [10 ** MAX_VAL_LEN - 1] * MAX_N, '0123456789')
write_testcase('min_input', 'Min n, min val', [0], '0123456789')


def random_order():
    numArray = []
    while (len(numArray) < 10):
        randDigit = random.randrange(0, 9 + 1)
        if (randDigit not in numArray):
            numArray.append(randDigit)
    return str(''.join(map(str, numArray)))


def random_value():
    return random.randrange(10 ** MAX_VAL_LEN)


def mapped_values(vals, ordering):
    result = []
    for val in vals:
        new_val = []
        for c in str(val):
            new_val.append(ordering[int(c)])
        result.append("".join(new_val))
    return result


for i in range(1, 5 + 1):
    numbersArray = []
    random_order_list = random_order()
    n = random.randrange(1, MAX_N + 1)
    for _ in range(n):
        numbersArray.append(random_value())
    numbersArray = mapped_values(numbersArray, random_order_list)
    write_testcase(f"random{i}", f"Random {i}", numbersArray, random_order_list)

numbersArray = []

for i in range(MAX_N):
    numbersArray.append(random_value())

numbersArray.sort()
write_testcase('worst_runtime_but_positive', 'ascending til the end', numbersArray, '0123456789')
numbersArray[-1] = 1
write_testcase('worst_runtime_but_negative', 'ascending til the end', numbersArray, '0123456789')

for i in range(1, 5 + 1):
    ordering = random_order()

    numbersArray = []
    for _ in range(MAX_N):
        numbersArray.append(random_value())
    numbersArray.sort()

    write_testcase(f"worst_runtime_random_positive{i}", 'ascending til the end with random order',
                   mapped_values(numbersArray, ordering), ordering)
    numbersArray[-1] = 0
    write_testcase(f"worst_runtime_random_negative{i}", 'ascending til the end with random order but last is smallest',
                   mapped_values(numbersArray, ordering), ordering)

