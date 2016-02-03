/*
 * Copyright (C) 2016 Daniel Becker <beckerdaniel.dani@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as published
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
  // Copy constructor.
}

BlockDrawingTool::BlockDrawingTool(BlockDrawingTool&& other)
  : m_fill_colour(other.m_fill_colour), m_line_colour(other.m_line_colour),
    m_line_width(other.m_line_width)
{
  // Move constructor-
}

void BlockDrawingTool::draw(const tetris::Block& block __attribute__((unused)),
                            tetris::DrawingContextInfo& dci) {
  const Cairo::RefPtr<Cairo::Context>& cr = dci.cr;
  cr->rectangle(0, 0, 1, 1);

  Gdk::Cairo::set_source_rgba(cr, m_fill_colour);
  cr->fill_preserve();

  Gdk::Cairo::set_source_rgba(cr, m_line_colour);
  cr->set_line_width(m_line_width);
  cr->stroke();
}

std::shared_ptr<tetris::DrawingTool<tetris::Block>>
BlockDrawingTool::copy() const {
  return std::make_shared<BlockDrawingTool>(*this);
}

} // namespace tetrisgui.
