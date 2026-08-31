n,k = map(int,input().split())
ar = list(map(int,input().split()))
count = 0
kth = ar[k-1]
for i in range(n):
    if ar[i] >= kth and ar[i] > 0:
        count+=1
print(count)