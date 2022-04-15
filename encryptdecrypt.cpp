#include<iostream>
#include<math.h>
#include <fstream>
using namespace std;
int gcd(int a, int h)
{
    int temp;
    while(1)
    {
        temp = a%h;
        if(temp==0)
        return h;
        a = h;
        h = temp;
    }
}
int main()
{
    double p,q;
    cout<<"Enter two Prime Numbers";
    cin>>p>>q;
    double n=p*q;
    double count;
    double totient = (p-1)*(q-1);
    double e=36;
    while(e<totient){
    count = gcd(e,totient);
    if(count==1)
        break;
    else
        e++;
    }   
    double d;
    double k = 36;
    d = (1 + (k*totient))/e;
    int ans;
    double en;
	string in;
	cout<<"Enter File Name -"<<endl;
	cin>>in;
	char c,fc;
	ifstream fin;
	ofstream fout;
	fin.open(in.c_str(), ios::binary);
	in = "encrypt";
	fout.open(in.c_str(), ios::binary);
	while (!fin.eof())
		{
			fin>>noskipws>>c;
             double temp = pow(c,e);
             en = temp;
			temp=fmod(temp,n);
			fout<<(char)temp;
		}
		fin.close();
		fout.close();
        cout<<"THE FOLLOWING FILE IS ENCRYPTED -"<<endl;
	
	    cout<<"Enter File Name to decrpt -"<<endl;
        cin>>in;
		string ft;
		cout<<"Enter File Format Type -"<<endl;
		cin>>ft;
		ifstream finn;
		ofstream foutt;
		finn.open(in.c_str(), ios::binary);
		in = "decrypt" + ft;
		foutt.open(in.c_str(), ios::binary);
		while (!finn.eof())
		{
            finn>>noskipws>>c;
			double temp2= pow(en,d);
            temp2=fmod(temp2,n);
		   foutt<<(char)temp2;
        }
		finn.close();
		foutt.close();
    return 0;
}
