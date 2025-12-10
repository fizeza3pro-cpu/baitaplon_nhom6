#pragma once
#include<iostream>
#include"sinhvien.h"
using namespace std;
class list_sinhvien {
private:
	int sl;
	sinhvien* p[100];
public:
	list_sinhvien()
	{
		sl = 0;
		for (int i = 0; i < 100; i++)
		{
			p[i] = nullptr;
		}
	}
	void nhapds();
	void xuatds();
} 