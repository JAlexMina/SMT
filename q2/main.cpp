#include <iostream>
#include <cstdio>
#include <string>


#ifdef _WIN32 // Includes both 32 bit and 64 bit
#define windows true
#else
#define windows false
#endif



//gameBoard Class that stores the gameBoard and
//whose turn it is, and all the functions to play
//the game
class gameBoard
{
private:
    char current_turn = 'X';
    char slots[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    void setSlot(int slotNumber);

public:
    void print();
    
    bool checkWin();
    void run();
    char getSlotInfo(int slotNumber);

};

//function such that an external tic tac toe
//interface might be able to use the game to
//perhaps draw it in a gui
//input: integer corresponding to the slot number
//output: the character associated with one of the players
//
char gameBoard::getSlotInfo(int slotNumber)
{
    return slots[slotNumber];
}


//function to print the gameBoard and the numberings
//input: Nothing
//output: Nothing
//
void gameBoard::print()
{
    std::printf("\n %d | %d | %d \n____________\n %d | %d | %d     <----------Each spot on the board is numbered\n____________\n %d | %d | %d                Enter a number to play in that spot\n\n\n",
        0, 1, 2, 3, 4, 5, 6, 7, 8);

    std::printf("It is: %c turn\n\n", current_turn);

    std::printf("\n %c | %c | %c \n____________\n %c | %c | %c \n____________\n %c | %c | %c \n",
        slots[0], slots[1], slots[2], slots[3], slots[4], slots[5], slots[6], slots[7], slots[8]);
}



//function to set a piece on the board (who ever's current turn it is)
//input: a slot number the player wants to
//       attempt to play on (the player whose
//       turn it is is gotten from the class
//       as well as the board information
//
//output: nothing, all the work this function
//        does is saved in the gameboard information
//
void gameBoard::setSlot(int slotNumber)
{
    if (slots[slotNumber] == ' ')
    {
        slots[slotNumber] = current_turn;
        if (current_turn == 'X')
        {
            current_turn = 'O';
        }
        else
        {
            current_turn = 'X';
        }
        if (windows) { system("cls"); }
        print();
    }
    else
    {
        std::printf("\nInvalid Move, Try again\n");
    }
}



//function to check and see if the game has been won
//input: nothing, it gets the gameboard info as its
//       a method of the class
//
//output: a boolean noting whether or not the game has
//        been won
//
bool gameBoard::checkWin()
{
    //    012
    //    345
    //    678

    char to_check = 'X';

    for (int i = 0; i < 2; i++)
    {
        //horizontal/////////////////////////////////////////////////////////////
        if ((slots[0] == to_check && slots[1] == to_check && slots[2] == to_check) ||
            (slots[3] == to_check && slots[4] == to_check && slots[5] == to_check) ||
            (slots[6] == to_check && slots[7] == to_check && slots[8] == to_check))
        {

            std::printf("\n\n%c won!\n\n\n", to_check);
            return true;
        }


        //vertical///////////////////////////////////////////////////////////////
        if ((slots[0] == to_check && slots[3] == to_check && slots[6] == to_check) ||
            (slots[1] == to_check && slots[4] == to_check && slots[7] == to_check) ||
            (slots[2] == to_check && slots[5] == to_check && slots[8] == to_check))
        {

            std::printf("\n\n%c won!\n\n\n", to_check);
            return true;
        }



        //diagonal///////////////////////////////////////////////////////////////
        if ((slots[0] == to_check && slots[4] == to_check && slots[8] == to_check) ||
            (slots[2] == to_check && slots[4] == to_check && slots[6] == to_check))
        {

            std::printf("\n\n%c won!\n\n\n", to_check);
            return true;
        }

        to_check = 'O';
    }

    for (int i = 0; i < 9; i++)
    {
        if (slots[i] == ' ')
        {
            return false;
        }
    }
    std::printf("\n\nNobody won!\n\n\n");
    return true;
}


//function to help make sure that the input is
//formated correctly (insure it is a number)
//
bool isNumeric(std::string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false; //when one non numeric value is found, return false
    return true;
}


void gameBoard::run()
{
    print();
    //internal (main) game loop
    while (!checkWin())
    {
        std::string selection = "";
        std::cin >> selection;
        if (!isNumeric(selection) || stoi(selection) < 0 || stoi(selection) > 8)
        {
            if (windows) { system("cls"); }
            std::printf("\nInvalid move, try again\n");
            print();
        }
        else
        {
            setSlot(stoi(selection));
        }
    }
}

//main function
//
int main()
{
    //external game-loop
    //used if the players
    //want to play more than
    //once
    while (true)
    {
        if (windows) { system("cls"); }
        gameBoard b;
        b.run();


        printf("Do you want to play again? (y/n):");
        bool breakQ = false;
        //loop to insure input is y/n
        while (true)
        {
            std::string selection2 = "";
            std::cin >> selection2;
            if (selection2 == "n" || selection2 == "N")
            {
                breakQ = true;
                break;
            }
            else if (selection2 == "y" || selection2 == "Y")
            {
                //do nothing
                break;
            }
            else
            {
                std::printf("\nInvalid input, try again\n");
            }
        }

        if (breakQ)
        {
            break;
        }
    }

    return 0;
}
