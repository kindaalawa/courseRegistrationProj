/**

    @file Course.cpp
    @brief Implementation of the Course class and its member functions.

    This file contains the declaration of the Course class, which represents an academic course
    and provides methods for managing course data and student registration.

    date 9 Nov 2023

    The purpose of this class is to encapsulate the properties and behaviors of an academic course.
    It allows users to manage course information, register and drop students, and display course details.

    Public Member Functions:
        1. Course(int, string , string , int)
        2. Course(string )
        3. Course(const )
        4. ~Course()
        5. registerStudent(const Student &) : bool
        6. dropStudent(string ): bool
        7. setCourseCode(string &): void
        8. setCourseTitle(string & ): void
        9. setNumberOfCredits(int ): void
        10. setCapacity(int ): void
        11. getCourseCode() const: string
        12. getCourseTitle() const: string
        13. getNumberOfCredits() const: int
        14. getCapacity() const: int
        15. getNumberOfEnrolled() const: int
        16. displayTabular(ostream &) const: ostream &
        17. displayRegisteredStudents(): void
        18. operator==(const Course &): bool
        19. operator<<(ostream &, const Course &):  friend ostream &
        20. operator=(const Course &): course&
        21. operator>>(istream &, Course &): friend istream &
        22. split(const string &): static vector<string>
*/

#ifndef COURSE_H
#define COURSE_H

// Forward declaration of the Student class to resolve the circular dependency.
#include "Student.h"
#include "LListWithDummyNode.h"

#include <string>
#include <map>

using namespace std;

class Student; // So we can solve the forward declaration error
class Course {
public:

    // Constructors


    /**
 * @brief Constructor for the Course class.
 *
 * This constructor initializes a Course object with specified attributes.
 *
 * @param numberOfCredit The number of credits for the Course.
 * @param courseCode The code of the Course.
 * @param courseTitle The title of the Course.
 * @param capacity The maximum capacity of the Course.
 *
 * @pre The provided parameters meet any necessary constraints for initialization.
 *
 * @post The Course object is initialized with the specified attributes.
 *
 * @details The constructor sets the Course code, title, number of credits, and capacity using
 * the provided parameters. It also initializes the registeredStudents map as an empty map.
 */
    Course(int numberOfCredits = 3, string courseCode = "Null", string courseTitle = "Null",  int capacity = 0);

    /**
 * @brief Copy constructor for the Course class.
 *
 * This constructor creates a new Course object as a copy of the provided Course object.
 *
 * @param course The Course object to be copied.
 *
 * @pre The provided Course object is properly initialized.
 *
 * @post A new Course object is created as a copy of the provided Course object.
 *
 * @details The copy constructor initializes a new Course object using the values from the
 * provided Course object.
 */
    Course(const Course &);

    /**
  * @brief Constructor for the Course class with a string parameter.
  *
  * This constructor initializes a Course object using information provided in a formatted string.
  *
  * @param s The string containing information to initialize the Course object.
  *
  * @pre The provided string follows the expected format with at least four values.
  *
  * @post The Course object is initialized based on the information in the provided string.
  */
    Course(string);

    /**
  * @brief Destructor for the Course class.
  *
  * This destructor is responsible for cleaning up resources associated with the Course object.
  *
  * @pre The Course object is being destroyed.
  *
  * @post Any resources associated with the Course object are released.
  */
    ~Course();

    // Getter methods


    /**
 * @brief Get the code of the Course.
 *
 * This method returns the code of the Course.
 *
 * @return string The code of the Course.
 *
 * @pre The Course object is properly initialized.
 *
 * @post None.
 *
 * @details The function returns the value of the 'courseCode' data member,
 * which represents the code of the course.
 */
    string getCourseCode() const;

    /**
  * @brief Get the title of the Course.
  *
  * This method returns the title of the Course.
  *
  * @return string The title of the Course.
  *
  * @pre The Course object is properly initialized.
  *
  * @post None.
  *
  * @details The function returns the value of the 'courseTitle' data member,
  * which represents the title of the course.
  */
    string getCourseTitle() const;

    /**
   * @brief Get the number of credits for the Course.
   *
   * This method returns the number of credits assigned to the Course.
   *
   * @return int The number of credits for the Course.
   *
   * @pre The Course object is properly initialized.
   *
   * @post None.
   *
   * @details The function returns the value of the 'numberOfCredits' data member,
   * which represents the number of credits assigned to the course.
   */
    int getNumberOfCredits() const;

