from collections import Counter

with open("chimin.txt") as file:
    length = int(file.readline())
    data = {"G": 1, "C": 2, "A": 3, "T":4}
    seq = [[data[char] for char in file.readline().strip()],
           [data[char] for char in file.readline().strip()],
           [data[char] for char in file.readline().strip()]]

print("DATA")
for item in seq:
    print(item)
count = [0, 0, 0]
ind_sort = sorted([i for i in range(length)], key = lambda i:len({seq[0][i], seq[1][i], seq[2][i]}))
print("ind_sort", ind_sort)
index = 0
for i in range(length):
    print("---\n",i)
    print(ind_sort)
    sorted_count = sorted(count)
    small1 = count.index(sorted_count[0])
    small2 = count.index(sorted_count[1])
    temp = False
    for j in range(len(ind_sort)):
        amount = Counter([seq[0][ind_sort[j]], seq[1][ind_sort[j]], seq[2][ind_sort[j]]])
        results = amount.most_common()
        print(results)
        if results[0][0] == seq[small1][i]:
            if results[0][0] == seq[small2][i]:
                index = ind_sort[j]
                break
            elif not temp:
                index = ind_sort[j]
                temp = results
        elif temp and max(results, key=lambda x:x[1])[1] < temp[0][1]:
            break
    print("Index chosen", index)
    print("count:", count)
    print("sequence", [seq[0][index], seq[1][index], seq[2][index]])
    count[0] += (seq[0][index]) == (seq[small1][index])
    count[1] += (seq[1][index]) == (seq[small1][index])
    count[2] += (seq[2][index]) == (seq[small1][index])
    seq[0].pop(index)
    seq[1].pop(index)
    seq[2].pop(index)
    ind_sort.remove(index)
    ind_sort = [x-(index < x) for x in ind_sort]

with open("chimout.txt", "w+") as file:
    file.write(str(min(count, key = lambda x:x[1])[1]))
