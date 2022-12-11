def minSkips(self, A, s, target):
    n = len(A)
    dp = [0] * (n + 1)
    for i, a in enumerate(A):
        for j in range(n, -1, -1):
            dp[j] += a
            if i < n - 1:
                dp[j] = (dp[j] + s - 1) / s * s
            if j:
                dp[j] = min(dp[j], dp[j - 1] + a)
    for i in range(n):
        if dp[i] <= s * target:
            return i
    return -1
    
if __name__ == '__main__':
    dist1 = [1, 3, 2]
    speed1 = 4
    hoursBefore1 = 2
    print(minSkips(minSkips,dist1,speed1,hoursBefore1)-1)#returns 1
    dist2 = [7, 3, 5, 5]
    speed2 = 2
    hoursBefore2 = 10
    print(minSkips(minSkips, dist2, speed2, hoursBefore2)-1)#returns 2
    dist3 = [7, 3, 5, 5]
    speed3 = 1
    hoursBefore3 = 10
    print(minSkips(minSkips, dist3, speed3, hoursBefore3))