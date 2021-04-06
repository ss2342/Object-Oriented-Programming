#include <iostream>
using namespace std;

struct TNode {
    TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
            : data(data), left(left), right(right) {}
    int data;
    TNode *left, *right;
};

int evenOnes(int n) {
    if (n < 2) {
        if (n == 1) {
            return false;
        }
        else {
            return true;
        }
    }
    else {
        bool check = evenOnes(n / 2);
        if (n % 2 == 0) {
            return check;
        }
        else {
            return !check;
        }
    }
}
#include <iostream>
using namespace std;

struct Node {
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};

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

Node* createNewList(Node* listOne, Node* listTwo) {
    Node* newList = new Node();
    if (listOne == nullptr && listTwo == nullptr) {
        return nullptr;
    }
    else if (listTwo == nullptr) {
        newList->data = listOne->data;
        newList->next = createNewList(listOne->next, listTwo);
    }
    else if (listOne == nullptr) {
        newList->data = listTwo->data;
        newList->next = createNewList(listOne, listTwo->next);
    }
    else {
        newList->data = listOne->data + listTwo->data;
        newList->next = createNewList(listOne->next, listTwo->next);
//        listAddTail(newList, value);
    }
    return newList;
}


int findMax(TNode* root) {
    int max_num = 0;
    if (root == nullptr) {
        throw length_error("Empty tree");
    }
    else {
        if (root->left == nullptr && root->right == nullptr) {
            max_num = root->data;
            return max_num;
        }
        else if (root->left == nullptr) {
            max_num = max(root->data, findMax(root->right));
        }
        else if (root->right == nullptr) {
            max_num = max(root->data, findMax(root->left));
        }
        else {
            max_num = max(root->data, max(findMax(root->left), findMax(root->right)));
        }
    }
    return max_num;
}


bool palindrome(char* words, size_t length) {
    if (length <= 1) {
        return true;
    }
    else {
        return (words[0]  == words[length-1]) && palindrome(&words[1], length - 2);
    }
}

int towers(int n, char start, char target, char spare) {
    if (n == 0) {
        return 0;
    }
    else {
        return 1 + towers(n-1, start, spare, target) + towers(n-1, spare, target, start);
    }
}

void mystery(int n) {
    if (n > 1) {
        cout << 'a';
        mystery(n/2);
        cout << 'b';
        mystery(n/2);
    }
    cout << 'c';
}



//int max(TNode* root) {
//    // Provide this code
//}

int main() {
    cout << evenOnes(0) << endl; // return 1
    cout << evenOnes(1) << endl; // return 0
    cout << evenOnes(3) << endl; // return 1
    cout << evenOnes(7) << endl; // return 0
    cout << evenOnes(47) << endl; // return 0

    Node* list1 = new Node();
    listAddTail(list1, 8);
    listAddTail(list1, 2);
    listAddTail(list1, 9);
    listDisplay(list1);


    Node* list2 = new Node();
    listAddTail(list2, 5);
    listDisplay(list2);

    Node* newList = createNewList(list1, list2);
    listDisplay(newList);




    TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
    cout << findMax(&f) << endl;

    cout << towers(1, 'a', 'b', 'c') << endl;
    cout << towers(2, 'a', 'b', 'c') << endl;
    cout << towers(3, 'a', 'b', 'c') << endl;
    cout << towers(4, 'a', 'b', 'c') << endl;
    cout << towers(5, 'a', 'b', 'c') << endl;

    mystery(4);


}
