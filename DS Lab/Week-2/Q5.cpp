#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target)
{

    int row = matrix.size();
    int col = matrix[0].size();
    int s = 0, e = row * col - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (matrix[mid / col][mid % col] == target)
        {
            return true;
        }
        else if (matrix[mid / col][mid % col] > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return false;
}
int main(){
    int row , col;
    cout <<"Enter the number of rows and columns"<<endl;
    cin>> row>>col;
    vector<vector<int>> matrix;

    
    for (int i = 0; i < row; i++) {
        vector<int> temp;
        for (int j = 0; j < col; j++) {
            temp.push_back(i * 4 + j); 
        }
        matrix.push_back(temp); 
    }
    int k ;
    cout<<"enter the element to be found "<<endl;
    cin>>k;
    cout <<"key value present or not: "<<searchMatrix(matrix, k)<<endl;
}
