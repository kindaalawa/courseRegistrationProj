/**
 * @file DoublyLinkedList.h
 * @brief Implementation of the DoublyLinkedList class template and its member functions.
 *
 * This file contains the declaration of the DoublyLinkedList class template, which represents
 * a doubly linked list that can store elements of any data type. It provides methods for managing
 * linked list operations such as insertion, deletion, searching, and display.
 *
 * @date 9 Nov 2023
 *
 * The purpose of this class template is to encapsulate the properties and behaviors of a doubly
 * linked list. It allows users to perform operations such as inserting elements at the beginning
 * and end, deleting elements, searching for elements, and displaying the list.
 *
 * Public Member Functions:
 *   1. DoublyLinkedList()
 *   2. DoublyLinkedList(const DoublyLinkedList &)
 *   3. ~DoublyLinkedList()
 *   4. bool insertAtBegin(const ElementType &)
 *   5. bool insertAtEnd(const ElementType &)
 *   6. bool deleteFromBegin()
 *   7. bool deleteFromEnd()
 *   8. bool deleteAtElement(const ElementType &)
 *   9. bool deleteAtIndex(unsigned)
 *   10. bool isEmpty() const
 *   11. int getSize() const
 *   12. ElementType &retrieveAtIndex(unsigned int) const
 *   13. int search(const ElementType &) const
 *   14. ElementType* searchAndRetreivePtr(const ElementType &) const
 *   15. DoublyLinkedList &operator=(const DoublyLinkedList &)
 *   16. ostream &displayList(ostream &) const
 *
 * Overloaded Operators:
 *   1. ostream &operator<<(ostream &, const DoublyLinkedList<ElementType> &)
 *   2. istream &operator>>(istream &, DoublyLinkedList<ElementType> &)
 *
 * @tparam ElementType The type of elements to be stored in the list.
 */
#ifndef DSPROJ_DOUBLYLINKEDLIST_H
#define DSPROJ_DOUBLYLINKEDLIST_H

#include "iostream"

using namespace std;

/**
 * @brief DoublyLinkedList class template.
 *
 * This class template represents a doubly linked list that can store elements of any data type.
 *
 * @tparam ElementType The type of elements to be stored in the list.
 */
template<typename ElementType>
class DoublyLinkedList {
private:
    /**
     * @brief Node structure for the doubly linked list.
     */
    class DNode {
    public:
        /**
         * @brief Constructor for DNode.
         * @param data The data to be stored in the node.
         */
        DNode(const ElementType &data) {
            this->data = data;
            next = nullptr;
            prev = nullptr;
        }

        ElementType data;  // The data stored in the node.
        DNode *next;       // Pointer to the next node in the list.
        DNode *prev;       // Pointer to the previous node in the list.
    };

    typedef DNode *DNodePtr;

    DNode *myFirst;   // Pointer to the first node in the list.
    int mySize;       // The size of the list.

public:
    // Constructors and Destructor

    /**
 * @brief Default constructor for DoublyLinkedList.
 *
 * This constructor initializes an empty DoublyLinkedList by setting the size to 0
 * and the pointer to the first Doubly Node in the list to nullptr.
 *
 * @tparam ElementType The type of elements to be stored in the list.
 *
 * @pre None.
 *
 * @post An empty DoublyLinkedList is constructed with size 0 and a null pointer
 *       to the first Doubly Node.
 *
 * @details This constructor is automatically called when a DoublyLinkedList object
 *          is created without specific initialization parameters. It sets up the
 *          initial state of the doubly linked list to be empty.
 */
    DoublyLinkedList();

    /**
 * @brief Copy constructor for DoublyLinkedList.
 *
 * This constructor creates a deep copy of the given DoublyLinkedList.
 *
 * @tparam ElementType The type of elements to be stored in the list.
 *
 * @param orig The DoublyLinkedList to be copied.
 *
 * @pre None.
 *
 * @post A deep copy of the original DoublyLinkedList is created.
 *
 * @details This constructor is responsible for creating a new DoublyLinkedList
 *          that is an exact copy of the provided original list. It performs
 *          deep copy, creating new DNode instances with the same data values.
 */
    DoublyLinkedList(const DoublyLinkedList &);

