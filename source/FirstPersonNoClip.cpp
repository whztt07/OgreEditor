#include "FirstPersonNoClip.h"
FirstPersonNoClip::FirstPersonNoClip(Ogre::Camera* cam)
{
    mCam = cam;
    mCameraMan = new OgreBites::SdkCameraMan(cam);
}
FirstPersonNoClip::~FirstPersonNoClip()
{
    delete mCameraMan;
    mCameraMan= NULL;
}
void FirstPersonNoClip::update(float timeSinceLastFrame, OIS::Keyboard* inputManager)
{
    float moveScale = timeSinceLastFrame;
    Ogre::Vector3 translateVector = Ogre::Vector3::ZERO;
    if(inputManager->isKeyDown(OIS::KC_PGUP))
        mCam->setPosition(mCam->getPosition() + Ogre::Vector3(0, 5, 0));
 
    if(inputManager->isKeyDown(OIS::KC_PGDOWN))
        mCam->setPosition(mCam->getPosition() - Ogre::Vector3(0, 5, 0));
    // Move camera forward.
    if(inputManager->isKeyDown(OIS::KC_W))
         translateVector.z = -(moveScale);

    // Move camera backward.
    if(inputManager->isKeyDown(OIS::KC_S))
         translateVector.z = moveScale;

    // Move camera left.
    if(inputManager->isKeyDown(OIS::KC_A))
         translateVector.x = -(moveScale);

    // Move camera right.
    if(inputManager->isKeyDown(OIS::KC_D))
         translateVector.x = moveScale;
    mCam->moveRelative(translateVector);
}
bool FirstPersonNoClip::mouseMoved(const OIS::MouseEvent& evt)
{
    mCameraMan->injectMouseMove(evt);
    return true;
}
const Ogre::Quaternion& FirstPersonNoClip::getOrientation()
{
    return mCam->getOrientation();
}
const Ogre::Vector3&    FirstPersonNoClip::getPosition()
{
    return mCam->getPosition();
}
Ogre::Ray FirstPersonNoClip::getCameraToViewportRay(Ogre::Real screenx, Ogre::Real screeny)
{
    return mCam->getCameraToViewportRay(screenx,screeny);
}
