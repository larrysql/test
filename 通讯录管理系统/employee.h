#pragma once
#include <iostream>//包含输入输出流头文件
#include "worker.h"
using namespace std;//使用标准的命名空间

class Employee :public Worker
{
public:
	//构造函数
	Employee(int id, string name, int dId);
	//显示个人信息
	virtual void showInfo();

	//获取职工岗位信息
	virtual string getDeptname();
};