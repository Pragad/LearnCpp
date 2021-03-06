// http://stackoverflow.com/questions/16243711/how-to-implement-a-generic-hash-function-in-c
// Should making "hash()" generic as well

#include <iostream>
#include <vector>
#include <functional>   // Contains function for std::hash
using namespace std;

static const uint32_t HASHTABLE_SIZE = 100;

// Not used
static size_t
myComputeHash(const int& key, size_t size)
{
    // http://stackoverflow.com/questions/8094790/how-to-get-hash-code-of-a-string-in-c
    size_t hashVal = hash<int>()(key);
    return hashVal % size;
}

// Make Hash function generic as well
template<typename K, typename V, typename H = hash<K> >
class HashTable
{
    private:
        class HashEntry;    // forward declaration
        size_t _size;        // Tracks the full size of the hash list
        size_t _numElements; // Tracks the current number of elements
        vector< vector<HashEntry> > _hashTable;

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

        size_t size();
        size_t capacity();
        size_t computeHash(const K& key);
};

// Default Parameter should be called out only in the declaration
// http://stackoverflow.com/questions/12989062/having-trouble-with-template-classes-having-template-member-functions
template<typename K, typename V, typename H >
HashTable<K, V, H>::HashTable(size_t size)
{
    this->_size = size;
    this->_numElements = 0;
    _hashTable.reserve(_size);
}

template<typename K, typename V, typename H >
HashTable<K, V, H>::HashTable()
{
    this->_size = HASHTABLE_SIZE;
    this->_numElements = 0;
    _hashTable.reserve(_size);
}

template<typename K, typename V, typename H >
size_t
HashTable<K, V, H>::size()
{
    return _size;
}

template<typename K, typename V, typename H >
size_t
HashTable<K, V, H>::capacity()
{
    return _numElements;
}

template<typename K, typename V, typename H >
size_t
HashTable<K, V, H>::computeHash(const K& key)
{
    // http://stackoverflow.com/questions/8094790/how-to-get-hash-code-of-a-string-in-c
    size_t hashVal = H()(key);
    return hashVal % _size;
}

template<typename K, typename V, typename H >
void
HashTable<K, V, H>::put(K key, V value)
{
    // Compute a new key based on the given key
    size_t newKey = computeHash(key);
    // Create a Hash entry with user's given key and value and push into the vector
    // Index where the entry should be pushed is computed from compute Hash
    _hashTable.insert(_hashTable.begin() + newKey, vector<HashEntry> {HashEntry (key, value)});
    _numElements++;
}

template<typename K, typename V, typename H >
V
HashTable<K, V, H>::get(K key)
{
    // Compute a new key based on the given key
    size_t newKey = computeHash(key);

    if (_hashTable[newKey].size() > 1)
    {
        for (auto itr = _hashTable[newKey].begin(); itr != _hashTable[newKey].end(); ++itr)
        {
            if (itr->getKey() == key)
            {
                return itr->getValue();
            }
        }

        // If we are here we have reached the end and the element is not present
        throw std::out_of_range("Index at Key: " + to_string(key) + "is empty.");
    }
    else if (_hashTable[newKey].size() == 1)
    {
        return _hashTable[newKey][0].getValue();
    }
    else
    {
        throw std::out_of_range("Index at Key: " + to_string(key) + "is empty.");
    }
}

int main()
{
    // http://www.drdobbs.com/windows/user-defined-hash-functions-for-unordere/231600210
    // http://stackoverflow.com/questions/17016175/c-unordered-map-using-a-custom-class-type-as-the-key
    // http://stackoverflow.com/questions/15810620/unordered-map-with-custom-hashing-equal-functions-functions-dont-get-called
    //HashTable<int, string, myComputeHash>* ht = new HashTable<int, string, myComputeHash>();

    HashTable<int, string>* ht = new HashTable<int, string>();

    for (uint32_t i = 0; i < 10; i++)
    {
        ht->put(i, "Value: " + to_string(i));
    }
    ht->put(3, "Value: " + to_string(13));
    ht->put(5, "Value: " + to_string(15));
    ht->put(7, "Value: " + to_string(17));

    cout << "Hash Table Capacity: " << ht->capacity() << endl;

    // TODO: The below line will try to insert to a random position in a vector.
    // This would crash the program
    // Fix: Assign dummy values to all of the vector elements
    //ht->put(17, "Value: " + to_string(17));
    for (uint32_t i = 0; i < ht->capacity(); i++)
    {
        cout << ht->get(i) << ", ";
    }
    cout << endl;

    return 0;
}
