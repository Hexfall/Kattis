s = input()
while len(s) != 1:
    p = 1
    for char in s:
        if char != "0":
            p *= int(char)
    s = str(p)
print(s)
