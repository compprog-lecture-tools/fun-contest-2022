import random
from pathlib import Path
import string

random.seed(-5914732549275081787)


def write_testcase(name, desc, string):
    Path(name + '.in').write_text(string)
    Path(name + '.desc').write_text(desc + '\n')

max_words = 50000

write_testcase("sample1", "A simple testcase solvable with greedy", "3\naaa bb ccc\n6")
write_testcase("sample2", "A simple testcase not solvable with greedy", "4\naaa bb cc ddddd\n6")
write_testcase("sample3", "A medium testcase", "11\nthis is a medium testcase and should still be wrapped correctly\n15")
write_testcase("sample4", "edge case", "1\na\n1")
words = " ".join(("".join(random.choice(string.ascii_lowercase) for _ in range(random.randint(3,8)))) for _ in range(20))
write_testcase("random_small", "A small random testcase",f"{len(words.split())}\n{words}\n8")
words = " ".join(("".join(random.choice(string.ascii_lowercase) for _ in range(random.randint(3,8)))) for _ in range(max_words//2))
write_testcase("random_medium", "A medium random testcase",f"{len(words.split())}\n{words}\n125")
words = " ".join(("".join(random.choice(string.ascii_lowercase) for _ in range(random.randint(3,8)))) for _ in range(max_words))
write_testcase("random_large_1", "A large random testcase",f"{len(words.split())}\n{words}\n250")
words = " ".join(("".join(random.choice(string.ascii_lowercase) for _ in range(random.randint(3,8)))) for _ in range(max_words))
write_testcase("random_large_2", "A large random testcase",f"{len(words.split())}\n{words}\n250")