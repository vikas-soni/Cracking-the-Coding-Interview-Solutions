#include<iostream>
#include<vector>
using namespace std;

// path of a robot is simple using backtracking
// idea is to explore every possible legal available cell
bool robo_path(int r, int c, vector<vector<bool>>& grid,int row_size,int col_size, vector<pair<int, int>>& path)
{
	// if robo reached to end
	if ((r == row_size - 1) && (c == col_size - 1))
		return true;

	// try moving robot to the right
	if (((c + 1) < col_size) && (grid[r][c + 1]))
	{
		path.emplace_back(r, c+1);
		if (robo_path(r, c + 1, grid, row_size, col_size, path))
			return true;
		path.pop_back();
	}	

	// try moving robot to down
	if (((r + 1) < row_size) && (grid[r+1][c]))
	{
		path.emplace_back(r+1, c);
		if (robo_path(r + 1, c, grid, row_size, col_size, path))
			return true;
		path.pop_back();
	}
	return false;
}

int main()
{
	// 2d grid of 4x4
	vector<vector<bool>> grid{ {true,true,true,false},
							   {false,false,true,false},
							   {false,false,true,true},
							   {false,false,false,true} };

	vector<pair<int, int>> path;
	path.emplace_back(0, 0);
	robo_path(0, 0, grid, grid.size(), grid[0].size(), path);
	return 0;
}