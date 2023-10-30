from math import log

for case in range(int(input())):
    num, source, target = [list(i) for i in input().split()]
    translated = 0
    for i, n in enumerate(num[::-1]):
        translated += source.index(n) * len(source)**i
    s = ""
    base = len(target)
    i = int(log(translated, base))
    while i >= 0:
        s += target[translated//(base**i)]
        translated = translated % (base**i)
        i -= 1
    print(f"Case #{case+1}: {s}")
