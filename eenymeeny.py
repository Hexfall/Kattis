rhymelength = len(input().split()) - 1
playerCount = int(input())
players = [input() for i in range(playerCount)]
index = 0
turnA = False
teamA, teamB = [], []

while len(players) != 0:
    turnA = not turnA
    index = (index + rhymelength) % len(players)
    player = players.pop(index)
    
    if turnA:
        teamA.append(player)
    else:
        teamB.append(player)
print(len(teamA))
print("\n".join(teamA))
print(len(teamB))
print("\n".join(teamB))
