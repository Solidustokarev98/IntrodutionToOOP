#include "stdafx.h"
#include"String.h"

#define HOME_WORK
//#define CONSTRUCTORS_CALLING

void main()
{
    setlocale(LC_ALL,"");
    //String str1;
    //str1.print();

    String str = "Hello";
    //str.print();
    //cout << str << endl;
#ifdef HOME_WORK
    String str1 = "Hello";
    //cout << str1 << endl;
    String str2 = "World";
    //cout << str2 << endl;
   // String str3 = str1 + str2;
    //cout << str3 << endl;
    str1 += str2;
    cout << str1 << endl;
#endif // HOME_WORK    
#ifdef CONSTRUCTORS_CALLING
    String str1; //Default constructor
    str1.print();
    
    String str2(22);    //Single-Argument constructor 'int'
    str2.print();

    String str3="Hello";    //Single-Argument constructor 'const char*'
    str3.print();

    String str4();   /*Default constructor НЕВОЗМОЖНО вызвать таким образом.
    В этой строке объявляется функция str4, которая ничегоне принимает,
    и возвращает объект класса String*/
    //str4.print();
    //Если нужно вызвать конструктор по умолчанию, то это можно сделать таке
    String str5{}; //Default constructor
    str5.print();
    
    String str6{"World"};
    str6.print();

    String str7=str3;   //CopyConstructor
    str7.print();

    String str8;   //CopyAssignment
    str8 = str6;
    str8.print();
#endif // CONSTRUCTORS_CALLING    
}