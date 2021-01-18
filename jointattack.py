from fractions import Fraction

input()
nums  = [int(i) for i in input().split()][::-1]
total = Fraction(nums[0])
for i in nums[1:]:
    total = Fraction(i + Fraction(1, total))

print("{}/{}".format(total.numerator, total.denominator))
