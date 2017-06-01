/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Control.cpp
 * Author: andre
 * 
 * Created on May 22, 2016, 4:23 PM
 */

#include <iostream>
#include <string>
#include <cstdio>
#include "Control.hpp"

using namespace std;

ostream& operator<<(ostream& os, const StrangeObject& st){
   os<<"{";
   for (int i = 0; i < 2 ; ++i) {
      os<<"[";
      for (int j = 0; j < 2; ++j) {
         os<<st.dataSet[i][j];
         if(j+1!=2){
            os<<" ";
         }
      }
      os<<"]";
      if(i+1!=2){
         os<<",";
      }
   }
   os<<"}";
   return os;
}

Control::Control(string progName)
   {
   this->progName = progName;
   }

Control::~Control()
   {
   vector<StrangeObject *>::iterator scam = dataArray.begin();
   while(scam != dataArray.end())
      {
      cout << "Cleaning dataArray. " << (*scam)->howManyInstances() << " instances left." <<endl;
      delete (*scam);
      (*scam) = NULL;
      scam++;
      }
   
   dataArray.clear();
   }

void Control::start()
   {
   StrangeObject * buffer;
   string decorator = "________________________________________________________________________________";
   char uniqueId[12];
   
   cout << decorator << endl;
   cout << "Starting\n";
   cout << decorator << endl;
   cout << endl;
   cout << "Creating objects...";
   
   for(int count = 0; count < REFERENCE; count++)
      {
      sprintf(uniqueId, "%i", count);
      buffer = new StrangeObject("StrangeObj " + string(uniqueId), count, count*2, count*3, count*4);
      dataArray.push_back(buffer);
      cout << "Created: " <<*buffer<< endl;
      }
   
   buffer = dataArray.at(REFERENCE / 2);
   
   cout << decorator << endl;
   cout << endl;
   cout << "Comparing all objects against " + buffer->toString() << endl;
   
      for(int count = 0; count < dataArray.size(); count++)
      {
          if(buffer < dataArray[count])
          {
          cout << "\t" << buffer->toString() << " is less than " << (dataArray[count]->toString()) << endl;
          }
          else{
          cout << "\t" << buffer->toString() << " is greater than " << (dataArray[count]->toString()) << endl;
          };
      }

   cout << decorator << endl;
   cout << endl;
   cout << "Modifying objects...";

   buffer = new StrangeObject("Strange Ref", 2.0f, 2.0f, 2.0f, 2.0f);
   cout << "Ref: " << buffer->toString() << endl;
   
   for(int count = dataArray.size() - 1 ; count >= 0; --count)
      {
      (*dataArray[count]) = ((*dataArray[count]) + (*buffer));
      cout << "Modified: " << dataArray[count]->toString() << endl;
   }
   cout << decorator << endl;
   cout << endl;
   delete buffer;
 }


