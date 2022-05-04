#include "Map.h"
#include "MapIterator.h"

Map::Map()
{
    // TODO - Implementation
    this->count = 0;
    this->head = new Node();
    this->head->node = nullptr;
    this->head->kv_pair.first = NULL_TVALUE;
    this->head->kv_pair.second = NULL_TVALUE;
}

Map::~Map()
{
    // TODO - Implementation
    while (this->head != nullptr)
    {
        Node *curr = this->head;
        this->head = this->head->node;
        delete[] curr;
    }
}

TValue Map::add(TKey c, TValue v)
{
    // TODO - Implementation
    // Complexity theta(this->count)
    if (this->count == 0)
    {
        this->head->kv_pair.first = c;
        this->head->kv_pair.second = v;
        this->count++;
    }
    else
    {
        TValue found;
        Node *i = this->head;
        while (i != nullptr)
        {
            if (i->kv_pair.first == c)
            {
                found = i->kv_pair.second;
                i->kv_pair.second = v;
                return found;
            }
            i = i->node;
        }

        Node *new_node = new Node();

        new_node->kv_pair.first = c;
        new_node->kv_pair.second = v;
        new_node->node = this->head;

        this->head = new_node;
        this->count++;
    }
    return NULL_TVALUE;
}

TValue Map::search(TKey c) const
{
    // TODO - Implementation
    // complexity theta(this->count)
    Node *i = this->head;
    while (i != nullptr)
    {
        if (i->kv_pair.first == c)
            return i->kv_pair.second;
        i = i->node;
    }
    return NULL_TVALUE;
}

TValue Map::remove(TKey c)
{
    // TODO - Implementation
    // complexity theta(this->count)
    Node *i = this->head->node;
    Node *prev = this->head;
    if (i == nullptr && prev->kv_pair.first == c)
    {
        TValue found = prev->kv_pair.second;
        prev->kv_pair.first = NULL_TVALUE;
        prev->kv_pair.second = NULL_TVALUE;
        prev->node = nullptr;
        this->count--;
        return found;
    }
    while (i != nullptr)
    {
        if (i->kv_pair.first == c)
        {
            TValue found = i->kv_pair.second;
            prev->node = i->node;
            delete[] i;
            this->count--;
            return found;
        }
        prev = i;
        i = i->node;
    }
    return NULL_TVALUE;
}

int Map::size() const
{
    // TODO - Implementation
    // complexity - theta(1)
    return this->count;
}

bool Map::isEmpty() const
{
    // TODO - Implementation
    // complexity - theta(1)
    if (this->head->node == nullptr && this->head->kv_pair.first == NULL_TVALUE)
        return true;
    return false;
}

void Map::empty()
{
    while (this->isEmpty() == false)
    {
        this->remove(this->head->kv_pair.first);
        this->head = this->head->node;
    }
}

MapIterator Map::iterator() const
{
    return MapIterator(*this);
}
