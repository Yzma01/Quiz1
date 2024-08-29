#include "FloorList.h"
#include <iostream>

FloorList::FloorList() {
	this->root = nullptr;
}

FloorNode* FloorList::searchFloorByNumber(int numberFloor) {
	FloorNode* current = root;
	while (current != nullptr && current->getNumberFloor() != numberFloor) {
		current = current->getNextFloor();
	}

	return current;
}

bool FloorList::checkFloor(FloorNode* newFloor) {

	if (root != nullptr) {
		FloorNode* current = root;

		while (current != nullptr) {
			if (current->getNumberFloor() == newFloor->getNumberFloor()) {

				return true;
			}
			current = current->getNextFloor();
		}
	}
	return false;

}

bool FloorList::checkEmployeeByFloor(int numberFloor, EmployeeNode* newEmployee) {

	FloorNode* selectedFloor = searchFloorByNumber(numberFloor);

	if (root != nullptr) {

		EmployeeNode* current = selectedFloor->getEmployeeRoot();

		while (current != nullptr) {

			if (current->getId() == newEmployee->getId()) {

				return true;
			}
			current = current->getEmployeeNext();
		}
	}
	return false;

}

double FloorList::getAmoutByFloor(int numberFloor) {
	FloorNode* selectedFloor = searchFloorByNumber(numberFloor);

	if (selectedFloor == nullptr) {
		cout << "Piso no encontrado\n";
		return 0;
	}
	else {
		return selectedFloor->getTotalSales();
	}

}

void FloorList::deleteFloor(int numberFloor, int newNumberFloor) {
	FloorNode* selectedFloor = searchFloorByNumber(numberFloor);
	FloorNode* newSelectedFloor = searchFloorByNumber(newNumberFloor);

	if (selectedFloor == nullptr || newSelectedFloor == nullptr) {
		cout << "Piso/s no encontrado\n";
		return;
	}

	if (selectedFloor->getNumberFloor() == newSelectedFloor->getNumberFloor()) {
		cout << "Los pisos son iguales\n";
		return;
	}

	if (selectedFloor->getEmployeeRoot() != nullptr) { //Aqui se transfieren los hps
		EmployeeNode* lastEmployee = newSelectedFloor->getEmployeeRoot();
		if (lastEmployee == nullptr) {
			newSelectedFloor->setEmployeeRoot(selectedFloor->getEmployeeRoot());
		}
		else {
			while (lastEmployee->getEmployeeNext() != nullptr) {
				lastEmployee = lastEmployee->getEmployeeNext();
			}
			lastEmployee->setEmployeeNext(selectedFloor->getEmployeeRoot());
		}
		selectedFloor->setEmployeeRoot(nullptr);
	}

	printEmployeesOfFloor(newNumberFloor); //Pa ver si se transfieren

	newSelectedFloor->setTotalSales(newSelectedFloor->getTotalSales() + selectedFloor->getTotalSales());

	//De aqui pa bajo no sirve
	if (selectedFloor == root) {
		root = selectedFloor->getNextFloor();
		if (root != nullptr) {
			root->setPreviusFloor(nullptr);
		}
	}
	else {
		FloorNode* prevFloor = selectedFloor->getPreviusFloor();
		FloorNode* nextFloor = selectedFloor->getNextFloor();

		if (prevFloor != nullptr) {
			prevFloor->setNextFloor(nextFloor);
		}
		if (nextFloor != nullptr) {
			nextFloor->setPreviusFloor(prevFloor);
		}
	}
	selectedFloor->~FloorNode();
	cout << "Piso " << numberFloor << " eliminado y sus empleados transferidos al piso " << newNumberFloor << "\n";
}


void FloorList::insertFloor(FloorNode* newFloor) {

	if (checkFloor(newFloor)) {
		cout << "El piso " << newFloor->getNumberFloor() << " ya existe\n";
		return;
	}
	if (root == nullptr || newFloor->getNumberFloor() < root->getNumberFloor()) {
		newFloor->setNextFloor(root);
		if (root != nullptr) {
			root->setPreviusFloor(newFloor);
		}
		root = newFloor;
		return;
	}


	FloorNode* current = root;
	while (current->getNextFloor() != nullptr &&
		current->getNextFloor()->getNumberFloor() < newFloor->getNumberFloor()) {
		current = current->getNextFloor();
	}

	newFloor->setNextFloor(current->getNextFloor());
	if (current->getNextFloor() != nullptr) {
		current->getNextFloor()->setPreviusFloor(newFloor);
	}
	current->setNextFloor(newFloor);
	newFloor->setPreviusFloor(current);
}

