/**
 * @file LListWithDummyNode.h
 * @brief Implementation of the LListWithDummyNode class and its member functions.
 *
 * This file contains the declaration of the LListWithDummyNode class, which represents a linked list
 * with a dummy node. It provides methods for managing linked list operations such as insertion, deletion,
 * searching, and display.
 *
 * @date 9 Nov 2023
 *
 * The purpose of this class is to encapsulate the properties and behaviors of a linked list with a dummy node.
 * It simplifies linked list operations by including a dummy node, which serves as a placeholder and simplifies
 * insertion and deletion operations.
 *
 * Public Member Functions:
 *   1. LListWithDummyNode()
 *   2. LListWithDummyNode(const LListWithDummyNode &)
 *   3. ~LListWithDummyNode()
 *   4. bool isEmpty() const
 *   5. bool insertAtBegin(const ElementType &)
 *   6. bool insertAtEnd(const ElementType &)
 *   7. bool deleteFromBegin()
 *   8. bool deleteFromEnd()
 *   9. bool deleteAtIndex(unsigned)
 *   10. bool deleteAtElement(const ElementType &)
 *   11. int getSize() const
 *   12. ElementType &retrieveAtIndex(unsigned) const
 *   13. int search(const ElementType &) const
 *   14. ElementType* searchAndRetreivePtr(const ElementType &) const
 *   15. LListWithDummyNode &operator=(const LListWithDummyNode &)
 *   16. ostream &displayList(ostream &) const
 *
 * Overloaded Operators:
 *   1. ostream &operator<<(ostream &, const LListWithDummyNode<ElementType> &)
 *   2. istream &operator>>(istream &, LListWithDummyNode<ElementType> &)
 *
 * @tparam ElementType The type of elements stored in the linked list.
 */

#ifndef DSPROJECT_LLISTWITHDUMMYNODE_H
#define DSPROJECT_LLISTWITHDUMMYNODE_H

#include "iostream"
#include "Course.h"
#include "Student.h"

using namespace std;

// Forward declarations for dependencies
class Student;
class Course;


template<typename ElementType>

class LListWithDummyNode {
private:
    // Node class for the elements in the linked list
    class Node {
    public:
        Node(const ElementType &data) {
            this->data = data;
            next = nullptr;
        }

        ElementType data;
        Node *next;
    };

    typedef Node *NodePtr;

    // Private members of the LListWithDummyNode class
    NodePtr myFirst; // Dummy node
    int mySize;

public:
    // Constructors and Destructor

    /**
 * @brief Default constructor for LListWithDummyNode.
 *
 * This constructor initializes a linked list with a dummy node.
 *
 * @tparam ElementType The type of elements stored in the linked list.
 *
 * @pre None.
 *
 * @post A new linked list is created with a dummy node containing the default value
 *       for ElementType. The size of the linked list is set to 0.
 *
 * @details The constructor initializes a dummy node with a default value for ElementType
 *          and sets the size of the linked list to 0. The dummy node serves as a placeholder
 *          and simplifies insertion and deletion operations.
 */
    LListWithDummyNode();

    /**
 * @brief Copy constructor for LListWithDummyNode.
 *
 * This constructor creates a deep copy of the provided LListWithDummyNode.
 *
 * @tparam ElementType The type of elements stored in the linked list.
 *
 * @param orig The LListWithDummyNode to be copied.
 *
 * @pre None.
 *
 * @post A new linked list is created with a deep copy of the elements from the
 *       original linked list. The size of the new linked list is set to the size
 *       of the original linked list.
 *
 * @details The constructor initializes a dummy node with a default value for ElementType
 *          and then creates a deep copy of the elements from the original linked list.
 *          It sets the size of the new linked list to the size of the original linked list.
 *          If the original list is empty, the new list will also have only the dummy node.
 *          Otherwise, a deep copy of each element is made and linked in the new list.
 */
    LListWithDummyNode(const LListWithDummyNode &);

    /**
 * @brief Destructor for the LListWithDummyNode class.
 *
 * This destructor deallocates the memory used by the linked list with a dummy node.
 *
 * @tparam ElementType The type of elements stored in the linked list.
 *
 * @pre None.
 *
 * @post All memory used by the linked list, including the dummy node and all data nodes,
 *       is deallocated, and the list is effectively cleared.
 *
 * @details The destructor iterates through the linked list, starting from the dummy node,
 *          and deallocates the memory for each node in the list. It uses a temporary pointer
 *          to traverse the list, deletes the current node, and updates the pointer to the
 *          next node until the end of the list is reached. After this process, the linked
 *          list is effectively cleared, and the memory is released.
 */
    ~LListWithDummyNode();

