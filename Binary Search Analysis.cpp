// Binary Search Analysis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <iostream>
#include <random>

//This is the beggining of the random numbers branch
int recursiveBinarySearch(const std::vector<int>& arr, int target, int low, int high)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            return recursiveBinarySearch(arr, target, mid + 1, high);
        }
        else
        {
            return recursiveBinarySearch(arr, target, low, mid - 1);
        }
    }
    else
    {
        return -1;
    }
}

int iterartiveBinarySearch(const std::vector<int>& arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int random_number;
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> distribution(1, 100);

    for (int i = 0; i < 5; i++)
    {
        random_number = distribution(rng);
        std::cout << "Random Number: " << random_number << std::endl;
    }


    //std::vector<int> arr = { 1,2,3,4,5,6,7,8,9,10,11,12 };

    std::vector<int> arr(100);
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = distribution(rng);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << std::endl;
    }

    int target = distribution(rng);
    std::cout << "Target is: " << target << std::endl;

    int result = recursiveBinarySearch(arr, target, 0, arr.size() - 1);

    //int result = iterartiveBinarySearch(arr, target);

    if (result != -1)
    {
        std::cout << "Element found at index: " << result << std::endl;
    }
    else
    {
        std::cout << "Element not found in the array." << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
