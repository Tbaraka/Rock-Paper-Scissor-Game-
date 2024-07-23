#include <ctime>
#include <iostream>

char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player, char computer);

int main() {
    char playAgain;

    do {
        char player;
        char computer;

        player = getUserChoice();
        std::cout << "Your choice: ";
        showChoice(player);

        computer = getComputerChoice();
        std::cout << "Computer's choice: ";
        showChoice(computer);

        chooseWinner(player, computer);

        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y');

    return 0;
}

char getUserChoice() {
    char player;
    std::cout << "Rock-Paper-Scissors Game!\n";

    do {
        std::cout << "Choose one of the following\n";
        std::cout << "*************************\n";
        std::cout << "'r' for rock\n";
        std::cout << "'p' for paper\n";
        std::cout << "'s' for scissors\n";
        std::cin >> player;
    } while (player != 'r' && player != 'p' && player != 's');

    return player;
}

char getComputerChoice() {
    srand(time(0));
    int num = rand() % 3 + 1;

    switch (num) {
        case 1: return 'r';
        case 2: return 'p';
        case 3: return 's';
    }

    return 0;
}

void showChoice(char choice) {
    switch (choice) {
        case 'r': std::cout << "Rock\n";
                  break;
        case 'p': std::cout << "Paper\n";
                  break;
        case 's': std::cout << "Scissors\n";
                  break;
    }
}

void chooseWinner(char player, char computer) {
    if (player == computer) {
        std::cout << "It's a tie!\n";
    } else if ((player == 'r' && computer == 's') ||
               (player == 'p' && computer == 'r') ||
               (player == 's' && computer == 'p')) {
        std::cout << "You win!\n";
    } else {
        std::cout << "You lose!\n";
    }
}