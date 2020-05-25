with open("postin.txt") as file:
    post_count = int(file.readline())
    posters = [tuple(map(int,file.readline().split()))for i in range(post_count)]

lm_s = posters[0][0]
lm_w = posters[0][1]
for i in range(post_count):
    poster = posters[i]
    if lm_s <= poster[0] < lm_s+lm_w or lm_s < poster[0] + poster[1] <= lm_s+lm_w:
        lm_s = poster[0]
        lm_w = poster[1]
    if poster[0] <= lm_s:
        lm_s = poster[0]
        lm_w = poster[1]
with open("postout.txt","w+") as file:
    file.write(str(posters.index((lm_s, lm_w))+1))
