#include <iostream>
#include <limits>
#include <fstream>
#include <vector>
#include "Course.h"
#include "Student.h"
#include "DoublyLinkedList.h"
#include "LListWithDummyNode.h"


using namespace std;


//----- user interaction functions ------
/**
 * @brief Display the menu of options and prompt the user to choose an option.
 *
 * This function displays a menu of registration system options, prompts the user to enter a choice,
 * and validates the input. It ensures that the entered choice is a valid integer between 1 and 10.
 *
 * @param out The output stream to display the menu.
 * @param in The input stream to take the user's choice.
 *
 * @return An integer representing the user's choice (between 1 and 10).
 *
 * @pre The output stream (out) and input stream (in) must be open and valid.
 *
 * @post The user's choice is validated, and the selected option is returned.
 *       The input stream is cleared, and any invalid input is ignored.
 *
 * @details The function prints a menu with 10 options related to the registration system.
 *          It then prompts the user to enter a choice and validates the input. If the input is not a valid integer
 *          or falls outside the range of 1 to 10, the user is informed of the error, and they are prompted again
 *          until a valid choice is entered. The chosen option is then returned.
 */
int displayMenuAndTakeOption(ostream &out, istream &in);
//----------------------------------------------------------------------------------------------------------------------

//----- file functions -----
/**
 * @brief Read and parse content from a file, returning an array of strings.
 *
 * This function reads the contents of a file specified by the 'filename' parameter, validates the input,
 * and stores the file contents in an array of strings. The first line of the file is expected to contain
 * a valid integer that represents the number of lines to read.
 *
 * If the file cannot be opened, an error message is displayed. If the first line of the file is not a valid integer,
 * an error message is shown as well. Any other exceptions are caught and reported as general errors.
 *
 * @param filename The name of the file to be read.
 * @return An array of strings containing the parsed content from the file, or nullptr on failure.
 *
 * @note The returned array is dynamically allocated, and it is the caller's responsibility to free the memory
 *       when it is no longer needed to prevent memory leaks.
 */
vector<string> readFileAndParseContent(string, const string &);

//----------------------------------------------------------------------------------------------------------------------


//----- Options -----

/**
 * @brief Display the list of non-registered students.
 *
 * This function takes a constant reference to a linked list of non-registered students and displays their information,
 * including student ID, name, GPA, and academic status. The information is formatted in a tabular fashion.
 *
 * @param List A constant reference to the linked list of non-registered students.
 *
 * @pre The 'List' parameter is a valid linked list containing instances of the 'Student' class.
 *
 * @post The information about non-registered students is displayed on the console.
 *       The console pauses, waiting for the user to press enter before proceeding.
 *
 * @details The function uses the overloaded '<<' operator to display the contents of the linked list.
 *          The formatting includes columns for student ID, name, GPA, and academic status.
 *          The function utilizes the '_getch()' function to wait for user input before returning.
 */
void option1(const LListWithDummyNode<Student> &);

/**
 * @brief Display the list of offered courses.
 *
 * This function takes a constant reference to a doubly linked list of offered courses and displays their information,
 * including course code, title, number of credits, number of enrolled students, and capacity. The information is formatted
 * in a tabular fashion.
 *
 * @param List A constant reference to the doubly linked list of offered courses.
 *
 * @pre The 'List' parameter is a valid doubly linked list containing instances of the 'Course' class.
 *
 * @post The information about offered courses is displayed on the console.
 *       The console pauses, waiting for the user to press enter before proceeding.
 *
 * @details The function uses the overloaded '<<' operator to display the contents of the doubly linked list.
 *          The formatting includes columns for course code, title, number of credits, number of enrolled students, and capacity.
 *          The function utilizes the '_getch()' function to wait for user input before returning.
 */
void option2(const DoublyLinkedList<Course> &);

