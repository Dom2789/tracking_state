#include <iostream>
#include <string>

unsigned int string_to_int(std::string str)
{
    unsigned int integer = 0;
    for(int i=0; i<=str.length()-1; i++)
    {
        if(i==0) integer = str[i]-'0';
        else 
        {
            integer *=10;
            integer += (str[i]-'0');
        }
    }   
    return integer;
}

int main()
{
    std::string str = "";
    unsigned int integer;
    std::cout << "Input Integer: ";
    std::cin >> str;
    integer = string_to_int(str);
    std::cout << integer;
    return 1;
}