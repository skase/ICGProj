#include "Camera.h"

#include "Core/Math/Rotator.h"

Matrix Camera::getWorldToProjectionMatrix() const
{
	float sinYaw = Math::Sin(Math::DegreesToRadians(yaw_));
	float sinPitch = Math::Sin(Math::DegreesToRadians(pitch_));

	Rotator rotator(pitch_, yaw_, 0.0f);
	Matrix test1 = Matrix::CreateXRotation(Math::DegreesToRadians(pitch_)).GetTranspose() * Matrix::CreateZRotation(Math::DegreesToRadians(yaw_)).GetTranspose();
	Matrix test2(rotator);

	//return viewToProjection_ * cy::Matrix4f::MatrixRotation(-upDir_, -upDir_) * cy::Matrix4f::MatrixTrans(-position_);
	//return viewToProjection_ * cy::Matrix4f::MatrixRotation(cy::Point3f(sinYaw, sqrtf(1 - sinYaw * sinYaw - sinPitch * sinPitch), sinPitch), -upDir_) * cy::Matrix4f::MatrixTrans(-position_);
	//return viewToProjection_ * cy::Matrix4f::MatrixNormal(cy::Point3f(0.0f, 1.0f, 0.0f), cyPoint3f(1.0f, 0.0f, 0.0f)) * cy::Matrix4f::MatrixTrans(-position_);
	//return viewToProjection_ * cy::Matrix4f::MatrixRotationY(yaw_ * cy::cyPi<float>() / 180.0f) * cy::Matrix4f::MatrixRotationX(pitch_ * cy::cyPi<float>() / 180.0f) * cy::Matrix4f::MatrixTrans(-position_)/*.GetTranspose()*/;
	//return viewToProjection_ * Matrix::CreateXRotation(Math::DegreesToRadians(pitch_)).GetTranspose() * Matrix::CreateZRotation(Math::DegreesToRadians(yaw_)).GetTranspose() * Matrix::CreateTranslate(-position_).GetTranspose();
	return viewToProjection_ * Matrix(rotator).GetTranspose() * Matrix::CreateTranslate(-position_).GetTranspose();
}

void Camera::Rotate(float yaw, float pitch)
{
	yaw_ += yaw;
	pitch_ += pitch;
}
