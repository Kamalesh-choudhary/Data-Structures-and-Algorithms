k,n,w = map(int,input().split())
total = 0
for i in range(w):
    total += k*(i+1)
print(total-n if total > n else 0)