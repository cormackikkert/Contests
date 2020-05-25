N, D = map(int, input().split())

class TrafficLight:
    def __init__(self, x, a, g, r):
        self.pos = a
        self.a = x
        self.g = g
        self.r = r

trafficLights = []

for i in range(N):
    a, b, c, d = map(int, input().split())
    trafficLights.append(TrafficLight(a, b, c, d))

trafficLights.sort(key = lambda n:n.pos)

for light in trafficLights:
    s = light.pos - light.a
    if not s % (light.g + light.r) <= light.g:
        print("NO")
        break

else:
    print("YES")
    
