#ifndef SDLHOST_H
#define SDLHOST_H

#include "AppHost.h"
#include "RenderSDL.h"

/*
 * Grid squares:
 *	Grid extends over whole level
 *	ScaleUnits are measured in pixels and are adjustable - this is measured in short
 *	Cells are generally of uniform size in ScaleUnits	 - this should probably be in integers
 *		A cells coordinates are measured by 4 positions, bl, tl, tr, br, which are tuples of ScaleUnits
 *		i.e. A cell which is {0,0}, {0,1}, {1,1}, {1,0} (square), with scale units 2, 1 will occupy the pixels {0,0}, {0,1}, {2,1}, {2,0}
 *		A cell at {2,3}, {2,4}, {3,5}, {3,4} (rhombus), with scale units 2, 3 will occupy the pixels {4,9}, {4,12}, {6,15}, {6,12}
 *	Objects have an origin cell and a 2D array of cells that they occupy
 *	Graphs are made up of cells, basically big objects that cover the whole level
 *		A uniform graph warrants uniform cells that won't have any nonconforming sizes
 *			This is so it can just draw straights lines from edge to edge
 *		A nonuniform graph does not warrant uniform cells, as they may have nonsquare shapes
 *			This is drawn by lines that enclose each cell's boundaries
 *	Generally three of the cell's edges will be entirely/partially defined by the origin
 *		i.e. Origin = {0,0}, {0,1}, {1,1}, {1,0} (a normal square cell) means that the absolute position of the adjacent rightward cell is {1,0}, {1,1}, {2,1}, {2,0}
 *			These cell coordinates should be available in absolute and relative coordinates. This could potentially get retarded as A{1,0}, R{0,0} is the same as A{1.2,0}, R{-0.2, 0}
 *		In a nonuniform graph this means that the above clause is more important: Origin = {0,0}, {0,1}, {1.2,1}, {1,0}, Right adjacent = {1,0}, {1.2,1}, {2,1}, {2,0}
 *		g0 = graph origin (usually just 0 on an everday map)
 *		Therefore, 
 *			cell[g0+1, g0].[0] = cell[g0, g0].[3] and cell[g0+1, g0].[1] = cell[g0, g0].[2]
 *			cell[g0, g0+1].[0] = cell[g0, g0].[1] and cell[g0, g0+1].[3] = cell[g0, g0].[2]
 *			etc... These will be worked out in a graph maths file somewhere...
 */

class SDLHost : public AppHost
{
	private:
		bool _running;
		RenderSDL* _renderSdl;
		SDL_Window* _window;
		int _mapWidth;
		int _mapHeight;

		bool HandleEvents();
		void Test();
	public:
		SDLHost();
		virtual ~SDLHost();

		bool Init(int argc, char** argv);
		void Exec();
		void Quit();
};

#endif