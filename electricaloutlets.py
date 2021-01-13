for i in range(int(input())):
    print(sum([int(i) - 1 for i in input().split()[1:]]) + 1)
