// Isaiah Aquino
// Exam 3
// Due: 6/5/2024

// All members worked together collectively via zoom.

#include <iostream> 
#include <vector> 
#include <algorithm>
#include <list>
#include <stack> 
#include <queue> 
#include <string> 
#include "Rational.h"
#include "input.h"
using namespace std; 

// Prototypes for menus.
void vectorMenu();
    void printVector(vector <Rational>& rationalVector, int i);
    void addToVector(vector<Rational>& rationalVector);
    void insertToVector(vector<Rational>& rationalVector);
    void retrieveFromVector(vector<Rational>& rationalVector, Rational& object);
    void eraseFromVector(vector < Rational>& rationalVector);

void listMenu(); 
    void printList(list<Rational>& obj, list<Rational>::iterator begin);
    void addToList(list<Rational>& rationalList, Rational& object);
    void insertToList(list<Rational>& rationalList);
    void retrieveFromList(list<Rational>& rationalList, Rational& object);
    void removeFromList(list<Rational>& rationalList);

void stackMenu(); 
    void printStack(stack <Rational>& obj);

void queueMenu(); 
    void printQueue(queue<Rational>& original, queue<Rational>& temp);

// Menu return prototypes
char mainMenuOption();
int vectorMenuOption();
int listMenuOption(); 
int stackMenuOption();
int queueMenuOption(); 


// Precondition: Char function named mainMenuOption
// Postcondition: Returns a char input.
char mainMenuOption()
{
      // Display the objective of the exam
      system("cls");
      cout << "\tA container is a holder object that stores a collection of other objects (its elements). They";
      cout << "\n\tare implemented as class templates, which allows great flexibility in the types supported as ";
      cout << "\n\telements. The container manages the storage space for its elements and provides member functions";
      cout << "\n\tto access them, either directly or through iterators (reference objects with similar properties";
      cout << "\n\tto pointers).";
      cout << endl;

      // Display the menu
      cout << "\n\tCMPR121 Exam3: STL (Standard Template Library) Containers & Container Adaptors by Isaiah, Isaac, Mario";
      cout << "\n\t" << string(102, '=');
      cout << "\n\t\033[31mV. Vector Container ";
      cout << "\n\t\033[93mL. List Container";
      cout << "\n\t\033[94mS. Stack (LIFO) Container Adaptor";
      cout << "\n\t\033[32mQ. Queue (FIFO) Container Adaptor";
      cout << "\n\t\033[0m" << string(102, '-');
      cout << "\n\t\033[0mX. Exit";
      cout << "\n\t" << string(102, '=') << "\n";

      // Prompt the user to enter an option
      char option = inputChar("\tOption: ", static_cast<string> ("VLSQX"));
      return option; 
}

int main()
{
   do
   { 
       switch (toupper(mainMenuOption()))
       {
       case 'V':  vectorMenu(); break;
       case 'L':  listMenu();   break;
       case 'S':  stackMenu();  break;
       case 'Q':  queueMenu();  break; 
       case 'X':  return 0;     break;
       }
       system("pause");
   } while (true);
}

// Precondition: void function named printVector, accepts the vector object and int argument.
// Postcondition: Utilized recursion to print the contents of the vector
void printVector(vector <Rational>& object, int i)
{
    // Base case #1 (check empty)
    if (object.size() == 0)
    {
        cout << "The current vector is empty. ";
        return; 
    }
    // Base case #2 (check if at last index)
    if (i == object.size())
    {
        return;
    }
    // Print
    cout << "\t" << object[i] << " ";
    i++;
    // Recursive call
    printVector(object, i);  
}

// Precondition: Int function named vectorMenuOption
// Postcondition: Returns an integer based on user input
int vectorMenuOption()
{
    // Print the menu
    cout << "\n\n\t\tVector (list array) Menu Option";
    cout << "\n\t" << string(102, '=');
    cout << "\n\t\t1. Add An Element";
    cout << "\n\t\t2. Insert An Element At Index";
    cout << "\n\t\t3. Retrieve An Element From Index";
    cout << "\n\t\t4. Erase Element(s)";
    cout << "\n\t\t5. Sort the vector elements in ascending order";
    cout << "\n\t\t6. Clear all elements";
    cout << "\n\t" << string(102, '-');
    cout << "\n\t\t0. Return";
    cout << "\n\t" << string(102, '=') << "\n";
    // Prompt the user to enter an option
    int option = inputInteger("\t\tOption: ", 0, 6);
    return option; 
}

