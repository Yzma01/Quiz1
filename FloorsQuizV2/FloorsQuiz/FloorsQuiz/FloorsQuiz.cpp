#include <iostream>
#include "FloorNode.h"
#include "EmployeeNode.h"
#include "FloorList.h"
#include "Program.h"

int main()
{
	Program program;
	program.printMainMenu();

	/*
	FloorNode* floor1 = new FloorNode(3, 0);
	FloorNode* floor2 = new FloorNode(2, 0);
	FloorNode* floor3 = new FloorNode(1, 0);


	FloorList list;

	list.insertFloor(floor1);
	list.insertFloor(floor2);
	list.insertFloor(floor3);


	//list.printFloors();

	EmployeeNode* employee1 = new EmployeeNode("Juan", 0, 1);
	EmployeeNode* employee2 = new EmployeeNode("Pedro", 0, 2);
	EmployeeNode* employee3 = new EmployeeNode("cARLOS", 0, 1);
	EmployeeNode* employee4 = new EmployeeNode("pEPE", 0, 3);

	list.insertEmployeeByFloor(3, employee1);
	list.insertEmployeeByFloor(3, employee2);
	list.insertEmployeeByFloor(3, employee3);
	list.insertEmployeeByFloor(3, employee4);

	list.printEmployeesOfFloor(3);

	list.insertSaleByFloorAndEmployeeId(3, 1, new SaleNode(500));
	list.insertSaleByFloorAndEmployeeId(3, 1, new SaleNode(1000));
	list.insertSaleByFloorAndEmployeeId(3, 2, new SaleNode(5000));

	cout << "\n";

	list.printSalesByFloorAndEmployeeId(3, 1);

	cout << "\n";
	list.printSalesByFloorAndEmployeeId(3, 2);

	cout << endl << "Total del piso " << list.getAmoutByFloor(3);
	*/

	return 0;
}

