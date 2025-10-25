#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target){
    int rows = matrix.size(); int cols = matrix[0].size();
    cout<< "rows & columns -> "<<rows<<" "<<cols<<endl;
    int low = 0, mid = 0, eleX = 0, eleY = 0;
    int high = (rows*cols)-1;
    while(low<=high){
        mid = low + (high-low)/2;   
        eleX = mid/cols;
        eleY = mid%cols;
        if(matrix[eleX][eleY] == target){
            cout<<"Found it yeaahh at"<< eleX<<" "<<eleY<<endl;
            return true;
        }
        else if(matrix[eleX][eleY] < target){
            low = mid+1;
            cout<<"low++d round"<<endl;
        }
        else{
            cout<<"high++d round"<<endl;
            high = mid-1;
        }
    }
    cout<<"could not find bweh even at"<<eleX<<" "<<eleY<<endl;
    return false;
}

int main() {
    vector<vector<int>> x = {{1,1}};
    // vector<vector<int>> x = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 2;
    searchMatrix(x,target);
    return 0;
}