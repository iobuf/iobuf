#include "list.h"
#include <iostream>

ilist_item *ilist::find(int value) {
    ilist_item *ptr = _at_front;
    while (ptr) {
        if (ptr->value() == value)
            break;
        ptr = ptr->next();
    }
    return ptr;
}

void ilist::display(std::ostream &os) {
    os << "\n(" << _size << ") [";
    ilist_item *ptr = _at_front;
    while (ptr) {
        os << ptr->value() << " ";
        ptr = ptr->next();
    }
    os << "]\n";
}

void ilist::insert_all(const ilist &rhs) {
    ilist_item *pt = rhs._at_front;
    while (pt) {
        insert_end(pt->value());
        pt = pt->next();
    }
}

void ilist::remove_all() {
    while (_at_front)
        remove_front();
    _size = 0;
    _at_end = 0;
    _at_front = 0;
}

int ilist::remove(int value) {
    ilist_item *plist = _at_front;
    int elem_cnt = 0;
    while (plist && plist->value() == value) {
        plist = plist->next();
        remove_front();
        ++elem_cnt;
    }

    if (!plist)
        return elem_cnt;

    ilist_item *prev = plist;
    plist = plist->next();
    while (plist) {
        if (plist->value() == value) {
            prev->next(plist->next());
            if (_current == plist)
                _current = prev->next();
            delete plist;
            ++elem_cnt;
            bump_down_size();
            plist = prev->next();
            if (!plist) {
                _at_end = prev;
                return elem_cnt;
            }
        } else {
            prev = plist;
            plist = plist->next();
        }
    }
    return elem_cnt;
}

void ilist::concat(const ilist &list) {
    ilist_item *ptr = list._at_front;
    while (ptr) {
        insert_end(ptr->value());
        ptr = ptr->next();
    }
}

void ilist::reverse() {
    ilist_item *ptr = _at_front;
    ilist_item *prev = 0;
    _at_front = _at_end;
    _at_end = ptr;
    while (ptr != _at_front) {
        ilist_item *tmp = ptr->next();
        ptr->next(prev);
        prev = ptr;
        ptr = tmp;
    }
    _at_front->next(prev);
}
