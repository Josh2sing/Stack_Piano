#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#define MAX 1000
using namespace std;
//Stack Class
class Stack
{
public:
    char a[MAX];
    int top;

    Stack() { top = -1; }
    //Push method
    bool Push(int x)
    {
        if (top >= (MAX - 1)) {
            cout << "Stack Overflow";
            return false;
        }
        else {
            a[++top] = x;
            cout << x << " pushed into stack\n";
            return true;
        }
    }
    //Pop Method
    //Using char because piano key is char and special key
    char Pop()
    {
        if (top < 0) {
            return 0;
        }
        else {
            int x = a[top--];
            return x;
        }
    }
    int Size()
    {
        return top;
    }
    char Peek()
    {
        if (top < 0) {
            return 0;
        }
        else {
            int x = a[top];
            return x;
        }
    }
    bool isEmpty()
    {
        return (top < 0);
    }
};
//Piano Class
class Piano
{
private:
    ifstream file;
    string fileString;
    Stack backString;
    char note = '0';
    int x = 0;
public:
    //Put file into string
    //Put string into stack
    void LoadNotes(string s)
    {
        file.open(s);
        while (file >> fileString) {}
        for (int i = 0; i < fileString.length(); i++)
            backString.Push(fileString[i]);
        cout << fileString << endl;
    }
    //Playnotes function
    void PlayNotes()
    {
        x = 0;
        while (x < fileString.length()){
            note = fileString[x];
            //do re mi fa sol la si do re mi fa sol
            if (note == 'a') {
                Beep(261, 100);
            }
            if (note == 's') {
                Beep(293, 100);
            }
            if (note == 'd') {
                Beep(329, 100);
            }
            if (note == 'f') {
                Beep(349, 100);
            }
            if (note == 'g') {
                Beep(392, 100);
            }
            if (note == 'h') {
                Beep(440, 100);
            }
            if (note == 'j') {
                Beep(493, 100);
            }
            if (note == 'k') {
                Beep(523, 100);
            }
            if (note == 'l') {
                Beep(587, 100);
            }
            if (note == ';') {
                Beep(659, 100);
            }
            if (note == '\'') {
                Beep(698, 100);
            }
            if (note == '\\') {
                Beep(784, 100);
            }

            //rebemol mibemol solbemol labemol sibemol rebemol mibemol solbemol
            if (note == 'w') {
                Beep(277, 100);
            }
            if (note == 'e') {
                Beep(311, 100);
            }
            if (note == 't') {
                Beep(370, 100);
            }
            if (note == 'y') {
                Beep(415, 100);
            }
            if (note == 'u') {
                Beep(466, 100);
            }
            if (note == 'o') {
                Beep(554, 100);
            }
            if (note == 'p') {
                Beep(622, 100);
            }
            if (note == ']') {
                Beep(740, 100);
            }
            x++;
            system("cls");
        }
    }
    void PlayNotesBackwards()
    {
        //Playnotes function but with a stack instead of string 
        x = 0;
        while (!backString.isEmpty()) {
           /* if (x == fileString.length())
                break;*/
            note = backString.Pop();
            //do re mi fa sol la si do re mi fa sol
            if (note == 'a') {
                Beep(261, 100);
            }
            if (note == 's') {
                Beep(293, 100);
            }
            if (note == 'd') {
                Beep(329, 100);
            }
            if (note == 'f') {
                Beep(349, 100);
            }
            if (note == 'g') {
                Beep(392, 100);
            }
            if (note == 'h') {
                Beep(440, 100);
            }
            if (note == 'j') {
                Beep(493, 100);
            }
            if (note == 'k') {
                Beep(523, 100);
            }
            if (note == 'l') {
                Beep(587, 100);
            }
            if (note == ';') {
                Beep(659, 100);
            }
            if (note == '\'') {
                Beep(698, 100);
            }
            if (note == '\\') {
                Beep(784, 100);
            }

            //rebemol mibemol solbemol labemol sibemol rebemol mibemol solbemol
            if (note == 'w') {
                Beep(277, 100);
            }
            if (note == 'e') {
                Beep(311, 100);
            }
            if (note == 't') {
                Beep(370, 100);
            }
            if (note == 'y') {
                Beep(415, 100);
            }
            if (note == 'u') {
                Beep(466, 100);
            }
            if (note == 'o') {
                Beep(554, 100);
            }
            if (note == 'p') {
                Beep(622, 100);
            }
            if (note == ']') {
                Beep(740, 100);
            }
            x++;
            system("cls");
        }
    }
};
class Rectangle
{
    int x, y, w, h;
    char c;
public:
    Rectangle(int xX, int yY, int wW, int hH, char cC) { x = xX; y = yY; w = wW; h = hH; c = cC; }
    void make()
    {
        gotoxy(x, y);
    }
};

void gotoxy(int x,int y)
{
    COORD c;
    c.X = x;
    c.Y = x;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
}
//Main Class
void main()

{

    Piano mypiano;

    mypiano.LoadNotes("c:\\temp\\mynotes.txt");

    mypiano.PlayNotes();

    mypiano.PlayNotesBackwards();

}