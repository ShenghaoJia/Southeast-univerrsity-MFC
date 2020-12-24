//********************************************************************************************************
//�ļ���:                                       TestPaper.h
//�汾:                                         1.0
//Ŀ�ļ���Ҫ����:                               �Ծ��࣬���ڽ����������������
//��������:                                     2020.9.4
//�޸�����:                                      
//����:                                         ���ɺ�
//�޸���:                                         
//��ϵ��ʽ:
//********************************************************************************************************
#pragma once
#include <afx.h>
#include<vector>
using namespace std;

//#include"TestQuestion.h"
#include"SingleChoiceQuestion.h"
#include"MultipleChoiceQuestion.h"
#include"ShortAnswerQuestion.h"
#include"JudgmentQuestion.h"
class TestPaper :
    public CObject
{
    DECLARE_SERIAL(TestPaper)
public:
    TestPaper();
    ~TestPaper();

    virtual void Serialize(CArchive& ar);//��д��Serialize����
    bool AddQuestion(const CString topic, const CString answer, int score, int type);//�������

    vector<TestQuestion*> m_vpTqExamPaper;//�Ծ���Ŀ
    vector<int> m_vnPaperType;//�Ծ���Ŀ������
    int m_nPaperNum;//���������
    int m_nTotalScore;//�Ծ���ܷ�
    
};

