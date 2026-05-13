from math import factorial

n = int(input())

maxa = 5 * 10**4
maxbdiff = 23

maxc = 100
maxFatC = factorial(maxc)


allFacts = dict()

f = 1
for i in range(1, 1000):
    f *= i
    allFacts[f] = i

for a in range(1, maxa + 1):
    lb = max(a - maxbdiff, 2)

    for b in range(lb, a):
        fatA = 1
        for i in range(a, b, -1):
            fatA *= i

        if fatA % n != 0:
            continue

        fatCShouldBe = fatA // n

        if fatCShouldBe in allFacts:
            c = allFacts[fatCShouldBe]
            if c >= 2 and c <= b:
                print(a, b, c)
                exit(0)


print(-1, -1, -1)
