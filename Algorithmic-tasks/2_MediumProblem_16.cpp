//799. Champagne Tower
//We stack glasses in a pyramid, where the first row has 1 glass, the second row has 2 glasses, and so on until the 100th row.Each glass
//holds one cup of champagne.
//
//Then, some champagne is poured into the first glass at the top.When the topmost glass is full, any excess liquid poured will fall
//equally to the glass immediately to the leftand right of it.When those glasses become full, any excess champagne will fall equally
//to the leftand right of those glasses, and so on.  (A glass at the bottom row has its excess champagne fall on the floor.)
//
//For example, after one cup of champagne is poured, the top most glass is full.After two cups of champagne are poured, 
//the two glasses on the second row are half full.After three cups of champagne are poured, those two cups become full - there are
//3 full glasses total now.After four cups of champagne are poured, the third row has the middle glass half full, and the two outside glasses
//are a quarter full, as pictured below.
//
//Now after pouring some non - negative integer cups of champagne, return how full the jth glass in the ith row is(both i and j are 0 - indexed.)
//
//Example 2:
//Input: poured = 2, query_row = 1, query_glass = 1
//Output : 0.50000
//Explanation : We poured 2 cups of champange to the top glass of the tower(which is indexed as(0, 0)).
//There is one cup of excess liquid.The glass indexed as(1, 0) and the glass indexed as(1, 1) will share the excess liquid equally,
//and each will get half cup of champange.
// 
// Example 3:
//Input: poured = 100000009, query_row = 33, query_glass = 17
//Output : 1.00000
//
//Constraints :
//    0 <= poured <= 109
//    0 <= query_glass <= query_row < 100

#include <iostream>


class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        double arr[101][101] = { 0.0 };
        arr[0][0] = (double)poured;
        for (int r = 0; r <= query_row; r++)
        {
            for (int c = 0; c <= r; c++)
            {
                double temp = (arr[r][c] - 1.0) / 2.0;
                if (temp > 0)
                {
                    arr[r + 1][c] += temp;
                    arr[r + 1][c + 1] += temp;
                    arr[r][c] = 1;
                }
            }
        }
        return arr[query_row][query_glass];
    }
};


int main()
{   
    Solution s;
    int poured = 100000009, query_row = 33, query_glass = 22;
    
    std::cout << "Result: " << s.champagneTower(poured, query_row, query_glass) << std::endl;

    return 0;
}