// Precondition: Void Function named addToVector, accepts a vector of rational objects
// Postcondition: Adds a user inputted value into the vector
void addToVector(vector<Rational> & rationalVector)
{
    // Prompt the user to enter a value for numerator and denominator
    cout << "\n\t\tInput a Rational number [numerator/denominator] to be added...";
    int numerator = inputInteger("\n\t\t\tEnter a value (-99...99) for the numerator  : ", -99, 99);
    int denominator = inputInteger("\t\t\tEnter a value (-99...99) for the denominator: ", -99, 99);
    // Try and catch in case the user enters 0 as a denominator value
    try
    {
        // Pass the user entered information to the class constructor
        Rational test(numerator, denominator);
        // Push the value into the vector.
        rationalVector.push_back(test);
        // Display the value that is being inserted.
        cout << "\n\t\t" << test << " will be added to the front of the vector.\n";

    }
    catch (Rational::DivideByZero)
    {
        // Display the error message if 0 is entered
        cout << "\n\t\tEXCEPTIONAL ERROR: Cannot add a Rational number, " << numerator << "/0" << ", that contains a zero denominator value.\n\n";
    }
}

// Precondition: Void Function named insertToVector, accepts a vector of rational objects
// Postcondition: Inserts a user inputted value into the vector at a specified index
void insertToVector(vector<Rational>& rationalVector)
{
    // Prompt the user to enter a numerator and denominator
    cout << "\n\t\tInput a Rational number [numerator/denominator] to be inserted...";
    int numerator = inputInteger("\n\t\t\tEnter a value (-99...99) for the numerator  : ", -99, 99);
    int denominator = inputInteger("\t\t\tEnter a value (-99...99) for the denominator: ", -99, 99);

    if (rationalVector.empty())
    {
        try
        {
            // Pass the user entered information into the class constructor
            Rational test(numerator, denominator);
            auto iter = rationalVector.begin();
            // Insert the value into the vector passing in the iterator and rational object.
            rationalVector.insert(iter, test);

            cout << "\n\t\t" << test << " will be inserted at index 0 to the vector. \n";
        }
        catch (Rational::DivideByZero)
        {
            // Display the error message if 0 is entered.
            cout << "\n\t\tEXCEPTIONAL ERROR: Cannot add a Rational number, " << numerator << "/0" << ", that contains a zero denominator value.\n\n";
        }
    }
    else
    {
        // Create the prompt
        string prompt = "\n\t\tInsert the Rational number at index (0..." + to_string(rationalVector.size() - 1) + ") of the vector: ";
        // Identify the size
        int size = rationalVector.size();
        try
        {
            // Pass the user entered information into the class constructor
            Rational test(numerator, denominator);
            // Create the index and prompt the user to enter where they want the index to be inserted.
            int index = inputInteger(prompt, 0, (size - 1));
            // Create an iterator to find the index of insertion
            auto iter = rationalVector.begin() + index;
            // Insert the value into the vector passing in the iterator and rational object.
            rationalVector.insert(iter, test);

            cout << "\n\t\t" << test << " will be inserted at index " << index << " to the vector. \n";
        }
        catch (Rational::DivideByZero)
        {
            // Display the error message if 0 is entered.
            cout << "\n\t\tEXCEPTIONAL ERROR: Cannot add a Rational number, " << numerator << "/0" << ", that contains a zero denominator value.\n\n";
        }
    }
}

// Precondition: Void Function named retrieveFromVector, accepts a vector of rational objects and a Rational class object
// Postcondition: Retrieves a user inputted value based on index from the vector and displays a memory address
void retrieveFromVector(vector<Rational>& rationalVector, Rational& object)
{
    if (rationalVector.empty())
    {
        cout << "\n\t\tERROR: Retrieve operation cannot be performed from an empty vector. \n";
    }
    else
    {
        try
        {
            int index = inputInteger("\n\t\tEnter an index of the Rational number from the vector to be retrieved: ");

            //throws exception if out of bounds
            object.checkBounds(index, rationalVector.size());

            cout << "\n\t\t" << rationalVector[index] << " is located at index(" << index << ") from the vector.";
            cout << "\n\t\tMemory address of item: " << &rationalVector[index] << "\n";

        }
        catch (Rational::InvalidSubscript)
        {
            cout << "\n\t\tEXCEPTIONAL ERROR: invalid vector subscript. \n";
        }
    }
}

