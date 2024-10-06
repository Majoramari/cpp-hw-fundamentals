#include <iostream>
#include <random>

using namespace std;

enum class GameMove {
	ROCK = 1,
	PAPER,
	SCISSORS
};

enum class EndState {
	WIN = 1,
	LOSE,
	TIE
};

int get_round_number() {
	int round_number;
	do {
		cout << "Enter round number: ";
		cin >> round_number;
	} while (round_number < 1);
	return round_number;
}

GameMove get_user_input() {
	int input;
	do {
		cout << "Enter 1 for rock, 2 for paper, 3 for scissors: ";
		cin >> input;
	} while (input < 1 || input > 3);
	return static_cast<GameMove>(input);
}

GameMove get_computer_input() {
	random_device rd;
	mt19937::result_type seed = rd();
	mt19937 gen(seed);

	uniform_int_distribution distribution(1, 3);

	return static_cast<GameMove>(distribution(gen));
}

EndState get_winner(const GameMove user_input, const GameMove computer_input) {
	if (user_input == computer_input)
		return EndState::TIE;

	if (
		user_input == GameMove::ROCK && computer_input == GameMove::SCISSORS
		|| user_input == GameMove::PAPER && computer_input == GameMove::ROCK
		|| user_input == GameMove::SCISSORS && computer_input == GameMove::PAPER
	)
		return EndState::WIN;

	return EndState::LOSE;
}

EndState play_round() {
	GameMove user_input = get_user_input();
	GameMove computer_input = get_computer_input();

	cout << "You chose: " << static_cast<int>(user_input) << endl;
	cout << "Computer chose: " << static_cast<int>(computer_input) << endl;

	return get_winner(user_input, computer_input);
}

void start_game() {
	const int round_number = get_round_number();
	int win = 0, lose = 0, tie = 0;

	for (int i = 0; i < round_number; i++) {
		switch (play_round()) {
			case EndState::WIN:
				win++;
				cout << "You win!" << endl;
				break;
			case EndState::LOSE:
				lose++;
				cout << "You lose!" << endl;
				break;
			case EndState::TIE:
				tie++;
				cout << "Tie!" << endl;
				break;
		}
		cout << endl;
	}

	cout << "You won " << win << " rounds." << endl;
	cout << "You lose " << lose << " rounds." << endl;
	cout << "You tie " << tie << " rounds." << endl;

	if (win > lose)
		cout << "You win the game!" << endl;
	else if (win < lose)
		cout << "You lose the game!" << endl;
	else
		cout << "Tie!" << endl;
}

int main() {
	start_game();
	return 0;
}
