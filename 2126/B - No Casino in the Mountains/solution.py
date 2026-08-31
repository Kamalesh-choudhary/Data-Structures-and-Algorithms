t = int(input())
for _ in range(t):
    n,k = map(int,input().split())
    ar = list(map(int,input().split()))
    temp = 0
    max_trip=0
    i=0
    while i<len(ar):
        if  ar[i]==0:
            temp+=1
            if temp == k:
                i+=1
                max_trip+=1
                temp=0
        else:
            temp = 0
        i+=1
    print(max_trip)