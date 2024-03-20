#include <iostream>
#include <cmath>
#include <string>
using namespace std;


struct Hospital {
	string name, productName;
	int age,quantity;
	double price, weight, height;

	void PatientData() {
		cout << "\n-----------------------\n"
			<< "Patient name: " << name << "\n"
			<< "Patient age: " << age << "\n"
			<< "Patient height: " << height << "\n"
			<< "Patient weight: " << weight << "\n";
	}

	void ProductData() {
		cout << "\n-----------------------\n"
			<< "Product name: " << productName << "\n"
			<< "Product quantity: " << quantity << "\n"
			<< "Product price: " << price << "\n";
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
void AddProductRecord(Hospital&, NodeProducts*&, NodeProducts*&);
void ViewProducts(NodeProducts*&);
void ComputeBMI(Hospital&, NodePatients*&);


int main()
{
	Hospital patient, product;
	NodePatients* headPatient = NULL, * tailPatient = NULL;
	NodeProducts* headProduct = NULL, * tailProduct = NULL;
	int employeeChoice, patientChoice, role = 0; 
	
	do {
		role = ChooseRole();

		if (role == 1) {
			do {
				patientChoice = PatientMainMenu();
				switch (patientChoice)
				{
				case 1:
					ViewProducts(headProduct);
					break;
				case 2:
					
					break;
				case 3:

					break;
				case 0:
					cout << "Thank you for using the program! \n";
					system("pause");
					exit(0);
				default:
					break;
				}
			} while (patientChoice >= 1 || patientChoice <= 3);

		}


		else if (role == 2) {

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
				case 0:
					cout << "Thank you for using the program! \n";
					system("pause");
					exit(0);
				default:
					break;
				}
			} while (employeeChoice >= 1 || employeeChoice <= 4);
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
		<< "                 Hospital Menu\n"
		<< "==============================================\n"
		<< "1. Add patient record\n"
		<< "2. View patient records\n"
		<< "3. Add product list\n"
		<< "4. View product list\n"
		<< "5. Compute BMI\n"
		<< "0. Exit\n"
		<< "\nEnter choice here: ";
	cin >> menuChoice;

	system("CLS");

	return menuChoice;
}

int PatientMainMenu() {
	int patientChoice;

	cout << "==============================================\n"
		<< "                 Hospital Menu\n"
		<< "==============================================\n"
		<< "1. View product list\n"
		<< "2. Buy products\n"
		<< "3. History\n"
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
	system("pause");
	system("CLS");

}

void AddProductData(Hospital& productInfo) {
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
			temp->products.ProductData();
			temp = temp->next;
		}
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
			cout << "Patient Name: " << temp->patient.name << endl;
			cout << "BMI: " << bodyMassIndex << endl;
			cout << "----------------------------------" << endl;
			temp = temp->next;
		}

		system("pause");
		system("CLS");
	}

}
