#pragma once
#include <iostream>
#include "SaleNode.h"
using namespace std;

class EmployeeNode
{
private:
    string name;
    double amountSold;
    int id;
    SaleNode* saleRoot;
    EmployeeNode* employeeNext;
public:
    EmployeeNode(string, double, int);
    ~EmployeeNode();

    string getName();
    double getAmoutSold();
    int getId();
    SaleNode* getSaleRoot();
    EmployeeNode* getEmployeeNext();

    void setName(string);
    void setAmoutSold(double);
    void setId(int);
    void setSaleRoot(SaleNode*);
    void setEmployeeNext(EmployeeNode*);

};

