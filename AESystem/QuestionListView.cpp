//********************************************************************************************************
//�ļ���:                                       QuestionListView.cpp
//�汾:                                         1.0
//Ŀ�ļ���Ҫ����:                               �½�����ͼ�࣬����ʱ������ʾ��Ŀ�б�
//��������:                                     2020.9.6
//�޸�����:                                      
//����:                                         ���ɺ�
//�޸���:                                         
//��ϵ��ʽ:
//********************************************************************************************************
#include "pch.h"
#include "QuestionListView.h"
#include"AEsystemDoc.h"
#include"ExistingQuestion.h"

QuestionListView::QuestionListView()
	:m_nQuestionSize(),
	m_bIsFirst(true)
{

}

QuestionListView::~QuestionListView()
{

}

void QuestionListView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	// TODO: �ڴ����ר�ô����/����û���
	CAEsystemDoc* t_pDocData = (CAEsystemDoc*)GetDocument();//��ȡ�ļ���ָ��

	if (m_bIsFirst)//����ǵ�һ��update
	{
		m_nQuestionSize = t_pDocData->m_TpMyTestPaper.m_nPaperNum;//��ȡ���ⳤ��

		CListCtrl& m_list = GetListCtrl();//�õ����õ�listctrl����

		LONG lStyle;
		lStyle = GetWindowLong(m_list.m_hWnd, GWL_STYLE);//��ȡ��ǰ���ڷ��
		lStyle &= ~LVS_TYPEMASK; //�����ʾ��ʽλ
		lStyle |= LVS_REPORT; //���ñ�����
		SetWindowLong(m_list.m_hWnd, GWL_STYLE, lStyle); //���ô��ڷ��
		DWORD dwStyle = m_list.GetExtendedStyle();

		//ѡ��ĳ��ʹ���и�����ֻ�����ڱ������listctrl��
		dwStyle |= LVS_EX_FULLROWSELECT;
		dwStyle |= LVS_EX_GRIDLINES;//�����ߣ�ֻ�����뱨�����listctrl��
		m_list.SetExtendedStyle(dwStyle); //������չ���
		m_list.SetBkColor(RGB(200, 200, 200)); //���ñ�����ɫ
		m_list.SetTextBkColor(RGB(200, 200, 200)); //�����ı�������ɫ
		m_list.SetTextColor(RGB(10, 10, 80)); //�����ı���ɫ
		//�����еı��⣬Ϊ�˼��������ֻ��������

		m_list.InsertColumn(0, _T("��Ŀ���"), LVCFMT_CENTER, 110);
		m_list.InsertColumn(1, _T("��Ŀ����"), LVCFMT_CENTER, 110);
		m_list.InsertColumn(2, _T("��Ŀ��ֵ"), LVCFMT_CENTER, 110);

		for (int i = 0; i < m_nQuestionSize; i++)//��ʼ�����
		{
			CString t_strTemp;//������ת�����ַ����Ĺ����ַ���
			t_strTemp.Format(_T("%d"), i+1);

			m_list.InsertItem(i, t_strTemp);//������
			if (t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[i]->m_nType == SINGLE_CHOICE)//����ǵ�ѡ��
				m_list.SetItemText(i, 1, _T("��ѡ��"));
			if (t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[i]->m_nType == MULTIPLE_CHOICE)//����Ƕ�ѡ��
				m_list.SetItemText(i, 1, _T("��ѡ��"));
			if (t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[i]->m_nType == SHORT_ANSWER)//����Ǽ����
				m_list.SetItemText(i, 1, _T("�����"));
			if (t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[i]->m_nType == JUDGMENT_CHOICE)//������ж���
				m_list.SetItemText(i, 1, _T("�ж���"));

			t_strTemp.Format(_T("%d"), t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[i]->m_nScore);//����Ŀ����תΪ�ַ���
			m_list.SetItemText(i, 2, t_strTemp);//�����ֵ
		}

		m_bIsFirst = false;
	}
	else//������ǵ�һ��update,��һ���������������Ĺ��̵���
	{
		CListCtrl& m_list = GetListCtrl();//�õ����õ�listctrl����
		CString t_strTemp;

		t_strTemp.Format(_T("%d"), m_nQuestionSize+1);
		m_list.InsertItem(m_nQuestionSize, t_strTemp);

		if (t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[m_nQuestionSize]->m_nType == SINGLE_CHOICE)//����ǵ�ѡ��
			m_list.SetItemText(m_nQuestionSize, 1, _T("��ѡ��"));
		if (t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[m_nQuestionSize]->m_nType == MULTIPLE_CHOICE)//����Ƕ�ѡ��
			m_list.SetItemText(m_nQuestionSize, 1, _T("��ѡ��"));
		if (t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[m_nQuestionSize]->m_nType == SHORT_ANSWER)//����Ǽ����
			m_list.SetItemText(m_nQuestionSize, 1, _T("�����"));
		if (t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[m_nQuestionSize]->m_nType == JUDGMENT_CHOICE)//������ж���
			m_list.SetItemText(m_nQuestionSize, 1, _T("�ж���"));

		t_strTemp.Format(_T("%d"), t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[m_nQuestionSize]->m_nScore);//����Ŀ����תΪ�ַ���
		m_list.SetItemText(m_nQuestionSize, 2, t_strTemp);//�����ֵ

		m_nQuestionSize++;//��������+1
	}
}
BEGIN_MESSAGE_MAP(QuestionListView, CListView)
	ON_NOTIFY_REFLECT(NM_DBLCLK, &QuestionListView::OnNMDblclk)
END_MESSAGE_MAP()


void QuestionListView::OnNMDblclk(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CAEsystemDoc* t_pDocData = (CAEsystemDoc*)GetDocument();//��ȡ�ļ���ָ��
	int t_nCounter = 0;
	CString t_strSrc;
	while (true)
	{
		ExistingQuestion t_eqTemp;
		t_strSrc.Format(_T("%d"), t_nCounter+1);
		t_eqTemp.m_strEqTopic = _T("����") + t_strSrc + _T("��)") + t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[t_nCounter]->m_strTopic;
		t_eqTemp.m_strEqAnswer = t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[t_nCounter]->m_strAnswer;

		int t_nOrder = t_eqTemp.DoModal();
		if (t_nOrder == 0)
		{
			break;
		}
		else if (t_nOrder == 1 && t_nCounter != t_pDocData->m_TpMyTestPaper.m_nPaperNum - 1)
		{
			t_nCounter++;
			continue;
		}
		else if (t_nOrder == -1 && t_nCounter != 0)
		{
			t_nCounter--;
			continue;
		}
		else
		{
			MessageBox(_T("�Ѿ��ǵ�һ������һ��"));
			continue;
		}
	}

	*pResult = 0;
}
