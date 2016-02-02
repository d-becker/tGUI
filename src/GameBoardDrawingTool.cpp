#include "GameBoardDrawingTool.h"

#include <Shape.h>

#include "DrawingContextInfo.h"

#include <iostream>////////////////////////////////////////////////////////////////////////////////

namespace tetrisgui {

GameBoardDrawingTool::GameBoardDrawingTool(const tetris::GameBoard& game_board)
  : m_game_board(game_board)
{
  //ctor
}

GameBoardDrawingTool::~GameBoardDrawingTool()
{
  //dtor
}

void GameBoardDrawingTool::draw(tetris::DrawingContextInfo& dci) {
  const Cairo::RefPtr<Cairo::Context>& cr = dci.cr;
  //
  cairo_matrix_t matrix;
  cr->get_matrix(matrix);
  std::cerr << "GameBoard0: \nxx = " << matrix.xx << ", xy = " << matrix.xy << ", x0 = " << matrix.x0
            << ", \nyx = " << matrix.yx << ", yy = " << matrix.yy << ", y0 = " << matrix.y0 << ".\n\n";
  //
  cr->save();
  m_game_board.getBoard()->draw(dci);

  cr->get_matrix(matrix);
  std::cerr << "GameBoard1 (after drawing board): \nxx = " << matrix.xx << ", xy = " << matrix.xy << ", x0 = " << matrix.x0
            << ", \nyx = " << matrix.yx << ", yy = " << matrix.yy << ", y0 = " << matrix.y0 << ".\n\n";

  cr->restore();
  cr->save();

  cr->get_matrix(matrix);
  std::cerr << "GameBoard2 (after restoring): \nxx = " << matrix.xx << ", xy = " << matrix.xy << ", x0 = " << matrix.x0
            << ", \nyx = " << matrix.yx << ", yy = " << matrix.yy << ", y0 = " << matrix.y0 << ".\n\n";

  tetris::Coords c = m_game_board.getCurrentShapePosition();
  cr->translate(c.getHorizontal(), c.getVertical());

  cr->get_matrix(matrix);
  std::cerr << "GameBoard3 (translation): \nxx = " << matrix.xx << ", xy = " << matrix.xy << ", x0 = " << matrix.x0
            << ", \nyx = " << matrix.yx << ", yy = " << matrix.yy << ", y0 = " << matrix.y0 << ".\n\n";

  const std::shared_ptr<const tetris::Shape>& current_shape
                                    = m_game_board.getCurrentShape();
  if (current_shape != nullptr) {
    current_shape->draw(dci);
  }
  cr->get_matrix(matrix);
  std::cerr << "GameBoard4 (after drawing shape): \nxx = " << matrix.xx << ", xy = " << matrix.xy << ", x0 = " << matrix.x0
            << ", \nyx = " << matrix.yx << ", yy = " << matrix.yy << ", y0 = " << matrix.y0 << ".\n\n";

  cr->restore();

  dci.cr->get_matrix(matrix);
  std::cerr << "GameBoard5 (before returning): \nxx = " << matrix.xx << ", xy = " << matrix.xy << "x0 = " << matrix.x0
            << ", \nyx = " << matrix.yx << ", yy = " << matrix.yy << "y0 = " << matrix.y0 << ".\n\n";
}

std::shared_ptr<tetris::DrawingTool> GameBoardDrawingTool::copy(
                              const tetris::Drawable& parent) const {
  // Assuming 'parent' is a 'GameBoard', as the contract states.
  // Otherwise, it's undefined behaviour. We could also use a dynamic cast.
  const tetris::GameBoard& parent_game_board
                              = static_cast<const tetris::GameBoard&>(parent);
  return std::make_shared<GameBoardDrawingTool>(parent_game_board);
}

} // namespace tetrisgui.
