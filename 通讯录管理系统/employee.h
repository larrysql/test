#pragma once
#include <iostream>//�������������ͷ�ļ�
#include "worker.h"
using namespace std;//ʹ�ñ�׼�������ռ�

class Employee :public Worker
{
public:
	//���캯��
	Employee(int id, string name, int dId);
	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡְ����λ��Ϣ
	virtual string getDeptname();
};