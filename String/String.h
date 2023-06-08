#pragma once
#include"stdafx.h"

class String;
std::ostream& operator<<(std::ostream& os, const String& obj);
String operator+(const String& left, const String& right);
class String
{
    /*������ � ����� '�' - ��� ������ ��������� ���� 'char',
    ��������� ������� �������� ������ �������� ASCII - ������ � ����� 0 -'\0'
    �������� ��������� ����� ������ */
    int size;       //������ ������
    char* str;     //����� ������ � ������������ ������
public:
    int get_size()const;
    const char* get_str()const;
    char* get_str();
    //          Constructors:
    explicit String(int size = 80);
    String(const char str[]);
    String(const String& other);
    String(String&& other);
    ~String();
    //      Operators:
    String& operator+=(const String& other);
    String& operator=(const String& other);
    const char& operator[](int i)const;
    char& operator[](int i);
    //      Methods:
    void print()const;
};