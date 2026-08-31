t = int(input())
for _ in range(t):
    n,c = map(int,input().split())
    ar = list(map(int,input().split()))
    ans = 0
    for _ in range(n):
        free_bag = [bag for bag in ar if bag <= c]
        destroy_bag = 0
        if free_bag:
            destroy_bag = max(free_bag)
        else:
            ans += 1
            destroy_bag = min(ar)
        ar.remove(destroy_bag)
        for i in range(len(ar)):
            ar[i]*=2
    print(ans)