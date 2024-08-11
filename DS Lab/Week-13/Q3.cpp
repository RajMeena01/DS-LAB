#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct DNSRecord {
    string domain;
    string ipAddress;

    DNSRecord(const string& d, const string& ip) : domain(d), ipAddress(ip) {}
};
class DNSCache {
private:
    static const int TABLE_SIZE = 100; 
    vector<DNSRecord*> table;
    int hashFunction(const string& key, int i) {
        const int c1 = 1, c2 = 1; 
        int h1 = 0;
        for (char ch : key) {
            h1 = (h1 * 31 + ch) % TABLE_SIZE; 
        }
        return (h1 + c1 * i + c2 * i * i) % TABLE_SIZE;
    }
public:
    DNSCache() : table(TABLE_SIZE, nullptr) {}
    ~DNSCache() {
        for (DNSRecord* record : table) {
            delete record;
        }
    }
    void insertRecord(const string& domain, const string& ipAddress) {
        int i = 0;
        int index;
        do {
            index = hashFunction(domain, i++);
        } while (table[index] != nullptr); 

        table[index] = new DNSRecord(domain, ipAddress);
    }
    string lookupIPAddress(const string& domain) {
        int i = 0;
        int index;
        do {
            index = hashFunction(domain, i++);
            if (table[index] && table[index]->domain == domain) {
                return table[index]->ipAddress; 
            }
        } while (table[index] != nullptr); 
        return "Domain not found.";
    }
    void updateIPAddress(const string& domain, const string& newIPAddress) {
        int i = 0;
        int index;
        do {
            index = hashFunction(domain, i++);
            if (table[index] && table[index]->domain == domain) {
                table[index]->ipAddress = newIPAddress; 
                return;
            }
        } while (table[index] != nullptr); 
        insertRecord(domain, newIPAddress);
    }
};

int main() {
    DNSCache cache;

    cache.insertRecord("www.example.com", "192.168.1.1");
    cache.insertRecord("www.openai.com", "208.45.76.98");
    cache.insertRecord("www.google.com", "172.217.168.78");

    cout << "IP address for www.example.com: " << cache.lookupIPAddress("www.example.com") << endl;
    cout << "IP address for www.openai.com: " << cache.lookupIPAddress("www.openai.com") << endl;
    cout << "IP address for www.google.com: " << cache.lookupIPAddress("www.google.com") << endl;

    cache.updateIPAddress("www.example.com", "10.0.0.1");

    cout << "Updated IP address for www.example.com: " << cache.lookupIPAddress("www.example.com") << endl;

    return 0;
}