/**
 * @brief Display the list of registered students with their registered courses.
 *
 * This function takes a constant reference to a linked list of registered students and displays
 * their information along with the courses they are registered for. If there are no registered students,
 * an appropriate message is displayed.
 *
 * @param registeredList A constant reference to the linked list of registered students.
 *
 * @pre The 'registeredList' parameter is a valid linked list containing instances of the 'Student' class.
 *
 * @post The information about registered students and their courses is displayed on the console.
 *       If no students are registered, an appropriate message is displayed.
 *       The console pauses, waiting for the user to press enter before proceeding.
 *
 * @details The function iterates through the registered students in the linked list and displays their registered courses.
 *          If there are no registered students, an appropriate error message is displayed.
 *          The function utilizes the '_getch()' function to wait for user input before returning.
 */
void option3(const LListWithDummyNode<Student> &);


/**
 * @brief Display the list of offered courses with the registered students.
 *
 * This function takes a constant reference to a doubly linked list of courses and displays
 * information about each course, including the students registered for that course.
 *
 * @param List A constant reference to the doubly linked list of courses.
 *
 * @pre The 'List' parameter is a valid doubly linked list containing instances of the 'Course' class.
 *
 * @post The information about each offered course and the students registered for those courses is displayed on the console.
 *       The console pauses, waiting for the user to press enter before proceeding.
 *
 * @details The function iterates through the courses in the doubly linked list and calls the 'displayRegisteredStudents'
 *          function for each course to show the list of students registered for that course.
 *          The function utilizes the '_getch()' function to wait for user input before returning.
 */
void option4(const DoublyLinkedList<Course> &);

/**
 * @brief Display the registered courses for a student.
 *
 * This function prompts the user to enter a student ID, validates the format of the ID,
 * and then searches for the student in both the registered and unregistered lists.
 * If the student is found, it displays the courses they are registered for, or indicates
 * that the student is unregistered if applicable.
 *
 * @param registered A constant reference to the list of registered students.
 * @param unregistered A constant reference to the list of unregistered students.
 *
 * @pre The 'registered' and 'unregistered' parameters are valid linked lists of students.
 *
 * @post If the entered student ID is valid and corresponds to a registered or unregistered student,
 *       the console displays the courses the student is registered for, or a message indicating
 *       that the student is unregistered. The console pauses, waiting for the user to press enter before proceeding.
 *
 * @details The function uses a do-while loop to repeatedly prompt the user for a student ID until a valid format is entered.
 *          It then converts the entered ID to uppercase using the 'toUpperCase' function.
 *          The function searches for the student in both the registered and unregistered lists and displays
 *          the registered courses if the student is found. If the student is not found, an appropriate error message is displayed.
 */
void option5(const LListWithDummyNode<Student> &, const LListWithDummyNode<Student> &);

/**
 * @brief Display the list of students registered in a course.
 *
 * This function prompts the user to enter a course code, converts it to uppercase, and searches for the course
 * in the provided list of courses. If the course is found, it displays the list of students registered in that course.
 * If the course is not found, an error message is displayed.
 *
 * @param courseList A constant reference to the list of courses.
 *
 * @pre The 'courseList' parameter is a valid doubly linked list of courses.
 *
 * @post If the entered course code is valid and corresponds to a course in the list,
 *       the console displays the list of students registered in that course.
 *       If the course is not found, an error message is displayed.
 *       The console pauses, waiting for the user to press enter before proceeding.
 *
 * @details The function uses the 'toUpperCase' function to convert the entered course code to uppercase.
 *          It then searches for the course in the 'courseList' using the 'searchAndRetreivePtr' function.
 *          If the course is found, it calls the 'displayRegisteredStudents' function to display the list of registered students.
 *          If the course is not found, an appropriate error message is displayed.
 *          The function utilizes the '_getch()' function to wait for user input before returning.
 */
void option6(const DoublyLinkedList<Course> &);

/**
 * @brief Display detailed information about a registered student.
 *
 * This function prompts the user to enter a student ID, validates its format, converts it to uppercase, and
 * searches for the student in the provided list of registered students. If the student is found, it displays
 * detailed information about that student. If the student is not found, an error message is displayed.
 *
 * @param registeredList A constant reference to the list of registered students.
 *
 * @pre The 'registeredList' parameter is a valid linked list with a dummy node containing registered students.
 *
 * @post If the entered student ID is valid and corresponds to a registered student in the list,
 *       the console displays detailed information about that student.
 *       If the student is not found, an error message is displayed.
 *       The console pauses, waiting for the user to press enter before proceeding.
 *
 * @details The function uses a do-while loop to prompt the user for a valid student ID format.
 *          It then converts the entered student ID to uppercase and searches for the student in the 'registeredList'
 *          using the 'searchAndRetreivePtr' function. If the student is found, it calls the 'displayInfo' function
 *          to display detailed information about the student. If the student is not found, an appropriate error message is displayed.
 *          The function utilizes the '_getch()' function to wait for user input before returning.
 */
