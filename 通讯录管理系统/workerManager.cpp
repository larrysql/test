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
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;;
		ifs.close();
		return;
	}
	//2.文件存在，数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		cout << "文件为空！" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;;
		ifs.close();
		return;
	}
	//3.文件存在，且不为空
	int num = this->getEmpNum();
	cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;
	cout << this->m_EmpNum << endl;
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//初始化职工
	initEmp();
}

//读取文件中有多少条数据
int WorkerManager::getEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//打开文件

	int id;
	string name;
	int dId;
	int num =0;
	//开始读取数据，统计记录数量
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//cout << id << " " << name << " " << dId << endl;
		num++;
	}
	ifs.close();
	return num;
}

//将文件中的数据读取到指针数组m_EmpArray中



void WorkerManager::Show_Menu()
{
	cout << "**********************************************" << endl;
	cout << "**************欢迎来到职工管理系统************" << endl;
	cout << "*************** 0.退出管理系统  **************" << endl;
	cout << "*************** 1.增加职工信息  **************" << endl;
	cout << "*************** 2.显示职工信息  **************" << endl;
	cout << "*************** 3.删除离职职工  **************" << endl;
	cout << "*************** 4.修改职工信息  **************" << endl;
	cout << "*************** 5.查找职工信息  **************" << endl;
	cout << "*************** 6.按照编号排序  **************" << endl;
	cout << "*************** 7.清空所有文档  **************" << endl;
	cout << "**********************************************" << endl;
	cout << endl;
}

void WorkerManager::Exit()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}


void WorkerManager::AddWorker()
{
	cout << "请输入添加职工数量：" << endl;
	int addNum = 0;   //保存用户的输入数量
	cin >> addNum;
	if (addNum > 0)
	{
		//添加
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum;//新空间大小=原来记录人数+新增人数
		//开辟新空间
		Worker** newSpace = new Worker * [newSize];
		//将原来空间下数据，拷贝到新空间下
		if (this->m_EmpArray!=NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//显示初始数据
		cout << "初始数据如下：" << endl;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			cout << this->m_EmpArray[i]->m_Id << " "
				<< this->m_EmpArray[i]->m_Name << " "
				<< this->m_EmpArray[i]->m_DeptId << endl;
		}
		//添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;       //职工id
			string name; //职工姓名
			int dSelect;  //部门编号
			cout << "请输入第" << i + 1 << "个新职工的编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工的姓名：" << endl;
			cin >> name;
			cout << "请选择该职工岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
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
			//将创建职工，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}
		//释放原有空间
		delete[] this->m_EmpArray;
		//更改新空间指向
		this->m_EmpArray = newSpace;
		//更新新的职工人数
		this->m_EmpNum = newSize;

		//更新职工不为空的标志
		this->m_FileIsEmpty = false;
		this->Save();
		//提示添加成功
		cout << "成功添加" << addNum << "名新职工！" << endl;
		//for (int i = 0; i < this->m_EmpNum; i++)
		//{
		//	cout << this->m_EmpArray[i]->m_Id << " "
		//		<< this->m_EmpArray[i]->m_Name << " "
		//		<< typeid(this->m_EmpArray[i]->m_DeptId).name() 
		//		<< this->m_EmpArray[i]->m_DeptId
		//		<< endl;
		//}
		//保存数据

	}
	else
	{
		cout << "输入有误！请重新输入" << endl;
	}
}

void WorkerManager::Save()
{
	ofstream ofs(FILENAME, ios::out | ios::trunc);//用输出方式打开文件
	//将每个人的数据写入到文件中
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
	ifs.open(FILENAME, ios::in);//打开文件

	int id;
	string name;
	int dId;
	int index = 0;
	//开始读取数据，统计记录数量
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
			deptName = "职工";
			break;
		case 2:
			deptName = "经理";
			break;
		case 3:
			deptName = "老板";
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