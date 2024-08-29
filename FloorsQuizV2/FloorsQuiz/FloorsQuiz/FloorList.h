#pragma once
#include <iostream>
#include "FloorNode.h"
#include "EmployeeNode.h"
#include "SaleNode.h"
using namespace std;

class FloorList
{
private:
    FloorNode* root;

public:
    FloorList();


    FloorNode* searchFloorByNumber(int);

    bool checkFloor(FloorNode*);

    bool checkEmployeeByFloor(int, EmployeeNode*);

    double getAmoutByFloor(int);

    void deleteFloor(int, int);

    void insertFloor(FloorNode*);

    void insertEmployeeByFloor(int, EmployeeNode*);

    void insertSaleByFloorAndEmployeeId(int, int, SaleNode*);

    void printFloors();
    void printFloorsInfo();

    void printEmployeesOfFloor(int);
    void printEmployeesOfFloorInfo(int);

    void printSalesByFloorAndEmployeeId(int, int);
};

