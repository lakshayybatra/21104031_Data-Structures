#include <bits/stdc++.h>
using namespace std;

// Create a class ArrayReader which reads the elements of array.
class ArrayReader{
public:
    vector<int> arr;
    ArrayReader(vector<int> &arr){
        this->arr = arr;
    }
    // Make a get function which returns the element at index i.
    int get(int i){
        return arr[i];
    }
};

// Create a class solution which searches for the element and returns the index.
class Solution {
public:
    int search(ArrayReader& reader, int target){

        int high = 1;
        int low = 0;
        
        // This loop updates the range.
        while(reader.get(high) < target){
            low = high;
            high = high << 1; // Left-Shift high by 1 bit which multipies high by 2.
        }

        // the following code is for binary search.
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int x = reader.get(mid); // Gets ths element at index mid.
            if (x == target)
                return mid;
            if (x > target){
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return -1;
    }
};

// Write main function.
int main(){
    
    Solution sol;
    int n, target;

    cout<<"Enter number of elements in array:";
    cin>>n;
    cout<<"Enter number we need to find in array:";
    cin>>target;

    vector<int> v(n);
    cout<<"Enter elemets in array separated by space \n";
    for(int i =0; i<n; i++){
        cin>>v[i];
    }

    ArrayReader reader(v); // Reads the array.
    cout<<(sol.search(reader, target)); // Outputs the searched index.
}