void option7(const LListWithDummyNode<Student> &);

/**
 * @brief Register courses for an unregistered student and move them to the registered list.
 *
 * This function guides the user through the process of registering courses for a specified unregistered student.
 * The user is prompted to enter the student ID and the course codes they want to register. The function validates
 * the input and checks various conditions, such as course availability, student credit limits, and probation status,
 * before registering the student for the selected courses. If successful, the student is moved from the unregistered
 * list to the registered list, and their course registration details are updated.
 *
 * @param unregistered A reference to the list of unregistered students.
 * @param registered A reference to the list of registered students.
 * @param courseList A reference to the list of available courses.
 *
 * @pre The 'unregistered', 'registered', and 'courseList' parameters are valid linked lists.
 *
 * @post The selected unregistered student is registered for the specified courses.
 *       The student is moved from the unregistered list to the registered list.
 *       The course enrollment information is updated.
 *       The console displays success messages or appropriate error messages.
 *       The console pauses, waiting for the user to press enter before proceeding.
 *
 * @details The function uses a do-while loop to prompt the user for a valid student ID format.
 *          It then converts the entered student ID to uppercase and searches for the student in the 'unregistered'
 *          list using the 'searchAndRetreivePtr' function. If the student is found, the function proceeds to
 *          prompt the user for course codes to register. Various conditions are checked, including course availability,
 *          student credit limits, and probation status, before registering the student for the selected courses.
 *          The function also handles user input to register additional courses and updates the student and course lists accordingly.
 *          Upon successful registration, the student is moved to the 'registered' list, and their information is updated.
 *          The function utilizes the '_getch()' function to wait for user input before returning.
 */
void option8(LListWithDummyNode<Student> &, LListWithDummyNode<Student> &, DoublyLinkedList<Course> &);

/**
 * @brief Add or drop courses for a registered student.
 *
 * This function allows the user to add or drop courses for a registered student. The user is prompted to enter the
 * student ID and then chooses between adding or dropping courses. If adding courses, the user enters the course code,
 * and the function validates the input, checking for course availability, capacity, and student credit limits.
 * If dropping courses, the user enters the course code to be dropped, and the function removes the student from
 * the course and updates the student's course list. The function continues to prompt the user for additional courses
 * until the user chooses to stop. If the student has no remaining courses, they are moved back to the unregistered list.
 *
 * @param registeredList A reference to the list of registered students.
 * @param unregistered A reference to the list of unregistered students.
 * @param courseList A reference to the list of available courses.
 *
 * @pre The 'registeredList', 'unregistered', and 'courseList' parameters are valid linked lists.
 *
 * @post The selected registered student's course list is updated based on user choices.
 *       The student may be moved from the registered list to the unregistered list if they drop all their courses.
 *       The console displays success messages or appropriate error messages.
 *       The console pauses, waiting for the user to press enter before proceeding.
 *
 * @details The function uses a do-while loop to prompt the user for a valid student ID format.
 *          It then converts the entered student ID to uppercase and searches for the student in the 'registeredList'
 *          using the 'searchAndRetreivePtr' function. If the student is found, the function proceeds to display the
 *          student's registered courses and prompts the user to add or drop courses. Depending on the user's choice,
 *          the function validates input, checks various conditions, and either registers or drops the selected course.
 *          The function continues to prompt the user for additional courses until the user chooses to stop.
 *          If the student has no remaining courses, they are moved back to the 'unregistered' list.
 *          The function utilizes the '_getch()' function to wait for user input before returning.
 */
void option9(LListWithDummyNode<Student> &, LListWithDummyNode<Student> &, DoublyLinkedList<Course> &);