    /**
 * @brief Destructor for DoublyLinkedList.
 *
 * This destructor deallocates memory used by the DoublyLinkedList.
 *
 * @tparam ElementType The type of elements stored in the list.
 *
 * @pre None.
 *
 * @post All memory used by the DoublyLinkedList is deallocated.
 *
 * @details The destructor is responsible for cleaning up the memory allocated
 *          for all nodes in the DoublyLinkedList. It iterates through the list,
 *          deletes each DNode, and sets the size to 0.
 */
    ~DoublyLinkedList();

    // Insertion operations

    /**
 * @brief Insert an element at the beginning of the DoublyLinkedList.
 *
 * This method inserts a new element at the beginning of the DoublyLinkedList.
 *
 * @tparam ElementType The type of elements stored in the list.
 *
 * @param data The data to be inserted.
 *
 * @return True if the insertion is successful, false otherwise.
 *
 * @pre None.
 *
 * @post The element is inserted at the beginning of the list.
 *
 * @details This method creates a new Doubly Node containing the provided data and
 *          inserts it at the beginning of the list. If the list is empty, the new
 *          node becomes the first node. Otherwise, the next pointer of the new node
 *          points to the old first node, and the previous pointer of the old first
 *          node points to the new node.
 */
    bool insertAtBegin(const ElementType &);

    /**
 * @brief Insert an element at the end of the DoublyLinkedList.
 *
 * This method inserts a new element at the end of the DoublyLinkedList.
 *
 * @tparam ElementType The type of elements stored in the list.
 *
 * @param data The data to be inserted.
 *
 * @return True if the insertion is successful, false otherwise.
 *
 * @pre None.
 *
 * @post The element is inserted at the end of the list.
 *
 * @details This method creates a new Doubly Node containing the provided data and
 *          inserts it at the end of the list. If the list is empty, the new node
 *          becomes the first node. Otherwise, it iterates through the list using a
 *          temporary pointer until it reaches the last node, and then inserts the
 *          new node at the end.
 */
    bool insertAtEnd(const ElementType &);

    // Deletion operations

    /**
 * @brief Delete the element at the beginning of the DoublyLinkedList.
 *
 * This method deletes the element at the beginning of the DoublyLinkedList.
 *
 * @tparam ElementType The type of elements stored in the list.
 *
 * @return True if the deletion is successful, false otherwise.
 *
 * @pre The list is not empty.
 *
 * @post The element at the beginning of the list is deleted.
 *
 * @details This method deletes the first element in the list. If the list is empty,
 *          it returns false. If there is only one element, it deletes the node and
 *          sets the first node pointer to nullptr. If there is more than one element,
 *          it adjusts pointers to maintain the list's integrity and then deletes the
 *          first node.
 */
    bool deleteFromBegin();

    /**
 * @brief Delete the element at the end of the DoublyLinkedList.
 *
 * This method deletes the element at the end of the DoublyLinkedList.
 *
 * @tparam ElementType The type of elements stored in the list.
 *
 * @return True if the deletion is successful, false otherwise.
 *
 * @pre The list is not empty.
 *
 * @post The element at the end of the list is deleted.
 *
 * @details This method deletes the last element in the list. If the list is empty,
 *          it returns false. If there is only one element, it deletes the node and
 *          sets the first node pointer to nullptr. If there is more than one element,
 *          it iterates through the list using a temporary pointer until it reaches
 *          the last node, deletes the last node, and adjusts pointers to maintain
 *          the list's integrity.
 */
    bool deleteFromEnd();

