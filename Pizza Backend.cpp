// ConsoleApplication1.cpp : Defines the entry point for the console application.
//


#include <string>
#include <iostream>
#include <iomanip>



class items {
protected:
	std::string item="";
	double price=0;
	items* next = nullptr;
public:
	
	double getPrice() {
		return price;
	}
	std::string getItem() {
		return item;
	}
	items* getNext() {
		return next;
	}
	void setNext(items* nxt) {
		next = nxt;
		return;
	}
	virtual bool addTopping(std::string topping) {
		return 1;
	}
	virtual bool changeSize(std::string size) {
		return 1;
	}
};

class pizza : public items{
private:
	bool nonMod=false;

public:
	pizza() {
		item = "Custom Pizza\n Tomato\n Cheese\n";
		price = 7.99;
		nonMod = false;
	}
	pizza(std::string house) {
		if (house == "Pizza Margherita") {
			item = "House Pizza\n Tomato\n Cheese\n";
			price = 7.99;
			nonMod = true;
		}
		if (house == "Hawaiian Pizza") {
			item = "House Pizza\n Tomato\n Cheese\n Ham\n Pineapple\n";
			price = 8.99;
			nonMod = true;
		}
		if (house == "Meat Lovers") {
			item = "House Pizza\n Tomato\n Cheese\n Ham\n Pepperoni\n";
			price = 9.99;
			nonMod = true;
		}
	}
	bool addTopping(std::string topping) {
		if (nonMod)
			return 1;
		item += " ";
		if (topping == "Cheese") {
			item += topping;
			item += "\n";
			price += .75;
			return 0;
		}
		if (topping == "Ham") {
			item += topping;
			item += "\n";
			price += .99;
			return 0;
		}
		if (topping == "Pepperoni") {
			item += topping;
			item += "\n";
			price += .99;
			return 0;
		}
		if (topping == "Green Pepper") {
			item += topping;
			item += "\n";
			price += .89;
			return 0;
		}
		if (topping == "Onions") {
			item += topping;
			item += "\n";
			price += .89;
			return 0;
		}
		if (topping == "Mushrooms") {
			item += topping;
			item += "\n";
			price += .89;
			return 0;
		}
		if (topping == "Pineapple") {
			item += topping;
			item += "\n";
			price += .99;
		}
		return 1;
	}
	bool changeSize(std::string size) {

		item += " ";
		if (size == "Individual") {
			item += size;
			item += "\n";
			price += -3.99;
			return 0;
		}
		if (size == "Family") {
			item += size;
			item += "\n";
			price += 5.99;
			return 0;
		}
		return 1;
	}
	
};

class drink : public items{					//Defaults to Soda

public:
	drink() {
		item = "Soda\n";
		price = 1.29;
	}
	drink(std::string type) {
		if (type == "Soda") {
			item = type + "\n";
			price = 1.29;
		}
		if (type == "Diet Soda") {
			item = type + "\n";
			price = 1.29;
		}
		if (type == "Bad Cheap Beer") {
			item = type + "\n";
			price = 4.99;
		}
	}

};

class merchandise : public items{

public:
	merchandise(std::string type) {
		if (type == "Shirt") {
			item = type + "\n";
			price = 21.99;
		}
		if (type == "Mug") {
			item = type + "\n";
			price = 4.99;
		}
	}

};

class order {
	items* start = nullptr;
	items* last = nullptr;
	items* newPtr = nullptr;
public:
	void newDrink(std::string in) {
		newPtr = new drink(in);
		if (start == nullptr) {
			start = newPtr;
			last = newPtr;
		}
		else {
			last->setNext(newPtr);
			last = newPtr;
		}
	}

	void newCustomPizza() {
		newPtr = new pizza();
		if (start == nullptr) {
			start = newPtr;
			last = newPtr;
		}
		else {
			last->setNext(newPtr);
			last = newPtr;
		}
	}

	void newHousePizza(std::string in) {
		newPtr = new pizza(in);
		if (start == nullptr) {
			start = newPtr;
			last = newPtr;
		}
		else {
			last->setNext(newPtr);
			last = newPtr;
		}
	}

	void newMerchandise(std::string in) {
		newPtr = new merchandise(in);
		if (start == nullptr) {
			start = newPtr;
			last = newPtr;
		}
		else {
			last->setNext(newPtr);
			last = newPtr;
		}
	}
	void addTopping(std::string in) {
		last->addTopping(in);
	}
	void changeSize(std::string in) {
		last->changeSize(in);
	}

	void getOrder() {
		newPtr = start;
		double sum = 0;
		while (newPtr != nullptr) {
			std::cout << newPtr->getItem();
			sum += newPtr->getPrice();
			newPtr = newPtr->getNext();
		}
		std::cout << "The Price for your order is $" << std::setprecision(2) << std::fixed << sum << std::endl;
	}

};

void getOptions(std::string choice){
	if (choice == "NewDrink") {
		std::cout << "Soda\nDiet Soda\nBad Cheap Beer\n";
	}
	if (choice == "NewHousePizza") {
		std::cout << "Pizza Margherita\nHawaiian Pizza\nMeat Lovers\n";
	}
	if (choice == "NewMerchandise") {
		std::cout << "Shirt\nMug\n";
	}
	if (choice == "AddTopping") {
		std::cout << "Cheese\nHam\nPepperoni\nGreen Pepper\nOnions\nMushrooms\nPineapple\n";
	}
	if (choice == "ChangeSize") {
		std::cout << "Family\nIndividual\n";
	}
}

int main(){
	std::string input = "";
	order* a;
	a = new order;
	std::cout << "Input Options\nNewCustomPizza\nNewDrink\nNewHousePizza\nNewMerchandise\nAddTopping\nChangeSize\nGetOrder\n\n";
	while (input != "end") {

		std::getline(std::cin, input);
		
		if (input == "NewCustomPizza")
			a->newCustomPizza();
		if (input == "NewDrink") {
			std::cout << "What kind of drink?\n";
			getOptions(input);
			std::getline(std::cin, input);
			a->newDrink(input);
		}
		if (input == "NewHousePizza") {
			std::cout << "What kind of Pizza?\n";
			getOptions(input);
			std::getline(std::cin,input);
			a->newHousePizza(input);
		}
		if (input == "NewMerchandise") {
			std::cout << "What kind of Merchandise?\n";
			getOptions(input);
			std::cin >> input;
			a->newMerchandise(input);
		}
		if (input == "AddTopping") {
			std::cout << "What kind of Topping?\n";
			getOptions(input);
			std::getline(std::cin, input);
			a->addTopping(input);
		}
		if (input == "GetOrder") {
			a->getOrder();
			delete a;
			a = new order;
		}
		if (input == "ChangeSize") {
			std::cout << "What size?\n";
			getOptions(input);
			std::getline(std::cin, input);
			a->changeSize(input);
		}
	}
	system("pause");
	return 0;
}