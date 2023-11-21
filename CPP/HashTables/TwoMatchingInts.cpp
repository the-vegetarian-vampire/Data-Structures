#include <iostream>
#include <vector>

int main()
{
    // Define two arrays
    std::vector<int> array1 = {1, 2, 3, 4, 5};
    std::vector<int> array2 = {4, 5, 6, 7, 8};

    // Iterate through elements of array1
    for (int i = 0; i < array1.size(); ++i)
    {
        // Compare each element of array1 with elements of array2
        for (int j = 0; j < array2.size(); ++j)
        {
            if (array1[i] == array2[j])
            {
                // If a match is found, print the matching integer
                std::cout << "Match found: " << array1[i] << std::endl;
            }
        }
    }

    return 0;
}
