#include "ex03-library.h"
#include <iostream>

// Do not modify
WordsList::WordsList()
{
	allWords.push_back("121");
	wordsToPalindromeDistance["121"] = 0;
	allWords.push_back("122");
	wordsToPalindromeDistance["122"] = 1;
}

// Exercise 3 (a) implement this method
void WordsList::print()
{
	int size = this->allWords.size();
	cout << size << " words:";

	for (unsigned i = 0; i < size; i++)
	{
		cout << " " << allWords[i];
		cout << " (" << this->wordsToPalindromeDistance[allWords[i]] << ")";
	}
}

// Exercise 3 (b) implement this method
int WordsList::distancePalindrome(string s)
{
	if (s.size() == 0 || s.size() == 1)
		return 0;

	int i = 0, j = s.size() - 1;
	int distance = 0;
	while (i < j)
	{
		if (s[i] != s[j])
			distance++;
		i++;
		j--;
	}

	return distance;
}

// Exercise 3 (c) implement this method
void WordsList::addWord(string word)
{
	if (find(this->allWords.begin(), this->allWords.end(), word) != this->allWords.end())
		return;

	this->allWords.push_back(word);
	this->wordsToPalindromeDistance.insert(pair<string, int>(word, distancePalindrome(word)));
}

// Exercise 3 (d) implement this method
int WordsList::palindromeWords()
{
	int pwords = 0;

	for (auto const &[key, val] : wordsToPalindromeDistance)
	{
		if (val == 0)
			pwords++;
	}

	return pwords;
}