#ifndef BLOCKDRAWINGTOOL_H
#define BLOCKDRAWINGTOOL_H

#include <gdkmm/rgba.h>

#include <Drawing.h>

namespace tetrisgui {

class BlockDrawingTool : public tetris::DrawingTool
{
  public:
    BlockDrawingTool(Gdk::RGBA fill_colour, Gdk::RGBA line_colour,
                     double line_width);
    virtual ~BlockDrawingTool();
    BlockDrawingTool(const BlockDrawingTool& other);
    BlockDrawingTool(BlockDrawingTool&& other);

    virtual void draw(tetris::DrawingContextInfo& dci) override;
    virtual std::shared_ptr<tetris::DrawingTool> copy(
                              const tetris::Drawable& parent) const override;
  protected:
  private:
    Gdk::RGBA m_fill_colour;
    Gdk::RGBA m_line_colour;
    double m_line_width;
};

} // namespace tetrisgui.

#endif // BLOCKDRAWINGTOOL_H
