class node:
    def __init__(self, height, tall_left, tall_right):
        self.height = height
        self.tall_left = tall_left
        self.tall_right = tall_right

    def bungee(self):
        small_tall = min(self.tall_right, self.tall_left)
        return max(0, small_tall - self.height)

count = int(input())
vals = [int(i) for i in input().split()]
tallest_rights = [vals[-1]]
for i in range(count - 2, -1, -1):
    tallest_rights.append(max(tallest_rights[-1], vals[i]))
tallest_rights = tallest_rights[::-1]
tallest_left = vals[0]

maxheight = 0
for i in range(1, count - 1):
    n = node(
        vals[i],
        tallest_left,
        tallest_rights[i]
    )
    tallest_left = max(
        tallest_left,
        vals[i]
    )
    maxheight = max(
        maxheight,
        n.bungee()
    )
print(maxheight)
