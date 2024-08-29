#pragma once
#include <iostream>
#include "EmployeeNode.h"
using namespace std;

class FloorNode
{

private:
    int numberFloor;
    double totalSales;
    EmployeeNode *employeeRoot;
    FloorNode* nextFloor;
    FloorNode* previusFloor;

public:
    FloorNode(int, double);
    ~FloorNode();

    EmployeeNode* searchEmployeeById(int);

    int getNumberFloor();
    double getTotalSales();
    EmployeeNode* getEmployeeRoot();
    FloorNode* getNextFloor();
    FloorNode* getPreviusFloor();

    void setNumberFloor(int);
    void setTotalSales(double);
    void setEmployeeRoot(EmployeeNode*);
    void setNextFloor(FloorNode*);
    void setPreviusFloor(FloorNode*);
};

