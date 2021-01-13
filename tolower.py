def canSolve(cases):
    b = True
    for i in range(cases):
        s = input()
        if not (s == s.lower() or s == s.capitalize()):
            b = False
    return b

probs, count = [int(i) for i in input().split()]
solved = 0
for i in range(probs):
    solved += 1 if canSolve(count) else 0
print(solved)