/**
 * @brief Exit the registration system and display contact information.
 *
 * This function terminates the registration system and displays a thank-you message along with contact information
 * for assistance. The contact details include a phone number and email address. Upon execution, the function prints
 * the message and terminates the program using the 'exit' function.
 *
 * @pre None.
 *
 * @post The registration system is terminated, and the thank-you message with contact information is displayed.
 *       The program exits successfully.
 *
 * @details The function prints a thank-you message for using the registration service and provides contact information
 *          for users who may need assistance. The phone number and email address are included in the message.
 *          The 'exit' function is then called to terminate the program.
 */
void option10();

int main() {

    // stores the raw lines in the vector from the Student.txt file
    vector<string> studentFileContent = readFileAndParseContent("Student",
                                                                "C:\\Users\\johnn\\CLionProjects\\DsProject\\Student.txt");
    // stores the raw lines in the vector from the Couurse.txt file
    vector<string> courseFileContent = readFileAndParseContent("Course",
                                                               "C:\\Users\\johnn\\CLionProjects\\DsProject\\Course.txt");

// creates a LInkedList to store unregistered students.
    LListWithDummyNode<Student> *unregisteredStudents = new LListWithDummyNode<Student>();

// creates a LinkedList to store registered students.
    LListWithDummyNode<Student> *registeredStudents = new LListWithDummyNode<Student>();

// creates a doublyLinkedList to store the courses
    DoublyLinkedList<Course> *courseList = new DoublyLinkedList<Course>();

// takes the raw strings and uses the constructor with string argument to assign the Student attributes then stores
// them in 'unregistered'
    for (int i = 0; i < studentFileContent.size(); i++)
        unregisteredStudents->insertAtBegin(*new Student(studentFileContent[i]));

// takes the raw strings and uses the constructor with string argument to assign the Course attributes then stores
// them in 'courseList'
    for (int i = 0; i < courseFileContent.size(); i++)
        courseList->insertAtBegin(*new Course(courseFileContent[i]));

    cout << "Program Ready to run!!!" << endl << endl << endl;
    cout << "---------------------------------------------Welcome Back Dr Hamid!--------------------------------"
            "-------------" << endl;

    // Main menu loop
    // Preconditions:
    // - The 'displayMenuAndTakeOption' function must be properly implemented to display the menu and take a valid option.
    // - 'unregisteredStudents', 'registeredStudents', and 'courseList' are assumed to be valid pointers to instances of their respective classes.
    // - 'option1' to 'option10' functions must be properly implemented to perform the corresponding actions based on the user's choice.
    //
    // Postconditions:
    // - The user is repeatedly presented with a menu until choosing option 10 to exit.
    // - Each option calls the corresponding function to perform the specified action.
    // - The state of 'unregisteredStudents', 'registeredStudents', and 'courseList' may be modified based on user interactions.
    int option;
    do {
        option = displayMenuAndTakeOption(cout, cin);

        switch (option) {
            case 1:
                option1(*unregisteredStudents);
                break;
            case 2:
                option2(*courseList);
                break;
            case 3:
                option3(*registeredStudents);
                break;
            case 4:
                option4(*courseList);
                break;
            case 5:
                option5(*registeredStudents, *unregisteredStudents);
                break;
            case 6:
                option6(*courseList);
                break;
            case 7:
                option7(*registeredStudents);
                break;
            case 8:
                option8(*unregisteredStudents, *registeredStudents, *courseList);
                break;
            case 9:
                option9(*registeredStudents, *unregisteredStudents, *courseList);
                break;
            case 10:
                option10();
                break;
        }

    } while (option != 10);


    return 0;


}


void option1(const LListWithDummyNode<Student> &List) {
    // prints a formated table column title for students
    printf("%-17s%-23s%-6s%-20s\n\n", "ID", "Name", "Gpa", "Academic Status");
    cout << List << endl;

    cout << "Press enter to proceed  <*__]" << endl;
    cin.ignore();
    cin.get();
}


void option2(const DoublyLinkedList<Course> &List) {
    // prints a formated table column title for courses
    printf("%-15s%-35s%-15s%-15s%-15s\n\n", "Code", "Title", "# Credit", "Enrolled", "Capacity");
    cout << List << endl;
    cout << "Press enter to proceed  <*__]" << endl;
    cin.ignore();
    cin.get();
}


