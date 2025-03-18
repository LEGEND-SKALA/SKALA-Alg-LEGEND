# A와 B

s = str(input())
t = str(input())

while True:
    
    if t == s:
        print(1)
        break
    
    else:
        if len(t) == 0:
            print(0)
            break
        else:
            if t[-1] == "A":
                t = t[:-1]
            elif t[-1] == "B":
                t = t[:-1]
                t = t[::-1]