    /**
  * @brief Delete the element with a specific value from the DoublyLinkedList.
  *
  * This method deletes the element with a specific value from the DoublyLinkedList.
  *
  * @tparam ElementType The type of elements stored in the list.
  *
  * @param e The value of the element to be deleted.
  *
  * @return True if the deletion is successful, false otherwise.
  *
  * @pre The list is not empty.
  *
  * @post The element with the specified value is deleted from the list.
  *
  * @details This method searches for the element with the specified value in the list.
  *          If the list is empty, it returns false. If the element is found at the
  *          beginning, it calls the `deleteFromBegin()` method. Otherwise, it iterates
  *          through the list using a temporary pointer until it finds the element,
  *          deletes it, and adjusts pointers to maintain the list's integrity.
  */
    bool deleteAtElement(const ElementType &);

    /**
  * @brief Delete an element at a specific index in the DoublyLinkedList.
  *
  * This method deletes the element at a specific index in the DoublyLinkedList.
  *
  * @tparam ElementType The type of elements stored in the list.
  *
  * @param index The index of the element to be deleted.
  *
  * @return True if the element is successfully deleted, false otherwise.
  *
  * @pre The list is not empty, and the index is within the valid range of the list (0 <= index < size).
  *
  * @post If successful, the element at the specified index is removed from the list.
  *       If the index is out of bounds or the list is empty, an error message is displayed.
  *
  * @details This method deletes the element at the specified index in the list.
  *          If the list is empty or the index is out of bounds, an error message is displayed.
  *          If the element to be deleted is the first element, the pointer to the first node is updated.
  *          Otherwise, the pointers of the adjacent nodes are adjusted to skip the node to be deleted.
  *          The memory occupied by the deleted node is then freed.
  */
    bool deleteAtIndex(unsigned);

    /**
 * @brief Checks whether the doubly linked list is empty.
 *
 * This function returns true if the doubly linked list is empty,
 * i.e., it has no elements, and false otherwise.
 *
 * @tparam ElementType The type of elements stored in the doubly linked list.
 *
 * @pre The DoublyLinkedList object must be properly initialized.
 *
 * @post The state of the DoublyLinkedList object is unchanged.
 *
 * @return True if the doubly linked list is empty, false otherwise.
 */
    bool isEmpty() const;

    // Access operations

    /**
 * @brief Get the size of the DoublyLinkedList.
 *
 * This method returns the current size (number of elements) of the DoublyLinkedList.
 *
 * @tparam ElementType The type of elements stored in the list.
 *
 * @return The number of elements in the list.
 *
 * @pre None.
 *
 * @post No changes to the list.
 *
 * @details This method provides the current size of the DoublyLinkedList by
 *          returning the value of the private member variable 'mySize'. It does
 *          not modify the state of the list.
 */
    int getSize() const;

    /**
 * @brief Retrieve the element at a specific index in the DoublyLinkedList.
 *
 * This method retrieves the element at a specific index in the DoublyLinkedList.
 *
 * @tparam ElementType The type of elements stored in the list.
 *
 * @param index The index of the element to be retrieved.
 *
 * @return A reference to the element at the specified index.
 *
 * @pre The index is within the valid range of the list (0 <= index < size).
 *
 * @post No changes to the list.
 *
 * @details This method retrieves the element at the specified index in the list.
 *          If the index is out of bounds (greater than or equal to the size of the list),
 *          it exits the program. Otherwise, it iterates through the list using a
 *          temporary pointer to find the element at the specified index.
 */
    ElementType &retrieveAtIndex(unsigned int) const;

    // Search operations

    /**
 * @brief Search for an element in the DoublyLinkedList.
 *
 * This method searches for the specified element in the DoublyLinkedList and returns the
 * index of the first occurrence. If the element is not found, it returns -1.
 *
 * @tparam ElementType The type of elements stored in the list.
 *
 * @param e The element to be searched in the DoublyLinkedList.
 *
 * @return The index of the first occurrence of the element in the list, or -1 if not found.
 *
 * @pre None.
 *
 * @post The state of the DoublyLinkedList remains unchanged.
 *
 * @details This method iterates through the elements of the DoublyLinkedList and compares
 *          each element with the specified element `e`. If a match is found, it returns the
 *          index of the first occurrence. If the element is not found, it returns -1.
 */
    int search(const ElementType &) const;

