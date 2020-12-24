//********************************************************************************************************
//�ļ���:                                       MultipleChoiceQuestion.cpp
//�汾:                                         1.0
//Ŀ�ļ���Ҫ����:                               ��ѡ����
//��������:                                     2020.9.4
//�޸�����:                                      
//����:                                         ���ɺ�
//�޸���:                                         
//��ϵ��ʽ:
//********************************************************************************************************
#include "pch.h"
#include "MultipleChoiceQuestion.h"

IMPLEMENT_SERIAL(MultipleChoiceQuestion,CObject,1)

MultipleChoiceQuestion::MultipleChoiceQuestion()
{

}

MultipleChoiceQuestion::~MultipleChoiceQuestion()
{

}

void MultipleChoiceQuestion::Serialize(CArchive& ar)//��д��Serialize����
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


int MultipleChoiceQuestion::MarkPaper(const CString ans)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	CString t_strSrc = ans;//��ans����һ�ݳ���
	CStringArray t_strResult;//һ��CString�͵����飬����ȡ����ͬ�Ĵ�

	CString strGap = _T(";");//����ֺ�Ϊ�ָ���
	int t_nPos = t_strSrc.Find(strGap);//�ָ���������

	CString strLeft = _T("");//�ָ���������ַ���
	while (0 <= t_nPos)//����ѭ����ȡ��������ַ���������������
	{
		strLeft = t_strSrc.Left(t_nPos);
		if (!strLeft.IsEmpty())
			t_strResult.Add(strLeft);

		t_strSrc = t_strSrc.Right(t_strSrc.GetLength() - t_nPos - 1);
		t_nPos = t_strSrc.Find(strGap);
	}

	if (!t_strSrc.IsEmpty()) {//���û��ȡ�꣬�����һ���ּӵ�������
		t_strResult.Add(t_strSrc);
	}

	int t_nSize = t_strResult.GetSize();//ȡ���𰸵ĸ���

	
	//ͬ���İ취ȡ����׼��
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
	if (t_nSize == 0)
	{
		return 0;
	}

	if (t_nSize == t_nStdSize)//������������
	{
		for (int i = 0; i < t_nStdSize;i++)//���αȶ�
		{
			int j = 0;
			for (; j < t_nSize; j++)
			{
				if (t_strStdResult[i] == t_strResult[j])
					break;
			}
			if (j == t_nSize && t_strStdResult[i] != t_strResult[j-1])//����Ѿ��ȶԵ������Ȼû���ҵ�ƥ��Ĵ�,˵�����д�
			{
				return 0;
			}
		}
		return this->m_nScore;//���д𰸶�ƥ��ɹ�����ȫ����ȷ

	}
	else if (t_nSize < t_nStdSize)//���ѧ���Ĵ𰸸������ڱ�׼�𰸸���
	{
		for (int i = 0; i < t_nSize; i++)//��ѧ���Ĵ�������Ϊ��ѭ�����ӱ�׼�����Ҷ�Ӧ�Ĵ�
		{
			int j = 0;
			for (; j < t_nStdSize; j++)
			{
				if (t_strResult[i] == t_strStdResult[j])
					break;
			}
			if (j == t_nStdSize && t_strStdResult[j-1] != t_strResult[i])//����Ѿ��ȶԵ������Ȼû���ҵ�ƥ��Ĵ�,˵�����д�
			{
				return 0;
			}
		}
		return this->m_nScore / 2;//ѧ�����еĴ𰸶��ڱ�׼���У���һ���
	}
	else//ѧ�������Ĵ𰸱ȱ�׼�𰸶࣬һ���д�
	{
		return 0;
	}
	
}
