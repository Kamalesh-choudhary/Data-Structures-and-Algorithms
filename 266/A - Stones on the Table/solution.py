n = int(input())
string = [str(letter) for letter in input()]
xount = 0
for i in range(n-1):
    if string[i] == string[i+1]:
        xount+=1
print(xount)