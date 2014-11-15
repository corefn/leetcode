/* 
 * Author : Feng Wei
 * Date   : Nov 15, 2014
 *
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they add up to the target, 
 * where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 *
 * Output: index1=1, index2=2 
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

/*
 * the easy solution is O(n^2) runtime complexity
 * 		
 * 		foreach(item1 in array) {
 * 			foreach(item2 in array) {
 * 				if (item1 + item2 == target) {
 * 					return result;
 * 				}
 * 			}
 * 		}
 * we can find that the nested loop just for search
 * so we can use a hashmap to reduce the searching complexity from O(n) to O(1)
 */

class Solution {
public:
	/*
	 * the implementation as blow based on map<int, int>:
	 *
	 * 1. travel the array one by one
	 * 2. put the  "target - numbers[i]" into the map
	 *    when we go on checking the next numbers[i] ,if it is existing in the map ,
	 *    the second one is found.
	 */
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int,int> IndexNumbers;
        vector<int> result;
        for (size_t i = 0; i < numbers.size(); ++i) {
            if (IndexNumbers.find(numbers[i]) == IndexNumbers.end())  {
                IndexNumbers[target - numbers[i]] = i;
            }
            else {
                result.push_back(IndexNumbers[numbers[i]] + 1);
                result.push_back(i + 1);
            }
        }
        return result;
    }
};

int main()
{
    vector<int> test;
    test.push_back(2);
    test.push_back(7);
    test.push_back(11);
    test.push_back(15);
    Solution s;

    vector<int> result = s.twoSum(test, 9);
    for (size_t i = 0; i < result.size(); ++i) {
        cout <<"index" << i + 1<<" = " <<result[i]<<" ";
    }
    return 0;
}
