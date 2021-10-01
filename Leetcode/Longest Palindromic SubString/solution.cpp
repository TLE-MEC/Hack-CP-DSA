// A C++ answer for longest palindromic substring
#include <bits/stdc++.h>
using namespace std;
// Function to print a substring str[low...high]
void printSubStr(string str, int low, int high)
{
	for (int i = low; i <= high; ++i)
		cout << str[i];;
}
// This function prints the largest palindrome substring
// It also returns the length of the longest palindrome
int longestPalindromicSubstring(string str)
{
	// get length of input string
	int n = str.size();
	// All substrings of length 1 are palindromes
	int maxLength = 1, start = 0;
	// Nested loop to sign start and end indexes
	for (int i = 0; i < str.length(); i++) {
		for (int j = i; j < str.length(); j++) {
			int flag = 1;
			// Check palindrome
			for (int k = 0; k < (j - i + 1) / 2; k++)
				if (str[i + k] != str[j - k])
					flag = 0;
			// Palindrome
			if (flag && (j - i + 1) > maxLength) {
				start = i;
				maxLength = j - i + 1;
			}
		}
	}
	cout << "Longest palindrome substring is: " << endl;
	printSubStr(str, start, start + maxLength - 1);
	// return length of Longest palindromic substring
	return maxLength;
}
// Driver Code
int main()
{
	string str = "chennai";
	cout << longestPalindromicSubstring(str) << endl;
	return 0;
}