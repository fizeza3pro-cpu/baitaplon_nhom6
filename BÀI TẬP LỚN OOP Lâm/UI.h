#pragma once
#define _HAS_STD_BYTE 0
#include<iostream>
#include<conio.h>
#include<windows.h>
#include <thread>
using namespace std;
// Thay doi kich thuoc cua so console (pixel)
class ui{
       enum Color {
        DEFAULT = 7,
        GREEN   = 10,
        RED     = 12,
        YELLOW  = 14,
        BLUE    = 9
    };
        // 2️⃣ Các hàm static → gọi bằng UI::
    static void setColor(Color color);
    static void print(const std::string& text, Color color = DEFAULT);
    static void println(const std::string& text, Color color = DEFAULT);


};
void loading() {
    cout << "Loading";
    for(int i=0;i<3;i++){
        cout << ".";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(300));
    }
    cout<<endl;
}
inline void resizeConsole(int width, int height){
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x - 1;
    coord.Y = y - 1;
    
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(consoleHandle, coord);
}
void doi_mau_full(int x) {
    HANDLE mau;
    mau = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(mau, x);
}
void doimau_string(const string& text, int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    WORD currentColor;
    
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    currentColor = csbi.wAttributes;
    
    SetConsoleTextAttribute(hConsole, color);
    cout << text;
    SetConsoleTextAttribute(hConsole, currentColor);
}
void doimau_f(int color, const char* format, ...) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    WORD currentColor;
    
    // Lấy màu hiện tại
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    currentColor = csbi.wAttributes;
    
    // Đặt màu mới
    SetConsoleTextAttribute(hConsole, color);
    
    // In với định dạng
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    
    // Trở về màu cũ
    SetConsoleTextAttribute(hConsole, currentColor);
}
void drawTitle(){
    cout << R"(

                        888 888 888'Y88   88P'888'Y88 888 888   e88 88e   Y88b Y88   e88'Y88  
                        888 888 888 ,'Y   P'  888  'Y 888 888  d888 888b   Y88b Y8  d888  'Y  
                        8888888 888C8         888     8888888 C8888 8888D b Y88b Y C8888 eeee 
                        888 888 888 ",d       888     888 888  Y888 888P  8b Y88b   Y888 888P 
                        888 888 888,d88       888     888 888   "88 88"   88b Y88b   "88 88"  
                                                                           
                                                                           
888 88e       e Y8b     Y88b Y88   e88'Y88    888 88P Y88b Y8P      888       e88 88e   888 88e    888 888   e88 88e     e88'Y88 
888 888b     d8b Y8b     Y88b Y8  d888  'Y    888 8P   Y88b Y       888      d888 888b  888 888D   888 888  d888 888b   d888  'Y 
888 8888D   d888b Y8b   b Y88b Y C8888 eeee   888 K     Y88b        888     C8888 8888D 888 88"    8888888 C8888 8888D C8888     
888 888P   d888888888b  8b Y88b   Y888 888P   888 8b     888        888  ,d  Y888 888P  888        888 888  Y888 888P   Y888  ,d 
888 88"   d8888888b Y8b 88b Y88b   "88 88"    888 88b    888        888,d88   "88 88"   888        888 888   "88 88"     "88,d88 
                                                                       

)";
}
