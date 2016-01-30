#ifndef TETRIS_DRAWINGCONTEXTINFO_H
#define TETRIS_DRAWINGCONTEXTINFO_H

#include <cairomm/context.h>

namespace tetris {

/**
 * This class is the definition and implementation of the class forward
 * declared in the tetris library. It contains a Cairo context object that
 * should be used when drawing the objects of the tetris library.
 */
class DrawingContextInfo
{
  public:
    DrawingContextInfo(Cairo::RefPtr<Cairo::Context> cr);
    virtual ~DrawingContextInfo();
    /**
     * A Cairo context object that should be used when drawing the objects of
     * the tetris library.
     */
    const Cairo::RefPtr<Cairo::Context> cr;
};

} // namespace tetris

#endif // TETRIS_DRAWINGCONTEXTINFO_H
