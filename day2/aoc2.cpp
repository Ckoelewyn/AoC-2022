#include <iostream>
#include <fstream>


/*
 *  A/X Rock X == 88 > 1
 *  B/Y Paper Y == 89 > 2
 *  C/Z Scissors Z == 90 > 3
 *
*/

void part1(){
    std::string line;
    std::ifstream inputFile("data.txt");
    int score = 0;
    while (std::getline(inputFile, line))
    {
        char them = line[0];
        char me   = line[2];
        score += (me - 87); // pick
        score += (me - them + 2)%3 * 3; // 0 win, 1 loss, 2 tie :: result
    }
    std::cout << "Part 1: " << score << std::endl;
}

/*
 *  A 66
 *  B 67
 *  C 68
*/
void part2(){
    std::string line;
    std::ifstream inputFile("data.txt");
    int score = 0;
    while (std::getline(inputFile, line))
    {
        char them = line[0] - 65; // normalizes scores to 1,2,3
        char result = line[2]- 88; // 0 lose, 1 draw, 2 win
        score += result * 3 ; // apply scoring scaling
        score += (them + 2 + result)%3 + 1; // :: pick
    }
    std::cout << "Part 2: " << score << std::endl;
}

int main(){
    part1();
    part2();
}