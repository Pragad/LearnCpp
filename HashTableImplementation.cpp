#include <iostream>
#include <vector>
#include <functional>   // Contains function for hash
using namespace std;

static const uint32_t HASHTABLE_SIZE = 100;

class HashTable
{
    private:
        class HashEntry;    // forward declaration
        size_t _size;
        vector<HashEntry> _hashTable;

        class HashEntry
        {
            public:
                uint32_t _key;
                string _value;

                HashEntry(uint32_t key, string value) : _key(key),
                                                        _value(value) { }

                int getKey() { return _key; }
                string getValue() {return _value; }
        };

    public:
        HashTable();
        HashTable(size_t size);
        void put(uint32_t key, string value);
        string get(uint32_t key);

        size_t computeHash(string value);
};

HashTable::HashTable(size_t size)
{
    this->_size = size;
    _hashTable.reserve(_size);
}

HashTable::HashTable()
{
    this->_size = HASHTABLE_SIZE;
    _hashTable.reserve(_size);
}

size_t
HashTable::computeHash(string key)
{
    // http://stackoverflow.com/questions/8094790/how-to-get-hash-code-of-a-string-in-c
    size_t hashVal = hash<string>()(key);
    return hashVal % _size;
}

void
HashTable::put(uint32_t key, string value)
{
    // Compute a new key based on the given key
    size_t newKey = computeHash(to_string(key));

    // Create a Hash entry with user's given key and value and push into the vector
    // Index where the entry should be pushed is computed from compute Hash
    // Replace existing value with new value if already exists
    //
    // TODO: Make it a list to add support for chaining
    _hashTable[newKey] = HashEntry(key, value); 
}

string
HashTable::get(uint32_t key)
{
    // Compute a new key based on the given key
    size_t newKey = computeHash(to_string(key));

    return _hashTable[newKey].getValue();
}

int main()
{
    HashTable* ht = new HashTable();

    for (uint32_t i = 0; i < 10; i++)
    {
        ht->put(i, "Value: " + to_string(i));
    }

    for (uint32_t i = 0; i < 10; i++)
    {
        cout << ht->get(i) << ", ";
    }
    cout << endl;

    return 0;
}
