#include"String.h"

    int String::get_size()const
    {
        return size;
    }
    const char* String::get_str()const
    {
        return str;
    }
    char* String::get_str()
    {
        return str;
    }
    //          Constructors:
    explicit String::String(int size = 80)
    {
        this->size = size;
        this->str = new char[size] {};
        cout << "Constructor:\t" << this << endl;
    }
    String::String(const char str[])
    {
        this->size = strlen(str)+1;         //Поскольку класс хранит размер в байтах, +1 нужен для хранения NULL-terminator'a
        this->str = new char[size] {};      //Выделяем память под строку
        for (int i = 0; i < size; i++)this->str[i] = str[i];
        cout << "Constructor:\t" << this << endl;
    }
    String::String(const String& other)
    {
        this->size = other.size;
        this->str = new char[size] {};
        for (int i = 0; i < size; i++)this->str[i] = other.str[i];
        cout << "CopyConstructor:\t" << this << endl;
    }
    String::String(String&& other)
    {
        //Shallow copy:
        this->size = other.size;
        this->str = other.str;
        other.size = 0;
        other.str = nullptr;
        cout << "MoveConstructor:\t" << this << endl;
    }
    String::~String()
    {
        delete[] this->str;
        cout << "Destructor:\t" << this << endl;
    }

    //      Operators:
    String& String::operator+=(const String& other)
    {
        return *this = *this + other;
    }
    String& String::operator=(const String& other)
    {
        if (this == &other)return *this;
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
    const char& String::operator[](int i)const
    {
        return str[i];
    }
    char& String::operator[](int i)
    {
        return str[i];
    }
    //      Methods:
    void String::print()const
    {
        cout << "Size: " << size << endl;
        cout << "Str: " << str << endl;
    }
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
    return os << obj.get_str();
}