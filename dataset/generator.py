import random
l =  [5 ,10]
a = 10;
s = []
def Almost(size):
    t = []
    for i in range(size):
        t.append(i-random.randint(-3, 5))
    return t
def Sorted(size):
    t = []
    for i in range(size):
        t.append(i)
    return t
def Random(size):
    t = []
    for i in range(size):
        t.append(int(random.random()*random.randrange(-10000,10000)))
    return t
def Reverse(size):
    t = []
    for i in range(size):
        t.append(size-i)
    return t
def Small_range(size):
    t = []
    for i in range(size):
        t.append(random.randint(0, 50))
    return t
t = ["Almost","Sorted","Random","Reverse","Small_range"] 
for n in t:
    while( a < 100001):
        for x in l:
            # with open(f"{n}_{x*a}.txt","w") as f:
            #     if(n=="Almost"):
            #         t = Almost(x*a)
            #         for x in t:
            #             print(f"{x}",file=f)
            #     if(n=="Sorted"):
            #         t = Sorted(x*a)
            #         for x in t:
            #             print(f"{x}",file=f)
            #     if(n=="Random"):
            #         t = Random(x*a)
            #         for x in t:
            #             print(f"{x}",file=f)
            #     if(n=="Reverse"):
            #         t = Reverse(x*a)
            #         for x in t:
            #             print(f"{x}",file=f)
            #     if(n=="Small_range"):
            #         t = Small_range(x*a)
            #         for x in t:
            #             print(f"{x}",file=f)
            s.append(f"{n}_{x*a}.txt")
        a*=10
    a = 10
print("{",end = '')
for a in s:
    print(f'"{a}"',end=',')
