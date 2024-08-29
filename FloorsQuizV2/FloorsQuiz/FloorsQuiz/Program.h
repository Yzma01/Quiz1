#pragma once
#include <iostream>
#include <cstdlib>
#include "FloorNode.h"
#include "EmployeeNode.h"
#include "SaleNode.h"
#include "FloorList.h"
using namespace std;

class Program
{
private:
	FloorList list;

public:
	Program();

	void printMainMenu();
	void addFloor();
	void deleteFloor();
	void addEmployee();
	void addSale();
	void showFloorsInfo();
	void showEmployeesInfo();
	void showSalesOfEmployee();
};

