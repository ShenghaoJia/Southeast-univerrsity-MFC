//********************************************************************************************************
//�ļ���:                                       JudgmentQuestion.h
//�汾:                                         1.0
//Ŀ�ļ���Ҫ����:                               �ж�����
//��������:                                     2020.9.4
//�޸�����:                                      
//����:                                         ���ɺ�
//�޸���:                                         
//��ϵ��ʽ:
//********************************************************************************************************
#pragma once
#include "TestQuestion.h"
class JudgmentQuestion :
    public TestQuestion
{
    DECLARE_SERIAL(JudgmentQuestion)
public:
    JudgmentQuestion();
    ~JudgmentQuestion();

    virtual void Serialize(CArchive& ar);//��д��Serialize����
    virtual int MarkPaper(const CString ans);//�о���
};

