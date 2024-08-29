#include "EmployeeNode.h"

EmployeeNode::EmployeeNode(string name, double amountSold, int id) {
	this->name = name;
	this->amountSold = amountSold;
	this->id = id;
	this->saleRoot = nullptr;
	this->employeeNext = nullptr;
}
EmployeeNode::~EmployeeNode() {

}

//!Getters

string EmployeeNode::getName() {
	return this->name;
}
double EmployeeNode::getAmoutSold() {
	return this->amountSold;
}
int EmployeeNode::getId() {
	return this->id;
}
SaleNode* EmployeeNode::getSaleRoot() {
	return this->saleRoot;
}
EmployeeNode* EmployeeNode::getEmployeeNext() {
	return this->employeeNext;
}

//!Setters

void EmployeeNode::setName(string name) {
	this->name = name;
}
void EmployeeNode::setAmoutSold(double amountSold) {
	this->amountSold = amountSold;
}
void EmployeeNode::setId(int id) {
	this->id = id;
}
void EmployeeNode::setSaleRoot(SaleNode* newSaleRoot) {
	this->saleRoot = newSaleRoot;
}
void EmployeeNode::setEmployeeNext(EmployeeNode* nextEmployee) {
	this->employeeNext = nextEmployee;
}
