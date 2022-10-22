add_executable(EditorTest
               Editor.test.cpp
               ../Editor/IDocument.h
               ../DocumentItem/IImage.h
               ../DocumentItem/IParagraph.h
               ../DocumentItem/CDocumentItem.cpp
               ../DocumentItem/CDocumentItem.h
               ../DocumentItem/CConstDocumentItem.cpp
               ../DocumentItem/CConstDocumentItem.h
               ../Command/ICommand.h
               ../Command/AbstractCommand/CAbstractCommand.cpp
               ../Command/AbstractCommand/CAbstractCommand.h
               ../Document/CDocument.cpp
               ../Document/CDocument.h
               ../Image/CImage.cpp
               ../Image/CImage.h
               ../Paragraph/CParagraph.cpp
               ../Paragraph/CParagraph.h
               ../Command/SetParagraphTextCommand/CSetParagraphTextCommand.cpp
               ../Command/SetParagraphTextCommand/CSetParagraphTextCommand.h)

target_link_libraries(EditorTest PUBLIC catch2 fakeit)
add_test(NAME EditorTest COMMAND EditorTest)
