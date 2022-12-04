#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

template <typename T>
void _err(T err){
    std::cerr << err << std::endl;
}

// look into const
template <typename T>
void splitter(std::string const &line, T &out, const char delim){
    std::stringstream ss(line);
    std::string s;
    while(std::getline(ss, s, delim)){
        out.push_back(s);
    }    
}

// not sure how to typecast in both functions
template <typename T>
void splitter_int(std::string const &line, T &out, const char delim){
    std::stringstream ss(line);
    std::string s;
    while(std::getline(ss, s, delim)){
        out.push_back(stoi(s));
    }    
}

void part1(){
    int sum = 0;
    std::string line;
    std::fstream inputFile("data.txt");
    while (std::getline(inputFile, line))
    {

        std::vector<int> ints;
        std::vector<std::string> splits;
        splitter(line, splits, ',');
        for (auto &&i : splits)
        {
            splitter_int(i, ints, '-');
        }
        if (ints.at(0) >= ints.at(2) && ints.at(1) <= ints.at(3))
        {
            sum++;
        }
        else if (ints.at(0) <= ints.at(2) && ints.at(1) >= ints.at(3))
        {
            sum++;
        }      
    }
    std::cout << "Part 1 : " << sum << std::endl;
}


void part2(){
    int sum = 0;
    std::string line;
    std::fstream inputFile("test.txt");
    while (std::getline(inputFile, line))
    {

        std::vector<int> ints;
        std::vector<std::string> splits;
        splitter(line, splits, ',');
        for (auto &&i : splits)
        {
            splitter_int(i, ints, '-');
        }
        if (ints.at(0) >= ints.at(2) && ints.at(0) <= ints.at(3)) // A in C,D
        {
            sum++;
        }
        else if (ints.at(1) >= ints.at(2) && ints.at(1) <= ints.at(3)) // B in C,D
        {
            sum++;
        }
        else if (ints.at(2) >= ints.at(0) && ints.at(2) <= ints.at(1)) // C in A,B
        {
            sum++;
        }
        else if (ints.at(3) >= ints.at(0) && ints.at(3) <= ints.at(1)) // D in A,B
        {
            sum++;
        }
    }
    std::cout << "Part 2 : " << sum << std::endl;
}


int main(int argc, char const *argv[])
{
    part1();
    part2();
    return 0;
}
