class Node:
    def __init__(self, name):
        self.name = name
        self.edges = []
        self.done = False
        self.target = False
        self.path = []

    def add_edge(self, other):
        self.edges.append(other)
        other.edges.append(self)


def inc(num, pos):
    s = str(num)
    d = s[pos]
    d = str((int(d) + 1) % 10)
    return s[:pos] + d + s[pos + 1:]


def dec(num, pos):
    s = str(num)
    d = s[pos]
    d = str((int(d) - 1) % 10)
    return s[:pos] + d + s[pos + 1:]


n, m = map(int, input().split())
origin = input()
target = input()

# Origin is target check
if origin == target:
    print(0)
    print(origin)
    exit()

ms = [input() for _ in range(m)]
ms.insert(0, origin)

nodes = {target: Node(target)}
nodes[target].target = True

for i in ms:
    nodes[i] = Node(i)
    for d in range(n):
        try:
            nodes[inc(i, d)].add_edge(nodes[i])
        except:
            pass
        try:
            nodes[dec(i, d)].add_edge(nodes[i])
        except:
            pass

nodes[origin].path = [origin]
q = [nodes[origin]]

while len(q) != 0:
    node = q.pop(0)
    if node.target:
        break
    if node.done:
        continue
    node.done = True
    for e in node.edges:
        if len(e.path) == 0:
            e.path = node.path + [e.name]
            q.append(e)

t = nodes[target]
if len(t.path) == 0:
    print("Neibb")
else:
    print(len(t.path) - 1)
    print("\n".join([str(n) for n in t.path]))
