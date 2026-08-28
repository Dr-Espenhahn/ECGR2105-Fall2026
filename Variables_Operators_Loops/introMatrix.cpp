#include <iostream>
#include <vector>

using namespace std;

int main(){

    int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    vector<vector<int>> matrix2; //allows various sized 2d vector

    vector<int> vectorName;

    vector<vector<int>> vector2D;

    // matrix[1] == {4,5,6}
    for (int j=0; j < 3; j++){
        for (int i : matrix[j]){
            cout << i;
        } 
        cout << endl;
    }
    


    return 0;
}