#include <iostream>
#include <string>
#include <vector>

// fills solution with # to match the size of grid
void init_solution(
    const std::vector<std::string>& grid, 
    std::vector<std::string>& solution
)
{
    int width = grid[0].size();
    std::string row = "";
    for (int i = 0; i < width; i++)
    {
        row += "#";
    }
    for (int i = 0; i < grid.size(); i++)
    {
        solution.push_back(row);
    }
}

// returns the index of the first letter of word in string
// returns -1 if string does not contain word
int word_position_in_string(
    std::string string,
    std::string word
)
{
    int lettersFound = 0;
    for (int i = 0; i < string.size(); i++)
    {
        if (string[i] == word[lettersFound])
        {
            if (lettersFound == word.size()-1)
            {
                return i-lettersFound;
            }
            lettersFound++;
        }
        else
        {
            lettersFound = 0;
        }
    }
    return -1;
}

// returns a specific column in grid as a string
std::string get_column(
    const std::vector<std::string>& grid,
    int columnNum
)
{
    std::string column = "";
    for (int i = 0; i < grid.size(); i++)
    {
        column += grid[i][columnNum];
    }
    return column;
}

// searches for a given word accross all columns in grid
// updates solution if the word is found
// returns true if the word is found, otherwise returns false
bool find_word_vertically(
    const std::vector<std::string>& grid, 
    std::vector<std::string>& solution,
    std::string word
)
{
    for (int i = 0; i < grid[0].size(); i++)
    {
        int wordPos = word_position_in_string(get_column (grid, i), word);
        
        if (wordPos != -1)
        {
            for (int j = 0; j < word.size(); j++)
            {
                solution[wordPos + j][i] = word[j];
            }
            return true;
        }
    }
    return false;
}

// searches for a given word accross all rows in grid
// updates solution if the word is found
// returns true if the word is found, otherwise returns false
bool find_word_horizontally(
    const std::vector<std::string>& grid, 
    std::vector<std::string>& solution,
    std::string word
)
{
    for (int i = 0; i < grid.size(); i++)
    {
        int wordPos = word_position_in_string(grid[i], word);
        
        if (wordPos != -1)
        {
            for (int j = 0; j < word.size(); j++)
            {
                solution[i][wordPos + j] = word[j];
            }
            return true;
        }
    }
    return false;
}

// iterates over all words, and searches for them in grid
// if the word is found neither horizontally or vertically, the word is added to the not_found vector
void find_words(
    const std::vector<std::string>& grid, 
    const std::vector<std::string>& words,
    std::vector<std::string>& solution,
    std::vector<std::string>& not_found
){
    init_solution(grid, solution);
    for (int i = 0; i < words.size(); i++)
    {
        if (! (find_word_horizontally(grid, solution, words[i]) || find_word_vertically(grid, solution, words[i])))
        {
            not_found.push_back(words[i]);
        }
    }
}

// test case
int main(){

    std::vector<std::string> grid = {
        "xappleg",
        "dzeazkg",
        "zwazzbx",
        "dxnqzoy",
        "qyueytp",
        "pythtyg"
    };

    std::vector<std::string> words = {"peanut", "bot", "mango", "apple", "cinnamon"};
    std::vector<std::string> solution;
    std::vector<std::string> not_found;

    find_words(grid, words, solution, not_found); 

    std::vector<std::string> expected_solution = {
        "#apple#",
        "##e####",
        "##a##b#",
        "##n##o#",
        "##u##t#",
        "##t####"
    };

    std::vector<std::string> expected_not_found = {"mango", "cinnamon"};

    if( (solution == expected_solution) && (not_found == expected_not_found) ){
        std::cout << "test passed" << std::endl;
    }
    else{
        std::cout << "test failed" << std::endl;
    }

    std::cout << "solution:" << std::endl;
    for(int i = 0; i < solution.size(); i++){
        std::cout << solution[i] << std::endl;
    }

    std::cout << "not found:" << std::endl;
    for(int i = 0; i < not_found.size(); i++){
        std::cout << not_found[i] << std::endl;
    }

}