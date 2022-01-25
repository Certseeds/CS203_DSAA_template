/*
MIT License

CS203_DSAA_template

Copyright (C) 2022  nanoseeds

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include "leetcode_146_test.hpp"
#include <class_helper/nonable.hpp>

namespace leetcode_146 {
class LRU final: public LRUCache, protected nonCopyMoveAble {
private:
    struct Node final : private nonCopyMoveAble {
        int32_t k;
        int32_t v;
        Node *before{nullptr};
        Node *next{nullptr};

        Node(int32_t k, int32_t v, Node *before, Node *next) : k(k), v(v), before(before), next(next) {}
    };

    Node head{std::numeric_limits<int32_t>::max(), std::numeric_limits<int32_t>::max(), nullptr, nullptr};
    std::unordered_map<int32_t, Node *> umap{};
public:

    explicit LRU(int32_t capacity) : LRUCache(capacity) {
        this->head.next = &(this->head);
        this->head.before = &(this->head);
    }

    bool exists(int32_t page) const {
        return umap.count(page) != 0; // equal,
    }

    int get(int32_t key) override {
        if (this->exists(key)) {
            Node *const ptr = umap.at(key);
            // step1,摘出
            {
                Node *const pnext = ptr->next;
                Node *const pbefore = ptr->before;
                pbefore->next = pnext;
                pnext->before = pbefore;
            }
            // step2,接续
            {
                Node *const snd = head.next;
                head.next = ptr;
                snd->before = ptr;
                ptr->next = snd;
                ptr->before = &head;
            }
            return ptr->v;
        }
        return -1;
    }

    void put(int32_t key, int32_t value) override {
        if (this->exists(key)) {
            Node *const ptr = umap.at(key);
            ptr->v = value;
            this->get(key);
            return;
        } else {
            if (umap.size() == this->size) {
                Node *const last = head.before;
                Node *const last_snd = last->before;
                last_snd->next = &head;
                head.before = last_snd;
                umap.erase(last->k);
                delete last;
            }
            Node *const fst = new Node(key, value, &head, head.next);
            head.next->before = fst;
            head.next = fst;
            umap[key] = fst;
        }
    }

    ~LRU() override {
        for (const auto&[k, v]: umap) {
            delete v;
        }
    }
};

std::unique_ptr<LRUCache> leetcode_146::get(int32_t cap) {
    return std::make_unique<LRU>(cap);
}
}

