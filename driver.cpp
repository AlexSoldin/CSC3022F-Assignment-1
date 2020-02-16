#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

#include "studentRecord.h"
#include "database.h"
#include "database.cpp"

using namespace std;

void clear(void);

void clear(void) {
    system("clear");
}

int main(int argc, char * argv[]) {

    std::string fileName = "studentData.txt";

    std::vector<SLDALE003::StudentRecord> record;
    record = readFile(fileName, record);

    std::string in = "Start";

    while(in.compare("q")!=0) {
        in = "Start";
        cout << "Choose an option from the following:"
                "\n1: Add student"
                "\n2: Read database"
                "\n3: Save database"
                "\n4: Display given student data"
                "\n5: Grade student"
                "\nq: Quit\n\n";

        cin >> in;
        cout << "\n";

        switch (in[0]) {
            case '1': {
                std::string newStudentData;
                cout << "Enter the details of a new student, ending with a full stop: ";
                std::getline(cin, newStudentData, '.');
                record = addStudent(newStudentData, record);
                break;
            }
            case '2': {
                readData(record);
                break;
            }
            case '3': {
                saveData(fileName, record);
                break;
            }
            case '4': {
                cout << "Option 4\n\n";
                break;
            }
            case '5': {
                cout << "Option 5\n\n";
                break;
            }
            case 'q': {
                break;
            }
            default: {
                cout << "Invalid option. Please try again.\n\n";
            }
        }

    }
    clear();
    return 0;
}