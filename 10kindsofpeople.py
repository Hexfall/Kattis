WORDMAP = {
    True  : 'binary',
    False : 'decimal',
}

class QuickUnion:
    def __init__(self, graph):
        # Dimensions of map.
        self.width = len(graph[0])
        self.height = len(graph)
        # QuickUnion Set.
        self.set = [i for i in range(self.width * self.height)]
        # Store node weights.
        self.weight = [1 for i in range(self.width * self.height)]
        # Store whether a cell is 'binary' or 'decimal'
        self.bin = [True for i in range(self.width * self.height)]
        self.__setup(graph)

    def get_index(self, y, x):
        return self.width * y + x

    def __setup(self, graph):
        # Give nodes correct type and connect them accordingly.
        for i in range(self.height):
            for j in range(self.width):
                # Set True if in 'binary' neighborhood.
                self.bin[self.get_index(i, j)] = (graph[i][j] == '0')
                # Try to connect node to node above.
                if i > 0:
                    self.__try_connect(
                        self.get_index(i, j),
                        self.get_index(i - 1, j)
                    )
                # Try to connect node to node to the left.
                if j > 0:
                    self.__try_connect(
                        self.get_index(i, j),
                        self.get_index(i, j - 1)
                    )

    def __try_connect(self, index1, index2):
        if self.bin[index1] == self.bin[index2]:
            self.connect(index1, index2)

    def connect(self, index1, index2):
        # Get top-level nodes.
        index1 = self.find(index1)
        index2 = self.find(index2)
        if self.connected(index1, index2):
            return
        if self.weight[index1] >= self.weight[index2]:
            self.set[index2] = index1
            self.weight[index1] += self.weight[index2]
        else:
            self.set[index1] = index2
            self.weight[index2] += self.weight[index1]

    def find(self, index):
        if index == self.set[index]:
            return index
        return self.find(self.set[index])

    def connected(self, index1, index2):
        return self.find(index1) == self.find(index2)

    def str(self, index):
        return WORDMAP[self.bin[index]]

    def __str__(self):
        rows = []
        for i in range(self.height):
            rows.append("".join([str(self.find(j)) for j in range(i * self.width, (i + 1) * self.width)]))
        return "\n".join(rows)

    def __repr__(self):
        return str(self)

y, x = [int(i) for i in input().split()]
# Read map from input.
graph = [input() for i in range(y)]
# Create QuickUnion set.
mapSet = QuickUnion(graph)

for i in range(int(input())):
    y1, x1, y2, x2 = [int(i) - 1 for i in input().split()]
    if mapSet.connected(
        mapSet.get_index(y1, x1),
        mapSet.get_index(y2, x2)
    ):
        print(mapSet.str(mapSet.get_index(y1, x1)))
    else:
        print('neither')

