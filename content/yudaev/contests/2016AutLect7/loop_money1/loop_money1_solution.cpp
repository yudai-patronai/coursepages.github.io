#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;


int main(){
  int price; 
  int m; //  
  int k;  // 
  int money = 0;
  int day = 1;
  int week = 1;

  cin>>price;
  cin>>k;
  cin>>m;
 
  
  while(week <= m){
       money+=price;
       price +=k;
   //  cout<<"week:"<<week<<" price="<<price<<" money="<<money<<endl; 
       day++;
 //      if((day - 1) % 7 == 0)
       if(day == 8){
         week++;
         day=1;
             
       }
   }   
    cout<<money<<endl;
         
}
