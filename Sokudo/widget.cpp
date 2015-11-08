#include "widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QHeaderView>
#include <QAbstractItemView>
#include <iostream>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QDebug>
using namespace std;
int candidate[] = {1,2,3,4,5,6,7,8,9};
//标记这个空格是否为原始数据
int g_a[9][9] = {0};
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
       resize(730,630);
       this->setStyleSheet("background-color:green;color:red");
       this->setWindowTitle("数独计算器");
       tablewidget = new QTableWidget;
       tablewidget->setGeometry(0,0,630,630);
       button = new QPushButton;
       rebutton = new QPushButton;
       QHBoxLayout *hbox = new QHBoxLayout;
       QVBoxLayout *vbox = new QVBoxLayout;
       vbox->addWidget(button);
       vbox->addWidget(rebutton);
       hbox->addWidget(tablewidget);
       hbox->addLayout(vbox);
       this->setLayout(hbox);
       button->setText("计算");
       rebutton->setText("刷新");
       tablewidget->setRowCount(9);
       tablewidget->setColumnCount(9);
      // tablewidget->horizontalHeader()->setStretchLastSection(true);
       tablewidget->horizontalHeader()->setDefaultSectionSize(65);
       tablewidget->verticalHeader()->setDefaultSectionSize(65);
       tablewidget->setStyleSheet("selection-background-color:lightblue;");
       tablewidget->setStyleSheet("background-color: cyan;color:red");
        connect(button,&QPushButton::clicked,this,&Widget::start);
        connect(rebutton,&QPushButton::clicked,this,&Widget::Refresh);
        Refresh();
}
Widget::~Widget()
{

}
void Widget::start()
{
    int a[9][9]={0};

    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            QString temp = tablewidget->item(i,j)->text();
            if(temp.toInt()  != 0)
            {
                a[i][j] = temp.toInt();
            }


        }

    TotalNumbers( a, 9, 9 );
        success( a, 0, 0 );
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
            {

                tablewidget->setItem(i,j,new QTableWidgetItem(QString(QString::number(a[i][j]))));
            }
        //QMessageBox::information(this,"no","no");
}
void Widget::Refresh()
{
    int a[9][9];
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            a[i][j] =0;
        }
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            QString temp = QString::number(a[i][j]);
            tablewidget->setItem(i,j,new QTableWidgetItem(temp));
        }
}
void Widget::ConfirmCandidate(int (*a)[9], int i, int j)
{
    for( int i_candidate = 0; i_candidate < 9; i_candidate++ )
            candidate[i_candidate] = i_candidate+1;
        for( int colm = 0; colm < 9; colm++ )
        {
            if( a[i][colm] != 0 )
                candidate[a[i][colm]-1] = 0;
        }
        for( int line = 0; line < 9; line++ )
        {
            if( a[line][j] != 0 )
                candidate[a[line][j]-1] = 0;
        }
        for( int line = i/3*3; line < i/3*3+3; line++ )
        {
            for( int colm = j/3*3; colm < j/3*3+3; colm++ )
                if( a[line][colm] != 0 )
                    candidate[a[line][colm]-1] = 0;
        }
}
void Widget::TotalNumbers(int (*a)[9], int i, int j)
{
    for( int line = 0; line < i; line++ )
    {
        for( int colm = 0; colm < j; colm++ )
            if( a[line][colm] == 0 )
            {
                g_a[line][colm] = 1;
            }
    }
}
bool Widget::JudgeValue(int (*a)[9], int i, int j)
{
    for( int colm = 0; colm < 9; colm++ )
        {
            if( a[i][colm] == a[i][j] && j != colm )
                return false;
        }
        //同一列有无重复数字
        for( int line = 0; line < 9; line++ )
        {
            if( a[line][j] == a[i][j] && i != line )
                return false;
        }
        //一个3*3的方格内有无重复数字
        for( int line = i/3*3; line < i/3*3+3; line++ )
        {
            for( int colm = j/3*3; colm < j/3*3+3; colm++ )
                if( a[line][colm] == a[i][j] && i != line && j != colm )
                    return false;
        }
        return true;
}
bool Widget::success(int (*a)[9], int i, int j)
{
    if( i < 0 || j < 0 ) return false;
        int line = i;
        int colm = j;
        for( ; line < 9; line++, colm = 0 )
        {
            for( ; colm < 9; colm++ )
            {
                //cout << "line = " << line <<"  colm = " << colm << endl;
                //if( colm == 8 && line == 8 ) return true;
                if( a[line][colm] != 0 && g_a[line][colm] == 0 ) continue;
                ConfirmCandidate(a, line, colm);
                for(int c = 0; c < 9; c++ )
                {
                    if( candidate[c] > a[line][colm] )
                    {
                        a[line][colm] = candidate[c];
                        /*
                        *TEST
                        *测试可选数字
                        */
                        /*
                        for(int i = 0; i < 9; i++ )
                            cout << candidate[i] << " ";
                        cout << endl << endl;
                        */
                        //print(a);
                        //判断放入的值是否正确
                        bool bRet = JudgeValue( a, line, colm );
                        if(!bRet)
                        {
                            //cout << "bRet  is  false" << endl;
                        }
                        else{
                            //cout << "bRet  is  true" << endl;
                            break;
                        }
                    }
                    else if( c == 8 && candidate[c] <= a[line][colm] )
                    {
                        //cout << "line = " << line <<"  colm = " << colm << endl;
                        int set_colm = 8;
                        a[line][colm] = 0;
                        if( colm == 0 )
                        {
                            while( g_a[line-1][set_colm] == 0)
                            {
                                if( set_colm == 0)
                                {
                                    line--;
                                    set_colm = 8;
                                }
                                else set_colm--;
                            }
                            return success( a, line - 1, set_colm);
                        }
                        else{
                            while( g_a[line][colm-1] == 0)
                            {
                                if( colm-1 == 0)
                                {
                                    line--;
                                    colm = 9;
                                }
                                else colm--;
                            }
                            return success( a ,line, colm-1 );
                        }
                    }
                }
            }
        }
        return true;
}
