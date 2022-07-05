import random
from pathlib import Path

random.seed(-6653597241841577263)


def write_testcase(name, desc, values):
    Path(name + '.in').write_text(str(len(values)) + '\n' + ' '.join(map(str, values)) + '\n')
    Path(name + '.desc').write_text(desc + '\n')


write_testcase('sample1', 'Sample 1 easy', [1, 2, 3])
write_testcase('sample2', 'Sample 2 easy', [10, 4, 5])

MAX_N = 2 * 10**5
MAX_VAL = 10**9

write_testcase('max_input', 'Max n, max vals', [MAX_VAL] * MAX_N)
write_testcase('min_input', 'Min n, min val', [1])


def random_arr():
    n = random.randrange(1, MAX_N + 1)
    vals = random.choices(range(1, MAX_VAL + 1), k=n)
    return vals


for i in range(1, 5 + 1):
    write_testcase(f"random{i}", f"Random {i}", random_arr())
