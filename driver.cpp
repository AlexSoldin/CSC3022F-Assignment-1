#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

#include "studentRecord.h"

using namespace std;

void clear(void);

void clear(void) {
    system("clear");
}

int main(int argc, char * argv[]) {

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
            case '1':
                cout << "Option 1\n\n";
                break;
            case '2':
                cout << "Option 2\n\n";
                break;
            case '3':
                cout << "Option 3\n\n";
                break;
            case '4':
                cout << "Option 4\n\n";
                break;
            case '5':
                cout << "Option 5\n\n";
                break;
            case 'q':
                break;

            default :
                cout << "Ivalid option. Please try again.\n\n";
        }

    }
    clear();
    return 0;
}