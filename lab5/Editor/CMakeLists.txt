add_executable(Editor
               main.cpp
               Document/IDocument.h
               Image/IImage.h
               Paragraph/IParagraph.h
               DocumentItem/CDocumentItem.cpp
               DocumentItem/CDocumentItem.h
               DocumentItem/CConstDocumentItem.cpp
               DocumentItem/CConstDocumentItem.h
               Command/ICommand.h
               Command/AbstractCommand/CAbstractCommand.cpp
               Command/AbstractCommand/CAbstractCommand.h
               Document/CDocument.cpp
               Document/CDocument.h
               Image/CImage.cpp
               Image/CImage.h
               Paragraph/CParagraph.cpp
               Paragraph/CParagraph.h
               Command/SetParagraphTextCommand/CSetParagraphTextCommand.cpp
               Command/SetParagraphTextCommand/CSetParagraphTextCommand.h Command/ChangeDocumentTitleCommand/CChangeDocumentTitleCommand.cpp Command/ChangeDocumentTitleCommand/CChangeDocumentTitleCommand.h Command/ResizeImageCommand/CResizeImageCommand.cpp Command/ResizeImageCommand/CResizeImageCommand.h History/CHistory.cpp History/CHistory.h Editor/CEditor.cpp Editor/CEditor.h)

add_subdirectory(tests)
