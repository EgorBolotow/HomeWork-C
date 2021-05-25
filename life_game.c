#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned is_live: 1;
} Point;

#define MAP_HEIGHT 10

#define MAP_WIDTH 10

Point map[MAP_WIDTH][MAP_HEIGHT];

void init_map (Point map[][MAP_HEIGHT]) {
    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            unsigned int num = rand();
            if (num % 2 == 0) {
                map[i][j].is_live = 1;
            } else {
                map[i][j].is_live = 0;
            }
        }
    }
}

void print_map (Point map[][MAP_HEIGHT]) {
    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            if (map[i][j].is_live == 1) {
                printf("*");
            } else {
                printf(" ");
            }
            printf(" ");
        }
        printf("\n");
    }
}

int live_points (Point map[][MAP_HEIGHT]) {
    int counter = 0;
    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            if (map[i][j].is_live == 1) {
                counter++;
            }
        }
    }
    return counter;
}

void point_neighbors (int nb[][2], unsigned int x, unsigned int y) {
    unsigned int k = 0;

    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i == x && j == y) {
                continue;
            }
            nb[k][0] = i;
            nb[k][1] = j;
            k++;
        }
    }
}

int live_neighbors(Point map[][MAP_HEIGHT], unsigned int x, unsigned int y) {
    unsigned int counter = 0;
    signed int nb[8][2];
    signed int x2, y2;

    point_neighbors(nb, x, y);

    for (int i = 0; i < 8; i++) {
        x2 = nb[i][0];
        y2 = nb[i][1];

        if (x2 < 0 || y2 < 0) {
            continue;
        }
        if (x2 >= MAP_WIDTH || y2 >= MAP_HEIGHT) {
            continue;
        }

        if (map[x2][y2].is_live == 1) {
            counter++;
        }
    }

    return counter;
}

void next_generation(Point map[][MAP_HEIGHT], Point prev_map[][MAP_HEIGHT]) {
    unsigned int live_nb;
    Point p;

    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            p = prev_map[i][j];
            live_nb = live_neighbors(prev_map, i, j);

            if (p.is_live == 0) {
                if (live_nb == 3) {
                    map[i][j].is_live = 1;
                }
            } else {
                if (live_nb < 2 || live_nb > 3) {
                    map[i][j].is_live = 0;
                }
            }
        }
    }
}

void copy_world(Point src[][MAP_HEIGHT], Point dest[][MAP_HEIGHT]) {
    unsigned int i, j;
    for (i = 0; i < MAP_WIDTH; i++) {
        for (j = 0; j < MAP_HEIGHT; j++) {
            dest[i][j] = src[i][j];
        }
    }
}

int cmp_world(Point w1[][MAP_HEIGHT], Point w2[][MAP_HEIGHT]) {
    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            if (w1[i][j].is_live != w2[i][j].is_live) {
                return -1;
            }
        }
    }
    return 0;
}

int main(void) {
    Point world[MAP_WIDTH][MAP_HEIGHT];
    Point prev_world[MAP_WIDTH][MAP_HEIGHT];

    init_map(world);
    unsigned int live_points2 = -1;
    int is_optimal = 0;

    do {
        print_map(world);
        copy_world(world, prev_world);
        next_generation(world, prev_world);

        is_optimal = cmp_world(world, prev_world) == 0;
        live_points2 = live_points(world);

        if (is_optimal) {
            printf("Optimal configuration");
        }

        if (live_points == 0) {
            printf("All points died");
        }
        sleep(1);
    } while (live_points != 0 && !is_optimal);

    return 0;
}
