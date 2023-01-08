def catalan(x):
    if (x == 0 or x == 1):
        return 1
 
    catalan = [0 for i in range(x + 1)]
 
    catalan[0] = 1
    catalan[1] = 1
 
    for i in range(2, x + 1):
        catalan[i] = 0
        for j in range(i):
            catalan[i] += catalan[j] * catalan[i-j-1]
 
    return catalan[x]
 
 
for i in range(20):
    print(catalan(i))