    // Basic operations

    /**
 * @brief Check if the linked list with a dummy node is empty.
 *
 * This method determines whether the linked list is empty by checking if the dummy node's
 * next pointer is set to nullptr.
 *
 * @tparam ElementType The type of elements stored in the linked list.
 *
 * @return True if the linked list is empty, false otherwise.
 *
 * @pre None.
 *
 * @post The state of the linked list remains unchanged.
 *
 * @details The method checks if the next pointer of the dummy node is nullptr. If it is,
 *          the linked list is considered empty, and the method returns true. Otherwise,
 */
    bool isEmpty() const;

    /**
* @brief Insert an element at the beginning of the linked list with a dummy node.
*
* This method inserts a new element at the beginning of the linked list by creating
* a new node with the provided data and updating pointers accordingly.
*
* @tparam ElementType The type of elements stored in the linked list.
*
* @param data The data to be inserted.
*
* @return True if the insertion is successful, false otherwise.
*
* @pre None.
*
* @post If successful, a new node with the specified data is inserted at the beginning
*       of the linked list, and the size of the list is incremented. If the insertion
*       is unsuccessful, the state of the list remains unchanged.
*
* @details This method first creates a new node containing the provided data. If the
*          linked list is empty, the next pointer of the dummy node is updated to
*          point to the new node, making it the first node. If the list is not empty,
*          the next pointer of the new node is set to the current first node, and the
*          next pointer of the dummy node is updated to point to the new node, making
*          it the new first node. The size of the linked list is then incremented, and
*          the method returns true to indicate a successful insertion.
*/
    bool insertAtBegin(const ElementType &);

    /**
 * @brief Insert an element at the end of the linked list with a dummy node.
 *
 * This method inserts a new element at the end of the linked list by creating
 * a new node with the provided data and updating pointers accordingly.
 *
 * @tparam ElementType The type of elements stored in the linked list.
 *
 * @param data The data to be inserted.
 *
 * @return True if the insertion is successful, false otherwise.
 *
 * @pre None.
 *
 * @post If successful, a new node with the specified data is inserted at the end
 *       of the linked list, and the size of the list is incremented. If the insertion
 *       is unsuccessful, the state of the list remains unchanged.
 *
 * @details This method first creates a new node containing the provided data. If the
 *          linked list is empty, the next pointer of the dummy node is updated to
 *          point to the new node, making it the first and only node in the list. If
 *          the list is not empty, it uses a walker pointer to traverse the list until
 *          it reaches the last node. The next pointer of the last node is then updated
 *          to point to the new node, making it the new last node. The size of the linked
 *          list is then incremented, and the method returns true to indicate a successful
 *          insertion.
 */
    bool insertAtEnd(const ElementType &);

    /**
 * @brief Delete the element at the beginning of the linked list with a dummy node.
 *
 * This method deletes the element at the beginning of the linked list by updating
 * pointers and deallocating memory for the deleted node.
 *
 * @tparam ElementType The type of elements stored in the linked list.
 *
 * @return True if the deletion is successful, false otherwise.
 *
 * @pre The linked list is not empty.
 *
 * @post If successful, the element at the beginning of the linked list is deleted,
 *       and the size of the list is decremented. If the deletion is unsuccessful
 *       (e.g., the list is empty), the state of the list remains unchanged, and
 *       the method returns false.
 *
 * @details This method first checks if the linked list is empty. If it is not empty,
 *          it creates a temporary pointer to the first node, updates the next pointer
 *          of the dummy node to skip the first node, deletes the first node, decrements
 *          the size of the list, and returns true to indicate a successful deletion.
 *          If the list is empty, the method returns false.
 */
    bool deleteFromBegin();

    /**
 * @brief Delete the element at the end of the linked list with a dummy node.
 *
 * This method deletes the element at the end of the linked list by updating
 * pointers and deallocating memory for the deleted node.
 *
 * @tparam ElementType The type of elements stored in the linked list.
 *
 * @return True if the deletion is successful, false otherwise.
 *
 * @pre The linked list is not empty.
 *
 * @post If successful, the element at the end of the linked list is deleted,
 *       and the size of the list is decremented. If the deletion is unsuccessful
 *       (e.g., the list is empty), the state of the list remains unchanged, and
 *       the method returns false.
 *
 * @details This method first checks if the linked list is not empty. If it is not,
 *          it creates a walker pointer to traverse the list until the last node.
 *          It then deletes the last node, decrements the size of the list, and
 *          returns true to indicate a successful deletion. If the list is empty,
 *          the method returns false.
 */
    bool deleteFromEnd();

