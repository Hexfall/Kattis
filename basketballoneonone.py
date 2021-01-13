inp = input()
scores = {
    'A': 0,
    'B': 0,
}

for i in range(len(inp) // 2):
    scores[inp[i*2]] += int(inp[i*2 + 1])

if scores['A'] > scores['B']:
    print('A')
else:
    print('B')
