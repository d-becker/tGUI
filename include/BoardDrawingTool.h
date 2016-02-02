#ifndef BOARDDRAWINGTOOL_H
#define BOARDDRAWINGTOOL_H

#include <gdkmm/rgba.h>

#include <Board.h>
#include <Drawing.h>

namespace tetrisgui {

class BoardDrawingTool : public tetris::DrawingTool
{
  public:
    BoardDrawingTool(const tetris::Board& board, Gdk::RGBA background_colour);
    virtual ~BoardDrawingTool();
    BoardDrawingTool(const BoardDrawingTool& other) = default;

    virtual void draw(tetris::DrawingContextInfo& dci) override;
    virtual std::shared_ptr<tetris::DrawingTool> copy(
                              const tetris::Drawable& parent) const override;
  protected:
  private:
    const tetris::Board& m_board;
    Gdk::RGBA m_background_colour;
    //Gdk::RGBA m_line_colour;
    //double m_line_width;
};

} // namespace tetrisgui.

#endif // BOARDDRAWINGTOOL_H
