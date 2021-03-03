#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream my_file;

    //OPTION 1
    /* set your path on your machine*/
    std::string PNG_ID = "PNG";
    char buffer[4];
    my_file.open("C:\\Users\\Poizone\\CLion_HW22_5\\picture.png", std::ios::binary);
    my_file.seekg(1);
    my_file.read(buffer, sizeof(buffer)-1);
    buffer[3] = 0;
    buffer == PNG_ID ? std::cout << "YES " : std::cout << "NO ";
    my_file.close();

    //OPTION 2
    /* set your path on your machine*/
    my_file.open("C:\\Users\\Poizone\\CLion_HW22_5\\picture.png");
    std::string from_file;
    my_file >> from_file;
    std::string png_sub = from_file.substr(1,3);
    my_file.close();
    png_sub == "PNG" ? std::cout << "YES" : std::cout << "NO";

    return 0;
}