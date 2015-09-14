#include "simplelistener.h"

SampleListener::~SampleListener()
{
    // Remove the sample listener when done
    controller.removeListener( *(Listener*)this );
}

void SampleListener::run()
{
    // Have the sample listener receive events from the controller
    controller.addListener( *(Listener*)this );

    controller.setPolicy( Leap::Controller::POLICY_BACKGROUND_FRAMES );

    // Slots connecting for internal using

    // Start event loop
    exec();
}

void SampleListener::onInit(const Controller& controller)
{
  std::cout << "Initialized" << std::endl;

  // Send signal
  this->initializedSignal();
}

void SampleListener::onConnect(const Controller& controller)
{
  std::cout << "Connected" << std::endl;

//  controller.enableGesture( Gesture::TYPE_CIRCLE        );
//  controller.enableGesture( Gesture::TYPE_KEY_TAP       );
//  controller.enableGesture( Gesture::TYPE_SCREEN_TAP    );
//  controller.enableGesture( Gesture::TYPE_SWIPE         );

  this->connectedSignal();
}

void SampleListener::onDisconnect(const Controller& controller)
{
  // Note: not dispatched when running in a debugger.
  std::cout << "Disconnected" << std::endl;

  this->disconnectedSignal();
}

void SampleListener::onExit(const Controller& controller)
{
  std::cout << "Exited" << std::endl;
}

void SampleListener::onFrame(const Controller& controller)
{
    bool thand, index = false;

    // Get the most recent frame and report some basic information
    const Frame frame = controller.frame();

    // Receive Hand List
    HandList hands = frame.hands();

    // For all hands
    for (HandList::const_iterator hl = hands.begin(); hl != hands.end(); ++hl)
    {
        // Get the first hand
        const Hand hand         = *hl;

        // Only for right hand
        if( hand.isRight() )
        {
            // Get fingers
            const FingerList fingers = hand.fingers();
            // For all fingers in the list
            for (FingerList::const_iterator fl = fingers.begin(); fl != fingers.end(); ++fl)
            {
                      Bone      bone;
                const Finger    finger = *fl;

                // If thamb or Index finger
                if( finger.type() == Finger::TYPE_THUMB )
                {
                    // Receive nided bone
                    bone        = finger.bone(Bone::TYPE_DISTAL);
                    m_vThand    = bone.center();

                    thand = true;
                }
                else if( finger.type() == Finger::TYPE_INDEX )
                {
                    // Receive nided bone
                    bone        = finger.bone(Bone::TYPE_DISTAL);
                    m_vIndex    = bone.center();

                    index = true;
                }
            }
        }
    }

    if( !thand || !index )
    {
        emit releySignal( false );
    }
    else
    {
        float distance = m_vThand.distanceTo(m_vIndex);
        qDebug () << "Distance: " << distance;

        if( distance < 40 )
        {
            emit releySignal( true );
        }
        else
        {
            emit releySignal( false );
        }
    }
}

void SampleListener::onFocusGained(const Controller& controller)
{
    std::cout << "Focus Gained" << std::endl;
}

void SampleListener::onFocusLost(const Controller& controller)
{
    std::cout << "Focus Lost" << std::endl;
}

void SampleListener::onDeviceChange(const Controller& controller)
{
    std::cout << "Device Changed" << std::endl;
    const DeviceList devices = controller.devices();

    for (int i = 0; i < devices.count(); ++i)
    {
        std::cout << "id: "             <<  devices[i].toString()                           << std::endl;
        std::cout << "  isStreaming: "  << (devices[i].isStreaming() ? "true" : "false")    << std::endl;
    }
}

void SampleListener::onServiceConnect(const Controller& controller)
{
    std::cout << "Service Connected" << std::endl;

    this->serviceConnectedSignal();
}

void SampleListener::onServiceDisconnect(const Controller& controller)
{
    std::cout << "Service Disconnected" << std::endl;

    this->serviceDisconnectedSignal();
}
