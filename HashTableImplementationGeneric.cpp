#include <iostream>
#include <vector>
#include <functional>   // Contains function for hash
using namespace std;

static const uint32_t HASHTABLE_SIZE = 100;

template<typename K, typename V>
class HashTable
{
    private:
        class HashEntry;    // forward declaration
        size_t _size;
        vector<HashEntry> _hashTable;

        class HashEntry
        {
            public:
                K _key;
                V _value;

                HashEntry(K key, V value) : _key(key),
                                            _value(value) { }

                K getKey() { return _key; }
                V getValue() {return _value; }
        };

    public:
        HashTable();
        HashTable(size_t size);
        void put(K key, V value);
        V get(K key);

        size_t computeHash(K key);
};

template<typename K, typename V>
HashTable<K, V>::HashTable(size_t size)
{
    this->_size = size;
    _hashTable.reserve(_size);
}

template<typename K, typename V>
HashTable<K, V>::HashTable()
{
    this->_size = HASHTABLE_SIZE;
    _hashTable.reserve(_size);
}

template<typename K, typename V>
size_t
HashTable<K, V>::computeHash(K key)
{
    // http://stackoverflow.com/questions/8094790/how-to-get-hash-code-of-a-string-in-c
    size_t hashVal = hash<K>()(key);
    return hashVal % _size;
}

template <typename K, typename V>
void
HashTable<K, V>::put(K key, V value)
{
    // Compute a new key based on the given key
    size_t newKey = computeHash(key);
    cout << "New Key: " << newKey << endl;

    // Create a Hash entry with user's given key and value and push into the vector
    // Index where the entry should be pushed is computed from compute Hash
    // Replace existing value with new value if already exists
    //
    // TODO: Make it a list to add support for chaining
    _hashTable[newKey] = HashEntry(key, value); 
}

template <typename K, typename V>
V
HashTable<K, V>::get(K key)
{
    // Compute a new key based on the given key
    size_t newKey = computeHash(key);

    return _hashTable[newKey].getValue();
}

int main()
{
    HashTable<int, string>* ht = new HashTable<int, string>();

    for (uint32_t i = 0; i < 10; i++)
    {
        ht->put(i, "Value: " + to_string(i));
    }
    cout << 1 << endl;

    for (uint32_t i = 0; i < 10; i++)
    {
        cout << ht->get(i) << ", ";
    }
    cout << endl;

    return 0;
}