void option3(const LListWithDummyNode<Student> &registeredList) {
    if (registeredList.getSize() == 0) {
        cerr << "No student registered" << endl;
        cout << "Press enter to proceed  <*__]" << endl;
        cin.ignore();
        cin.get();
        return;
    }
    for (int i = 0; i < registeredList.getSize(); i++) {
        registeredList.retrieveAtIndex(i).displayRegisteredCourse();
        cout << endl << endl;
    }
    cout << endl << "Press enter to proceed  <*__]" << endl;
    cin.ignore();
    cin.get();
}

void option4(const DoublyLinkedList<Course> &List) {
    for (int i = 0; i < List.getSize(); i++) {
        List.retrieveAtIndex(i).displayRegisteredStudents();
    }

    cout << "Press enter to proceed  <*__]" << endl;
    cin.ignore();
    cin.get();
}


void option5(const LListWithDummyNode<Student> &registered, const LListWithDummyNode<Student> &unregistered) {
    string studentId;

    do {
        cout << "Enter the student ID: ";
        cin >> studentId;
        if (!(studentId[0] != 'a' || studentId[0] != 'A') && studentId.length() == 8)
            cerr << "Invalid studentId format, please enter a valid ID eg: A2210191." << endl;
    } while (!((studentId[0] != 'a' || studentId[0] != 'A') && studentId.length() == 8));
    cout << endl;
    studentId = toUpperCase(studentId);

    const Student *pointerPtr = registered.searchAndRetreivePtr(Student(0, studentId));
    if (pointerPtr == nullptr) {
        pointerPtr = unregistered.searchAndRetreivePtr(Student(0, studentId));
        if (pointerPtr == nullptr) {
            cerr << "The student you are looking for doesn't exists" << endl;
            cout << endl << endl << endl;
            cout << "Press enter to proceed  <*__]" << endl;
            cin.ignore();
            cin.get();
            return;
        }
        cerr << "The student exists but is unregistered" << endl;
    } else
        pointerPtr->displayRegisteredCourse();;
    cout << endl << endl;
    cout << "Press enter to proceed  <*__]" << endl;
    cin.ignore();
    cin.get();
}


void option6(const DoublyLinkedList<Course> &courseList) {
    string courseId;

    cout << "Enter the course code: ";
    cin >> courseId;
    courseId = toUpperCase(courseId);


    cout << endl;
    // storing in a pointer the address of the object we looking for
    Course *resultCourse = courseList.searchAndRetreivePtr(Course(NULL, courseId));

    if (resultCourse == nullptr)
        cerr << "The course you entered doesn't exists" << endl;
    else
        resultCourse->displayRegisteredStudents();

    cout << "Press enter to proceed  <*__]" << endl;
    cin.ignore();
    cin.get();
}


void option7(const LListWithDummyNode<Student> &registeredList) {
    string studentId;

    //making sure the input is a valid id
    do {
        cout << "Enter the student ID: ";
        cin >> studentId;
        if (!(studentId[0] != 'a' || studentId[0] != 'A') && studentId.length() == 8)
            cerr << "Invalid studentId format, please enter a valid ID eg: A2210191." << endl;
    } while (!((studentId[0] != 'a' || studentId[0] != 'A') && studentId.length() == 8));
    cout << endl;

    // making sure we set all characters to be upercase to successfully find the student that matches the student id
    studentId = toUpperCase(studentId);

    // retreiving a pointer to the object student we are searching for
    Student *resultStudent = registeredList.searchAndRetreivePtr(Student(NULL, studentId));

    if(resultStudent != nullptr)
    // displaying the info
        resultStudent->displayInfo();
    else
        cerr<< "The student ypu are looking for might not be registered yet.";

    cout << endl;

    cout << "Press enter to proceed  <*__]" << endl;
    cin.ignore();
    cin.get();
}


