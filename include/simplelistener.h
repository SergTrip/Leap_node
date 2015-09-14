#ifndef SIMPLELISTENER_H
#define SIMPLELISTENER_H

#include <QThread>
#include <QDebug>

#include <iostream>
#include <cstring>

#include "Leap.h"

const std::string fingerNames[] = { "Thumb",            "Index",        "Middle",       "Ring",     "Pinky" };
const std::string boneNames[]   = { "Metacarpal",       "Proximal",     "Middle",       "Distal"            };
const std::string stateNames[]  = { "STATE_INVALID",    "STATE_START",  "STATE_UPDATE", "STATE_END"         };

using namespace Leap;

class SampleListener : public QThread, public Listener
{
    Q_OBJECT

public:

    SampleListener();
    ~SampleListener();

    void run();

    virtual void onInit                 (const Controller&);
    virtual void onConnect              (const Controller&);
    virtual void onDisconnect           (const Controller&);
    virtual void onExit                 (const Controller&);
    virtual void onFrame                (const Controller&);
    virtual void onFocusGained          (const Controller&);
    virtual void onFocusLost            (const Controller&);
    virtual void onDeviceChange         (const Controller&);
    virtual void onServiceConnect       (const Controller&);
    virtual void onServiceDisconnect    (const Controller&);

Q_SIGNALS:
    // Initilize done
    void initializedSignal();

    // Connect done
    void connectedSignal();
    void disconnectedSignal();

    void exitedSignal();

    void serviceConnectedSignal();
    void serviceDisconnectedSignal();

    void releySignal(bool state);

private:
    // Leap Controller object
    Controller      controller;

    Leap::Vector    m_vThand;
    Leap::Vector    m_vIndex;

    bool            m_bLastState;
};

#endif // SIMPLELISTENER_H