    /**
 * @brief Delete an element at a specific index in the linked list with a dummy node.
 *
 * This method deletes the element at a specific index in the linked list.
 *
 * @tparam ElementType The type of elements stored in the linked list.
 *
 * @param index The index of the element to be deleted.
 *
 * @return True if the element is successfully deleted, false otherwise.
 *
 * @pre The linked list is not empty, and the index is within the valid range of the list (0 <= index < size).
 *
 * @post If successful, the element at the specified index is removed from the list.
 *       If the index is out of bounds or the list is empty, an error message is displayed.
 *
 * @details This method deletes the element at the specified index in the linked list.
 *          If the list is empty or the index is out of bounds, an error message is displayed.
 *          If the element to be deleted is the first element, the pointer to the first node is updated.
 *          If the element to be deleted is the last element, the pointer to the last node is updated.
 *          Otherwise, the pointers of the adjacent nodes are adjusted to skip the node to be deleted.
 *          The memory occupied by the deleted node is then freed.
 */
    bool deleteAtIndex(unsigned);

    /**
 * @brief Deletes the first occurrence of the specified element in the linked list with a dummy node.
 *
 * This method searches for the specified element in the linked list and deletes the first occurrence.
 *
 * @tparam ElementType The type of elements stored in the linked list.
 *
 * @param e The element to be deleted from the linked list.
 *
 * @return True if the element is found and deleted, false otherwise.
 *
 * @pre None.
 *
 * @post If the element is found in the linked list, the first occurrence is deleted, and the size is updated.
 *       If the element is not found, the linked list remains unchanged.
 *
 * @details This method searches for the specified element in the linked list. If the element is found,
 *          it is deleted, and the size of the linked list is updated. If the element is not found,
 *          the linked list remains unchanged.
 */
    bool deleteAtElement(const ElementType &);

    // Access operations

    /**
 * @brief Get the size of the linked list with a dummy node.
 *
 * This method returns the current size (number of elements) of the linked list.
 *
 * @tparam ElementType The type of elements stored in the linked list.
 *
 * @return The number of elements in the list.
 *
 * @pre None.
 *
 * @post No changes to the linked list.
 *
 * @details This method provides the current size of the linked list by returning the value
 *          of the private member variable 'mySize'. It does not modify the state of the list.
 */
    int getSize() const;

    /**
 * @brief Retrieve the element at a specific index in the linked list with a dummy node.
 *
 * This method retrieves the element at a specific index in the linked list.
 *
 * @tparam ElementType The type of elements stored in the linked list.
 *
 * @param index The index of the element to be retrieved.
 *
 * @return A reference to the element at the specified index.
 *
 * @pre The index is within the valid range of the linked list (0 <= index < size).
 *
 * @post No changes to the linked list.
 *
 * @details This method retrieves the element at the specified index in the linked list.
 *          If the index is out of bounds (greater than or equal to the size of the list),
 *          it prints an error message to the standard error stream and terminates the program.
 *          Otherwise, it iterates through the list using a temporary pointer to find the element
 *          at the specified index and returns a reference to that element.
 */
    ElementType &retrieveAtIndex(unsigned) const;

    // Search operations

    /**
 * @brief Search for an element in the linked list with a dummy node.
 *
 * This method searches for the specified element in the linked list with a dummy node and returns the
 * index of the first occurrence. If the element is not found, it returns -1.
 *
 * @tparam ElementType The type of elements stored in the linked list.
 *
 * @param e The element to be searched in the linked list with a dummy node.
 *
 * @return The index of the first occurrence of the element in the list, or -1 if not found.
 *
 * @pre None.
 *
 * @post The state of the linked list with a dummy node remains unchanged.
 *
 * @details This method iterates through the elements of the linked list with a dummy node and compares
 *          each element with the specified element `e`. If a match is found, it returns the index of the
 *          first occurrence. If the element is not found, it returns -1.
 */
    int search(const ElementType &) const;

