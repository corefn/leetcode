/*
 * Author : Feng Wei
 * Date   : Nov 18, 2014
 *
 * Given a string S, find the longest palindromic substring in S. 
 * 
 * You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	/*
	 * use  Dynamic programming, time complexity is O(n^2) and space complexity is also O(n^2):
	 *
	 * we use a two-dimensional arry table[1000][1000] to store some infomation:
	 *
	 * 		1. if s[i] ~ s[j] is a palindrome, table[i][j] = true,otherwise ,table[i][j] = false;
	 *
	 * 		2. if s[i] = s[j], table[i][j] = table[i + 1][j - 1];
	 *
	 * 		3. table[i][i] = 1, and table[i][i+1] = 1 if s[i] = s[i + 1].
	 */
	string longestPalindrome(string s) {
		int n = s.size();
		int longest_substr_begin = 0;
		int max_len = 1;
		bool table[1000][1000] = {false};

		for (int i = 0; i < n; ++i) {
			table[i][i] = true;
		}

		for (int i = 0; i < n - 1; i++) {
			if (s[i] == s[i + 1]) {
				table[i][i + 1] = true;
				longest_substr_begin = i;
				max_len = 2;
			}
		}

		for (int len = 3; len <= n; len++) {
			for (int i = 0; i < n - len + 1; ++i) {
				int j = i + len - 1;
				if (s[i] == s[j] && table[i + 1][j - 1]) {
					table[i][j] = true;
					longest_substr_begin = i;
					max_len = len;
				}
			}
		}

		return s.substr(longest_substr_begin, max_len);
	}
};

int main()
{
	Solution s;
	cout<<s.longestPalindrome("weiew")<<endl;
	cout<<s.longestPalindrome("abb")<<endl;
	cout<<s.longestPalindrome("tattarrattat")<<endl;

	return 0;
}
