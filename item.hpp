/*
 * item.hpp
 *
 *  Created on: Dec 22, 2022
 *      Author: llanyro
 */

#ifndef ITEM_HPP_
#define ITEM_HPP_

class Item {
    public:
	virtual ~Item() {}
        virtual const char* getName() = 0;
        virtual int getPrice() = 0;
};

#endif // !ITEM_HPP_
