string = input()
upcase = 0
lowcase = 0
for i in range(len(string)):
    if string[i] == string[i].upper():
        upcase+=1
    else:
        lowcase+=1
if upcase > lowcase:
    print(string.upper())
elif lowcase > upcase:
    print(string.lower())
else:
    print(string.lower())