// Precondition: Void Function named addToVector, accepts a vector of rational objects
// Postcondition: Erases a user inputted value from the vector
void eraseFromVector(vector < Rational>& rationalVector)
{
    if (rationalVector.empty())
    {
        cout << "\n\t\tERROR: Erase operation cannot be performed on an empty vector. \n";
    }
    else
    {
        // Prompt the user to enter values for the numerator and denominator to remove. 
        cout << "\n\t\tInput a Rational number [numerator/denominator] to be removed...";
        int numerator = inputInteger("\n\t\t\tEnter a value (-99...99) for the numerator  : ", -99, 99);
        int denominator = inputInteger("\t\t\tEnter a value (-99...99) for the denominator: ", -99, 99);
        char userChoice = ' ';

        try
        {
            // Put the user information into the class
            Rational toDelete(numerator, denominator);
            // For loop to cycle through the vector contents, if the value is found prompt the user to enter a char based on 
            // if they want to delete 1 or all instances of the value.
            for (int i = 0; i < rationalVector.size(); i++)
            {
                if (rationalVector[i] == toDelete)
                {
                    userChoice = toupper(inputChar("\n\tDo you want to remove (O-one or A-all) element(s): ", static_cast <string> ("OA")));
                    break;
                }
            }

            if (userChoice == 'O' || userChoice == 'A')
            {
                switch (userChoice)
                {
                case 'O': //only deletes one item
                {
                    // Cycle through the vector.
                    for (auto it = rationalVector.begin(); it != rationalVector.end(); it++)
                    {
                        // If the iterator matches the value to delete, delete 1 element and return/break out.
                        if ((*it) == toDelete)
                        {
                            rationalVector.erase(it);
                            break;
                        }
                    }
                }
                break;
                case 'A': //deletes all items
                {
                    // Cylce through the vector
                    for (auto iterator = rationalVector.begin(); iterator != rationalVector.end();)
                    {
                        // If found delete instance, continue, and increment through the vector checking all indexes. 
                        if ((*iterator) == toDelete)
                        {
                            iterator = rationalVector.erase(iterator);
                            continue;
                        }
                        iterator++;
                    }
                }
                break;
                }
            }
            else
            {
                // Else display that the value isn't in the vector
                cout << "\n\t\t" << toDelete << " cannot be found from the vector. \n";
            }
        }
        catch (Rational::DivideByZero)
        {
            // Display the error message if 0 is entered.
            cout << "\n\t\tEXCEPTIONAL ERROR: Cannot remove the Rational number, [" << numerator << "/0]" << ", that contains a zero denominator value.\n\n";
        }
    }
}

void vectorMenu()
{
    // Declare vector as well as rational object.
    vector<Rational> rationalVector;
    Rational object; 
    do
    {
        // Prompt the purpose of the vector
        system("cls");
        cout << "\n\tVectors (array) are same as dynamic arrays with the ability to resize itself automatically";
        cout << "\n\twhen an element is inserted or deleted, that contains their storage being handled automatically";
        cout << "\n\tby the container. Vector elements are placed in contiguous storage so that they can be accessed";
        cout << "\n\tand traversed using iterators or indexes. \n\n";

        // Display the contents of vector if size is not equal to 0.
        if (!rationalVector.empty())
        {
            cout << "\tThe current vector contains " << rationalVector.size() << " element(s): \n\n";
        }

        // Make space in the output display and print the contents of the vector if any
        cout << "\t";
        printVector(rationalVector, 0);
        cout << "\n\n";
        
        // Display the index of the vector as well as starting address if the size is not equal to 0.
        
        if (!rationalVector.empty())
        {
            cout << "\n\tIndex:   ";
            for (int i = 0; i < rationalVector.size(); i++)
                cout << i << "\t  ";
            cout << "\n\tStarting Address: " << &(rationalVector[0]);
        }

        switch ((vectorMenuOption()))
        {
        case 1: addToVector(rationalVector);  break;
        case 2: insertToVector(rationalVector);  break;
        case 3: retrieveFromVector(rationalVector, object);  break;
        case 4: eraseFromVector(rationalVector);  break;
        case 5:
        {
            // Check if the size is 0, if it is display the error message. Else, sort the vector.
            if (rationalVector.empty())
                cout << "\n\t\tERROR: Sort operation cannot be performed on an empty vector. \n";
            else
            {
                sort(rationalVector.begin(), rationalVector.end());
                cout << "\n\t\tThe vector of Rational numbers will be sorted in ascending order. \n";
            }
        }
        break;
        case 6:
        {
            // Check if the size is 0, if it is display the error message. Else, clear the vector.
            if (rationalVector.empty())
                cout << "\n\t\tERROR: Clear operation cannot be performed on an empty vector. \n";
            else
            {
                rationalVector.clear();
                cout << "\n\t\tThe vector will be cleared of all Rational elements. \n";
            }
        }   
        break;
        case 0: return;

        } // end of switch
        system("pause");
    } while (true);
}

