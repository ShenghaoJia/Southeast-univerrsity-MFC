//********************************************************************************************************
//�ļ���:                                       ShortAnswerQuestion.h
//�汾:                                         1.0
//Ŀ�ļ���Ҫ����:                               �������
//��������:                                     2020.9.4
//�޸�����:                                      
//����:                                         ���ɺ�
//�޸���:                                         
//��ϵ��ʽ:
//********************************************************************************************************
#pragma once
#include "TestQuestion.h"

class ShortAnswerQuestion :
    public TestQuestion
{
    DECLARE_SERIAL(ShortAnswerQuestion)
public:
    ShortAnswerQuestion();
    ~ShortAnswerQuestion();

    virtual void Serialize(CArchive& ar);//��д��Serialize����
    virtual int MarkPaper(const CString ans);//�о���
};

