#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>

#include "simplelistener.h"
#include "../include/qnode.hpp"

namespace Ui {
class Dialog;
}

using namespace leap_node;

class Dialog : public QDialog
{
    Q_OBJECT

public:
     Dialog(int argc, char** argv, QWidget *parent = 0);
    ~Dialog();

public Q_SLOTS:
    // Initilize done
    void initializedSlot();

    // Connect done
    void connectedSlot();
    void disconnectedSlot();

    void exitedSlot();

    void serviceConnectedSlot();
    void serviceDisconnectedSlot();

    void releySlot(bool state);

private:
    void showNoMasterMessage();

private:
    Ui::Dialog *ui;

    // Create a sample listener and controller
    SampleListener  listener;

    QNode           qnode;
};

#endif // DIALOG_H
