//
// Satyen Singh
// rec 09
// CS 2024
//

#include <iostream>

// Task 2
//using namespace std;
//
//class PrintedMaterial {
//public:
//protected:
//private:
//    unsigned numOfPages;
//};
//
//class Magazine : public PrintedMaterial {
//public:
//protected:
//private:
//    unsigned numOfPages;
//};
//
//class Book : public PrintedMaterial {
//public:
//protected:
//private:
//    unsigned numOfPages;
//};
//
//class TextBook : public Book {
//public:
//protected:
//private:
//    unsigned numOfPages;
//};
//
//class Novel : public Book {
//public:
//protected:
//private:
//    unsigned numOfPages;
//};

// Task 3
//using namespace std;
//
//class PrintedMaterial {
//public:
//
//protected:
//private:
//    unsigned numOfPages;
//};
//
//class Magazine : public PrintedMaterial {
//public:
//protected:
//private:
//
//};
//
//class Book : public PrintedMaterial {
//public:
//protected:
//private:
//
//};
//
//class TextBook : public Book {
//public:
//protected:
//private:
//
//};
//
//class Novel : public Book {
//public:
//protected:
//private:
//
//};

//Task 4
//using namespace std;
//
//class PrintedMaterial {
//public:
//    PrintedMaterial(unsigned pages) : numOfPages(pages) {}
//protected:
//private:
//    unsigned numOfPages;
//};
//
//class Magazine : public PrintedMaterial {
//public:
//
//protected:
//private:
//
//};
//
//class Book : public PrintedMaterial {
//public:
//protected:
//private:
//
//};
//
//class TextBook : public Book {
//public:
//protected:
//private:
//
//};
//
//class Novel : public Book {
//public:
//protected:
//private:
//
//};

// Task 5
//using namespace std;
//
//class PrintedMaterial {
//public:
//    PrintedMaterial(unsigned pages) : numOfPages(pages) {}
//protected:
//private:
//    unsigned numOfPages;
//};
//
//class Magazine : public PrintedMaterial {
//public:
//    Magazine(unsigned pages) : PrintedMaterial(pages) {}
//protected:
//private:
//
//};
//
//class Book : public PrintedMaterial {
//public:
//    Book(unsigned pages) : PrintedMaterial(pages) {}
//protected:
//private:
//
//};
//
//class TextBook : public Book {
//public:
//    TextBook(unsigned pages) : Book(pages) {}
//protected:
//private:
//
//};
//
//class Novel : public Book {
//public:
//    Novel(unsigned pages) : Book(pages) {}
//protected:
//private:
//
//};

//task 6
//

//using namespace std;
//
//class PrintedMaterial {
//public:
////    PrintedMaterial(unsigned pages) : numOfPages(pages) {}
//protected:
//    void displayNumPages() const {
//        cout << numOfPages;
//    }
//
//private:
//    unsigned numOfPages;
//};
//
//class Magazine : public PrintedMaterial {
//public:
////    Magazine(unsigned pages) : PrintedMaterial(pages) {}
//protected:
//private:
//
//};
//
//class Book : public PrintedMaterial {
//public:
////    Book(unsigned pages) : PrintedMaterial(pages) {}
//protected:
//private:
//
//};
//
//class TextBook : public Book {
//public:
////    TextBook(unsigned pages) : Book(pages) {}
//protected:
//private:
//
//};
//
//class Novel : public Book {
//public:
////    Novel(unsigned pages) : Book(pages) {}
//protected:
//private:
//
//};