    /**
 * @brief Search for an element in the DoublyLinkedList and retrieve a pointer to it.
 *
 * This method searches for the specified element in the DoublyLinkedList and returns a pointer
 * to the first occurrence of the element. If the element is not found, it returns nullptr.
 *
 * @tparam ElementType The type of elements stored in the list.
 *
 * @param e The element to be searched in the DoublyLinkedList.
 *
 * @return A pointer to the first occurrence of the element in the list, or nullptr if not found.
 *
 * @pre None.
 *
 * @post The state of the DoublyLinkedList remains unchanged.
 *
 * @details This method iterates through the elements of the DoublyLinkedList and compares
 *          each element with the specified element `e`. If a match is found, it returns a
 *          pointer to the element. If the element is not found, it returns nullptr.
 */
    ElementType* searchAndRetreivePtr(const ElementType & e) const;

    // Overloaded operators

    /**
 * @brief Assign the content of another DoublyLinkedList to this one.
 *
 * This method assigns the content of another DoublyLinkedList to this one.
 *
 * @tparam ElementType The type of elements stored in the list.
 *
 * @param comparisonList The DoublyLinkedList to be copied.
 *
 * @return A reference to the modified DoublyLinkedList.
 *
 * @pre None.
 *
 * @post The content of the current DoublyLinkedList is replaced with a copy of the content
 *       from the specified DoublyLinkedList. The size and elements are updated accordingly.
 *
 * @details This method performs a deep copy of the content from the specified DoublyLinkedList
 *          to the current DoublyLinkedList. It first deletes all existing nodes in the current list
 *          and then creates new nodes to replicate the content of the specified list. If the specified
 *          list is empty, the current list becomes empty as well. The assignment is skipped if the
 *          specified list is the same as the current one (self-assignment).
 */
    DoublyLinkedList<ElementType> &operator=(const DoublyLinkedList<ElementType> &);

    /**
 * @brief Display the elements of the DoublyLinkedList.
 *
 * This method prints the elements of the DoublyLinkedList to the specified output stream.
 * If the list is empty, it prints "Empty List."
 *
 * @tparam ElementType The type of elements stored in the list.
 *
 * @param out The output stream to which the elements are printed.
 *
 * @return A reference to the output stream.
 *
 * @pre None.
 *
 * @post The elements of the DoublyLinkedList are printed to the specified output stream.
 *
 * @details This method iterates through the elements of the DoublyLinkedList and prints each
 *          element followed by a newline character. If the list is empty, it prints "Empty List."
 */
    ostream &displayList(ostream &) const;


    //ostream &operator<<(ostream &);

};

/**
 * @brief Overloaded stream insertion operator for displaying the contents of the DoublyLinkedList.
 *
 * This operator allows the DoublyLinkedList to be displayed using the << operator.
 *
 * @tparam ElementType The type of elements stored in the list.
 *
 * @param out The output stream to which the DoublyLinkedList will be displayed.
 * @param list The DoublyLinkedList to be displayed.
 *
 * @return A reference to the output stream after displaying the DoublyLinkedList.
 *
 * @pre None.
 *
 * @post The state of the DoublyLinkedList remains unchanged.
 *
 * @details This operator calls the `displayList` method of the DoublyLinkedList to
 *          output its contents to the provided output stream.
 */
template<typename ElementType>
ostream & operator<<(ostream &, DoublyLinkedList<ElementType> const &);

template<typename ElementType>

/**
 * @brief Overloaded stream extraction operator for reading input into the DoublyLinkedList.
 *
 * This operator allows the DoublyLinkedList to read input using the >> operator.
 *
 * @tparam ElementType The type of elements stored in the list.
 *
 * @param in The input stream from which data will be read.
 * @param list The DoublyLinkedList to which the read data will be added.
 *
 * @return A reference to the input stream after reading data into the DoublyLinkedList.
 *
 * @pre The input stream must be valid and not in a fail state.
 *
 * @post The DoublyLinkedList may be modified by adding elements read from the input stream.
 *
 * @details This operator reads an element from the input stream into a temporary variable
 *          and then inserts it at the beginning of the DoublyLinkedList using the `insertAtBegin` method.
 */
