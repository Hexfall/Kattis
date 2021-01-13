for c in range(int(input())):
    sound = input().split()
    animals = set()
    animal = input()
    while animal != "what does the fox say?":
        animals.add(animal.split()[-1])
        animal = input()

    for i in range(len(sound) - 1, -1, -1):
        if sound[i] in animals:
            sound.pop(i)
    print(" ".join(sound))
