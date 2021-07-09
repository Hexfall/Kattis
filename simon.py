prefix = "simon says "

for _ in range(int(input())):
    inp = input()
    if inp.startswith(prefix):
        print(inp[len(prefix):])
    else:
        print()
