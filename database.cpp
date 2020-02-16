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

            while(getline(file, lineIn)){

                std::stringstream s(lineIn); //string object, whose content is copied called a stream
                std::string temp;
                std::vector<std::string> temps;
                SLDALE003::StudentRecord instance = {"", "", "", ""};
                std::string results;

                while(getline(s, temp, ' ')){ //getline - line from stream into string
                    temps.push_back(temp);
                }

                for(int i=0; i<temps.size();i++) {

                    switch (i) {
                        case 0:
                            instance.Name = temps[i];
                            break;
                        case 1:
                            instance.Surname = temps[i];
                            break;
                        case 2:
                            instance.StudentNumber = temps[i];
                            break;

                        default:
                            if (i == temps.size() - 1) {
                                results += temps[i];
                            } else {
                                results += temps[i] + " ";
                            }
                    }
                }
                    instance.ClassRecord = results;
                    data.push_back(instance);
            }
        }
        return data;

    }

    else if(!file){
        cout << "File not found" << endl;
        exit(0);
    }
}


void SLDALE003::readData(std::vector<StudentRecord> data){
    cout << "The following data is stored in the database:\n";

    for(int i = 0; i < data.size(); i++){
        SLDALE003::StudentRecord current = data[i];
        cout << current.Name << " " << current.Surname << " " << current.StudentNumber << " " << current.ClassRecord << "\n";
    }

    cout << "\n";
}
