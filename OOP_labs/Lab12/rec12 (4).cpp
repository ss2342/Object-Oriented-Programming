// Satyen Singh

#include <cstdlib>
#include <iostream>
using namespace std;

class List {

public:
    friend ostream& operator<<(ostream& os, const List& rhs) {
        Node* theNode = rhs.header->next;
        while (theNode != rhs.trailer) {
            os << " " << theNode->data;
            theNode = theNode->next;
        }
        return os;
    }
    struct Node {
        Node(int data = 0, Node* prior = nullptr, Node* next = nullptr) :
                data(data), prior(prior), next(next) {}
        int data;
        Node* prior;
        Node* next;
    };
    class iterator {

        friend List;

        friend bool operator==(const iterator& lhs, const iterator& rhs) {
            return lhs.nodePtr == rhs.nodePtr;
        }

        friend bool operator!=(const iterator& lhs, const iterator& rhs) {
            return lhs.nodePtr != rhs.nodePtr;
        }

    public:

        iterator(Node* node) : nodePtr(node) {}

        iterator& operator++() {
            nodePtr = nodePtr->next;
            return *this;
        }

        iterator& operator--() {
            nodePtr = nodePtr->prior;
            return *this;
        }

        int& operator*() const {
            return nodePtr->data;
        }

    private:
        Node* nodePtr;
    };


    List() : sizeOfList(0) {
        header = new Node(0);
        trailer = new Node(0);
        header->next = trailer;
        trailer->prior = header;
    }

    int& front() {
        return header->next->data;
    }
    int& front() const {
        return header->next->data;
    }

    int& back() {
        return trailer->prior->data;
    }

    int& back() const {
        return trailer->prior->data;
    }

    size_t size() const {
        return sizeOfList;
    }


    void push_back(int data) {

        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = trailer;
        Node *oldLast = trailer->prior;
        newNode->prior = oldLast;
        trailer->prior = newNode;
        oldLast->next = newNode;
        ++sizeOfList;
    }

    void push_front(int data) {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->prior = header;
        Node *oldFirst = header->next;
        newNode->next = oldFirst;
        header->next = newNode;
        oldFirst->prior = newNode;
        ++sizeOfList;
    }

    int pop_back() {
        if (size() == 0) {
            return -1;
        }
        Node* newLast = trailer->prior->prior;
        delete trailer->prior;
        newLast->next = trailer;
        trailer->prior = newLast;
        --sizeOfList;
        return newLast->data;
    }

    int pop_front() {
        if (size() == 0) {
            return -1;
        }
        Node* newFirst = header->next->next;
        delete header->next;
        newFirst->prior = header;
        header->next = newFirst;
        --sizeOfList;
        return newFirst->data;
    }


    void clear() {
        Node* headPtr = header->next;
        while (headPtr != trailer) {
            Node* deletedNode = headPtr;
            headPtr = headPtr->next;
            delete deletedNode;
        }
        header->next = trailer;
        trailer->prior = header;
        sizeOfList = 0;
    }

    int&operator[](size_t index) {
        Node* headPtr = header->next;
        size_t counter = 0;
        while (counter != index) {
            ++counter;
            headPtr = headPtr->next;
        }
        return headPtr->data;
    }

    int&operator[](size_t index) const {
        Node* headPtr = header->next;
        size_t counter = 0;
        while (counter != index) {
            ++counter;
            headPtr = headPtr->next;
        }
        return headPtr->data;
    }

    iterator begin() const {
        return iterator(header->next);
    }

    iterator end() const {
        return iterator(trailer);
    }

    iterator insert(const iterator& iter, int data) {
        Node* nodeBefore = iter.nodePtr->prior;
        Node* newNode = new Node();
        newNode->data = data;
        Node* nodeAfter = iter.nodePtr;
        newNode->prior = nodeBefore;
        newNode->next = nodeAfter;
        nodeAfter->prior = newNode;
        nodeBefore->next = newNode;
        ++sizeOfList;
        return iterator(newNode);
    }

