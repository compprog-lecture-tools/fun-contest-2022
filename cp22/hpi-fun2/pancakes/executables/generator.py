from math import ceil
import random
from pathlib import Path

random.seed(9167932976977720948)

def write_testcase(name, desc, pancakes, answer = None):
    Path(name + '.in').write_text(str(len(pancakes)) + '\n' + pancakes + '\n')
    Path(name + '.desc').write_text(desc + '\n')
    if answer:
        Path(name + '.desc').write_text(answer + '\n')

write_testcase('sample1', 'Sample 1 easy', 'duuu', '2 \n 3 4')
write_testcase('sample2', 'Sample 2 easy', 'uuuuuud', '3 \n 7 1 7')
write_testcase('sample3', 'Sample 3 easy', 'udududdu', '8 \n 1 2 7 2 4 1 4 7')
alternating1 = ''.join(['u' if i%2 else 'd' for i in range(200)])
write_testcase('alternating1', 'alternating up and down starting with up', alternating1)
alternating2 = ''.join(['d' if i%2 else 'u' for i in range(200)])
write_testcase('alternating2', 'alternating up and down starting with down', alternating2)

# some edge cases
write_testcase('edge_case1', 'one turn', 'd')
write_testcase('edge_case1', 'no turn', 'u')


MAX_N = 5000
def generate_random_sample(length, id):
    a = ''.join(['u' if random.randint(1,2) > 1 else 'd' for i in range(length)])
    # Adding a puffer for how much turns one can make.
    write_testcase('long_random' + id, 'testing long random sequence', a)
generate_random_sample(MAX_N, '1')
for i in range(2, 5 + 2):
    generate_random_sample(random.randint(1, MAX_N), str(i))
write_testcase('long_up_only', 'testing long down only sequence', ''.join('u' * MAX_N))
write_testcase('long_down_only', 'testing long up only sequence', ''.join('d' * MAX_N))


