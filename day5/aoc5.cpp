#include <fstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

template <typename T>
void scream(T _err){
    std::cout << _err << std::endl;
}


void part1(std::string inF){
    std::string output = inF;
    std::string line;
    std::fstream inFSTR(inF);
    std::vector<std::vector<char>> stacks(10);
    while(std::getline(inFSTR, line)){
        if (line.length() == 0)
        {
            break;
        }
        for (int i = 1, j = 0; i < line.length(); i+=4, j++)
        {
            stacks[j].push_back(line[i]);
        }
        
        
    }
    //read until empty line
        std::cout <<  stacks;

    
    std::cout << "Part 1: " << output << std::endl;
}


int main(int argc, char const *argv[])
{
    part1(argv[1]);
    return 0;
}
