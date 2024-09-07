#include <bits/stdc++.h>
using namespace std;

struct Column;
struct Cell;

struct Column {
	int value;
	vector<Cell> cells;
};
 
struct Cell {
	Column *previous_column, *next_column;
};

class SkipList {
    static const int MAX_LEVEL = 20;
    Column* head, *tail;

    SkipList() {
        head = new Column;
        tail = new Column;
        head->value = 0;
        tail->value = 0;
        for (int i = 0; i < MAX_LEVEL; i++) {
            head->cells.push_back((Cell){NULL, tail});
            tail->cells.push_back((Cell){head, NULL});
        }
    }
	bool empty() {
        return head->cells[0].next_column == tail;
    }
	Column *lower_bound(int value) {
        Column *iter = head;
        for(int level = MAX_LEVEL - 1; level >= 0; level--) {
            while(iter->cells[level].next_column != tail && iter->cells[level].next_column->value < value) {
                iter = iter->cells[level].next_column;
            }
        }
        return iter->cells[0].next_column;
    }
	Column *upper_bound(int value) {
        Column *iter = head;
        for(int level = MAX_LEVEL - 1; level >= 0; level--) {
            while(iter->cells[level].next_column != tail && iter->cells[level].next_column->value <= value) {
                iter = iter->cells[level].next_column;
            }
        }
        return iter->cells[0].next_column;
    }
	void insert(int value) {
        Column *temp = lower_bound(value);
        if(temp != tail && temp->value == value) {
            return;
        }
        Column *inserted_column = new Column;
        inserted_column->value = value;
        inserted_column->cells.push_back((Cell){NULL, NULL});
        while(inserted_column->cells.size() < MAX_LEVEL && rand() % 2 == 0) {
            inserted_column->cells.push_back((Cell){NULL, NULL});
        }
        Column *iter = head;
        for(int level = MAX_LEVEL - 1; level >= 0; level--) {
            while(iter->cells[level].next_column != tail && iter->cells[level].next_column->value < value) {
                iter = iter->cells[level].next_column;
            }
            if(level < inserted_column->cells.size()) {
                Column *next_iter = iter->cells[level].next_column;
                iter->cells[level].next_column = inserted_column;
                next_iter->cells[level].previous_column = inserted_column;
                inserted_column->cells[level].previous_column = iter;
                inserted_column->cells[level].next_column = next_iter;
            }
        }
    }
	void erase(int value) {
        Column *erased_column = lower_bound(value);
        if(erased_column == tail || erased_column->value != value) {
            return;
        }
        Column *iter = head;
        for(int level = MAX_LEVEL - 1; level >= 0; level--) {
            while(iter->cells[level].next_column != tail && iter->cells[level].next_column->value <= value) {
                iter = iter->cells[level].next_column;
            }
            if(iter == erased_column) {
                Column *previous_iter = iter->cells[level].previous_column, *next_iter = iter->cells[level].next_column;
                previous_iter->cells[level].next_column = next_iter;
                next_iter->cells[level].previous_column = previous_iter;
            }
        }
        delete erased_column;
    }
};