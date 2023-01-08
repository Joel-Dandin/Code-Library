def ncatalan(n):
    if n <= 1:
        return 1
    result = 0
    for i in range(n):
        result += ncatalan(i) * ncatalan(n-i-1)
 
    return result
 
print("The 20 catalan numbers are\n")
for i in range(20):
    print(ncatalan(i), end=" ")
