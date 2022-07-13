#include <bits/stdc++.h>
using namespace std;
#define ROW 5
#define COL 5
struct Cell
{
	int y;
	int z;
};
struct queueNode
{
	Cell pt;
	int dist;
};

bool chk_Valid(int row, int col)
{
	return ((row >= 0) && (row < ROW) &&	(col >= 0) && (col < COL));
}
int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};

int bfs_Lee_Algo(int mat[][COL], Cell src, Cell dest)
{
	if (!mat[src.y][src.z] || !mat[dest.y][dest.z])
		return -1;

	bool visited[ROW][COL];
	memset(visited, false, sizeof visited);
	visited[src.y][src.z] = true;

	queue<queueNode> Q;
	queueNode s = {src, 0};
	Q.push(s);

	while (!Q.empty())
	{
		queueNode curr = Q.front();
		Cell pt = curr.pt;

		if (pt.y == dest.y && pt.z == dest.z)
			return curr.dist;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int row = pt.y + rowNum[i];
			int col = pt.z + colNum[i];

			if (chk_Valid(row, col) && mat[row][col] &&
			!visited[row][col])
			{

				visited[row][col] = true;
				queueNode Adjcell = { {row, col},
									curr.dist + 1 };
				Q.push(Adjcell);
			}
		}
	}
	return -1;
}


int main()
{
	int mat[ROW][COL] =
	{
		{ 1, 0, 1, 1, 1 },
		{ 1, 0, 1, 0, 1 },
		{ 1, 1, 1, 0, 1 },
		{ 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 0, 1 }};

	Cell source = {0, 0};
	Cell dest = {2, 1};

	int dist = bfs_Lee_Algo(mat, source, dest);

	if (dist != -1)
		cout<< "Length of the Shortest Path is "<<dist ;
	else
		cout<< "Shortest Path doesn't exist";

	return 0;
}
