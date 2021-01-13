def stretch(word, mult):
    s = ""
    for char in word:
        s += char * mult
    return s

row, col, xrow, xcol = [int(i) for i in input().split()]
rows = []

for i in range(row):
    rows.append(input())

for i in range(row*xrow):
    print(stretch(rows[i // xrow], xcol))
