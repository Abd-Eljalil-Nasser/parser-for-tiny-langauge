#include "show_tree.h"
#include "ui_show_tree.h"
#include<form.h>
#include <QLayout>
#include<stack>
#include<vector>
using std::pair;
using std::stack;
using std::vector;
show_tree::show_tree(node *tree,QWidget *parent) :
    QDialog (parent),
    ui(new Ui::show_tree)
{
   QHBoxLayout  *horizontal= new QHBoxLayout;
    //QHBoxLayout  *horizontal= new QHBoxLayout;
   horizontal->addStretch();
    this->tree = tree;
    ui->setupUi(this);
}
int traversal(node *input, vector<int> &levels, int y,int level, int rec_width , int rec_hight,
 list<pair<int,int>> &rectangles,list<pair<int,int>> &circles, list<pair<QString,QString>> &texts_rec ,list<pair<QString,QString>> &texts_cir,list<pair<QPoint,QPoint>> &lines);
 void show_tree::paintEvent(QPaintEvent *e)
 {
     int x = 20;
     int y=  20;
      QPainter painter(this);
      QFont font = painter.font();
      font.setPixelSize(20);
      painter.setFont(font);
      QPen pinpaint(Qt::black);
      pinpaint.setWidth(2);
      painter.setPen(pinpaint);
     // queue<pair<node *,int>> buffer;
     // buffer.push(tree);
     // stack<pair<int,int>> level;
      int levelcount=0;
      vector<int> levels_value(10,20);
      node* temp = tree;
      list<pair<int,int>> rectangles;
      list<pair<int,int>> circles;
      list<pair<QPoint,QPoint>> lines;
      list<pair<QString,QString>> texts_rec;
      list<pair<QString,QString>>texts_cir;
      /*while(1)
     {
          levelcount=0;
          if (temp->get_operation()=="read" || temp->get_operation()=="write" ||  temp->get_operation()=="assign" ||temp->get_operation()=="repeat"||temp->get_operation()=="if")
          {
              QRect rect(x,y,100,100);
               painter.drawRect(rect);
               painter.drawText(rect,Qt:: AlignCenter,temp->get_operation()+'\n'+'\n');
               painter.drawText(rect,Qt::AlignCenter|Qt::AlignVCenter,temp->get_value());

          }
          int parent_x = x+100;
          int parent_y = y+100;
          if (temp->children_size()==1)
          {
          levelcount++;
          buffer.push(*it,);
          }
          for(list<node*> ::iterator it = temp->get_first_child();it!=temp->get_first_child();it++)
          {
              buffer.push(*it);
          }
      while(buffer.empty() == false)
      {
          node* temp = buffer.front();
          buffer.pop();
          QPoint temppoint(x,y);
          if (temp->get_operation()=="read" || temp->get_operation()=="write" ||  temp->get_operation()=="assign" ||temp->get_operation()=="repeat"||temp->get_operation()=="if")
          {
               QRect rect(x,y,100,100);
               painter.drawRect(rect);
               painter.drawText(rect,Qt:: AlignCenter,temp->get_operation()+'\n'+'\n');
               painter.drawText(rect,Qt::AlignCenter|Qt::AlignVCenter,temp->get_value());
          }
          else
          {

          }
      }
      break;
      }
       */
  traversal(tree,levels_value,20,levelcount,100,100,rectangles,circles,texts_rec ,texts_cir,lines);
  list<pair<QString,QString>> ::iterator it1 = texts_rec.begin();
  for (list<pair<int,int>> ::iterator it =rectangles.begin();it!=rectangles.end();it++)
  {
      QRect rect((*it).first,(*it).second,100,100);
      painter.drawRect(rect);
      painter.drawText(rect,Qt:: AlignCenter,(*it1).first+'\n'+'\n');
      painter.drawText(rect,Qt::AlignCenter|Qt::AlignVCenter,(*it1).second);
      it1++;
  }
  it1 = texts_cir.begin();
  for (list<pair<int,int>> ::iterator it =circles.begin();it!=circles.end();it++)
  {
      QRect rect((*it).first,(*it).second,100,100);
      painter.drawEllipse(rect);
      painter.drawText(rect,Qt:: AlignCenter,(*it1).first+'\n'+'\n');
      painter.drawText(rect,Qt::AlignCenter|Qt::AlignVCenter,(*it1).second);
      it1++;
  }
  for (list<pair<QPoint,QPoint>>::iterator it = lines.begin();it!=lines.end();it++)
  {
      QPoint temp1 =(*it).first;
      QPoint temp2 = (*it).second;
      painter.drawLine(temp1,temp2);
  }
  int w = 20;
  int k =500;

 }
 int maxDepth(node* input)
 {
     if (input->children_size()==0)
         return 0;
     else
     {
         if (input->children_size()==1)
         {
             list<node*> ::iterator it = input->get_first_child();
             return maxDepth(*it)+1;
         }
         else if (input->children_size()==2)
         {
             list<node*> ::iterator it = input->get_first_child();
             int left_d = maxDepth(*it);
             it++;
             int right_d = maxDepth(*it);
             if (right_d >left_d)
             {
                 return right_d+1;
             }
             else
             {
                 return left_d+1;
             }
         }
         else if (input->children_size()==3)
         {
             list<node*> ::iterator it = input->get_first_child();
             int left_d = maxDepth(*it);
             it++;
             int mid_d = maxDepth(*it);
             it++;
             int right_d = maxDepth(*it);

             if (right_d >left_d)
             {
                 if (right_d > mid_d)
                 {
                     return right_d+1;
                 }
                 else
                 {
                     return mid_d+1;
                 }
             }
             else
             {
                 if (left_d > mid_d)
                 {
                     return left_d+1;
                 }
                 else
                 {
                     return mid_d+1;
                 }
             }
         }
     }
 }
