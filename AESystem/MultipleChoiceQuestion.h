//********************************************************************************************************
//�ļ���:                                       MultipleChoiceQuestion.h
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
class MultipleChoiceQuestion :
    public TestQuestion
{
    DECLARE_SERIAL(MultipleChoiceQuestion)
public:
    MultipleChoiceQuestion();
    virtual ~MultipleChoiceQuestion();

    virtual void Serialize(CArchive& ar);//��д��Serialize����
    virtual int MarkPaper(const CString ans);//�о���
};

