import random
from pathlib import Path

random.seed(-6653597241841577263)


def write_testcase(name, desc, numbers, newNumberOrdering):
    Path(name + '.in').write_text(str(len(numbers)) + '\n' + ' '.join(map(str, numbers)) + '\n' + str(newNumberOrdering))
    Path(name + '.desc').write_text(desc + '\n')


write_testcase('sample1', 'Sample 1 easy', [1, 3, 5, 8], '0123456789')
write_testcase('sample2', 'Sample 2 easy', [92, 53, 10], 9876543210)
write_testcase('sample3', 'Sample 3', [47, 40, 99], 2164783059)
write_testcase('sample4', 'Sample 4', [0, 40, 99], '0164783259')
write_testcase('wrong_order', 'wrong order', [1, 2], 1234567890)
write_testcase('same_values', 'numbers are the same', [1, 1], 1234567890)
write_testcase('different_lengths', 'values have different lengths', [1, 11111], 1234567890)
write_testcase('different_lengths2', 'values have different lengths', [51111, 123333, 15666666], 1234567890)


MAX_N = 2 * 10**5
MAX_VAL = 10**9

write_testcase('max_input', 'Max n, max vals', [MAX_VAL] * MAX_N, 9876543210)
write_testcase('min_input', 'Min n, min val', [0], 9876543210)

def random_order():
    numArray = [];
    while(len(numArray) < 10):
        randDigit = random.randrange(0, 9+1)
        if(randDigit not in numArray ):
            numArray.append(randDigit)
    return str(''.join(map(str, numArray)))

def random_value():
    return random.randrange(0, MAX_VAL)

for i in range(1, 5 + 1):
    numbersArray = [];
    for j in range(0, MAX_N):
        numbersArray.append(random_value())
    write_testcase(f"random{i}", f"Random {i}", numbersArray, random_order())


descending_order = []
numbersArray = [];

for i in range(0, MAX_N):
    numbersArray.append(random_value())

numbersArray.sort()
write_testcase('worst_runtime_but_positive', 'ascending til the end', numbersArray, '0123456789')
numbersArray[-1] = 0
write_testcase('worst_runtime_but_negative', 'ascending til the end', numbersArray, '0123456789')
