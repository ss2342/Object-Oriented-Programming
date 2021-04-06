// rec13_test.cpp
// Satyen Singh
// CS 2124

#include <iostream>
#include <fstream>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <string>      // task 21
#include <set>         // task 22
#include <map>         // task 23
using namespace std;

//// Task 9 - incorrect as we are using iterator instead of const_iterator
//// incompatible as we are passing in by constant reference
//void printList(const list<int>& aList)  {
//    for (list<int>::iterator iter = aList.begin(); iter != aList.end(); ++iter) {
//        cout << *iter << ' ';
//    }
//    cout << endl;
//}

//// Task 9 - const_iterator
void printList(const list<int>& aList)  {
    for (list<int>::const_iterator  iter = aList.begin(); iter != aList.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;
}

//// Task 10 - ranged for only
void printListRangedFor(list<int>& aList) {
    for (int i : aList) {
        cout << i << ' ';
    }
    cout << endl;
}

//// Task 11 - auto
void autoPrintList(const list<int>& aList) {
    for (auto iter = aList.begin(); iter != aList.end(); ++ ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;
}

//// Task 12
list<int>::const_iterator returnVal(const list<int>& aList, int findThis) {
    for (list<int>::const_iterator  iter = aList.begin(); iter != aList.end(); ++iter) {
        if (*iter == findThis) {
            return iter;
        }
    }
    return aList.end();
}

/// Task 13
auto autoReturnVal(const list<int>& aList, int findThis) {
    for (auto iter = aList.begin(); iter != aList.end(); ++iter) {
        if (*iter == findThis) {
            return iter;
        }
    }
    return aList.end();
}

//// Task 14
bool isEven(int number) {
    return (number & 1) == 0;
}

//// Task 15
class IsEven {
public:
    // overloading the parenthesis operator
    bool operator() (int n) const {
        return (n % 2 == 0);
    }
};

//// Task 19 - non template
list<int>::const_iterator ourFind(list<int>::const_iterator start,
        list<int>::const_iterator stop, int target) {
    for (list<int>::const_iterator pInt = start; pInt != stop; ++pInt) {
        if (*pInt == target) {
            return pInt;
        }
    }
    return stop;
}

//// Task 20 - template
template <typename typeOfIterator, typename findType>
typeOfIterator ourFindT(typeOfIterator start,
                         typeOfIterator stop, findType target) {
    for (typeOfIterator p = start; p != stop; ++p) {
        if (*p == target) {
            return p;
        }
    }
    return stop;
}

int main() {
    // 1. Create a vector with some values and display using ranged for

    vector<int> vecOfInts{76, 14, 28, 3, 84, 5};
    for (int i : vecOfInts) {
        cout << i << ' ';
    }
    cout << endl;
    cout << "Task 1:\n";
    cout << "\n=======\n";

    // 2. Initalize a list as a copy of values from the vector

    cout << "Task 2:\n";
    list<int> listOfInts(vecOfInts.begin(), vecOfInts.end());
    for (int i : listOfInts) {
        cout << i << ' ';
    }
    cout << endl;
    cout << "\n=======\n";

    // 3. Sort the original vector.  Display both the vector and the list
    cout << "Task 3:\n";
    sort(vecOfInts.begin(), vecOfInts.end());

    for (int i : vecOfInts) {
        cout << i << ' ';
    }
    cout << endl;

    for (int i : listOfInts) {
        cout << i << ' ';
    }
    cout << endl;

    cout << "\n=======\n";

    // 4. print every other element of the vector.
    cout << "Task 4:\n";
    for (size_t i = 0; i < vecOfInts.size(); i+=2) {
        cout << vecOfInts[i] << ' ';
    }
    cout << endl;

    cout << "\n=======\n";

    // 5. Attempt to print every other element of the list using the
    //    same technique.
    cout << "Task 5:\n";
////    for (size_t i = 0; i < listOfInts.size(); i+=2) {
////        cout << listOfInts[i] << ' ';
////    }
////    cout << endl;

    cout << "\n=======\n";

    //
    // Iterators
    //

    // 6. Repeat task 4 using iterators.  Do not use auto;
    cout << "Task 6:\n";

    for (vector<int>::iterator iter = vecOfInts.begin(); iter != vecOfInts.end(); iter+=2) {
        cout << *iter << ' ';
    }
    cout << endl;

    cout << "\n=======\n";

    // 7. Repeat the previous task using the list.  Again, do not use auto.
    //    Note that you cannot use the same simple mechanism to bump
    //    the iterator as in task 6.
    cout << "Task 7:\n";
    for (list<int>::iterator iter = listOfInts.begin(); iter != listOfInts.end(); ++ ++iter) {
        cout << *iter << endl;
    }
    cout << endl;


    cout << "\n=======\n";

    // 8. Sorting a list
    cout << "Task 8:\n";
    listOfInts.sort();
    for (int i : listOfInts) {
        cout << i << ' ';
    }
    cout << endl;

    cout << "\n=======\n";

    // 9. Calling the function to print the list
    cout << "Task 9:\n";

    printList(listOfInts);

    cout << "=======\n";

    // 10. Calling the function that prints the list, using ranged-for
    cout << "Task 10:\n";

    printListRangedFor(listOfInts);

    cout << "=======\n";

    //
    // Auto
    //

    // 11. Calling the function that, using auto, prints alterate
    // items in the list
    cout << "Task 11:\n";

    autoPrintList(listOfInts);
    cout << "=======\n";


    // 12.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 12:\n";
    list<int>::const_iterator exists =  returnVal(listOfInts, 14);
    list<int>::const_iterator notExist =  returnVal(listOfInts, 140);
    if (exists != listOfInts.end()) {
        cout << *exists << endl;
    }
    if (notExist != listOfInts.end()) {
        cout << *notExist << endl;
    }
    else {
        cout << "cannot be located" << endl;
    }



    cout << "=======\n";

    // 13.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 13:\n";
    auto exists2 =  autoReturnVal(listOfInts, 14);
    auto notExist2 =  autoReturnVal(listOfInts, 140);
    if (exists != listOfInts.end()) {
        cout << *exists2 << endl;
    }
    if (notExist != listOfInts.end()) {
        cout << *notExist2 << endl;
    }
    else {
        cout << "cannot be located" << endl;
    }

    cout << "=======\n";

    //
    // Generic Algorithms
    //

    // 14. Generic algorithms: find
    cout << "Task 14:\n";
    list<int>::iterator location = find(listOfInts.begin(), listOfInts.end(), 14); // find 14
    list<int>::iterator location2 = find(listOfInts.begin(), listOfInts.end(), 140); // find 140
    if (location != listOfInts.end()) {
        cout << *location << endl;
    }
    if (location2 != listOfInts.end()) {
        cout << *location2 << endl;
    }
    else {
        cout << "cannot be located" << endl;
    }
    cout << "=======\n";

    // 15. Generic algorithms: find_if
    cout << "Task 15:\n";
    list<int>::iterator location3 = find_if(listOfInts.begin(), listOfInts.end(), isEven);
    if (location3 != listOfInts.end()) {
        cout << *location3 << endl;
    }
    else {
        cout << "cannot be located" << endl;
    }
    cout << "=======\n";
    // 16. Functor
    cout << "Task 16:\n";
    list<int>::iterator location4 = find_if(listOfInts.begin(), listOfInts.end(), IsEven());
    if (location4 != listOfInts.end()) {
        cout << *location4 << endl;
    }
    else {
        cout << "cannot be located" << endl;
    }
    cout << "=======\n";
    // 17. Lambda
    cout << "Task 17:\n";
    [] { cout << "Hello Lambda!"; }();
    cout << endl;
    [] (int a, int b) { cout << a + b << endl; } (4, 5);

    int result = [] (int a, int b) { return a + b; } (4, 5);
    cout << "the result is: " << result << endl;

    int result2 = [] (int a, int b) -> int { return a + b; } (4, 5);
    cout << "the result is: " << result2 << endl;

    cout << "=======\n";

    // 18. Generic algorithms: copy to an array
    cout << "Task 18:\n";
    int length = 6;
    int arrayList[length];
    copy(vecOfInts.begin(), vecOfInts.end(), arrayList);
    for (int i = 0; i < length; ++i) {
        cout << *(arrayList+i) << ' ';
    }
    cout << endl;
    cout << "=======\n";

    //
    // Templated Functions
    //

    // 19. Implement find as a function for lists
    cout << "Task 19:\n";
    list<int>::const_iterator location5 = ourFind(listOfInts.begin(), listOfInts.end(), 14); // find 14
    list<int>::const_iterator location6 = ourFind(listOfInts.begin(), listOfInts.end(), 140); // find 140
    if (location5 != listOfInts.end()) {
        cout << *location5 << endl;
    }
    if (location6 != listOfInts.end()) {
        cout << *location6 << endl;
    }
    else {
        cout << "cannot be located" << endl;
    }
    cout << "=======\n";

    // 20. Implement find as a templated function
    cout << "Task 20:\n";
    list<int>::const_iterator location7 = ourFindT(listOfInts.begin(), listOfInts.end(), 14); // find 14
    list<int>::const_iterator location8 = ourFindT(listOfInts.begin(), listOfInts.end(), 140); // find 140
    if (location7 != listOfInts.end()) {
        cout << *location7 << endl;
    }
    if (location8 != listOfInts.end()) {
        cout << *location8 << endl;
    }
    else {
        cout << "cannot be located" << endl;
    }

    cout << "=======\n";

    //
    // Associative collections
    //

    // 21. Using a vector of strings, print a line showing the number
    //     of distinct words and the words themselves.
    cout << "Task 21:\n";
    vector<string>allWords;
    ifstream wordStream;
    wordStream.open("pooh-nopunc.txt");
    string word;
    if (!wordStream) {
        cerr << "could not open file" << endl;
    }
    while (wordStream >> word) {
        auto location9 = find(allWords.begin(), allWords.end(), word);
        if (location9 == allWords.end()) {
            allWords.push_back(word);
        }
    }
    wordStream.close();
    cout << "Number of different words is " << allWords.size() << endl;
    for (size_t i = 0; i < allWords.size(); ++i) {
        cout << allWords[i] << endl;
    }
    cout << "\n=======\n";

    // 22. Repeating previous step, but using the set
    cout << "Task 22:\n";
    set<string>setOfWords;
    wordStream.open("pooh-nopunc.txt");
    if (!wordStream) {
        cerr << "could not open file" << endl;
    }
    while (wordStream >> word) {
        setOfWords.insert(word);
    }
    wordStream.close();
    cout << "Number of different words is " << setOfWords.size() << endl;
    for (const string& text: setOfWords) {
        cout << text << endl;
    }
    cout << "=======\n";

    // 23. Word co-occurence using map
    cout << "Task 23:\n";
    map<string, vector<int>> wordMap;
    size_t index = 0;
    wordStream.open("pooh-nopunc.txt");
    if (!wordStream) {
        cerr << "could not open file" << endl;
    }
    while (wordStream >> word) {
        wordMap[word].push_back(index);
        ++index;
    }
    wordStream.close();

    for(const auto& textKey : wordMap) {
        cout << textKey.first << ": ";
        for (int ind : textKey.second) {
            cout << ind << ' ';
        }
        cout << endl;
    }
    cout << "=======\n";
}
