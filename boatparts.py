partcount, days = [int(i) for i in input().split()]
parts = set()
for i in range(days):
    part = input()
    parts.add(part)
    if len(parts) == partcount:
        print(i + 1)
        break
else:
    print("paradox avoided")
