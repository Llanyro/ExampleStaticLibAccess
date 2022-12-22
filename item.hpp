// item.hpp

#ifndef ITEM_HPP_
#define ITEM_HPP_

class Item {
    public:
	virtual ~Item() {}
        virtual const char* getName() = 0;
        virtual int getPrice() = 0;
};

#endif // !ITEM_HPP_
