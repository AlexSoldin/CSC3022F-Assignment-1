# CSC3022F-Assignment-1

- driver.cpp is the main driver of the assignment. This program handles the input/output and contains the main event loop which handles all method calls for loading the database data, adding a new student (update existing student), reading the database, saving to the database, viewing the information of a specific student and calculating the average of a specific student

- studentRecord.h defines a struct specific to the data required for each individual student. Each student has a first name, second name, student number and multiple grades. This is often referred to as a vector of these structs are used when loading/reading/writing to the text file

- database.h contains all the method calls that are held in database.cpp

- database.cpp holds all the methods contained in database.h. These methods include:
	- readFile reads the contents of the text file and creates a vector of StudentRecord structs
	- addStudent is responsible for adding a new student to the database or updating existing student data
	- readData is tasked with displaying the data contained in the vector of StudentRecord structs
	- saveData writes the database data to the text file
	- displayData shows the data of a specific student given a student number
	- gradeStudent displays an average of the grades of a specific student given a student number

- studentData.txt contains an example 'database' which has been populated with some random student information. This works sufficiently well when testing the functionality of the program but should you choose to use your own text file, please change the fileName variable shown in driver.cpp

- Makefile compiles and links the necessary files into the database.run executable. Some commands include:
	- make: compiles files
	- make run: runs executable
	- make clean: removes executables
