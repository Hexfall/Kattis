x, y, z = [int(i) for i in input().split()]
print(max(y - x, z - y) - 1)
