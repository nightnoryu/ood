#include "CTransformer.h"
#include "../InputDataStream/FileInputStream/CFileInputStream.h"
#include "../InputDataStreamDecorator/DecompressingInputStream/CDecompressingInputStream.h"
#include "../InputDataStreamDecorator/DecryptingInputStream/CDecryptingInputStream.h"
#include "../OutputDataStream/FileOutputStream/CFileOutputStream.h"
#include "../OutputDataStreamDecorator/EncryptingOutputStream/CEncryptingOutputStream.h"

CTransformer::CTransformer(Args const& args)
	: m_input(std::make_unique<CFileInputStream>(args.inputFilename))
	, m_output(std::make_unique<CFileOutputStream>(args.outputFilename))
{
	AddDecorators(args);
}

void CTransformer::Transform()
{
	while (!m_input->IsEOF())
	{
		m_output->WriteByte(m_input->ReadByte());
	}
}

void CTransformer::AddDecorators(Args const& args)
{
	for (auto const key : args.encryptionKeys)
	{
		m_output = std::move(m_output) << MakeDecorator<CEncryptingOutputStream>(key);
	}

	for (auto const key : args.decryptionKeys)
	{
		m_input = std::move(m_input) << MakeDecorator<CDecryptingInputStream>(key);
	}

	if (args.compress)
	{
		m_output = std::move(m_output) << MakeDecorator<CCompressingOutputStream>();
	}

	if (args.decompress)
	{
		m_input = std::move(m_input) << MakeDecorator<CDecompressingInputStream>();
	}
}