//task 7
//#include <iostream>
//using namespace std;
//
//class PrintedMaterial {
//public:
//    PrintedMaterial( unsigned numPages )
//            : numOfPages(numPages)
//    {}
//    void displayNumPages() const
//    { cout << numOfPages; }
//protected:
//private:
//    unsigned numOfPages;
//};
//
//class Magazine : public PrintedMaterial {
//public:
//    Magazine( unsigned numPages )
//            : PrintedMaterial(numPages)
//    {}
//protected:
//private:
//};
//
//class Book : public PrintedMaterial {
//public:
//    Book( unsigned numPages )
//            : PrintedMaterial(numPages)
//    {}
//protected:
//private:
//};
//
//class TextBook : public Book {
//public:
//    TextBook( unsigned numPages, unsigned numIndxPgs  )
//            : Book(numPages),
//              numOfIndexPages(numIndxPgs)
//    {}
//    void displayNumPages() const
//    {
//        cout << numOfIndexPages << endl;
//        cout << numOfPages;
//    }
//protected:
//private:
//    unsigned numOfIndexPages;
//};
//
//class Novel : public Book {
//public:
//    Novel( unsigned numPages )
//            : Book(numPages)
//    {}
//protected:
//private:
//};
//
//// tester/modeler code
//int main()
//{
//    TextBook t(5430, 234);
//    Novel n(213);
//    Magazine m(6);
//
//    t.displayNumPages();
//    n.displayNumPages();
//    m.displayNumPages();
//}

//// The mistake here is that in the Textbook class, numOfPages is trying to be accessed which is
//// a private memeber of Printed Material. If we want to have access to numOfPages, we should make it a
/// a protected field.

//task 8
//#include <iostream>
//using namespace std;
//
//class PrintedMaterial {
//public:
//    PrintedMaterial( unsigned numPages )
//            : numOfPages(numPages)
//    {}
//    void displayNumPages() const
//    { cout << numOfPages; }
//protected:
//private:
//    unsigned numOfPages;
//};
//
//class Magazine : public PrintedMaterial {
//public:
//    Magazine( unsigned numPages )
//            : PrintedMaterial(numPages)
//    {}
//protected:
//private:
//};
//
//class Book : public PrintedMaterial {
//public:
//    Book( unsigned numPages )
//            : PrintedMaterial(numPages)
//    {}
//protected:
//private:
//};
//
//class TextBook : public Book {
//public:
//    TextBook( unsigned numPages, unsigned numIndxPgs  )
//            : Book(numPages),
//              numOfIndexPages(numIndxPgs)
//    {}
//    void displayNumPages() const
//    {
//        cout << "Pages: ";
//        cout << numOfIndexPages << endl;
//        PrintedMaterial::displayNumPages();
//        cout << "Index Pages: ";
//        cout << numOfIndexPages << endl;
//    }
//protected:
//private:
//    unsigned numOfIndexPages;
//};
//
//class Novel : public Book {
//public:
//    Novel( unsigned numPages )
//            : Book(numPages)
//    {}
//protected:
//private:
//};
//
//// tester/modeler code
//int main()
//{
//    TextBook t(5430, 234);
//    Novel n(213);
//    Magazine m(6);
//
//    t.displayNumPages();
//    n.displayNumPages();
//    m.displayNumPages();
//}


// task 9
//#include <iostream>
//using namespace std;
//
//class PrintedMaterial {
//public:
//    PrintedMaterial( unsigned numPages )
//            : numOfPages(numPages)
//    {}
//    void displayNumPages() const
//    { cout << numOfPages; }
//protected:
//private:
//    unsigned numOfPages;
//};
//
//class Magazine : public PrintedMaterial {
//public:
//    Magazine( unsigned numPages )
//            : PrintedMaterial(numPages)
//    {}
//protected:
//private:
//};
//
//class Book : public PrintedMaterial {
//public:
//    Book( unsigned numPages )
//            : PrintedMaterial(numPages)
//    {}
//protected:
//private:
//};
//
//class TextBook : public Book {
//public:
//    TextBook( unsigned numPages, unsigned numIndxPgs  )
//            : Book(numPages),
//              numOfIndexPages(numIndxPgs)
//    {}
//    void displayNumPages() const
//    {
//        cout << "Pages: ";
//        cout << numOfIndexPages << endl;
//        PrintedMaterial::displayNumPages();
//        cout << "Index Pages: ";
//        cout << numOfIndexPages << endl;
//    }
//protected:
//private:
//    unsigned numOfIndexPages;
//};
//
//class Novel : public Book {
//public:
//    Novel( unsigned numPages )
//            : Book(numPages)
//    {}
//protected:
//private:
//};
//
//// tester/modeler code
//int main()
//{
//    TextBook t(5430, 234);
//    Novel n(213);
//    Magazine m(6);
//
//    t.displayNumPages();
//    n.displayNumPages();
//    m.displayNumPages();
//
//    PrintedMaterial pm = t;
//    pm.displayNumPages();
//}

