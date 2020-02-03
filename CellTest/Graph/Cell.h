#ifndef CELL_H
#define CELL_H

#include "ScaleUnit.h"

namespace Graph
{
	/** A cell stores 4 worldspace positions:
	 *	0, 0 is bottom left
	 *	0, 1 is top left
	 *	1, 1 is top right
	 *	1, 0 is bottom right
	 *
	 * Because this class doesn't do anything complicated, everything is defined here in the header
	 * The only unintuitive part is that the draw order is different to the store order, which is why it's
	 *	abstracted away like this
	 */
	class Cell
	{
		private:
			ScaleUnit _p[2][2];

			//this probably should not be used after the Cell has been constructed, hence private
			void Set(short i, short j, ScaleUnit val)
			{
				if (i >= 0 && i < 2 && j >= 0 && j < 2)
				{
					_p[i][j] = val;
				}
			}

		public:
			//GameObject *occupier = nullptr;

			Cell() 
			{ 
				_p[0][0] = ScaleUnit(0, 0);
				_p[0][1] = ScaleUnit(0, 1);
				_p[1][0] = ScaleUnit(1, 0);
				_p[1][1] = ScaleUnit(1, 1);
			}

			Cell(ScaleUnit bl, ScaleUnit tl, ScaleUnit tr, ScaleUnit br)
			{
				_p[0][0] = bl;
				_p[0][1] = tl;
				_p[1][0] = br;
				_p[1][1] = tr;
			}

			Cell(ScaleUnit positions[2][2])
			{
				_p[0][0] = positions[0][0];
				_p[0][1] = positions[0][1];
				_p[1][0] = positions[1][0];
				_p[1][1] = positions[1][1];
			}

			ScaleUnit Get(short i, short j)
			{
				if (i >= 0 && i < 2 && j >= 0 && j < 2)
				{
					return _p[i][j];
				}

				return ScaleUnit();
			}
	};
}

#endif
