#include "employee.h"

Employee::Employee(int id, string name, int dId)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}

void Employee::showInfo()
{
	cout << "ְ����ţ�" << "\t" << this->m_Id
		<< "\t" << "ְ��������" << this->m_Name
		<< "\t" << "��λ��" << this->getDeptname() << endl;
}

string Employee::getDeptname()
{
	return string("Ա��");
}