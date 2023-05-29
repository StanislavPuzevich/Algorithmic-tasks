//1603. Design Parking System(Easy)
//
//------------------------------------------------------------------ 
// https://leetcode.com/problems/design-parking-system/description/
//------------------------------------------------------------------ 
// 
//Design a parking system for a parking lot.The parking lot has three kinds of parking spaces : big, medium, and small, with a fixed number of slots for each size.
//
//Implement the ParkingSystem class :
//ParkingSystem(int big, int medium, int small) Initializes object of the ParkingSystem class.The number of slots for each parking space are given as part of the constructor.
//bool addCar(int carType) Checks whether there is a parking space of carType for the car that wants to get into the parking lot.
//carType can be of three kinds : big, medium, or small, which are represented by 1, 2, and 3 respectively.
//A car can only park in a parking space of its carType.If there is no space available, return false, else park the car in that size spaceand return true.
//
//Example 1:
//    Input
//    ["ParkingSystem", "addCar", "addCar", "addCar", "addCar"]
//    [[1, 1, 0], [1], [2], [3], [1]]
//    Output
//    [null, true, true, false, false]
//    
//    Explanation
//    ParkingSystem parkingSystem = new ParkingSystem(1, 1, 0);
//    parkingSystem.addCar(1); // return true because there is 1 available slot for a big car
//    parkingSystem.addCar(2); // return true because there is 1 available slot for a medium car
//    parkingSystem.addCar(3); // return false because there is no available slot for a small car
//    parkingSystem.addCar(1); // return false because there is no available slot for a big car. It is already occupied.
//
//Constraints:
//    0 <= big, medium, small <= 1000
//    carType is 1, 2, or 3
//    At most 1000 calls will be made to addCar

#include <iostream>
#include <vector>

class ParkingSystem_vers1
{
    int m_big;
    int m_medium;
    int m_small;

public:
    ParkingSystem_vers1(int big, int medium, int small) : m_big(big), m_medium(medium), m_small(small) { }

    bool addCar(int carType) 
    {
        switch (carType)
        {
        case 1: 
            if (!m_big) return false;
            m_big--;
            break;
        case 2:
            if (!m_medium) return false;
            m_medium--;
            break;
        case 3:
            if (!m_small) return false;
            m_small--;
            break;
        default:
            return false;
        }

        return true;
    }
};

class ParkingSystem_vers2
{
    std::vector<int> vec;

public:
    ParkingSystem_vers2(int big, int medium, int small) : vec({big, medium, small}) { }

    bool addCar(int carType)
    {
        return vec[carType - 1] ? vec[carType - 1]-- : false;
    }
};

int main()
{
    ParkingSystem_vers2 ps(1, 1, 0);

    std::cout << ps.addCar(1) << std::endl << ps.addCar(2) << std::endl << ps.addCar(3) << std::endl;

    return 0;
}
