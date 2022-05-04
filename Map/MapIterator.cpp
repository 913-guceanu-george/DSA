#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;

MapIterator::MapIterator(const Map &d) : map(d)
{
    // TODO - Implementation
    this->curr = nullptr;
}

void MapIterator::first()
{
    // TODO - Implementation
    this->curr = this->map.head;
}

void MapIterator::next()
{
    // TODO - Implementation
    if (this->curr != nullptr)
    {
        this->curr = this->curr->node;
        return;
    }
    throw std::exception();
}

TElem MapIterator::getCurrent()
{
    // TODO - Implementation
    if (this->curr != nullptr)
    {
        return this->curr->kv_pair;
    }
    throw std::exception();
    // return NULL_TELEM;
}

bool MapIterator::valid() const
{
    // TODO - Implementation
    if (this->curr != nullptr)
        return true;
    return false;
}
