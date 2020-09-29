#include "widget.h"
#include<QLayout>
#include<QMessageBox>
#include<show_tree.h>
#include<QScrollArea>
#include<form.h>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setputUi();
}

Widget::~Widget()
{
    delete label;
    delete inputbox;
}
// two match + and - operators using grammer rule addop ---> +|-
bool match_addopp(QString token_types)
{
    if (token_types == "Plus" || token_types == "Minus")
    {
        return true;
    }
    return false;
}
// two semi_colon
bool semi_colon(QString token_types)
{
    if (token_types == "Semicolon")
    {
        return true;
    }
    return false;
}
// to match * and / operators using grammer rule mulop ---> * | /
bool match_mulopp(QString token_types)
{
    if (token_types == "Division" || token_types == "Multiply")
    {
        return true;
    }
    return false;
}
// to match < or = operators comparison_op ----> < | =
bool match_comparison_opp(QString token_types)
{
    if (token_types == "Smaller than" || token_types == "Equal")
    {
        return true;
    }
    return false;
}
bool match_exp(list<QString> &token_types, list<QString> &token_Value, list<QString> ::iterator &it_types, list<QString> ::iterator &it_values, int &length, node * &input);
bool match_factor(list<QString> &token_types, list<QString> &token_Value, list<QString> ::iterator &it_types, list<QString> ::iterator &it_values, int &length, node * &input);
bool match_term(list<QString> &token_types, list<QString> &token_Value, list<QString> ::iterator &it_types, list<QString> ::iterator &it_values, int &length, node * &input);
bool match_simple_exp(list<QString> &token_types, list<QString> &token_Value, list<QString> ::iterator &it_types, list<QString> ::iterator &it_values, int &lengthh, node * &input);
bool match_read(list<QString> &token_types, list<QString> &token_Value, list<QString> ::iterator &it_types, list<QString> ::iterator &it_values, int &length, node * &input);
bool match_write(list<QString> &token_types, list<QString> &token_Value, list<QString> ::iterator &it_types, list<QString> ::iterator &it_values, int &length, node * &input);
bool match_assign(list<QString> &token_types, list<QString> &token_Value, list<QString> ::iterator &it_types, list<QString> ::iterator &it_values, int &length, node * &input);
bool match_repeat(list<QString> &token_types, list<QString> &token_Value, list<QString> ::iterator &it_types, list<QString> ::iterator &it_values, int &lengthh, node * &input);
bool match_if(list<QString> &token_types, list<QString> &token_Value, list<QString> ::iterator &it_types, list<QString> ::iterator &it_values, int &length,node * &input);
bool match_statement(list<QString> &token_types, list<QString> &token_Value, list<QString> ::iterator &it_types, list<QString> ::iterator &it_values, int &length, node *&input);
bool match_statement_seq(list<QString> &token_types, list<QString> &token_Value, list<QString> ::iterator &it_types, list<QString> ::iterator &it_values, int &length,node *&input);





