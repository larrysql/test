#pragma once
#include <iostream>//�������������ͷ�ļ�
using namespace std;//ʹ�ñ�׼�������ռ�

class Worker
{
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;
	//��ȡ��λ����
	virtual string getDeptname() = 0;

	int m_Id;//ְ�����
	string m_Name;//ְ������
	int m_DeptId;//ְ�����ڲ������Ʊ��

};