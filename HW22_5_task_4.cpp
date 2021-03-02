#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    std::ifstream my_file;

    //OPTION 1
    std::vector<char> data;
    std::vector<char> PNG_ID = {'-', '1', '1', '9', 'P', 'N', 'G'};
    /* set your path on your machine*/
    my_file.open("C:\\Users\\Poizone\\CLion_HW22_5\\picture.png", std::ios::binary);
    for(int i = 0; i < 4; i++)
    {
        char buffer[2];
        my_file.read(buffer, sizeof(buffer)-1);
        buffer[my_file.gcount()] = 0;
        if(*buffer == -119) {
            data.push_back('-'); data.push_back('1'); data.push_back('1'); data.push_back('9');
            continue;
        }
        data.push_back(*buffer);
    }
    my_file.close();
    data == PNG_ID ? std::cout << "YES " : std::cout << "NO ";


    //OPTION 2
    my_file.open("C:\\Users\\Poizone\\CLion_HW22_5\\picture.png", std::ios::binary);
    std::string from_file;
    my_file >> from_file;
    std::string png_sub = from_file.substr(1,3);
    my_file.close();
    png_sub == "PNG" ? std::cout << "YES" : std::cout << "NO";

    return 0;
}