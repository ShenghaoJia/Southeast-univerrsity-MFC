//********************************************************************************************************
//�ļ���:                                       SingleChoiceQuestion.h
//�汾:                                         1.0
//Ŀ�ļ���Ҫ����:                               ��ѡ����
//��������:                                     2020.9.4
//�޸�����:                                      
//����:                                         ���ɺ�
//�޸���:                                         
//��ϵ��ʽ:
//********************************************************************************************************
#pragma once
#include "TestQuestion.h"
class SingleChoiceQuestion :public TestQuestion
{
	DECLARE_SERIAL(SingleChoiceQuestion)
public:
	SingleChoiceQuestion();
	virtual ~SingleChoiceQuestion();

	virtual void Serialize(CArchive& ar);//��д��Serialize����
	virtual int MarkPaper(const CString ans);//�о���
};

