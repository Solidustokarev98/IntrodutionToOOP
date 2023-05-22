#include <iostream>
using namespace std;

class String;
String operator+(const String& left, const String& right);
class String
{
    /*Строка в языке 'С' - это массив элементов типа 'char',
    последний элемент которого всегда содержит ASCII - символ с кодом 0 -'\0'
    является признаком конца строки */
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
    explicit String(int size = 80)
    {
        this->size = size;
        this->str = new char[size] {};
        cout << "Constructor:\t" << this << endl;
    }
    String(const char str[])
    {
        this->size = strlen(str)+1;         //Поскольку класс хранит размер в байтах, +1 нужен для хранения NULL-terminator'a
        this->str = new char[size] {};      //Выделяем память под строку
        for (int i = 0; i < size; i++)this->str[i] = str[i];
        cout << "Constructor:\t" << this << endl;
    }
    String(const String& other)
    {
        this->size = other.size;
        this->str = new char[size] {};
        for (int i = 0; i < size; i++)this->str[i] = other.str[i];
        cout << "CopyConstructor:\t" << this << endl;
    }
    String(String&& other)
    {
        this->size = other.size;
        this->str = other.str;
        other.size = 0;
        other.str = nullptr;
        cout << "MoveConstructor:\t" << this << endl;
    }
    ~String()
    {
        delete[] this->str;
        cout<<"Destructor:\t" << this << endl;
    }

    //      Operators:
    String& operator+=(const String& other)
    {
        return *this = *this + other;
    }
    String& operator=(const String& other)
    {
        delete[] str;
        this->size = other.size;
        this->str = new char[size] {};
        for (int i = 0; i < size; i++)
        {
            this->str[i] = other.str[i];
        }
        cout << "CopyAssignment:\t" << this << endl;
        return *this;
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
    String cat(left.get_size() + right.get_size() - 1);
    for (int i = 0; i < left.get_size(); i++)
        //l-value = r-value;
        cat[i] = left[i];
    //cat.get_str()[i] = left.get_str()[i];
    for (int i = 0; i < right.get_size(); i++)
        cat[left.get_size() - 1 + i] = right[i];
    //cat.get_str()[left.get_size() - 1 + i] = right.get_str()[i];
    return cat;
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
}