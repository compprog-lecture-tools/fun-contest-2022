import random
from pathlib import Path

random.seed(-837120128602079247)

Path(f"sample.in").write_text("queue")
Path(f"sample.desc").write_text("queue")

for test in ("stack", "set", "pq"):
    Path(f"{test}.in").write_text(test)
    Path(f"{test}.desc").write_text(test)

