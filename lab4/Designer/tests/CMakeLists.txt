add_executable(DesignerTest
               Designer.test.cpp
               ../Common/App/ICanvas.h
               ../Common/Infrastructure/SVG/CCanvas.cpp
               ../Common/Infrastructure/SVG/CCanvas.h
               ../PictureDraft/CPictureDraft.cpp
               ../PictureDraft/CPictureDraft.h
               ../Client/IDesigner.h
               ../Designer/CDesigner.cpp
               ../Designer/CDesigner.h
               ../Painter/CPainter.cpp
               ../Painter/CPainter.h
               ../Designer/IShapeFactory.h
               ../ShapeFactory/CShapeFactory.cpp
               ../ShapeFactory/CShapeFactory.h
               ../Shapes/ShapeTypes.h
               ../Shapes/CShape.cpp
               ../Shapes/CShape.h
               ../Shapes/Ellipse/CEllipse.cpp
               ../Shapes/Ellipse/CEllipse.h
               ../Shapes/Rectangle/CRectangle.cpp
               ../Shapes/Rectangle/CRectangle.h
               ../Shapes/RegularPolygon/CRegularPolygon.cpp
               ../Shapes/RegularPolygon/CRegularPolygon.h
               ../Shapes/Triangle/CTriangle.cpp
               ../Shapes/Triangle/CTriangle.h)

target_link_libraries(DesignerTest PUBLIC catch2 fakeit)
add_test(NAME DesignerTest COMMAND DesignerTest)
