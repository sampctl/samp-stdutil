#include "util.inc"


main(){
	printf("361 absolute: %f", GetAbsoluteAngle(361.0));
	printf("-180 absolute: %f", GetAbsoluteAngle(-180.0));
	printf("720 absolute: %f", GetAbsoluteAngle(720.0));

	printf("angle to 50, 50: %f", GetAngleToPoint(0.0, 0.0, 50.0, 50.0));
	printf("angle to -50, 50: %f", GetAngleToPoint(0.0, 0.0, -50.0, 50.0));
	printf("angle to -50, -50: %f", GetAngleToPoint(0.0, 0.0, -50.0, -50.0));
	printf("angle to 50, -50: %f", GetAngleToPoint(0.0, 0.0, 50.0, -50.0));

	printf("distance to 50, 50, 50: %f", GetDistance3D(0.0, 0.0, 0.0, 50.0, 50.0, 50.0));
}
