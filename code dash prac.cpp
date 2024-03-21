#include <iostream>
#include <cmath>
#include <string>
using namespace std;


struct Hospital {
	
	string name, productName;
	int age,quantity, productNumber;
	double price, weight, height;

	void PatientData() {
		cout << "\n-----------------------\n"
			<< "Patient name: " << name << "\n"
			<< "Patient age: " << age << "\n"
			<< "Patient height: " << height << "\n"
			<< "Patient weight: " << weight << "\n"
			<< "-----------------------\n";
	}
};

struct NodePatients {
	Hospital patient;
	NodePatients* next;
};

struct NodeProducts {
	Hospital products;
	NodeProducts* next;
};


int ChooseRole();
int EmployeeMainMenu();
int PatientMainMenu();
void AddPatientData(Hospital&);
void AddRecord(Hospital&, NodePatients*&, NodePatients*&);
void ViewRecord(NodePatients*&);
void AddProductData(Hospital&);
void ClearPatientRecord(NodePatients*&);
void AddProductRecord(Hospital&, NodeProducts*&, NodeProducts*&);
void ViewProducts(NodeProducts*&);
void BuyProducts(Hospital&, NodeProducts*&, NodeProducts*&);
void ComputeBMI(Hospital&, NodePatients*&);


int main()
{
	Hospital patient, product;
	NodePatients* headPatient = NULL, * tailPatient = NULL;
	NodeProducts* headProduct = NULL, * tailProduct = NULL;
	int employeeChoice, patientChoice, pickRole = 0; 
	string employeeName, employeePassword;
	
	do {
			pickRole = ChooseRole();

			if (pickRole == 1) {
			
				do {
					do {
						patientChoice = PatientMainMenu();
						switch (patientChoice)
						{
						case 1:
							break;
						case 2:
							ViewProducts(headProduct);
							BuyProducts(product, headProduct, tailProduct);
							break;
						case 3:

							break;
						case 4:
							cout << ".";
							system("CLS");
							break;
						case 0:
							cout << "Thank you for using the program! \n";
							system("pause");
							exit(0);
						default:
							cout << "Incorrect choice\n";
							system("pause");
							system("CLS");
							break;
						}
					} while (patientChoice != 4);

				} while (patientChoice >= 1 && patientChoice <= 3);
			}
		

		else if (pickRole == 2) {
		
				do {
					system("CLS");
					cout << "Enter employee name: "; cin >> employeeName;
					cout << "Enter employee password: "; cin >> employeePassword;

				} while (employeeName != "Adrian" || employeePassword != "IloveyousomuchZyrah");
			
			system("CLS");
			do {
				do {
					employeeChoice = EmployeeMainMenu();
					switch (employeeChoice)
					{
					case 1:
						AddPatientData(patient);
						AddRecord(patient, headPatient, tailPatient);
						break;
					case 2:
						ViewRecord(headPatient);
						break;
					case 3:
						AddProductData(product);
						AddProductRecord(product, headProduct, tailProduct);
						break;
					case 4:
						ViewProducts(headProduct);
						break;
					case 5:
						ComputeBMI(patient, headPatient);
						break;
					case 6:
						ClearPatientRecord(headPatient);
					case 7:
						cout << "Returning to main menu\n";
						system("pause");
						system("CLS");
						break;
					case 0:
						cout << "Thank you for using the program! \n";
						system("pause");
						exit(0);
					default:
						cout << "Incorrect choice\n";
						system("pause");
						system("CLS");
						break;
					}
					
				} while (employeeChoice != 7);
				
			} while (employeeChoice >= 1 && employeeChoice <= 6);
		}

	} while (true);
	return 0;
}


int ChooseRole() {
	int role;
	do {
		cout << "--------------------------------------\n"
			<< "|               HOSPITAL              |\n"
			<< "---------------------------------------\n"
			<< "| 1 - Patient      | 2 - Employee     |\n"
			<< "|          0 - Exit Program           |\n"
			<< "---------------------------------------\n"
			<< "\n Enter choice here: "; cin >> role;

		system("CLS");

		if (role == 0) {
			cout << "Thank you!\n";
			system("pause");
			system("CLS");
		}

	} while (role < 1 || role > 2);

	return role;
}


int EmployeeMainMenu() {

	int menuChoice;

	cout << "==============================================\n"
		<< "                 Employee Menu\n"
		<< "==============================================\n"
		<< "1. Add patient record\n"
		<< "2. View patient records\n"
		<< "3. Add product list\n"
		<< "4. View product list\n"
		<< "5. Compute BMI\n"
		<< "6. Clear patient record\n"
		<< "7. Go back to choose role\n"
		<< "0. Exit\n"
		<< "\nEnter choice here: ";
	cin >> menuChoice;

	system("CLS");

	return menuChoice;
}

