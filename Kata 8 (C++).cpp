// Kata 8 (C++).cpp
// This Function takes two vectors and compares if the square of each element in the first
// appears the same number of times in the second.

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Same {
public:
    // Static prototypes allows for the member functions to be called without creating
    // an instance of the class.
    static void vSwap(vector<int>& my_vector, int a, vector<int>::iterator& b_it);
    static bool comp(vector<int>& a, vector<int>& b);
};

// Takes the index of the first vector and the iterator of the second and 
// swaps the values in their respective positions.
void Same::vSwap(vector<int>& my_vector, int a, vector<int>::iterator& b_it) {
    int temp = my_vector[a];
    my_vector[a] = *b_it;
    *b_it = temp;
}

// This function performs the comparison by iterating through vector "b" searching for 
// the square of each element in "a." When a match is found, vSwap() is called 
// to move it to the first location in "b", and then the "first" position in the vector is 
// incremented. This prevents all elements in "b" before the updated "first" position in the 
// vector from being included in the search of future iterations.
bool Same::comp(vector<int>& a, vector<int>& b) {
    bool bResult = true;

    // Ensures both vectors are of equal size else returns false
    if (a.size() == b.size()) {
        // Iterates through each element of "a"
        for (int lower = 0; lower < a.size(); lower++) {
            // This is the iterator that points to the first position of "b"
            auto lowerB_It = b.begin() + lower;
            // This look for the position of the match in "b"
            auto matchPos = find(lowerB_It, b.end(), pow(a[lower], 2));
            // If a match is not found, set result to false and break out of loop
            if (matchPos == b.end()) {
                bResult = false;
                break;
            }
            else {
                // If the match is found and it's not at the "first" position,
                // swap it to the current "first" position and increment "first."
                if (lowerB_It != matchPos)
                    vSwap(b, lower, matchPos);
            }
        }
    }
    else {
        bResult = false;
    }
    return bResult;
}


int main(){
    //std::vector<int> a = { 121, 144, 19, 161, 19, 144, 19, 11 };
    //std::vector<int> b = { 20736, 14641, 361, 25921, 361, 20736, 361, 121 };
    //std::vector<int> a = { 5, 3, 4 };
    //std::vector<int> b = { 9, 15, 25 };
    std::vector<int> a = { 121, 144, 19, 161, 19, 144, 19, 11 };
    std::vector<int> b = { 14641, 20736, 361, 25921, 361, 20736, 362, 121 };
    static bool cBool = Same::comp(a, b);
    cout << cBool << endl;
}


