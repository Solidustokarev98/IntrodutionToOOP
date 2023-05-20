#include <iostream>
using namespace std;

class String;
String operator+(const String& left, const String& right);
class String
{
    int size;       //Размер строки
    char* str;     //Адрес строки в динамической памяти
public:
    int get_size()const
    {
        return size;
    }
    const char* get_str()const
    {
        return str;
    }
    char* get_str()
    {
        return str;
    }
    //          Constructors:
    String(int size = 80)
    {
        this->size = size;
        this->str = new char[size] {};
        cout << "Constructor:\t" << this << endl;
    }
    String(const char* str)
    {
        size = strlen(str)+1;
    }
    ~String()
    {
        delete[] this->str;
        cout<<"Destructor:\t" << this << endl;
    }
    const char& operator[](int i)const
    {
        return str[i];
    }
    char& operator[](int i)
    {
        return str[i];
    }
    //      Methods:
    void print()const
    {
        cout << "Size: " << size << endl;
        cout << "Str: " << str << endl;
    }
};
String operator+(const String& left, const String& right)
{
    String result(left.get_size() + right.get_size() - 1);
    for (int i = 0; i < left.get_size(); i++)
        //l-value = r-value;
        result[i] = left[i];
    //result.get_str()[i] = left.get_str()[i];
    for (int i = 0; i < right.get_size(); i++)
        result[left.get_size() - 1 + i] = right[i];
    //result.get_str()[left.get_size() - 1 + i] = right.get_str()[i];
    return result;
}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
    return os<<obj.get_str();      
}
#define HOME_WORK

void main()
{
    setlocale(LC_ALL,"");
    //String str1;
    //str1.print();

#ifdef HOME_WORK
    String str1 = "Hello";
    cout << str1 << endl;
    String str2 = "World";
    cout << str2 << endl;
    String str3 = str1 + str2;
    cout << str3 << endl;
#endif // HOME_WORK    
}