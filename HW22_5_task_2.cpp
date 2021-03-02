#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::ifstream my_file;
    char buffer[2];
    std::string path = "C:\\Users\\Poizone\\CLion_HW22_5\\data.txt"; /* set your path on your machine*/

    std::cout << "Type path to file\n: ";
    //std::cin >> path;
    path = "C:\\Users\\Poizone\\CLion_HW22_5\\data.txt";

    my_file.open(path, std::ios::binary);
    while(!my_file.is_open())
    {
        std::cout << std::endl;
        std::cout << "Wrong path to file\n";
        std::cout << "Type path to file again\n: ";
        std::cin >> path;
    }
    std::cout << std::endl;

    while (!my_file.eof())
    {
        my_file.read(buffer, sizeof(buffer)-1);
        buffer[my_file.gcount()] = 0;
        //if(*buffer == 'e') std::cout << '!';
        std::cout << buffer;
    }

    my_file.close();

    return 0;
}