    /**
 * @brief Get the capacity of the Course.
 *
 * This method returns the maximum capacity of the Course, i.e., the maximum number of students
 * that can be enrolled in the Course.
 *
 * @return int The maximum capacity of the Course.
 *
 * @pre The Course object is properly initialized.
 *
 * @post None.
 *
 * @details The function returns the value of the 'capacity' data member, which represents
 * the maximum number of students that can be enrolled in the course.
 */
    int getCapacity() const;

    /**
  * @brief Get the number of enrolled students in the Course.
  *
  * This method returns the number of students currently enrolled in the Course.
  *
  * @return int The number of enrolled students.
  *
  * @pre The Course object is properly initialized.
  *
  * @post None.
  *
  * @details The function retrieves the size of the registeredStudents vector,
  * which represents the number of students currently enrolled in the course.
  */
    int getNumberOfEnrolled() const;

    // Setter methods


    /**
 * @brief Set the code of the Course.
 *
 * This method sets the code of the Course to the provided value.
 *
 * @param courseCode The code to set for the Course.
 *
 * @pre The Course object is properly initialized.
 *
 * @post The code of the Course is updated with the provided value.
 *
 * @details The function checks if the provided course code is an empty string.
 * If it is, an error message is printed to the standard error stream (cerr), and the function returns
 * without making any changes. Otherwise, the course code of the Course is set to the provided value.
 */
    void setCourseCode(string &);

    /**
 * @brief Set the title of the Course.
 *
 * This method sets the title of the Course to the provided value.
 *
 * @param courseTitle The title to set for the Course.
 *
 * @pre The Course object is properly initialized.
 *
 * @post The title of the Course is updated with the provided value.
 *
 * @details The function checks if the provided course title is an empty string.
 * If it is, an error message is printed to the standard error stream (cerr), and the function returns
 * without making any changes. Otherwise, the course title of the Course is set to the provided value.
 */
    void setCourseTitle(string &);

    /**
 * @brief Set the Number of credits of the Course.
 *
 * This method sets the  Number of credits of the Course to the provided value.
 *
 * @param numberOfCredits The title to set for the Course.
 *
 * @pre The Course object is properly initialized.
 *
 * @post The numberOfCredits of the Course is updated with the provided value.
 *
 * @details The function checks if the provided number of credits is a negative value.
 * If it is, the default value will remain the same.
 */
    void setNumberOfCredits(int );

    /**
  * @brief Set the capacity of the Course.
  *
  * This method sets the maximum capacity of the Course to the provided value.
  *
  * @param capacity The maximum capacity to set for the Course.
  *
  * @pre The Course object is properly initialized.
  *
  * @post The capacity of the Course is updated with the provided value.
  *
  * @details The function checks if the provided capacity is non-negative. If it is negative,
  * an error message is printed to the standard error stream (cerr), and the function returns without
  * making any changes. Otherwise, the capacity of the Course is set to the provided value.
  */
    void setCapacity(int);


    // Registration methods

    /**
 * @brief Register a student for the Course.
 *
 * This method adds a student with the provided ID and full name to the Course's list of registered students.
 *
 * @param studentId The ID of the student to register.
 * @param studentFullName The full name of the student to register.
 * @return bool True if the student was successfully registered, false otherwise.
 *
 * @pre The Course object is properly initialized.
 *
 * @post If the student with the provided ID does not already exist in the Course,
 * they are added to the registeredStudents map, and true is returned.
 * If the student already exists, false is returned, indicating that the registration failed.
 *
 * @details The function adds a student to the Course by assigning the provided full name to the provided ID.
 * If a student with the same ID already exists, the registration fails, and false is returned.
 */
    bool registerStudent(const string &, const string &);

    /**
  * @brief Drop a student from the Course.
  *
  * This method removes a student with the provided ID from the Course's list of registered students.
  *
  * @param id The ID of the student to drop.
  * @return bool True if the student was successfully dropped, false otherwise.
  *
  * @pre The Course object is properly initialized.
  *
  * @post If the student with the provided ID exists in the Course, they are removed, and true is returned.
  * Otherwise, false is returned, indicating the student was not found.
  *
  * @details The function searches for a student with the provided ID in the registeredStudents map.
  * If found, the student is removed from the Course, and true is returned. If not found, false is returned.
  */
    bool dropStudent(const string & );

    // Display methods

    /**
 * @brief Display the registered students for the Course.
 *
 * This method displays the course code, course title, and the list of registered students for the Course object.
 *
 * @pre The Course object is properly initialized.
 *
 * @post The registered students for the Course are displayed on the console.
 *
 * @details The method checks if there are any registered students for the course. If none, a message is displayed.
 * Otherwise, it iterates through the registered students and prints their information.
 */
    void displayRegisteredStudents();

