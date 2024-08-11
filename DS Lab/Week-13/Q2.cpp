#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Book {
    string title;
    string author;
    string ISBN;
    Book(const string& t, const string& a, const string& i) : title(t), author(a), ISBN(i) {}
};
struct Node {
    Book* book;
    Node* next;
    Node(Book* b) : book(b), next(nullptr) {}
};
class HashTable {
private:
    static const int TABLE_SIZE = 100; 
    vector<Node*> table;
    int hashFunction(const string& ISBN) {
        int hash = 0;
        for (char ch : ISBN) {
            hash = (hash * 31 + ch) % TABLE_SIZE; 
        }
        return hash;
    }
public:
    HashTable() : table(TABLE_SIZE, nullptr) {}
    ~HashTable() {
        for (Node* head : table) {
            while (head) {
                Node* temp = head;
                head = head->next;
                delete temp->book;
                delete temp;
            }
        }
    }
    void insertBook(Book* book) {
        int index = hashFunction(book->ISBN);
        Node* newNode = new Node(book);
        if (!table[index]) {
            table[index] = newNode;
        } else {
            newNode->next = table[index];
            table[index] = newNode;
        }
    }
    Book* searchBook(const string& ISBN) {
        int index = hashFunction(ISBN);
        Node* current = table[index];
        while (current) {
            if (current->book->ISBN == ISBN) {
                return current->book; 
            }
            current = current->next;
        }
        return nullptr; 
    }
    void deleteBook(const string& ISBN) {
        int index = hashFunction(ISBN);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current) {
            if (current->book->ISBN == ISBN) {
                if (prev)
                    prev->next = current->next;
                else
                    table[index] = current->next;
                delete current->book;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
};
int main() {
    HashTable library;
    library.insertBook(new Book("Introduction to Algorithms", "Thomas H. Cormen", "9780262533058"));
    library.insertBook(new Book("The Catcher in the Rye", "J.D. Salinger", "9780316769488"));
    library.insertBook(new Book("To Kill a Mockingbird", "Harper Lee", "9780061120084"));
    library.insertBook(new Book("1984", "George Orwell", "9780451524935"));
    Book* book = library.searchBook("9780316769488");
    if (book) {
        cout << "Book found: " << book->title << " by " << book->author << " (ISBN: " << book->ISBN << ")" << endl;
    } else {
        cout << "Book not found." << endl;
    }
    library.deleteBook("9780316769488");
    book = library.searchBook("9780316769488");
    if (book) {
        cout << "Book found: " << book->title << " by " << book->author << " (ISBN: " << book->ISBN << ")" << endl;
    } else {
        cout << "Book not found." << endl;
    }
    library.insertBook(new Book("Pride and Prejudice", "Jane Austen", "9780141439518"));
    book = library.searchBook("9780141439518");
    if (book) {
        cout << "Book found: " << book->title << " by " << book->author << " (ISBN: " << book->ISBN << ")" << endl;
    } else {
        cout << "Book not found." << endl;
    }
    return 0;
}
