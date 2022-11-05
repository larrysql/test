#pragma once//防止头文件重复包含
#include <iostream>//包含输入输出流头文件
#include "worker.h"
using namespace std;//使用标准的命名空间

class WorkerManager
{
public:
	//构造函数
	WorkerManager();

	//展示菜单
	void Show_Menu();

	//退出系统
	void Exit();

	//增加职工信息
	void AddWorker();

	//显示职工信息
	void ShowEmp();

	//数组元素写入到文件
	void Save();

	//判断文件是否为空
	bool m_FileIsEmpty;

	//读取文件中有多少条数据
	int getEmpNum();

	//从文件中读取数据
	void initEmp();

	//删除职工
	void delEmp();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;

	//析构函数
	~WorkerManager();
};