#ifndef KURSACH
#define KURSACH

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <windows.h>
#include <math.h>
#include <time.h>
using namespace std;
class Num
{
protected:
	vector<int> bef;
public:
	Num() {};
	Num(string s) {};
	Num(long long s) {};
	Num(vector<int>& b) {};
	Num(const Num& b) {};
	~Num() {};
	Num operator +(Num b) {};
	Num operator /(Num b) {};
	Num operator %(Num b) {};
	Num operator -(Num b) {};
	Num operator *(Num b) {};
};

class Big:  public Num
{
public:
	Big() {}
	Big(string s)
	{
		bef.erase(bef.begin(), bef.end());
		int check = 0;
		if (s[0] == '-')
		{
			check = 2;
			bef.push_back((int(s[1]) - 48) * -1);
		}
		for (int i = 0 + check; i < s.size(); ++i)
		{
			bef.push_back(int(s[i]) - 48);
		}
	}
	Big(const Big& b)
	{
		bef.erase(bef.begin(), bef.end());
		bef.resize(b.bef.size());
		for (int i = 0; i < bef.size(); ++i)
		{
			bef[i] = b.bef[i];
		}
	}
	Big(vector<int>& b)
	{
		bef.erase(bef.begin(), bef.end());
		for (int i = 0; i < b.size(); ++i)
		{
			bef.push_back(b[i]);
		}
	}
	Big(long long s) 
	{
		bef.erase(bef.begin(), bef.end());
		int znak = 1;
		if (s < 0)
		{
			znak = -1;
			s = s * -1;
		}
		if (s == 0)
		{
			bef.push_back(0);
			return;
		}

		while (s > 0)
		{
			bef.push_back(s % 10);
			s = s / 10;
		}
		reverse(bef.begin(), bef.end());
		bef[0] *= znak;
	}
	
	
	~Big() {}
	void cut();
	Big operator +(Big b);
	Big operator /(Big b) ;
	Big operator %(Big b) ;
	Big operator -(Big b) ;
	Big operator *(Big b) ;

	
		
	friend Big operator *(Big a, long long b);
	friend bool operator >(Big a, Big b);
	friend bool operator <(Big a, Big b);
	friend bool operator ==(Big a, Big b);
	friend bool operator !=(Big a, Big b);
	friend ostream& operator<<(ostream& os, const Big& s);
	friend istream& operator>> (istream& is, Big& s);

};
#endif
