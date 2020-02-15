#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {

    std::string in = "Start";

    while(in.compare("q")!=0){
        cout << "Choose an option from the following:"
                "\n1: Add student"
                "\n2: Read database"
                "\n3: Save database"
                "\n4: Display given student data"
                "\n5: Grade student"
                "\nq: Quit\n\n";

        cin >> in;
        cout << "\n";
    }

    std::cout << "Hello, World!" << std::endl;
}