// Precondition: Void function named printList, accepts a list of rational objects, and a list of rational iterator. 
// Postcondition: Utilizes recursion to print a list
void printList(list<Rational>& obj, list<Rational>::iterator begin)
{
    // Base case
    if (begin == obj.end()) 
    {
        return;
    }
    // Print and recursive call
    cout << *begin << "    ";
    printList(obj, ++begin);
}

// Precondition: Int function named listMenuOption
// Postcondition: Returns an integer based on user input.
int listMenuOption()
{
    cout << "\n\n";
    cout << "\n\t\tLinked List Menu Options";
    cout << "\n\t" << string(102, '=');
    cout << "\n\t\t1. Add (Push) An Element ";
    cout << "\n\t\t2. Insert An Element After ";
    cout << "\n\t\t3. Find An Element ";
    cout << "\n\t\t4. Remove Element(s) ";
    cout << "\n\t\t5. Sort The Elements In Ascending Order ";
    cout << "\n\t\t6. Clear all elements";
    cout << "\n\t" << string(102, '-');
    cout << "\n\t\t0. Return";
    cout << "\n\t" << string(102, '=') << "\n";
    int option = inputInteger("\t\tOption: ", 0, 6);
    return option; 
}

// Precondition: Void function named addToList, accepts a list of rational objects and a Rational class object.
// Postcondition: Adds an element to the list based on user input
void addToList(list<Rational>& rationalList, Rational& object)
{
    cout << "\n\t\tInput a Rational number [numerator/denominator] to be added...";
    int numerator = inputInteger("\n\t\t\tEnter a value (-99...99) for the numerator  : ", -99, 99);
    int denominator = inputInteger("\t\t\tEnter a value (-99...99) for the denominator: ", -99, 99);
    try
    {
        if (rationalList.empty())
        {
            object.setNumerator(numerator);
            object.setDenominator(denominator);

            rationalList.push_back(object);
            cout << "\n\t\t" << object << " will be added to the front of the list.\n";
        }
        else
        {
            object.setNumerator(numerator);
            object.setDenominator(denominator);

            char choice = toupper(inputChar("\n\t\t\tAdd to the (F-front) or from the (B-back): ", static_cast<string>("FB")));
            if (choice == 'F')
            {
                rationalList.push_front(object);
                cout << "\n\t\t" << object << " will be added to the front of the list.\n";
            }
            else
            {
                rationalList.push_back(object);
                cout << "\n\t\t" << object << " will be added to the back of the list.\n";
            }
        }
    }
    catch (Rational::DivideByZero)
    {
        cout << "\n\t\tEXCEPTIONAL ERROR: Cannot add a Rational number, " << numerator << "/0" << ", that contains a zero denominator value.\n\n";
    }
}

