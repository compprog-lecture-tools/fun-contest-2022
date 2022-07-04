from pathlib import Path

SAMPLES = [
    ['sample1', "NOTAPALINDROME"],
    ['sample2', "ISAPALINILAPASI"],
    ['sample3', "2A3MEAS"],
    ['sample4', "ATOYOTA"]
]

for name, s in SAMPLES:
    Path(name + '.in').write_text(s+'\n')
    Path(name + '.desc').write_text(name+'\n')

TESTCASES = [
    "HJA23WYO5UZOYWESALH",
    "R3O8ZRVYO8OYVRZ8O3R",
    "AHMIL8TTE3TT8JIMHA",
    "QCJWDDWJCQ",
    "CEEC",
    "FDJ8Q4ISRPRSI4Q8JDF",
    "YTYYTY",
    "HA9AH",
    "FWEVTAMQMATVEWF",
    "ELE",
    "TUTITUT",
    "ZLLZ",
    "I2HLAAAJHSI",
    "TS12T",
    "NWL6MTDL55BAHH",
    "MIXCQCXIM",
    "ZEXWTJP8",
    "X322J5EXXXX3ZLSSEX",
    "8U8",
    "8YY8",
    "1XBX1",
    "WSAA3UU3AASW",
    "1JKPU3QQ3UPKJ1",
    "XHHX",
    "2ZVIVAOVTXTVOAVIV5S",
    "OVJIMZ8AIIA85MILVO",
    "W1WMAV1UUU1VAMW1W",
    "LXLJXJ",
    "ZHEMTMEHZ",
    "J6P8P6J",
    "N4AVK44KVA4N",
    "XJOZW5UUUZW5OLX",
    "XAXMMV1H88H1VMMXAX",
    "BR82BPW77WPB28RB",
    "RKHX4R4XHKR",
    "EE2VVVV2EE",
    "WTOMNXXNMOTW",
    "M4RPAD3IHE3MSF",
    "W1XTOW8V1V8WOTX1W",
    "NOTAPALINDROME",
    "ISAPALINILAPASI",
    "2A3MEAS",
    "ATOYOTA"
]

for s in TESTCASES:
    Path(s + '.in').write_text(s+'\n')
    Path(s + '.desc').write_text(s+'\n')

for i in range(5):
    Path('large' + str(i) + '.in').write_text('A'*10000+'\n')
    Path('large' + str(i) + '.desc').write_text('10k A\'s'+'\n')

