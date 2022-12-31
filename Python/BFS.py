from collections import defaultdict
class Graph:
 #a
    
    def __init__(self):
        self.graph = defaultdict(list)
 
    
    def addedge(self,u,v):
        self.graph[u].append(v)
 
    
    def BFS(self, s):
        nvisited = [False] * (max(self.graph) + 1)
        queue = []
        queue.append(s)
        nvisited[s] = True
        while queue:
            s = queue.pop(0)
            print (s, end = " ")
            for i in self.graph[s]:
                if nvisited[i] == False:
                    queue.append(i)
                    nvisited[i] = True

gra = Graph()
gra.addedge(0, 1)
gra.addedge(0, 2)
gra.addedge(1, 2)
gra.addedge(2, 0)
gra.addedge(2, 3)
gra.addedge(3, 3)

start = input("Enter your value: ")
gra.BFS(int(start))