    /**
 * @brief Search for an element in the linked list with a dummy node and retrieve a pointer to it.
 *
 * This method searches for the specified element in the linked list with a dummy node and returns a pointer
 * to the first occurrence of the element. If the element is not found, it returns nullptr.
 *
 * @tparam ElementType The type of elements stored in the linked list.
 *
 * @param e The element to be searched in the linked list with a dummy node.
 *
 * @return A pointer to the first occurrence of the element in the list, or nullptr if not found.
 *
 * @pre None.
 *
 * @post The state of the linked list with a dummy node remains unchanged.
 *
 * @details This method iterates through the elements of the linked list with a dummy node and compares
 *          each element with the specified element `e`. If a match is found, it returns a pointer to the
 *          element. If the element is not found, it returns nullptr.
 */
    ElementType* searchAndRetreivePtr(const ElementType &) const;


    // Overloaded operators

    /**
 * @brief Assign the content of another linked list with a dummy node to this one.
 *
 * This method assigns the content of another linked list with a dummy node to this one.
 *
 * @tparam ElementType The type of elements stored in the linked list.
 *
 * @param comparisonList The linked list with a dummy node to be copied.
 *
 * @return A reference to the modified linked list with a dummy node.
 *
 * @pre None.
 *
 * @post The content of the current linked list with a dummy node is replaced with a copy of the content
 *       from the specified linked list with a dummy node. The size and elements are updated accordingly.
 *
 * @details This method performs a deep copy of the content from the specified linked list with a dummy node
 *          to the current linked list with a dummy node. It first deletes all existing nodes in the current list
 *          (excluding the dummy node) and then creates new nodes to replicate the content of the specified list.
 *          If the specified list is empty, the current list becomes empty as well. The assignment is skipped if the
 *          specified list is the same as the current one (self-assignment).
 */
    LListWithDummyNode &operator=(const LListWithDummyNode &);

    /**
 * @brief Display the elements of the linked list with a dummy node.
 *
 * This method prints the elements of the linked list with a dummy node to the specified output stream.
 * If the list is empty, it prints "Empty List."
 *
 * @tparam ElementType The type of elements stored in the linked list.
 *
 * @param out The output stream to which the elements are printed.
 *
 * @return A reference to the output stream.
 *
 * @pre None.
 *
 * @post The elements of the linked list with a dummy node are printed to the specified output stream.
 *
 * @details This method iterates through the elements of the linked list with a dummy node and prints each
 *          element to the provided output stream. If the list is empty, it prints "Empty List."
 */
    ostream &displayList(ostream &) const;



};

/**
 * @brief Overloaded stream insertion operator for displaying the contents of the linked list with a dummy node.
 *
 * This operator allows the linked list with a dummy node to be displayed using the << operator.
 *
 * @tparam ElementType The type of elements stored in the linked list.
 *
 * @param out The output stream to which the linked list with a dummy node will be displayed.
 * @param list The linked list with a dummy node to be displayed.
 *
 * @return A reference to the output stream after displaying the linked list with a dummy node.
 *
 * @pre None.
 *
 * @post The state of the linked list with a dummy node remains unchanged.
 *
 * @details This operator calls the `displayList` method of the linked list with a dummy node to
 *          output its contents to the provided output stream.
 */
template<typename ElementType>
ostream &operator<<(ostream &, const LListWithDummyNode<ElementType> &);


/**
 * @brief Overloaded stream extraction operator for reading input into the linked list with a dummy node.
 *
 * This operator allows the linked list with a dummy node to read input using the >> operator.
 *
 * @tparam ElementType The type of elements stored in the linked list.
 *
 * @param in The input stream from which data will be read.
 * @param list The linked list with a dummy node to which the read data will be added.
 *
 * @return A reference to the input stream after reading data into the linked list with a dummy node.
 *
 * @pre The input stream must be valid and not in a fail state.
 *
 * @post The linked list with a dummy node may be modified by adding elements read from the input stream.
 *
 * @details This operator reads an element from the input stream into a temporary variable
 *          and then inserts it at the beginning of the linked list with a dummy node
 *          using the `insertAtBegin` method.
 */
template<typename ElementType>
istream & operator>>(istream & in,  LListWithDummyNode<ElementType>& list);


template<typename ElementType>
LListWithDummyNode<ElementType>::LListWithDummyNode() {
    ElementType dummy;
    myFirst = new Node(dummy);
    mySize = 0;
}


