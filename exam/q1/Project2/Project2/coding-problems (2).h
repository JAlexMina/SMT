#define PI 3.14159

#include <math.h>       /* trig functions */
#include <iostream>

// Our SMT coding exercise is below. There are three methods that need to be filled out.  
// There are descriptions for each method (pay close attention to the return values), as well as the 
// method prototypes. You should use C++ to implement the methods and any testing you deem appropriate.
// Take as much time as you need and send back the completed file(s) once you are finished, as well 
// as any console output of the results of your testing.

// Imagine a camera pointed straight down at a field. We would like to figure out how far off the
// ground the camera needs to be in order to see the entire field within the camera's field of
// view. For this problem, imagine the simple 2D problem as illustrated below. Don't worry about
// the camera's orientation or the difference between horizontal field of view and vertical field
// of view. Suppose that covering the length of the field is also sufficient for 
// covering the width of the field. Your objective is to fill-out the skeleton function called 
// FindCameraHeight. The inputs to the function are the length of the field and the camera's known
// field of view (in degrees). The output will be your computed camera height (given in the same units
// as the field length). You should use the return value to flag inappropriate inputs.
//                              ____
//                             |    |
//                             |    | camera
//      _                      |____|
//                               /\ 
//      |                       /__\    
//      |                      /\__/\   
//      |                    /  fov   \ <- camera_field_of_view
//      |  camera          /            \   
//      |  height        /                \ 
//      |              /                    \   
//      |            /                        \ 
//      |          /                            \   
//      |        /                                \ 
//      _      /____________________________________\   
//             ^                 ^                  ^
//             |                 |                  |
//           field              mid               field
//           start             field               end
//
//             |____________________________________|
//                          field_length
//
//
//
//                              /|\ 
//half_camera_field_of_view --/> |  \   
//                          /    |    \ 
//                        /      |      \   
//                      /        |        \ 
//                    /          |<- height \   
//                  /            |            \ 
//                /             _|              \   
//              /______________|_|________________\ 
//                      ^
//              |-----------------|
//               half_field_length
//
bool FindCameraHeight(const double field_length, const double camera_field_of_view, double &camera_height)
{
    //returning 1 if there is an issue with input data
    if(field_length <= 0 || camera_field_of_view <= 0 || camera_field_of_view  >= 180)
    {
        return 1;
    }

    double half_field_length = field_length/2.0;
    double half_camera_field_of_view = camera_field_of_view/2.0;
    camera_height = half_field_length/tan(half_camera_field_of_view * PI / 180.0);
    return 0;
}


// In the following 2D scenario, the camera is tilted down towards the field. We would like to
// compute the distance along the ground plane between the camera and where the camera is looking.
// To do this, imagine that the camera's center of projection and principal point are aligned and
// that you should perform the intersection with the ground plane using the very center of the
// camera's lens. Your objective is to fill-out the skeleton function called
// FindIntersectionDistance. The inputs to the function are the camera's height (in some units),
// the camera's tilt down from the horizon (in degrees), and the output is the distance from the
// origin (on the ground directly below the camera's principal point) to the intersection point 
// along the ground plane. You should use the return value to flag inappropriate inputs.
//
//            camera
//            ______
//         _ |      |/| _  _  _  _  _  _  _  _  _  _  _  _  _  _  _   <- horizon
//           |______|\|          |
//         |                    /
//         |         |        /   camera_tilt (down from horizon)
//         |               /
// camera  |         |_ /
// height  |
//         |
//         |
//         |
//         |
//         _         ______________________________________________ <- ground plane
//                  ^
//                  |
//                origin
//
//                                      _ _
// camera_tilt  |\                       |
//   (angle) ---|> \                     |
//              |    \                   | 
//              |      \                 |  Camera
//              |        \               |  Height
//              |          \             |
//              |            \           |
//              |_             \         |
//              |_|______________\      _|_
//                      ^
//                   distance
//
//
bool FindIntersectionDistance(const double camera_height, const double camera_tilt, double &distance)
{
    //returning 1 if there is an issue with input data
    if(camera_tilt >= 90 || camera_tilt < 0 || camera_height <= 0)
    {
        return 1;
    }

    distance = camera_height*tan(camera_tilt * PI / 180.0);
    return 0;
}


// A batter located at the origin has hit a baseball and we would like to figure out if the ball
// was hit well enough to fly over the outfield wall for a home run. You should imagine the 2D
// scenario depicted below. Your objective is to fill-out the skeleton function called
// IsHomeRun. The inputs to the function will be the the exit velocity of the ball (in "units" per
// second), the launch angle up away from the horizon (in degrees), and the height of the outfield
// wall (in "units"). The givens are that the ball was contacted 3 units off of the ground, the
// outfield wall is located 400 units from the origin, and that there is a downward force of 32.2
// units per second squared. The output is a single boolean flag denoting whether the ball will be
// a home run. You should use the return value to flag inappropriate inputs.
//                                                  __
//                                                 |__|
//
//                                  __                        __
//                                 |__|                      |__|
//
//                  __                                                   _
//                 |__|                                               |
// contact  _                                                         |  |  wall_height
//  height  _  |______________________________________________________|  _
// = 3 units   ^
//             |
//           origin
//
//             |______________________________________________________|
//                        outfield wall distance = 400 units
//
bool IsHomeRun(const double exit_velocity, const double launch_angle, const double wall_height, bool &is_homerun)
{
    if ((launch_angle <= 0 && launch_angle > -270) || exit_velocity <= 0)
    {
        is_homerun = 0;
        return is_homerun;
    }

    const double wall_distance = 400.0;
    const double contact_height = 3.0;
    const double gravity = 32.2;

    const double sin_ang = sin(launch_angle * PI / 180.0);
    const double cos_ang = cos(launch_angle * PI / 180.0);

    double t = wall_distance/(exit_velocity*(cos_ang));
    double height_at_wall = contact_height + exit_velocity*t*sin_ang - 0.5*(gravity)*t*t;

    //std::cout << height_at_wall << std::endl;
    is_homerun = ((wall_height) < height_at_wall);
    return is_homerun;
}
