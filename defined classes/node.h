#include<list>
#include<QString>
using std::list;
using std::string;
#ifndef NODE_H
#define NODE_H
class node
{
private:
    list<node*> children;
    QString  operation;
    QString value;
    node * left;
    node * right;
public:
    node();
    void insert_chlid(node* chlid);
    void set_operation(QString oper);
    void set_value(QString val);
    void set_left(node * le);
    void set_right(node * rig);
    QString get_operation();
    QString get_value();
    node* get_left();
    node* get_right();
    list<node*> get_childs();
    list<node*> ::iterator  get_first_child();
    list<node*> ::iterator  get_last_child();
    int children_size();
};
#endif // NODE_H
