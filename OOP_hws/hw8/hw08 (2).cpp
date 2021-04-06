
// Satyen Singh
//#include "polynomial.h"
#include <iostream>
#include <vector>
using namespace std;


//// I did not understand anything in this homework and it really flew over my head
//// if I could meet with a TA to get some help on this, that would be great, maybe during their
//// office hours

class Polynomial {
    struct Node {
        Node(int data = 0, Node* next = nullptr) :
                data(data), next(next) {}
        int data;
        Node* next;
    };


public:
    Polynomial() : degrees(0) {
        equation = new Node(0);
    }

    Polynomial(const vector<int>& coeffs) {
        equation = new Node(coeffs[0]);
        if (coeffs.size() > 0) {
            for (int i : coeffs) {
                listAddHead(equation, i);
            }
        }
        degrees = coeffs.size() - 1;
    }

    Polynomial(const Polynomial& rhs) : degrees(rhs.degrees) {
        Node* rhs_Ptr = (new Node(rhs.equation->data));
        Node* rhs_headPtr = rhs_Ptr->next;
        while (rhs_headPtr) {
            listAddTail(equation, rhs_Ptr->data);
            rhs_headPtr = rhs_headPtr->next;
        }
    }
    ~Polynomial() {
        while (equation) {
            Node* nodeToBeDeleted = equation;
            equation = equation->next;
            delete nodeToBeDeleted;
        }
    }



    void listDisplay(Node* headPtr) {
        //for (const Node* p = headPtr; p != nullptr; p = p->next) {
        for (Node* p = headPtr; p != nullptr; p = p->next) {
            cout << p->data << ' ';
        }
        cout << endl;
        //headPtr = nullptr;
    }

    int listLength(Node* headPtr) {
        Node* p = headPtr;
        int counter = 0;
        while ( p != nullptr ) {
            //while ( p ) {
            ++counter;
            p = p->next; // bump
        }
        return counter;
    }


    void listAddHead(Node*& headPtr, int data) {
        headPtr = new Node(data, headPtr);
    }


    Node* findTail(Node* headPtr) {
        if (headPtr == nullptr) return nullptr;
        Node* p = headPtr;
        while (p->next != nullptr) { // while we are not looking at the last node
            p = p->next;
        }
        return p;
    }

    void listAddTail(Node*& headPtr, int data) {
        if (headPtr == nullptr) {
            headPtr = new Node(data);
        } else {
            Node* tail = findTail(headPtr);
            tail->next = new Node(data);
        }
    }

    void listAdd(Node* prior, int data) {
        prior->next = new Node(data, prior->next);
    }

    void listRemoveHead(Node*& headPtr) {
        Node* victim = headPtr;
        headPtr = headPtr->next;
        delete victim;
    }

    void listRemoveTail(Node*& headPtr) {
        if (headPtr == nullptr) {     }
        else if (headPtr->next == nullptr) {
            delete headPtr;
            headPtr = nullptr;
        }
        else {
            Node* p = headPtr;
            // while we are not looking at the second to last node
            while (p->next->next != nullptr) {
                p = p->next;
            }

            delete p->next;
            p->next = nullptr;
        }
    }

    void listRemove(Node* prior) {
        Node* victim = prior->next;
        //prior->next = prior->next->next;
        prior->next = victim->next;
        delete victim;
    }

    void listClear(Node*& headPtr) {
        //int len = listLength(headPtr);
        while (headPtr) {
            listRemoveHead(headPtr);
        }
    }


    Node* listDuplicate(Node* headPtr) {
        if (headPtr == nullptr) return nullptr;

        // initialization code
        Node* result = new Node(headPtr->data);
        Node* last = result;
        Node* current = headPtr->next;

        // loop to duplicate the rest
        while (current != nullptr) {
            last->next = new Node(current->data);
            //listAddTail(result, current->data);
            last = last->next;
            current = current->next;
        }
        return result;
    }

private:
    size_t sizeOfList;
    Node* header;
    Node* trailer;
    int degrees;
    Node* equation;
};

void doNothing(Polynomial temp) {}

int main() {

    //test constructor
    Polynomial p1({17});                 // 17
    Polynomial p2({1, 2});               // x + 2
    Polynomial p3({-1, 5});              // -1x + 5
    Polynomial p4({5, 4, 3, 2, 1});      // 5x^4 + 4x^3 + 3x^2 + 2x + 1
    Polynomial has_a_zero({4, 0, 1, 7}); // 4x^3 + x + 7

    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p3: " << p3 << endl;
    cout << "p4: " << p4 << endl;
//    cout << "has_a_zero: " << has_a_zero << endl;
//    cout << "p2 + p3: " << (p2+p3) << endl;
//    cout << "p2 + p4: " << (p2+p4) << endl;
//    cout << "p4 + p2: " << (p4+p2) << endl;


//    //test copy constructor - the statement below uses the copy constructor
//    //to initialize poly3 with the same values as poly4
//    Polynomial p5(p4);
//    p5 += p3;
//    cout << "Polynomial p5(p4);\n"
//         << "p5 += p3;\n";
//
//    cout << "p4: " << p4 << endl;
//    cout << "p5: " << p5 << endl;
//
//    cout << "Calling doNothing(p5)\n";
//    doNothing(p5);
//    cout << "p5: " << p5 << endl;
//
//    //tests the assignment operator
//    Polynomial p6;
//    cout << "p6: " << p6 << endl;
//    cout << boolalpha;  // Causes bools true and false to be printed that way.
//    cout << "(p4 == p6) is " << (p4 == p6) << endl;
//    p6 = p4;
//    cout << "p6: " << p6 << endl;
//    cout << boolalpha;
//    cout << "(p4 == p6) is " << (p4 == p6) << endl;
//
//    //test the evaluaton
//    int x = 5;
//    cout << "Evaluating p1 at " << x << " yields: " << p1.evaluate(5) << endl;
//    cout << "Evaluating p2 at " << x << " yields: " << p2.evaluate(5) << endl;
//
//    Polynomial p7({3, 2, 1});           // 3x^2 + 2x + 1
//    cout << "p7: " << p7 << endl;
//    cout << "Evaluating p7 at " << x << " yields: " << p7.evaluate(5) << endl;
//
//    cout << boolalpha;
//    cout << "(p1 == p2) is " << (p1 == p2) << endl;
//    cout << "(p1 != p2) is " << (p1 != p2) << endl;
//
//    /*=================================================================
//    NEW TEST CODE - test if cleaning the leading 0s
//    ===================================================================*/
//
//    Polynomial p8({ 1, 1 });
//    Polynomial p9({ -1, 1 });
//    Polynomial p10({ 0, 0, 2 });
//    //p8 + p9 tests if += does the cleanup()
//    //p10 tests if constructor does the cleanup()
//    cout << "((p8 + p9) == p10) is " << ((p8 + p9) == p10) << endl;
//
//
}
