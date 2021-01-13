from fractions import Fraction

for i in range(int(input())):
    inp = input().split()
    f1 = Fraction(
        int(inp[0]),
        int(inp[1])
    )
    f2 = Fraction(
        int(inp[3]),
        int(inp[4])
    )
    f3 = eval('f1 ' + inp[2] + ' f2')
    print(str(f3.numerator) + ' / ' + str(f3.denominator))
