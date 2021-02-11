births = {}
for i in range(int(input())):
    name, prio, date = input().split()
    prio = int(prio)
    if date in births.keys():
        if births[date][1] < prio:
            births[date] = (name, prio)
    else:
        births[date] = (name, prio)
print(len(births))
for name in sorted([pair[0] for pair in births.values()]):
    print(name)

