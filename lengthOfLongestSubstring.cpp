/*
 * Author : Feng Wei
 * Date   : Nov 16, 2014
 *
 * Given a string, find the length of the longest substring without repeating characters. 
 * 
 * For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
 * 
 * which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 */
#include <iostream>
#include <map>
#include <string>
#include <string.h>
using namespace std;

/*
 * it is easy to give a solution whose run-time complexity is O(n^2), but we can use a hashmap to give a O(n) solution,
 *
 * we use a array locs[256] to store the characters's index that have been visited , for s[i]:
 *
 * 	1. if s[i] does not exist in locs, the substring's length + 1;
 * 	2. if s[i] exists in locs, we should choose the new substring thats start i + 1.
 */
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int max = 0;
		int index = -1;
		int locs[256];

		memset(locs, -1, sizeof(int) * 256);

		for (int i = 0;i < s.size(); ++i) {
			if (locs[s[i]] > index) {
				index = locs[s[i]];
			}

			if (i - index > max) {
				max = i - index;
			}

			locs[s[i]] = i;
		}

		return max;
	}
};

int main()
{
	Solution s;
	string str("abcabcbb");
	cout<<s.lengthOfLongestSubstring(str)<<endl;

	string str1("bbbbbbb");
	cout<<s.lengthOfLongestSubstring(str1)<<endl;

	string str2("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco");
	cout<<s.lengthOfLongestSubstring(str2)<<endl;

	string str3("zbexrampetvhqnddjeqvuygpnkazqfrpjvoaxdpcwmjobmskskfojnewxgxnnofwltwjwnnvbwjckdmeouuzhyvhg");
	cout<<s.lengthOfLongestSubstring(str3)<<endl;
	return 0;
}
