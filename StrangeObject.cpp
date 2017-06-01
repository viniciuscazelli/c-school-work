/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StrangeObject.cpp
 * Author: andre
 * 
 * Created on May 22, 2016, 5:12 PM
 */

#include <sstream>
#include <iomanip>
#include "StrangeObject.hpp"
#include "Info.hpp"

using namespace std;

int StrangeObject::globalCount = 0;
int StrangeObject::globalPool = 0;

StrangeObject::StrangeObject() {
    globalCount++;
    this->localID = globalPool++;
    this->text = Info::getInstitution();
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            this->dataSet[i][j] = 0.0f;
        }
    }
}

StrangeObject::StrangeObject(string text, float e00, float e01, float e10, float e11) {
    globalCount++;
    this->localID = globalPool++;
    this->text = text;
    this->dataSet[0][0] = e00;
    this->dataSet[0][1] = e01;
    this->dataSet[1][0] = e10;
    this->dataSet[1][1] = e11;
}

StrangeObject::StrangeObject(const StrangeObject& value){


    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            this->dataSet[i][j] = value.dataSet[i][j];
        }
    }
    this->globalCount   = value.globalCount;
    this->localID       = value.localID;
    this->globalPool    = value.globalPool;
    this->text          = value.text;

}

StrangeObject::StrangeObject(StrangeObject&& other){

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            this->dataSet[i][j] = (move(other.dataSet[i][j]));;
        }
    }
    this->globalCount= (move(other.globalCount));
    this->localID= (move(other.localID));
    this->globalPool= (move(other.globalPool));
    this->text= (move(other.text));

}

StrangeObject::~StrangeObject() {
    globalCount--;
    this->localID = 0;
    this->text = "";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            this->dataSet[i][j] = 0.0f;
        }
    }

}

int StrangeObject::howManyInstances() {
    return (globalCount);
}

int StrangeObject::getLocalID() {
    return (localID);
}

string StrangeObject::toString() {
    stringstream buffer;
    buffer << "Strange Object #" << this->localID << ". (" << globalCount << " instance(s)).";
    buffer << " { " << setprecision(3) << fixed << dataSet[0][0] << ", " << dataSet[0][1] << ", " << dataSet[1][0] << ", " << dataSet[1][1] << " } ";
    buffer << "[" << text << "]";
    return (buffer.str());
}

StrangeObject StrangeObject::operator=(const StrangeObject value) {
    this->text = value.text;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            this->dataSet[i][j] = value.dataSet[i][j];
        }
    }
    return (*this);
}

StrangeObject& StrangeObject::operator+=(const StrangeObject& value) {
    this->text += "; " + value.text;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            this->dataSet[i][j] += value.dataSet[i][j];
        }
    }
    return (*this);
}

StrangeObject StrangeObject::operator+(StrangeObject value) {
    StrangeObject buffer;
    buffer.text = this->text + "; " + value.text;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            buffer.dataSet[i][j] = this->dataSet[i][j] += value.dataSet[i][j];
        }
    }
    return (buffer);
}

StrangeObject& StrangeObject::operator-=(const StrangeObject& value) {
    this->text += "; " + value.text;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            this->dataSet[i][j] -= value.dataSet[i][j];
        }
    }
    return (*this);
}


StrangeObject StrangeObject::operator-(StrangeObject value) {
    StrangeObject buffer;
    buffer.text = this->text + "; " + value.text;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            buffer.dataSet[i][j] = (value.dataSet[i][j])-1;
        }
    }
    return (*this+buffer);
}
StrangeObject& StrangeObject::operator*=(const StrangeObject& value) {

    (*this) = (*this)*value;

    return (*this);
}
StrangeObject StrangeObject::operator*(StrangeObject value) {
    StrangeObject buffer;
    buffer.text = this->text + "; " + value.text;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            buffer.dataSet[i][j] = 0;
            for (int k = 0; k < 2; ++k) {
                buffer.dataSet[i][j] += (this->dataSet[i][k] * value.dataSet[k][j]);
            }
        }
    }
    return (buffer);
}

bool StrangeObject::operator==(StrangeObject value) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if(this->dataSet[i][j] != value.dataSet[i][j]){
                return false;
            }
        }
    }
    return true;
}

bool StrangeObject::operator!=(StrangeObject value) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if(this->dataSet[i][j] != value.dataSet[i][j]){
                return true;
            }
        }
    }
    return false;
}

bool StrangeObject::operator<(const StrangeObject& value) {
    return (this->localID < value.localID);
}
bool StrangeObject::operator>(const StrangeObject& value) {
    return (this->localID > value.localID);
}
bool StrangeObject::operator<=(const StrangeObject& value) {
    return (this->localID <= value.localID);
}
bool StrangeObject::operator>=(const StrangeObject& value) {
    return (this->localID >= value.localID);
}

void StrangeObject::setIdentityMatrix(){

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if(i=j){
                this->dataSet[i][j] = 1;
            }else{
                this->dataSet[i][j] = 0;
            }
        }
    }

}