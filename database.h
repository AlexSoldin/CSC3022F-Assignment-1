//
// Created by Alex Soldin on 2020/02/15.
//
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

#ifndef _DATABASE_H
#define _DATABASE_H

#include "studentRecord.h"


namespace SLDALE003{
    std::vector<StudentRecord> readFile(std::string fileName, std::vector<StudentRecord> data);
    std::vector<StudentRecord> addStudent(std::string details, std::vector<StudentRecord> data);
    void readData(std::vector<StudentRecord> record);
    void saveData(std::string fileName, std::vector<StudentRecord> data);
    void displayData(std::string studentNumber, std::vector<StudentRecord> data);
    void gradeStudent(std::string studentNumber, std::vector<StudentRecord> data);
}

#endif
