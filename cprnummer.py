ns = [int(i) for i in "".join(input().split('-'))]
ms = [4, 3, 2, 7, 6, 5, 4, 3, 2, 1]
prod = 0
for n, m in zip(ns, ms):
    prod += n*m
if prod % 11 == 0:
    print(1)
else:
    print(0)