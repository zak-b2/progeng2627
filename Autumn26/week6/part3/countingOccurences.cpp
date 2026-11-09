#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    std::ifstream fin;
    std::ofstream fout;
    std::vector<std::string> words;
    std::vector<std::string> text;

    fin.open("words.txt");
    if (!fin.is_open())
    {
        std::cout<<"words.txt could not be opened";
        return EXIT_FAILURE;
    }

    std::string tmp;
    while (fin >> tmp)
    {
        words.push_back(tmp);
    }

    fin.close();
    if (fin.is_open())
    {
        std::cout<<"words.txt could not be closed";
        return EXIT_FAILURE;
    }
    fin.open("text.txt");

    if (!fin.is_open())
    {
        std::cout<<"text.txt could not be opened";
        return EXIT_FAILURE;
    }

    while (fin >> tmp)
    {
        text.push_back(tmp);
    }

    std::vector<int> counts;

    for (int i = 0; i<words.size(); i++)
    {
        std::string word = words[i];
        counts.push_back(0);
        for (int j=0; j<text.size(); j++)
        {
            if (text[j] == word)
            {
                counts[i] ++;
            }
        }
    }

    fin.close();

    fout.open("result.txt");
    
    if (!fout.is_open())
    {
        std::cout<<"result.txt could not be opened";
        return EXIT_FAILURE;
    }

    for (int i=0; i<words.size(); i++)
    {
        fout<<words[i]<<": "<<counts[i]<<std::endl;
    }

    fout.close();

    return 0;
}