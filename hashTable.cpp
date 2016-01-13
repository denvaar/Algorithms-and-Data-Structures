#include <iostream>
#include <string>

class Item {
    private:
        std::string key;
        Item *next;
    public:
        Item(std::string k, Item *n = NULL) {
            key = k;
            next = n;
        }
        std::string getKey() const { return key; }
        Item* getNext() { return next; }
        void setNext(Item *n) { next = n; }
};

class LinkedList {
    private:
        Item *head;
        int length;
    public:
        LinkedList() {
            head = new Item("");
            head->setNext(NULL);
            length = 0;
        }
        void insert(Item *item) {
            if (!head->getNext()) {
                head->setNext(item);
                length++;
                return;
            }
            Item *p = head;
            Item *q = head;
            while(q) {
                p = q;
                q = p->getNext();
            }
            p->setNext(item);
            item->setNext(NULL);
            length++;
        }
        bool remove(std::string key) {
            if (!head->getNext()) return false;
            Item *p = head;
            Item *q = head;
            while(q) {
                if (q->getKey() == key) {
                    p->setNext(q->getNext());
                    delete q;
                    length--;
                    return true;
                }
                p = q;
                q = p->getNext();
            }
            return false;
        }
        Item* getItem(std::string key) {
            Item *p = head;
            Item *q = head;
            while(q) {
                p = q;
                if ((p != head) && (p->getKey() == key)) return p;
                q = p->getNext();
            }
            return NULL;
        }
        void printList() {
            if (length == 0) {
                std::cout << "{ }" << std::endl;
                return;
            }
            Item *p = head;
            Item *q = head;
            std::cout << "{";
            while (q) {
                p = q;
                if (p != head) {
                    std::cout << p->getKey();
                    if (p->getNext()) std::cout << ", ";
                }
                q = p->getNext();
            }
            std::cout << "}" << std::endl;
        }
        int getLength() const {
            return length;
        }
        ~LinkedList() {
            Item *p = head;
            Item *q = head;
            while(q) {
                p = q;
                q = p->getNext();
                if (q) delete p;
            }
        }
};


class HashTable {
    private:
        LinkedList *list;
        int length;
        int hash(std::string key) {
            int value = 0;
            for (int i = 0; i < key.length(); i++)
                value += key[i];
            return (value * key.length()) % length;
        }
    public:
        HashTable(int length = 13) {
            if (length <= 0) this->length = 13;
            list = new LinkedList[length];
            this->length = length;
        }
        void insert(Item *item) {
            int index = hash(item->getKey());
            list[index].insert(item);
        }
        bool remove(std::string key) {
            int index = hash(key);
            return list[index].remove(key);
        }
        Item* getItem(std::string key) {
            int index = hash(key);
            return list[index].getItem(key);
        }
        void printTable()
        {
            std::cout << "Hash Table:\n";
            for ( int i = 0; i < length; i++ )
            {
                std::cout << "Bucket " << i + 1 << ": ";
                list[i].printList();
            }
        }
        ~HashTable() { delete [] list; }
};

int main(int argc, char *argv[]) {
    Item *a = new Item("Denver");
    Item *b = new Item("Niccole");
    Item *c = new Item("Todd");
    Item *d = new Item("Dennis");

    HashTable table;

    table.insert(a);
    table.insert(b);
    table.insert(c);
    table.insert(d);
    table.printTable();
    std::cout << table.getItem("Denver")->getKey() << std::endl;
    table.remove("Denver");
    table.printTable();
    if (!table.getItem("Denver"))
        std::cout << "Doesn't exist" << std::endl;
    return 0;
}
