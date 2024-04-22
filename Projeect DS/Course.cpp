
#include "Course.h"
#include "iostream"
#include <string>
#include <vector>
#include <iomanip>


using namespace std;
typedef DoublyLinkedList<Student> Doubly;


Course::Course(int numberOfCredit, string courseCode, string courseTitle, int capacity) {
    setCourseCode(courseCode);
    setCourseTitle(courseTitle);
    setNumberOfCredits(numberOfCredit);
    setCapacity(capacity);
    registeredStudents = map<string, string>();

}


Course::Course(string s) {
    vector<string> valuesList = split(s);

    //default values in case the format of string didn't meet the minimum length
    if (valuesList.size() < 4) {
        courseCode = "";
        courseTitle = "";
        numberOfCredits = 0;
        capacity = 0;
        registeredStudents = map<string, string>();
    } else {
        // Assign values to attributes following the format Code, Title, Number of credits, and Capacity
        courseCode = valuesList[0];
        numberOfCredits = stoi(valuesList[valuesList.size() - 2]);
        capacity = stoi(valuesList[valuesList.size() - 1]);
        courseTitle = "";
        for (int i = 1; i < valuesList.size() - 2; i++) {
            courseTitle = courseTitle + valuesList[i] + " ";
        }
        registeredStudents = map<string, string>();

    }
}



Course::Course(const Course &course) {
    *this = course;
}


Course::~Course() {
}


bool Course::registerStudent(const string &studentId, const string &studentFullName) {
    registeredStudents[studentId] = studentFullName;
    return true;// true if insertion was successful (student was not already in the course)
}


bool Course::dropStudent(const string &id) {
    auto it = registeredStudents.find(id);

    if (it != registeredStudents.end()) {
        registeredStudents.erase(it);
        return true;
    }

    return false;
}


void Course::setCourseCode(string &courseCode) {
    if (courseCode == "") {
        cerr << "the course code is invalid.";
        // Optionally, throw an exception or handle the error in an appropriate way.
        return;
    } else {
        this->courseCode = courseCode; // set the course code to the course code provided.
    }
}


void Course::setCourseTitle(string &courseTitle) {

    if (courseTitle == "") {
        cerr << "the course title is invalid.";//test and exit function if the course title provided is an empty string.
        return;
    } else {
        this->courseTitle = courseTitle;  // set the course title to the course title provided.
    }
}

void Course::setNumberOfCredits(int numberOfCredits) {
    if(numberOfCredits < 0)
        this->numberOfCredits = numberOfCredits;  // set the number of credits of the course  to the number of credits provided.

}


void Course::setCapacity(int capacity) {

    if (capacity < 0) {
        cerr << "the capacity is invalid.";// test and exit function if the capacity provided is negative.
        return;
    } else {
        this->capacity = capacity; // set the capacity of the course to the capacity provided.
    }
}


string Course::getCourseCode() const {
    return courseCode;
}


string Course::getCourseTitle() const {
    return courseTitle;
}


int Course::getNumberOfCredits() const {
    return numberOfCredits;
}


int Course::getCapacity() const {
    return capacity;
}


int Course::getNumberOfEnrolled() const {
    return registeredStudents.size();
}


ostream &Course::displayTabular(ostream &out) const {

    out << left <<
        setw(15) << courseCode <<
        setw(35) << courseTitle <<
        setw(15) << fixed << setprecision(1) << numberOfCredits <<
        setw(15) << fixed << setprecision(1) << registeredStudents.size() <<
        setw(15) << fixed << setprecision(1) << capacity <<
        endl;

    return out;
}


void Course::displayRegisteredStudents() {
    // Display course code and title
    cout << getCourseCode() << " - " << getCourseTitle() << endl;

    // Iterator for the map of registered students
    map<string, string>::iterator itr;

    // Check if there are no registered students
    if (registeredStudents.size() == 0) {
        cout << "No student is registered yet in this course." << endl;
    } else {
        // Loop through the registered students and display their information
        for (itr = registeredStudents.begin(); itr != registeredStudents.end(); ++itr)
            cout << itr->first << ' ' << itr->second << endl;
    }

    // Add some extra newlines for better formatting
    cout << endl << endl << endl;
}


bool Course::operator==(const Course &other) {
    return courseCode == other.courseCode;
}


ostream &operator<<(ostream &out, const Course &course) {
    return course.displayTabular(out);
}


Course &Course::operator=(const Course &other) {
    // Check for self-assignment
    if (this == &other)
        return *this;

    // Copy attributes from 'other' to the current object
    courseCode = other.courseCode;
    courseTitle = other.courseTitle;
    capacity = other.capacity;
    numberOfCredits = other.numberOfCredits;
    registeredStudents = other.registeredStudents;

    return *this;
}


istream &operator>>(istream &in, Course &course) {
    string courseCode, courseTitle;
    unsigned capacity, numberOfCredits;

    // Prompt user for input
    cout << "Adding Course:" << endl << endl <<
         "Enter the course code: ";
    in >> courseCode;
    cout << "Enter the course name: ";
    in >> courseTitle;
    cout << "Enter the course credit value";
    in >> numberOfCredits;
    cout << "Enter the maximum capacity of the course";
    in >> capacity;

    // Set the attributes of the Course object
    course.setCourseCode(courseCode);
    course.setCapacity(capacity);
    course.setCourseTitle(courseTitle);
    course.setNumberOfCredits(numberOfCredits);

    return in;
}


string toUpperCase(const string &input) {
    string result = input;

    // Convert all lowercase letters to uppercase
    for (size_t i = 0; i < result.length(); ++i) {
        if (result[i] >= 'a' && result[i] <= 'z') {
            // If the character is a lowercase letter, convert it to uppercase.
            result[i] = result[i] - 'a' + 'A';
        }
    }
    return result;
}


vector<string> split(const string &s) {
    vector<string> splitting;
    string temp = ""; // Temporary string for building substrings

    // building substring character by character and splitting whenever there is a space
    for (int i = 0; i < s.length(); i++) {
        if (s.at(i) == ' ' && !temp.empty()) {
            splitting.push_back(temp);
            temp = "";
        } else {
            temp = temp + s.at(i);
        }
    }

    // in case there was only one element
    if (!temp.empty())
        splitting.push_back(temp);

    return splitting;
}