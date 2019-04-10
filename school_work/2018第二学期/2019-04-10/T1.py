str = input()
L = str.split(',')
sum = 0
j = 0
for i in L:
    i = int(i)
    sum += i
    j += 1
print(L)
print('平均值为:', sum / j)
