#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    drawPreview();

    connect(ui->slidRed, SIGNAL(valueChanged(int)),
            this, SLOT(drawPreview()));
    connect(ui->slidGreen, SIGNAL(valueChanged(int)),
            this, SLOT(drawPreview()));
    connect(ui->slidBlue, SIGNAL(valueChanged(int)),
            this, SLOT(drawPreview()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawPreview()
{
    QPixmap pixmap(100, 100);
    pixmap.fill(QColor(ui->slidRed->value(),
                       ui->slidGreen->value(),
                       ui->slidBlue->value()));
    ui->lblColorView->setPixmap(pixmap);
}
