//********************************************************************************************************
//�ļ���:                                       TestQuestion.h
//�汾:                                         1.0
//Ŀ�ļ���Ҫ����:                               ����������Ļ���
//��������:                                     2020.9.4
//�޸�����:                                      
//����:                                         ���ɺ�
//�޸���:                                         
//��ϵ��ʽ:
//********************************************************************************************************
#pragma once
#include <afx.h>

enum
{
	SINGLE_CHOICE, MULTIPLE_CHOICE, SHORT_ANSWER,JUDGMENT_CHOICE//��ѡ����ѡ�����
};

class TestQuestion : public CObject
{
	DECLARE_SERIAL(TestQuestion)
public:
	TestQuestion();
	virtual ~TestQuestion();

	CString m_strTopic;//��Ŀ
	CString m_strAnswer;//��
	int m_nScore;//����ķ���
	int m_nType;//��Ŀ����

	virtual void Serialize(CArchive& ar);//���ص�Serialize����
	virtual int MarkPaper(const CString ans);//�о���
};

