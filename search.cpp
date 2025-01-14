#include <iostream>
#include <vector>

using namespace std;

bool binarySearch(int x, int* numArray, int lowerBound, int upperBound){
    if (upperBound >= lowerBound){
        int midElemIndex = lowerBound + (upperBound - lowerBound) / 2;
        if (x == numArray[midElemIndex]){
            return true;
        }else if (x > numArray[midElemIndex]){
            return binarySearch(x, numArray, midElemIndex + 1, upperBound);
        }else {
            return binarySearch(x, numArray, lowerBound, midElemIndex - 1);
        }
        return false;
    }
    return false;
}

