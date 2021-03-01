#include <iostream>
#include <fstream>

int main()
{
    std::ifstream my_file;
    int budget_to_pay = 0,  biggest_salary = 0;
    std::string human_with_biggest_salary;
    my_file.open("C:\\Users\\Poizone\\CLion_HW22_5\\list.txt"); /* set your path on your machine*/
    while(!my_file.eof())
    {
        int money_current;
        std::string name, surname, date;
        my_file >> name >> surname >> money_current >> date;
        budget_to_pay += money_current;
        if(money_current > biggest_salary)
        {
            biggest_salary = money_current;
            human_with_biggest_salary = name + ' ' + surname;
        }
    }
    my_file.close();
    std::cout << "budget: " << budget_to_pay << std::endl;
    std::cout << "human_with_big_salary: " << human_with_biggest_salary;
}
