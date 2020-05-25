S = list(reversed(input().strip()))

MOD = int(pow(10, 9) + 7)

powers = [1 for i in range(len(S))]
for i in range(1, len(S)):
    powers[i] = (10 * powers[i - 1]) % 13

dp = [[0 for i in range(13)] for j in range(len(S))]

for i, char in enumerate(S):
    def compute(num):
        if i == 0:
            # Base case
            dp[0][num] += 1
        else:
            for o in range(13):
                dp[i][(o + num * powers[i]) % 13] += dp[i - 1][o]
                dp[i][(o + num * powers[i]) % 13] %= MOD
                
    if char == "?":
        for j in range(10):
            compute(j)
    else:
        compute(int(char))

print(dp[-1][5])
