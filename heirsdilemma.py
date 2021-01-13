def validNum(num):
    nums = getNums(num)
    if len(nums) != 6 or 0 in nums:
        return False
    for n in nums:
        if num % n != 0:
            return False
    return True

def getNums(num):
    nums = set()
    for char in str(num):
        nums.add(int(char))
    return nums

lo, hi = [int(i) for i in input().split()]
count = 0
for i in range(lo, hi + 1):
    if validNum(i):
        count += 1
print(count)
