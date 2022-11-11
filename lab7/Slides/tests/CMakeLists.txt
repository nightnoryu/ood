add_executable(SlidesTest
               Slides.test.cpp
               ../Common/App/ICanvas.h
               ../Common/Infrastructure/SVG/CCanvas.cpp
               ../Common/Infrastructure/SVG/CCanvas.h
               ../Shapes/ShapeTypes.h
               ../Common/App/IDrawable.h
               ../Slide/IShape.h
               ../Shapes/Shape/CShape.cpp
               ../Shapes/Shape/CShape.h
               ../Shapes/Rectangle/CRectangle.cpp
               ../Shapes/Rectangle/CRectangle.h
               ../Shapes/Ellipse/CEllipse.cpp
               ../Shapes/Ellipse/CEllipse.h
               ../Shapes/Triangle/CTriangle.cpp
               ../Shapes/Triangle/CTriangle.h
               ../Shapes/IStyle.h
               ../Shapes/IOutlineStyle.h
               ../Styles/CStyleImpl.h
               ../Styles/FillStyle/CFillStyle.h
               ../Styles/OutlineStyle/COutlineStyle.cpp
               ../Styles/OutlineStyle/COutlineStyle.h
               ../Styles/GroupStyles/CGroupStyleImpl.h
               ../Styles/GroupStyles/GroupFillStyle/CGroupFillStyle.h
               ../Styles/GroupStyles/GroupOutlineStyle/CGroupOutlineStyle.cpp
               ../Styles/GroupStyles/GroupOutlineStyle/CGroupOutlineStyle.h
               ../ShapeGroup/IShapeGroup.h
               ../ShapeGroup/CShapeGroup.cpp
               ../ShapeGroup/CShapeGroup.h
               ../Slide/ISlide.h
               ../ShapeCollection/IShapeCollection.h
               ../Slide/Slide/CSlide.cpp
               ../Slide/Slide/CSlide.h
               ../ShapeCollection/CShapeCollection.h
               ../ShapeCollection/CShapeCollectionImpl.h)

target_link_libraries(SlidesTest PUBLIC catch2 fakeit)
add_test(NAME SlidesTest COMMAND SlidesTest)
