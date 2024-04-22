
#include "Student.h"
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;


Student::Student(double gpa, string studentID, string firstName, string lastName) {
    setSudentId(studentID);
    setFirstName(firstName);
    setLastName(lastName);
    numberOfcredits = 0;
    courseRegistred = vector<string>();
    setGpa(gpa);
}


Student::Student(string s) {
    // Split the input string into a vector of values
    vector<string> valuesList = split(s);

    // Check if the correct number of values is present in the input
    if (valuesList.size() != 4) {
        // If not, set default values and print a warning
        firstName = "NULL";
        lastName = "NULL";
        studentID = "NULL";
        courseRegistred = vector<string>();
        gpa = 0;
        cerr << "A student object was created with default values please check if any info is missing \n"
                "or if the first or last name is composed of multiple words make sure to connect them with \n"
                "a '_' or '-'." << endl;
        numberOfcredits = 0;
    } else {
        // If the correct number of values is present, initialize the student object
        studentID = valuesList[0];
        firstName = valuesList[1];
        lastName = valuesList[2];
        gpa = stod(valuesList[3]);
        numberOfcredits = 0;
        courseRegistred = vector<string>();
    }
}



Student::Student(const Student &student) {
    *this = student;
}


Student::~Student() {
}


void Student::setSudentId(string id) {
    // Check if the provided ID has a length of 8
    if (id.length() == 8) {
        // Check if the first character is 'A'
        if (id[0] == 'A') {
            bool isValid = true;

            // Check if the remaining characters are digits
            for (int i = 1; i < 8; i++) {
                if (!isdigit(id[i])) {
                    // If any character is not a digit, set the ID to "NULL" and exit the loop
                    isValid = false;
                    studentID = "NULL";
                    break;
                }
            }

            // If all characters are digits, set the student ID
            if (isValid) {
                studentID = id;
            }
        }
    }
    // If the provided ID does not meet the criteria, the student ID remains unchanged
}


void Student::setFirstName(string name) {
    firstName = name;
}


void Student::setLastName(string name) {
    lastName = name;
}


void Student::setGpa(double gpa) {
    // Check if the provided GPA is outside the valid range (0 to 4)
    if (gpa > 4 || gpa < 0) {
        // If outside the range, set the GPA to a default value (e.g., 2)
        this->gpa = 2;
    } else {
        // If within the valid range, set the GPA to the provided value
        this->gpa = gpa;
    }
}


void Student::setNumberOfCredits(int number){
    numberOfcredits = number;
}


bool Student::addCourse(const string  courseID) {

    courseRegistred.push_back(courseID);
    return true;
}


// Remove a course from the list of registered courses for the student
bool Student::dropCourse(const string courseCode) {
    // Check if the student has any courses registered
    if (courseRegistred.size() == 0) {
        cerr << "Student doesn't have any course registered" << endl;
        return false;
    }

    // Iterate through the registered courses to find the specified course code
    for (int i = 0; i < courseRegistred.size(); i++) {
        // Check if the current course matches the specified course code
        if (courseRegistred[i] == courseCode) {
            // Remove the course from the list
            courseRegistred.erase(courseRegistred.begin() + i);
            return true; // Course successfully dropped
        }
    }

    // If the specified course code was not found in the registered courses
    cerr << "Course not found" << endl;
    return false; // Course not found, no changes made
}



string Student::getStudentId() const {
    return studentID;
}


int Student::getNumberOfcredits() const{
    return numberOfcredits;
}


string Student::getFirstName() const {
    return firstName;
}


string Student::getLastName() const {
    return lastName;
}


string Student::getAcademicStatus() const {
    return (gpa>=2 ? "Regular" : "Probation");
}


string Student::getFullName() const {
    return firstName + ", " + lastName;
}


double Student::getGpa() const {
    return gpa;
}

vector<string> & Student::getRegisteredCourse() {
    return courseRegistred;
}


void Student::displayInfo() const {
    // Output student information, including ID, name, major, and GPA
    cout << "Student: " << endl <<
         "\tID: " << studentID << endl <<
         "\tName: " << firstName << " " << lastName << endl <<
         "\tMajor: " << "COMPUTER SCIENCE" << endl << // Assuming a fixed major for simplicity
         "\tGPA: " << gpa << endl;
}



ostream & Student::displayTabular(ostream & out) const {

    out << left <<
        setw(17) << studentID <<
        setw(23) << getFullName() <<
        setw(6) << fixed << setprecision(1) << gpa <<
        setw(20) << getAcademicStatus() << endl;

    return out;
}


void Student::displayRegisteredCourse() const {
    // Output student information, including ID and name
    cout << "Student " << studentID << " - " << firstName << " " << lastName << "\nCourses:\n\n";

    // Iterate through the registered courses and display each course code
    for (int i = 0; i < courseRegistred.size(); i++) {
        cout << "-  " << courseRegistred[i] << endl;
    }
}



bool Student::operator==(const Student &student) const {
    return studentID == student.getStudentId();
}


Student &Student::operator=(const Student &student) {
    // Check for self-assignment
    if (this != &student) {
        // Copy values from the right-hand side student to the left-hand side object (*this)
        studentID = student.studentID;
        firstName = student.firstName;
        lastName = student.lastName;
        gpa = student.gpa;

        numberOfcredits = student.numberOfcredits; // Corrected member name
        courseRegistred = student.courseRegistred;
    }
    // Return a reference to the modified object
    return *this;
}


ostream &operator<<(ostream &out, Student &student) {
    // here we calculate the size of the formatted string dynamically
    return student.displayTabular(out);
}


istream &operator>>(istream &in, Student &student) {
    string firstName, lastName, studentID;
    double gpa;

    cout << "Create a student:" << endl << endl;
    cout << "Enter the student ID: ";
    cin >> studentID;
    cout << "Enter the student first name: ";
    cin >> firstName;
    cout << "Enter the student last name: ";
    cin >> lastName;
    cout << "Enter the student GPA: ";
    cin >> gpa;

    student.setFirstName(firstName);
    student.setLastName(lastName);
    student.setGpa(gpa);
    student.setSudentId(studentID);

    return in;

}

