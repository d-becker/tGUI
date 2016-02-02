#include "GameDrawingTool.h"

#include "DrawingContextInfo.h"

#include <iostream> ///////////////////////////////////////////////////////////////////////////////

namespace tetrisgui {

GameDrawingTool::GameDrawingTool(const tetris::Game& game)
  : m_game(game)
{
  //ctor
}

GameDrawingTool::~GameDrawingTool()
{
  //dtor
}

void GameDrawingTool::draw(tetris::DrawingContextInfo& dci) {
  const Cairo::RefPtr<Cairo::Context>& cr = dci.cr;
  cairo_matrix_t matrix;
  cr->get_matrix(matrix);
  std::cerr << "GameDrawingTool0 (first): \nxx = " << matrix.xx << ", xy = " << matrix.xy << ", x0 = " << matrix.x0
            << ", \nyx = " << matrix.yx << ", yy = " << matrix.yy << ", y0 = " << matrix.y0 << ".\n\n";

  cr->save();

  cr->get_matrix(matrix);
  std::cerr << "GameDrawingTool1 (after saving): \nxx = " << matrix.xx << ", xy = " << matrix.xy << ", x0 = " << matrix.x0
            << ", \nyx = " << matrix.yx << ", yy = " << matrix.yy << ", y0 = " << matrix.y0 << ".\n\n";

  m_game.getGameBoard()->draw(dci);

  cr->get_matrix(matrix);
  std::cerr << "GameDrawingTool2 (after drawing the game board): \nxx = " << matrix.xx << ", xy = " << matrix.xy << ", x0 = " << matrix.x0
            << ", \nyx = " << matrix.yx << ", yy = " << matrix.yy << ", y0 = " << matrix.y0 << ".\n\n";

  cr->restore();

  cr->get_matrix(matrix);
  std::cerr << "GameDrawingTool3 (after restoring): \nxx = " << matrix.xx << ", xy = " << matrix.xy << ", x0 = " << matrix.x0
            << ", \nyx = " << matrix.yx << ", yy = " << matrix.yy << ", y0 = " << matrix.y0 << ".\n\n";
}

std::shared_ptr<tetris::DrawingTool> GameDrawingTool::copy(
                              const tetris::Drawable& parent) const {
  // Assuming 'parent' is a 'Game', as the contract states.
  // Otherwise, it's undefined behaviour. We could also use a dynamic cast.
  const tetris::Game& parent_game
                              = static_cast<const tetris::Game&>(parent);
  return std::make_shared<GameDrawingTool>(parent_game);
}

} // namespace tetrisgui.
