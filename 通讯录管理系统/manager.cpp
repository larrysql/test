#include "manager.h"
//构造函数
Manager::Manager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
//显示个人信息
void Manager::showInfo()
{
	cout << "职工编号：" << "\t" << this->m_Id
		<< "\t" << "职工姓名：" << this->m_Name
		<< "\t" << "岗位：" << this->getDeptname() 
		<<"\t岗位职责：完成老板交给的任务，并下发任务给普通员工" << endl;
 }
//获取岗位名称
string Manager::getDeptname()
{
	return string("经理");
 }