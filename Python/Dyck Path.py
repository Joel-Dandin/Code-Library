
def DyckPaths(x):
	

	result = 1
	for i in range(0, x):
		result *= (2 * x - i)
		result /= (i + 1)

	return result / (x+1)

n = 4
print("No of Dyck Paths: ",	str(int(DyckPaths(n))))


