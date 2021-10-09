#include <iostream>
#include <list>
#include "headers/product.h"

using namespace std;

// Массив продуктов ресторана
Product products[] = {
		Product("Рулетики с шоколадом", 255),
		Product("Пицца", 495),
		Product("Роллы", 265),
		Product("Кока-кола", 90),
};
// Записать в константу длину массива продуктов, чтобы каждый раз не высчитывать
const int commandLength = sizeof(products) / sizeof(Product);
// Это чек! Будет увеличиваться при каждом выборе продукта
float receipt = 0.0f;

list<const Product*> receiptList = list<const Product*>();

// Очистить консоль и напечатать список команд.
// Принимает строку, которая будет выведена перед списком команд
void printCommands(const char*);

// Проверить выбранную команду и вернуть сообщение
bool checkCommands(int, char**);

// Выдать чек пользователю
void calculateReceipt();

int main() {
	setlocale(LC_ALL, "rus");

	// Объявление переменной для ввода пользователем номера команды
	int input = -1;

	// Указатель на строку, которую нужно вывести перед списком команд
	// Она будет содержать информацию о выбранном продукте
	char** message = new char* { nullptr };

	// Флажок работы "заказов"
	bool running = true;

	// Запустить цикл, чтобы пользователь мог циклически выбирать команды
	while (running) {
		// Вывести списко команд (при первой итерации message указывает на null
		// поэтому оно не будет выведено
		printCommands(*message);

		// Ожидание ввода пользователем числа
		cin >> input;

		// Проверяем что ввел пользователь и в message пишем сообщение
		// Если команда равняется 0, тогда функция вернет false
		running = checkCommands(input, message);
	}

	// windows cmd
	system("cls");

	// unix cmd
	//system("clear");

	//cout << "Ваш чек составляет " << receipt << " рублей" << "\n\n";
	calculateReceipt();

	return 0;
}

void printCommands(const char* prepend) {
	// windows cmd
	system("cls");

	// unix cmd
	//system("clear");

	// Если указатель не пустой, тогда вывести эту строку
	if (prepend != nullptr) {
		cout << prepend << "\n\n";
	}

	// Затем вывести все команды
	for (int i = 0; i < commandLength; i++) {
		cout << i + 1 << ". " << products[i].Name << "(" << products[i].Price << "р.)\n";
	}

	// И добавить дополнительную информацию
	cout << "\n0. Сделать заказ" << "\n";
	cout << "Введите номер команды" << "\n\n";
}

bool checkCommands(int cmd, char** message) {
	// Выделить память под сообщение
	*message = new char[128];

	// Если команда была вне диапазона списка продуктов
	if (cmd < 1 || cmd > commandLength) {
		// Скопировать строку в выделенную память
		strcpy(*message, "Неверная команда");
		// Вернуть false, если cmd = 0
		return cmd != 0;
	}

	// Команда вводится от 1 до N, для работы с массивом уменьшить на единицу
	cmd--;

	Product* selectedProduct = &products[cmd];

	// Пополнить чек
	receipt += selectedProduct->Price;

	receiptList.push_back(selectedProduct);

	// Скопировать в выделенную память форматированную строку
	sprintf(*message, "Вы выбрали: %s по цене %.2f руб", selectedProduct->Name, selectedProduct->Price);

	// Команда выбрана корректно, поэтому возвращаем true
	return true;
}

void calculateReceipt() {

	cout << "==================================" << "\n\n";
	cout << "Ваш чек составляет " << receipt << " рублей" << "\n\n";
	cout << "==================================" << "\n\n";

	for (list<const Product*>::iterator itr = receiptList.begin(); itr != receiptList.end(); itr++) {
		cout << (*itr)->Name << " " << (*itr)->Price << " руб.\n";
	}

	cout << "\n======= СПАСИБО ЗА ПОКУПКУ =======" << "\n";
	cout << "==================================" << "\n\n";
}