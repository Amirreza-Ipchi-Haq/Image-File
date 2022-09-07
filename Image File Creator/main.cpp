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
    unsigned int x,y;
    unsigned short int r,g,b;
    string s,hex;
    ofstream image;
    cout<<"Please enter the file name: ",getline(cin,s);
    image.open(s.c_str());
    system("CLS");
    cout<<"Please enter the width & height in order: ";
    cin>>x>>y;
    image<<x,image<<' ',image<<y;
    initwindow(x,y);
    for(unsigned int i=0; i<y; i++)for(unsigned int j=0; j<x; j++)
        {
            system("CLS");
            cout<<"Please enter the hex color code of pixel ",cout<<j,cout<<'X',cout<<i,cout<<": ",cin>>s;
            image<<' ',image<<s;
            for(unsigned int k=0; k<2; k++)hex+=s[k];
            r=htd(hex),hex="";
            for(unsigned int k=2; k<4; k++)hex+=s[k];
            g=htd(hex),hex="";
            for(unsigned int k=4; k<6; k++)hex+=s[k];
            b=htd(hex),hex="";
            setcolor(COLOR(r,g,b));
            line(j,i,j+1,i+1);
        }
    image.close();
    getch();
}
