#include <iostream>
#include <string>
#include <cstdio>
#include <cassert>
#include <coding-problems (2).h>

int main()
{
    //these are my unit test

    //FindCameraHeight/////////////////////////////////////////


    //two regular test
    double camera_height;
    assert(FindCameraHeight(100, 30, camera_height) == 0);
    assert(abs(camera_height - 186.603) < 0.01);

    assert(FindCameraHeight(45, 45, camera_height) == 0);
    assert(abs(camera_height - 54.3199) < 0.01);


    //couple of edge cases
    
    assert(FindCameraHeight(0, 45, camera_height) == 1);
    assert(FindCameraHeight(45, 0, camera_height) == 1);
    assert(FindCameraHeight(0, 0, camera_height) == 1);

    assert(FindCameraHeight(-1, 45, camera_height) == 1);
    assert(FindCameraHeight(45, -1, camera_height) == 1);
    assert(FindCameraHeight(-1, -1, camera_height) == 1);

    assert(FindCameraHeight(45, 180, camera_height) == 1);
    assert(FindCameraHeight(45, 185, camera_height) == 1);

    printf("Passed all FindCameraHeight Assertions\n\n");



    //FindIntersectionDistance/////////////////////////////////

    //two regualr test cases
    double distance;
    assert(FindIntersectionDistance(20.0, 20.0, distance) == 0);
    assert(abs(distance - 7.2794) < 0.01);

    assert(FindIntersectionDistance(50.0, 45.0, distance) == 0);
    assert(abs(distance - 50.0) < 0.01);

    //couple of edge cases

    assert(FindIntersectionDistance(50.0, 0, distance) == 0);
    assert(abs(distance - 0) < 0.01);

    assert(FindIntersectionDistance(50.0, -1, distance) == 1);
    assert(FindIntersectionDistance(0, 50, distance) == 1);
    assert(FindIntersectionDistance(-1, 50, distance) == 1);
    assert(FindIntersectionDistance(50, 90, distance) == 1);
    assert(FindIntersectionDistance(50, 95, distance) == 1);



    //IsHomeRun////////////////////////////////////////////////

    //two normal cases
    bool is_homerun;
    assert(IsHomeRun(300.0, 35, 12, is_homerun) == 1);
    assert(IsHomeRun(30.0, 20, 12, is_homerun) == 0);

    
    //a couple edge cases
    assert(IsHomeRun(0, 35, 12, is_homerun) == 0);
    assert(IsHomeRun(-5000, 35, 12, is_homerun) == 0);
    assert(IsHomeRun(300.0, 0, 12, is_homerun) == 0);
    assert(IsHomeRun(300.0, -45, 12, is_homerun) == 0);

    assert(IsHomeRun(300.0, -300, 12, is_homerun) == 1);

    return 0;
}
