#include "FloorNode.h"

FloorNode::FloorNode(int numberFloor, double totalSales)
{
    this->numberFloor = numberFloor;
    this->totalSales = totalSales;
    this->nextFloor = nullptr;
    this->previusFloor = nullptr;
}

FloorNode::~FloorNode() {
    this->nextFloor = nullptr;
    this->previusFloor = nullptr;
}

EmployeeNode* FloorNode::searchEmployeeById(int id) {
    EmployeeNode* current = employeeRoot;
    while (current != nullptr && current->getId() != id) {
        current = current->getEmployeeNext();
    }

    return current;
}

//!Getters

int FloorNode::getNumberFloor() {
    return this->numberFloor;
}
double FloorNode::getTotalSales() {
    return this->totalSales;
}
EmployeeNode* FloorNode::getEmployeeRoot() {
    return this->employeeRoot;
}
FloorNode* FloorNode::getNextFloor() {
    return this->nextFloor;
}
FloorNode* FloorNode::getPreviusFloor() {
    return this->previusFloor;
}

//! Setters

void FloorNode::setNumberFloor(int numberFloor) {
    this->numberFloor = numberFloor;
}
void FloorNode::setTotalSales(double totalSales) {
    this->totalSales = totalSales;
}
void FloorNode::setEmployeeRoot(EmployeeNode* newEmployeeRoot) {
    this->employeeRoot = newEmployeeRoot;
}
void FloorNode::setNextFloor(FloorNode* nextFloor) {
    this->nextFloor = nextFloor;
}
void FloorNode::setPreviusFloor(FloorNode* previusFloor) {
    this->previusFloor = previusFloor;
}
