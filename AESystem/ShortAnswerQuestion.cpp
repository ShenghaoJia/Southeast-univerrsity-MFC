//********************************************************************************************************
//�ļ���:                                       ShortAnswerQuestion.cpp
//�汾:                                         1.0
//Ŀ�ļ���Ҫ����:                               �������
//��������:                                     2020.9.4
//�޸�����:                                      
//����:                                         ���ɺ�
//�޸���:                                         
//��ϵ��ʽ:
//********************************************************************************************************
#include "pch.h"
#include "ShortAnswerQuestion.h"

IMPLEMENT_SERIAL(ShortAnswerQuestion,CObject,1)

ShortAnswerQuestion::ShortAnswerQuestion()
{

}

ShortAnswerQuestion::~ShortAnswerQuestion()
{

}

void ShortAnswerQuestion::Serialize(CArchive& ar)//��д��Serialize����
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


int ShortAnswerQuestion::MarkPaper(const CString ans)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	//�Ͷ�ѡ������о����ƣ��ȴӱ�׼����ȡ���ؼ���

	CString strGap = _T(";");
	CString t_strStdSrc = this->m_strAnswer;
	CStringArray t_strStdResult;

	int t_nStdPos = t_strStdSrc.Find(strGap);

	CString t_strStdLeft = _T("");
	while (t_nStdPos >= 0)
	{
		t_strStdLeft = t_strStdSrc.Left(t_nStdPos);
		if (!t_strStdLeft.IsEmpty())
			t_strStdResult.Add(t_strStdLeft);

		t_strStdSrc = t_strStdSrc.Right(t_strStdSrc.GetLength() - t_nStdPos - 1);
		t_nStdPos = t_strStdSrc.Find(strGap);

	}

	if (!t_strStdSrc.IsEmpty())
	{
		t_strStdResult.Add(t_strStdSrc);
	}

	int t_nStdSize = t_strStdResult.GetSize();

	///////////////////////////////////////////////////////////////////////////////////
	int t_nCorrectNum = 0;//�ܹ�ƥ�䵽�Ĺؼ��ʵĸ���

	for (int i = 0; i < t_nStdSize; i++)//ÿ���ؼ��ʽ��бȶ�
	{
		int t_nIsFind = ans.Find(t_strStdResult[i]);
		if (t_nIsFind != -1)
			t_nCorrectNum++;
	}
	if (t_nStdSize == t_nCorrectNum)
	{
		return this->m_nScore;
	}
	else
	{
		double t_dReturnValue = (this->m_nScore / t_nStdSize) * t_nCorrectNum;//���ؼ��ʵ�������ƥ�䵽�ؼ��ʵĸ������д��
		return t_dReturnValue;
	}
	

}
