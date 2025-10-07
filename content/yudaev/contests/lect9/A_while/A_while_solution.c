#include <stdio.h>
#include <math.h>

// Функция x * x+4*x+4 (f>=0)
float f(float x){
  float y;
  y = x * x + 4 * x + 4;
  return y; 
}

int main(){
   float y, x; 
   float a;                         // начало отрезка (a < b)
   float b;                         // конец отрезка (a >=0, b>=0)
   float delta;                     // размер шага
   int i, n;
   float s=0;
   
   delta = 2.0; 

   scanf("%f%f", &a, &b);

   n = (b - a) / delta;             // количество шагов

   x = a;                           // сначала x равен началу отрезка (левые значения)

/*
   начинаем с нулевого шага i==0
   пока i <= n вычисляем значения функции
   и печатаем
*/
    i = 0;
    while(i<n){

        y = f(x);                   //  вычислили значения в точке x
        // printf("%i=%f x=%f y=%f ", i, x, y); 
        
        s += y*delta;
                                    // готовим следующий шаг
        x = x + delta;              // изменили x на delta    
        i++;                        // увеличили номер шага
   }
   printf("%f\n", s);
   return 0;
}