istream & operator>>(istream &, DoublyLinkedList<ElementType>  &);


template<typename ElementType>
DoublyLinkedList<ElementType>::DoublyLinkedList() {
    /*
     We construct an empty DoublyLinkedList by setting the size to 0, and the
     pointer to the first Doubly Node in the list to nullptr.
     */
    mySize = 0;
    myFirst = nullptr;
}


template<typename ElementType>
DoublyLinkedList<ElementType>::DoublyLinkedList(const DoublyLinkedList<ElementType> &orig) {
    // Copy the size from the original list
    mySize = orig.mySize;

    // Initialize the first node of the new list to nullptr
    myFirst = nullptr;

    // Check if the original list is not empty
    if (orig.myFirst != nullptr) {
        // Create a new node for the first element in the new list
        myFirst = new DNode(orig.myFirst->data);

        // Pointers to traverse the original and new lists
        DNodePtr loopPtr = orig.myFirst;
        DNodePtr initPtr = myFirst;

        // Traverse the original list and create corresponding nodes in the new list
        while (loopPtr != nullptr) {
            // Create a new node with the data from the original list
            initPtr->next = new DNode(loopPtr->data);

            // Set the previous pointer of the new node
            initPtr->next->prev = initPtr;

            // Move the pointers to the next nodes in both lists
            initPtr = initPtr->next;
            loopPtr = loopPtr->next;
        }
    }
}



template<typename ElementType>
DoublyLinkedList<ElementType>::~DoublyLinkedList() {
    // Loop until the list is empty
    while (!isEmpty()) {
        // Save the pointer to the first node
        DNodePtr tempPtr = myFirst;

        // Update the first node pointer to the next node
        myFirst = myFirst->next;

        // Delete the saved node
        delete tempPtr;
    }

    // Set the size to 0 after deleting all nodes
    mySize = 0;
}


template<typename ElementType>
bool DoublyLinkedList<ElementType>::isEmpty() const {
    return myFirst == nullptr;
}


template<typename ElementType>
bool DoublyLinkedList<ElementType>::insertAtBegin(const ElementType &data) {

    //first create a new Doubly Node containing data from the parameter and then check if the list is empty.
    DNodePtr newNode = new DNode(data);
    if (isEmpty()) {
        // If yes,we make the pointer of the first Doubly Node point to the newly created Doubly Node, and make it the first DoublyNode.
        mySize++;
        myFirst = newNode;
        return true;
    }
    /*
     If not, we make the next pointer of the new DoublyNode point to the first Node and link the previous pointer of the old first Doubly Node
     to the newly created Doubly Node to make it as the new First Doubly Node.
     */
    newNode->next = myFirst;
    myFirst->prev = newNode;
    myFirst = newNode;

    //Increment size of the list after successful insertion in the beginning.
    mySize++;
    return true;
}


template<typename ElementType>
bool DoublyLinkedList<ElementType>::insertAtEnd(const ElementType &data) {
    // Create a new Doubly Node containing data from the parameter
    DNodePtr newNode = new DNode(data);
    if (isEmpty()) {
        // If the list is empty, make the pointer of the first Doubly Node
        // point to the newly created Doubly Node, and make it the first Doubly Node.
        mySize++;
        myFirst = newNode;
        return false;
    }

    // If not, use a temporary pointer to continue to loop until it
    // reaches the last Doubly Node in the list for inserting at the end.
    DNodePtr tempDNodePtr = myFirst;
    while (tempDNodePtr->next != nullptr) {
        tempDNodePtr = tempDNodePtr->next;
    }
    tempDNodePtr->next = newNode;
    newNode->prev = tempDNodePtr;

    // Increment the size of the list after successful insertion at the end.
    mySize++;
    return true;
}


