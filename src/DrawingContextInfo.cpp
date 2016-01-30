#include "DrawingContextInfo.h"

namespace tetris {

DrawingContextInfo::DrawingContextInfo(Cairo::RefPtr<Cairo::Context> p_cr)
  : cr(p_cr)
{
  //ctor
}

DrawingContextInfo::~DrawingContextInfo()
{
  //dtor
}

} // namespace tetris
