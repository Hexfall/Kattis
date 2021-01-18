for i in range(int(input())):
    num, switches = [int(j) for j in input().split()]
    mask = switches & 2**num - 1 == 2**num - 1
    print("Case #{}: {}".format(i + 1, "ON" if mask else "OFF"))