    iterator erase(const iterator& iter) {
        Node* nodeBefore = iter.nodePtr->prior;
        Node* currentNode = iter.nodePtr;
        Node* nodeAfter = iter.nodePtr->next;
        delete currentNode;
        nodeBefore->next = nodeAfter;
        nodeAfter->prior = nodeBefore;
        --sizeOfList;
        return iterator(nodeAfter);
    }






private:
    size_t sizeOfList;
    Node* header;
    Node* trailer;
};

// Task 1
void printListInfo(const List& myList) {
    cout << "size: " << myList.size()
         << ", front: " << myList.front()
         << ", back(): " << myList.back()
         << ", list: " << myList << endl;
}

// The following should not compile. Check that it does not.
// void changeFrontAndBackConst(const List& theList){
//     theList.front() = 17;
//     theList.back() = 42;
// }

void changeFrontAndBack(List& theList){
    theList.front() = 17;
    theList.back() = 42;
}

// Task 4
void printListSlow(const List& myList) {
    for (size_t i = 0; i < myList.size(); ++i) {
        cout << myList[i] << ' ';
    }
    cout << endl;
}

// Task 8
void doNothing(List aList) {
    cout << "In doNothing\n";
    printListInfo(aList);
    cout << endl;
    cout << "Leaving doNothing\n";
}




int main() {

    // Task 1
    cout << "\n------Task One------\n";
    List myList;
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList.push_back(" << i*i << ");\n";
        myList.push_back(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";

    cout << "Modify the first and last items, and display the results\n";
    changeFrontAndBack(myList);
    printListInfo(myList);
    cout << "===================\n";

    cout << "Remove the items with pop_back\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_back();
    }
    cout << "===================\n";

    // Task 2
    cout << "\n------Task Two------\n";
    cout << "Fill empty list with push_front: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList2.push_front(" << i*i << ");\n";
        myList.push_front(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    cout << "Remove the items with pop_front\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_front();
    }
    cout << "===================\n";

    // Task 3
    cout << "\n------Task Three------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        myList.push_back(i*i);
    }
    printListInfo(myList);
    cout << "Now clear\n";
    myList.clear();
    cout << "Size: " << myList.size() << ", list: " << myList << endl;
    cout << "===================\n";

    // Task 4
    cout << "\n------Task Four------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    cout << "Display elements with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Add one to each element with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) myList[i] += 1;
    cout << "And print it out again with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Now calling a function, printListSlow, to do the same thing\n";
    printListSlow(myList);
    cout << "Finally, for this task, using the index operator to modify\n"
         << "the data in the third item in the list\n"
         << "and then using printListSlow to display it again\n";
    myList[2] = 42;
    printListSlow(myList);

    // Task 5
    cout << "\n------Task Five------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    printListInfo(myList);
    cout << "Now display the elements in a ranged for\n";
    for (int x : myList) cout << x << ' ';
    cout << endl;
    cout << "And again using the iterator type directly:\n";
    // Note you can choose to nest the iterator class or not, your choice.
    //for (iterator iter = myList.begin(); iter != myList.end(); ++iter) {
    for (List::iterator iter = myList.begin(); iter != myList.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;
    cout << "WOW!!! (I thought it was cool.)\n";

    // Task 6
    cout << "\n------Task Six------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Filling an empty list with insert at begin(): "
         << "i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.begin(), i*i);
    printListInfo(myList);
    // ***Need test for insert other than begin/end***
    cout << "===================\n";

    // Task 7
    cout << "\n------Task Seven------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    cout << "Erasing the elements in the list, starting from the beginning\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.erase(myList.begin());
    }
    // ***Need test for erase other than begin/end***
    cout << "===================\n";

    // ***Need test for erase other than begin/end***
    cout << "===================\n";

    // Task 8
    cout << "\n------Task Eight------\n";
    cout << "Copy control\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Calling doNothing(myList)\n";
    doNothing(myList);
    cout << "Back from doNothing(myList)\n";
    printListInfo(myList);

    cout << "Filling listTwo with insert at begin: i*i for i from 0 to 9\n";
    List listTwo;
    for (int i = 0; i < 10; ++i) listTwo.insert(listTwo.begin(), i*i);
    printListInfo(listTwo);
    cout << "listTwo = myList\n";
    listTwo = myList;
    cout << "myList: ";
    printListInfo(myList);
    cout << "listTwo: ";
    printListInfo(listTwo);
    cout << "===================\n";
}
