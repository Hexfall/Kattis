word = set(input())
wrong = 0
for char in input():
    if char in word:
        word.remove(char)
        if len(word) == 0:
            print("WIN")
            exit()
    else:
        wrong += 1
        if wrong == 10:
            break
print("LOSE")
