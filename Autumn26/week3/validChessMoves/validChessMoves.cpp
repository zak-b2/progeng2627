#include <iostream>
#include<string>

int main()
{
    std::cout<<"[1] Knight\n[2] Bishop\n[3] Rook\n[4] Queen\n[5] King\n[6] Pawn\n[0] Exit Program"<<std::endl;
    int choice;
    std::cin>>choice;

        switch (choice)
        {
            case 0:
            goto terminate;
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
            case 6:
            break;
            default:
            std::cout<<"Invalid input"<<std::endl;
        }


        terminate:
}

void knightTest()
{
    std::cout<<"Enter <Start Coordinates>:<End Coordinates>"<<std::endl;
    std::string input;
    std::cin>>input;
    
}