//********************************************************************************************************
//�ļ���:                                       SingleChoiceQuestion.cpp
//�汾:                                         1.0
//Ŀ�ļ���Ҫ����:                               ��ѡ����
//��������:                                     2020.9.4
//�޸�����:                                      
//����:                                         ���ɺ�
//�޸���:                                         
//��ϵ��ʽ:
//********************************************************************************************************
#include "pch.h"
#include "SingleChoiceQuestion.h"

IMPLEMENT_SERIAL(SingleChoiceQuestion,CObject,1)

SingleChoiceQuestion::SingleChoiceQuestion()
{

}

SingleChoiceQuestion::~SingleChoiceQuestion()
{

}

void SingleChoiceQuestion::Serialize(CArchive& ar)//��д��Serialize����
{
	if (ar.IsStoring())
	{	// storing code
		ar << m_strTopic << m_strAnswer << m_nScore << m_nType;;
	}
	else
	{	// loading code
		ar >> m_strTopic >> m_strAnswer >> m_nScore >> m_nType;
	}
}

int SingleChoiceQuestion::MarkPaper(const CString ans)
{
	//��ѡֻ��һ���𰸣���ֻҪ�𰸺ͱ�׼����ͬ���ɵ�����
	if (ans == this->m_strAnswer)
		return this->m_nScore;
	else
		return 0;
}
