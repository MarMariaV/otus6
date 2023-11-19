#pragma once

#include <vector>
#include <map>
#include <iostream>
#include <utility>

template <typename T, T def = T{}>
class Matrix
{
public:

	class Item
	{
	public:
       std::map<std::pair<int,int>, T> itemMap;

        int firstIndex = -1;
        int secondIndex = -1;

        Item& operator[](int index)
        {
            secondIndex = index;
            return *this;
        }

       ~Item() {};

        Item& operator=(const T& value)
        {
            if (value != def) {
                itemMap[std::make_pair(firstIndex,secondIndex)] = value;
            }
            else {
                itemMap.erase(std::make_pair(firstIndex,secondIndex));
            }
            return *this;
        }

        void setIndex(int index)
        {
            firstIndex = index;
        }

        bool operator==(const T& value) {
            if (itemMap.find(std::make_pair(firstIndex,secondIndex)) != itemMap.end()) {
                return itemMap.at(std::make_pair(firstIndex,secondIndex)) == value;
            }
            else
                return def == value;
        }

        friend std::ostream &operator<<(std::ostream &out, const Item &thisRow)
        {
            if (thisRow.itemMap.find(std::make_pair(thisRow.firstIndex,thisRow.secondIndex)) != thisRow.itemMap.end()) {
                    out << thisRow.itemMap.at(std::make_pair(thisRow.firstIndex,thisRow.secondIndex));
                }
                else {
                    out << def;
                }
            return out;
        }
	};

    Item itemMatrix;

public:

	Item& operator[](int index)
	{
        itemMatrix.setIndex(index);
		return itemMatrix;
	}
    int size() {
        return itemMatrix.itemMap.size();
	}

    auto begin()
    {
        return itemMatrix.itemMap.begin();
    }

    auto end()
    {
        return itemMatrix.itemMap.end();
    }
};

