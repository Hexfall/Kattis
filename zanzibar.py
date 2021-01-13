for c in range(int(input())):
    imports = 0
    ledger = [int(i) for i in input().split()[:-1]]
    for i in range(len(ledger)):
        imports += max(
            0,
            ledger[i] - 2*ledger[i - 1]
        )
    print(imports)
