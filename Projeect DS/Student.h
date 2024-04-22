/**

    @file Student.cpp
    @brief Implementation of the Student class and its member functions.

    This file contains the implementation of the Student class, which represents a student with information
    such as ID, name, GPA, and registered courses. It provides methods for managing student data and course registration.

    date 10 Nov 2023

    The purpose of this class is to encapsulate the properties and behaviors of a student. It allows users to manage
    student information, register and drop courses, and display student details.

    Public Member Functions:
        1. Student(double, string, string, string): Student
        2. Student(string): Student
        3. Student(const Student &): Student
        4. ~Student(): ~Student
        5. setSudentId(string): void
        6. setFirstName(string): void
        7. setLastName(string): void
        8. setGpa(double): void
        9. setNumberOfCredits(int): void
        10. addCourse(const string): bool
        11. dropCourse(const string): bool
        12. getStudentId() const: string
        13. getNumberOfCredits() const: int
        14. getFirstName() const: string
        15. getLastName() const: string
        16. getAcademicStatus() const: string
        17. getFullName() const: string
        18. getGpa() const: double
        19. getRegisteredCourse(): vector<string> &
        20. displayInfo() const: void
        21. displayTabular(ostream &) const: ostream &
        22. displayRegisteredCourse() const: void
        23. operator==(const Student &) const: bool
        24. operator<<(ostream &, Student &): friend ostream &
        25. operator=(const Student &): Student &
        26. operator>>(istream &, Student &): friend istream &
        27. split(const string &): static vector<string>
*/

#ifndef DSPROJ_STUDENT_H
#define DSPROJ_STUDENT_H


#include <string>
#include <iostream>
#include <vector>

using namespace std;

#include "Course.h"
#include "DoublyLinkedList.h"



class Course; // So we can solve the forward declaration error
class Student {
public:
    // Constructors and Destructor
    /**
 * @brief Constructor for the Student class.
 *
 * @details This constructor initializes a Student object with the provided GPA, student ID, first name, and last name.
 * It sets the number of credits to 0 and initializes the registered courses vector.
 *
 * @param gpa The GPA of the student.
 * @param studentID The unique identifier for the student.
 * @param firstName The first name of the student.
 * @param lastName The last name of the student.
 *
 * @pre The GPA is within the valid range [0, 4].
 *      The studentID follows the format 'A' followed by 7 digits.
 *      The first and last names are valid non-empty strings.
 *
 * @post The Student object is initialized with the specified attributes.
 *       The number of credits is set to 0, and the registered courses vector is empty.
 */
    Student(double gpa = 0, string studentID = "NuLL", string firstName = "Null", string lastName = "Null");

    /**
 * @brief Constructor for the Student class.
 *
 * @details This constructor initializes a Student object using a formatted string containing student information.
 * The string is split into components, and the corresponding attributes are set.
 * If the string does not contain enough information, default values are set.
 *
 * @param s A formatted string containing student information.
 *
 * @pre The input string follows the format "studentID_firstName_lastName_GPA".
 *
 * @post The Student object is initialized with the specified attributes from the input string.
 *       If the input string is invalid, default values are set.
 */
    Student(string);

    /**
 * @brief Copy constructor for the Student class.
 *
 * @details This constructor creates a new Student object by copying the attributes of an existing Student object.
 *
 * @param student The Student object to be copied.
 *
 * @pre The input Student object is valid.
 *
 * @post The new Student object is created with attributes identical to the input Student object.
 */
    Student(const Student &);

    /**
 * @brief Destructor for the Student class.
 *
 * @details This destructor is responsible for cleaning up resources associated with a Student object.
 * It is automatically called when a Student object goes out of scope or is explicitly deleted.
 *
 * @pre None.
 *
 * @post The Student object is destroyed, and its associated memory is deallocated.
 */
    ~Student();

    // Getter methods

    /**
 * @brief Get the student's ID.
 *
 * This method returns the unique identifier (ID) of the student.
 *
 * @return string The student's ID.
 *
 * @pre The Student object is properly initialized.
 *
 * @post None.
 *
 * @details The function retrieves and returns the value of the 'studentID' data member,
 * which represents the unique identifier of the student.
 */
    string getStudentId() const;

    /**
  * @brief Get the full name of the student.
  *
  * This method returns the full name of the student, which is a combination of the first name and last name.
  *
  * @return string The full name of the student.
  *
  * @pre The Student object is properly initialized.
  *
  * @post None.
  *
  * @details The function concatenates the values of the 'firstName' and 'lastName' data members,
  * separated by a comma and space, and returns the result.
  */
    string getFullName() const;

