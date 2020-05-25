A, B, K = map(int, input().split())
diff = min(A, K)
A -= diff
K -= diff

if K > 0:
    B -= min(B, K)
print(A, B)
