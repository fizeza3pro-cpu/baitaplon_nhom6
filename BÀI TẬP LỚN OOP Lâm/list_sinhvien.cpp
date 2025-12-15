#include<iostream>
#include"list_sinhvien.h"
#include<string>
using namespace std;

void list_sinhvien::nhapds()
{
	int sl;
	cout << "Nhap so luong sinh vien :";
	cin >> sl;
	for (int i = 0; i < sl; i++)
	{
		cout << "Nhap thong tin sinh vien thu " << i + 1<<":"<<endl;
		dssv[i].nhap();
	}
}
void list_sinhvien::xuatds()
{
	cout << "-------Thong tin sinh vien-------";
	for (int i = 0; i <dssv.size(); i++)
	{
		dssv[i].hienthithongtin();
		cout << "\n";
	}
}
bool list_sinhvien::lay_du_lieu_tu_file(string file_name){
    ifstream f(file_name);
    if(!f.is_open()){
        cout<<"ko mo dc file!"<<endl;
        return false; //lỗi gì gì đấy
    }else{
        sinhvien sv_temp;
        while(sv_temp.nhap_du_lieu_tu_file(f)){
            dssv.push_back(sv_temp);
        }
    }
    f.close();
	return true;
}
sinhvien * list_sinhvien::tim_sinhvien_theo_id(string ma_sv){
	for(int i = 0;i<dssv.size();i++){
		if(dssv[i].get_ma() == ma_sv){
			return &dssv[i];
		}
	}
 	return nullptr;
}
// -------
void list_sinhvien::them_sinhvien() {
    sinhvien sv;
    sv.nhap();

    dssv.push_back(sv);

    ofstream f("D:/dulieusinhvien.txt", ios::app);  // ghi thêm cuối file
    sv.ghi_vao_file();
    f.close();
}


// void list_sinhvien::xuatds()
// {
//     ifstream f("D:/dulieusinhvien.txt");
//     if (!f.is_open()) {
//         cout << "Không mở được file!\n";
//         return;
//     }

//     string line;

//     while (getline(f, line))
//     {
//         vector<string> a;
//         string temp = "";

//         for (char c : line)
//         {
//             if (c == '|') {
//                 a.push_back(temp);
//                 temp = "";
//             }
//             else temp += c;
//         }
//         a.push_back(temp); // phần cuối cùng

//         if (a.size() >= 11)
//         {
//             cout << a[0] << " | " << a[1] << " | " << a[2]
//                 << " | " << a[3] << " | " << a[4] << " | "
//                 << a[5] << "/" << a[6] << "/" << a[7]
//                 << " | " << a[8] << " | " << a[9]
//                 << " | " << a[10] << endl;
//         }
//     }
//     f.close();
// }


    


