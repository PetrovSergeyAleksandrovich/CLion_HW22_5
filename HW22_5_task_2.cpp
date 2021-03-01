#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::ifstream my_file;
    int const n = 41;
    char buffer[n];

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

    std::cout << "\nFile contains: \n" << std::endl;
    my_file.read(buffer, sizeof(buffer));
    buffer[n-1] = 0;
    std::cout << buffer << std::endl << "\ndata.txt file size = " << my_file.gcount() << " byte";

    my_file.close();

    return 0;
}



