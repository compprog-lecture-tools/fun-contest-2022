from math import ceil
import random
from pathlib import Path

random.seed(9167932976977720948)

def write_testcase(name, desc, values, allowed_turns):
    Path(name + '.in').write_text(str(len(values)) + ' ' + str(allowed_turns) + '\n' + ' '.join(values) + '\n')
    Path(name + '.desc').write_text(desc + '\n')

write_testcase('sample1', 'Sample 1 easy', ['down','up','up','up','up','up','up'], 3)
write_testcase('sample2', 'Sample 2 easy', ['up','up','up','up','up','up','down'], 3)
write_testcase('sample3', 'Sample 3 easy', ['up','down','up','down','up','down','down'], 6)

# some edge cases
write_testcase('edge_case1', 'one turn', ['down'], 1)
write_testcase('edge_case1', 'no turn', ['up'], 0)


MAX_N = 10**6
def generate_random_sample(length, id):
    a = ['up' if random.randint(1,2) > 1 else 'down' for i in range(length)]
    number_of_changes = 0
    for i in range(length - 1):
        if a[i] != a[i+1]:
            number_of_changes += 1
    # Adding a puffer for how much turns one can make.
    number_of_changes = ceil(1.2 * number_of_changes)
    write_testcase('long_random' + id, 'testing long random sequence', a, number_of_changes)
generate_random_sample(MAX_N, '1')
for i in range(2, 5 + 2):
    generate_random_sample(random.randint(1, MAX_N), str(i))
write_testcase('long_up_only', 'testing long down only sequence', ['up'] * MAX_N, 0)
write_testcase('long_down_only', 'testing long up only sequence', ['down'] * MAX_N, 2)


