array = []

i = 0
n = int(input('请输入一个数以确定输入的数据个数:\n'))

for i in range(n):
    temp = int(input())
    j = 0
    while j < i:
        if (temp < array[j]):
            break
        j += 1
    array.insert(j,temp)


print(array)
