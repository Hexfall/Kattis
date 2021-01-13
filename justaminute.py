mins, secs = 0, 0
for i in range(int(input())):
    min, sec =  [int(j) for j in input().split()]
    mins += min
    secs += sec
avg = float(secs)/float(mins*60)
if avg <= 1:
    print("measurement error")
else:
    print("%.10f" % avg)
