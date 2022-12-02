#include <iostream>
#include <fstream>

int main() {
    int cal = 0;
    int elf = 1;
    int max = 0;
    int strongest = 0;
    std::string line ;
    std::ifstream input_File("test.txt");
    while( std::getline(input_File, line))
    {
        if (line.length() > 0) {
            cal += stoi(line);
        } else {
            if (cal > max){
                max = cal;
                strongest = elf;
            }
            elf++;
            cal = 0;
        }
    }
        std::cout << "Elf : " << strongest << " - " << max << std::endl;
}