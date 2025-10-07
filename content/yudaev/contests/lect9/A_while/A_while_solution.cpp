#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

// Функция x * x+4*x+4 (f>=0)
float f(float x){
  float y;
  y = x * x + 4 * x + 4;
  return y; 
}

int main(){
   float y, x; 
   float a; //начало отрезка (a < b)
   float b; //конец отрезка (a >=0, b>=0)
   float delta;// размер шага
   int i, n;
   float s=0;
   
   delta = 2.0; 

   cin>>a>>b;
// количество шагов
   n = (b - a) / delta;

// сначала x равен началу отрезка (левые значения)
   x = a;

/*
   начинаем с нулевого шага i==0
   пока i <= n вычисляем значения функции
   и печатаем
*/
   i = 0;
   while(i <n){
//  вычислили значения в точке x
//  потом увеличим 
      y = f(x);
  //    cout<<"i="<<i<<" x="<<x<<" y="<<y<<endl;
      s+=y*delta;
   //   cout<<"s="<<s<<endl;
// изменили x на delta
      x = x + delta;
// увеличили номер шага
      i++; 
   }
    cout<<s<<endl;
}
