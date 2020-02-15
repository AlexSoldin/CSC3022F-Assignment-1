//
// Created by Alex Soldin on 2020/02/15.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

#ifndef INC_1_RECORD_H
#define INC_1_RECORD_H


namespace SLDALE003{
    struct StudentRecord{
        std::string Name;
        std::string Surname;
        std::string StudentNumer;
        std::string ClassRecord;
    };
}

#endif //INC_1_RECORD_H
