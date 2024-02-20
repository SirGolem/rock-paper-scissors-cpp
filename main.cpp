#include <string>
#include <iostream>

enum Choice
{
    ROCK,
    PAPER,
    SCISSORS
};

const std::string ChoiceStrings[] = {"Rock", "Paper", "Scissors"};

int generateComputerChoice(void);

void computerWins(void);
void playerWins(void);

int main()
{
    srand(time(NULL));

    std::cout << "Rock Paper Scissors, made by SirGolem" << std::endl
              << std::endl;

    std::cout << "\tRock: " << ROCK << std::endl;
    std::cout << "\tPaper: " << PAPER << std::endl;
    std::cout << "\tScissors: " << SCISSORS << std::endl
              << std::endl;

    int computerChoice = generateComputerChoice();
    int playerChoice;

    do
    {
        if (playerChoice == computerChoice)
        {
            computerChoice = generateComputerChoice();
            std::cout << "Match! Try again." << std::endl;
        }

        std::cout << "> Make your selection: ";
        std::cin >> playerChoice;
    } while (playerChoice < ROCK || playerChoice > SCISSORS || playerChoice == computerChoice);

    std::cout << "\tComputer: " << ChoiceStrings[computerChoice] << std::endl;
    std::cout << "\tYou: " << ChoiceStrings[playerChoice] << std::endl;

    switch (computerChoice)
    {
    case ROCK:
        if (playerChoice == PAPER)
            playerWins();
        else
            computerWins();
        break;
    case PAPER:
        if (playerChoice == SCISSORS)
            playerWins();
        else
            computerWins();
        break;
    case SCISSORS:
        if (playerChoice == ROCK)
            playerWins();
        else
            computerWins();
        break;
    }

    return 0;
}

int generateComputerChoice()
{
    return rand() % (SCISSORS + 1);
}

void computerWins()
{
    std::cout << "> You lost. Better luck next time." << std::endl;
}

void playerWins()
{
    std::cout << "> Congratulations, you won!" << std::endl;
}