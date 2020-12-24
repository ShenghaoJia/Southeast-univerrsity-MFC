//********************************************************************************************************
//�ļ���:                                       JudgmentQuestion.cpp
//�汾:                                         1.0
//Ŀ�ļ���Ҫ����:                               �ж�����
//��������:                                     2020.9.4
//�޸�����:                                      
//����:                                         ���ɺ�
//�޸���:                                         
//��ϵ��ʽ:
//********************************************************************************************************
#include "pch.h"
#include "JudgmentQuestion.h"

IMPLEMENT_SERIAL(JudgmentQuestion,CObject,1)

JudgmentQuestion::JudgmentQuestion()
{

}

JudgmentQuestion::~JudgmentQuestion()
{

}

void JudgmentQuestion::Serialize(CArchive& ar)//��д��Serialize����
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


int JudgmentQuestion::MarkPaper(const CString ans)//�о���
{
	// TODO: �ڴ˴����ʵ�ִ���.
	if (ans == this->m_strAnswer)
		return this->m_nScore;
	else
		return 0;
}