// Precondition: Void function named insertToList, accepts a list of rational objects,
// Postcondition: Inserts an element to the list based on user input
void insertToList(list<Rational>& rationalList)
{
    //Prompt for rational to be inserted
    cout << "\n\t\tInput a Rational number [numerator/denominator] to be inserted...";
    int numerator1 = inputInteger("\n\t\t\tEnter a value (-99...99) for the numerator  : ", -99, 99);
    int denominator1 = inputInteger("\t\t\tEnter a value (-99...99) for the denominator: ", -99, 99);

    if (rationalList.empty())           //execute when list is empty
    {
        try
        {
            Rational elementToAdd(numerator1, denominator1);

            //push item into list
            rationalList.push_back(elementToAdd);
            cout << "\n\t\t" << elementToAdd << " will be inserted to the empty list.\n";
        }
        catch (Rational::DivideByZero)
        {
            // Display the error message if 0 is entered.
            cout << "\n\t\tEXCEPTIONAL ERROR: Cannot add a Rational number, " << numerator1 << "/0" << ", that contains a zero denominator value.\n\n";
        }
    }
    else        //executes when list !empty()
    {
        try
        {
            Rational elementToAdd(numerator1, denominator1);

            //prompt for element that is insert position
            cout << "\n\t\t Input an existing Rational number as the insert position to be added...";
            int numerator2 = inputInteger("\n\t\t\tEnter a value (-99...99) for the numerator  : ", -99, 99);
            int denominator2 = inputInteger("\t\t\tEnter a value (-99...99) for the denominator: ", -99, 99);

            try
            {
                Rational insertionPoint(numerator2, denominator2);

                bool inList = false;

                for (auto it = rationalList.begin(); it != rationalList.end(); it++)
                {
                    //check if insertPosition exists
                    if ((*it) == insertionPoint)
                    {
                        //prompt user choice
                        char choice = toupper(inputChar("\n\t\tInsert (B-before) or (A-after) the existing element : ", static_cast<string>("AB")));

                        if (choice == 'B')
                        {   //add before insertPosition
                            rationalList.insert(it, elementToAdd);
                            cout << "\n\t\t" << elementToAdd << " will be inserted before the existing element from the list.\n";
                        }
                        else
                        {
                            it++;
                            //add after insertPosition
                            rationalList.insert(it, elementToAdd);
                            cout << "\n\t\t" << elementToAdd << " will be inserted after the existing element from the list.\n";
                        }
                        inList = true;
                        break;
                    }
                }
                if (!inList)
                {
                    cout << "\n\t\tERROR: " << insertionPoint << " not found in the list. \n";
                }
            }
            catch (Rational::DivideByZero)
            {
                // Display the error message if 0 is entered.
                cout << "\n\t\tEXCEPTIONAL ERROR: Cannot add a Rational number, " << numerator2 << "/0" << ", that contains a zero denominator value.\n\n";
            }

        }
        catch (Rational::DivideByZero)
        {
            // Display the error message if 0 is entered.
            cout << "\n\t\tEXCEPTIONAL ERROR: Cannot add a Rational number, " << numerator1 << "/0" << ", that contains a zero denominator value.\n\n";
        }
    }
}

// Precondition: Void function named retrieveFromList, accepts a list of rational objects and a Rational class object.
// Postcondition: Retrieves a user inputted value from the list and displays the memory address.
void retrieveFromList(list<Rational>& rationalList, Rational& object)
{
    if (rationalList.empty())
        cout << "\n\t\tERROR: Search operation cannot be performed on an empty list. \n";

    else
    {
        cout << "\n\t\tInput a Rational number [numerator/denominator] to be searched...";

        int numerator = inputInteger("\n\t\t\tEnter a value (-99...99) for the numerator  : ", -99, 99);
        int denominator = inputInteger("\t\t\tEnter a value (-99...99) for the denominator: ", -99, 99);

        try
        {
            object.setNumerator(numerator);
            object.setDenominator(denominator);

            bool inList = false;

            for (auto it = rationalList.begin(); it != rationalList.end(); it++)
            {
                if ((*it) == object)
                {
                    cout << "\n\t\t" << object << " found in memory address: " << &(*it) << "\n";
                    inList = true;
                    break;
                }
            }
            if (!inList)
            {
                cout << "\n\t\tERROR: " << object << " not found in the list. \n";
            }
        }
        catch (Rational::DivideByZero)
        {
            cout << "\n\t\tEXCEPTIONAL ERROR: Rational number, " << numerator << "/0" << ", contains a zero denominator value.\n\n";
        }
    }
}

