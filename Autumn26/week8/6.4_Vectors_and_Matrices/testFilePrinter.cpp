#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]){
    std::ifstream fin(argv[1]);
    std::string tmp;
    while (std::getline(fin, tmp))
    {
        std::cout<<tmp<<std::endl;
    }
    return 0;
}