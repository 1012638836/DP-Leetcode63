#include<iostream>
#include<vector>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	if (obstacleGrid[0][0] == 1) { return 0; }//no way!
	else if (m == 1 && n == 1) { return 1; }
	int **path = new int* [m];
	for (int i = 0; i < m; i++)
	{
		path[i] = new int[n];
	}

	for (int i = 0; i < m; i++)
	{
		if (obstacleGrid[i][0] == 1)
		{
			while (i < m)
			{
				path[i][0] = 0;
				i++;
			}
		}
		else { path[i][0] = 1; }
	}
	for (int j = 0; j < n; j++)
	{
		if (obstacleGrid[0][j] == 1)
		{
			while (j < n)
			{
				path[0][j] = 0;
				j++;
			}
		}
		else { path[0][j] = 1; }
	}
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (obstacleGrid[i][j] == 1) { path[i][j] = 0; }
			else { path[i][j] = path[i - 1][j] + path[i][j - 1]; }
		}
	}
	return path[m - 1][n - 1];
}