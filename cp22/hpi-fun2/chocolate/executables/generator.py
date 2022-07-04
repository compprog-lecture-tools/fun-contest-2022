from pathlib import Path
import random as r

TESTCASES = [
    ('sample1', '1 1', 'Sample 1x1'),
    ('sample2', '2 1', 'Sample 2x1'),
    ('sample3', '2 2', 'Sample 1x2'),
    ('25x25', '25 25', 'Hard testcase')
]

for name, in_data, description in TESTCASES:
    Path(name + '.in').write_text(in_data + '\n')
    Path(name + '.desc').write_text(description + '\n')

for i in range(1,21):
    Path('random' + str(i) + '.in').write_text(str(r.randint(100, 10000)) + ' ' + str(r.randint(100, 10000)) + '\n')
    Path('random' + str(i) + '.desc').write_text('random testcase ' + str(i) + '\n')

