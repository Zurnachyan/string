#include <iostream>
#include <cstring>
#include "Line.h"

Line::Line() : ch(nullptr), size{} {}

Line::Line(const char* st) {
    size = strlen(st);
    ch = new char[size];
    for(int i = 0; i < size; ++i) {
        ch[i] = st[i];
    }
}

Line::Line(const Line& rhs) {
    size = rhs.size;
    ch = new char[size];
    for(int i = 0; i < size; ++i) {
        ch[i] = rhs.ch[i];
    }
}

Line::Line(const Line&& rhs) {
    size = rhs.size;
    ch = new char[size];
    for(int i = 0; i < size; ++i) {
        ch[i] = rhs.ch[i];
    }
}

Line::~Line() {
    delete ch;
}

Line& Line::operator =(const Line& rhs) {
    size = rhs.size;
    delete ch;
    ch = new char[size];

    for(int i = 0; i < size; ++i) {
        ch[i] = rhs.ch[i];
    }

    return *this;
}
    
Line& Line::operator =(const Line&& rhs) {
    size = rhs.size;
    delete ch;
    ch = new char[size];
    
    for(int i = 0; i < size; ++i) {
        ch[i] = rhs.ch[i];
    }

    return *this;
}

char Line::operator [](int i) {
    return ch[i];
}

std::ostream& operator <<(std::ostream& os, Line& rhs) {
    for(int i = 0; i < rhs.size; ++i) {
        os << rhs.ch[i];
    }
    return os;
}

void Line::push_back(const char* ob) {
    char* tmp = new char[size + strlen(ob)];
    for(int i = 0; i < size; ++i) {
        tmp[i] = ch[i];
    }

    size += strlen(ob);

    delete ch;
    ch = new char[size];

    for(int i = 0; i < size; ++i) {
        ch[i] = tmp[i];
    }
    delete tmp;

    for(int i = size - strlen(ob), j = 0; i < size; ++i, ++j) {
        ch[i] = ob[j];
    }

    ch[size] = '\0';
}

void Line::pop_back() {
    ch[size - 1] = '\0';
}
    
void Line::insert(int ind, const char* c) {
    char* tmp = new char[size + strlen(c)];
    for(int i = 0; i <= ind; ++i) {
        tmp[i] = ch[i];
    }

    int s = strlen(c);
    for(int i = ind + 1, j = 0; j < s; ++i, ++j) {
        tmp[i] = c[j];
    }

    for(int i = ind + 1, j = s + ind + 1; i <= size; ++i, ++j) {
        tmp[j] = ch[i];
    }

    delete ch;
    size += s;
    ch = new char[size];
    
    for(int i = 0; i < size; ++i) {
        ch[i] = tmp[i];
    }

    ch[size] = '\0';

    delete tmp;
}

int Line::at(int i) {
    if(i > size) {
        return -1;
    }
    return i;
}

int Line::find(char c) {
    for(int i = 0; i < size; ++i) {
        if(ch[i] == c) {
            return i;
        }
    }
    return -1;
}


int main() {
    Line ob;
    Line obj = "asda";

    obj.insert(2, "cv");

    std::cout << obj;
}