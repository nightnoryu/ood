add_executable(Transform
               main.cpp
               OutputDataStream/IOutputDataStream.h
               OutputDataStream/FileOutputStream/CFileOutputStream.cpp
               OutputDataStream/FileOutputStream/CFileOutputStream.h
               OutputDataStream/MemoryOutputStream/CMemoryOutputStream.cpp
               OutputDataStream/MemoryOutputStream/CMemoryOutputStream.h
               InputDataStream/IInputDataStream.h
               OutputDataStreamDecorator/Encryption/EncryptingOutputDataStream/CEncryptingOutputStream.cpp
               OutputDataStreamDecorator/Encryption/EncryptingOutputDataStream/CEncryptingOutputStream.h OutputDataStreamDecorator/Encryption/DecryptingOutputStream/CDecryptingOutputStream.cpp OutputDataStreamDecorator/Encryption/DecryptingOutputStream/CDecryptingOutputStream.h OutputDataStreamDecorator/Compression/CompressingOutputStream/CCompressingOutputStream.cpp OutputDataStreamDecorator/Compression/CompressingOutputStream/CCompressingOutputStream.h OutputDataStreamDecorator/Compression/DecompressingOutputStream/CDecompressingOutputStream.cpp OutputDataStreamDecorator/Compression/DecompressingOutputStream/CDecompressingOutputStream.h)
