#include "mainwindow.h"
#include <QImage>
#include <QRadioButton>
#include <QCheckBox>
#include <QPushButton>
#include <QScrollArea>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("QScrollArea & QTabWidget");
    resize(1000, 600);

    // 主窗口布局
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    _layout = new QGridLayout();
    centralWidget -> setLayout(_layout);

    // 主窗口内控件构造、初始化、放入布局
    _header = new QLabel("  ---  This is an interest questionnaire  ---  ", centralWidget);
    _header -> setAlignment(Qt::AlignHCenter);
    _widgets = new QTabWidget(centralWidget);
    _layout -> addWidget(_header, 0, 0, 1, 4);
    _layout -> addWidget(_widgets, 1, 0, 3, 4);

    // widget_1
    QWidget* window_politics = new QWidget(_widgets);

    QGridLayout* layout_politics = new QGridLayout(window_politics);

    QLabel* header_politics = new QLabel("1. Which camp do you support?", window_politics);
    header_politics -> setAlignment(Qt::AlignCenter);

    QRadioButton* dem = new QRadioButton("Joe Biden", window_politics);
    QRadioButton* rep = new QRadioButton("Donald Trump", window_politics);
    rep -> setChecked(true);

    QLabel* dem_pic = new QLabel(window_politics);
    QPixmap dem_pixmap("D:\\Christopher\\Desktop\\biden.jpg");
    dem_pic -> setPixmap(dem_pixmap);

    QLabel* rep_pic = new QLabel(window_politics);
    QPixmap rep_pixmap("D:\\Christopher\\Desktop\\trump.jpg");
    rep_pic -> setPixmap(rep_pixmap);

    QScrollArea* for_dem = new QScrollArea(window_politics);
    for_dem -> setWidget(dem_pic);
    for_dem -> setWidgetResizable(false);
    for_dem -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    for_dem -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    QScrollArea* for_rep = new QScrollArea(window_politics);
    for_rep -> setWidget(rep_pic);
    for_rep -> setWidgetResizable(false);
    for_rep -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    for_rep -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    layout_politics -> addWidget(header_politics, 0, 0, 1, 4);
    layout_politics -> addWidget(dem, 1, 0, 1, 2);
    layout_politics -> addWidget(rep, 1, 2, 1, 2);
    layout_politics -> addWidget(for_dem, 2, 0, 2, 2);
    layout_politics -> addWidget(for_rep, 2, 2, 2, 2);

    _widgets -> addTab(window_politics, "politics");

    // widget_2
    QWidget* window_entertainment = new QWidget(_widgets);

    QGridLayout* layout_entertainment = new QGridLayout(window_entertainment);

    QLabel* header_entertainment = new QLabel("2. Which entertainment stars do you like?", window_entertainment);
    header_entertainment -> setAlignment(Qt::AlignCenter);

    QCheckBox* star_1 = new QCheckBox("Angelina Jolie", window_entertainment);
    QCheckBox* star_2 = new QCheckBox("Reese Witherspoon", window_entertainment);
    QCheckBox* star_3 = new QCheckBox("Jennifer Lawrence", window_entertainment);

    QLabel* star1_pic = new QLabel(window_entertainment);
    QPixmap star1_pixmap("D:\\Christopher\\Desktop\\Angelina Jolie.jpg");
    star1_pic -> setPixmap(star1_pixmap);

    QLabel* star2_pic = new QLabel(window_entertainment);
    QPixmap star2_pixmap("D:\\Christopher\\Desktop\\Reese Witherspoon.jpg");
    star2_pic -> setPixmap(star2_pixmap);

    QLabel* star3_pic = new QLabel(window_entertainment);
    QPixmap star3_pixmap("D:\\Christopher\\Desktop\\Jennifer Lawrence.jpg");
    star3_pic -> setPixmap(star3_pixmap);

    QScrollArea* for_star1 = new QScrollArea(window_entertainment);
    for_star1 -> setWidget(star1_pic);
    for_star1 -> setWidgetResizable(false);
    for_star1 -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    for_star1 -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    QScrollArea* for_star2 = new QScrollArea(window_entertainment);
    for_star2 -> setWidget(star2_pic);
    for_star2 -> setWidgetResizable(false);
    for_star2 -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    for_star2 -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    QScrollArea* for_star3 = new QScrollArea(window_entertainment);
    for_star3 -> setWidget(star3_pic);
    for_star3 -> setWidgetResizable(false);
    for_star3 -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    for_star3 -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    layout_entertainment -> addWidget(header_entertainment, 0, 0, 1, 6);
    layout_entertainment -> addWidget(star_1, 1, 0, 1, 2);
    layout_entertainment -> addWidget(star_2, 1, 2, 1, 2);
    layout_entertainment -> addWidget(star_3, 1, 4, 1, 2);
    layout_entertainment -> addWidget(for_star1, 2, 0, 2, 2);
    layout_entertainment -> addWidget(for_star2, 2, 2, 2, 2);
    layout_entertainment -> addWidget(for_star3, 2, 4, 2, 2);

    _widgets -> addTab(window_entertainment, "entertainment");

    // widget_3
    QWidget* window_technology = new QWidget(_widgets);

    QGridLayout* layout_technology = new QGridLayout(window_technology);

    QLabel* header_technology = new QLabel("3. Which tech giant do you admire most?", window_technology);
    header_technology -> setAlignment(Qt::AlignCenter);

    QRadioButton* musk = new QRadioButton("Elon Musk", window_technology);
    QRadioButton* gates = new QRadioButton("Bill Gates", window_technology);
    QRadioButton* bezos = new QRadioButton("Jeff Bezos", window_technology);
    QRadioButton* jobs = new QRadioButton("Steve Jobs", window_technology);
    QPushButton* submit = new QPushButton("Click here to submit.", window_technology);

    musk -> setChecked(true);

    QLabel* musk_pic = new QLabel(window_technology);
    QPixmap musk_pixmap("D:\\Christopher\\Desktop\\musk.jpg");
    musk_pic -> setPixmap(musk_pixmap);

    QLabel* gates_pic = new QLabel(window_technology);
    QPixmap gates_pixmap("D:\\Christopher\\Desktop\\gates.jpg");
    gates_pic -> setPixmap(gates_pixmap);

    QLabel* bezos_pic = new QLabel(window_technology);
    QPixmap bezos_pixmap("D:\\Christopher\\Desktop\\bezos.jpg");
    bezos_pic -> setPixmap(bezos_pixmap);

    QLabel* jobs_pic = new QLabel(window_technology);
    QPixmap jobs_pixmap("D:\\Christopher\\Desktop\\jobs.jpg");
    jobs_pic -> setPixmap(jobs_pixmap);

    QScrollArea* for_musk = new QScrollArea(window_technology);
    for_musk -> setWidget(musk_pic);
    for_musk -> setWidgetResizable(false);
    for_musk -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    for_musk -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    QScrollArea* for_gates = new QScrollArea(window_technology);
    for_gates -> setWidget(gates_pic);
    for_gates -> setWidgetResizable(false);
    for_gates -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    for_gates -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    QScrollArea* for_bezos = new QScrollArea(window_technology);
    for_bezos -> setWidget(bezos_pic);
    for_bezos -> setWidgetResizable(false);
    for_bezos -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    for_bezos -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    QScrollArea* for_jobs = new QScrollArea(window_technology);
    for_jobs -> setWidget(jobs_pic);
    for_jobs -> setWidgetResizable(false);
    for_jobs -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    for_jobs -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    layout_technology -> addWidget(header_technology, 0, 0, 1, 4);
    layout_technology -> addWidget(musk, 1, 0, 1, 2);
    layout_technology -> addWidget(gates, 1, 2, 1, 2);
    layout_technology -> addWidget(for_musk, 2, 0, 2, 2);
    layout_technology -> addWidget(for_gates, 2, 2, 2, 2);
    layout_technology -> addWidget(bezos, 4, 0, 1, 2);
    layout_technology -> addWidget(jobs, 4, 2, 1, 2);
    layout_technology -> addWidget(for_bezos, 5, 0, 2, 2);
    layout_technology -> addWidget(for_jobs, 5, 2, 2, 2);
    layout_technology ->addWidget(submit, 7, 2, 1, 2);

    _widgets -> addTab(window_technology, "technology");

    // 信号与槽
    connect(submit, &QPushButton::clicked, this, &MainWindow::after_submit);
}

void MainWindow::after_submit() {
    QMessageBox::information(this, "Submission successful!", "We have received your questionnaire.");
}

MainWindow::~MainWindow()
{
}

