S = input()
N = len(S)
def check(s):
    return s == s[::-1]

if check(S) and check(S[:(N-1)//2]) and check(S[(N+3)//2-1:]):
    print("Yes")
else:
    print("No")