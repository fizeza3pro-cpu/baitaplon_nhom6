#include "ui.h"

// #define NOMINMAX        // tránh xung đột min/max
#undef byte            // 🔥 DÒNG QUAN TRỌNG NHẤT xoá định nghĩa byte của
#include <windows.h>
#include <iostream>
// 0 = Black      8 = Gray
// 1 = Blue       9 = Light Blue
// 2 = Green      10 = Light Green
// 3 = Aqua       11 = Light Aqua
// 4 = Red        12 = Light Red
// 5 = Purple     13 = Light Purple
// 6 = Yellow     14 = Light Yellow
// 7 = White      15 = Bright White
void UI::setColor(Color c) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void UI::println(const std::string& s, Color c) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(h, &csbi);

    setColor(c);
    std::cout << s << std::endl;
    SetConsoleTextAttribute(h, csbi.wAttributes);
}
void UI::doi_mau_full(int x) {
    HANDLE mau;
    mau = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(mau, x);
}
void UI::drawTitle(){
    std::cout << R"(

   _____                        ___           _     __           __  _         
  / ___/__  __ _________ ___   / _ \___ ___ _(_)__ / /________ _/ /_(_)__  ___ 
 / /__/ _ \/ // / __(_-</ -_) / , _/ -_) _ `/ (_-</ __/ __/ _ `/ __/ / _ \/ _ \
 \___/\___/\_,_/_/ /___/\__/ /_/|_|\__/\_, /_/___/\__/_/  \_,_/\__/_/\___/_//_/
                                      /___/                                  

)";
}
void UI::chuanhoa(int x){
    SetConsoleOutputCP(x);
    SetConsoleCP(x);
}
int UI::getUTF8LenDiff(std::string s) {
    int diff = 0;
    for (unsigned char c : s) {
        // Trong UTF-8, các byte phụ của ký tự có dấu luôn bắt đầu bằng 10xxxxxx (nhị phân)
        // tương đương với giá trị từ 128 đến 191
        if (c >= 128 && c <= 191) diff++;
    }
    return diff;
}