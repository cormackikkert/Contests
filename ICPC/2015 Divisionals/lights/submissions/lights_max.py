N, D = [int(v) for v in input().split()]
lights = []
for i in range(N):
	lights.append([int(v) for v in input().split()])

g = True
for l in lights:
	le = l[2]+l[3]
	t = l[0]-l[1]
	rem = t%le
	if rem > l[2] or t < 0:
		g = False

if g:
	print("YES")
else:
	print("NO")
