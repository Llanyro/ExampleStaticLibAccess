/*
 * dll.cpp
 *
 *  Created on: Dec 22, 2022
 *      Author: llanyro
 */

#include "dll.hpp"

class Apple : public Item {
    public:
        const char* getName() override { return "Apple"; }
        int getPrice() override { return 20; }
};

Item* createApple() { return new Apple(); }

