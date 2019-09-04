#include <iostream>
#include <random>
#include <ctime>
using namespace std;


char position[9] = { '1','2','3','4','5','6','7','8','9' };

void board(char position[]) {
	system("cls");
	cout << "-------------------------------" << endl;
	cout << "| Player 1 = X" << " & Player 2 = O |" << endl;
	cout << "-------------------------------" << endl;
	cout << "\t   |   |   " << endl;
	cout << "\t " << position[0] << " | " << position[1] << " | " << position[2] << " " << endl;
	cout << "\t___|___|___" << endl;
	cout << "\t   |   |   " << endl;
	cout << "\t " << position[3] << " | " << position[4] << " | " << position[5] << " " << endl;
	cout << "\t___|___|___" << endl;
	cout << "\t   |   |   " << endl;
	cout << "\t " << position[6] << " | " << position[7] << " | " << position[8] << " " << endl;
	cout << "\t   |   |   " << endl;

}

void decision() {
	int number;
	bool invalid = true;
	do {
		cout << "Choose your position: ";
		cin >> number;
		if (position[number - 1] == 'X' || position[number -1] == 'O')
			cout << "Position has been taken!" << endl;
		else if (number < 1 || number > 9) {
			cout << "Invalid number!" << endl;
		}
		else {
			position[number - 1] = 'X';
			invalid = false;
		}
	} while (invalid);
}

void bot(){
	bool invalid = true;
	do {
		srand(time(NULL));
		const int randomVal = (rand() % (9 + 1 - 1)) + 1;
		if (position[randomVal - 1] == 'X' || position[randomVal - 1] == 'O')
			invalid = true;
		else {
			position[randomVal - 1] = 'O';
			invalid = false;
		}
	} while (invalid);
	cout << "Player 2's Turn" << endl << endl;
	system("pause");
}

bool win() {
	//row
	if (position[0] == position[1] && position[1] == position[2])
		return 0;
	if (position[3] == position[4] && position[4] == position[5])
		return 0;
	if (position[6] == position[7] && position[7] == position[8])
		return 0;
	//column
	if (position[0] == position[3] && position[3] == position[6])
		return 0;
	if (position[1] == position[4] && position[4] == position[7])
		return 0;
	if (position[2] == position[5] && position[5] == position[8])
		return 0;
	//diagonal
	if (position[0] == position[4] && position[4] == position[8])
		return 0;
	if (position[2] == position[4] && position[4] == position[6])
		return 0;
	return 1;
}

int main() {
	bool play = true;
	int count = 0;
	do {
		board(position);
		decision();
		count++;
		board(position);
		play = win();
		if (play == 0) {
			cout << "Congratulations, you win!\n";
			break;
		}
		if (count == 9) {
			cout << "Tie!" << endl;
			break;
		}
		bot();
		count++;
		board(position);
		play = win();
		if (play == 0) {
			cout << "You lose!" << endl;
			break;
		}
		if (count == 9) {
			cout << "Tie!" << endl;
			break;
		}
	} while (play);
}