#include "Program.h"


Program::Program() {

}

void Program::printMainMenu() {
    int option;
    do {
        system("cls");
        std::cout << "=== Menú Principal ===\n";
        std::cout << "1. Agregar Piso\n";
        std::cout << "2. Eliminar Piso\n";
        std::cout << "3. Agregar Empleado\n";
        std::cout << "4. Agregar Venta\n";
        std::cout << "5. Mostrar Pisos\n";
        std::cout << "6. Mostrar Empleados de un Piso\n";
        std::cout << "7. Mostrar Ventas de Empleado\n";
        std::cout << "8. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> option;

        switch (option) {
        case 1:
            addFloor();
            break;
        case 2:
            deleteFloor();
            break;
        case 3:
            addEmployee();
            break;
        case 4:
            addSale();
            break;
        case 5:
            showFloorsInfo();
            break;
        case 6:
            showEmployeesInfo();
            break;
        case 7:
            showSalesOfEmployee();
            break;
        case 8:
            std::cout << "Saliendo del programa...\n";
            break;
        default:
            std::cout << "Opción inválida. Por favor, intente nuevamente.\n";
        }
    } while (option != 8);
}

void Program::addFloor() {
    int floorNumber = 0;
    system("cls");
    cout << "--------Ingrese los datos del piso--------\n";
    cout << "Numero de Piso: ";
    cin >> floorNumber;

    this->list.insertFloor(new FloorNode(floorNumber, 0));
    system("pause");
}

void Program::deleteFloor() {
    int toDeleteNumber = 0, toTransferNumber = 0;
    system("cls");
    cout << "----Ingrese los datos para eliminar el piso----\n";
    cout << "Numero de Piso a Borrar: ";
    cin >> toDeleteNumber;
    cout << "Numero de Piso a Transferir (Los empleados del piso a borrar tiene que migrar a otro piso): ";
    cin >> toTransferNumber;

    list.deleteFloor(toDeleteNumber, toTransferNumber);
    system("pause");
}

void Program::addEmployee() {
    int floorNumber = 0, employeeId = 0;
    string employeeName = "";
    system("cls");
    cout << "--------Ingrese los datos del empleado--------\n";
    cout << "Numero de piso donde trabaja el empleado: ";
    cin >> floorNumber;
    cout << "Nombre: ";
    cin >> employeeName;
    cout << "Identificacion: ";
    cin >> employeeId;

    this->list.insertEmployeeByFloor(floorNumber, new EmployeeNode(employeeName, 0, employeeId));
    system("pause");
}

void Program::addSale() {
    double floorNumber = 0, price = 0, employeeId = 0;
    system("cls");
    cout << "--------Ingrese los datos de la venta--------\n";
    cout << "Numero de piso donde se hizo la venta: ";
    cin >> floorNumber;
    list.printEmployeesOfFloor(floorNumber);
    cout << "\n";
    cout << "Identificacion del empleado que hizo la venta: ";
    cin >> employeeId;
    cout << "Total de la venta: ";
    cin >> price;

    list.insertSaleByFloorAndEmployeeId(floorNumber, employeeId, new SaleNode(price));
    system("pause");
}

void Program::showFloorsInfo() {
    system("cls");
    cout << "--------Pisos actuales--------\n";
    cout << "\tPiso |  Total\n";
    list.printFloorsInfo();
    cout << "\n";
    system("pause");
}

void Program::showEmployeesInfo() {
    int floorNumber = 0;
    system("cls");
    cout << "Numero de piso de los empleados: ";
    cin >> floorNumber;
    system("cls");
    cout << "----Empleados actuales----\n";
    cout << "\Id | Nombre| Total\n";
    list.printEmployeesOfFloorInfo(floorNumber);
    cout << "\n";
    system("pause");
}

void Program::showSalesOfEmployee() {
    int floorNumber = 0, employeeId = 0;;
    system("cls");
    cout << "Numero de piso del empleado: ";
    cin >> floorNumber;
    list.printEmployeesOfFloor(floorNumber);
    cout << "\n";
    cout << "Identificacion del empleado: ";
    cin >> employeeId;
    system("cls");
    cout << "----Ventas del empleado seleccionado----\n";
    list.printSalesByFloorAndEmployeeId(floorNumber, employeeId);
    cout << "\n";
    system("pause");
}