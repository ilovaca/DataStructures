/* 
 * File:   hash_table.h
 * Author: austin
 * A simple hash table implementation, using separate chaining
 * Created on July 30, 2015, 8:15 PM
 */
#include <vector>
#include "bucket.h"
#include <functional>
#include "ElementExistsException.h"
#ifndef HASH_TABLE_H
#define	HASH_TABLE_H

template<typename K, typename V>
class hash_table {
private:
    std::vector<bucket<K, V>> buckets;
    // some other bookkeeping data
    unsigned bucket_count;
    std::hash<K> key_hasher;

public:
    hash_table() = default;
    hash_table(unsigned num_buckect_reserved = 100000);
    ~hash_table() = default;
    void insert(const std::pair<K, V>& p);
    V& get(const K& key);
    void remove(const K& key);
    void clear();

    std::size_t get_hash_index(const K& key) {
        auto hash_code = key_hasher(key);
        unsigned index = hash_code / bucket_count;
    }

    bool exist(const K& key) {
        return buckets[get_hash_index(key)].size() > 0;
    }

    inline unsigned get_bucket_count() {
        return bucket_count;
    }

    inline double load_factor() {
        return 0 / bucket_count;
    }

    V& operator[](const K& key) {
        return get(key);
    }
    
   
};


#endif	/* HASH_TABLE_H */

/**
 * Constructor to reserve a certain number of buckets in the hash_table
 * @param num_bucket_reserved
 */
template <typename K, typename V>
hash_table<K, V>::hash_table(unsigned num_bucket_reserved) : bucket_count(num_bucket_reserved) {
    buckets.resize(num_bucket_reserved, bucket<K, V>());
}

template <typename K, typename V>
void hash_table<K, V>::insert(const std::pair<K, V>& pair) {
    if(exist(pair.first)) throw ElementExistsException("the element with this key already exists");
    auto index = hash_table::get_hash_index(pair.first);
    buckets[index].insert(pair);
}

template <typename K, typename V>
void hash_table<K, V>::clear() {
    
}

template <typename K, typename V>
void hash_table<K, V>::remove(const K& key) {
    auto index = get_hash_index(key);
    buckets[index].remove(key);
}

template <typename K, typename V>
V& hash_table<K, V>::get(const K& key){
    if(!exist(key)) throw std::runtime_error("Error referencing elements: key does not exist");
    else {
        auto dehash = get_hash_index(key);
        return buckets[dehash].get(key);
    }
}