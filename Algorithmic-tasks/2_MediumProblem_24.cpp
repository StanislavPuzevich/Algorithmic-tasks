//36. Valid Sudoku
//Determine if a 9 x 9 Sudoku board is valid.Only the filled cells need to be validated according to the following rules :
//Each row must contain the digits 1 - 9 without repetition.
//Each column must contain the digits 1 - 9 without repetition.
//Each of the nine 3 x 3 sub - boxes of the grid must contain the digits 1 - 9 without repetition.
//Note :
//    A Sudoku board(partially filled) could be valid but is not necessarily solvable.
//    Only the filled cells need to be validated according to the mentioned rules.
//
//Example 2:
//Input: board =
//[["8", "3", ".", ".", "7", ".", ".", ".", "."]
//, ["6", ".", ".", "1", "9", "5", ".", ".", "."]
//, [".", "9", "8", ".", ".", ".", ".", "6", "."]
//, ["8", ".", ".", ".", "6", ".", ".", ".", "3"]
//, ["4", ".", ".", "8", ".", "3", ".", ".", "1"]
//, ["7", ".", ".", ".", "2", ".", ".", ".", "6"]
//, [".", "6", ".", ".", ".", ".", "2", "8", "."]
//, [".", ".", ".", "4", "1", "9", ".", ".", "5"]
//, [".", ".", ".", ".", "8", ".", ".", "7", "9"]]
//Output: false
//Explanation : Same as Example 1, except with the 5 in the top left corner being modified to 8. 
//Since there are two 8's in the top left 3x3 sub-box, it is invalid.
//
//Constraints :
//    board.length == 9
//    board[i].length == 9
//    board[i][j] is a digit 1 - 9 or '.'.

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution 
{
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) 
    {
        int m, n;
        int size = board.size();
        std::unordered_map<char, int> mp;

        for (int i = 0; i < size; i++)
        {
            mp.clear();
            for (int j = 0; j < size; j++)
                if (board[i][j] != '.')
                {
                    mp[board[i][j]]++;
                    if (mp[board[i][j]] == 2)
                        return false;
                }
        }

        for (int i = 0; i < size; i++)
        {
            mp.clear();
            for (int j = 0; j < size; j++)
                if (board[j][i] != '.')
                {
                    mp[board[j][i]]++;
                    if (mp[board[j][i]] == 2)
                        return false;
                }
        }

        for (int i = 0; i < size; i += 3)
            for (int j = 0; j < size; j += 3)
            {
                mp.clear();
                for (int m = i; m < i + 3; m++)
                    for (int n = j; n < j + 3; n++)
                        if (board[m][n] != '.')
                        {
                            mp[board[m][n]]++;
                            if (mp[board[m][n]] == 2)
                                return false;
                        }
            }

        return true;
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<char>> board
    {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'},
    };

    std::cout << "The Sum of strings: " << s.isValidSudoku(board) << std::endl;

    return 0;
}