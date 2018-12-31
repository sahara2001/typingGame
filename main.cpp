#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include <Windows.h>
using namespace std;
/**
 * Declaim: This program is copied from zsc2015030401035 at https://blog.csdn.net/zsc2015030401035/article/details/50921764 and
 *  is only used for reference of the component usage.
 */
// Generate number, upper and lower case letters uniformly among catagories
char RandomChar()
{
    int type = rand() % 3;
    if (type == 0)
    {
        return rand() % 10 + '0';
    }
    if (type == 1)
    {
        return rand() % 26 + 'A';
    }
    return rand() % 26 + 'a';
}
// move cursor to console position (x,y)
void gotoxy(int x, int y)
{
    CONSOLE_SCREEN_BUFFER_INFO cs;
    HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut, &cs);
    cs.dwCursorPosition.X = y;
    cs.dwCursorPosition.Y = x;
    SetConsoleCursorPosition(hConsoleOut,
        cs.dwCursorPosition);
}

int main()
{
    //get console handle for changing font color
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//获取控制台的句柄，用于随意改变字体颜色

    cout << "Game Description: \n";
    cout << "Finite number of arbitrary words fall through screen, get right more -> Higher Score \n\n";
    cout << "Press arbitrary key to continue...\n\n";
    getch();
    cout << "Press arbitrary key to start Game...\n";
    getch();
    system("cls");//清除屏幕当前所有信息
    bool again = 1;//判断是否重来游戏
    while (again)
    {
        srand((unsigned int)time(NULL));//随机产生数字

        int x[100];//记录x轴信息
        int y[100];//记录y轴信息
        char target[100];//记录字符信息
        int  score = 0;//游戏得分
        cout << "Please enter number corresponding to you desired toughness...\n";
        cout << "1: " << "Beginner" << endl;
        cout << "2: " << "Simple" << endl;
        cout << "3: " << "Normal" << endl;
        cout << "4: " << "Hard" << endl;
        cout << "5: " << "Nightmare" << endl;
        cout << endl;
        int n;
        cin >> n;
        system("cls");//清除屏幕当前所有信息
        gotoxy(0, 55);//游戏得分位置
        cout << "Current Score: " << score;

        SetConsoleTextAttribute(hOut,
            FOREGROUND_RED |
            FOREGROUND_INTENSITY);  //红色
        gotoxy(20 - 2 * n, 0);//按难度定义游戏终止位置
        cout << "-------deadline------------deadline--------------deadline--------" << endl;

        SetConsoleTextAttribute(hOut,
            FOREGROUND_GREEN |
            FOREGROUND_INTENSITY);  //绿色
        for (int i = 1; i <= 2 * n; i++)
        {
            x[i] = 0;
            y[i] = rand() % 50;
        }
        for (int i = 1; i <= 2 * n; i++)
        {
            target[i] = RandomChar();
        }
        bool gameOver = 0;//judge gameover
        while (gameOver == 0)
        {
            while (!kbhit()) // When user does not press a key
            {
                for (int i = 1; i <= 2 * n; i++)
                {
                    gotoxy(x[i], y[i]);
                    cout << target[i];
                    x[i]++;
                    if (x[i] == 20 - 2 * n) // word reach bottom line
                    {
                        gameOver = 1;
                    }
                }
                Sleep(1000 - n * 100);          // speed of word dropping determined by hardness
                for (int i = 1; i <= 2 * n; i++)
                {
                    gotoxy(x[i] - 1, y[i]);
                    cout << ' ';                // erase word at line before

                }
                if (gameOver)
                {
                    break;
                }
            }
            if (gameOver)  //gameover judge again
            {
                break;
            }
            char userHit = getch();
            for (int i = 1; i <= 2 * n; i++)
            {
                if (target[i] == userHit)// user hit a char
                {
                    score++;
                    gotoxy(0, 65);
                    cout << score;
                    gotoxy(x[i], y[i]);
                    cout << ' ';//erase char

                    // regenerate char
                    x[i] = 0;
                    y[i] = rand() % 50;
                    target[i] = RandomChar();
                }
            }
        }

        SetConsoleTextAttribute(hOut,
            FOREGROUND_RED |
            FOREGROUND_GREEN |
            FOREGROUND_BLUE |
            FOREGROUND_INTENSITY); //white
        gotoxy(20 - 2 * n + 2, 0);
        cout << " WASTED \nFinal Score: ";

        SetConsoleTextAttribute(hOut,
            FOREGROUND_GREEN |
            FOREGROUND_INTENSITY);  //绿色
        cout << score;

        SetConsoleTextAttribute(hOut,
            FOREGROUND_RED |
            FOREGROUND_GREEN |
            FOREGROUND_BLUE |
            FOREGROUND_INTENSITY); //白色
        cout << "Char\n\nChallenge Again? Y/N\n";
        string str;
        cin >> str;
        if (str == "N" || str == "n")
        {
            cout << "Bye!\n";
            break;
        }
        else
        {
            system("cls");//erase screen
        }
    }
    return 0;
}
/*
--------------------- 
作者：zsc2015030401035 
来源：CSDN 
原文：https://blog.csdn.net/zsc2015030401035/article/details/50921764 
版权声明：本文为博主原创文章，转载请附上博文链接！

*/