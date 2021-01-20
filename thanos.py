for i in range(int(input())):
    pop, gro, foo = [int(i) for i in input().split()]
    days = 0
    while pop <= foo:
        pop *= gro
        days += 1
    print(days)
