import multiprocessing
import time


def cube(x):
	return x * x * x


mppool = multiprocessing.Pool()
resultasync = [mppool.apply_async(cube, args = (i, )) for i in	range(20)]
results = [res.get() for res in resultasync]
print("Result: {}".format(results))
