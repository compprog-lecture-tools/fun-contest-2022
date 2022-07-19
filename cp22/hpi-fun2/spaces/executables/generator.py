import random
from pathlib import Path
import string

random.seed(-5914732549275081787)


def write_testcase(name, desc, string):
    Path(name + '.in').write_text(string)
    Path(name + '.desc').write_text(desc + '\n')

max_words = 10**5
w = 250

write_testcase("sample1", "A simple testcase solvable with greedy", "3\naaa bb ccc\n6")
write_testcase("sample2", "A simple testcase not solvable with greedy", "4\naaa bb cc ddddd\n6")
write_testcase("sample3", "A medium testcase", "11\nthis is a medium testcase and should still be wrapped correctly\n15")
write_testcase("sample4", "edge case", "1\na\n1")
words = " ".join(("".join(random.choice(string.ascii_lowercase) for _ in range(random.randint(1,w)))) for _ in range(20))
write_testcase("random_small", "A small random testcase",f"{len(words.split())}\n{words}\n8")
words = " ".join(("".join(random.choice(string.ascii_lowercase) for _ in range(random.randint(1,w)))) for _ in range(max_words//2))
write_testcase("random_medium", "A medium random testcase",f"{len(words.split())}\n{words}\n{int(w/2)}")
for i in range(10):
    words = " ".join(("".join(random.choice(string.ascii_lowercase) for _ in range(random.randint(1,20)))) for _ in range(max_words))
    write_testcase(f"random_large_{i}", "A large random testcase",f"{len(words.split())}\n{words}\n{w}")