void option8(LListWithDummyNode<Student> &unregistered,
             LListWithDummyNode<Student> &registered,
             DoublyLinkedList<Course> &courseList) {

    string courseId, studentId; // to store the courseid and studentid
    bool validS; // checks if the student id is valid
    bool alreadytaken; // checks if the course has already been registered
    char choice; // takes Y or y and N or n to be able to register multiple courses

// making the user input the studentId and making sure it is in the valid format
    do {
        cout << "Enter the student ID: ";
        cin >> studentId;
        validS = (studentId.length() == 8) && (studentId[0] == 'A' || studentId[0] == 'a');

        if (!validS) {
            cerr << "Invalid studentId format, please enter a valid ID eg: A2210191." << endl;
        }
    } while (!validS);
    cout << endl;

    // making studentId capital so it can successfully search for other course with this id
    studentId = toUpperCase(studentId);

    // creating a pointer to object student such as the id is equals to studentId
    Student *resultStudent = unregistered.searchAndRetreivePtr(Student(NULL, studentId));


    // checking to make sure we result student is pointing at  the object student we looking for
    if (resultStudent == nullptr) {

        // in case we don't find him in the unregistered list we check if the student is already registered
        resultStudent = registered.searchAndRetreivePtr(Student(NULL, studentId));

        // we check if we got what we looking for if we don't we terminate the session in option 8
        if (resultStudent == nullptr)
            cerr << "The student you are looking for doesn't exists!" << endl;
        else
            cerr << "The student you are looking for exists but is already registered." << endl;

        cout << "Press enter to proceed  <*__]" << endl;
        cin.ignore();
        return;

    }

    // we are taking the input of the course we wanna register
    do {
        cout << "Enter the course code: ";
        cin >> courseId;
        courseId = toUpperCase(courseId);

        // storing in a pointer the address of the object we looking for
        Course *resultCourse = courseList.searchAndRetreivePtr(Course(NULL, courseId));

        alreadytaken = false;

        // we check if the course we wanna add is already registered by the student
        for (int i = 0; i < resultStudent->getRegisteredCourse().size() && !alreadytaken; i++)
            if (resultStudent->getRegisteredCourse()[i] == resultCourse->getCourseCode())
                alreadytaken = true;

        // making sure the value is valid
        if (resultCourse != nullptr) {
            if(alreadytaken)
                cerr << "Course already registered!!!" << endl;
            // making sure that the course capacity isn't full
            else if (resultCourse->getCapacity() <= resultCourse->getNumberOfEnrolled()) {
                cerr << "The course has already reached its maximum capacity!!" << endl;
            }
                // making sure that the regular student doesn't exceed 18 credits
            else if (resultStudent->getNumberOfcredits() + resultCourse->getNumberOfCredits() > 12
                     && resultStudent->getGpa() < 2) {
                cerr << resultStudent->getFullName()
                     << " has reached their maximum allowed credits this semester as "
                        "they are in probation."
                     << endl;
            }
                // making sure the student on probation hasn't exceeded 12 credits
            else if (resultStudent->getNumberOfcredits() + resultCourse->getNumberOfCredits() > 18
                     && resultStudent->getGpa() >= 2) {
                cerr << resultStudent->getFullName() << " has reached their maximum allowed credits this semester."
                     << endl;
            }
                // in case all conditions are met we can jump into the registration process
            else {

                // we register the course to the student and the student to the course
                resultStudent->addCourse(resultCourse->getCourseCode());
                resultCourse->registerStudent(resultStudent->getStudentId(), resultStudent->getFullName());


                // we increment the amount of credit registered into the original amount

                resultStudent->setNumberOfCredits(
                        resultStudent->getNumberOfcredits() + resultCourse->getNumberOfCredits());
                cout << "Successfully register the student" << endl;
            }

        } else
            cerr << "The course is not offered." << endl;

        // we check if the user want to register more courses to the same student
        do {
            cout << "Do you need to add more courses [Y] yes or [N] no: ";
            cin >> choice;
        } while (choice != 'N' && choice != 'Y' && choice != 'n' && choice != 'y');

    } while (choice != 'N' && choice != 'n');


    // we remove the student from the unregistered list if we successfully added at least one course
    if (resultStudent->getNumberOfcredits() != 0) {
        registered.insertAtBegin(*resultStudent);
        unregistered.deleteAtElement(*resultStudent);
    }

    cout << endl << "Press enter to proceed  <*__]" << endl;
    cin.ignore();
    cin.get();

}


