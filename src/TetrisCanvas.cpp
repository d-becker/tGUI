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
  : Gtk::DrawingArea(cobject), m_thread_id(std::this_thread::get_id())
{
  //ctor
  set_can_focus(true);
  grab_focus();
  add_events(Gdk::KEY_PRESS_MASK | Gdk::KEY_RELEASE_MASK);
  add_events(Gdk::BUTTON_PRESS_MASK | Gdk::BUTTON_RELEASE_MASK);

  signal_key_press_event().connect(sigc::mem_fun(
                                     *this,
                                     &TetrisCanvas::m_key_signal_handler),
                                     false );
  signal_button_press_event().connect(sigc::mem_fun(
                                    *this,
                                    &TetrisCanvas::m_mouse_signal_handler));

  m_dispatcher.connect(sigc::mem_fun(*this, &TetrisCanvas::queue_draw));
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

void TetrisCanvas::notify() {
  m_dispatcher.emit();
}

std::thread::id TetrisCanvas::getThreadId() const {
  return m_thread_id;
}

// Private methods.
bool TetrisCanvas::m_key_signal_handler(GdkEventKey* event) {
  m_game_flow->processInput(event->keyval);
  return true;
}

bool TetrisCanvas::m_mouse_signal_handler(GdkEventButton* event
                                          __attribute__((unused))) {
  grab_focus();
  return true;
}

} // namespace tetrisgui.