    /**
 * @brief Get the student's first name.
 *
 * This method returns the first name of the student.
 *
 * @return string The student's first name.
 *
 * @pre The Student object is properly initialized.
 *
 * @post None.
 *
 * @details The function retrieves and returns the value of the 'firstName' data member,
 * which represents the first name of the student.
 */
    string getFirstName() const;

    /**
  * @brief Get the student's last name.
  *
  * This method returns the last name of the student.
  *
  * @return string The student's last name.
  *
  * @pre The Student object is properly initialized.
  *
  * @post None.
  *
  * @details The function retrieves and returns the value of the 'lastName' data member,
  * which represents the last name of the student.
  */
    string getLastName() const;

    /**
 * @brief Get the academic status of the student.
 *
 * This method returns the academic status of the student, which is either "Regular" or "Probation"
 * based on the student's GPA.
 *
 * @return string The academic status ("Regular" or "Probation").
 *
 * @pre The Student object is properly initialized.
 *
 * @post None.
 *
 * @details The function checks the GPA of the student and returns "Regular" if the GPA is 2 or higher,
 * otherwise, it returns "Probation".
 */
    string getAcademicStatus() const;

    /**
  * @brief Get the number of credits the student is enrolled in.
  *
  * This method returns the total number of credits the student is currently enrolled in.
  *
  * @return int The number of credits.
  *
  * @pre The Student object is properly initialized.
  *
  * @post None.
  *
  * @details The function retrieves and returns the value of the 'numberOfcredits' data member,
  * which represents the total number of credits the student is enrolled in.
  */
    int getNumberOfcredits() const;

    /**
 * @brief Get the GPA of the student.
 *
 * This method returns the Grade Point Average (GPA) of the student.
 *
 * @return double The GPA of the student.
 *
 * @pre The Student object is properly initialized.
 *
 * @post None.
 *
 * @details The function retrieves and returns the value of the 'gpa' data member,
 * which represents the Grade Point Average of the student.
 */
    double getGpa() const;

    /**
 * @brief Get a reference to the vector of registered courses.
 *
 * This method returns a reference to the vector containing the course codes of the courses
 * the student is registered in.
 *
 * @return vector<string>& A reference to the vector of registered course codes.
 *
 * @pre The Student object is properly initialized.
 *
 * @post None.
 *
 * @details The function returns a reference to the 'courseRegistred' data member,
 * which is a vector containing the course codes of the courses the student is registered in.
 */
    vector<string> &getRegisteredCourse();

    // Setter methods


    /**
 * @brief Setter for the student ID of the Student class.
 *
 * @param id The student ID to set.
 *
 * @pre The provided ID should be an 8-character string starting with 'A' followed by 7 digits.
 *
 * @post If the provided ID meets the specified format, the student ID is set; otherwise, it is set to "NULL".
 *
 * @details This function sets the student ID of the Student object. It performs validation to ensure
 * that the provided ID follows the specified format. If the format is valid, the student ID is set;
 * otherwise, it is set to "NULL".
 */
    void setSudentId(string);

    /**
 * @brief Setter for the first name of the Student class.
 *
 * @param name The first name to set.
 *
 * @pre None.
 *
 * @post The first name of the student is set to the provided value.
 *
 * @details This function sets the first name of the Student object to the provided value.
 */
    void setFirstName(string);

    /**
  * @brief Setter for the last name of the Student class.
  *
  * @param name The last name to set.
  *
  * @pre None.
  *
  * @post The last name of the student is set to the provided value.
  *
  * @details This function sets the last name of the Student object to the provided value.
  */
    void setLastName(string);

    /**
  * @brief Setter for the GPA of the Student class.
  *
  * @param gpa The GPA to set.
  *
  * @pre None.
  *
  * @post The GPA of the student is set to the provided value. If the provided GPA is
  * outside the valid range (0 to 4), the GPA is set to a default value of 2.
  *
  * @details This function sets the GPA of the Student object to the provided value,
  * ensuring it falls within the valid range of 0 to 4.
  */
    void setGpa(double);

    /**
 * @brief Setter for the number of credits of the Student class.
 *
 * @param number The number of credits to set.
 *
 * @pre None.
 *
 * @post The number of credits of the student is set to the provided value.
 *
 * @details This function sets the number of credits of the Student object to the provided value.
 */
    void setNumberOfCredits(int);

    // Course-related methods


