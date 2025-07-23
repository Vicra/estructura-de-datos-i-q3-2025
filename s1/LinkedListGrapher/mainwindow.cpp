#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "nodeitem.h"

using std::to_string;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addNodeButton_clicked()
{
    QString value = ui->addValueInput->text();  // Get the text
    ui->addValueInput->clear();                 // Clear the input field

    // backend
    l.addNode(value.toInt());

    // frontend
    QGraphicsScene* scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setSceneRect(0, 0, 400, 300);

    redrawNodes();
}

void MainWindow::redrawNodes() {
    QGraphicsScene* scene = ui->graphicsView->scene();
    scene->clear(); // Remove existing nodes

    const int spacing = 120;
    const int startX = 50;
    const int y = 100;

    for (int i = 0; i < l.getItems().size(); ++i) {
        bool isLast = (i == l.getItems().size() - 1);
        NodeItem* node = new NodeItem(QString::fromStdString(l.getItems().at(i)), isLast);
        scene->addItem(node);
        node->setPos(startX + i * spacing, y);
    }
}
