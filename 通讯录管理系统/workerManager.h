#pragma once//��ֹͷ�ļ��ظ�����
#include <iostream>//�������������ͷ�ļ�
#include "worker.h"
using namespace std;//ʹ�ñ�׼�������ռ�

class WorkerManager
{
public:
	//���캯��
	WorkerManager();

	//չʾ�˵�
	void Show_Menu();

	//�˳�ϵͳ
	void Exit();

	//����ְ����Ϣ
	void AddWorker();

	//��ʾְ����Ϣ
	void ShowEmp();

	//����Ԫ��д�뵽�ļ�
	void Save();

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//��ȡ�ļ����ж���������
	int getEmpNum();

	//���ļ��ж�ȡ����
	void initEmp();

	//ɾ��ְ��
	void delEmp();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;

	//��������
	~WorkerManager();
};