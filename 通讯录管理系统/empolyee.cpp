#include "employee.h"

Employee::Employee(int id, string name, int dId)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}

void Employee::showInfo()
{
	cout << "职工编号：" << "\t" << this->m_Id
		<< "\t" << "职工姓名：" << this->m_Name
		<< "\t" << "岗位：" << this->getDeptname() << endl;
}

string Employee::getDeptname()
{
	return string("员工");
}