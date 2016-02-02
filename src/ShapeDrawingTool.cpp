#include "ShapeDrawingTool.h"

#include <cairomm/context.h>

#include <Block.h>

#include "DrawingContextInfo.h"

#include <iostream> //////////////////////////////////////////////////////////////////////////////////
#include <typeinfo> //////////////////////////////////////////////////////////////////////////////////

namespace tetrisgui {

ShapeDrawingTool::ShapeDrawingTool(const tetris::Shape& shape)
  : m_shape(shape)
{
  //ctor
}

ShapeDrawingTool::~ShapeDrawingTool()
{
  //dtor
}

void ShapeDrawingTool::draw(tetris::DrawingContextInfo& dci) {
  const Cairo::RefPtr<Cairo::Context>& cr = dci.cr;
  std::vector<tetris::Coords> block_positions = m_shape.getBlockPositions();

  for (const tetris::Coords& c : block_positions) {
    std::shared_ptr<tetris::Block> block = m_shape.get(c);
    if (block != nullptr) {
      cr->save();

      cairo_matrix_t matrix;
      cr->get_matrix(matrix);
      std::cerr << "Shape drawing: \nxx = " << matrix.xx << ", xy = " << matrix.xy << ", x0 = " << matrix.x0
                << ", \nyx = " << matrix.yx << ", yy = " << matrix.yy << ", y0 = " << matrix.y0 << ".\n\n";

      cr->translate(c.getHorizontal(), c.getVertical());
      block->draw(dci);
      cr->restore();
    }
  }
}

std::shared_ptr<tetris::DrawingTool> ShapeDrawingTool::copy(
                              const tetris::Drawable& parent) const {
  // Assuming 'parent' is a 'Shape', as the contract states.
  // Otherwise, it's undefined behaviour. We could also use a dynamic cast.
  std::cerr << "Typeid: " << typeid(parent).name() << ".\n";
  const tetris::Shape& parent_shape = dynamic_cast<const tetris::Shape&>(parent);///////////////////////////////
  return std::make_shared<ShapeDrawingTool>(parent_shape);
}

} // namespace tetrisgui.
