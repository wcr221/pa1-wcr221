#include <vector>
#include <list>
#include <set>
#include <unordered_set>

using namespace std;

class Set
{
public:
    virtual bool insert(int key) = 0;
    virtual bool remove(int key) = 0;
    virtual bool find(int key) = 0;
};

class arraySet : public Set
{
private:
    vector<int> setPrime;

public:
    arraySet(int size, int max_key)
    {
        for (int i = 0; i < (size / 2); i++)
        {
            int key = rand() % max_key;
            while (!insert(key))
            {
                key = rand() % max_key;
            }
        }
    }

    bool insert(int key)
    {
        // for each loop
        for (int x : setPrime)
        {
            if (x == key)
            {
                return false;
            }
            // check if key = x
            // if it is, return false
            // if it is not, use push_back to add key to the end of setPrime and return true
        }
        setPrime.push_back(key);
        return true;
    }

    bool remove(int key)
    {
        for (vector<int>::iterator it = setPrime.begin(); it != setPrime.end(); it++)
        {
            if (*it == key)
            {
                setPrime.erase(it);
                return true;
            }
            // if you find it, use function erase to remove key and return true
            // else return false
        }
        return false;
    }

    bool find(int key)
    {
        for (int x : setPrime)
        {
            if (key == x)
            {
                return true;
            }
            // check if key = x
            // if it is, return true
        }
        return false;
        // when you check them all and no true return false
    }
};

class hashSet : public Set
{
private:
    unordered_set<int> setPrime;

public:
    hashSet(int size, int max_key)
    {
        for (int i = 0; i < (size / 2); i++)
        {
            int key = rand() % max_key;
            while (!insert(key))
            {
                key = rand() % max_key;
            }
        }
    }

    bool insert(int key)
    {
        // for each loop
        for (int x : setPrime)
        {
            if (x == key)
            {
                return false;
            }
            // check if key = x
            // if it is, return false
            // if it is not, use push_back to add key to the end of setPrime and return true
        }
        setPrime.insert(key);
        return true;
    }

    bool remove(int key)
    {
        for (unordered_set<int>::iterator it = setPrime.begin(); it != setPrime.end(); it++)
        {
            if (*it == key)
            {
                setPrime.erase(it);
                return true;
            }
            // if you find it, use function erase to remove key and return true
            // else return false
        }
        return false;
    }

    bool find(int key)
    {
        for (int x : setPrime)
        {
            if (key == x)
            {
                return true;
            }
            // check if key = x
            // if it is, return true
        }
        return false;
        // when you check them all and no true return false
    }
};

class treeSet : public Set
{
private:
    set<int> setPrime;

public:
    treeSet(int size, int max_key)
    {
        for (int i = 0; i < (size / 2); i++)
        {
            int key = rand() % max_key;
            while (!insert(key))
            {
                key = rand() % max_key;
            }
        }
    }

    bool insert(int key)
    {
        // for each loop
        for (int x : setPrime)
        {
            if (x == key)
            {
                return false;
            }
            // check if key = x
            // if it is, return false
            // if it is not, use push_back to add key to the end of setPrime and return true
        }
        setPrime.insert(key);
        return true;
    }

    bool remove(int key)
    {
        for (int x : setPrime)
        {
            if (x == key)
            {
                setPrime.erase(x);
                return true;
            }
            // if you find it, use function erase to remove key and return true
            // else return false
        }
        return false;
    }

    bool find(int key)
    {
        for (int x : setPrime)
        {
            if (key == x)
            {
                return true;
            }
            // check if key = x
            // if it is, return true
        }
        return false;
        // when you check them all and no true return false
    }
};

class listSet : public Set
{
private:
    list<int> setPrime;

public:
    listSet(int size, int max_key)
    {
        for (int i = 0; i < (size / 2); i++)
        {
            int key = rand() % max_key;
            while (!insert(key))
            {
                key = rand() % max_key;
            }
        }
    }
    bool insert(int key)
    {
        // for each loop
        for (int x : setPrime)
        {
            if (x == key)
            {
                return false;
            }
            // check if key = x
            // if it is, return false
            // if it is not, use push_back to add key to the end of setPrime and return true
        }
        setPrime.push_back(key);
        return true;
    }

    bool remove(int key)
    {
        for (list<int>::iterator it = setPrime.begin(); it != setPrime.end(); it++)
        {
            if (*it == key)
            {
                setPrime.erase(it);
                return true;
            }
            // if you find it, use function erase to remove key and return true
            // else return false
        }
        return false;
    }

    bool find(int key)
    {
        for (int x : setPrime)
        {
            if (key == x)
            {
                return true;
            }
            // check if key = x
            // if it is, return true
        }
        return false;
        // when you check them all and no true return false
    }
};