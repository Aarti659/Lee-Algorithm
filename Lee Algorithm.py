from collections import deque
ROW = 5
COL = 5
class Cell:
    def __init__(self, x: int, y: int):
        self.x = x
        self.y = y

class Node:
    def __init__(self, pt: Cell, dist: int):
        self.pt = pt
        self.dist = dist

def chk_Val(row: int, col: int):
    return ((row >= 0) and (row < ROW) and (col >= 0) and (col < COL))
rowNum = [-1, 0, 0, 1]
colNum = [0, -1, 1, 0]

def Lee(matrix, src: Cell, dest: Cell):
    if matrix[src.x][src.y] != 1 or matrix[dest.x][dest.y] != 1:
        return -1
    visited = [[False for j in range(COL)]
               for j in range(ROW)]
    visited[src.x][src.y] = True
    q = deque()
    s = Node(src, 0)
    q.append(s)

    while q:
        curr = q.popleft()
        pt = curr.pt
        if pt.x == dest.x and pt.y == dest.y:
            return curr.dist
        for j in range(4):
            row = pt.x + rowNum[j]
            col = pt.y + colNum[j]

            if (chk_Val(row, col) and
                    matrix[row][col] == 1 and
                    not visited[row][col]):
                visited[row][col] = True
                Adjcell = Node(Cell(row, col),
                                    curr.dist + 1)
                q.append(Adjcell)
    return -1
matrix = [[1, 0, 1, 1, 1],
       [1, 0, 1, 0, 1],
       [1, 1, 1, 0, 1],
       [0, 0, 0, 0, 1],
       [1, 1, 1, 0, 1]]
source = Cell(0, 0)
dest = Cell(2, 1)

dist = Lee(matrix, source, dest)

if dist != -1:
    print("Length of the Shortest Path ", dist)
else:
    print("no shortest path")
