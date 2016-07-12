/*
 * Camera.cpp
 *
 *  Created on: 11 июля 2016 г.
 *      Author: CHESTER
 */

#include "Camera.h"

Camera::Camera(float posx,float posy,float posz) {
	this->position.x=posx;
	this->position.y=posy;
	this->position.z=posz;

}

const vector3& Camera::getLookAt() const {
	return lookAt;
}

void Camera::setLookAt(const vector3& lookAt) {
	this->lookAt = lookAt;
}

const vector3& Camera::getPosition() const {
	return position;
}

void Camera::setPosition(const vector3& position) {
	this->position = position;
}

Camera::~Camera() {
	// TODO Auto-generated destructor stub
}

