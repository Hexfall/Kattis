for _ in range(int(input())):
    book = {}
    cons = True
    for _ in range(int(input())):
        num = input()
        if cons:
            d = book
            for c in num[:-1]:
                if c in d.keys():
                    if not type(d[c]) is dict:
                        cons = False
                        break
                else:
                    d[c] = {}
                d = d[c]
            if cons:
                if num[-1] in d.keys():
                    cons = False
                else:
                    d[num[-1]] = True
    print("YES" if cons else "NO")
