#include "form.h"
#include "ui_form.h"
#include<show_tree.h>
Form::Form(node *tree,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window |Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);
    show_tree *x = new show_tree(tree);
    ui->scrollArea->setWidget(x);
}

Form::~Form()
{
    delete ui;
}
