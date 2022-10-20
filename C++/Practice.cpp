#include <iostream>

//This function assumes that the arrays are SORTED
int* mergeArrays (int* array1, int size1, int* array2, int size2) {

    //the new array using the size of array1 and array2
    int *array3 = new int [size1 + size2];
    int i = 0, j = 0, k = 0;
    
    //Compare the array1 and array2 values by index
    while (i < size1 && j < size2) {
        if (array1[i] < array2[j]) {
            array3[k++] = array1[i++];
        } else {
            array3[k++] = array2[j++];
        }
    }

    //If there is any array1 elements remaining, add them to array3
    while (i < size1) {
        array3[k++] = array1[i++];
    }

    //If there is any array2 elements remaining, add them to array3
    while (j < size2) {
        array3[k++] = array2[j++];
    }

    return array3;
}

int main () {

    //Two arrays that are "SORTED" in ascending order and not necessarily the same size
    int arr1 [] = {1,5,8,9,10,100}; 
    int arr2 [] = {2,3,7,20,50,60,88,95,152};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    int size3 = size1 + size2;

    //Calling the mergeArrays function
    int *arr3 = mergeArrays(arr1, size1, arr2, size2);
    
    //Array 1
    std::cout << "Array1 is: [";
    for (int x = 0; x < size1; x++)
        std::cout << arr1[x] << " ";
    std::cout<< "]"<< std::endl;

    //Array 2
    std::cout << "Array2 is: [";
    for (int y = 0; y < size2; y++)
        std::cout << arr2[y] << " ";
    std::cout<< "]"<< std::endl;

    //Merged Array | Array 3
    std::cout<< "The Merged Array is: [";
    for (int z = 0; z < size3; z++)
        std::cout << arr3[z] << " ";
    
    std::cout<< "]"<< std::endl;
    delete [] arr3;

}