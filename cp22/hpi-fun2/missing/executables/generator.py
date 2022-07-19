from asyncore import write
import random
from pathlib import Path
import string

random.seed(-5439687794124513171)


def write_testcase(name, desc, string):
    Path(name + '.in').write_text(string)
    Path(name + '.desc').write_text(desc + '\n')

max_length = 2500

write_testcase("sample1", "A simple testcase", "allaoggo")
write_testcase("sample2", "A simple testcase", "banana")
write_testcase("sample3", "A simple testcase", "masseffect")
some_text = "sqddbydscraqgvzfquizlmdopleiqtceyemhuyotzj"
write_testcase("single_letter", "Only one letter", "x")
write_testcase("long_palindrome", "A long palindrome", some_text + "".join(reversed(some_text)))
write_testcase("no_palindromes", "A testcase without palindromes", "azbcdefgzhijklmznopqrsztuvw")
long_text = ''.join(random.choice(string.ascii_lowercase) for _ in range(int(max_length/2)))
write_testcase("very_long_palindrome", "A very long palindrome", long_text + "".join(reversed(long_text)))
write_testcase("anti_greedy", "A testcase that has a different result for a greedy algo", "abbacddcbbae")
write_testcase("many_palindromes", "Many similar palindromes", "".join(random.choice(["anna", "otto", "iggi"]) for _ in range(int((max_length-1)/4))))
for i in range(5):
    write_testcase(f"random_small_{i}", "A small random testcase",''.join(random.choice(string.ascii_lowercase) for _ in range(20)))
    write_testcase(f"random_large_{i}", "A large random testcase",''.join(random.choice(string.ascii_lowercase) for _ in range(max_length)))
