array = [23, 45, 6, 31, 78, 65, 20]

for i in range(7):
    min = i
    for j in range(i, 7):
        if (array[j] < array[min]):
            min = j
    array[i], array[min] = array[min], array[i]
print(array)
