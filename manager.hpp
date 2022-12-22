/*
 * manager.hpp
 *
 *  Created on: Dec 22, 2022
 *      Author: llanyro
 */

#ifndef MANAGER_HPP_
#define MANAGER_HPP_

#include <map>

#include "item.hpp"

/*
#include <vector>
#include <algorithm>
#include <iostream>

class Manager {
    public:
        static Manager* getInstance() {
            static Manager instance;
            return &instance;
        }

        void addItem(Item* item) {
            std::cout << "Singleton Int mem: " << this << std::endl;
            items.push_back(item);
        }
        void removeItem(Item* item) {
            auto it = std::find(items.begin(), items.end(), item);
            if (it != items.end())
                items.erase(it);
        }
        std::vector<Item*> getItems() { return items; }

    private:
        std::vector<Item*> items;

        Manager() = default;
        Manager(const Manager&) = delete;
        Manager& operator=(const Manager&) = delete;
};
*/


class Manager {
    public:
        std::map<Item*, Item*> items;
    public:
        static Manager* getInstance() {
            static Manager instance;
            return &instance;
        }
        void addItem(Item* item) { items[item] = item; }
        void removeItem(Item* item) { items.erase(item); }
    private:
        Manager() {}
};

#endif // !MANAGER_HPP_
