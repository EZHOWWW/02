// Ежов Дмитрий j3113 471242
// Lab2 Hard lvl :  
// Реализовать функцию, которая определяет, являются ли две строки изоморфными
#include <cassert>
#include <fstream>
#include <map>
#include <string>
#include <locale>

bool is_isomorf(std::string a, std::string b)
{
/*
Память: a.size() байт + b.size() байт + в худшем случае a.size() байт в map (+ доп данные в string, map) = O(n)
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

    assert(is_isomorf("", "") == true);
    assert(is_isomorf("11", "1") == false);
    assert(is_isomorf("1", "11") == false);
    assert(is_isomorf("aaa", "aaa") == true);
    assert(is_isomorf("abc", "rgt") == true);
    assert(is_isomorf("rrrtttyyy", "bbbmmmnnn") == true);
    assert(is_isomorf("zxcvb", "asdfg") == true);
    assert(is_isomorf("giiittt 123", "caaattt 654") == true);


    std::string a, b;
    std::cin >> a >> b;
    std::cout << (is_isomorf(a, b)?"True":"False") << std::endl;
}