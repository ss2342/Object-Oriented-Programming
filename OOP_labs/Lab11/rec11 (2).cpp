/*
  functions for use with CS2124 rec11
  -jbs
*/

// Satyen Singh
#include <iostream>

#include <vector>
#include <unordered_set>
using namespace std;
// Node to be used a part of linked list
struct Node {
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};

// listAddHead: adds a data item to the beginning of a [possibly empty] list
void listAddHead(Node*& headPtr, int entry) {
    headPtr = new Node(entry, headPtr);
}

// listClear: frees up all the nodes in a list
void listClear(Node*& headPtr) {
    while (headPtr) {
        Node* next = headPtr->next;
        delete headPtr;
        headPtr = next;
    }
}

void splice(Node* spliced, Node* original) {
    Node* spliceHolder = original->next;
    original->next = spliced;
    while (spliced->next) {
        spliced = spliced->next;
    }
    spliced->next = spliceHolder;
}

Node* isSublist(Node* sub, Node* whole) {
    Node* subH = sub;
    Node* wholeH = whole;
    while (whole) {
        if (whole->data == sub->data) {
            Node* nodeFound = whole;
            bool found = false;
            while (subH) {
                if (wholeH && subH->data == wholeH->data) {
                    subH = subH->next;
                    wholeH = wholeH->next;
                    found = true;
                }
                else {
                    break;
                }
            }
            if (found) {
                return nodeFound;
            }
        }
        whole = whole->next;
    }
    cout << "failed to match" << endl;
    return nullptr;
}

Node* sharedListBruteForce(Node* listOne, Node* listTwo) {
    while (listOne && listTwo) {
        if (listOne != listTwo) {
            listOne = listOne->next;
            listTwo = listTwo->next;
        }
        else {
            return listOne->next;
        }
    }
    return nullptr;
}

Node* sharedListUsingSet(Node* listOne, Node* listTwo) {
    unordered_set<Node*> nodes;
    while (listOne) {
        nodes.insert(listOne);
        listOne = listOne->next;
    }
    bool found;
    if (nodes.end() == nodes.find(listTwo)) {
        found = true;
    }
    while (listTwo) {
        if (!found) {
            return listTwo;
        }
        listTwo = listTwo->next;
    }
    return nullptr;
}

void display(const Node* node) {
    while (node) {
        cout << node->data << ' ';
        node = node->next;
    }
    cout << endl;
}

// listBuild: constructs a list from a vector of data items. Note that
// you can use a curly-braced sequence.
// This may be useful for setting up test cases. Feel free to use it
// or not as you like.
// Example of using would be:
//    Node* myList = listBuild({1, 4, 9, 16}); // builds a list of: 1 4 9 16
Node* listBuild(const vector<int>& vals) {
    Node* result = nullptr;
    for (size_t index = vals.size(); index > 0; --index) {
        listAddHead(result, vals[index-1]);
    }
    return result;
}

int main() {
    Node* original = listBuild({5, 7, 9, 1});
    Node* spliced = listBuild({6, 3, 2});
    splice(spliced, original->next);
    display(original);

    cout << endl;
    cout << endl;

    Node* Target = listBuild({1, 2, 3, 2, 3, 2, 4, 5, 6});
    Node* attempt1 = listBuild({1});
    Node* attempt2 = listBuild({3, 9});
    Node* attempt3 = listBuild({2, 3});
    Node* attempt4 = listBuild({2, 4, 5, 6});
    Node* attempt5 = listBuild({2, 3, 2, 4});
    Node* attempt6 = listBuild({5, 6, 7});

    display(isSublist(attempt1, Target));
    display(isSublist(attempt2, Target));
    display(isSublist(attempt3, Target));
    display(isSublist(attempt4, Target));
    display(isSublist(attempt5, Target));
    display(isSublist(attempt6, Target));

    cout << endl;
    cout << endl;

    Node* listOne = listBuild({1, 2});
    Node* listTwo = listBuild({1,2, 3, 4, 5, 6});
    listOne->next = listTwo->next->next->next;
    sharedListBruteForce(listOne, listTwo);
    sharedListUsingSet(listOne, listTwo);




}