void option9(LListWithDummyNode<Student> &registeredList,
             LListWithDummyNode<Student> &unregistered,
             DoublyLinkedList<Course> &courseList) {
    string courseId, studentId; // to store the courseid and studentid
    bool validS; // checks if the student id is valid

    char nyChoice; // takes Y or y and N or n to be able to register multiple courses
    char daChoice; // takes D or d and A or a to drop or add courses to the student

// making the user input the studentId and making sure it is in the valid format
    do {
        cout << "Enter the student ID: ";
        cin >> studentId;
        validS = (studentId.length() == 8) && (studentId[0] == 'A' || studentId[0] == 'a');

        if (!validS) {
            cerr << "Invalid studentId format, please enter a valid ID eg: A2210191." << endl;
        }
    } while (!validS);
    cout << endl;

    // making studentId capital so it can successfully search for other course with this id
    studentId = toUpperCase(studentId);

    // creating a pointer to object student such as the id is equals to studentId
    Student *resultStudent = registeredList.searchAndRetreivePtr(Student(NULL, studentId));


    // checking to make sure we result student is pointing at  the object student we looking for
    if (resultStudent == nullptr) {

        // in case we don't find him in the unregistered list we check if the student is already registered
        resultStudent = unregistered.searchAndRetreivePtr(Student(NULL, studentId));

        // we check if we got what we looking for if we don't we terminate the session in option 8
        if (resultStudent == nullptr)
            cerr << "The student you are looking for doesn't exists!" << endl;
        else
            cerr << "The student you are looking for exists but isn't registered yet." << endl;

        cout << "Press enter to proceed  <*__]" << endl;
        cin.ignore();
        cin.get();
        return;

    }


    resultStudent->displayRegisteredCourse();
    cout << endl << endl;

    do {
        do {
            cout << "Add course [A] or drop course [D]: ";
            cin >> daChoice;
        } while ((daChoice != 'a' && daChoice != 'A') && (daChoice != 'D' && daChoice != 'd'));


        cout << "Enter the course code: ";
        cin >> courseId;
        courseId = toUpperCase(courseId);

        // storing in a pointer the address of the object we looking for
        Course *resultCourse = courseList.searchAndRetreivePtr(Course(NULL, courseId));

        bool alreadytaken; // stores if the value that indicates that the course is already taken by the student

        // making sure the value is valid
        if (resultCourse == nullptr) {
            cerr << "The course is not offered." << endl;
        } else if (daChoice == 'a' || daChoice == 'A') {
            alreadytaken = false;

            // we check if the course we wanna add is already registered by the student
            for (int i = 0; i < resultStudent->getRegisteredCourse().size() && !alreadytaken; i++)
                if (resultStudent->getRegisteredCourse()[i] == resultCourse->getCourseCode())
                    alreadytaken = true;


            // validating already taken if it returns true the registration process is stopped
            if (alreadytaken)
                cerr << "The course is already registered by this student." << endl;
                // making sure that the course capacity isn't full
            else if (resultCourse->getCapacity() <= resultCourse->getNumberOfEnrolled()) {
                cerr << "The course has already reached its maximum capacity!!" << endl;
            }
                // making sure that the regular student doesn't exceed 18 credits
            else if (resultStudent->getNumberOfcredits() + resultCourse->getNumberOfCredits() > 12
                     && resultStudent->getGpa() < 2) {
                cerr << resultStudent->getFullName()
                     << " has reached their maximum allowed credits this semester as "
                        "they are in probation."
                     << endl;
            }
                // making sure the student on probation hasn't exceeded 12 credits
            else if (resultStudent->getNumberOfcredits() + resultCourse->getNumberOfCredits() > 18
                     && resultStudent->getGpa() >= 2) {
                cerr << resultStudent->getFullName() << " has reached their maximum allowed credits this semester."
                     << endl;
            }
                // in case all conditions are met we can jump into the registration process
            else {

                // we register the course to the student and the student to the course
                resultStudent->addCourse(resultCourse->getCourseCode());
                resultCourse->registerStudent(resultStudent->getStudentId(), resultStudent->getFullName());


                // we increment the amount of credit registered into the original amount

                resultStudent->setNumberOfCredits(
                        resultStudent->getNumberOfcredits() + resultCourse->getNumberOfCredits());

                cout << "Successfully registered the course." << endl;

            }

        } else if (daChoice == 'd' || daChoice == 'D') {
            alreadytaken = false;

            // we check if the course we wanna add is already registered by the student
            for (int i = 0; i < resultStudent->getRegisteredCourse().size() && !alreadytaken; i++)
                if (resultStudent->getRegisteredCourse()[i] == resultCourse->getCourseCode())
                    alreadytaken = true;

            if (alreadytaken) {

                //removing the student from the registered students list and removing the student from the registered course list
                resultStudent->dropCourse(resultCourse->getCourseCode());
                resultCourse->dropStudent(resultStudent->getStudentId());

                // remove the number of credits from the total credit taken by the student
                resultStudent->setNumberOfCredits(
                        resultStudent->getNumberOfcredits() - resultCourse->getNumberOfCredits());

                cout << "Successfully dropped the student." << endl;

            }

        }
        // we check if the user want to register or drop more courses to the same student
        do {
            cout << "Do you need to add more courses [Y] yes or [N] no: ";
            cin >> nyChoice;
        } while (nyChoice != 'N' && nyChoice != 'Y' && nyChoice != 'n' && nyChoice != 'y');

    } while (nyChoice != 'N' && nyChoice != 'n');

    if (resultStudent->getRegisteredCourse().size() == 0) {
        unregistered.insertAtBegin(*resultStudent);
        unregistered.deleteAtElement(*resultStudent);
    }

    cout << endl << endl;
    cout << "Press enter to proceed  <*__]" << endl;
    cin.ignore();
    cin.get();

}


