// Binary Search Analysis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <iostream>
#include <random>
#include <chrono>

//This is the beggining of the random numbers branch
int recursiveBinarySearch(const std::vector<int>& arr, int target, int low, int high)
{
    if (low <= high)
    {
        int mid = low + ((high - low) / 2);

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
        return -1; //Target not found
    }
}

int iterartiveBinarySearch(const std::vector<int>& arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + ((high - low) / 2);

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

int sequentialSearch(const std::vector<int>& arr, int target)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    //declaring variables
    int n = 1000000;
    double sumRBS = 0;
    double sumIBS = 0;
    double sumSeqS = 0;
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> distribution(1, 100);
    for (int l = 0; l < 10; ++l)
    {  
        //random number generation

        //Initalization of the vector array
        int target = distribution(rng);
        std::vector<int> arr(n);
        for (int i = 0; i < arr.size(); ++i)
        {
            arr[i] = distribution(rng);
            //arr[i] = i;
        }
        for (int i = 0; i < arr.size(); ++i)
        {
            //std::cout << arr[i] << std::endl;
        }
        std::cout << "Target is: " << target << std::endl;

        //Clocking the recursive Search
        auto start_time1 = std::chrono::high_resolution_clock::now();
        int result1 = recursiveBinarySearch(arr, target, 0, arr.size() - 1);
        auto end_time1 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end_time1 - start_time1).count();
        double countr = (double)duration1; //casting duration to double
        sumRBS = sumRBS + countr; //adding to sum

        //printing results
        std::cout << "Binary duration:" << countr << std::endl;
        if (result1 != -1)
        {
            std::cout << "Element found at index: " << result1 << std::endl;
        }
        else
        {
            std::cout << "Element not found in the array." << std::endl;
        }


        //clocking the iterative Search
        auto start_time2 = std::chrono::high_resolution_clock::now();
        int result2 = iterartiveBinarySearch(arr, target);
        auto end_time2 = std::chrono::high_resolution_clock::now();

        auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end_time2 - start_time2).count();
        double counti = (double)duration2;
        sumIBS = sumIBS + counti;

        std::cout << "Iterative duration: " << counti << std::endl;

        if (result2 != -1)
        {
            std::cout << "Element found at index: " << result2 << std::endl;
        }
        else
        {
            std::cout << "Element not found in the array." << std::endl;
        }

        //clocking the Sequential Search
        auto start_time3 = std::chrono::high_resolution_clock::now();
        int result3 = sequentialSearch(arr, target);
        auto end_time3 = std::chrono::high_resolution_clock::now();

        auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(end_time3 - start_time3).count();
        double counts = (double)duration3;
        sumSeqS = sumSeqS + counts;

        std::cout << "Sequential duration: " << counts << std::endl;

        if (result3 != -1)
        {
            std::cout << "Element found at index: " << result3 << std::endl;
        }
        else
        {
            std::cout << "Element not found in the array." << std::endl;
        }
        
    }
    std::cout << "Average Running Time for Recursive Binary Search in microseconds is " << (sumRBS / 10) << std::endl;
    std::cout << "Average Running Time for Iterative Binary Search in microseconds is " << (sumIBS / 10) << std::endl;
    std::cout << "Average Running Time for Sequential Search in microseconds is " << (sumSeqS / 10) << std::endl;
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
