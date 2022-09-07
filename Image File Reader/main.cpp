#include<iostream>
#include<fstream>
#include<graphics.h>
#include<cmath>
#include<windows.h>
using namespace std;
unsigned int htd(string hex)
{
    unsigned short int d[23]= {0,1,2,3,4,5,6,7,8,9,0,0,0,0,0,0,0,10,11,12,13,14,15},n=0;
    for(unsigned int i=hex.size(),j=0; i; i--,j++)n+=d[hex[i-1]-48]*pow(16,j);
    return n;
}
int main()
{
    unsigned int x=0,y=0;
    unsigned short int r,g,b;
    string s, hex;
    ifstream image;
    cout<<"Please enter file path (must be .image format): ",getline(cin,s);
    image.open(s.c_str());
    image>>s;
    for(unsigned int i=0; i<s.size(); i++)x=x*10+s[i]-48;
    image>>s;
    for(unsigned int i=0; i<s.size(); i++)y=y*10+s[i]-48;
    initwindow(x,y);
    for(unsigned int i=0; i<y; i++)for(unsigned int j=0; j<x; j++)
        {
            image>>s;
            for(unsigned int k=0; k<2; k++)hex+=s[k];
            r=htd(hex), hex="";
            for(unsigned int k=2; k<4; k++)hex+=s[k];
            g=htd(hex), hex="";
            for(unsigned int k=4; k<6; k++)hex+=s[k];
            b=htd(hex), hex="";
            setcolor(COLOR(r,g,b));
            line(j,i,j+1,i+1);
        }
    image.close();
    getch();
}
