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

#include "GtkGameFlow.h"

#include <gdk/gdkkeysyms.h>

namespace tetrisgui {

GtkGameFlow::GtkGameFlow(std::shared_ptr<TetrisCanvas> tetris_canvas,
                         std::shared_ptr<tetris::Game> game,
                         unsigned int interval)
  : BasicGameFlow(game, interval), m_tetris_canvas(tetris_canvas)
{
  //ctor

  // Binding input.
  bindInput(GDK_KEY_Down, "move_down");
  bindInput(GDK_KEY_Left, "move_left");
  bindInput(GDK_KEY_Right, "move_right");
  bindInput(GDK_KEY_a, "rotate_left");
  bindInput(GDK_KEY_s, "rotate_right");
  bindInput(GDK_KEY_space, "drop");
  bindInput(GDK_KEY_p, "toggle_paused");
  bindInput(GDK_KEY_r, "resume");///////////////////////////////////////////////////////////
}

GtkGameFlow::GtkGameFlow(std::shared_ptr<TetrisCanvas> tetris_canvas,
                         std::shared_ptr<tetris::Game> game)
  : BasicGameFlow(game), m_tetris_canvas(tetris_canvas)
{
  //ctor
}

GtkGameFlow::~GtkGameFlow()
{
  //dtor
}

void GtkGameFlow::draw() {
  if (std::this_thread::get_id() == m_tetris_canvas->getThreadId()) {
    m_tetris_canvas->queue_draw();
  } else {
    m_tetris_canvas->notify();
  }
}

} // namespace tetrisgui.
