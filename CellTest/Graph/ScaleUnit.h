#ifndef SCALEUNIT_H
#define SCALEUNIT_H

namespace Graph
{

	const short PixelScaleX = 1;
	const short PixelScaleY = 1;

	//you can treat this class as any x,y position in the world
	//it can be converted to pixels by calling x_s() and y_s()
	class ScaleUnit
	{
		private:
			short _xUnscaled;
			short _yUnscaled;

		public:
			ScaleUnit()
			{
				_xUnscaled = _yUnscaled = 0;
			}

			ScaleUnit(short x_unscaled, short y_unscaled)
			{
				_xUnscaled = x_unscaled;
				_yUnscaled = y_unscaled;
			}

			//scaled unit, i.e. the screenspace position (pixels)
			short GetX_Scaled() { return _xUnscaled * PixelScaleX; }
			short GetY_Scaled() { return _yUnscaled * PixelScaleY; }

			//unscaled unit, i.e. the worldspace position
			short GetX() { return _xUnscaled; }
			short GetY() { return _yUnscaled; }

			//set the exact pixel position on the screen
			short SetX_Scaled(short x_scaled) { _xUnscaled = x_scaled / PixelScaleX; }
			short SetY_Scaled(short y_scaled) { _yUnscaled = y_scaled / PixelScaleY; }

			//set the simple, worldspace position
			short SetX(short x_unscaled) { _xUnscaled = x_unscaled; }
			short SetY(short y_unscaled) { _yUnscaled = y_unscaled; }
	};
}

#endif
