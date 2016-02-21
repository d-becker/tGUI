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

#include "AdvancedGameBoardDrawingTool.h"

#include <Shape.h>

#include "DrawingContextInfo.h"

namespace tetrisgui {

AdvancedGameBoardDrawingTool::AdvancedGameBoardDrawingTool()
  : AdvancedGameBoardDrawingTool(true)
{
  //ctor
}

AdvancedGameBoardDrawingTool::AdvancedGameBoardDrawingTool(
                                                bool show_fall_place,
                                                double alpha)
  : tetrisgui::GameBoardDrawingTool(),
    m_show_where_block_falls(show_fall_place),
    m_alpha_of_falling_place(alpha)
{
  //ctor
}

AdvancedGameBoardDrawingTool::~AdvancedGameBoardDrawingTool()
{
  //dtor
}

AdvancedGameBoardDrawingTool::AdvancedGameBoardDrawingTool(
                                const AdvancedGameBoardDrawingTool& other)
  : tetrisgui::GameBoardDrawingTool(other),
    m_show_where_block_falls(other.m_show_where_block_falls)
{
  // Copy ctor.
}

AdvancedGameBoardDrawingTool::AdvancedGameBoardDrawingTool(
                                AdvancedGameBoardDrawingTool&& other)
  : tetrisgui::GameBoardDrawingTool(other),
    m_show_where_block_falls(other.m_show_where_block_falls)
{
  // Move ctor.
}

bool AdvancedGameBoardDrawingTool::getShowFallingPlace() const {
  return m_show_where_block_falls;
}

void AdvancedGameBoardDrawingTool::setShowFallingPlace(bool show_fall_place) {
  m_show_where_block_falls = show_fall_place;
}

double AdvancedGameBoardDrawingTool::getAlphaOfFallingPlace() const {
  return m_alpha_of_falling_place;
}

void AdvancedGameBoardDrawingTool::setAlphaOfFallingPlace(double alpha) {
  m_alpha_of_falling_place = alpha;
}

void AdvancedGameBoardDrawingTool::draw(const tetris::GameBoard& game_board,
                                   tetris::DrawingContextInfo& dci) {
  tetrisgui::GameBoardDrawingTool::draw(game_board, dci);

  if (!m_show_where_block_falls) {
    return;
  }

  const Cairo::RefPtr<Cairo::Context>& cr = dci.cr;



  const std::shared_ptr<const tetris::Shape>& current_shape
                                    = game_board.getCurrentShape();
  if (current_shape != nullptr) {
    cr->push_group();
    tetris::Coords c = game_board.whereWouldLand();
    cr->translate(c.getHorizontal(), c.getVertical());
    current_shape->draw(dci);
    cr->pop_group_to_source();
    cr->paint_with_alpha(m_alpha_of_falling_place);
  }

}

std::shared_ptr<tetris::DrawingTool<tetris::GameBoard>>
AdvancedGameBoardDrawingTool::copy() const {
  return std::make_shared<AdvancedGameBoardDrawingTool>(*this);
}

} // namespace tetrisgui.