    /**
 * @brief Display the Course object in tabular format.
 *
 * This function displays the Course object in a tabular format, including course code, course title,
 * number of credits, number of registered students, and maximum capacity.
 *
 * @param out The output stream to which the Course object is to be displayed.
 * @return ostream& A reference to the output stream after display.
 *
 * @pre The Course object is properly initialized.
 *
 * @post The Course object is displayed in tabular format on the output stream.
 *
 * @details The function uses the output stream manipulators to format the output in a tabular structure.
 * It includes columns for course code, course title, number of credits, number of registered students, and capacity.
 */
    ostream & displayTabular(ostream &) const;

    // Assignment and equality operators

    /**
 * @brief Overloaded assignment operator for the Course class.
 *
 * This operator assigns the attributes of another Course object to the current object.
 *
 * @param other The Course object to be copied.
 * @return Course& A reference to the current Course object after assignment.
 *
 * @pre The Course object 'other' is properly initialized.
 *
 * @post The attributes of the current Course object are updated with the values from 'other'.
 *
 * @details The function checks for self-assignment and, if not the same object, copies the attributes
 * of the 'other' Course object to the current object. The function returns a reference to the current object
 * to allow chaining of assignments.
 */
    Course & operator=(const Course &);

    /**
   * @brief Overloaded operator for the Course class.
   *
   * This operator compares to object courses with their course ID.
   *
   * @param other The Course object to be copied.
   * @return Course& A reference to the current Course object after assignment.
   *
   * @pre The Course object 'other' is properly initialized.
   *
   * @post If the courses ID match they will return true.
   *
   */
    bool operator==(const Course &);

private:
    string courseCode;
    string courseTitle;
    int numberOfCredits;
    int capacity;
    // https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/
    map<string,string> registeredStudents; //To store id + name documentation used

};

/**
 * @brief Overloaded output stream insertion operator for the Course class.
 *
 * This operator allows a Course object to be displayed using the output stream.
 *
 * @param out The output stream to which the Course object is to be inserted.
 * @param course The Course object to be displayed.
 * @return ostream& A reference to the output stream after insertion.
 *
 * @pre The Course object 'course' is properly initialized.
 *
 * @post The Course object 'course' is displayed in a tabular format on the output stream.
 *
 * @details The function calls the `displayTabular` member function of the Course class
 * to display the Course object in a tabular format on the output stream. The function
 * returns a reference to the output stream to allow chaining of insertions.
 */
ostream & operator<<(ostream & out, const Course & course);

/**
 * @brief Overloaded input stream extraction operator for the Course class.
 *
 * This operator allows user input to initialize a Course object by extracting relevant information
 * such as course code, course title, number of credits, and maximum capacity from the input stream.
 *
 * @param in The input stream from which data is extracted.
 * @param course The Course object to be initialized with user input.
 * @return istream& The reference to the input stream after extraction.
 *
 * @pre The input stream 'in' is in a valid state, The Course object 'course' is properly initialized.
 *
 * @post The Course object 'course' is updated with information from user input.
 *       The input stream 'in' is in a valid state after extraction.
 *
 * @details The function prompts the user to enter information for a Course object, including course code,
 * course title, number of credits, and maximum capacity. The entered data is then used to set the corresponding
 * attributes of the Course object. The function returns the input stream to allow chaining.
 */
istream & operator>>(istream & in, Course & course);

/**
 * @brief Splits a string into substrings based on space (' ') delimiter.
 *
 * This function takes a string as input and splits it into substrings based on space (' ') as the delimiter.
 * It builds substrings character by character and adds them to a vector.
 *
 * @pre The input string 's' is not empty.
 *
 * @post The returned vector contains substrings obtained by splitting the input string based on space (' ') delimiter.
 */
vector<string> split(const string &s);

/**
 * @brief Converts a given string to uppercase.
 *
 * This function takes a string as input and converts all lowercase letters in the string to uppercase.
 *
 * @return string The resulting string with all lowercase letters converted to uppercase.
 *
 * @pre The input string 'input' is not empty.
 *
 * @post The returned string is the result of converting all lowercase letters in the input string to uppercase.
 *
 * @details The function iterates through each character in the input string, checking if it is a lowercase letter.
 * If a lowercase letter is found, it is converted to uppercase using ASCII values.
 */
string toUpperCase(const string &input);


#endif