// Precondition: Void function named removeFromList, accepts a list of rational objects.
// Postcondition: Removes an element or all instances of an element from the list
void removeFromList(list<Rational>& rationalList)
{
    if (rationalList.empty())
        cout << "\n\t\tERROR: Delete operation cannot be performed on an empty list. \n";
    else
    {
        //prompt for rational number to delete
        cout << "\n\t\tInput a Rational number [numerator/denominator] to be removed...";
        int numerator = inputInteger("\n\t\t\tEnter a value (-99...99) for the numerator  : ", -99, 99);
        int denominator = inputInteger("\t\t\tEnter a value (-99...99) for the denominator: ", -99, 99);

        char userChoice = ' ';

        try
        {
            Rational toDelete(numerator, denominator);

            //search for value in list
            //if found prompt user to chose o-one or a-all
            for (auto it = rationalList.begin(); it != rationalList.end(); it++)
            {
                if ((*it) == toDelete)
                {
                    userChoice = toupper(inputChar("\n\tDo you want to remove (O-one or A-all) element(s): ", static_cast <string> ("OA")));
                    break;
                }
            }

            //will execute if item was found
            if (userChoice == 'O' || userChoice == 'A')
            {
                switch (userChoice)
                {
                case 'O': //only deletes one item
                {
                    // Cycle through list.
                    for (auto it = rationalList.begin(); it != rationalList.end(); it++)
                    {
                        // If value referenced by it matches value to delete, delete element and return/break out.
                        if ((*it) == toDelete)
                        {
                            rationalList.erase(it);
                            break;
                        }
                    }

                    cout << "\n\t\t" << toDelete << " has been removed once from the list.\n";
                }
                break;

                case 'A': //deletes all items
                {
                    // Cycle through the list.
                    for (auto it = rationalList.begin(); it != rationalList.end();)
                    {
                        // If value referenced by it matches value to delete, delete element and return/break out.
                        if ((*it) == toDelete)
                        {
                            it = rationalList.erase(it);
                            continue;
                        }
                        it++;
                    }
                    cout << "\n\t\t" << toDelete << " has been removed from the list.\n";
                }
                break;
                }
            }

            else
            {
                // Item to delete not found
                cout << "\n\t\t" << toDelete << " cannot be found from the vector. \n";
            }
        }
        catch (Rational::DivideByZero)
        {
            //Error out if denom == 0
            cout << "\n\t\tEXCEPTIONAL ERROR: Cannot remove the Rational number, [" << numerator << "/0]" << ", that contains a zero denominator value.\n\n";
        }
    }
}

void listMenu()
{
    list<Rational> rationalList; 
    Rational object; 
    do
    {
        system("cls");
        cout << "\n\tLinked lists are sequence containers that allow non-contiguous memory allocation. As compared to";
        cout << "\n\tvector, the linked list has slow traversal, but once a position has been found, insertion and";
        cout << "\n\tdeletion are quicker.\n\n";
        
        if (rationalList.empty())
        {
            cout << "\tThe current list is empty. ";
        }

        cout << "\t";
        printList(rationalList, rationalList.begin());

        if (!rationalList.empty())
        {
            cout << "\n\tHeader: " << &(rationalList.front());
        }
        switch (listMenuOption())
        {
        case 1: addToList(rationalList, object);  break;
        case 2: insertToList(rationalList);  break;
        case 3: retrieveFromList(rationalList, object);  break;
        case 4: removeFromList(rationalList);  break;
        case 5:
        {
            // Check if the size is 0, if it is display error message. Else, sort the list.
            if (rationalList.empty())
                cout << "\n\t\tERROR: Sort operation cannot be performed on an empty list. \n";
            else
            {
                rationalList.sort();
                cout << "\n\t\tThe list of Rational numbers has been sorted. \n";
            }     
        } break;
        case 6:
        {
            // Check if the size is 0, if it is display error message. Else, clear the list.
            if (rationalList.empty())
                cout << "\n\t\tERROR: Clear operation cannot be performed on an empty list. \n";
            else
            {
                rationalList.clear();
                cout << "\n\t\t The list has been cleared of all Rational element(s). \n";
            }
        } break;
        case 0: return; break;
        } // end of switch
        system("pause");
    } while (true);
}

// Precondition: Void function named printStack, accepts a stack of rational objects
// Postcondition: Utilizes recursion to print the items in a stack. 
void printStack(stack <Rational>& obj)
{
    // Base case (check empty)
    if (obj.empty())
    {
        return;
    }
    // Prints the items and then pops elements. 
    Rational topElement = obj.top();
    obj.pop();
    cout << "\t" << topElement << " ";

    // Recursively print remaining stack elements
    printStack(obj);
    
    // Restore the top element to the stack
    obj.push(topElement);
}

