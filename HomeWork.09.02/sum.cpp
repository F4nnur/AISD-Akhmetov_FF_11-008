#include <iostream>
using namespace std;

int main() {
	
	int amount,numbers;
	int sum = 0;
	
	cin >> amount;

	for (int i = 0; i < amount; i++) {
		cin >> numbers;
		sum += numbers;
	}
	cout << sum;

}
