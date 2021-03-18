#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#define EXP 0.00001

typedef struct Point {
    float x;
    float y;
} Point_t;

Point_t* init_point (float x, float y);
int print_coordinates(Point_t* point);
int equality_fracNum (float a, float b);
int parallel_abscissa_axis (Point_t* point1,Point_t* point2);
int parallel_ordinate_axis (Point_t* point1,Point_t* point2);
float distance_between_2points (Point_t* point1,Point_t* point2);
Point_t* init_triangle(float x1,float y1,
                       float x2,float y2,
                       float x3,float y3);
float area_triangle(Point_t* triangle);


#endif // POINT_H_INCLUDED
