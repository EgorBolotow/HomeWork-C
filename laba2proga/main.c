#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <point.h>

int main(int argc, char** argv)
{
    float first_point_x;
    float first_point_y;
    float second_point_x;
    float second_point_y;
    float third_point_x;
    float third_point_y;


    printf("Enter the coordinates of the first point: ");
    printf("x = ");
    scanf ("%f",&first_point_x);
    printf("y = ");
    scanf ("%f",&first_point_y);

    printf("Enter the coordinates of the second point: ");
    printf("x = ");
    scanf ("%f",&second_point_x);
    printf("y = ");
    scanf ("%f",&second_point_y);

    Point_t* first_point = init_point(first_point_x, first_point_y);
    Point_t* second_point = init_point(second_point_x, second_point_y);

    print_coordinates(first_point);
    printf("\n");
    print_coordinates(second_point);
    printf("\n");

    if (parallel_abscissa_axis(first_point,second_point)) {
        printf ("The straight line passing through your points is parallel to the abscissa axis.");
        printf("\n");
    } else {
        printf("The straight line through your points is not parallel to the abscissa axis.");
        printf("\n");
    }

    if (parallel_ordinate_axis(first_point,second_point)) {
        printf ("The straight line passing through your points is parallel to the ordinate axis.");
        printf("\n");
    } else {
        printf("The straight line through your points is not parallel to the ordinate axis.");
        printf("\n");
    }

    printf("Distance between two points = %f", distance_between_2points(first_point,second_point));
    printf("\n");

    printf("Enter the coordinates of the triangle: ");
    scanf("%f%f%f%f%f%f",
          &first_point_x,&first_point_y,
          &second_point_x,&second_point_y,
          &third_point_x,&third_point_y);
    Point_t* triangle = init_triangle(
        first_point_x,first_point_y,
        second_point_x,second_point_y,
        third_point_x,third_point_y);
    printf("Area of triangle = %f", area_triangle(triangle));



    return 0;
}
