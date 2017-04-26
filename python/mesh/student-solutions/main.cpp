#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <deque>
#include <set>

struct Point
{
	double x, y, z;
	std::size_t index;
};

struct Cell
{
	std::size_t v1, v2, v3, v4;
};

double sqr (double x)
{
	return x * x;
}

int main ()
{
	std::vector<Point> points;
	std::vector<Cell> cells;
	// read data
	{
		std::ifstream file ("mesh-coarse.out");
		std::size_t points_num, cells_num;
		file >> points_num;
		points.resize (points_num);
		for (std::size_t i = 0; i < points_num; ++i)
			file >> points[i].x >> points[i].y >> points[i].z;
		file >> cells_num;
		cells.resize (cells_num);
		for (std::size_t i = 0; i < cells_num; ++i)
		{
			file >> cells[i].v1 >> cells[i].v2 >> cells[i].v3 >> cells[i].v4;
			int dummy;
			file >> dummy;
		}
	}
	Point center;
	float radius;
	center.x = 0; center.y = 75; center.z =  1420;
	radius = 30;
	
	// algorithm
	std::deque<std::size_t> ans_cells;
	std::set<std::size_t> ans_points;
	for (std::size_t i = 0; i < cells.size(); ++i)
	{
		Cell cell = cells[i];
		Point cell_center = {(points[cell.v1-1].x + points[cell.v2-1].x + points[cell.v3-1].x + points[cell.v4-1].x) / 4,
		                     (points[cell.v1-1].y + points[cell.v2-1].y + points[cell.v3-1].y + points[cell.v4-1].y) / 4,
		                     (points[cell.v1-1].z + points[cell.v2-1].z + points[cell.v3-1].z + points[cell.v4-1].z) / 4, 0};
		 if (sqr (cell_center.x - center.x) +
		     sqr (cell_center.y - center.y) +
			 sqr (cell_center.z - center.z) <= sqr (radius))
		 {
			 ans_cells.push_back (i);
			 ans_points.insert (cell.v1 - 1);
			 ans_points.insert (cell.v2 - 1);
			 ans_points.insert (cell.v3 - 1);
			 ans_points.insert (cell.v4 - 1);
		}
	}

	// write data
	{
		std::ofstream file ("ans.out");
		file << ans_points.size() << std::endl;
		std::size_t index = 1;
		for (const auto& i: ans_points)
		{
			file << points[i].x << ' ' << points[i].y << ' ' << points[i].z << std::endl;
			points[i].index = index++;
		}
		file << ans_cells.size() << std::endl;
		for (const auto& i: ans_cells)
			file << points[cells[i].v1 - 1].index << ' ' << points[cells[i].v2 - 1].index << ' '
			     << points[cells[i].v3 - 1].index << ' ' << points[cells[i].v4 - 1].index << " 0" << std::endl;
		file << "0" << std::endl;
	}
	return 0;
}
