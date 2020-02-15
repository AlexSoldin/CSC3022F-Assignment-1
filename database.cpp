//
// Created by Alex Soldin on 2020/02/15.
//
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

#include "database.h"
#include "studentRecord.h"

using namespace std;

std::vector<SLDALE003::StudentRecord> SLDALE003::readFile(std::string fileName, std::vector<StudentRecord> data){
    std::ifstream file(fileName.c_str()); //returns a const char * pointer to the string
    std::string lineIn;

    if(file){
        while(!file.eof()){

            

        }
    }
}

void SLDALE003::readData(std::vector<StudentRecord> data){
    cout << "The following data is stored in the database:\n";

    for(int i = 0; i < data.size(); i++){
        SLDALE003::StudentRecord current = data[i];
        cout << current.Name << " " << current.Surname << " " << current.StudentNumer << " " << current.ClassRecord << "\n";
    }

    cout << "\n";
}
