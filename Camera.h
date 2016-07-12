/*
 * Camera.h
 *
 *  Created on: 11 июля 2016 г.
 *      Author: CHESTER
 */

#ifndef CAMERA_H_
#define CAMERA_H_

struct vector3{
	float x;
	float y;
	float z;
};

class Camera {
private:
	vector3 position;
	vector3 lookAt;
public:
	Camera(float posx,float posy,float posz);
	virtual ~Camera();
	const vector3& getLookAt() const;
	void setLookAt(const vector3& lookAt);
	const vector3& getPosition() const;
	void setPosition(const vector3& position);
};

#endif /* CAMERA_H_ */
