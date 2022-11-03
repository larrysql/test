#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include<fstream>
using namespace std;
#define FILENAME "empFile.txt"

WorkerManager::WorkerManager()
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;;
		ifs.close();
		return;
	}
	//2.�ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		cout << "�ļ�Ϊ�գ�" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;;
		ifs.close();
		return;
	}
	//3.�ļ����ڣ��Ҳ�Ϊ��
	int num = this->getEmpNum();
	cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;
	cout << this->m_EmpNum << endl;
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//��ʼ��ְ��
	initEmp();
}

//��ȡ�ļ����ж���������
int WorkerManager::getEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�

	int id;
	string name;
	int dId;
	int num =0;
	//��ʼ��ȡ���ݣ�ͳ�Ƽ�¼����
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//cout << id << " " << name << " " << dId << endl;
		num++;
	}
	ifs.close();
	return num;
}

//���ļ��е����ݶ�ȡ��ָ������m_EmpArray��



void WorkerManager::Show_Menu()
{
	cout << "**********************************************" << endl;
	cout << "**************��ӭ����ְ������ϵͳ************" << endl;
	cout << "*************** 0.�˳�����ϵͳ  **************" << endl;
	cout << "*************** 1.����ְ����Ϣ  **************" << endl;
	cout << "*************** 2.��ʾְ����Ϣ  **************" << endl;
	cout << "*************** 3.ɾ����ְְ��  **************" << endl;
	cout << "*************** 4.�޸�ְ����Ϣ  **************" << endl;
	cout << "*************** 5.����ְ����Ϣ  **************" << endl;
	cout << "*************** 6.���ձ������  **************" << endl;
	cout << "*************** 7.��������ĵ�  **************" << endl;
	cout << "**********************************************" << endl;
	cout << endl;
}

void WorkerManager::Exit()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}


void WorkerManager::AddWorker()
{
	cout << "���������ְ��������" << endl;
	int addNum = 0;   //�����û�����������
	cin >> addNum;
	if (addNum > 0)
	{
		//���
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum;//�¿ռ��С=ԭ����¼����+��������
		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];
		//��ԭ���ռ������ݣ��������¿ռ���
		if (this->m_EmpArray!=NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//��ʾ��ʼ����
		cout << "��ʼ�������£�" << endl;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			cout << this->m_EmpArray[i]->m_Id << " "
				<< this->m_EmpArray[i]->m_Name << " "
				<< this->m_EmpArray[i]->m_DeptId << endl;
		}
		//���������
		for (int i = 0; i < addNum; i++)
		{
			int id;       //ְ��id
			string name; //ְ������
			int dSelect;  //���ű��
			cout << "�������" << i + 1 << "����ְ���ı�ţ�" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ����������" << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, dSelect);
				break;
			case 2:
				worker = new Manager(id, name, dSelect);
				break;
			case 3:
				worker = new Boss(id, name, dSelect);
				break;
			default:
				break;
			}
			//������ְ�������浽������
			newSpace[this->m_EmpNum + i] = worker;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;
		//�����¿ռ�ָ��
		this->m_EmpArray = newSpace;
		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//����ְ����Ϊ�յı�־
		this->m_FileIsEmpty = false;
		this->Save();
		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "����ְ����" << endl;
		//for (int i = 0; i < this->m_EmpNum; i++)
		//{
		//	cout << this->m_EmpArray[i]->m_Id << " "
		//		<< this->m_EmpArray[i]->m_Name << " "
		//		<< typeid(this->m_EmpArray[i]->m_DeptId).name() 
		//		<< this->m_EmpArray[i]->m_DeptId
		//		<< endl;
		//}
		//��������

	}
	else
	{
		cout << "������������������" << endl;
	}
}

void WorkerManager::Save()
{
	ofstream ofs(FILENAME, ios::out | ios::trunc);//�������ʽ���ļ�
	//��ÿ���˵�����д�뵽�ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << " "
			<< endl;
	}
	ofs.close();
}

void WorkerManager::initEmp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�

	int id;
	string name;
	int dId;
	int index = 0;
	//��ʼ��ȡ���ݣ�ͳ�Ƽ�¼����
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		cout << id << " " << name << " " << dId << endl;
		Worker* worker = NULL;

		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkerManager::ShowEmp()
{
	for (int i = 0; i < this->m_EmpNum;i++)
	{
		int dId = m_EmpArray[i]->m_DeptId;
		string deptName;
		switch (dId)
		{
		case 1:
			deptName = "ְ��";
			break;
		case 2:
			deptName = "����";
			break;
		case 3:
			deptName = "�ϰ�";
			break;
		}

		cout << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< deptName << endl;
	}
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}