template<typename ElementType>
LListWithDummyNode<ElementType>::LListWithDummyNode(const LListWithDummyNode<ElementType> &orig) {
    // Create a dummy element for the new list
    ElementType dummy;

    // Copy the size from the original list
    mySize = orig.mySize;

    // Create a new Node for the dummy element in the new list
    myFirst = new Node(dummy);

    // Check if the original list is empty
    if (orig.myFirst->next == nullptr) {
        // If empty, set the next pointer of the dummy node to null
        myFirst->next = nullptr;
    } else {
        // If not empty, copy the elements from the original list to the new list
        NodePtr loopPtr = orig.myFirst->next;  // Pointer for traversing the original list
        NodePtr initPtr = myFirst->next;        // Pointer for building the new list

        // Loop through the original list
        while (loopPtr != nullptr) {
            // Create a new node with the data from the original list
            initPtr = new Node(loopPtr->data);

            // Move the pointers to the next nodes in both lists
            initPtr = initPtr->next;
            loopPtr = loopPtr->next;
        }
    }
}



template<typename ElementType>
LListWithDummyNode<ElementType>::~LListWithDummyNode() {
    NodePtr current = myFirst;

    // Iterate through the linked list and deallocate memory for each node
    while (current != nullptr) {
        NodePtr next = current->next; // Save the pointer to the next node
        delete current; // Deallocate memory for the current node
        current = next;  // Move to the next node in the list
    }
}


template<typename ElementType>
bool LListWithDummyNode<ElementType>::isEmpty() const {
    return myFirst->next == nullptr;
}


template<typename ElementType>
bool LListWithDummyNode<ElementType>::insertAtBegin(const ElementType &data) {
    // Create a new node with the provided data
    NodePtr newNode = new Node(data);

    // Check if the list is empty
    if (isEmpty()) {
        // If empty, set the next pointer of the dummy node to the new node
        myFirst->next = newNode;

        // Increment the size of the list
        mySize++;

        // Insertion successful
        return true;
    }

    // If the list is not empty, insert the new node at the beginning
    newNode->next = myFirst->next;
    myFirst->next = newNode;

    // Increment the size of the list
    mySize++;

    // Insertion successful
    return true;
}



template<typename ElementType>
bool LListWithDummyNode<ElementType>::insertAtEnd(const ElementType &data) {
    // Create a new node with the provided data
    NodePtr newNode = new Node(data);

    // Check if the list is empty
    if (mySize == 0) {
        // If empty, set the next pointer of the dummy node to the new node
        myFirst->next = newNode;

        // Increment the size of the list
        mySize++;

        // Insertion successful
        return true;
    }

    // If the list is not empty, find the last node and insert the new node at the end
    NodePtr walker = myFirst->next;

    // Traverse the list to find the last node
    while (walker->next != nullptr) {
        walker = walker->next;
    }

    // Set the next pointer of the last node to the new node
    walker->next = newNode;

    // Increment the size of the list
    mySize++;

    // Insertion successful
    return true;
}



template<typename ElementType>
bool LListWithDummyNode<ElementType>::deleteFromBegin() {
    // Check if the list is empty
    if (isEmpty())
        return false;

    // Save the pointer to the first node
    NodePtr first = myFirst->next;

    // Update the next pointer of the dummy node to skip the first node
    myFirst->next = first->next;

    // Delete the first node
    delete first;

    // Decrement the size of the list
    mySize--;

    // Deletion successful
    return true;
}



template<typename ElementType>
bool LListWithDummyNode<ElementType>::deleteFromEnd() {
    // Check if the list is empty
    if (myFirst->next == nullptr) {
        // If empty, deletion is not possible
        return false;
    }

    // Create a walker pointer to traverse the list
    NodePtr walker = myFirst->next;

    // Traverse the list to find the last node
    while (walker->next != nullptr) {
        walker = walker->next;
    }

    // Delete the last node
    delete walker;

    // Decrement the size of the list
    mySize--;

    // Deletion successful
    return true;
}



template<typename ElementType>
bool LListWithDummyNode<ElementType>::deleteAtIndex(unsigned int index) {
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

    // If the index is at the beginning, use deleteFromBegin method
    if (index == 0) {
        return deleteFromBegin();
    }

    // If the index is at the end, use deleteFromEnd method
    if (index == mySize - 1) {
        return deleteFromEnd();
    }

    // Traverse the list to the node before the one to be deleted
    NodePtr prev = myFirst->next;
    for (int i = 0; i < index - 1; i++) {
        prev = prev->next;
    }

    // Save the pointer to the node to be deleted
    NodePtr deleteMe = prev->next;

    // Update the next pointer of the previous node to skip the node to be deleted
    prev->next = deleteMe->next;

    // Delete the node
    delete deleteMe;

    // Decrement the size of the list
    mySize--;

    // Deletion successful
    return true;
}




