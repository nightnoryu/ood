add_executable(Designer
               main.cpp
               Canvas/ICanvas.h
               Canvas/CCanvas.cpp
               Canvas/CCanvas.h
               PictureDraft/CPictureDraft.cpp
               PictureDraft/CPictureDraft.h
               Designer/IDesigner.h
               Designer/CDesigner.cpp
               Designer/CDesigner.h
               Painter/CPainter.cpp
               Painter/CPainter.h
               ShapeFactory/IShapeFactory.h
               ShapeFactory/CShapeFactory.cpp
               ShapeFactory/CShapeFactory.h
               Shapes/ShapeTypes.h
               Shapes/CShape.cpp
               Shapes/CShape.h
               Shapes/Ellipse/CEllipse.cpp
               Shapes/Ellipse/CEllipse.h
               Shapes/Rectangle/CRectangle.cpp
               Shapes/Rectangle/CRectangle.h
               Shapes/RegularPolygon/CRegularPolygon.cpp
               Shapes/RegularPolygon/CRegularPolygon.h
               Shapes/Triangle/CTriangle.cpp
               Shapes/Triangle/CTriangle.h)

set(SFML_STATIC_LIBRARIES TRUE)
find_package(Freetype REQUIRED)
find_package(JPEG REQUIRED)
find_package(SFML 2 COMPONENTS window graphics system REQUIRED)

target_compile_definitions(Designer PRIVATE SFML_STATIC)

target_link_libraries(Designer ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} ${JPEG_LIBRARIES} ${FREETYPE_LIBRARIES})
target_include_directories(Designer PUBLIC ${SFML_INCLUDE_DIR})
