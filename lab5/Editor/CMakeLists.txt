add_executable(Editor
               main.cpp
               Document/IDocument.h
               Image/IImage.h
               Paragraph/IParagraph.h
               DocumentItem/CDocumentItem.cpp
               DocumentItem/CDocumentItem.h
               DocumentItem/CConstDocumentItem.cpp
               DocumentItem/CConstDocumentItem.h
               Command/ICommand.h Command/AbstractCommand/CAbstractCommand.cpp Command/AbstractCommand/CAbstractCommand.h Document/CDocument.cpp Document/CDocument.h Saver/ISaver.h Saver/CHtmlSaver.cpp Saver/CHtmlSaver.h)