// Precondition: Int function named stackMenuOption
// Postcondition: Returns an integer based on user input.
int stackMenuOption()
{
    cout << "\n\n";
    cout << "\n\t\tStack Menu Options";
    cout << "\n\t" << string(102, '=');
    cout << "\n\t\t1. Push";
    cout << "\n\t\t2. Top";
    cout << "\n\t\t3. Pop";
    cout << "\n\t" << string(102, '-');
    cout << "\n\t\t0. Return";
    cout << "\n\t" << string(102, '=') << "\n";
    int option = inputInteger("\t\tOption: ", 0, 3);
    return option; 
}

void stackMenu()  
{
    // Create a stack of rational objects and a Rational class object.
    stack <Rational> rationalStack; 
    Rational object; 
    do
    {
        system("cls");
        cout << "\n\tStacks are type of container adaptors with LIFO (Last In First Out) type of working, where";
        cout << "\n\ta new element is added (pushed) at one end (top) and an element is removed (popped) from that end";
        cout << "\n\tonly. Stack uses an encapsulated object of either vector or deque (by default) or list (sequential";
        cout << "\n\tcontainer class) as its underlying container, providing a specific set of member functions to";
        cout << "\n\taccess its elements.\n\n";

        // recursion 
        if (rationalStack.empty())
        {
            cout << "\tThe current stack is empty. ";
        }
        else
        {
            cout << "\tThe current stack contains " << rationalStack.size() << " element(s): \n\n";
            cout << "\tTop >> ";
            printStack(rationalStack);
        }
       
        switch (stackMenuOption())
        {
        case 1:
        {
            // Prompts the user to enter a numerator/denominator to be pushed/added to the stack
            cout << "\n\t\tInput a Rational number [numerator/denominator] to be pushed...";
            int numerator = inputInteger("\n\t\t\tEnter a value (-99...99) for the numerator  : ", -99, 99);
            int denominator = inputInteger("\t\t\tEnter a value (-99...99) for the denominator: ", -99, 99);

            try
            {
                // Sets the user entered values into the class
                object.setNumerator(numerator);
                object.setDenominator(denominator);
                // Pushes the item into the stack
                rationalStack.push(object);
                // Displays the item
                cout << "\n\t\t" << object << " will be added to the front of the vector.\n";
            }
            catch (Rational::DivideByZero)
            {
                // Display the error message if 0 is entered.
                cout << "\n\t\tEXCEPTIONAL ERROR: Cannot add a Rational number, " << numerator << "/0" << ", that contains a zero denominator value.\n\n";
            }
           
        } break;
        case 2:
        {
            // If the stack is empty display that the top cannot be found. Otherwise display the top value in the stack
            if (rationalStack.empty())
            {
                cout << "\n\t\tERROR: No top element can be retrieved from an empty stack. \n";
                break;
            }
            else
            {
                cout << "\n\t\t" << rationalStack.top() << " is at the top of the stack. \n";
            }
        } break;
        case 3:
        {
            // If the stack is empty display that the pop cannot be performed. Otherwise display the top value in the stack
            // and pop the element.
            if (rationalStack.empty())
            {
                cout << "\n\t\tERROR: No pop operation can be performed from an empty stack. \n";
            }
            else
            {
                cout << "\n\t\t" << rationalStack.top() << " will be popped from the stack. \n";
                rationalStack.pop();
            }
        } break;
        case 0: return;  break;
        } // end of switch
        system("pause");
    } while (true);
}

// Precondition: Void function named printQueue, accepts queue object.
// Postcondition: Utilizes recursion to dispaly the queue
void printQueue(queue<Rational>& original, queue<Rational>& temp)
{
    // Base case (check empty)
    if (original.empty())
    {
        return;
    }
    // Creates a rational item to hold the front item
    Rational frontItem = original.front();
    temp.push(frontItem);
    // Pops the item
    original.pop();

    // Recursive call
    printQueue(original, temp);

    // Prints the front item
    cout << frontItem << "  ";
    frontItem = temp.front();
    // Pushes the item into the queue and pops the item from the temp queue.
    original.push(frontItem);
    temp.pop();
}

