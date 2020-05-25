with open("magicin.txt") as file:
    A, B, C = map(int, file.read().split())

def calculate(A, B, C):
    for N in range(1, 21):
        for P in range(1, 21):
            
            E = N - C + B
            F = A + N - P
            G = C + P - N
            H = A + B - C - P + N
                
            if all(1 <= n <= 20 for n in [E, F, G, H]):
                return [A, B, N, C, P, H, E, F, G]

answers = calculate(A, B, C)

with open("magicout.txt", "w") as file:
    file.write(' '.join(map(str, answers[:3])) + '\n')
    file.write(' '.join(map(str, answers[3:6])) + '\n')
    file.write(' '.join(map(str, answers[6:])))
