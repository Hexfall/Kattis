judge1 = {}
num = int(input())
same = 0

for i in range(num):
    grade = input()
    try:
        judge1[grade] += 1
    except:
        judge1[grade] = 1
for i in range(num):
    grade = input()
    if grade in judge1.keys():
        if judge1[grade] > 0:
            judge1[grade] -= 1
            same += 1
print(same)
