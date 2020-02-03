#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "Cell.h"

namespace Graph
{
	//A graph that is rendered uniformly should have Cells that are uniformly sized
	//A graph that is nonuniform will render each Cell as its own square
	//This will be specified in the render function at the programmer's specification
	class Graph
	{
		protected:
			unsigned int _xCells;
			unsigned int _yCells;
			std::vector<std::vector<Cell>> _cells;

		public:
			Graph()
			{
				_cells.resize(0);
			}

			//this generates a very simple uniform graph
			Graph(int x_cells, int y_cells)
			{
				_cells.resize(x_cells);
				for (int i = 0; i < x_cells; i++)
				{
					_cells[i].resize(y_cells);
					for (int j = 0; j < y_cells; j++)
					{
						_cells[i][j] = Cell(ScaleUnit(i, j), ScaleUnit(i, j+1), ScaleUnit(i+1, j+1), ScaleUnit(i+1, j));
					}
				}
			}

			Graph(std::vector<std::vector<Cell>> initCells)
			{
				_cells = initCells;
			}

			Cell* GetCell(int x, int y)
			{
				if (x >= 0 && x < _cells.size() && y >= 0 && y < _cells[x].size())
				{
					return &_cells[x][y];
				}
			}
	};
}

#endif