// task 10
//#include <iostream>
//using namespace std;
//
//class PrintedMaterial {
//public:
//    PrintedMaterial( unsigned numPages )
//            : numOfPages(numPages)
//    {}
//    void displayNumPages() const
//    { cout << numOfPages; }
//protected:
//private:
//    unsigned numOfPages;
//};
//
//class Magazine : public PrintedMaterial {
//public:
//    Magazine( unsigned numPages )
//            : PrintedMaterial(numPages)
//    {}
//protected:
//private:
//};
//
//class Book : public PrintedMaterial {
//public:
//    Book( unsigned numPages )
//            : PrintedMaterial(numPages)
//    {}
//protected:
//private:
//};
//
//class TextBook : public Book {
//public:
//    TextBook( unsigned numPages, unsigned numIndxPgs  )
//            : Book(numPages),
//              numOfIndexPages(numIndxPgs)
//    {}
//    void displayNumPages() const
//    {
//        cout << "Pages: ";
//        cout << numOfIndexPages << endl;
//        PrintedMaterial::displayNumPages();
//        cout << "Index Pages: ";
//        cout << numOfIndexPages << endl;
//    }
//protected:
//private:
//    unsigned numOfIndexPages;
//};
//
//class Novel : public Book {
//public:
//    Novel( unsigned numPages )
//            : Book(numPages)
//    {}
//protected:
//private:
//};
//
//// tester/modeler code
//int main()
//{
//    TextBook t(5430, 234);
//    Novel n(213);
//    Magazine m(6);
//
//    t.displayNumPages();
//    n.displayNumPages();
//    m.displayNumPages();
//
//    PrintedMaterial* pmPtr;
//    pmPtr = &t;
//// instead of putting an actual PrintedMaterial
//// object into the vector, we put a pointer to
//// a PrintedMaterial object (t) into a vector
//// of pointers-to-PrintedMaterial
//// (that is, pointers to the Base class)
//// we'll be "managing" our objects by using
//// pointers to PrintedMaterial values.
//
//    pmPtr->displayNumPages();
//
////    PrintedMaterial pm = t;
////    pm.displayNumPages();
//}

