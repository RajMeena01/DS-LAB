#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct Product {
    string name;
    double price;
    string id;
    Product(const string& n, double p, const string& i) : name(n), price(p), id(i) {}
};

struct Node {
    Product* product;
    Node* next;

    Node(Product* p) : product(p), next(nullptr) {}
};
class ShoppingCart {
private:
    static const int TABLE_SIZE = 100; 
    vector<Node*> table;
    int hashFunction(const string& key, int i) {
        const int c1 = 1, c2 = 2; 
        int h1 = 0;
        for (char ch : key) {
            h1 = (h1 * 31 + ch) % TABLE_SIZE; 
        }
        return (h1 + i * (c1 * h1 + c2)) % TABLE_SIZE;
    }

public:
    ShoppingCart() : table(TABLE_SIZE, nullptr) {}

    ~ShoppingCart() {
        for (Node* head : table) {
            while (head) {
                Node* temp = head;
                head = head->next;
                delete temp->product;
                delete temp;
            }
        }
    }
    void addProduct(Product* product) {
        int i = 0;
        int index;
        do {
            index = hashFunction(product->id, i++);
        } while (table[index] != nullptr); 

        table[index] = new Node(product);
    }
    void removeProduct(const string& id) {
        int i = 0;
        int index;
        do {
            index = hashFunction(id, i++);
            if (table[index] && table[index]->product->id == id) {
                Node* temp = table[index];
                table[index] = table[index]->next;
                delete temp->product;
                delete temp;
                return;
            }
        } while (table[index] != nullptr); 
    }
    Product* searchProduct(const string& id) {
        int i = 0;
        int index;
        do {
            index = hashFunction(id, i++);
            if (table[index] && table[index]->product->id == id) {
                return table[index]->product;
            }
        } while (table[index] != nullptr); 
        return nullptr;
    }
};

int main() {
    ShoppingCart cart;
    cart.addProduct(new Product("Laptop", 999.99, "1001"));
    cart.addProduct(new Product("Smartphone", 499.99, "1002"));
    cart.addProduct(new Product("Headphones", 79.99, "1003"));

    Product* product = cart.searchProduct("1002");
    if (product) {
        cout << "Product found: " << product->name << " - $" << product->price << endl;
    } else {
        cout << "Product not found." << endl;
    }
    cart.removeProduct("1002");

    product = cart.searchProduct("1002");
    if (product) {
        cout << "Product found: " << product->name << " - $" << product->price << endl;
    } else {
        cout << "Product not found." << endl;
    }

    return 0;
}
