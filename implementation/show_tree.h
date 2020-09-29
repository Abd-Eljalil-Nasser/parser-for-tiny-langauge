#include<node.h>
#include<qpainter.h>
#include<QPoint>
#include<queue>
using std::list;
using std::queue;
#ifndef SHOW_TREE_H
#define SHOW_TREE_H

#include <QDialog>

namespace Ui {
class show_tree;
}

class show_tree : public QDialog
{
    Q_OBJECT

public:
    explicit show_tree(node *tree,QWidget *parent = nullptr);
    virtual void paintEvent(QPaintEvent *e);
    virtual void CloseEvent();
    ~show_tree();

private:
    node * tree;
    Ui::show_tree *ui;
};

#endif // SHOW_TREE_H
