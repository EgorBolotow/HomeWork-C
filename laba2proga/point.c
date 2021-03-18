#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <point.h>

#define EXP 0.00001

//constructor of point
Point_t* init_point (float x, float y) {
    Point_t* point = (Point_t*)malloc(sizeof(Point_t));
    point->x = x;
    point->y = y;
    return point;
}

int print_coordinates(Point_t* point) {
    printf("Coordinates x = %f y = %f",point->x,point->y);
    return 0;
}

int equality_fracNum (float a, float b) {
    if ((fabs(a-b)) < EXP) {
        return 1;
    } else {
        return 0;
    }
}

int parallel_abscissa_axis (Point_t* point1,Point_t* point2) {
    if (equality_fracNum(point1->y,point2->y)) {
        return 1;
    } else {
        return 0;
    }
}

int parallel_ordinate_axis (Point_t* point1,Point_t* point2) {
    if (equality_fracNum(point1->x,point2->x)) {
        return 1;
    } else {
        return 0;
    }
}

float distance_between_2points (Point_t* point1,Point_t* point2) {
    float a;
    float b;
    if (point1->x < point2->x) {
        a = point2->x - point1->x;
    } else {
        a = point1->x - point2->x;
    }

    if (point1->y < point2->y) {
        b = point2->y - point1->y;
    } else {
        b = point1->y - point2->y;
    }

    return sqrtf((a*a) + (b*b));
}

Point_t* init_triangle(float x1,float y1,
                       float x2,float y2,
                       float x3,float y3) {
    Point_t* triangle = (Point_t*)malloc(sizeof(Point_t)*3);
    triangle[0].x = x1;
    triangle[0].y = y1;
    triangle[1].x = x2;
    triangle[1].y = y2;
    triangle[2].x = x3;
    triangle[2].y = y3;
    return triangle;
}

float area_triangle(Point_t* triangle) {
    float i0j0 = triangle[0].x - triangle[2].x;
    float i0j1 = triangle[0].y - triangle[2].y;
    float i1j0 = triangle[1].x - triangle[2].x;
    float i1j1 = triangle[1].y - triangle[2].y;

    return 0.5*(fabs((i0j0*i1j1) - (i0j1*i1j0)));
}
 