// match factor using grammer rule factor ----> (exp)| number| identifier
bool match_factor(list<QString> &token_types, list<QString> &token_Value, list<QString> ::iterator &it_types, list<QString> ::iterator &it_values, int &length, node * &input)
{
    //check that we don't get out of the range of the list
    if (length != token_types.size())
    {
        int countleft = 0;
        if (*it_types == "Open Bracket")
        {
            // increament the iterators and the length
            it_types++;
            it_values++;
            length++;
            // new temp_lists to check the expression between the open and close bracket
            // if the input was  : write ((kadgkladgka+10)) we have matched write
            // now if the input is   ((kadgkladgka+10))
            // new list store (kadgkladgka+10) we pass this the match_exp() function ,match_exp() will call match_simple_exp() function
            // match_simple_exp() will call match_term() function
            // match_term() will call match_factor() again with a list that store (kadgkladgka+10)
            // input now is (kadgkladgka+10)
            // new list store kadgkladgka+10 we pass this the match_exp() function ,match_exp() will call match_simple_exp() function
            // match_simple_exp() will call match_term() function
            // match_term() will call match_factor() again with a list that store kadgkladgka+10
            // match_factor() function will specify that kadgkladgka is identifier and return true
            // now we back to term function and it will check  {mulopp term } as the grammer rule says: factor {mulopp factor }
            // it will find that there is no mulopp so it return true because the factor was matched
            // now we go back to simple_exp function again it will check {addop term } as grammer rule says : term {addop term}
            // it will check for addop
            // call match_addopp () which  return true because it find +
            // check if the list still have term as the grammer rule says
            // it will find that it  still have -->  10
            // it will call match_term() function again list
            // match_term() calls match_factor() function
            // match_factor() will find that 10 match a number , it returns true
            // match_term() return true
            // match_simple_exp() return true
            // match_exp() return true
            // mtach_write ()  return true
            // match_statement() return true
            // match_statement_seq() return true  :))))))))))
            // والله و عمولها الرجالة و رفعوا رأس مصر بدلنا  :))))))))))

            list<QString> temp_types;
            list<QString> temp_Values;
            /*
            the comming if , and 3 whiles to make the newlist correctly
            for example
            if we have (fguoeh(10*4+h)jsfngjsf)
            we want the new list store  fguoeh(10*4+h)jsfngjsf which means everything between the brackets
            */
            if (length != token_types.size())
            {
                while (*it_types != "Close Bracket")
                {
                    if (*it_types == "Open Bracket")
                        countleft++;
                    temp_types.push_back(*it_types);
                    temp_Values.push_back(*it_values);
                    it_types++;
                    it_values++;
                    length++;
                }
                while (countleft!=0)
                {
                    temp_types.push_back(*it_types);
                    temp_Values.push_back(*it_values);
                    it_types++;
                    it_values++;
                    length++;
                    countleft--;

                }
                while (*it_types != "Close Bracket")
                {
                    temp_types.push_back(*it_types);
                    temp_Values.push_back(*it_values);
                    it_types++;
                    it_values++;
                    length++;
                }
                int newlength = 0;
                it_types++;
                it_values++;
                length++;
                node * newexp = new node;
                list<QString> ::iterator temp_type = temp_types.begin();
                list<QString> ::iterator temp_value = temp_Values.begin();
                if (match_exp(temp_types, temp_Values,temp_type, temp_value, newlength, newexp))
                {
                    input=newexp;
                    return true;
                }
                else
                {
                    return false;
                }

            }
        }
        else if (*it_types == "NUMBER")
        {
         //add node
         //set it operation to const
         //set value to (*it_value)
            input->set_operation("const");
            input->set_value('(' + *it_values + ')');
            it_types++;
            it_values++;
            length++;
            return true;
        }
        else if (*it_types == "IDENTIFIER")
        {
            //add node
            //set it operation to id
            //set value to (*it_value)
            input->set_operation("id");
            input->set_value('(' + *it_values + ')');
            it_types++;
            it_values++;
            length++;
            return true;
        }
    }
    return false;
}
// match term using grammer rule term ----> factor { mulop factor }
bool match_term(list<QString> &token_types, list<QString> &token_Value, list<QString> ::iterator &it_types, list<QString> ::iterator &it_values, int &length, node * &input)
{
    //stack<node*> nodes;
    node *first_factor = new node;
    if (length != token_types.size())
    {
        if (match_factor(token_types, token_Value, it_types, it_values, length, first_factor))
        {
            node * temp_op = nullptr;
            node * temp = first_factor;
            //temp = first_factor;
            //nodes.push(first_factor);
            if (length != token_types.size())
            {
                while (length != token_types.size())
                {
                    if (match_mulopp(*it_types))
                    {
                        //add node
                        //set it operation to op
                        //set value to (*it_value)
                        node *mul_op = new node;
                        mul_op->set_operation("op");
                        mul_op->set_value('(' + *it_values + ')');
                        temp_op = mul_op;
                        it_types++;
                        it_values++;
                        length++;
                        if (length != token_types.size())
                        {
                            node *second_factor = new node;
                            if (match_factor(token_types, token_Value, it_types, it_values, length, second_factor))
                            {
                                //nodes.push(mul_op);
                                //nodes.push(second_factor);
                                //set_left_chlid_then_right
                                mul_op->insert_chlid(temp);
                                mul_op->insert_chlid(second_factor);
                                temp = mul_op;
                                continue;
                            }
                            else
                            {
                                return false;
                            }
                        }
                        else
                        {
                            return false;
                        }
                      }
                      else
                      {
                        break;
                      }
                }
            }
            /*
            if (nodes.size() != 1)
            {
                nodes.pop();
                node* x = nodes.top();
                input->insert_chlid(x);
            }
            else
            {
                node* x = nodes.top();
                input->insert_chlid(x);
            }
            */
            if (temp_op != nullptr)
            {
                //input->insert_chlid(temp_op);
                input = temp_op;
                /*input->set_operation(temp_op->get_operation());
                input->set_value(temp_op->get_value());
                for (list<node *> ::iterator it = (temp_op->get_childs().begin());it != (temp_op->get_childs()).end();it++)
                {
                    input->insert_chlid(*it);
                }
                */

                return true;
            }
            //input->insert_chlid(first_factor);
            input = first_factor;
            /*input->set_operation(first_factor->get_operation());
            input->set_value(first_factor->get_value());
            for (list<node *> ::iterator it = (first_factor->get_childs()).begin();it != (first_factor->get_childs()).end();it++)
            {
                input->insert_chlid(*it);
            }

            */
            //input->set_operation(first_factor->get_operation());
            //input->set_value(first_factor->get_value());
            return true;
        }
    }
    return false;
}
// match match_simple_exp using grammer rule term ----> term { addop term}
bool match_simple_exp(list<QString> &token_types, list<QString> &token_Value, list<QString> ::iterator &it_types, list<QString> ::iterator &it_values, int &length, node * &input)
{

    if (length != token_types.size())
    {
        node *first_Term = new node;
        if (match_term(token_types, token_Value, it_types, it_values, length, first_Term))
        {
            node * temp_op = nullptr;
            node * temp = first_Term;
            if (length != token_types.size())
            {
                while (length != token_types.size())
                {
                    if (match_addopp(*it_types))
                    {
                        //add node
                        //set it operation to op
                        //set value to (*it_value)
                        node *add_op = new node;
                        add_op->set_operation("op");
                        add_op->set_value('(' + *it_values + ')');
                        temp_op = add_op;
                        it_types++;
                        it_values++;
                        length++;
                        if (length != token_types.size())
                        {
                            node *second_Term = new node;
                            if (match_term(token_types, token_Value, it_types, it_values, length, second_Term))
                            {
                                add_op->insert_chlid(temp);
                                add_op->insert_chlid(second_Term);
                                temp = add_op;
                                continue;
                            }
                            else
                            {
                                return false;
                            }
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (temp_op != nullptr)
            {
                //input->insert_chlid(temp_op);
                input = temp_op;
                return true;
            }
            //input->insert_chlid(first_Term);
            input = first_Term;
            return true;
        }
    }
    return false;
}
// mtach expression using grammer rule exp ----> Simple_exp [Comparison_op Simple_exp]
bool match_exp(list<QString> &token_types, list<QString> &token_Value, list<QString> ::iterator &it_types, list<QString> ::iterator &it_values, int &length, node * &input)
{
    //check that we don't get out of the range of the list
    if (length != token_types.size())
    {
        // call the function match_simple_exp
        node * first_exp = new node;
        if (match_simple_exp(token_types, token_Value, it_types, it_values, length,first_exp))
        {
            node * temp_op = nullptr;
            //check that we don't get out of the range of the list
            if (length != token_types.size())
            {
                //check that we don't get out of the range of the list
                if (length != token_types.size())
                {
                    if (match_comparison_opp(*it_types))
                    {
                        // increament the iterators and the length
                        node * comp_op = new node;
                        comp_op->set_operation("op");
                        comp_op->set_value('('+*it_values+')');
                        temp_op = comp_op;
                        it_types++;
                        it_values++;
                        length++;
                        //check that we don't get out of the range of the list
                        if (length != token_types.size())
                        {
                            node * second_exp = new node;
                            if (match_simple_exp(token_types, token_Value, it_types, it_values, length, second_exp))
                            {
                                comp_op->insert_chlid(first_exp);
                                comp_op->insert_chlid(second_exp);
                                //input->insert_chlid(comp_op);
                                input = comp_op;
                                return true;
                            }
                        }
                    }
                }
            }
            //input->insert_chlid(first_exp);
            input = first_exp;
            return true;

        }
    }
    return false;
}
// match read_statment using grammer rule read_statment ---> read identifier
bool match_read(list<QString> &token_types, list<QString> &token_Value, list<QString> ::iterator &it_types, list<QString> ::iterator &it_values, int &length, node * &input)
{
    if (length != token_types.size())
    {
        int temp_length = length;
        list<QString> ::iterator it_temp_type = it_types;
        list<QString> ::iterator it_temp_value = it_values;
        if (*it_temp_type == "READ")
        {
            //add node
            //set it operation to read
            input->set_operation("read");
            it_temp_type++;
            it_temp_value++;
            temp_length++;
            if (length != token_types.size())
            {
                if (*it_temp_type == "IDENTIFIER")
                {
                input->set_value('(' + *it_temp_value + ')');
                //set value to ((*it_value))
                    it_temp_type++;
                    it_temp_value++;
                    temp_length++;
                    it_types = it_temp_type;
                    it_values = it_temp_value;
                    length = temp_length;
                    return true;
                }
            }
        }
    }
}
// match write_statment using grammer rule write_statment ---> write exp
bool match_write(list<QString> &token_types, list<QString> &token_Value, list<QString> ::iterator &it_types, list<QString> ::iterator &it_values, int &length, node * &input)
{
    if (length != token_types.size())
    {
        int temp_length = length;
        list<QString> ::iterator it_temp_type = it_types;
        list<QString> ::iterator it_temp_value = it_values;
        if (*it_temp_type == "WRITE")
        {
            //add node
            //set it operation to write
            input->set_operation("write");
            it_temp_type++;
            it_temp_value++;
            temp_length++;
            if (length != token_types.size())
            {
                //add children ->>>> exp
                node * newexp = new node;
                if (match_exp(token_types, token_Value, it_temp_type, it_temp_value, temp_length, newexp))
                {
                    input->insert_chlid(newexp);
                    it_types = it_temp_type;
                    it_values = it_temp_value;
                    length = temp_length;
                    return true;
                }
                else
                {
                    delete newexp;
                    return false;
                }
            }
        }
    }
    return false;
}
// match assign_statment using grammer rule assign_statment---> identifier := exp
bool match_assign(list<QString> &token_types, list<QString> &token_Value, list<QString> ::iterator &it_types, list<QString> ::iterator &it_values, int &length, node * &input)
{
    if (length != token_types.size())
    {
        int temp_length = length;
        list<QString> ::iterator it_temp_type = it_types;
        list<QString> ::iterator it_temp_value = it_values;
        if (*it_temp_type == "IDENTIFIER")
        {
            //add node
            //set it operation to assign
            // set it value t= ->>>> (*it_vlaue)
            // add children
            input->set_operation("assign");
            input->set_value('(' + *it_temp_value + ')');
            it_temp_type++;
            it_temp_value++;
            temp_length++;
            if (length != token_types.size())
            {
                if (*it_temp_type == "ASSIGN")
                {
                    it_temp_type++;
                    it_temp_value++;
                    temp_length++;
                    if (length != token_types.size())
                    {
                        node * newexp = new node;
                        if (match_exp(token_types, token_Value, it_temp_type, it_temp_value, temp_length, newexp))
                        {
                            input->insert_chlid(newexp);
                            it_types = it_temp_type;
                            it_values= it_temp_value ;
                            length = temp_length;
                            return true;
                        }
                        else
                        {
                            delete newexp;
                            return false;
                        }
                    }
                }
            }
        }
    }
    return false;
}
// match repeat_statment using grammer rule repeat_statment ---> identifier := exp
bool match_repeat(list<QString> &token_types, list<QString> &token_Value, list<QString> ::iterator &it_types, list<QString> ::iterator &it_values, int &length,node *&input)
{
    if (length != token_types.size())
    {
        int temp_length = length;
        list<QString> ::iterator it_temp_type = it_types;
        list<QString> ::iterator it_temp_value = it_values;
        if (*it_temp_type == "REPEAT")
        {
            it_temp_type++;
            it_temp_value++;
            temp_length++;
            input->set_operation("repeat");
            if (length != token_types.size())
            {
                node* body = new node;
                if (match_statement_seq(token_types, token_Value, it_temp_type, it_temp_value, temp_length, body))
                {
                    if (length !=token_types.size())
                    {
                        if (*it_temp_type == "UNTIL")
                        {
                            it_temp_type++;
                            it_temp_value++;
                            temp_length++;
                            if (length != token_types.size())
                            {
                                node * test = new node;
                                 if (match_exp(token_types, token_Value, it_temp_type, it_temp_value, temp_length, test))
                                {
                                     input->insert_chlid(body);
                                     input->insert_chlid(test);
                                     it_types = it_temp_type;
                                     it_values = it_temp_value;
                                     length = temp_length;
                                     return true;
                                }
                                 else
                                 {
                                     delete test;
                                     return false;
                                 }
                            }
                        }
                    }

                }

            }
        }
    }
    return false;
}
// match if_statment using grammer rule if_statment ---> if exp then statment_sequance [else statment_sequance] end
bool match_if(list<QString> &token_types, list<QString> &token_Value, list<QString> ::iterator &it_types, list<QString> ::iterator &it_values, int &length, node * &input)
{
    if (length !=token_types.size())
    {
        int temp_length = length;
        list<QString> ::iterator it_temp_type = it_types;
        list<QString> ::iterator it_temp_value = it_values;
        if (*it_temp_type == "IF")
        {
            input->set_operation("if");
            it_temp_type++;
            it_temp_value++;
            temp_length++;
            if (temp_length !=token_types.size())
            {
                node * test = new node;
                if (match_exp(token_types, token_Value, it_temp_type, it_temp_value, temp_length, test))
                {
                    if (temp_length !=token_types.size())
                    {

                        if (*it_temp_type == "THEN")
                        {
                            it_temp_type++;
                            it_temp_value++;
                            temp_length++;
                            if (temp_length !=token_types.size())
                            {
                                node * then_part = new node;
                                if (match_statement_seq(token_types, token_Value, it_temp_type, it_temp_value, temp_length, then_part))
                                {
                                    if (temp_length !=token_types.size())
                                    {
                                        if (*it_temp_type == "ELSE")
                                        {
                                            it_temp_type++;
                                            it_temp_value++;
                                            temp_length++;
                                            if (temp_length !=token_types.size())
                                            {
                                            node * else_part = new node;
                                                if (match_statement_seq(token_types, token_Value, it_temp_type, it_temp_value, temp_length, else_part))
                                                {
                                                    if (temp_length !=token_types.size())
                                                    {
                                                        if (*it_temp_type == "END")
                                                        {
                                                            input->insert_chlid(test);
                                                            input->insert_chlid(then_part);
                                                            input->insert_chlid(else_part);
                                                            it_temp_type++;
                                                            it_temp_value++;
                                                            temp_length++;
                                                            it_types = it_temp_type;
                                                            it_values = it_temp_value;
                                                            length = temp_length;
                                                            return true;
                                                        }
                                                    }
                                                }
                                                delete else_part;
                                            }
                                            else
                                                return false;
                                        }
                                        else if (*it_temp_type == "END")
                                        {
                                            input->insert_chlid(test);
                                            input->insert_chlid(then_part);
                                            it_temp_type++;
                                            it_temp_value++;
                                            temp_length++;
                                            it_types = it_temp_type;
                                            it_values = it_temp_value;
                                            length = temp_length;
                                            return true;
                                        }
                                    }
                                }
                                delete then_part;
                            }
                        }
                    }

                }
                    delete test;
            }
        }
    }
    return false;
}
// match statement using grammer rule  statement---> if_statement| repeat_statement | assign_statement | read_statement | write_statement
bool match_statement(list<QString> &token_types, list<QString> &token_Value, list<QString> ::iterator &it_types, list<QString> ::iterator &it_values, int &length, node *&input)
{

    if (match_assign(token_types, token_Value, it_types, it_values, length,input))
    {
        return true;
    }
    if (match_if(token_types, token_Value, it_types, it_values, length, input))
    {
        return true;
    }
    if (match_repeat(token_types, token_Value, it_types, it_values, length,input))
    {
        return true;
    }
    if (match_write(token_types, token_Value, it_types, it_values, length,input))
    {
        return true;
    }
    if (match_read(token_types, token_Value, it_types, it_values, length,input))
    {
        return true;
    }
    return false;
}
// to match statment_sequance using grammer rule  statment sequance ----> statment {;statment}
bool match_statement_seq(list<QString> &token_types, list<QString> &token_Value, list<QString> ::iterator &it_types, list<QString> ::iterator &it_values,int &length, node * &input)
{
    if (match_statement(token_types, token_Value, it_types, it_values, length,input))
    {
        if (length !=token_types.size())
        {
            node* temp = input;
            while (length !=token_types.size())
            {

                if (semi_colon(*it_types))
                {
                    it_types++;
                    it_values++;
                    length++;
                    if (length != token_types.size())
                    {
                        node * newright = new node;
                        temp->set_right(newright);
                        if (match_statement(token_types, token_Value, it_types, it_values, length, newright))
                        {
                            temp = temp->get_right();
                            continue;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        return true;
    }
    return false;
}

void Widget::setputUi()
{
       this->resize(800,800);
       //this->move(300,300);
       this->setWindowTitle("scanner & Parser");
       inputbox = new QTextEdit;
       output = new QTextEdit;
       inputbox->setMinimumSize(400,400);
       output->setMinimumSize(400,400);
       QHBoxLayout  *horizontal= new QHBoxLayout;
       QVBoxLayout  *vertical= new QVBoxLayout;
       QHBoxLayout * horizontalforbutton = new QHBoxLayout;
       QHBoxLayout * submithandel = new QHBoxLayout;
       QHBoxLayout * parsetreehandel = new QHBoxLayout;
       QHBoxLayout * horizontalforlabels = new QHBoxLayout;
       label= new QLabel;
       //label->setText("scanner");
       label->setAlignment(Qt::AlignCenter);
       inputlabel  = new QLabel;
       outputlabel = new QLabel;
       inputlabel->setText("Input");
       outputlabel->setText("Scan");
       submit = new QPushButton;
       submit->setText("submit");
       submit->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
       show_perse_tree = new QPushButton;
       show_perse_tree->setText(" Show parse tree");
       show_perse_tree->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
       show_perse_tree->setEnabled(false);
       horizontalforlabels->addWidget(inputlabel);
       horizontalforlabels->addWidget(outputlabel);
       horizontal->addWidget(inputbox);
       horizontal->addWidget(output);
       //horizontal->addWidget(submit);
       horizontal->addStretch();
       horizontal->setStretchFactor(output,1);
       horizontal->setStretchFactor(inputbox,1);
       //QScrollArea *tm = new QScrollArea(this);
       submithandel->addWidget(submit);
       parsetreehandel->addWidget(show_perse_tree);
      // horizontalforbutton->addWidget(submit);
       //horizontalforbutton->addWidget(show_perse_tree);
      // horizontalforbutton->setAlignment(Qt::AlignCenter);
      // horizontalforbutton->setSpacing(200);
       submithandel->setAlignment(Qt::AlignCenter);
       parsetreehandel->setAlignment(Qt::AlignCenter);
       horizontalforbutton->addLayout(submithandel);
       horizontalforbutton->addLayout(parsetreehandel);

       //vertical->addWidget(label);
       vertical->addLayout(horizontalforlabels);
       vertical->addLayout(horizontal);
       vertical->addLayout(horizontalforbutton);
       vertical->addLayout(horizontalforlabels);
       vertical->addStretch();
      // vertical->setStretchFactor(label,1);
       vertical->setStretchFactor(horizontal,1);
       vertical->setStretchFactor(submit,1);
       vertical->setAlignment(Qt::AlignCenter);
       this->setLayout(vertical);
       connect(submit,SIGNAL(clicked()),this,SLOT(button_clicked()));
       connect(inputbox,SIGNAL(textChanged()),this,SLOT(clear()));
       connect(show_perse_tree,SIGNAL(clicked()),this,SLOT(show_button_clicked()));

}
void Widget::show_button_clicked()
{
 node * tree = new node;
 int length = 0;
 list<QString> ::iterator  token_types_begin = token_types.begin();
 list<QString> ::iterator  token_Value_begin = token_Value.begin();
 if (match_statement_seq(token_types, token_Value, token_types_begin, token_Value_begin, length, tree))
 {    // QGridLayout lmoo();
     Form draw(tree);
     int l =draw.exec();

 }
 else
 {
         QMessageBox message;
         message.setWindowTitle("Error");
         message.setText(" THIS PROGRAM DOESNT FOLLOW TINY LANGUAGE RULES !!");
         message.setStandardButtons(QMessageBox::Ok);
         message.setDefaultButton(QMessageBox::Ok);
         message.exec();

 }
}
void Widget::button_clicked()
{
    QStack<int> x;
    output->clear();
    QString reservedWords[8] = {"if","then","else","end","repeat","until","read","write"};
    QString specialSymbols[10] = {"+","-","*","/","=","<","(",")",";",":="};
    QString symbolName[10] = {"Plus","Minus","Multiply","Division","Equal","Smaller than","Open Bracket","Close Bracket","Semicolon","Assign"};
    QString id = "";
    QString num = "";
    int lineCount = 1;
    QMessageBox Q;
  QString input = inputbox->toPlainText();
  QString outputtext ="";
  for(int i =0 ; i < input.length() ; i++)
  {
      if (input[i]=="{")
      {
          int f=0;
          i++;
          x.push(i);
          while (i <input.length())
          {
              if (input[i] !='}' && input[i] !='{')
              {
                  if (input[i] == '\n')
                  {
                      lineCount++;
                  }
                  i++;
              }
              else if (input[i] =='{')
              {
                  x.push(i);
                  i++;
              }
              else
              {
                  x.pop();
                  i++;
                  if (x.empty()==true)
                  {
                      i--;
                      f=1;
                      break;
                  }
              }
          }
          if (i==input.length() && x.empty()==false)
          {
             outputtext = outputtext+"ERROR ON LINE "+QString::number(lineCount)+ " COMMENT ISN'T CLOSED ";
             output->setText(outputtext);
             Q.setWindowTitle("Error");
             Q.setText("ERROR ON LINE "+QString::number(lineCount)+"COMMENT ISN'T CLOSED");
             Q.setStandardButtons(QMessageBox::Ok);
             Q.setDefaultButton(QMessageBox::Ok);
             Q.exec();
              return;
          }
          if (f==1)
              continue;
      }
      if (i ==input.length())
      {
          break;
      }
      if(i < input.length()&& input[i] == '\n')
                    {
                      lineCount++;
                      continue;
                    }

      int flag=0;
          if ( (input[i] > 64 && input[i] < 91) || (input[i] > 96 && input[i] < 123))
          {
          id = "";
          while (i < input.length())
          {
              if (( input[i] > 64 && input[i] < 91) || (input[i] > 96 && input[i] < 123))
              {
              id = id+input[i];
              i++;
              }
              else
              {
              if (input[i].isDigit())
              {

                  outputtext = outputtext+"ERROR ON LINE "+QString::number(lineCount);
                  output->setText(outputtext);
                  Q.setWindowTitle("Error");
                  Q.setText("ERROR ON LINE "+QString::number(lineCount)+"      ");
                  Q.setStandardButtons(QMessageBox::Ok);
                  Q.setDefaultButton(QMessageBox::Ok);
                  Q.exec();
                  return;
              }
              break;
              }
          }
          for (int r = 0; r < 8 ; r++)
          {
              if (id == reservedWords[r])
              {
              QString tempid = id;
              for(int d = 0 ; d < tempid.length() ; d++)
                    {
               tempid[d]=static_cast<QChar>(tempid.at(d).unicode()-32);
                    }
              //cout << id << " , " << tempid << endl;
               outputtext = outputtext+ id+" , " +tempid+" "+"\n";
               this->token_types.push_back(tempid);
               this->token_Value.push_back(id);
              id = "";
              flag=1;
              break;
              }
           }

          if (id != "")
              {
            // cout << id <<" , " << "Identifier" << endl;
              this->token_types.push_back("IDENTIFIER");
              this->token_Value.push_back(id);
              outputtext = outputtext+id+" , " + "Identifier"+" "+"\n";
              id = "";
              i--;
              continue;
              }
          else if(flag==1)
          {
              i--;
              continue;
          }
          }

              while (i < input.length())
              {
              if(input[i].isDigit())
                 {
              num += input[i];
              i++;
              flag=1;
                 }
              else
                 {
                   if ((input[i] > 64 && input[i] < 91) || (input[i] > 96 && input[i] < 123))
                   {
                       outputtext = outputtext+"ERROR ON LINE "+QString::number(lineCount);
                       output->setText(outputtext);
                       Q.setWindowTitle("Error");
                       Q.setText("ERROR ON LINE "+QString::number(lineCount));
                       Q.setStandardButtons(QMessageBox::Ok);
                       Q.setDefaultButton(QMessageBox::Ok);
                       Q.exec();
                       return;
                   }
                    break;
                 }
              }
              if (flag==1)
              {
                  //cout << num <<" , " << "Number" << endl;
                  token_types.push_back("NUMBER");
                  token_Value.push_back(num);
                  outputtext = outputtext+num+" , " + "Number"+" "+"\n";
                  num = "";
                  i--;
                  continue;
              }
              if (input[i]==":" && i<input.length()-1)
              {
                  if (input[i+1]=="=")
                  {
                      token_types.push_back("ASSIGN");
                      token_Value.push_back(":=");
                    outputtext = outputtext+":=" +" , " + "Assign"+" "+"\n";
                    i++;
                    continue;
                  }
                  else
                  {
                      outputtext = outputtext+"ERROR ON LINE "+QString::number(lineCount);
                      output->setText(outputtext);
                      Q.setWindowTitle("Error");
                      Q.setText("ERROR ON LINE "+QString::number(lineCount));
                      Q.setStandardButtons(QMessageBox::Ok);
                      Q.setDefaultButton(QMessageBox::Ok);
                      Q.exec();

                      return;
                  }
              }
              else
              {
               for (int r = 0; r < 9 ; r++)
               {
                   if (input[i]==specialSymbols[r])
                   {
                    token_types.push_back(symbolName[r]);
                    QString tempchar = "";
                    tempchar =tempchar+specialSymbols[r];
                    token_Value.push_back(tempchar);
                    outputtext = outputtext+specialSymbols[r]+" , " +symbolName[r]+" "+"\n";
                    flag=1;
                    break;
                   }
               }
               if (flag==1)
               {
                   continue;
               }
               else
               {
                   if (input[i]==" ")
                   {
                       continue;
                   }
                   outputtext = outputtext+"ERROR ON LINE "+QString::number(lineCount);
                   output->setText(outputtext);
                   Q.setWindowTitle("Error");
                   Q.setText("ERROR ON LINE "+QString::number(lineCount));
                   Q.setStandardButtons(QMessageBox::Ok);
                   Q.setDefaultButton(QMessageBox::Ok);
                   Q.exec();
                   return;
               }
              }
  }
  output->setText(outputtext);
  show_perse_tree->setEnabled(true);

  token_Value;
  token_types;
  int p=50;
}
void Widget::clear()
{
    show_perse_tree->setEnabled(false);
    token_types.clear();
    token_Value.clear();
    output->clear();
}

