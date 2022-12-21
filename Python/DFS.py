from collections import defaultdict
 
class Graph:
 
    def __init__(self):
 
        self.graph = defaultdict(list)
 
    def addEdge(self,x,y):
        self.graph[x].append(y)
 

    def bfsu(self, y, visitednode):
        visitednode[y]= True
        print(y)

        for i in self.graph[y]:
            if visitednode[i] == False:
                self.bfsu(i, visitednode)
 
 

    def DFS(self):
        a = len(self.graph)
        visitednode =[False]*(a)
        for i in range(a):
            if visitednode[i] == False:
                self.bfsu(i, visitednode)
 

grap = Graph()
grap.addEdge(0, 1)
grap.addEdge(0, 2)
grap.addEdge(1, 2)
grap.addEdge(2, 0)
grap.addEdge(2, 3)
grap.addEdge(3, 3)
 
print("DFS Route")
grap.DFS()
