#ifndef I_LIST
#define I_LIST

template<class ItemType>
class I_List{
public:
    virtual bool isEmpty() const = 0;
    virtual int getLength() const = 0;
    virtual insert(int newPos, const ItemType& newEntry) = 0;
    virtual bool remove(int pos) = 0;
    virtual void clear () = 0;
    virtual ItemType getEntry(int pos) const = 0;
    virtual ItemType replace(int pos, const ItemType& newEntry) = 0;
    virtual ~I_List() {}
};

#endif