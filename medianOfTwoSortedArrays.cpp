/*
 * Author : Feng Wei
 * Date   : Nov 15, 2014
 *
 * There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays.
 *
 * The overall run time complexity should be O(log (m+n)).
 */

#include <iostream>
#include <algorithm>
using namespace std;

/*
 * we are required to find the median of array, 
 *
 * 		if array.len is odd {
 * 			return array[(len + 1) / 2 ];
 * 		}
 * 		else {
 * 			return (array[len / 2] + array[len / 2 + 1]) / 2;
 * 		}
 * 		note: len = m + n
 */
class Solution {
public:
	/*
	 * the problem can be transformed to find the kth smallest number in two arrays,
	 *
	 * Supposed that two arrays A and B, A.size() > k / 2 and B.size() > k / 2:
	 *
	 * 		1. if A[k / 2 - 1] < B[k / 2 - 1], it means that A[0] ~  A[k / 2 - 1] in the top k of the array merged A and B;
	 * 		2. if A[k / 2 - 1] > B[k / 2 - 1], this sitution is similar to 1;
	 * 		3. if A[k / 2 - 1] = B[k / 2 - 1], return A[k / 2 - 1] or B[k / 2 - 1].
	 *
	 * 	but we must consider some edge cases:
	 *
	 * 		1. if A or B is empty, return B[k - 1] or A[k - 1];
	 * 		2. if k == 1, return min(A[0], B[0]);
	 * 		3. if A[k / 2 - 1] == B[k / 2 - 1], return one of them.
	 */

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int len = m + n;
		double result;

		if ((len & 1) != 0) {
			return findKNum(A, m, B, n, len / 2 + 1);
		}
		else {
			double a = findKNum(A, m, B, n, len / 2);
			double b = findKNum(A, m, B, n, len / 2 + 1);
			return (a + b) / 2;
		}

		return -1;
    }

	double findKNum(int *A, int m, int *B, int n, int k)
	{
		if (m > n) {
			return findKNum(B, n, A, m, k);
		}

		if ( m == 0) {
			return B[k - 1];
		}
		if (k == 1) {
			return min(A[0], B[0]);
		}
		int pa = min(k / 2, m);
		int pb = k - pa;
		if (A[pa - 1] < B[pb - 1]) {
			return findKNum(A + pa, m - pa, B, n, k - pa);
		}
		else if (A[pa - 1] > B[pb - 1]) {
			return findKNum(A, m, B + pb, n - pb, k - pb);
		}
		else {
			return A[pa - 1];
		}

		return -1;
	}
};

int main()
{
	Solution s;

	int a[] = {1,2};
	int b[] = {1,2};
	cout << s.findMedianSortedArrays(a, 2, b, 2) <<endl;

	int c[] = {};
	int d[] = {1,2};
	cout << s.findMedianSortedArrays(c, 0, d, 2)<<endl;

	int e[] = {1};
	int f[] = {1};
	cout << s.findMedianSortedArrays(e, 1, f, 1)<<endl;
	return 0;
}
