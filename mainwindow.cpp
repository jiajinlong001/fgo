#include "mainwindow.h"
#include "ui_mainwindow.h"

//头像按钮点击状态数组
extern int bright[SERVANT_MAX+1]={0};
//选择从者的数量及顺序数组
extern int selected[SERVANT_MAX+1]={0};
//等级设置条各部件数组，包括一个头像label，3个技能label，8个等级spinbox，1个删除pushbutton，一个突破CheckBox
QLabel *heads[SERVANT_MAX+1];
QLabel *skills[SERVANT_MAX*3+1];
QSpinBox *levels[SERVANT_MAX*8+1];
QPushButton *deletes[SERVANT_MAX+1];
QCheckBox *breaks[SERVANT_MAX+1];

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i=1;i<SERVANT_MAX;i++)
    {
        //各部件组初始化
        heads[i]=new QLabel(ui->scrollAreaWidgetContents);
        skills[3*i-2]=new QLabel(ui->scrollAreaWidgetContents);
        skills[3*i-1]=new QLabel(ui->scrollAreaWidgetContents);
        skills[3*i]=new QLabel(ui->scrollAreaWidgetContents);
        levels[i*8-7]=new QSpinBox(ui->scrollAreaWidgetContents);
        levels[i*8-6]=new QSpinBox(ui->scrollAreaWidgetContents);
        levels[i*8-5]=new QSpinBox(ui->scrollAreaWidgetContents);
        levels[i*8-4]=new QSpinBox(ui->scrollAreaWidgetContents);
        levels[i*8-3]=new QSpinBox(ui->scrollAreaWidgetContents);
        levels[i*8-2]=new QSpinBox(ui->scrollAreaWidgetContents);
        levels[i*8-1]=new QSpinBox(ui->scrollAreaWidgetContents);
        levels[i*8]=new QSpinBox(ui->scrollAreaWidgetContents);
        deletes[i]=new QPushButton(ui->scrollAreaWidgetContents);
        breaks[i]=new QCheckBox(ui->scrollAreaWidgetContents);
        //设置技能设置条初始状态为隐藏
        heads[i]->setVisible(false);
        skills[3*i-2]->setVisible(false);
        skills[3*i-1]->setVisible(false);
        skills[3*i]->setVisible(false);
        levels[i*8-7]->setVisible(false);
        levels[i*8-6]->setVisible(false);
        levels[i*8-5]->setVisible(false);
        levels[i*8-4]->setVisible(false);
        levels[i*8-3]->setVisible(false);
        levels[i*8-2]->setVisible(false);
        levels[i*8-1]->setVisible(false);
        levels[i*8]->setVisible(false);
        deletes[i]->setVisible(false);
        breaks[i]->setVisible(false);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::image_dark(int id,QLabel *label){
    QString buf;
    buf.sprintf(":/resource/head/%03d.jpg",id);
    QImage *head = new QImage(buf);
    QImage *newhead=new QImage(head->width(),head->height(),QImage::Format_ARGB32);
    QColor oldColor;
    int r,g,b;
    for (int x=0;x<head->width();x++)
    {
        for (int y=0;y<head->height();y++)
        {
            oldColor=QColor(head->pixel(x,y));
    //将亮度降低为60%，并写入到新的QImage对象newhead
            r=oldColor.red()*0.6;
            g=oldColor.green()*0.6;
            b=oldColor.blue()*0.6;

            newhead->setPixel(x,y,qRgb(r,g,b));
        }
    }
    //将QImage对象newhead转化为QPixmap对象icon并作为pushbutton8的图标，实现点击后变暗
    QPixmap icon=QPixmap::fromImage(newhead->scaled(head->size(),Qt::KeepAspectRatio));
    QPushButton * button = (QPushButton *)sender();
    button->setIcon(icon);
    QPixmap heads;
    heads.load(buf);

    label->setPixmap(heads);

}

void MainWindow::showdetails(int id)
{

    //定义每个设置框内的部件位置
    //定义每个设置框内的部件，包括4个label，依次显示头像（9）和三个技能（10,11,12）
    //8个spinbox，依次显示从者当前等级（9）、目标等级（10）、技能当前等级（11,12,13）、目标等级（14,15,16）
    //1个checkbox，设定是否已经完成该阶段突破，比如60级时
    //1个pushbutton，删除该从者

    //设定各个部件的左上顶点位置和尺寸，认为每个设置框的高度为130
    int i = selected[0];
    //设定各部件出现在主窗口

    heads[i]->setGeometry(230,495+130*(i-1),100,100);
    skills[3*i-2]->setGeometry(640,485+130*(i-1),30,30);
    skills[3*i-1]->setGeometry(640,525+130*(i-1),30,30);
    skills[3*i]->setGeometry(640,565+130*(i-1),30,30);
    levels[i*8-7]->setGeometry(400,525+130*(i-1),60,30);
    levels[i*8-6]->setGeometry(490,525+130*(i-1),60,30);
    levels[i*8-5]->setGeometry(690,485+130*(i-1),60,30);
    levels[i*8-4]->setGeometry(690,525+130*(i-1),60,30);
    levels[i*8-3]->setGeometry(690,565+130*(i-1),60,30);
    levels[i*8-2]->setGeometry(780,485+130*(i-1),60,30);
    levels[i*8-1]->setGeometry(780,525+130*(i-1),60,30);
    levels[i*8]->setGeometry(780,565+130*(i-1),60,30);
    deletes[i]->setGeometry(900,515+130*(i-1),130,50);
    breaks[i]->setGeometry(430,565+130*(i-1),60,20);
    //设定所有部件可见
    heads[i]->setVisible(true);
    skills[3*i-2]->setVisible(true);
    skills[3*i-1]->setVisible(true);
    skills[3*i]->setVisible(true);
    levels[i*8-7]->setVisible(true);
    levels[i*8-6]->setVisible(true);
    levels[i*8-5]->setVisible(true);
    levels[i*8-4]->setVisible(true);
    levels[i*8-3]->setVisible(true);
    levels[i*8-2]->setVisible(true);
    levels[i*8-1]->setVisible(true);
    levels[i*8]->setVisible(true);
    deletes[i]->setVisible(true);
    breaks[i]->setVisible(true);

    //为4个label赋予图片
    //QPixmap heads;
    image_dark(id,heads[i]);//暗化图像整合成一个参数id=从者序号，buf为QString

    QPixmap skill1,skill2,skill3;
    //buf.clear();
    //buf.sprintf(":/resource/skill/%d.png",18);
    skill1.load(":/resource/skill/18.png");
    skill2.load(":/resource/skill/50.png");
    skill3.load(":/resource/skill/01.png");

    heads[i]->setScaledContents(true);
    skills[3*i-2]->setScaledContents(true);
    skills[3*i-1]->setScaledContents(true);
    skills[3*i]->setScaledContents(true);


    skills[3*i-2]->setPixmap(skill1);
    skills[3*i-1]->setPixmap(skill2);
    skills[3*i]->setPixmap(skill3);

    //为pushbutton和CheckBox设置文字
    deletes[i]->setText("Delete");
    breaks[i]->setText("break");

    //为8个spinbox赋予初值
    levels[i*8-7]->setValue(1);
    levels[i*8-6]->setValue(90);
    levels[i*8-5]->setValue(1);
    levels[i*8-4]->setValue(1);
    levels[i*8-3]->setValue(1);
    levels[i*8-2]->setValue(10);
    levels[i*8-1]->setValue(10);
    levels[i*8]->setValue(10);
    //为各框设定最大值
    levels[i*8-7]->setMaximum(100);
    levels[i*8-6]->setMaximum(100);
    levels[i*8-5]->setMaximum(10);
    levels[i*8-4]->setMaximum(10);
    levels[i*8-3]->setMaximum(10);
    levels[i*8-2]->setMaximum(10);
    levels[i*8-1]->setMaximum(10);
    levels[i*8]->setMaximum(10);
}

void MainWindow::on_servant_cal_001_clicked()//点击学妹
{
    int id=1;
        if (bright[id]==0)
        {
            selected[0]=selected[0]+1;
            int num=selected[0];
            selected[num]=id;
            showdetails(id);
            connect(deletes[1],SIGNAL(clicked(bool)),this,SLOT(delete1()));
            bright[id]=SERVANT_MAX+1;
        }
        else if (bright[id]<SERVANT_MAX+1)
        {
            int i = bright[id];
            bright[id]=0;
            heads[i]->setVisible(false);
            skills[3*i-2]->setVisible(false);
            skills[3*i-1]->setVisible(false);
            skills[3*i]->setVisible(false);
            levels[i*8-7]->setVisible(false);
            levels[i*8-6]->setVisible(false);
            levels[i*8-5]->setVisible(false);
            levels[i*8-4]->setVisible(false);
            levels[i*8-3]->setVisible(false);
            levels[i*8-2]->setVisible(false);
            levels[i*8-1]->setVisible(false);
            levels[i*8]->setVisible(false);
            deletes[i]->setVisible(false);
            breaks[i]->setVisible(false);

            QString buf;
            buf.sprintf(":/resource/head/%03d.jpg",id);
            QPixmap head;
            head.load(buf);
            ui->servant_cal_001->setIcon(head);

            QString s = QString::number(i,10);
            ui->label->setText(s);
        }
}

void MainWindow::on_servant_cal_002_clicked()//点击saber
{
    int id=2;
        selected[0]=selected[0]+1;
        selected[selected[0]]=id;
        if (bright[id]==0)
        {
            showdetails(id);
            bright[id]=2;
        }
        else if (bright[id]==1)
        {
            bright[id]=0;
            int i = selected[0];
            heads[i]->setVisible(false);
        }
}

void MainWindow::on_servant_cal_008_clicked()//点击阿蒂拉
{
    int id=8;
    selected[0]=selected[0]+1;
    selected[selected[0]]=id;
    if (bright[id]==0)
    {
        showdetails(id);
        bright[id]=2;
    }
    else if (bright[id]==1)
    {
        bright[id]=0;
        int i = selected[0];
        heads[i]->setVisible(false);
    }
}

void MainWindow::delete1()
{
    for (int i=1;i<SERVANT_MAX+1;i++)
        if (selected[i]==1)
            bright[1]=i;
    on_servant_cal_001_clicked();
}
