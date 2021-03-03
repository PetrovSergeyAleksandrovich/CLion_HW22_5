#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream my_file;

    //OPTION 1
    /* set your path on your machine*/
    char buffer[5];
    my_file.open("C:\\Users\\Poizone\\CLion_HW22_5\\picture.png", std::ios::binary);
    my_file.read(buffer, sizeof(buffer)-1);
    buffer[0] == -119 && buffer[1] == 'P' && buffer[2] == 'N' && buffer[3] == 'G' ?
    std::cout << "YES\n" : std::cout << "NO\n";
    my_file.close();

    // test output
    buffer[4] = 0;
    std::cout << buffer << std::endl << &buffer << std::endl << buffer[0] << std::endl << buffer[3] ;

    return 0;
}