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

#ifndef TETRISCANVAS_H
#define TETRISCANVAS_H

#include <glibmm/dispatcher.h>
#include <gtkmm/builder.h>
#include <gtkmm/drawingarea.h>

#include <GameFlow.h>

#include <memory>
#include <thread>

namespace tetrisgui {

/**
 * A Gtk::DrawingArea that is associated with a \c tetris::Game object.
 * The canvas' \c on_draw method draws the \c tetris::Game object.
 */
class TetrisCanvas : public Gtk::DrawingArea
{
  public:
    TetrisCanvas(BaseObjectType* cobject,
                 const Glib::RefPtr<Gtk::Builder>& builder);
    virtual ~TetrisCanvas();

    /**
     * Returns a (smart) pointer to the \c tetris::GameFlow object that is
     * associated with this \c TetrisCanvas.
     *
     * \return A (smart) pointer to the \c tetris::GameFlow object that is
     *         associated with this \c TetrisCanvas.
     */
    std::shared_ptr<tetris::GameFlow> getGameFlow() const;

    /**
     * Sets the \c tetris::GameFlow object that is associated with this
     * \c TetrisCanvas to the one pointed to by \a game.
     *
     * \param game A (smart) pointer that points to the \c tetris::GameFlow
     *        object that will be associated with this \c TetrisCanvas.
     *        If it is a null pointer, an instance of
     *        \c std::invalid_argument is thrown.
     */
    void setGameFlow(std::shared_ptr<tetris::GameFlow> game_flow);

    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

    /**
     * This method can be called by another thread
     * that wants to redraw this \c TetrisCanvas.
     */
    void notify();

    /**
     * Returns the id (as returned by \c std::this_thread::get:id())
     * of the thread that created this \c TetrisCanvas object. It can be used
     * by a thread that wants to redraw this \c TetrisCanvas object to decide
     * whether it needs to use a dispatcher (throw calling \c notify() )
     * to do so or it can safely call \c queue_draw() directly.
     *
     * \return The id (as returned by \c std::this_thread::get:id())
     *         of the thread that created this \c TetrisCanvas object.
     */
    std::thread::id getThreadId() const;
  private:
    bool m_key_signal_handler(GdkEventKey* event);
    bool m_mouse_signal_handler(GdkEventButton* event); // Grabs focus.
  private:
    std::shared_ptr<tetris::GameFlow> m_game_flow;

    Glib::Dispatcher m_dispatcher {};

    // The thread id so that the caller thread of queue_draw can decide
    // whether to directly call queue_draw or to call notify.
    const std::thread::id m_thread_id;
};

} // namespace tetrisgui.

#endif // TETRISCANVAS_H
