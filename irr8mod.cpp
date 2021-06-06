#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<stdio.h>
#include<math.h>
#include<conio.h>
using namespace std;

main()
{

    float MX[5],theta_max,sum1=0,ten_th_percentile,trial,random_deplacer;
    string name1[1];
    float noofen=4;
    char filename[100]={"inputs.txt"};
 ifstream take(filename);

 for(int i=0 ;i<noofen;i++)
 {
     take>>MX[i];
 }


     take>>name1[0];
//system("Drawing1.dwg");

//remove("ofstream.xls");
string name;
    float roll,q,b,u1,Tw,tw,h1,h2,fr1,l,s,w,id;
    double lbyh2,lh;

//ofstream xl;
std::ofstream xl("drawing_codes_for_autocad_16_or_higher.txt");
std::ofstream dl("docs.txt");

roll=MX[0];

if(roll<=50)
    q=roll+20000;
else if(roll<=100)
    q=roll+18000;
else
    q=roll+15000;


b=MX[1];


u1=MX[3];


Tw=MX[2];
name=name1[0];



h1=q/(b*u1);
fr1=u1/(sqrt(9.81*h1));
h2=h1*.5*(sqrt(1+8*fr1*fr1)-1);

if(Tw<h2)
Tw=.9*h2;

lh=7.72328373481017390000+-4.61019934614066700000*pow(fr1,1)+1.87595361230146400000*pow(fr1,2)+-0.38008076144493080000*pow(fr1,3)+0.04368156794151419700*pow(fr1,4)+-0.00289534198655535740*pow(fr1,5)+0.00010322561965850397*pow(fr1,6)+-0.00000153458893468831*pow(fr1,7);
l=h2*lh;
s=.15*h2;
w=.15*h2;
tw=.02*h2;
int n1,n2;
n1=(b-2*h1)/(2*h1);
n2=(b-2*.02*h2)/(2*.15*h2);



int n;
n=3;


//xl<<"\n\t\t\t\t\t\t\t\th1=\t"<<h1<<"\n\t\t\t\t\t\t\t\tfr1=\t"<<fr1<<"\n\t\t\t\t\t\t\t\th2\t="<<h2<<"\n\t\t\t\t\t\t\t\ttw=\t"<<Tw<<"\n\t\t\t\t\t\t\t\tL=\t"<<l<<"\n\t\t\t\t\t\t\t\ts=\t"<<s<<"\n\t\t\t\t\t\t\t\tw=\t"<<w<<"\n\t\t\t\t\t\t\t\ttopw=\t"<<tw<<"\n\t\t\t\t\t\t\t\ttL=\t"<<l<<"\n";
h2=.2*h2;
dl<<q<<"\n"<<Tw<<"\n"<<b<<"\n"<<0<<"\n"<<u1<<"\n"<<h1<<"\n"<<fr1<<"\n"<<(h2/.2)/h1<<"\n"<<q<<"\n"<<Tw<<"\n"<<h1<<"\n"<<fr1<<"\n"<<h2/.2<<"\n"<<l;


for(int i=1;i<=n2;i++)
{
    xl<<"WEDGE";
    xl<<"\n"<<l<<","<<.2*h2+w*(i-1)+s*(i-1);
    xl<<"\n"<<l+1.5*h2<<","<<.2*h2+w*(i-0)+s*(i-1);
    xl<<"\n"<<h2;
    xl<<"\nENTER";

      xl<<"\nWEDGE";
    xl<<"\n"<<l+.8572*h2<<","<<.2*h2+w*(i-0)+s*(i-1);
    xl<<"\n"<<l<<","<<.2*h2+w*(i-0)+s*(i-0);
    xl<<"\n"<<.4285*h2;
      xl<<"\nENTER";


     xl<<"\nWEDGE";
    xl<<"\n"<<l+.8572*h2<<","<<.2*h2+w*(i-0)+s*(i-1);
    xl<<"\n"<<l+1.5*h2<<","<<.2*h2+w*(i-0)+s*(i-0);
    xl<<"\n"<<.4285*h2;
     xl<<"\nENTER";


     xl<<"\nBOX";
    xl<<"\n"<<l-.02*h2<<","<<.2*h2+w*(i-1)+s*(i-1);
    xl<<"\n"<<l<<","<<.2*h2+w*(i-0)+s*(i-1);
    xl<<"\n"<<h2;
    xl<<"\n";





}
for(int i=1;i<=n1;i++)
{
         xl<<"WEDGE";
    xl<<"\n"<<0<<","<<h1+h1*(i-1)+h1*(i-1)<<","<<h1;
    xl<<"\n"<<-h1<<","<<h1+h1*(i-0)+h1*(i-1)<<","<<h1;
    xl<<"\n"<<-h1;
     xl<<"\nENTER\n";


}




xl<<"BOX\n";
xl<<"0,0\n"<<l<<","<<b<<"\n-3\nENTER";


   xl<<"\nWEDGE";
    xl<<"\n"<<-50<<","<<0;
    xl<<"\n"<<0<<","<<b;
    xl<<"\n"<<30;
     xl<<"\nENTER";

     xl<<"\nBOX\n";
xl<<l<<","<<0<<"\n"<<l+1.5*h2<<","<<b<<"\n-3\nENTER";

 xl<<"\nBOX\n";
xl<<l+h2<<","<<0<<"\n"<<l+1.5*h2<<","<<b<<"\n-10\nENTER";


     xl<<"\nBOX\n";
xl<<0<<","<<0<<"\n"<<-50<<","<<b<<"\n-3\nENTER";

xl<<"\n-TEXT";
xl<<"\n"<<-26<<","<<15<<","<<25;
xl<<"\n"<<7<<"\n"<<90;
xl<<"\nName : "<<name<<"\nENTER";

xl<<"\n-TEXT";
xl<<"\n"<<-
15<<","<<15<<","<<25;
xl<<"\n"<<7<<"\n"<<90;
xl<<"\nStd id : "<<roll<<"\nENTER";



xl.close();
dl.close();

system("base.exe");




 //std::ofstream ofs;
  //ofs.open("ofstream.xls", std::ofstream::out | std::ofstream::app);
//ofs.close();

//system("ofstream.xls");


}
