#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int TABLE_SIZE = 100; 
struct Contact {
    string name;
    string phoneNumber;
    bool isDeleted; 
    Contact() : name(""), phoneNumber(""), isDeleted(false) {}
};
int hashFunction(const string& key, int tableSize) {
    int hash = 0;
    for (char ch : key) {
        hash = (hash * 31 + ch) % tableSize;
    }
    return hash;
}
class PhoneBook {
private:
    vector<Contact> table;
    int size;
public:
    PhoneBook() : table(TABLE_SIZE), size(0) {}
    void addContact(const string& name, const string& phoneNumber) {
        if (size >= TABLE_SIZE) {
            cout << "Phone book is full!" << endl;
            return;
        }
        int index = hashFunction(name, TABLE_SIZE);
        int i = 0;
        while (i < TABLE_SIZE) {
            int probeIndex = (index + i) % TABLE_SIZE;
            if (table[probeIndex].name == "" || table[probeIndex].isDeleted) {
                table[probeIndex].name = name;
                table[probeIndex].phoneNumber = phoneNumber;
                table[probeIndex].isDeleted = false;
                size++;
                return;
            }
            i++;
        }
        cout << "Unable to add contact, hash table is full!" << endl;
    }
    string searchContact(const string& name) {
        int index = hashFunction(name, TABLE_SIZE);
        int i = 0;
        while (i < TABLE_SIZE) {
            int probeIndex = (index + i) % TABLE_SIZE;
            if (table[probeIndex].name == name && !table[probeIndex].isDeleted) {
                return table[probeIndex].phoneNumber;
            }
            if (table[probeIndex].name == "" && !table[probeIndex].isDeleted) {
                break; 
            }
            i++;
        }
        return "Contact not found!";
    }
    void deleteContact(const string& name) {
        int index = hashFunction(name, TABLE_SIZE);
        int i = 0;
        while (i < TABLE_SIZE) {
            int probeIndex = (index + i) % TABLE_SIZE;
            if (table[probeIndex].name == name && !table[probeIndex].isDeleted) {
                table[probeIndex].isDeleted = true;
                size--;
                return;
            }
            if (table[probeIndex].name == "" && !table[probeIndex].isDeleted) {
                break; 
            }
            i++;
        }
        cout << "Contact not found!" << endl;
    }
};

int main() {
    PhoneBook phoneBook;

    // Add contacts
    phoneBook.addContact("narendra", "11111111");
    phoneBook.addContact("rahul", "123345667");
    phoneBook.addContact("keju", "34563204933");

    // Search for contacts
    cout << "narendra's number: " << phoneBook.searchContact("narendra") << endl;
    cout << "rahul's number: " << phoneBook.searchContact("rahul") << endl;
    cout << "keju's number: " << phoneBook.searchContact("keju") << endl;
    cout << "laju's number: " << phoneBook.searchContact("laju") << endl; // Should not be found

    // Delete a contact
    phoneBook.deleteContact("narendra");
    cout << "narendra's number after deletion: " << phoneBook.searchContact("narendra") << endl;

    return 0;
}
