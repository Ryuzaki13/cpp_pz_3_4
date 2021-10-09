#include <iostream>
#include <list>
#include "headers/product.h"

using namespace std;

// ������ ��������� ���������
Product products[] = {
		Product("�������� � ���������", 255),
		Product("�����", 495),
		Product("�����", 265),
		Product("����-����", 90),
};
// �������� � ��������� ����� ������� ���������, ����� ������ ��� �� �����������
const int commandLength = sizeof(products) / sizeof(Product);
// ��� ���! ����� ������������� ��� ������ ������ ��������
float receipt = 0.0f;

list<const Product*> receiptList = list<const Product*>();

// �������� ������� � ���������� ������ ������.
// ��������� ������, ������� ����� �������� ����� ������� ������
void printCommands(const char*);

// ��������� ��������� ������� � ������� ���������
bool checkCommands(int, char**);

// ������ ��� ������������
void calculateReceipt();

int main() {
	setlocale(LC_ALL, "rus");

	// ���������� ���������� ��� ����� ������������� ������ �������
	int input = -1;

	// ��������� �� ������, ������� ����� ������� ����� ������� ������
	// ��� ����� ��������� ���������� � ��������� ��������
	char** message = new char* { nullptr };

	// ������ ������ "�������"
	bool running = true;

	// ��������� ����, ����� ������������ ��� ���������� �������� �������
	while (running) {
		// ������� ������ ������ (��� ������ �������� message ��������� �� null
		// ������� ��� �� ����� ��������
		printCommands(*message);

		// �������� ����� ������������� �����
		cin >> input;

		// ��������� ��� ���� ������������ � � message ����� ���������
		// ���� ������� ��������� 0, ����� ������� ������ false
		running = checkCommands(input, message);
	}

	// windows cmd
	system("cls");

	// unix cmd
	//system("clear");

	//cout << "��� ��� ���������� " << receipt << " ������" << "\n\n";
	calculateReceipt();

	return 0;
}

void printCommands(const char* prepend) {
	// windows cmd
	system("cls");

	// unix cmd
	//system("clear");

	// ���� ��������� �� ������, ����� ������� ��� ������
	if (prepend != nullptr) {
		cout << prepend << "\n\n";
	}

	// ����� ������� ��� �������
	for (int i = 0; i < commandLength; i++) {
		cout << i + 1 << ". " << products[i].Name << "(" << products[i].Price << "�.)\n";
	}

	// � �������� �������������� ����������
	cout << "\n0. ������� �����" << "\n";
	cout << "������� ����� �������" << "\n\n";
}

bool checkCommands(int cmd, char** message) {
	// �������� ������ ��� ���������
	*message = new char[128];

	// ���� ������� ���� ��� ��������� ������ ���������
	if (cmd < 1 || cmd > commandLength) {
		// ����������� ������ � ���������� ������
		strcpy(*message, "�������� �������");
		// ������� false, ���� cmd = 0
		return cmd != 0;
	}

	// ������� �������� �� 1 �� N, ��� ������ � �������� ��������� �� �������
	cmd--;

	Product* selectedProduct = &products[cmd];

	// ��������� ���
	receipt += selectedProduct->Price;

	receiptList.push_back(selectedProduct);

	// ����������� � ���������� ������ ��������������� ������
	sprintf(*message, "�� �������: %s �� ���� %.2f ���", selectedProduct->Name, selectedProduct->Price);

	// ������� ������� ���������, ������� ���������� true
	return true;
}

void calculateReceipt() {

	cout << "==================================" << "\n\n";
	cout << "��� ��� ���������� " << receipt << " ������" << "\n\n";
	cout << "==================================" << "\n\n";

	for (list<const Product*>::iterator itr = receiptList.begin(); itr != receiptList.end(); itr++) {
		cout << (*itr)->Name << " " << (*itr)->Price << " ���.\n";
	}

	cout << "\n======= ������� �� ������� =======" << "\n";
	cout << "==================================" << "\n\n";
}