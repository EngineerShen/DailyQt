#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(1000, 700);
    setWindowTitle("QFrame_QDockWidget");

    // 设置中央部件与布局
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    _layout = new QGridLayout(centralWidget);

    // 设置背景颜色与字体颜色
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::black);
    pal.setColor(QPalette::WindowText, Qt::white);
    this -> setPalette(pal);

    // 主窗口: _header 相关
    _header = new QLabel("     -----    This is an American political software    -----     ", centralWidget);
    _header -> setAlignment(Qt::AlignCenter);
    _layout -> addWidget(_header, 0, 0, 1, 4);

    // 主窗口: _frame_dem 相关
    _frame_dem = new QFrame(centralWidget);
    _frame_dem -> setStyleSheet("background-color: blue;");
    _frame_dem -> setFrameShape(QFrame::Box);
    _frame_dem -> setFrameShadow(QFrame::Raised);
    _frame_dem -> setLineWidth(10);

    QVBoxLayout* dem_layout = new QVBoxLayout();
    _frame_dem -> setLayout(dem_layout);

    QLabel* dem_name = new QLabel("   *****   Democratic Party   *****   ", _frame_dem);
    dem_name -> setAlignment(Qt::AlignCenter);
    QFont font = dem_name -> font();
    font.setBold(true);
    font.setPointSize(15);
    dem_name -> setFont(font);

    QLabel* dem_pic = new QLabel(_frame_dem);
    QImage dem_img("D:\\Christopher\\Desktop\\dem.jpg");
    dem_pic -> setPixmap(QPixmap::fromImage(dem_img));

    QScrollArea* dem_area = new QScrollArea(_frame_dem);
    dem_area -> setWidgetResizable(false);
    dem_area -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    dem_area -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    dem_area -> setWidget(dem_pic);

    QLabel* dem_idea = new QLabel("1. Healthcare<br>2. Climate Action<br>3. Social Justice", _frame_dem);
    font = dem_idea -> font();
    font.setBold(true);
    font.setPointSize(10);
    dem_idea -> setFont(font);

    dem_layout -> addWidget(dem_name);
    dem_layout -> addWidget(dem_area);
    dem_layout -> addWidget(dem_idea);

    _layout -> addWidget(_frame_dem, 1, 0, 2, 2);

    // 主窗口: _frame_rep 相关
    _frame_rep = new QFrame(centralWidget);
    _frame_rep -> setStyleSheet("background-color: red;");
    _frame_rep -> setFrameShape(QFrame::Box);
    _frame_rep -> setFrameShadow(QFrame::Raised);
    _frame_rep -> setLineWidth(10);

    QVBoxLayout* rep_layout = new QVBoxLayout();
    _frame_rep-> setLayout(rep_layout);

    QLabel* rep_name = new QLabel("   *****   Republican Party   *****   ", _frame_rep);
    rep_name -> setAlignment(Qt::AlignCenter);
    font = rep_name -> font();
    font.setBold(true);
    font.setPointSize(15);
    rep_name -> setFont(font);

    QLabel* rep_pic = new QLabel(_frame_rep);
    QImage rep_img("D:\\Christopher\\Desktop\\rep.jpg");
    rep_pic -> setPixmap(QPixmap::fromImage(rep_img));

    QScrollArea* rep_area = new QScrollArea(_frame_rep);
    rep_area -> setWidgetResizable(false);
    rep_area -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    rep_area -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    rep_area -> setWidget(rep_pic);

    QLabel* rep_idea = new QLabel("1. Tax Cuts and Economic Freedom<br>2. National Security and Defense<br>3. Traditional Values", _frame_rep);
    font = rep_idea -> font();
    font.setBold(true);
    font.setPointSize(10);
    rep_idea -> setFont(font);

    rep_layout -> addWidget(rep_name);
    rep_layout -> addWidget(rep_area);
    rep_layout -> addWidget(rep_idea);

    _layout -> addWidget(_frame_rep, 1, 2, 2, 2);

    // Dock Widget 相关
    _dock_widget = new QDockWidget("Donation window", centralWidget);
    QWidget* for_dock = new QWidget(_dock_widget);
    _dock_widget -> setWidget(for_dock);

    QVBoxLayout* dock_layout = new QVBoxLayout();
    for_dock -> setLayout(dock_layout);

    QLabel* dock_header = new QLabel("DONATE TO YOUR PARTY", for_dock);
    dock_header -> setAlignment(Qt::AlignCenter);

    QTabWidget* widgets = new QTabWidget(for_dock);

    dock_layout -> addWidget(dock_header);
    dock_layout -> addWidget(widgets);