// task 11
//using namespace std;
//
//class PrintedMaterial {
//public:
//    PrintedMaterial( unsigned numPages )
//            : numOfPages(numPages)
//    {}
//    virtual void displayNumPages() const
//    { cout << numOfPages; }
//
//
//protected:
//private:
//    unsigned numOfPages;
//};
//
//class Magazine : public PrintedMaterial {
//public:
//    Magazine( unsigned numPages )
//            : PrintedMaterial(numPages)
//    {}
//protected:
//private:
//};
//
//class Book : public PrintedMaterial {
//public:
//    Book( unsigned numPages )
//            : PrintedMaterial(numPages)
//    {}
//protected:
//private:
//};
//
//class TextBook : public Book {
//public:
//    TextBook( unsigned numPages, unsigned numIndxPgs  )
//            : Book(numPages),
//              numOfIndexPages(numIndxPgs)
//    {}
//    void displayNumPages() const
//    {
//        cout << "Pages: ";
//        cout << numOfIndexPages << endl;
//        PrintedMaterial::displayNumPages();
//        cout << "Index Pages: ";
//        cout << numOfIndexPages << endl;
//    }
//protected:
//private:
//    unsigned numOfIndexPages;
//};
//
//class Novel : public Book {
//public:
//    Novel( unsigned numPages )
//            : Book(numPages)
//    {}
//protected:
//private:
//};
//
//void displayNumberOfPages(const PrintedMaterial& aPM) {
//    aPM.displayNumPages();
//}
//
//// tester/modeler code
//int main() {
//    TextBook t(5430, 23);
//    Novel n(213);
//    Magazine m(6);
//
//    t.displayNumPages();
//    n.displayNumPages();
//    m.displayNumPages();
//
//    cout << "\nA PrintedMaterial material object!\n";
//    PrintedMaterial pm(2345);
//    pm.displayNumPages();
//
//    pm = t; // like putting a t into a vector of PrintedMaterials
//    pm.displayNumPages();
//
//    cout << "\nUsing PrintedMaterial* to \"store\" a TextBook object\n";
//    cout << "Now with the virtual mechanism involved\n";
//    // should work now that the virtual mechanism is being invoked
//    PrintedMaterial *pmPtr;
//    pmPtr = &t; // like putting t into a vector but
//    // we are actually putting the address of t
//    // into a vector pointers of pointers to
//    // PrintedMaterials. We'll "say" we are putting
//    pmPtr->displayNumPages();
//
//    // print some stuff by calling a generic function
//    cout << "\nUse a generic functino for printing\n";
//    displayNumberOfPages(m);
//    displayNumberOfPages(n);
//    displayNumberOfPages(t);
//}



// task 12
//#include <iostream>
//using namespace std;
//
//class PrintedMaterial {
//public:
//    PrintedMaterial( unsigned numPages )
//            : numOfPages(numPages)
//    {}
//    virtual void displayNumPages() const {
//    cout <<< numOfPages << endl;
//}

//
//
//protected:
//private:
//    unsigned numOfPages;
//};
//
//class Magazine : public PrintedMaterial {
//public:
//    Magazine( unsigned numPages )
//            : PrintedMaterial(numPages)
//    {}
//protected:
//private:
//};
//
//class Book : public PrintedMaterial {
//public:
//    Book( unsigned numPages )
//            : PrintedMaterial(numPages)
//    {}
//protected:
//private:
//};
//
//class TextBook : public Book {
//public:
//    TextBook( unsigned numPages, unsigned numIndxPgs  )
//            : Book(numPages),
//              numOfIndexPages(numIndxPgs)
//    {}
//    void displayNumPages() const
//    {
//        cout << "Pages: ";
//        cout << numOfIndexPages << endl;
//        PrintedMaterial::displayNumPages();
//        cout << "Index Pages: ";
//        cout << numOfIndexPages << endl;
//    }
//protected:
//private:
//    unsigned numOfIndexPages;
//};
//
//class Novel : public Book {
//public:
//    Novel( unsigned numPages )
//            : Book(numPages)
//    {}
//protected:
//private:
//};
//
//void displayNumberOfPages(const PrintedMaterial& aPM) {
//    aPM.displayNumPages();
//}
//
//// tester/modeler code
//
//int main() {
//    TextBook t(5430, 23);
//    Novel n(213);
//    Magazine m(6);
//
//    t.displayNumPages();
//    n.displayNumPages();
//    m.displayNumPages();
//
//    cout << "\nA PrintedMaterial material object!\n";
//    PrintedMaterial pm(2345);
//    pm.displayNumPages();
//
//    pm = t; // like putting a t into a vector of PrintedMaterials
//    pm.displayNumPages();
//
//    cout << "\nUsing PrintedMaterial* to \"store\" a TextBook object\n";
//    cout << "Now with the virtual mechanism involved\n";
//    // should work now that the virtual mechanism is being invoked
//    PrintedMaterial *pmPtr;
//    pmPtr = &t; // like putting t into a vector but
//    // we are actually putting the address of t
//    // into a vector pointers of pointers to
//    // PrintedMaterials. We'll "say" we are putting
//    pmPtr->displayNumPages();
//
//    // print some stuff by calling a generic function
//    cout << "\nUse a generic functino for printing\n";
//    displayNumberOfPages(m);
//    displayNumberOfPages(n);
//    displayNumberOfPages(t);
//}




