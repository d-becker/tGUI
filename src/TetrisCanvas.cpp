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

#include <functional>
#include <stdexcept>

#include <GameBoard.h>
#include <Board.h>


#include "DrawingContextInfo.h"

namespace tetrisgui {

TetrisCanvas::TetrisCanvas(BaseObjectType* cobject,
                           const Glib::RefPtr<Gtk::Builder>& builder
                              __attribute__((unused))
                          )
  : Gtk::DrawingArea(cobject)
{
  //ctor
  set_can_focus(true);
  grab_focus();
  add_events(Gdk::KEY_PRESS_MASK | Gdk::KEY_RELEASE_MASK);

  signal_key_press_event().connect(sigc::mem_fun(*this,
                                                 &TetrisCanvas::signal_handler),
                                                 false );
}

TetrisCanvas::~TetrisCanvas()
{
  //dtor
}

std::shared_ptr<tetris::GameFlow> TetrisCanvas::getGameFlow() const {
  return m_game_flow;
}

void TetrisCanvas::setGameFlow(std::shared_ptr<tetris::GameFlow> game_flow) {
  if (game_flow == nullptr) {
    throw std::invalid_argument("A null GameFlow object is not allowed.");
  }
  m_game_flow = game_flow;
}


bool TetrisCanvas::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
  if (m_game_flow == nullptr) {
    throw std::invalid_argument("The current game is null.");
  }

  std::shared_ptr<const tetris::Game> game = m_game_flow->getGame();

  // Determining scaling (we assume that we are in an AspectFrame).
  double scale = static_cast<double>(get_allocation().get_width()) /
            static_cast<double>(game->getGameBoard()->getBoard()->getWidth());

  cr->scale(scale, scale);

  tetris::DrawingContextInfo dci(cr);
  game->draw(dci);

  return true;
}

// Private methods.
bool TetrisCanvas::signal_handler(GdkEventKey* event) {
  m_game_flow->processInput(event->keyval);
  return true;
}

} // namespace tetrisgui.
