t = int(input())
for _ in range(t):
    x = input()
    for i in range(10):
        if str(i) in x:
            print(i)
            break