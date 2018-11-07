// author:	Kathryn Silva
// course:	CS 202-003

#include "scanner.h"

void get_string(char* input, int length) {
	cin.get(input, length, '\n');
	while (cin.peek() != '\n') {
		cout << "Invalid length. Enter a shorter string: ";
		cin.ignore(1000, '\n');
		cin.get(input, length, '\n');
	}
	cin.ignore(1000, '\n');	
}

void get_string(char* input) {
	const int length = 10000; // arbitrary limit
	//input[length];
	cin.get(input, length, '\n');
	while (cin.peek() != '\n') {
		cout << "Invalid length. Enter a shorter string: ";
		cin.ignore(1000, '\n');
		cin.get(input, length, '\n');
	}
	cin.ignore(1000, '\n');	
}

void get_int(int& input, int min, int max) {
	cin >> input;
	while (input > max || input < min) {
		cout << "Invalid entry. Enter a number in the range [";
		cout << min << ", " << max << "]: ";
		cin >> input;
	}
}

void get_pos_int(int& input) {
	cin >> input;
	while (input <= 0) {
		cout << "Invalid entry. Enter a positive number: ";
		cin >> input;
	}
}

void get_up_char(char& input) {
    cin >> input;
    cin.ignore(100, '\n'); 
    input = toupper(input);
}

bool yes() {
	char input;
	get_up_char(input);
    while (input != 'Y' && input != 'N') {
        cout << "Invalid response. (y/n): ";
        get_up_char(input);
    }
    return input == 'Y';
}

void capitalize(char* input) {
	bool cap = false;
	input[0] = toupper(input[0]);
	for (int i = 0; input[i] != '\0'; ++i) {
		if (cap) {
			input[i] = toupper(input[i]);
			cap = false;
		} 
	
		if (input[i] == ' ') 
			cap = true;
	}
}
