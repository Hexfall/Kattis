for i in range(int(input())):
    cals = int(input())
    num = cals // 400
    num += 0 if cals % 400 == 0 else 1
    print(num)
