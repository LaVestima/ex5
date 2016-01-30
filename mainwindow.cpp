#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    pixmap = new QPixmap(ui->label->width(), ui->label->height());

    ui->label->installEventFilter(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

bool MainWindow::eventFilter(QObject *object, QEvent *event) { // Double click event
    if(object == ui->label) {
        if(event->type() == QEvent::MouseButtonDblClick) {
            QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);

            for (int i = 0; i < 3; i++) {
                QRadioButton* shapeButton = findChild<QRadioButton*>("radioButton_" + QString::number(i));

                if (shapeButton->isChecked()) {
                    int shapeWidth = ui->widthLineEdit->text().toDouble();
                    int shapeHeight = ui->heightLineEdit->text().toDouble();

                    switch(i) {
                    case 0: // Circle
                        shapeList.push_back(new Circle(mouseEvent->pos(), shapeWidth, shapeHeight));
                        ui->circleComboBox->addItem(QString::number(shapeList.count()-1));
                        ui->circleComboBox->setCurrentIndex(-1);
                        break;
                    case 1: // Rectangle
                        shapeList.push_back(new Square(mouseEvent->pos(), shapeWidth, shapeHeight));
                        ui->circleComboBox->addItem(QString::number(shapeList.count()-1));
                        ui->circleComboBox->setCurrentIndex(-1);
                        break;
                    case 2: // Triangle
                        shapeList.push_back(new Triangle(mouseEvent->pos(), shapeWidth, shapeHeight));
                        ui->circleComboBox->addItem(QString::number(shapeList.count()-1));
                        ui->circleComboBox->setCurrentIndex(-1);
                        break;
                    }
                }
            }
        }
    }
    //on_drawPushButton_clicked();
    return QMainWindow::eventFilter(object,event);
}

void MainWindow::on_drawPushButton_clicked() {
    pixmap->fill(Qt::white);

    if (ui->checkBox->isChecked()) {
        for(int i = 0; i < shapeList.count(); i++) {
            shapeList[i]->draw(pixmap);
        }
//        for(int i = 0; i < squareList.count(); i++) {
//            squareList[i].draw(pixmap);
//        }
//        for(int i = 0; i < triangleList.count(); i++) {
//            triangleList[i].draw(pixmap);
//        }
    }
    else {
        int shapeNumber = -1;
        if ((shapeNumber = ui->circleComboBox->currentIndex()) >= 0) {
            shapeList[shapeNumber]->draw(pixmap);
        }
//        else if ((shapeNumber = ui->squareComboBox->currentIndex()) >= 0) {
//            squareList[shapeNumber].draw(pixmap);
//        }
//        else if ((shapeNumber = ui->triangleComboBox->currentIndex()) >= 0) {
//            triangleList[shapeNumber].draw(pixmap);
//        }

    }

    ui->label->setPixmap(*pixmap);
}

void MainWindow::on_circleComboBox_currentIndexChanged(int index) {
    ui->squareComboBox->setCurrentIndex(-1);
    ui->triangleComboBox->setCurrentIndex(-1);
    ui->checkBox->setChecked(false);
    ui->circleComboBox->setCurrentIndex(index);
}

void MainWindow::on_squareComboBox_currentIndexChanged(int index) {
    ui->circleComboBox->setCurrentIndex(-1);
    ui->triangleComboBox->setCurrentIndex(-1);
    ui->checkBox->setChecked(false);
    ui->squareComboBox->setCurrentIndex(index);
}

void MainWindow::on_triangleComboBox_currentIndexChanged(int index) {
    ui->circleComboBox->setCurrentIndex(-1);
    ui->squareComboBox->setCurrentIndex(-1);
    ui->checkBox->setChecked(false);
    ui->triangleComboBox->setCurrentIndex(index);
}

void MainWindow::on_deleteSelectedPushButton_clicked() {
    int shapeNumber = -1;
    if ((shapeNumber = ui->circleComboBox->currentIndex()) >= 0) {
        shapeList.removeAt(shapeNumber);
        ui->circleComboBox->removeItem(shapeList.count());
    }
//    else if ((shapeNumber = ui->squareComboBox->currentIndex()) >= 0) {
//        squareList.removeAt(shapeNumber);
//        ui->squareComboBox->removeItem(squareList.count());
//    }
//    else if ((shapeNumber = ui->triangleComboBox->currentIndex()) >= 0) {
//        triangleList.removeAt(shapeNumber);
//        ui->triangleComboBox->removeItem(triangleList.count());
//    }
}

void MainWindow::on_deleteAllPushButton_clicked() {
    for(int i = 0; i < shapeList.count(); i++) {
        ui->circleComboBox->removeItem(0);
    }
    shapeList.clear();
//    for(int i = 0; i < squareList.count(); i++) {
//        ui->squareComboBox->removeItem(0);
//    }
//    squareList.clear();
//    for(int i = 0; i < triangleList.count(); i++) {
//        ui->triangleComboBox->removeItem(0);
//    }
//    triangleList.clear();
}

void MainWindow::on_editSelectedPushButton_clicked() {
    int shapeNumber = -1;
    int shapeWidth = ui->widthLineEdit->text().toDouble();
    int shapeHeight = ui->heightLineEdit->text().toDouble();

    if ((shapeNumber = ui->circleComboBox->currentIndex()) >= 0) {
        //shapeList[shapeNumber].setRadius(shapeWidth);
        shapeList[shapeNumber]->setWidth(shapeWidth);
        shapeList[shapeNumber]->setHeight(shapeHeight);
        //circleList.removeAt(shapeNumber);
        //ui->circleComboBox->removeItem(circleList.count());
    }
//    else if ((shapeNumber = ui->squareComboBox->currentIndex()) >= 0) {
//        squareList[shapeNumber].setWidth(shapeWidth);
//        squareList[shapeNumber].setHeight(shapeHeight);
//        //squareList.removeAt(shapeNumber);
//        //ui->squareComboBox->removeItem(squareList.count());
//    }
//    else if ((shapeNumber = ui->triangleComboBox->currentIndex()) >= 0) {
//        triangleList[shapeNumber].setWidth(shapeWidth);
//        triangleList[shapeNumber].setHeight(shapeHeight);
//        //triangleList.removeAt(shapeNumber);
//        //ui->triangleComboBox->removeItem(triangleList.count());
//    }
}
