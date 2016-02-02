#include "BoardDrawingTool.h"

#include <gdkmm/general.h>

#include "DrawingContextInfo.h"

namespace tetrisgui {

BoardDrawingTool::BoardDrawingTool(const tetris::Board& board,
                                   Gdk::RGBA background_colour)
  : m_board(board), m_background_colour(background_colour)
{
  //ctor
}

BoardDrawingTool::~BoardDrawingTool()
{
  //dtor
}

void BoardDrawingTool::draw(tetris::DrawingContextInfo& dci) {
  const Cairo::RefPtr<Cairo::Context>& cr = dci.cr;
  int height = m_board.getHeight();
  int width = m_board.getWidth();

  Gdk::Cairo::set_source_rgba(cr, m_background_colour);
  cr->rectangle(0, 0, width, height);
  cr->fill();
}

std::shared_ptr<tetris::DrawingTool> BoardDrawingTool::copy(
                              const tetris::Drawable& parent) const {
  // Assuming 'parent' is a 'Board', as the contract states.
  // Otherwise, it's undefined behaviour. We could also use a dynamic cast.
  const tetris::Board& parent_board = static_cast<const tetris::Board&>(parent);
  return std::make_shared<BoardDrawingTool>(parent_board,
                                            this->m_background_colour);
}

} // namespace tetrisgui.
