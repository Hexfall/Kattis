prev = ''
points = 0
for i in range(int(input())):
    c = input()
    if c == prev:
        points += 1
    prev = c
print(points)
