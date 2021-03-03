#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    std::ifstream my_file;
    std::vector<int> left_questions = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int player = 0, spectators = 0;
    std::string question_number, question_text, answer_number, answer_text, user_input, user_answer;

    //game started with conditions
    while(player != 6 && spectators != 6)
    {
        /* set your path on your machine*/
        my_file.open("C:\\Users\\Poizone\\CLion_HW22_5\\game.txt");

        // output questions left to answer
        std::cout << std::endl <<"Number of questions left: " ;
        for(int i = 0; i < left_questions.size(); i++)
        {
            if(left_questions[i] == 0) continue;
            std::cout << left_questions[i] << " ";
        }

        //user input question number
        std::cout << std::endl <<":" ;
        std::cin >> user_input;

        //check user input
        while ((stoi(user_input) > 13 || stoi(user_input) < 1) || left_questions[stoi(user_input)-1] == 0)
        {
            std::cout << std::endl <<"Wrong input. Try again: ";
            std::cin >> user_input;
        }
        std::cout << std::endl <<"User input OK\n\nQUESTION: ";

        //read data from file with regards to input number
        do {
            my_file >> question_number >> question_text;
            my_file >> answer_number >> answer_text;
        } while (user_input != question_number);

        //output question for user to read from input data recieved
        for(int i = 0; i < question_text.length(); i++)
        {
            if (question_text[i] == '_') std::cout << " ";
            else std::cout << question_text[i];
        }

        //user input answer
        std::cout << std::endl << "\nType the answer:";
        std::cin >> user_answer;

        //check answer
        if(user_answer == answer_text)
        {
            std::cout << "Your answer is correct!" << std::endl;
            player++;
        }
        else
        {
            std::cout << "Your answer is wrong! Score goes to spectators" << std::endl;
            spectators++;
        }
        
        left_questions[stoi(user_input)-1] = 0;
        std::cout << "\nPlayer: " << player << "\nSpectators: " << spectators << std::endl;
        my_file.close();
    }

    if(player == 6) std::cout << "\nPLAYER WINS!" << "\nGAME OVER!";
    if(spectators == 6) std::cout << "\nSPECTATORS WINS!" << "\nGAME OVER!";

    return 0;
}

