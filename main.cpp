#include <fstream>
#include <map>
#include <string>
#include <locale>

bool is_isomorf(std::string a, std::string b)
{
/*
Память: a.size() байт + b.size() байт + в худшем случае a.size() байн в map (доп данные в string, map) = O(n)
Сложность O(n)
*/
    if(a.size() != b.size())
        return false;
    std::map<char, char> isomorf;
    for(int i = 0; i < a.size(); ++i)
    {
        if(isomorf.find(a[i]) == isomorf.end())
            isomorf[a[i]] = b[i];
        else if(isomorf[a[i]] != b[i])
        {
            return false;
        }
    }
    return true;
}

#include <iostream>
int main()
{    
    std::locale::global(std::locale("ru_RU.UTF-8"));
    std::string a, b;
    std::cin >> a >> b;
    std::cout << (is_isomorf(a, b)?"True":"False") << std::endl;
}