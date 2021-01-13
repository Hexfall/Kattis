dirs = {
    "North": 0,
    "East" : 1,
    "South": 2,
    "West" : 3,
}

def isRight(this, other):
    return (this - other) % 4 == 1

def isStraight(this, other):
    return (this - other) % 4 == 2

def isLeft(this, other):
    return (this - other) % 4 == 3

cur, dir, oth = [dirs[i] for i in input().split()]
if isLeft(cur, oth) or isRight(cur, dir):
    print("No")
    exit()
if isRight(cur, oth) or (isStraight(cur, oth) and isLeft(cur, dir)):
    print("Yes")
else:
    print("No")