template<typename ElementType>
bool DoublyLinkedList<ElementType>::deleteFromBegin() {
    // Check if the list is empty
    if (isEmpty())
        return false;

    // If there is only one node in the list
    if (myFirst->next == nullptr) {
        // Delete the first (and only) node
        delete myFirst;

        // Set the first pointer to nullptr
        myFirst = nullptr;

        // Decrement the size of the list
        mySize--;

        // Deletion successful
        return true;
    }

    // Save the pointer to the first node
    DNodePtr tempPtr = myFirst;

    // Update the first node pointer to the next node
    myFirst = myFirst->next;

    // Set the previous pointer of the new first node to nullptr
    myFirst->prev = nullptr;

    // Delete the saved node
    delete tempPtr;

    // Decrement the size of the list
    mySize--;

    // Deletion successful
    return true;
}



template<typename ElementType>
bool DoublyLinkedList<ElementType>::deleteFromEnd() {
    // Check if the list is empty
    if (isEmpty())
        return false;

    // If there is only one node in the list
    if (myFirst->next == nullptr) {
        // Delete the first (and only) node
        delete myFirst;

        // Set the first pointer to nullptr
        myFirst = nullptr;

        // Decrement the size of the list
        mySize--;

        // Deletion successful
        return true;
    }

    // Create a pointer to traverse the list
    DNodePtr loopPtr = myFirst;

    // Traverse the list to the last node
    while (loopPtr->next != nullptr)
        loopPtr = loopPtr->next;

    // Update the next pointer of the second-to-last node to nullptr
    loopPtr->prev->next = nullptr;

    // Delete the last node
    delete loopPtr;

    // Decrement the size of the list
    mySize--;

    // Deletion successful
    return true;
}



template<typename ElementType>
bool DoublyLinkedList<ElementType>::deleteAtElement(const ElementType & e){
    // Check if the list is empty
    if(isEmpty())
        return false;

    // Create a pointer to traverse the list
    DNodePtr temp = myFirst;

    // If the first node contains the element to be deleted, use deleteFromBegin method
    if(temp->data == e)
        return deleteFromBegin();

    // Traverse the list to find the element to be deleted
    while(temp != nullptr){
        // Check if the current node contains the element to be deleted
        if(temp->data == e){
            // Update the next pointer of the previous node to skip the node to be deleted
            temp->prev->next = temp->next;

            // Update the previous pointer of the next node to skip the node to be deleted
            temp->next->prev = temp->prev;

            // Delete the node
            delete temp;

            // Decrement the size of the list
            mySize--;

            // Deletion successful
            return true;
        }

        // Move the pointer to the next node
        temp = temp->next;
    }

    // Element not found in the list
    return false;
}



template<typename ElementType>
ElementType &DoublyLinkedList<ElementType>::retrieveAtIndex(unsigned int index) const {
    // Check if the index is out of bounds
    if (index >= mySize) {
        // Consider throwing an exception instead of using exit(0) for better error handling
        cerr << "Index out of bounds. Code terminated!!";
        exit(0); // Exit the program (You may want to consider a different approach for error handling)
    }

    // Create a pointer to traverse the list
    DNodePtr temp = myFirst;

    // Traverse the list to the specified index
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }

    // Return the data of the node at the specified index
    return temp->data;
}



template<typename ElementType>
int DoublyLinkedList<ElementType>::getSize() const {
    return mySize;
}


template<typename ElementType>
bool DoublyLinkedList<ElementType>::deleteAtIndex(unsigned index) {
    // Check if the list is empty
    if (isEmpty()) {
        cerr << "List is empty" << endl;
        return false;
    }

    // Check if the index is out of bounds
    if (index >= mySize) {
        cerr << "Invalid index" << endl;
        return false;
    }

    // Create a pointer to traverse the list
    DNodePtr temp = myFirst;

    // If deleting the first node
    if (index == 0) {
        // Update the first node pointer to the next node
        myFirst = temp->next;

        // If there is a next node, update its previous pointer to nullptr
        if (myFirst) {
            myFirst->prev = nullptr;
        }

        // Delete the saved node
        delete temp;
    } else {
        // Traverse the list to the specified index
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }

        // Update the next pointer of the previous node to skip the node to be deleted
        temp->prev->next = temp->next;

        // If there is a next node, update its previous pointer to skip the node to be deleted
        if (temp->next) {
            temp->next->prev = temp->prev;
        }

        // Delete the saved node
        delete temp;
    }

    // Decrement the size of the list
    mySize--;

    // Deletion successful
    return true;
}



