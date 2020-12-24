//********************************************************************************************************
//�ļ���:                                       TestQuestion.cpp
//�汾:                                         1.0
//Ŀ�ļ���Ҫ����:                               ����������Ļ���
//��������:                                     2020.9.4
//�޸�����:                                      
//����:                                         ���ɺ�
//�޸���:                                         
//��ϵ��ʽ:
//********************************************************************************************************
#include "pch.h"
#include "TestQuestion.h"

IMPLEMENT_SERIAL(TestQuestion,CObject,1)

TestQuestion::TestQuestion()
	:m_strTopic(_T("")),
	m_strAnswer(_T("")),
	m_nScore(0),
	m_nType(0)
{

}

TestQuestion::~TestQuestion()
{

}

void TestQuestion::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
		ar << m_strTopic << m_strAnswer << m_nScore << m_nType;
	}
	else
	{	// loading code
		ar >> m_strTopic >> m_strAnswer >> m_nScore >> m_nType;
	}
}


int TestQuestion::MarkPaper(const CString ans)
{
	// TODO: �ڴ˴����ʵ�ִ���.

	return 0;
}
