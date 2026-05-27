#include <iostream>

void mainMenu()
{
    int input;
    bool inputActive = 1;
    
    std::cout << "===========Welcome to Cannaworld===========" << std::endl;
    std::cout << "===========================================" << std::endl;
    std::cout << "Please make a selection:" << std::endl;
    std::cout << "1: New Game" << std::endl;
    std::cout << "2: Load Game" << std::endl;
    std::cout << "3: Credits" << std::endl;
    std::cin >> input;
    
    while(inputActive == 1)

        if(input == 1)
        {
            std::cout << "You have chosen option 1" << std::endl;
            std::cin >> input;
        }

        else if(input == 2)
        {
            std::cout << "You have chosen option 2" << std::endl;
            std::cin >> input;
        }

        else if(input == 3)
        {
            std::cout << "You have chosen option 3" << std::endl;
            std::cin >> input;
        }

        else if(input == 4)
        {
            std::cout << "You have chosen to exit... Goodbye!" << std::endl;
            inputActive = 0;
        }

        else
        {
            std::cout << "Invalid Input" << std::endl;
            std::cin >> input;
        }

}