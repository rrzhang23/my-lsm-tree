//
// Created by rrzhang on 19-2-21.
//

#ifndef LSM_TREE_LSM_TREE_H
#define LSM_TREE_LSM_TREE_H

#include "buffer_.h"
#include "level_.h"
#include "merge_.h"
#include <vector>

class LSMTree {
private:

    boost::shared_mutex mutex;
    Buffer buffer;
    float bf_bits_per_entry;
    std::vector<Level*> levels;

    void merge_down(std::vector<Level*>::iterator current_level);
    void flush_buffer();
    RetCode search_run(entry_t* entry);
public:
    LSMTree(int buffer_size, int bits_per_entry, int num_threads, int depth, int fanout);
    ~LSMTree();

    RetCode put(const entry_t &entry);
    RetCode put(const KEY_t &key, const VAL_t &value);
    VAL_t get(const KEY_t &key);
    RetCode get(const KEY_t &key, VAL_t* value);



// TODO:
//    void range(KEY_t, KEY_t) const;
// TODO:
//    RetCode del(KEY_t);
// TODO:
//    RetCode load(std::string);
};


#endif //LSM_TREE_LSM_TREE_H
