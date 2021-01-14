size, walls = [int(i) for i in input().split()]
parts = [int(i) for i in input().split()]
parts.append(size)
parts.insert(0, 0)
configs = set()

for i in range(walls + 1):
    for j in range(i + 1, walls + 2):
        configs.add(parts[j] - parts[i])

print(" ".join([str(i) for i in sorted(configs)]))    

