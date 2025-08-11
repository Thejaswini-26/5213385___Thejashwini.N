#in C even after getting exactly as expected output(sample output), we getting as wrong answer.. that why i used Python code for this quetion

def strings_xor(s, t):
    res = ""
    for i in range(len(s)):
        if s[i] == t[i]:
            res+= '0'
        else:
            res+= '1'

    return res

s = input()
t = input()
print(strings_xor(s, t))
