from math import ceil

a, b, h = [int(i) for i in input().split()]

if (h <= a):
    print(1)
    exit()

h -= a
print(ceil(h/(a-b)) + 1)