void FloorList::insertEmployeeByFloor(int numberFloor, EmployeeNode* newEmployee) {
	FloorNode* selectedFloor = searchFloorByNumber(numberFloor);

	if (selectedFloor == nullptr) {
		cout << "Piso no encontrado\n";
	}
	else {
		if (checkEmployeeByFloor(numberFloor, newEmployee)) {
			cout << "En el piso " << numberFloor << " ya existe un empleado con el id: " << newEmployee->getId() << "\n";
			return;
		}

		if (selectedFloor->getEmployeeRoot() == nullptr) {
			selectedFloor->setEmployeeRoot(newEmployee);
			return;
		}

		EmployeeNode* currentEmployee = selectedFloor->getEmployeeRoot();
		while (currentEmployee->getEmployeeNext() != nullptr) {
			currentEmployee = currentEmployee->getEmployeeNext();
		}

		currentEmployee->setEmployeeNext(newEmployee);
	}
}

void FloorList::insertSaleByFloorAndEmployeeId(int numberFloor, int employeeId, SaleNode* newSale) {
	FloorNode* selectedFloor = searchFloorByNumber(numberFloor);
	EmployeeNode* selectedEmployee = nullptr;
	if (selectedFloor != nullptr) {
		selectedEmployee = selectedFloor->searchEmployeeById(employeeId);
	}

	if (selectedFloor == nullptr || selectedEmployee == nullptr) {
		cout << "Piso/Empleado no encontrado\n";
		return;
	}
	else {
		if (selectedEmployee->getSaleRoot() == nullptr) {
			selectedEmployee->setSaleRoot(newSale);
			selectedEmployee->setAmoutSold(newSale->getPrice());
			selectedFloor->setTotalSales(selectedFloor->getTotalSales() + newSale->getPrice());
			return;
		}


		SaleNode* currentSale = selectedEmployee->getSaleRoot();
		while (currentSale->getSaleNext() != nullptr) {

			currentSale = currentSale->getSaleNext();
		}

		currentSale->setSaleNext(newSale);
		
		selectedEmployee->setAmoutSold(selectedEmployee->getAmoutSold() + newSale->getPrice());
		selectedFloor->setTotalSales(0);
		selectedFloor->setTotalSales(selectedFloor->getTotalSales() + selectedEmployee->getAmoutSold());
	}
}

void FloorList::printFloors() {
	FloorNode* current = this->root;
	while (current != nullptr)
	{
		cout << current->getNumberFloor();
		if (current->getNextFloor() != nullptr) {
			cout << ", ";
		}
		else {
			cout << ".";
		}

		current = current->getNextFloor();
	}
}

void FloorList::printFloorsInfo() {
	FloorNode* current = this->root;
	while (current != nullptr)
	{
		if (current->getNumberFloor() < 10) {
			cout << "\t" << current->getNumberFloor() << "    |    " << current->getTotalSales() << "\n";
		}
		else {
			cout << "\t" << current->getNumberFloor() << "   |    " << current->getTotalSales() << "\n";
		}
		current = current->getNextFloor();
	}
}

void FloorList::printEmployeesOfFloor(int numberFloor) {
	FloorNode* selectedFloor = searchFloorByNumber(numberFloor);

	if (selectedFloor == nullptr) {
		cout << "Piso no encontrado\n";
	}
	else {
		EmployeeNode* currentEmployee = selectedFloor->getEmployeeRoot();
		while (currentEmployee != nullptr) {
			cout << currentEmployee->getId() << "- " << currentEmployee->getName() << "\n";
			currentEmployee = currentEmployee->getEmployeeNext();
		}
	}
}

void FloorList::printEmployeesOfFloorInfo(int numberFloor) {
	FloorNode* selectedFloor = searchFloorByNumber(numberFloor);

	if (selectedFloor == nullptr) {
		cout << "Piso no encontrado\n";
	}
	else {
		EmployeeNode* currentEmployee = selectedFloor->getEmployeeRoot();
		while (currentEmployee != nullptr) {
			cout << currentEmployee->getId() << "   " << currentEmployee->getName() << "   " << currentEmployee->getAmoutSold() << "\n";
			currentEmployee = currentEmployee->getEmployeeNext();
		}
	}
}

void FloorList::printSalesByFloorAndEmployeeId(int numberFloor, int employeeId) {
	FloorNode* selectedFloor = searchFloorByNumber(numberFloor);
	EmployeeNode* selectedEmployee = nullptr;
	if (selectedFloor != nullptr) {
		selectedEmployee = selectedFloor->searchEmployeeById(employeeId);
	}

	if (selectedFloor == nullptr || selectedEmployee == nullptr) {
		cout << "Piso/Empleado no encontrado\n";
	}
	else {
		SaleNode* currentSale = selectedEmployee->getSaleRoot();
		cout << "\nLas ventas del empleado " << selectedEmployee->getName() << " son: ";
		while (currentSale != nullptr) {
			cout << currentSale->getPrice();
			if (currentSale->getSaleNext() != nullptr) {
				cout << ", ";
			}
			else {
				cout << ".";
			}
			currentSale = currentSale->getSaleNext();
		}
		cout << "\nTotal: " << selectedEmployee->getAmoutSold();
	}

}