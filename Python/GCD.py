def gcd(a, b):
	if a == 0:
		return b

	return gcd(b % a, a)

a=37
b=7
print("gcd(", a, ",", b, ") = ", gcd(a, b))

def gcdExtended(a, b):

    if a == 0:
        return b, 0, 1
 
    gcd, x1, y1 = gcdExtended(b % a, a)
 
    x = y1 - (b//a) * x1
    y = x1
 
    return gcd, x, y
 
 

a, b = 45, 25
g, x, y = gcdExtended(a, b)

print("gcd(", a, ",", b, ") = ", g)



