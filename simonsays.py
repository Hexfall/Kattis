for i in range(int(input())):
    order = input()
    if order.startswith("Simon says"):
        print(order[11:])

