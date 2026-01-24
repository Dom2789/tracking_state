#include <iostream>
#include <string>
#include <vector>

enum struct State {uppercase, lowercase, punctuation};

unsigned int string_to_int(std::string str)
{
    unsigned int integer = 0;
    for(int i=0; i<str.length(); i++)
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

char int_to_lowercase(int integer)
{
    if (integer<1 || integer>27) return '0';
    else return (integer + 'a' - 1);   
}

char int_to_uppercase(int integer)
{
    if (integer<1 || integer>27) return '0';
    else return (integer + 'A' - 1);   
}

char int_to_punctuation(int integer)
{
    switch (integer) {
        case 1:
            return '!';
        case 2:
            return '?';
        case 3:
            return ',';
        case 4:
            return '.';
        case 5:
            return ' ';
        case 6:
            return ';';
        case 7:
            return '"';
        case 8:
            return '\'';
        default:
            return '0';
        }
}

std::vector<std::string> split_string(std::string str, char seperator = ',')
{
    std::vector<std::string> strings;
    int i = 0;
    int j = 0;
    do{
        if (str[i]==seperator)
        {
            strings.push_back(str.substr(j, i-j));
            j = i+1;
        }
        i++;
    }while(i<str.length());
    if(i>j)
    {
        strings.push_back(str.substr(j, i-j));
    }
    return strings;
}

int main()
{
    State state {State::uppercase};
    std::string str = "";
    unsigned int integer;
    std::vector<std::string> strings;

    std::cout << "Input integers separated with ',': ";
    std::cin >> str;
    strings = split_string(str);
    for(auto str : strings )
    {
        integer = string_to_int(str);
        switch (state)
        {
        case State::uppercase:
            integer %= 27;
            if(integer == 0) state = State::lowercase;
            else std::cout << int_to_uppercase(integer) << "\n";
            break;
        case State::lowercase:
            integer %= 27;
            if(integer == 0) state = State::punctuation;
            else std::cout << int_to_lowercase(integer) << "\n";
            break;
        case State::punctuation:
            integer %= 9;
            if(integer == 0) state = State::uppercase;
            else std::cout << int_to_punctuation(integer) << "\n";
            break;
        default:
            break;
        }        
    }
    return 1;
}