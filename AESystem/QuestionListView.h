//********************************************************************************************************
//�ļ���:                                       QuestionListView.h
//�汾:                                         1.0
//Ŀ�ļ���Ҫ����:                               �½�����ͼ�࣬����ʱ������ʾ��Ŀ�б�
//��������:                                     2020.9.6
//�޸�����:                                      
//����:                                         ���ɺ�
//�޸���:                                         
//��ϵ��ʽ:
//********************************************************************************************************
#pragma once
#include<afxcview.h>
class QuestionListView :
    public CListView
{
public:
    QuestionListView();
    ~QuestionListView();


    virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
    bool m_bIsFirst;//�Ƿ�Ϊ��һ�δ�
    int m_nQuestionSize;//��ǰ�Ծ���Ŀ������
    DECLARE_MESSAGE_MAP()
    afx_msg void OnNMDblclk(NMHDR* pNMHDR, LRESULT* pResult);//˫���˱��
};

