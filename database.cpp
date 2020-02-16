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
            file.close();
        }
        return data;
    }

    else if(!file){
        cout << "File not found" << endl;
        exit(0);
    }
}

std::vector<SLDALE003::StudentRecord> SLDALE003::addStudent(std::string newStudentData, std::vector<StudentRecord> data){

    std::stringstream addNewStudent(newStudentData);
    std::string newInfo;
    std::vector<std::string> newInfoArr;
    SLDALE003::StudentRecord newStudent = {"", "", "", ""};
    std::string newResults;

    while(getline(addNewStudent, newInfo, ' ')){ //getline - line from stream into string
        newInfoArr.push_back(newInfo);
    }

    for(int i=0; i<newInfoArr.size();i++) {

        switch (i) {
            case 0:
                newStudent.Name = newInfoArr[i];
                break;
            case 1:
                newStudent.Surname = newInfoArr[i];
                break;
            case 2:
                newStudent.StudentNumber = newInfoArr[i];
                break;

            default:
                if (i == newInfoArr.size() - 1) {
                    newResults += newInfoArr[i];
                } else {
                    newResults += newInfoArr[i] + " ";
                }
        }
    }
    newStudent.ClassRecord = newResults;

    bool found = 0;
    for(int i = 0; i < data.size(); i++){
        SLDALE003::StudentRecord instance = data[i];
        if((instance.StudentNumber).compare(newStudent.StudentNumber)==0){
            found = 1;
            data[i]=newStudent;
        }
//        else{
//            continue;
//        }
    }

    if(found){
        cout << "Data for existing student " << newStudent.StudentNumber <<" has been updated.\n\n";
        return data;
    }

    else{
        data.push_back(newStudent);
        cout << "New student added.\n\n";
        return data;
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

void SLDALE003::saveData(std::string fileName, std::vector<StudentRecord> data){
    std::ofstream write;
    write.open(fileName);
    for(int i = 0; i < data.size(); i++){
        SLDALE003::StudentRecord instance = data[i];
        write << instance.Name << " " << instance.Surname << " " << instance.StudentNumber << " " << instance.ClassRecord << "\n";
    }
    write.close();
    cout << "The database has been saved!\n\n";
}

void SLDALE003::displayData(std::string studentNumber, std::vector<StudentRecord> data){
    int found = 0;
    for(int i=0; i<data.size(); i++){
        SLDALE003::StudentRecord instance = data[i];
        if(instance.StudentNumber.compare(studentNumber)==0){
            found = 1;
            cout << studentNumber << ":\n" << instance.Name << " " << instance.Surname << " "
                 << instance.StudentNumber << " " << instance.ClassRecord << "\n\n";
        }
    }

    if(!found){
        cout << "The student could not be found in the database.\n\n";
    }
}