// Precondition: Int function named queueMenuOption
// Postcondition: Returns an integer based on user input
int queueMenuOption()
{
    // Display queue menu
    cout << "\n\n";
    cout << "\n\t\tQueue Menu Option";
    cout << "\n\t" << string(102, '=');
    cout << "\n\t\t1. Enqueue (Push Into The Rear)";
    cout << "\n\t\t2. Rear (Back)";
    cout << "\n\t\t3. Front";
    cout << "\n\t\t4. Dequeue (pop from the front)";
    cout << "\n\t" << string(102, '-');
    cout << "\n\t\t0. Return";
    cout << "\n\t" << string(102, '=') << "\n";
    // Prompt the user to enter an option
    int option = inputInteger("\t\tOption: ", 0, 4);
    return option; 
}

void queueMenu()
{
    // Create the queue and rational class constructor.
    queue<Rational> rationalQueue; 
    Rational object; 
    queue<Rational> temp;
    do
    {
        // Display the purpose of a queue
        system("cls");
        cout << "\n\tQueues are type of container adaptors that operate in a first in first out (FIFO) type of";
        cout << "\n\tarrangement. Elements are inserted / pushed (enqueued) at the rear and are removed / popped (dequeued)";
        cout << "\n\tfrom the front. Queues use an encapsulated object of deque or list (sequential container class)";   
        cout << "\n\tas its underlying container, providing a specific set of member functions to access elements.\n\n";

        // Check if the queue is empty and display
        if (rationalQueue.empty())
        {
            cout << "\tThe current queue is empty. ";
        }
        else
        {   
            // Display contents of the queue
            cout << "\tThe Queue contains " << rationalQueue.size() << " element(s): \n\n";
            cout << "\tin (rear)  >>  ";
            printQueue(rationalQueue, temp);
            cout << ">> out (front)";
        }

        switch (queueMenuOption())
        {
        case 1:
        {
            // Prompt the user to enter the numerator and denominator
            cout << "\n\t\tInput a Rational number [numerator/denominator] to be enqueued (pushed)... ";
            int numerator = inputInteger("\n\t\t\tEnter a value (-99...99) for the numerator  : ", -99, 99);
            int denominator = inputInteger("\t\t\tEnter a value (-99...99) for the denominator: ", -99, 99);

            try
            {
                // Use the set to enter the numerator/denominator into the class object
                object.setNumerator(numerator);
                object.setDenominator(denominator);
                // Push the value into the queue
                rationalQueue.push(object);
                // Display the value being pushed
                cout << "\n\t\t" << object << " will be enqueued (pushed) onto the queue. \n";

            }
            catch (Rational::DivideByZero)
            {
                // Display the error message if 0 is entered.
                cout << "\n\t\tEXCEPTIONAL ERROR: Cannot add a Rational number, " << numerator << "/0" << ", that contains a zero denominator value.\n\n";
            }
        }
        break;
        
        case 2:
        {
            // Check if the queue is empty, if it is empty display error message. Else display the value that is at the back.
            if (rationalQueue.empty())
            {
                cout << "\n\t\tERROR: No back element can be retrieved from an empty queue. \n";
            }
            else
            {
                cout << "\n\t\t" << rationalQueue.back() << " is at the back of the queue. \n";
            }
        }
        break;

        case 3:
        {
            // Check if the queue is empty, if it is empty display error message. Else display the value that is at the front.
            if (rationalQueue.empty())
            {
                cout << "\n\t\tERROR: No front element can be retrieved from an empty queue. \n";
            }
            else
            {
                cout << "\n\t\t" << rationalQueue.front() << " is at the front of the queue. \n";
            }
        }
        break;

        case 4:
        {
            // Check if the queue is empty, if it is empty display error message. Else display the value that is being popped and pop it.
            if (rationalQueue.empty())
            {
                cout << "\n\t\tERROR: No dequeue (pop) operation can be performed on an empty queue. \n";
            }
            else
            {
                cout << "\n\t\t" << rationalQueue.front() << "  will be dequeued (popped) from the queue. \n";
                rationalQueue.pop(); 
            }
        }
        break;

        case 0:
        {
            return;
        }
        break;
        } // end of switch
        system("pause");
    } while (true);
}