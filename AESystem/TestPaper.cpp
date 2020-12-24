//********************************************************************************************************
//�ļ���:                                       TestPaper.cpp
//�汾:                                         1.0
//Ŀ�ļ���Ҫ����:                               �Ծ��࣬���ڽ����������������
//��������:                                     2020.9.4
//�޸�����:                                      
//����:                                         ���ɺ�
//�޸���:                                         
//��ϵ��ʽ:
//********************************************************************************************************
#include "pch.h"
#include "TestPaper.h"

IMPLEMENT_SERIAL(TestPaper,CObject,1)

TestPaper::TestPaper()
	:m_nPaperNum(0),
	m_nTotalScore(0)
{

}

TestPaper::~TestPaper()
{

}

void TestPaper::Serialize(CArchive& ar)//��д��Serialize����
{
	if (ar.IsStoring())
	{	// storing code
		
		ar << m_nPaperNum;//��������������
		ar << m_nTotalScore;//���ִܷ���

		for (int i = 0; i < this->m_vnPaperType.size(); i++)//��������������
		{
			ar << this->m_vnPaperType[i];
		}
	
		for (int i = 0; i < this->m_vpTqExamPaper.size(); i++)//��������������
		{
			this->m_vpTqExamPaper[i]->Serialize(ar);
		}
	}
	else
	{	// loading code
		ar >> m_nPaperNum;//�����������ó�
		ar >> m_nTotalScore;//���ܷ��ó�

		for (int i = 0; i < m_nPaperNum; i++)//���������������Ծ����������ó�
		{
			m_vnPaperType.push_back(0);
			ar >> this->m_vnPaperType[i];
		}
		for (int i = 0; i < m_nPaperNum; i++)//���������������������ͽ������ó�
		{
			if (m_vnPaperType[i] == SINGLE_CHOICE)
				m_vpTqExamPaper.push_back(new SingleChoiceQuestion());
			if (m_vnPaperType[i] == MULTIPLE_CHOICE)
				m_vpTqExamPaper.push_back(new MultipleChoiceQuestion());
			if (m_vnPaperType[i] == SHORT_ANSWER)
				m_vpTqExamPaper.push_back(new ShortAnswerQuestion());
			if (m_vnPaperType[i] == JUDGMENT_CHOICE)
				m_vpTqExamPaper.push_back(new JudgmentQuestion());
			//m_vpTqExamPaper.push_back(new TestQuestion());
			this->m_vpTqExamPaper[i]->Serialize(ar);
		}
	}
}


bool TestPaper::AddQuestion(const CString topic, const CString answer, int score, int type)//�������⺯��
{
	// TODO: �ڴ˴����ʵ�ִ���.
	if (m_nTotalScore + score > 100)
		return false;
	else
	{
		m_vnPaperType.push_back(type);

		if (type == SINGLE_CHOICE)
			m_vpTqExamPaper.push_back(new SingleChoiceQuestion());
		if (type == MULTIPLE_CHOICE)
			m_vpTqExamPaper.push_back(new MultipleChoiceQuestion());
		if (type == SHORT_ANSWER)
			m_vpTqExamPaper.push_back(new ShortAnswerQuestion());
		if (type == JUDGMENT_CHOICE)
			m_vpTqExamPaper.push_back(new JudgmentQuestion());

		m_vpTqExamPaper.back()->m_strTopic = topic;
		m_vpTqExamPaper.back()->m_strAnswer = answer;
		m_vpTqExamPaper.back()->m_nScore = score;
		m_vpTqExamPaper.back()->m_nType = type;

		m_nPaperNum++;
		m_nTotalScore += score;
		return true;
	}


	
}