int PatientMainMenu() {
	int patientChoice;

	cout << "==============================================\n"
		<< "                 Patient Menu\n"
		<< "==============================================\n"
		<< "1. View product list\n"
		<< "2. Buy products\n"
		<< "3. History\n"
		<< "4. Go back to choose role\n"
		<< "0. Exit\n"
		<< "\nEnter choice here: ";
	cin >> patientChoice;

	system("CLS");

	return patientChoice;
}

void AddPatientData(Hospital& patientInfo) {
	cout << "Enter patient name: ";
	cin >> patientInfo.name;
	cout << "Enter patient age: ";
	cin >> patientInfo.age;
	cout << "Enter patient height: ";
	cin >> patientInfo.height;
	cout << "Enter patient weight: ";
	cin >> patientInfo.weight;
}

void AddRecord(Hospital& patientInfo, NodePatients*& headPatient, NodePatients*& tailPatient) {
	NodePatients* temp = new NodePatients;
	temp -> patient = patientInfo;
	temp->next = NULL;

	if (!headPatient)
	{
		headPatient = temp;
	}
	else
	tailPatient->next=temp;
	tailPatient = temp;
	system("pause");
	system("CLS");
}

void ViewRecord(NodePatients*& headPatient) {
	NodePatients* temp = headPatient;

	if (!headPatient) {
		cout << "No patient info yet!";
	}
	else {
		while (temp)
		{
			temp->patient.PatientData();
			temp = temp->next;
		}

	}
	cout << "\n";
	system("pause");
	system("CLS");
}

void ClearPatientRecord(NodePatients*& headPatient)
{
	NodePatients* temp = NULL, * current = headPatient;

	if (!headPatient)
		cout << "No Patient Records Yet!\n\n";
	else
	{
		while (temp)
		{
			temp = current->next;
			delete current;
			current = temp;
		}

		cout << "Patient Record Cleared!\n";
	}

	cout << "\n";
	system("pause");
	system("cls");
}

void AddProductData(Hospital& productInfo) {
	cout << "Enter product number: ";
	cin >> productInfo.productNumber;
	cout << "Enter product name: ";
	cin >> productInfo.productName;
	cout << "Enter product quantity: ";
	cin >> productInfo.quantity;
	cout << "Enter product price: ";
	cin >> productInfo.price;
}

void AddProductRecord(Hospital& productInfo, NodeProducts*& headProduct, NodeProducts*& tailProduct) {
	NodeProducts* temp = new NodeProducts;
	temp->products = productInfo;
	temp->next = NULL;

	if (!headProduct)
	{
		headProduct = temp;
	}
	else
		tailProduct->next = temp;
	tailProduct = temp;
	system("pause");
	system("CLS");
}

void ViewProducts(NodeProducts*& headProduct) {
	NodeProducts* temp = headProduct;

	if (!headProduct) {
		cout << "No products yet!";
	}
	else {
		while (temp)
		{
			cout << "\n-----------------------\n"
				<< "Product number: " << temp->products.productNumber << "\n"
				<< "Product name: " << temp->products.productName << "\n"
				<< "Product quantity: " << temp->products.quantity << "\n"
				<< "Product price: " << temp->products.price << "\n"
				<< "-----------------------\n";
			temp = temp->next;
		}
	}
	cout << "\n";
	system("pause");
	system("CLS");
}

void BuyProducts(Hospital& productInfo, NodeProducts*& headProduct, NodeProducts*& tailProduct) {
	NodeProducts* current = headProduct;
	int chooseProducts, chooseProductQuantity;
	double totalAmount = 0;

	cout << "Enter product number: ";
	cin >> chooseProducts;

	while (current != nullptr && current->products.productNumber != chooseProducts) {
		current = current->next;
	}

	if (current == nullptr) {
		cout << "Product not found!" << endl;
		return;
	}

	cout << "\n\nChosen product details:\n"
		<< "Product Name: " << current->products.productName << "\n"
		<< "Product Quantity: " << current->products.quantity << "\n"
		<< "Product Price: " << current->products.price << "\n\n";

	cout << "Choose how many quantity: ";
	cin >> chooseProductQuantity;

	if (chooseProductQuantity > current->products.quantity) {
		cout << "Not enough quantity available!" << endl;
	}
	else {
		current->products.quantity -= chooseProductQuantity;
		totalAmount = chooseProductQuantity * current->products.price;
		cout << "Total amount for chosen products: " << totalAmount << endl;
	}

	system("pause");
	system("CLS");
}

void ComputeBMI(Hospital& patientInfo, NodePatients*& headPatient) {
	NodePatients* temp = headPatient;
	double bodyMassIndex;

	if (!headPatient) {
		cout << "No records yet!";
	}
	else {
		while (temp != nullptr) {
			bodyMassIndex = ((temp->patient.weight) * 703 / (temp->patient.height * temp->patient.height));
			cout << "----------------------------------\n"
			     << "Patient Name: " << temp->patient.name;
			cout << "\nBMI: " << bodyMassIndex;
			cout << "\n----------------------------------\n";
			temp = temp->next;
		}

		system("pause");
		system("CLS");
	}
}
