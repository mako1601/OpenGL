#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>

enum class Movement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Camera {
public:
	// camera Attributes
	glm::vec3 Position{ 0.0f, 0.0f, 3.0f };
	glm::vec3 Front{ 0.0f, 0.0f, -1.0f };
	glm::vec3 Up;
	glm::vec3 Right;
	glm::vec3 WorldUp{ 0.0f, 1.0f, 0.0f };
	// euler Angles
	float Yaw	= -90.0f;
	float Pitch	= 0.0f;
	// camera options
	float MovementSpeed	= 2.5f;
	float Sensitivity	= 0.15f;
	float Zoom			= 90.0f;

	// constructor
	Camera() { updateCameraVectors(); }

	// returns the view matrix calculated using Euler Angles and the LookAt Matrix
	glm::mat4 GetViewMatrix();
	// processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
	void ProcessKeyboard(Movement direction, float deltaTime);
	// processes input received from a mouse input system. Expects the offset value in both the x and y direction.
	void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);
	// processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
	void ProcessMouseScroll(float yoffset);

private:
	// calculates the front vector from the Camera's (updated) Euler Angles
	void updateCameraVectors();
};

#endif