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

#include "TetrisCanvas.h"

#include <stdexcept>

#include <GameBoard.h>
#include <Board.h>


#include "DrawingContextInfo.h"
#include "BlockDrawingTool.h" ///////////////////////////////////////////////////////////////////////
#include <cairomm/matrix.h>
#include <iostream>

namespace tetrisgui {

TetrisCanvas::TetrisCanvas(BaseObjectType* cobject,
                           const Glib::RefPtr<Gtk::Builder>& builder
                              __attribute__((unused))
                          )
  : Gtk::DrawingArea(cobject)
{
  //ctor
}

TetrisCanvas::~TetrisCanvas()
{
  //dtor
}

std::shared_ptr<tetris::Game> TetrisCanvas::getGame() const {
  return m_game;
}

void TetrisCanvas::setGame(std::shared_ptr<tetris::Game> game) {
  if (game == nullptr) {
    throw std::invalid_argument("A null game is not allowed.");
  }
  m_game = game;
}


bool TetrisCanvas::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
  if (m_game == nullptr) {
    throw std::invalid_argument("The current game is null.");
  }

  // Determining scaling (we assume that we are in an AspectFrame).
  double scale = static_cast<double>(get_allocation().get_width()) /
            static_cast<double>(m_game->getGameBoard()->getBoard()->getWidth());
  cairo_matrix_t matrix;
  cr->get_matrix(matrix);
  std::cerr << "TetrisCanvas0: \nxx = " << matrix.xx << ", xy = " << matrix.xy << ", x0 = " << matrix.x0
            << ", \nyx = " << matrix.yx << ", yy = " << matrix.yy << ", y0 = " << matrix.y0 << ".\n\n";


  cr->scale(scale, scale);

  cr->get_matrix(matrix);
  std::cerr << "TetrisCanvas1: \nxx = " << matrix.xx << ", xy = " << matrix.xy << ", x0 = " << matrix.x0
            << ", \nyx = " << matrix.yx << ", yy = " << matrix.yy << ", y0 = " << matrix.y0 << ".\n\n";

  tetris::DrawingContextInfo dci(cr);
  m_game->draw(dci);

  dci.cr->get_matrix(matrix);
  std::cerr << "TetrisCanvas2: \nxx = " << matrix.xx << ", xy = " << matrix.xy << ", x0 = " << matrix.x0
            << ", \nyx = " << matrix.yx << ", yy = " << matrix.yy << ", y0 = " << matrix.y0 << ".\n\n";


  //auto b = BlockDrawingTool(Gdk::RGBA("yellow"), Gdk::RGBA("blue"), 0.2);
  //cr->scale(scale, scale);
  //b.draw(dci);

  return true;
}

} // namespace tetrisgui.
