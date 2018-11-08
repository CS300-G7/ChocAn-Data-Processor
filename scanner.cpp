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

void get_digits(int& input, int num_digits) {
	int divisor = 1;
	for (int i = 1; i < num_digits; ++i) divisor *= 10;
	
	cin >> input;
	while (input/divisor >= 10 || input/divisor < 1) {
		cout << "Invalid entry. Enter a " << num_digits << "-digit number: ";
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

void get_date(char& input) {

	char MM[2];
	char DD[2];
	char YYYY[4];
	bool done = false;

	do {
		cout << "Enter month (MM): "
		get_string(MM, 2);

		if (MM[0] == '0') 					// check 01-09
			if (MM[1] > '0' && MM[1] <= '9') done = true;
		if (MM[0] == '1') 					// check 10-12
			if (MM[1] >= '0' && MM[1] <= '2') done = true;

		if (!done) cout << "Invalid entry. ";

	} while (!done);
	done = false;
	 
	strcpy(input, MM);
	strcat(input, "-");
	
	do{
		cout << "Enter day (DD): ";
		get_string(DD, 2);

		if (DD[0] == '0') 					// check 01-09
			if (DD[1] > '0' && DD[1] <= '9') done = true;
		if (DD[0] == '1' || DD[0] == '2') 	// check 10-29
			if (DD[1] > '0' && DD[1] <= '9') done = true;
		if (DD[0] == '3') 					// check 30-31
			if (DD[1] == '0' || DD[1] == '1') done = true;

		if (!done) cout << "Invalid entry. ";

	} while (!done);
	done = false;

	strcat(input, DD);
	strcat(input, "-");

	do {
		cout << "Enter year (YYYY): ";
		get_string(YYYY, 4);

		if (YYYY[0] == '2') done = true; // This should never != '2'
		for (int i = 1; i <= 3; ++i) // Ensure rest of chars are digits
			if (YYYY[i] < '0' || YYYY[i] > '9') done = false; 

		if (!done) cout << "Invalid entry. ";

	} while (!done);
	done = false;

	strcat(input, YYYY);
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
