#include "boss.h"
//构造函数
Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
//显示个人信息
void Boss::showInfo()
{
	cout << "职工编号：" << "\t" << this->m_Id
		<< "\t" << "职工姓名：" << this->m_Name
		<< "\t" << "岗位：" << this->getDeptname()
		<< "\t岗位职责：管理公司所有事务" << endl;
}
//获取岗位名称
string Boss::getDeptname()
{
	return string("老板");
}