

x = 10
y = 50

temp = x
x = y
y = temp

print("Value of x: " + str(x) + " Value of y: " + str(y))

x, y = y, x

print("Value of x: " + str(x) + " Value of y: " + str(y))

x = x ^ y
y = x ^ y
x = x ^ y

print("Value of x: " + str(x) + " Value of y: " + str(y))

x = x + y  
y = x - y 
x = x - y

print("Value of x: " + str(x) + " Value of y: " + str(y))

x = x * y
y = x / y
x = x / y

print("Value of x: " + str(x) + " Value of y: " + str(y))

u = 2
v = 7
u = (u & v) + (u | v)
v = u + (~v) + 1
u = u + (~v) + 1

print("Value of x: " + str(u) + " Value of y: " + str(v))