    /**
  * @brief Adds a course to the registered courses of the Student.
  *
  * @param courseID The ID of the course to be added.
  *
  * @pre None.
  *
  * @post The specified course is added to the list of registered courses for the student.
  *
  * @details This function adds the provided course ID to the list of courses registered by the student.
  */
    bool addCourse(const string);   // string course code

    /**
  * @brief Drops a course from the registered courses of the Student.
  *
  * @param courseCode The code of the course to be dropped.
  *
  * @pre The student has at least one registered course.
  *
  * @post The specified course is removed from the list of registered courses for the student.
  *
  * @details This function removes the course with the provided code from the list of courses registered by the student.
  * If the course is not found, an error message is displayed.
  *
  * @return True if the course is successfully dropped, false otherwise.
  */
    bool dropCourse(const string);  // course code

    /**
 * @brief Display the list of courses registered by the student.
 *
 * This method outputs the list of courses registered by the student to the standard output.
 * It includes the student's ID, full name, and a list of registered courses.
 *
 * @return void
 *
 * @pre The Student object is properly initialized.
 *
 * @post The list of registered courses is displayed on the standard output.
 */
    void displayRegisteredCourse() const;

    // Display methods


    /**
 * @brief Display information about the student.
 *
 * This method outputs information about the student to the standard output.
 * The information includes the student's ID, full name, major, and GPA.
 *
 * @pre The Student object is properly initialized.
 *
 * @post None.
 */
    void displayInfo() const;

    /**
 * @brief Display student information in a tabular format.
 *
 * This method outputs student information in a tabular format to the provided output stream.
 * The information includes the student's ID, full name, GPA, and academic status.
 *
 * @param out The output stream where the information will be displayed.
 *
 * @return ostream& A reference to the output stream after displaying the information.
 *
 * @pre The Student object is properly initialized.
 *
 * @post The student information is displayed in a tabular format on the output stream.
 */
    ostream &displayTabular(ostream &) const;

    // Overloaded operators


    /**
  * @brief Compare two Student objects for equality.
  *
  * This method compares two Student objects based on their student IDs.
  *
  * @param student The Student object to compare with.
  *
  * @return bool True if the student IDs are equal, false otherwise.
  *
  * @pre Both Student objects are properly initialized.
  *
  * @post None.
  *
  * @details The function compares the student IDs of the current object and the provided object.
  * If the student IDs are equal, the function returns true; otherwise, it returns false.
  */
    bool operator==(const Student &) const;

    /**
 * @brief Assign the values of another Student object to this object.
 *
 * This method assigns the values of another Student object to the current object.
 *
 * @param student The Student object to assign values from.
 *
 * @return Student& A reference to the current Student object.
 *
 * @pre Both Student objects are properly initialized.
 *
 * @post The current object's attributes are updated with the values of the provided object.
 *
 * @details The function checks if the current object is not the same as the provided object,
 * and if not, it assigns the values of the provided object's attributes to the current object.
 * It then returns a reference to the current object.
 */
    Student &operator=(const Student &student);

private:
    string studentID;
    string firstName;
    string lastName;
    int numberOfcredits;
    double gpa;
    vector<string> courseRegistred;

};

// Overloaded stream operators

/**
 * @brief Overloaded << operator to display a Student object in a formatted way.
 *
 * This function overloads the << operator to allow displaying a Student object
 * in a formatted way using the displayTabular method.
 *
 * @param out The output stream to write the formatted output.
 * @param student The Student object to be displayed.
 *
 * @return ostream& The output stream after displaying the Student object.
 *
 * @pre The Student object is properly initialized.
 *
 * @post The formatted representation of the Student object is written to the output stream.
 *
 * @details The function calls the displayTabular method of the provided Student object,
 * and the formatted output is written to the output stream. The output stream is then returned.
 */
ostream & operator<<(ostream &, Student &);

/**
 * @brief Overloaded >> operator to input values for a Student object.
 *
 * This function overloads the >> operator to allow inputting values for a Student object.
 *
 * @param in The input stream to read values from.
 * @param student The Student object to store the input values.
 *
 * @return istream& The input stream after reading values for the Student object.
 *
 * @pre The input stream is ready for reading.
 *
 * @post The Student object is updated with the input values.
 *
 * @details The function prompts the user to enter the student ID, first name, last name, and GPA.
 * It then sets these values in the provided Student object using its member functions.
 */
istream & operator>>(istream &, Student &);

#endif //DSPROJ_STUDENT_H
