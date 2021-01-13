def isHarshad(n):
    subsum = sum([int(c) for c in str(n)])
    return n % subsum == 0

num = int(input())
while not isHarshad(num):
    num += 1
print(num)
