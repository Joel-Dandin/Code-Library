def knapSack(w, wt, value, n):
    k = [[0 for x in range(w + 1)] for x in range(n + 1)]
  
    for i in range(n + 1):
        for W in range(w + 1):
            if i == 0 or W == 0:
                k[i][W] = 0
            elif wt[i-1] <= W:
                k[i][W] = max(value[i-1] + k[i-1][W-wt[i-1]],  k[i-1][W])
            else:
                k[i][W] = k[i-1][W]
  
    return k[n][w]
  

value = [60, 100, 120]
wt = [10, 20, 30]
w = 50
n = len(value)
print(knapSack(w, wt, value, n))