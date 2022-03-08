#include "Rect.h"


bool Rect::intersects(Circle acircle) {
  Rect arect = {acircle.x-acircle.r,acircle.y-acircle.r,acircle.r*2+1,acircle.r*2+1};
  return intersects(arect);
}
bool Rect::intersects(Rect arect)
{
	bool ret = false;
	for(int i = arect.x; i <= arect.x+arect.w; i++) {
		for(int j = arect.y; j <= arect.y+arect.w; j++) {
			if(includes(Point{i,j})) {
				ret = true;
				break;
			}
		}
		if(ret == true) {
			break;
		}
	}
	return ret;
}

bool Rect::intersects(Line aline)
{
	bool ret = false;
	for(int i = aline.a.x; i <= aline.b.x; i++) {
		for(int j = aline.a.y; j <= aline.b.y; j++) {
			if(includes(Point{i,j})) {
				ret = true;
				break;
			}
		}
		if(ret == true) {
			break;
		}
	}
	return ret;
}

bool Rect::includes(Point apoint)
{
	if(apoint.x >= x && apoint.y >= y && apoint.x <= x+w && apoint.y <= y+h) {
		return true;
	}
	else {
		return false;
	}
}

