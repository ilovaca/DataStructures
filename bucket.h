/* 
 * File:   bucket.h
 * Author: austin
 *
 * Created on July 30, 2015, 8:59 PM
 */
#include <list>
#ifndef BUCKET_H
#define	BUCKET_H

template<typename K, typename V>
class bucket {
public:
    
    bucket() = default;
    bucket(const bucket& orig) = default;
    virtual ~bucket() = default;

    void remove(const K& key) {
        for (auto iter = entry_list.begin(); iter != entry_list.end(); iter++) {
            if ((*iter).first == key){
                entry_list.erase(iter);
            }
        }
    }
    
    V& get(const K& key){
        for(auto & entry : entry_list){
            if(entry.first == key){
                return entry.second;
            }
        }
    }
    
    int size(){
        return entry_list.size();
    }
    int entry_count() {;
        return entry_list.size();
    }

    inline void insert(std::pair<K, V> pair) {
        entry_list.push_back(pair);
    }
private:
    std::list<std::pair<K, V>> entry_list;
};

#endif	/* BUCKET_H */

