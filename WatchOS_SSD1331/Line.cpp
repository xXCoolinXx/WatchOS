#include "Line.h"

bool Line::intersects(Circle acircle) {
  return intersects(Rect{acircle.x - acircle.r, acircle.y - acircle.r, acircle.r * 2 + 1, acircle.r * 2 + 1});
}
bool Line::intersects(Rect arect) {
  return arect.intersects(*this);
}



