#ifndef I_TREE_H
#define I_TREE_H

template<class ItemType>
class ITree{
public: 
    virtual bool isEmpty() const = 0;
    virtual int getHeight() const = 0;
    virtual ItemType getRootData() const = 0;
    virtual bool add(const ItemType& newEntry) = 0;
    virtual ItemType getEntry(const ItemType& anEntry) const = 0;
    //virtual int getNumberOfNodes() const = 0;
    //virtual bool remove(const ItemType& anEntry) = 0;
    //virtual void clear() = 0;
    //virtual bool contains(const ItemType& anEntry) const = 0;
    //virtual ~ITree() {}
};

#endif