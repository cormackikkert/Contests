import sys
def solve(n, h, a, P):
    if h == 0:
        return 0.0
    P = {k: v/100.0 for k, v in P.items()}

    dp = [None for x in range(0,n+1)]
    A = [None for x in range(0,n+1)]

    Y = range(0,h+1)
    trans = [  [(-1,P[-1]), (0,P[-1]+P[0])]            if y == 0 else (
                      [(-1,P[-1]), (0,P[0]), (1,P[1])] if y < h else
                      [(0,P[0]+P[1]), (1,P[1])] )
                                                       for y in Y]

    dp[0] = [(1.0 if y == a else 0.0) for y in Y]
    A[0] = [0 for y in Y]
    for i in range(1, n+1):
        dp[i] = [sum(dp[i-1][y-k]*p for k,p in trans[y]) for y in Y]
        A[i] = [sum((dp[i-1][y-k]*A[i-1][y-k] + dp[i-1][y-k]*(y-k + y)/2.0)*p
            for k,p in trans[y])/dp[i][y] if dp[i][y] > 1e-9 else 0.0 for y in Y]

    assert abs(sum(dp[n]) - 1.0) < 1e-9
    return sum(dp[n][y]*A[n][y] for y in Y)

def main():
    P = {}
    n, h, a, P[-1], P[0], P[1] = [int(x) for x in str(sys.stdin.readline()).split()]
    print ("{0:.10f}".format(solve(n, h, a, P)))

if __name__ == "__main__":
    main()
