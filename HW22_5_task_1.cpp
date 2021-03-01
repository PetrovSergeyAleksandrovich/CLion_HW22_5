#include <iostream>
#include <fstream>

int main() {

    std::ifstream my_file;
    std::string output, user_input;
    int counter = 0;

    std::cout << "Type number like 'one, two, three... ten' to search in file\n: ";
    std::cin >> user_input;

    my_file.open("C:\\Users\\Poizone\\CLion_HW22_5\\text.txt"); /* set your path on your machine*/
    while(!my_file.eof())
    {
        my_file >> output;
        if(output == user_input) counter++;
    }

    my_file.close();
    std::cout << user_input << " - found " << counter << " times."<< std::endl;
    return 0;
}


