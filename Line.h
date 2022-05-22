#ifndef __Line__
#define __Line__

#include <ostream>

class Line {
public:
    Line();
    Line(const char*);
    Line(const Line&);
    Line(const Line&&);
    ~Line();
public:
    Line& operator =(const Line&);
    Line& operator =(const Line&&);
    friend Line operator +(const Line& ob1, const Line& ob2) {
        Line tmp = ob1;

        tmp.size += ob2.size;

        for(int i = ob1.size, j = 0; i < tmp.size; ++i, ++j) {
            tmp.ch[i] = ob2.ch[j];
        }

        tmp.ch[tmp.size] = '\0';

        return tmp;
    }
    friend std::ostream& operator<<(std::ostream&, Line&);
    char operator[](int i);
public:
    void push_back(const char*);
    void pop_back();
    void insert(int, const char*);
    int at(int i);
    int find(char);
private:
    unsigned size;
    char* ch;
};

#endif  //Line.cpp