template<typename ElementType>
bool LListWithDummyNode<ElementType>::deleteAtElement(const ElementType & e) {
    // Check if the list is empty
    if (isEmpty())
        return false;

    // Create pointers to traverse the list
    NodePtr temp = myFirst->next;
    NodePtr prev = myFirst;

    // If the element to be deleted is at the beginning, use deleteFromBegin method
    if (temp->data == e)
        return deleteFromBegin();

    // Traverse the list to find the element to be deleted
    while (temp != nullptr) {
        // Check if the current node contains the element to be deleted
        if (temp->data == e) {
            // Update the next pointer of the previous node to skip the node to be deleted
            prev->next = temp->next;

            // Delete the node
            delete temp;

            // Decrement the size of the list
            mySize--;

            // Deletion successful
            return true;
        }

        // Move the pointers to the next nodes
        prev = prev->next;
        temp = temp->next;
    }

    // Element not found in the list
    return false;
}



template<typename ElementType>
int LListWithDummyNode<ElementType>::getSize() const {
    return mySize;
}


template<typename ElementType>
ElementType &LListWithDummyNode<ElementType>::retrieveAtIndex(unsigned index) const {
    // Check if the index is out of bounds
    if (index >= mySize) {
        cerr << "Out of bounds. Code terminated!!";
        exit(0); // Exit the program (You may want to consider a different approach for error handling)
    }

    // Create a pointer to traverse the list
    NodePtr temp = myFirst->next;

    // Traverse the list to the specified index
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }

    // Return the data of the node at the specified index
    return temp->data;
}


template<typename ElementType>
LListWithDummyNode<ElementType> &
LListWithDummyNode<ElementType>::operator=(const LListWithDummyNode<ElementType> &comparisonList) {
    if (this != &comparisonList) {
        // Delete the current list (excluding the dummy node)
        while (myFirst->next != nullptr) {
            NodePtr tempPtr = myFirst->next;
            myFirst->next = tempPtr->next;
            delete tempPtr;
        }

        mySize = comparisonList.mySize;
        // Create a new dummy node
        NodePtr listPtr = comparisonList.myFirst;
        NodePtr temp = myFirst;

        // Create and copy the remaining nodes
        while (listPtr != nullptr) {
            temp->next = new Node(listPtr->data);
            temp = temp->next;
            listPtr = listPtr->next;
        }
    }

    return *this;

}


template<typename ElementType>
int LListWithDummyNode<ElementType>::search(const ElementType &e) const {
    int counter = 0;

    // Check if the list is empty
    if (isEmpty())
        return -1;

    // Create a pointer to traverse the list
    NodePtr temp = myFirst->next;

    // Check if the first node contains the element to be searched
    if (temp->data == e)
        return 0;

    // Traverse the list to find the element
    while (temp->next != nullptr) {
        // Check if the next node contains the element to be searched
        if (temp->next->data == e)
            return counter;

        // Increment the counter and move the pointer to the next node
        counter++;
        temp = temp->next;
    }

    // Element not found in the list
    return -1;
}



template<typename ElementType>
ElementType* LListWithDummyNode<ElementType>::searchAndRetreivePtr(const ElementType & e) const {
    // Check if the list is empty
    if (isEmpty())
        return nullptr;

    // Create a pointer to traverse the list
    NodePtr temp = myFirst->next;

    // Check if the first node contains the element to be searched
    if (temp->data == e)
        return &temp->data;

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
ostream & LListWithDummyNode<ElementType>::displayList(ostream & out) const {
    // Check if the list is empty
    if (isEmpty()) {
        out << "Empty List";
        return out;
    }

    // Create a pointer to traverse the list
    NodePtr dataPtr = myFirst->next;

    // Traverse the list and output each element
    while (dataPtr != nullptr) {
        out << dataPtr->data;

        // Move the pointer to the next node
        dataPtr = dataPtr->next;
    }

    // Return the output stream
    return out;
}



template<typename ElementType>
ostream & operator<<(ostream & out, const LListWithDummyNode<ElementType> & list){
    return list.displayList(out);
}


template<typename ElementType>
istream & operator>>(istream & in,  LListWithDummyNode<ElementType>& list){
    ElementType tempData; // Create a temporary variable to read the input into
    in >> tempData;      // Read the input into the temporary variable

    list.insertAtBegin(tempData); // Add the temporary data to the list

    return in;
}



#endif //DSPROJECT_LLISTWITHDUMMYNODE_H
