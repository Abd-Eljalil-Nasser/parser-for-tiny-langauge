
#include "node.h"
node::node()
{
    operation = "";
    value = "";
    left = nullptr;
    right = nullptr;
}
void node::insert_chlid(node* chlid)
{
    children.push_back(chlid);
}
void  node::set_operation(QString oper)
{
    operation = oper;
}
void node::set_value(QString val)
{
    value = val;
}
void  node::set_left(node * le)
{
    left = le;
}
void  node::set_right(node * rig)
{
    right = rig;
}
node*  node::get_left()
{
    return left;
}
node* node::get_right()
{
    return right;
}
list<node*> node::get_childs()
{
    return children;
}
QString node::get_operation()
{
    return operation;
}
QString node::get_value()
{
    return value;
}
list<node*> ::iterator node ::get_first_child()
{
    return children.begin();
}
list<node *> ::iterator node::get_last_child()
{
    return children.end();
}
int node::children_size()
{
    return children.size();
}
