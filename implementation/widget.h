
#include <QWidget>
#include<QTextEdit>
#include<QLabel>
#include<QPushButton>
#include<string>
#include<QString>
#include<iostream>
#include<list>
#include<node.h>
#include <QStack>
using std::string;
using std::cout;
using std::endl;
using std::list;
#ifndef WIDGET_H
#define WIDGET_H
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void setputUi();
  private slots:
    void button_clicked();
    void show_button_clicked();
    void clear();
     private:
     QTextEdit * inputbox;
     QTextEdit *output;
     QLabel * label;
     QLabel  *inputlabel;
     QLabel  *outputlabel;
     QPushButton * submit;
     QPushButton * show_perse_tree;
     list<QString> token_types;
     list<QString> token_Value;
};

#endif // WIDGET_H
