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

#include <iostream>
#include <gdkmm/rgba.h>
#include <gdkmm/rectangle.h>
#include <gtkmm/window.h>
#include <gtkmm/aspectframe.h>
#include <gtkmm/builder.h>
#include <gtkmm/drawingarea.h>
#include <glibmm/fileutils.h>
#include <glibmm/markup.h>

#include "BasicBlock.h"
#include "BasicBoard.h"
#include "DefaultGame.h"
#include "DefaultGameBoard.h"
#include "Shape.h"
#include "TetrominoO.h"
#include "TetrominoT.h"

#include "TetrisCanvas.h"
#include "BlockDrawingTool.h"
#include "ShapeDrawingTool.h"
#include "BoardDrawingTool.h"
#include "GameBoardDrawingTool.h"
#include "GameDrawingTool.h"

using namespace std;
using namespace tetrisgui;
using namespace tetris;

shared_ptr<Game> createGame(int height, int width) {
  shared_ptr<Block> block = make_shared<BasicBlock>();
  block->setDrawingTool(make_shared<BlockDrawingTool>(Gdk::RGBA("yellow"), Gdk::RGBA("blue"), 0.2));

  if (block->getDrawingTool() == nullptr) {
    cout << "Null pointer in drawing tool.\n";
  }

  shared_ptr<TetrominoO> tO = make_shared<TetrominoO>(block);
  tO->setDrawingTool(make_shared<ShapeDrawingTool>(*tO));
  shared_ptr<TetrominoT> tT = make_shared<TetrominoT>(block);
  tT->setDrawingTool(make_shared<ShapeDrawingTool>(*tT));
  vector<shared_ptr<Shape>> shapes {tO, tT};

  if (shapes[0]->getBlocks()[0]->getDrawingTool() == nullptr) {
    cout << "Null pointer in drawing tool.\n";
  }

  shared_ptr<Board> board = make_shared<BasicBoard>(height, width);
  board->setDrawingTool(make_shared<BoardDrawingTool>(*board, Gdk::RGBA("gray")));

  shared_ptr<GameBoard> game_board = make_shared<DefaultGameBoard>(board);
  game_board->setDrawingTool(make_shared<GameBoardDrawingTool>(*game_board));

  shared_ptr<Game> game = make_shared<DefaultGame>(game_board, shapes);
  game->setDrawingTool(make_shared<GameDrawingTool>(*game));

  game->newGame();
  game->drop();
  game->advance();

  return game;
}

void check() {
  shared_ptr<Block> block = make_shared<BasicBlock>();
  block->setDrawingTool(make_shared<BlockDrawingTool>(Gdk::RGBA("yellow"), Gdk::RGBA("blue"), 0.2));

  shared_ptr<TetrominoO> tO = make_shared<TetrominoO>(block);
  tO->setDrawingTool(make_shared<ShapeDrawingTool>(*tO));

  if (tO->getDrawingTool() == nullptr) {
    cerr << "Null in check original.\n";
  }

  shared_ptr<Shape> tOc = tO->clone();
  if (tOc->getDrawingTool() == nullptr) {
    cerr << "Null in check clone.\n";
  }
}

int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
  cerr << "Application created.\n";
  //Load the GtkBuilder file and instantiate its widgets:
  auto refBuilder = Gtk::Builder::create();
  try
  {
    refBuilder->add_from_file("Glade/main_ui.glade");
  }
  catch(const Glib::FileError& ex)
  {
    std::cerr << "FileError: " << ex.what() << std::endl;
    return 1;
  }
  catch(const Glib::MarkupError& ex)
  {
    std::cerr << "MarkupError: " << ex.what() << std::endl;
    return 1;
  }
  catch(const Gtk::BuilderError& ex)
  {
    std::cerr << "BuilderError: " << ex.what() << std::endl;
    return 1;
  }

  Gtk::Window* window;
  Gtk::AspectFrame* aspect_frame;
  TetrisCanvas* tc;
  refBuilder->get_widget("window1", window);
  refBuilder->get_widget("aspectframe1", aspect_frame);
  refBuilder->get_widget_derived("TetrisCanvas", tc);

  double height = 15;
  double width = 10;
  aspect_frame->property_ratio().set_value(width/height);

  check();

  shared_ptr<Game> game = createGame(height, width);

  tc->setGame(game);

  //shared_ptr<DrawingTool> dt = game->getGameBoard()->getCurrentShape()->getDrawingTool();
  //cerr << "Dt == nullptr: " << (dt == nullptr) << ".\n";

//  Gdk::Rectangle r(0, 0, tc->get_allocation().get_width(),
//          tc->get_allocation().get_height());
//  window->invalidate_rect(r, false);

  if (window) {
    return app->run(*window);
  }
}
