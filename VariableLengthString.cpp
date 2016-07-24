/*
 *	Author: Caleb A. Payton
 *	Various exercises dealing with the manipulation of a string
 */

#include <iostream>

using namespace std;

typedef char * arrayString;

char characterAt (arrayString s, int position)
{
	return s[position];
}

int length (arrayString s)
{
	int count = 0;
	while (s[count] != 0)
	{
		count++;
	}
	return count;
}

void append (arrayString& s, char c)
{
	int oldLength = length(s);
	arrayString newS = new char[oldLength + 2];
	for (int i = 0; i < oldLength; i++)
	{
		newS[i] = s[i];
	}
	newS[oldLength] = c;
	newS[oldLength + 1] = 0;
	delete[] s;
	s = newS;
}

void concatenate (arrayString& s1, arrayString s2)
{
	int s1_OldLength = length(s1);
	int s2_Length = length(s2);
	int s1_NewLength = s1_OldLength + s2_Length;
	arrayString newS = new char[s1_NewLength + 1];
	for (int i = 0; i < s1_OldLength; i++)
	{
		newS[i] = s1[i];
	}
	for (int i = 0; i < s2_Length; i++)
	{
		newS[s1_OldLength + i] = s2[i];
	}
	newS[s1_NewLength] = 0;
	delete[] s1;
	s1 = newS;
}

void substring (arrayString& s, int pos, int len)
{
	arrayString subString = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		subString[i] = s[i+pos];
	}
	subString[len] = 0;
	delete[] s;
	s = subString;
}

void replaceChar (arrayString& s, char a, char b)
{
	int oldLength = length(s);
	arrayString newS = new char[oldLength + 1];
	for (int i = 0; i < oldLength; i++)
	{
		if (s[i] == a)
		{
			newS[i] = b;
		}
		else
		{
			newS[i] = s[i];
		}
	}
	newS[oldLength] = 0;
	delete[] s;
	s = newS;
}

void replace (arrayString& s, arrayString target, arrayString replacement)
{
	int s_OldLength = length(s);
	int target_Length = length(target);
	int replacement_Length = length(replacement);
	int s_NewLength = s_OldLength - target_Length + replacement_Length;
	arrayString newS = new char[s_NewLength + 1];
	int pos = 0;
	do
	{
		for (int i = 0; i < target_Length; i++)
		{
			if (s[pos] == target[i])
			{				
				newS[pos] = replacement[i];
			}
			else
			{
				newS[pos] = s[pos];
			}
		}
		pos++;	
	} while (s[pos] != 0);
	newS[s_NewLength] = 0;
	delete[] s;
	s = newS;
}

int main ()
{
	arrayString a = new char[9];
	a[0] = 'a';
	a[1] = 'b';
	a[2] = 'c';
	a[3] = 'd';
	a[4] = 'a';
	a[5] = 'b';
	a[6] = 'e';
	a[7] = 'e';
	a[8] = 0;
	cout << a << "\n";
	arrayString b = new char[2];
	b[0] = 'a';
	b[1] = 0;
	arrayString c = new char[2];
	c[0] = 'x';
	c[1] = 0;
	replace(a, b, c);
	cout << a << "\n";	
	append(a, 'f');
	cout << a << "\n";
	substring(a, 1, 5);
	cout << a << "\n";
	replaceChar(a, 'x', 'z');
	cout << a << "\n";
}
