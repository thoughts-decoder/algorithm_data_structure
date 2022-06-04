#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int negative = 0, i = 0,left = 1, right = 1;
        vector<int> sorted;
        while (i < nums.size()){
            if (nums[i] < 0){
                negative = i + 1;
                i++;
            }
        }
        if (negative == nums.size()){
            int i = nums.size() - 1;
            while ( i >= 0){
                sorted.push_back(nums[i] * nums[i]);
                i --;
            }

        }
        else if (negative == 0){
            int i = 0;
            while ( i < nums.size()){
                sorted.push_back(nums[i] * nums[i]);
                i ++;
            }
        }
        else{
            sorted.push_back(nums[negative] * nums[negative]);
            while((negative - left) >= 0  && (negative + right) < nums.size()){
                if (abs(nums[negative - left]) > nums[negative + right]){
                    sorted.push_back(nums[negative - left] * nums[negative - left]);
                    left ++;
                }
                else{
                    sorted.push_back(nums[negative + right] * nums[negative + right]);
                    right ++;
                }
            }
            while ((negative - left) >= 0){
                    sorted.push_back(nums[negative - left] * nums[negative - left]);
                    left ++;                
            }
            while ((negative + right) < nums.size()){
                    sorted.push_back(nums[negative + right] * nums[negative + right]);
                    right ++;                
            }


        }


        return sorted;
    }
};
void printVector(vector<int>& c){
    for(int i = 0; i < c.size(); i++){
        cout << c[i] << " ";
    }
    cout << endl;
}

int main(){

    vector< int> c = {0,3,10};
    vector<int> ss;
    class Solution s;
    ss = s.sortedSquares(c);
    printVector(ss);

    return 0;
}