import random as rd;

def printArray(a, vert=False):
    for x in a:
        print(x, end="\n" if vert else " ")
    if not vert:
        print()
def randomArray(n, min, max, order=0):
    a = []
    for _ in range(n):
        b = rd.randint(min, max)
        a.append(b)
    if order:
        a.sort()
        if order == -1:
            a.reverse()
    return a

if __name__ == "__main__":
    pass