int traversal(node *input, vector<int> &levels, int y,int level, int rec_width , int rec_hight,
               list<pair<int,int>> &rectangles,list<pair<int,int>> &circles, list<pair<QString,QString>> &texts_rec ,list<pair<QString,QString>> &texts_cir,list<pair<QPoint,QPoint>> &lines)
{
    if (input->children_size()==0)
    {
        // has zero children

        if (level-1 >=0)
        {
            int k = level-1;
            bool k_value = false;
            while (k >=0)
            {
            if (levels[k] > levels[level]+300)
            {
                k_value=true;
                break;
            }
            k--;
            }
            if (k_value)
            {
            for (int i=level;i>k;i--)
            {
                levels[i] = levels[k]-150;
            }
            }
        }

        int x_cor = levels[level];
        levels[level] = levels[level]+rec_width+100;
        int x_first_point =  x_cor + rec_width;
        int y_first_point = y + rec_hight /2;
        if (input->get_right() != nullptr)
        {
            int x_second_point = traversal(input->get_right(),levels,y,level,rec_width,rec_hight,rectangles,circles,texts_rec,texts_cir,lines);
            QPoint first_point (x_first_point,y_first_point);
            QPoint second_point (x_second_point,y_first_point);
            pair<QPoint,QPoint> line (first_point,second_point);
            lines.push_back(line);
        }
        if (input->get_operation() =="read")
        {
            pair<int,int> rectangle_cordinates;
            rectangle_cordinates.first = x_cor;
            rectangle_cordinates.second = y;
            rectangles.push_back(rectangle_cordinates);
            pair<QString,QString> rectangle_text;
            rectangle_text.first = input->get_operation();
            rectangle_text.second = input->get_value();
            texts_rec.push_back(rectangle_text);
        }
        else
        {
            pair<int,int> circle_cordinates;
            circle_cordinates.first = x_cor;
            circle_cordinates.second = y;
            circles.push_back(circle_cordinates);
            pair<QString,QString> circle_text;
            circle_text.first = input->get_operation();
            circle_text.second = input->get_value();
            texts_cir.push_back(circle_text);
        }
        return x_cor;
    }
    else
    {
     // has many children
    int depth =maxDepth(input);
    int max_x_value_in_my_depth =0;
    for (int i =level+1;i<depth;i++)
    {
        if (max_x_value_in_my_depth < levels[i])
        {
            max_x_value_in_my_depth = levels[i];
        }
    }
    for (int i =level+1;i<depth;i++)
    {
        levels[i]=max_x_value_in_my_depth;
    }
    int children_count =0;
    int frist_child_cordinate=0;
    int last_child_cordinat =0; ;
    list<QPoint>children_points;
    for (list<node*> ::iterator it = input->get_first_child(); it!=input->get_last_child();it++)
    {

     int x_child = traversal(*it,levels,(y+rec_hight+100),(level+1),rec_width,rec_hight,rectangles,circles,texts_rec,texts_cir,lines);
     int y_child = (y+rec_hight+100);
     QPoint first_point (x_child+rec_width/2 ,y_child);
     children_points.push_back(first_point);
        if(children_count==0)
          {
          frist_child_cordinate =x_child;
          }
          if (children_count==input->children_size()-1)
          {
          last_child_cordinat = x_child+rec_width;
          }
          children_count++;
    }
   /* list<node*> ::iterator it = input->get_first_child();
    int x_firct_child = traversal(*it,levels,(y+rec_hight+150),(level+1),rec_width,rec_hight,rectangles,circles,texts_rec,texts_cir,lines);
    int y_first_child = (y+rec_hight+150);
    int x_parent = x_firct_child+rec_width;
    */
    int x_parent =0;
    // has one child only
    if (last_child_cordinat ==frist_child_cordinate+rec_width)
    {
        x_parent = frist_child_cordinate;
    }
    else
    {
        x_parent =(frist_child_cordinate+last_child_cordinat)/ input->children_size();
    }
    /*
     *
     */
    /*if (x_parent +150 < levels[level+1])
    {
        x_parent = x_parent+250;
    }
    */
    if (x_parent <levels[level])
    {
        x_parent =levels[level];
    }

     if (input->get_operation()=="write" ||  input->get_operation()=="assign" ||input->get_operation()=="repeat"||input->get_operation()=="if")
     {
         pair<int,int> rectangle_cordinates;
         rectangle_cordinates.first = x_parent;
         rectangle_cordinates.second = y;
         rectangles.push_back(rectangle_cordinates);
         pair<QString,QString> rectangle_text;
         rectangle_text.first = input->get_operation();
         rectangle_text.second = input->get_value();
         texts_rec.push_back(rectangle_text);
     }
     else
     {
         pair<int,int> circle_cordinates;
         circle_cordinates.first = x_parent;
         circle_cordinates.second = y;
         circles.push_back(circle_cordinates);
         pair<QString,QString> circle_text;
         circle_text.first = input->get_operation();
         circle_text.second = input->get_value();
         texts_cir.push_back(circle_text);
     }
    // set_lines to children
    QPoint second_point(x_parent+rec_width/2,y+rec_hight);
    for (list<QPoint>::iterator it =children_points.begin();it !=children_points.end();it++)
    {
    pair<QPoint,QPoint> line (*it,second_point);
    lines.push_back(line);
    }
    levels[level]= x_parent + rec_width+100;
    if (input->get_right()!= nullptr)
    {
        int x_second_point = traversal(input->get_right(),levels,y,level,rec_width,rec_hight,rectangles,circles,texts_rec,texts_cir,lines);
        QPoint first_point  (x_second_point,y+rec_hight/2);
        QPoint second_point (x_parent+rec_width,y+rec_hight/2);
        pair<QPoint,QPoint> line (first_point,second_point);
        lines.push_back(line);
    }
    return x_parent;
    }
}
void show_tree::CloseEvent()
{
    this->hide();
    delete  this->ui;

    this->close();
}
show_tree::~show_tree()
{

    this->close();
    delete ui;
}
