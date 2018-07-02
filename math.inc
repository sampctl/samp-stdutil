// built-in include guard removal
// just in case the user has a local dependency with the same file name
#if defined _inc_math
	#undef _inc_math
#endif
// custom include-guard to ensure we don't duplicate
#if defined _math_included
	#endinput
#endif
#define _math_included


#include <a_samp>


// Truncates a value to the range 0.0 - 360.0
stock Float:GetAbsoluteAngle(Float:angle) {
	while(angle < 0.0) {
		angle += 360.0;
	}
	while(angle > 360.0) {
		angle -= 360.0;
	}
	return angle;
}

// Returns the offset heading from north between a point and a destination
stock Float:GetAngleToPoint(Float:fPointX, Float:fPointY, Float:fDestX, Float:fDestY) {
	return GetAbsoluteAngle(-(
		90.0 - (
			atan2(
				(fDestY - fPointY),
				(fDestX - fPointX)
			)
		)
	));
}

// Returns the distance between two points in 3D space
stock Float:GetDistance3D(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2) {
	return VectorSize(x1 - x2, y1 - y2, z1 - z2);
}

// Returns the distance between two points in 2D space
stock Float:GetDistance2D(Float:x1, Float:y1, Float:x2, Float:y2) {
	return floatsqroot(
		((x1 - x2) * (x1 - x2)) +
		((y1 - y2) * (y1 - y2))
	);
}

// Distance from any point on a projected line to a point
stock Float:GetDistancePointLine(
	Float:line_x, Float:line_y, Float:line_z,
	Float:vector_x, Float:vector_y, Float:vector_z,
	Float:point_x, Float:point_y, Float:point_z
) {
	return (
		VectorSize(
			(vector_y) * ((point_z) - (line_z)) - (vector_z) * ((point_y) - (line_y)),
			(vector_z) * ((point_x) - (line_x)) - (vector_x) * ((point_z) - (line_z)),
			(vector_x) * ((point_y) - (line_y)) - (vector_y) * ((point_x) - (line_x))
		) / VectorSize(vector_x, vector_y, vector_z)
	);
}

// 2D Projection position based on distance and angle
stock GetXYFromAngle(&Float:x, &Float:y, Float:a, Float:distance) {
	x += (distance * floatsin(-a, degrees));
	y += (distance * floatcos(-a, degrees));
}

// 3D Projection position based on distance and angles
stock GetXYZFromAngle(&Float:x, &Float:y, &Float:z, Float:angle, Float:elevation, Float:distance) {
	x += distance * floatsin(angle, degrees) * floatcos(elevation, degrees);
	y += distance * floatcos(angle, degrees) * floatcos(elevation, degrees);
	z += distance * floatsin(elevation, degrees);
}

// Convert 3D velocity vectors to a single velocity unit (close to Km/h in SA:MP)
stock Float:CalculateVelocity(Float:x, Float:y, Float:z) {
	return VectorSize(x, y, z) * 150.0;
}

// Return a floating point random number
stock Float:floatrandom(Float:max, Float:min = 0.0, decimalPlaces = 4) {
	new
		Float:multiplier = floatpower(10.0, decimalPlaces),
		minRounded = floatround(min * multiplier),
		maxRounded = floatround(max * multiplier);
	return float(random(maxRounded - minRounded) + minRounded) / multiplier;
}

// Forces a floating point value to be within a range (default arguments represent negative and positive infinity respectively)
stock Float:floatclamp(Float:value, Float:min = Float:0xFF800000, Float:max = Float:0x7F800000) {
	if (value < min) {
		return min;
	}
	if (value > max) {
		return max;
	}
	return value;
}

// Checks if one angle is within range of another angle
stock AngleInRangeOfAngle(Float:a1, Float:a2, Float:range) {
	a1 -= a2;
	return (a1 < range) && (a1 > -range);
}

// Returns the absolute value of an integer
stock abs(int) {
	if(int < 0) {
		return -int;
	}
	return int;
}

// Checks if a value is not a number
stock IsNaN(Float:number) {
	return number != number;
}