//    addDockWidget(Qt::TopDockWidgetArea, _dock_widget);

    // Dock Widget::widgets::dem_window 相关
    QWidget* dem_window = new QWidget(widgets);
    QGridLayout* d_w_layout = new QGridLayout(dem_window);

    QLabel* d_w_people = new QLabel("politician", dem_window);

    dem_people_button = new QToolButton(dem_window);
    dem_people_button -> setText("Just select.");

    QMenu* dem_menu = new QMenu(dem_people_button);
    QStringList dem_options = {"Joe Biden", "Gavin Newsom", "Josh Shapiro", "Hakeem Jeffries", "Wes Moore"};
    for (const QString& option : dem_options) {
        QAction* action = new QAction(option, dem_menu);
        dem_menu -> addAction(action);
        connect(action, &QAction::triggered, this, &MainWindow::dock_widget_menu_triggered_dem);
    }
    dem_people_button -> setMenu(dem_menu);
    dem_people_button -> setPopupMode(QToolButton::MenuButtonPopup);

    QLabel* dem_money = new QLabel("donation amount:", dem_window);

    QRadioButton* dem_money_1 = new QRadioButton("$5", dem_window);
    QRadioButton* dem_money_2 = new QRadioButton("$15", dem_window);
    QRadioButton* dem_money_3 = new QRadioButton("$25", dem_window);

    QPushButton* dem_confirm = new QPushButton("confirm", dem_window);

    d_w_layout -> addWidget(d_w_people, 0, 0, 1, 1);
    d_w_layout -> addWidget(dem_people_button, 0, 1, 1, 3);
    d_w_layout -> addWidget(dem_money, 1, 0, 1, 1);
    d_w_layout -> addWidget(dem_money_1, 1, 1, 1, 1);
    d_w_layout -> addWidget(dem_money_2, 1, 2, 1, 1);
    d_w_layout -> addWidget(dem_money_3, 1, 3, 1, 1);
    d_w_layout -> addWidget(dem_confirm, 2, 0, 1, 4);

    widgets -> addTab(dem_window, "Dem");

    // Dock Widget::widgets::rep_window 相关
    QWidget* rep_window = new QWidget(widgets);
    QGridLayout* r_w_layout = new QGridLayout(rep_window);

    QLabel* r_w_people = new QLabel("politician", rep_window);

    rep_people_button = new QToolButton(rep_window);
    rep_people_button -> setText("Just select.");

    QMenu* rep_menu = new QMenu(rep_people_button);
    QStringList rep_options = {"Donald Trump", "JD Vance", "John Thune", "Mike Johnson", "Marco Rubio"};
    for (const QString& option : rep_options) {
        QAction* action = new QAction(option, rep_menu);
        rep_menu -> addAction(action);
        connect(action, &QAction::triggered, this, &MainWindow::dock_widget_menu_triggered_rep);
    }
    rep_people_button -> setMenu(rep_menu);
    rep_people_button -> setPopupMode(QToolButton::MenuButtonPopup);

    QLabel* rep_money = new QLabel("donation amount:", rep_window);

    QRadioButton* rep_money_1 = new QRadioButton("$10", rep_window);
    QRadioButton* rep_money_2 = new QRadioButton("$20", rep_window);
    QRadioButton* rep_money_3 = new QRadioButton("$30", rep_window);

    QPushButton* rep_confirm = new QPushButton("confirm", rep_window);

    r_w_layout -> addWidget(r_w_people, 0, 0, 1, 1);
    r_w_layout -> addWidget(rep_people_button, 0, 1, 1, 3);
    r_w_layout -> addWidget(rep_money, 1, 0, 1, 1);
    r_w_layout -> addWidget(rep_money_1, 1, 1, 1, 1);
    r_w_layout -> addWidget(rep_money_2, 1, 2, 1, 1);
    r_w_layout -> addWidget(rep_money_3, 1, 3, 1, 1);
    r_w_layout -> addWidget(rep_confirm, 2, 0, 1, 4);

    widgets -> addTab(rep_window, "Rep");

    // 信号与槽
    connect(this, &MainWindow::menu_action_chosen_dem, this, &MainWindow::update_dem_buttonText);
    connect(this, &MainWindow::menu_action_chosen_rep, this, &MainWindow::update_rep_buttonText);
    connect(dem_confirm, &QPushButton::clicked, this, &MainWindow::confirm_clicked);
    connect(rep_confirm, &QPushButton::clicked, this, &MainWindow::confirm_clicked);
}

void MainWindow::dock_widget_menu_triggered_dem() {
    QAction* action = (QAction*)sender();
    if (action) { emit menu_action_chosen_dem(action -> text()); }
}

void MainWindow::update_dem_buttonText(const QString& option) {
    dem_people_button -> setText(option + "is your choice");
}

void MainWindow::dock_widget_menu_triggered_rep() {
    QAction* action = (QAction*)sender();
    if (action) { emit menu_action_chosen_rep(action -> text()); }
}

void MainWindow::update_rep_buttonText(const QString& option) {
    rep_people_button -> setText(option + "is your choice");
}

void MainWindow::confirm_clicked() {
    QMessageBox::information(this, "Success!", "Thank you very much for your donation!");
}

MainWindow::~MainWindow()
{
}

