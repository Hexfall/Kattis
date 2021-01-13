def parse(exp):
    if not '-' in exp:
        return 1
    ran = [int(i) for i in exp.split('-')]
    return ran[1] - ran[0] + 1

s = 0
for exp in input().split(';'):
    s += parse(exp)
print(s)
