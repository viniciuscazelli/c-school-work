/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StrangeObject.hpp
 * Author: andre
 *
 * Created on May 22, 2016, 5:12 PM
 */

#ifndef STRANGEOBJECT_HPP
#define STRANGEOBJECT_HPP

#include <string>

using namespace std;

class StrangeObject {
private:
    static int   globalCount;
    static int   globalPool;
    int          localID;
    double       dataSet[2][2];
    string       text;




public:
    StrangeObject();
    StrangeObject(string, float, float, float, float);
    StrangeObject(const StrangeObject& value);
    StrangeObject(StrangeObject&& other);
    virtual ~StrangeObject();

    int howManyInstances();
    int getLocalID();
    string toString();
    StrangeObject operator=(StrangeObject);
    StrangeObject operator+(StrangeObject);
    StrangeObject& operator+=(const StrangeObject &);
    StrangeObject& operator-=(const StrangeObject &);
    StrangeObject& operator*=(const StrangeObject &);
    StrangeObject operator-(StrangeObject);
    StrangeObject operator*(StrangeObject);
    bool operator==(StrangeObject);
    bool operator!=(StrangeObject);

    bool operator <(const StrangeObject&);
    bool operator >(const StrangeObject&);
    bool operator <=(const StrangeObject&);
    bool operator >=(const StrangeObject&);

    void setIdentityMatrix();

    friend ostream& operator<<(ostream& os, const StrangeObject& st);
};

#endif /* STRANGEOBJECT_HPP */

