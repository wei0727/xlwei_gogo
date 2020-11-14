#include <iostream>
#include <vector>
#include "leetcode.h"

/*
    reference
    https://www.oreilly.com/library/view/c-cookbook/0596007612/ch08s10.html

*/

class m_Singleton {
public:
    void set_val(int v) { val = v; }
    int get_val(void) { return val; }

    static m_Singleton* get_instance(void);

private:
    static m_Singleton* inst;
    int val;

    m_Singleton() : val(0) {}
    m_Singleton& operator=(const m_Singleton&) = delete;
    m_Singleton(const m_Singleton&) = delete;
};
m_Singleton* m_Singleton::inst = NULL;

m_Singleton* m_Singleton::get_instance(void)
{
    if (inst == NULL) {
        m_Singleton::inst = new m_Singleton();
    }
    return inst;
}

class m_Normalclass {
public:
    void set_val(int v) { val = v; }
    int get_val(void) { return val; }

private:
    static m_Normalclass* inst;
    int val;
};

void singleton_class_demo()
{
    m_Singleton* p_obj_1;
    m_Singleton* p_obj_2;
    m_Normalclass m_obj_2;
    m_Normalclass m_obj_3;

    p_obj_1 = m_Singleton::get_instance();
    p_obj_2 = m_Singleton::get_instance();

    std::cout << p_obj_1 << " " << p_obj_2  << " " << &m_obj_2 << " " << &m_obj_3 << std::endl;

    p_obj_1->set_val(1);
    std::cout << p_obj_1->get_val() << " " << p_obj_2->get_val() << " " << std::endl;
    p_obj_2->set_val(10);
    std::cout << p_obj_1->get_val() << " " << p_obj_2->get_val() << std::endl;
}