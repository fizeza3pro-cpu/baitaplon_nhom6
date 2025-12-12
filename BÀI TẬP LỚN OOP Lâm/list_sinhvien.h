#pragma once
#include<iostream>
#include<vector>
#include"sinhvien.h"
using namespace std;
class list_sinhvien {
private:
	vector<sinhvien>dssv;
public:
	void add_sinhvien(sinhvien a) {
		dssv.push_back(a);
	}
	void nhapds();
	void xuatds();
	bool lay_du_lieu_tu_file(string file_name);
	void them_sinhvien();
};