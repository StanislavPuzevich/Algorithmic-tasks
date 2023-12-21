//661. Image Smoother(Easy)
//
//----------------------------------------------------------- 
// https://leetcode.com/problems/image-smoother/description/
//----------------------------------------------------------- 
// 
//An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image by rounding down 
//the average of the cell and the eight surrounding cells(i.e., the average of the nine cells in the blue smoother).
//If one or more of the surrounding cells of a cell is not present, we do not consider it in the average(i.e., the average of the four cells in the red smoother).
//
//Given an m x n integer matrix img representing the grayscale of an image, return the image after applying the smoother on each cell of it.
//
//Example 1:
//    Input: img = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
//    Output : [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
//    Explanation :
//    For the points(0, 0), (0, 2), (2, 0), (2, 2) : floor(3 / 4) = floor(0.75) = 0
//    For the points(0, 1), (1, 0), (1, 2), (2, 1) : floor(5 / 6) = floor(0.83333333) = 0
//    For the point(1, 1) : floor(8 / 9) = floor(0.88888889) = 0
//
//Example 2 :
//
//    Input : img = [[100, 200, 100], [200, 50, 200], [100, 200, 100]]
//    Output : [[137, 141, 137], [141, 138, 141], [137, 141, 137]]
//    Explanation :
//    For the points(0, 0), (0, 2), (2, 0), (2, 2) : floor((100 + 200 + 200 + 50) / 4) = floor(137.5) = 137
//    For the points(0, 1), (1, 0), (1, 2), (2, 1) : floor((200 + 200 + 50 + 200 + 100 + 100) / 6) = floor(141.666667) = 141
//    For the point(1, 1) : floor((50 + 200 + 200 + 200 + 200 + 100 + 100 + 100 + 100) / 9) = floor(138.888889) = 138
//
//Constraints :
//    m == img.length
//    n == img[i].length
//    1 <= m, n <= 200
//    0 <= img[i][j] <= 255

#include <iostream>
#include <vector>

class Solution 
{
public:
    std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>>& img)
    {
        std::vector<std::vector<int>> result;
        result.reserve(img.size());

        for (int i = 0; i < img.size(); i++)
        {
            std::vector<int> str;
            str.reserve(img[0].size());

            for (int j = 0; j < img[i].size(); j++)
            {
                int count = 0;
                int sum = 0;

                for (int l = std::max(0, i - 1); l < std::min(int(img.size()), i + 2); l++)
                {
                    for (int k = std::max(0, j - 1); k < std::min(int(img[i].size()), j + 2); k++)
                    {
                        sum += img[l][k];
                        count++;
                    }
                }
                str.push_back(sum / count);
            }
            result.push_back(str);
        }

        return result;
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<int>> img
    {
        {100,200,100},
        {200,50,200},
        {100,200,100}
    };

    std::vector<std::vector<int>> res = s.imageSmoother(img);
    for (const auto i : res)
    {
        for (const auto j : i)
            std::cout << j << " ";
        std::cout << std::endl;
    }

    return 0;
}