void option10() {
    cout << "Thanks for using using our registration service for any sort of assistance make sure"
            " to contact us\non +961 81-445-042 or via email on team4@freelabor.com.lb";

    exit(0);
}


int displayMenuAndTakeOption(ostream &out, istream &in) {

    //----- Displaying the options -----
    out
            << "1. Display the list of non-registered students." << endl
            << "2. Display the list of offered courses" << endl
            << "3. Display the list of registered students with the registered courses." << endl
            << "4. Display the list of offered courses with the registered students." << endl
            << "5. Display the registered courses for a student." << endl
            << "6. Display the list of students registered in a course." << endl
            << "7. Display the information related to a specific student." << endl
            << "8. Register a student." << endl
            << "9. Choose a student to add/drop a course for him/her." << endl
            << "10. Quit the application." << endl << endl;

    int option;

    //------- Taking input and insuring its validation
    do {
        out << "Enter your choice: ";
        in >> option;

        if (in.fail() || option < 1 || option > 10) {
            in.clear();  // Clear error flags
            in.ignore(numeric_limits<streamsize>::max(), '\n'); // Consume invalid input
            cerr << "Invalid choice. Please enter a number between 1 and 10." << endl;
        }
    } while (in.fail() || option < 1 || option > 10);

    out << endl << endl << endl;

    return option;
}



vector<string> readFileAndParseContent(string title, const string &filename) {
    vector<string> content;

    try {
        ifstream inputFile(filename);

        if (!inputFile.is_open()) {
            throw runtime_error(
                    "Failed to open the file.\nPlease double-check if the file exists or if there "
                    "has been any error while pasting the directory or file name.\n");
        }

        string maxIndexS;
        getline(inputFile, maxIndexS);
        int arraySize = stoi(maxIndexS);
        content.resize(arraySize);

        for (int i = 0; i < arraySize && getline(inputFile, content[i]); i++) {
            content[i];
        }

        cout << endl << content.size() << " " << title << (content.size() > 1 ? "s" : "")
             << "  have been read from the file " << filename << endl;
        if (content.size() < arraySize)
            cerr << (arraySize - content.size()) << " " << title << " have not been read!";

        inputFile.close();
        return content;
    } catch (const invalid_argument &e) {
        cerr
                << "Error: The element on the first line should be a "
                   "decimal number (e.g., 8), please fix the error in the file located in:\n"
                << filename;
        exit(0);
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
        exit(0);
    }
}