//task 13
//#include <iostream>
//#include <iostream>
//using namespace std;
//
//class PrintedMaterial {
//public:
//    PrintedMaterial( unsigned numPages )
//            : numOfPages(numPages)
//    {}
//    virtual void displayNumPages() const = 0;
//
//
//protected:
//private:
//    unsigned numOfPages;
//};
//
//class Magazine : public PrintedMaterial {
//public:
//    Magazine( unsigned numPages )
//            : PrintedMaterial(numPages)
//    {}
//protected:
//private:
//};
//
//class Book : public PrintedMaterial {
//public:
//    Book( unsigned numPages )
//            : PrintedMaterial(numPages)
//    {}
//protected:
//private:
//};
//
//class TextBook : public Book {
//public:
//    TextBook( unsigned numPages, unsigned numIndxPgs  )
//            : Book(numPages),
//              numOfIndexPages(numIndxPgs)
//    {}
//    void displayNumPages() const
//    {
//        cout << "Pages: ";
//        cout << numOfIndexPages << endl;
//        PrintedMaterial::displayNumPages();
//        cout << "Index Pages: ";
//        cout << numOfIndexPages << endl;
//    }
//protected:
//private:
//    unsigned numOfIndexPages;
//};
//
//class Novel : public Book {
//public:
//    Novel( unsigned numPages )
//            : Book(numPages)
//    {}
//protected:
//private:
//};
//
//void displayNumberOfPages(const PrintedMaterial& aPM) {
//    aPM.displayNumPages();
//}
//
//// tester/modeler code
//
//int main() {
//    TextBook t(5430, 23);
//    Novel n(213);
//    Magazine m(6);
//
//    t.displayNumPages();
//    n.displayNumPages();
//    m.displayNumPages();
//
//    cout << "\nA PrintedMaterial material object!\n";
//    PrintedMaterial pm(2345);
//    pm.displayNumPages();
//
//    pm = t; // like putting a t into a vector of PrintedMaterials
//    pm.displayNumPages();
//
//    cout << "\nUsing PrintedMaterial* to \"store\" a TextBook object\n";
//    cout << "Now with the virtual mechanism involved\n";
//    // should work now that the virtual mechanism is being invoked
//    PrintedMaterial* pmPtr;
//    pmPtr = &t; // like putting t into a vector but
//    // we are actually putting the address of t
//    // into a vector pointers of pointers to
//    // PrintedMaterials. We'll "say" we are putting
//    pmPtr->displayNumPages();
//
//    // print some stuff by calling a generic function
//    cout << "\nUse a generic functino for printing\n";
//    displayNumberOfPages(m);
//    displayNumberOfPages(n);
//    displayNumberOfPages(t);
//}





