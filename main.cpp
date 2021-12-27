#include<iostream>

using namespace std;

enum {B500 = 1, B1000 = 4, B1500 = 7, B2000 = 9};

int getConsumption(int weight, int fuel = 300) {
	if (weight > 0) {
		if (weight < 500) {
			return B500;
		}
		if (weight < 1000) {
			return B1000;
		}
		if (weight < 1500) {
			return B1500;
		}
		if (weight < 2000) {
			return B2000;
		}
	}

	return -1;
}

void printError() {
	cout << "Fly is impossible" << endl;
}

int main() {
	const int fuel = 300;
	int firstPart, secondPart, weight;
	cout << "enter first part distance: ";
	cin >> firstPart;
	cout << "Enter second part distance: ";
	cin >> secondPart;
	cout << "Enter weight: ";
	cin >> weight;

	int consumption = getConsumption(weight, fuel);

	if (consumption != -1) {
		if (fuel >= (consumption * firstPart) + (consumption *  secondPart)) {
			cout << "no need more fuel" << endl;
		} else {
			int lastFuel = fuel - (consumption * firstPart);

			if (lastFuel >= 0) {
				int newFuel = (consumption * secondPart) - lastFuel;

				if (newFuel <= fuel) {
					cout << "we need: " << newFuel << " litres";
				} else {
					cout << "Needed amount of fuel is larger than tank" << endl;
					printError();
				}
			} else {
				cout << "First part of distance can't be walking" << endl;
				printError();
			}
		}
	} else {
		cout << "Too big wieght for fly, or negative" << endl;
		printError();
	}


	return 0;
}