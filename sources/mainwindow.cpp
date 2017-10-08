#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  setWindowTitle("QT Template");

  QPixmap pm(":/naeco/images/profile_round.png");
  ui->label->setPixmap(pm);
  ui->label->setFixedSize(pm.size());
}

MainWindow::~MainWindow()
{
  delete ui;
}
