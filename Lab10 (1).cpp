/* A.I. Disclaimer: All work for this assignment was completed by myself and entirely without the use  
of artificial intelligence tools such as ChatGPT, MS Copilot, other LLMs, etc. 
*/     

#include <iostream>
#include <fstream>
#include <string> 
#include <cassert> 
using namespace std; 

// Prototypes  
void ReadData(ifstream &myIn, string books[], int &numBooks);  
void SelectionSort(string books[], int numBooks);
int LinearSearch(const string books[], int numBooks, const string &target);

const int MAX_BOOKS = 100; 

int main() {
    string books[MAX_BOOKS];
    int numBooks;
    ifstream myIn;

    myIn.open("booktitles.dat");  

    // Check if file opens 
    assert(myIn && "Error! Unable to open file!");

    ReadData(myIn, books, numBooks);
    myIn.close();
    
    SelectionSort(books, numBooks);
    
    // Display sorted book list
    for (int i = 0; i < numBooks; i++) {
        cout << (i + 1) << " : " << books[i] << endl;
    }
    
    cout << endl; 
    // query mode
    string query; 
    cout << "Enter the book title: ";
    getline(cin, query);
    
    while (!query.empty()) {
        int position = LinearSearch(books, numBooks, query);
        if (position != -1) {
            cout << "The book is at location " << position << endl;
        } else {
            cout << "The book is not in the collection." << endl;
        }
        cout << "Enter the book title: ";
       
        getline(cin, query);
    }
    
    return 0;
}

// Function to read book titles from file
void ReadData(ifstream &myIn, string books[], int &numBooks) {
    numBooks = 0;
    while (getline(myIn, books[numBooks]) && numBooks < MAX_BOOKS) {
        numBooks++;
    }
}

// Function to sort book titles using Selection Sort
void SelectionSort(string books[], int numBooks) {
    for (int i = 0; i < numBooks - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < numBooks; j++) {
            if (books[j] < books[minIndex]) {
                minIndex = j;
            }
        }
        swap(books[i], books[minIndex]);
    }
}

// Function to perform linear search
int LinearSearch(const string books[], int numBooks, const string &target) {
    for (int i = 0; i < numBooks; i++) {
        if (books[i] == target) {
            return i + 1;  // Return 1-based index
        }
    }
    return -1;  
}
