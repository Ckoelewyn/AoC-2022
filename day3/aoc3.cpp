#include <fstream>
#include <iostream>
#include <vector>

template <typename T>

void scream(T err){
    std::cout << "AAAAAAAAAAAAAAAAAAAHHHHHHHHHH " << err << std::endl;
}

// duplicate characters, given values. O(n^2) nested for loops
char getDuplicate(std::string line){
        int length = line.length();
        for (int i = 0; i < length; i++)
        {
            //this is dirty, bad input could give out of bound error
            for (int j = length/2; j < length; j++) 
            {
                if (line[i] == line[j])
                {
                    return line[i];
                }
                
            }
            
        }
        scream(line);
        return '0';
}

char getTriplicate(std::vector<std::string> vtr){
    // scream(vtr[0]);
    // scream(vtr[1]);
    // scream(vtr[2]);
        for (u_int i = 0; i < vtr[0].length(); i++)
        {
            for (u_int j = 0; j < vtr[1].length(); j++) 
            {
                if (vtr[0][i] == vtr[1][j])
                {
                    for (u_int k = 0; k < vtr[2].length(); k++)                    {
                        if (vtr[0][i] == vtr[2][k])
                        {
                            // std::cout << vtr[0][i] << std::endl;
                            return vtr[0][i];
                        }
                        
                    }
                    
                }
                
            }
            
        }
        // scream(vtr[0]);
        return '0';
}

int getVal(char letter){
    if ('a' <= letter && 'z' >= letter)
    {
        return letter - 96;
    } else if ('A' <= letter && 'Z' >= letter)
    {
        return letter - 64 + 26;
    }
    scream(letter);
    return 0;
}

void part1(){
    std::string line;
    std::ifstream inputfile("data.txt");
    int sum = 0;
    while (std::getline(inputfile, line)){
        // std::cout << getVal(getDuplicate(line)) << std::endl;
        sum += getVal(getDuplicate(line));
    }
    std::cout << "Part 1 : " << sum << std::endl;
    return;
}

void part2(){
    std::string line;
    std::vector<std::string> vtr(3);
    std::ifstream inputfile("data.txt");
    int sum = 0;
    int cnt = 0;
    while (std::getline(inputfile, line))
    {
        vtr[cnt] = line;
        if (cnt == 2)
        {
            cnt = -1;
            sum += getVal(getTriplicate(vtr));
        }
        cnt++;
    }
    std::cout << "Part 2 : " << sum << std::endl;
    return;
}

int main(){
    part1();
    part2();
    return 0;
}