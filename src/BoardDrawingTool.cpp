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

#include "BoardDrawingTool.h"

#include <gdkmm/general.h>

#include <Block.h>

#include "DrawingContextInfo.h"

namespace tetrisgui {

BoardDrawingTool::BoardDrawingTool(Gdk::RGBA background_colour)
  : m_background_colour(background_colour)
{
  //ctor
}

BoardDrawingTool::~BoardDrawingTool()
{
  //dtor
}

BoardDrawingTool::BoardDrawingTool(const BoardDrawingTool& other)
  : BoardDrawingTool(other.m_background_colour)
{
  // Copy constructor.
}

BoardDrawingTool::BoardDrawingTool(BoardDrawingTool&& other)
  : BoardDrawingTool(other.m_background_colour)
{
  // Move constructor.
}

void BoardDrawingTool::draw(const tetris::Board& board,
                            tetris::DrawingContextInfo& dci) {
  const Cairo::RefPtr<Cairo::Context>& cr = dci.cr;
  int height = board.getHeight();
  int width = board.getWidth();

  // Painting the background.
  Gdk::Cairo::set_source_rgba(cr, m_background_colour);
  cr->rectangle(0, 0, width, height);
  cr->fill();

  // Painting the filled blocks.
  for (int vertical = 0; vertical < height; ++vertical) {
    for (int horizontal = 0; horizontal < width; ++horizontal) {
      std::shared_ptr<const tetris::Block> block = board.get(vertical,
                                                             horizontal);
      if (block != nullptr) {
        cr->save();

        cr->translate(horizontal, vertical);
        block->draw(dci);

        cr->restore();
      }
    }
  }
}

std::shared_ptr<tetris::DrawingTool<tetris::Board>>
BoardDrawingTool::copy() const {
  return std::make_shared<BoardDrawingTool>(this->m_background_colour);
}

} // namespace tetrisgui.
