n = int(input())
s = input()
s2=""

for i in range(n):
    s2+=s[i]
    if i+1 < n and s[i]==')' and s[i+1]=='(':
        s2+='*'

    if i+1 < n and s[i]=='(' and s[i+1]==')':
        s2+='1'
        
    if i+1 < n and s[i]==')' and s[i+1]==')':
        s2+='+1'
print(eval(s2))
