#include "BlockDrawingTool.h"

#include <gdkmm/general.h> // For Gdk::Cairo::set_source_rgba.

#include "DrawingContextInfo.h"

namespace tetrisgui {

BlockDrawingTool::BlockDrawingTool(Gdk::RGBA fill_colour, Gdk::RGBA line_colour,
                     double line_width)
  : m_fill_colour(fill_colour), m_line_colour(line_colour),
    m_line_width(line_width)
{
  //ctor
}

BlockDrawingTool::~BlockDrawingTool()
{
  //dtor
}

BlockDrawingTool::BlockDrawingTool(const BlockDrawingTool& other)
  : m_fill_colour(other.m_fill_colour), m_line_colour(other.m_line_colour),
    m_line_width(other.m_line_width)
{
  //copy ctor
}

BlockDrawingTool::BlockDrawingTool(BlockDrawingTool&& other)
  : m_fill_colour(other.m_fill_colour), m_line_colour(other.m_line_colour),
    m_line_width(other.m_line_width)
{
  // Move constructor-
}

void BlockDrawingTool::draw(tetris::DrawingContextInfo& dci) {
  const Cairo::RefPtr<Cairo::Context>& cr = dci.cr;
  cr->rectangle(0, 0, 1, 1);

  Gdk::Cairo::set_source_rgba(cr, m_fill_colour);
  cr->fill_preserve();

  Gdk::Cairo::set_source_rgba(cr, m_line_colour);
  cr->set_line_width(m_line_width);
  cr->stroke();
}

std::shared_ptr<tetris::DrawingTool> BlockDrawingTool::copy(
              const tetris::Drawable& parent __attribute__((unused))) const {
  // There is no parent, so we only return a copy.
  return std::make_shared<BlockDrawingTool>(*this);
}

} // namespace tetrisgui.