template<typename ElementType>
DoublyLinkedList<ElementType> &
DoublyLinkedList<ElementType>::operator=(const DoublyLinkedList<ElementType> &comparisonList) {
    // Check for self-assignment
    if (this != &comparisonList) {
        // First, delete the current list nodes
        DNodePtr tempo;
        while (myFirst != nullptr) {
            tempo = myFirst;
            myFirst = myFirst->next;
            delete tempo;
        }

        // Now, create a copy of the comparisonList
        mySize = comparisonList.mySize;
        myFirst = nullptr;

        // Check if the comparisonList is not empty
        if (comparisonList.myFirst != nullptr) {
            // Create a new node for the first element in the new list
            myFirst = new DNode(comparisonList.myFirst->data);

            // Pointers to traverse the original and new lists
            DNodePtr listPtr = comparisonList.myFirst;
            DNodePtr temp = myFirst;

            // Traverse the original list and create corresponding nodes in the new list
            while (listPtr != nullptr) {
                // Create a new node with the data from the original list
                temp->next = new DNode(listPtr->data);

                // Set the previous pointer of the new node
                temp->next->prev = temp;

                // Move the pointers to the next nodes in both lists
                temp = temp->next;
                listPtr = listPtr->next;
            }
        }
    }

    // Return a reference to the modified object
    return *this;
}



template<typename ElementType>
ostream &DoublyLinkedList<ElementType>::displayList(ostream &out) const {
    // Check if the list is empty
    if (isEmpty()) {
        out << "Empty List";
        return out;
    }

    // Create a pointer to traverse the list
    DNodePtr dataPtr = myFirst;

    // Traverse the list and output each element
    while (dataPtr != nullptr) {
        out << dataPtr->data << endl;

        // Move the pointer to the next node
        dataPtr = dataPtr->next;
    }

    // Return the output stream
    return out;
}



template<typename ElementType>
int DoublyLinkedList<ElementType>::search(const ElementType &e) const {
    int counter = 0;

    // Check if the list is empty
    if (isEmpty())
        return -1;

    // Create a pointer to traverse the list
    DNodePtr temp = myFirst;

    // Check if the first node contains the element to be searched
    if (temp->data == e)
        return 0;

    // Traverse the list to find the element
    while (temp != nullptr) {
        // Check if the current node contains the element to be searched
        if (temp->data == e)
            return counter;

        // Increment the counter and move the pointer to the next node
        counter++;
        temp = temp->next;
    }

    // Element not found in the list
    return -1;
}



template<typename ElementType>
ElementType* DoublyLinkedList<ElementType>::searchAndRetreivePtr(const ElementType & e) const{
    // Check if the list is empty
    if (isEmpty())
        return nullptr;

    // Create a pointer to traverse the list
    DNodePtr temp = myFirst;

    // Check if the first node contains the element to be searched
    if (temp->data == e)
        return &(temp->data);

    // Traverse the list to find the element
    while (temp->next != nullptr) {
        // Check if the next node contains the element to be searched
        if (temp->next->data == e)
            return &(temp->next->data);

        // Move the pointer to the next node
        temp = temp->next;
    }

    // Element not found in the list
    return nullptr;
}


template<typename ElementType>
ostream & operator<<(ostream & out, const DoublyLinkedList<ElementType> & list){
    return list.displayList(out);
}


template<typename ElementType>
istream & operator>>(istream & in,  DoublyLinkedList<ElementType>& list) {
    ElementType tempData; // Create a temporary variable to read the input into
    in >> tempData;      // Read the input into the temporary variable

    list.insertAtBegin(tempData); // Add the temporary data to the list

    return in;
}

#endif //DSPROJ_DOUBLYLINKEDLIST_H
