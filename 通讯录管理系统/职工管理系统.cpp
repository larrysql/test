#include <iostream>
using namespace std;
#include <string>;
#include<stdio.h> 
#include<fstream>
#include "workerManager.h";
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main()
{
	////���Դ���
	//Worker* worker = NULL;
	//worker = new Employee(1, "����", 1);
	//worker->showInfo();
	//delete worker;
	//Worker* worker = NULL;
	//worker = new Manager(2, "����", 2);
	//worker->showInfo();
	//delete worker;
	//worker = new Boss(3, "����", 3);
	//worker->showInfo();

	int choice;
	WorkerManager wm;
	for (;;)
	{
		wm.Show_Menu();
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.Exit();
			break;
		case 1:
			wm.AddWorker();
			break;
		case 2:
			wm.ShowEmp();
			break;
		case 3:
			wm.delEmp();
			break;
		case4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;

		default:
			break;
		}
	}

}