//task 14
#include <iostream>
#include <vector>
//using namespace std;
//
//class PrintedMaterial {
//public:
//    PrintedMaterial(unsigned numPages) : numOfPages(numPages) {}
//
//    virtual void displayNumPages() const = 0;
//
//protected:
//private:
//    unsigned numOfPages;
//};
//
//void PrintedMaterial::displayNumPages() const {
//    cout << numOfPages << endl;
//}
//
//class Magazine : public PrintedMaterial {
//public:
//    Magazine(unsigned numPages) : PrintedMaterial(numPages) {}
//
//    void displayNumPages() const
//    {
//        cout << "Hi, I'm a Magazine object stored " << endl
//             << "(but I can't know that I am being" << endl
//             << "stored (by pointer) in a vector of" << endl
//             << "PrintedMaterial pointers!" << endl;
//        PrintedMaterial::displayNumPages();
//        cout << "(and I'm very glossy!" << endl;
//    }
//
//protected:
//private:
//};
//
//class Book : public PrintedMaterial {
//public:
//    Book(unsigned numPages) : PrintedMaterial(numPages) {}
//protected:
//private:
//};
//
//class TextBook : public Book {
//public:
//    TextBook(unsigned numPages, unsigned numIndxPgs ) : Book(numPages), numOfIndexPages(numIndxPgs) {}
//
//    void displayNumPages() const
//    {
//        PrintedMaterial::displayNumPages();
//        cout << numOfIndexPages << endl;
//    }
//protected:
//private:
//    unsigned numOfIndexPages;
//};
//
//class Novel : public Book {
//public:
//    Novel( unsigned numPages )
//            : Book(numPages)
//    {}
//    void displayNumPages() const
//    {
//        PrintedMaterial::displayNumPages();
//
//    }
//protected:
//private:
//};
//
//
//// tester/modeler code
//int main()
//{
//    TextBook t(5430, 23);
//    Novel n(213);
//    Magazine m(6);
//
//    t.displayNumPages();
//    n.displayNumPages();
//    m.displayNumPages();
//
//    cout << "\nUsing PrintedMaterial* to \"store\" a TextBook object\n";
//    cout << "Now with the virtual mechanism involved\n";
//    PrintedMaterial* pmPtr;
//    pmPtr = &t; // like putting t into a vector but
//    // we are actually putting the address of t
//    // into a vector pointers of pointers to
//    // PrintedMaterials. We'll "say" we are putting
//    // t into the vector
//    // (that is, pointers to the Base class)
//    pmPtr->displayNumPages();
//

//}




//task 15
#include <iostream>
#include <vector>
using namespace std;

class PrintedMaterial {
public:
    PrintedMaterial(unsigned numPages) : numOfPages(numPages) {}

    virtual void displayNumPages() const = 0;

protected:
private:
    unsigned numOfPages;
};

void PrintedMaterial::displayNumPages() const {
    cout << numOfPages << endl;
}

class Magazine : public PrintedMaterial {
public:
    Magazine(unsigned numPages) : PrintedMaterial(numPages) {}

    void displayNumPages() const
    {
        PrintedMaterial::displayNumPages();

    }

protected:
private:
};

class Book : public PrintedMaterial {
public:
    Book(unsigned numPages) : PrintedMaterial(numPages) {}
protected:
private:
};

class TextBook : public Book {
public:
    TextBook(unsigned numPages, unsigned numIndxPgs ) : Book(numPages), numOfIndexPages(numIndxPgs) {}

    void displayNumPages() const
    {
        PrintedMaterial::displayNumPages();
        cout << numOfIndexPages << endl;
    }
protected:
private:
    unsigned numOfIndexPages;
};

class Novel : public Book {
public:
    Novel( unsigned numPages )
            : Book(numPages)
    {}
    void displayNumPages() const
    {
        PrintedMaterial::displayNumPages();

    }
protected:
private:
};

int main()
{
    TextBook t(5430, 23);
    Novel n(213);
    Magazine m(6);

    // as direct method calls
    cout << "\nEach will now be asked directly,\n"
         << "using the dot member operator to\n"
         << "display its number of pages:\n";
    t.displayNumPages();
    n.displayNumPages();
    m.displayNumPages();

    // Storing generic objects in a vector
    cout << "\n\nNow we'll use a container. Yea!!!\n\n";
    vector< PrintedMaterial* > Materials;
    Materials.push_back(&t);
    Materials.push_back(&n);
    Materials.push_back(&m);
    for( size_t i = 0; i < Materials.size(); ++i )
    {
        Materials[i]->displayNumPages();
        cout << endl;
    }
}





