#include <stdio.h>
#include <math.h>

#define H 0
#define O 1

typedef struct {
    double x, y, z;
} Point3D;

typedef struct {
    int type;
    Point3D pos;
} Atom;

int main() {
    char atoms;
    Atom atom[3] = {
        {H, {0.0, 0.0, 0.0}},
        {H, {1.0, 0.0, 0.0}},
        {H, {0.5, 0.5, 0.8}}
    };
    printf("물 분자:\n");
    for (int i = 0; i  < 3; i++) {
        Atom atom = atom[i];
        char* name = (atom.type == H) ? "H" : "O";
        printf("%s: (%.2f, %.2f, %.2f)\n", name, atom.pos.x, atom.pos.y, atom.pos.z);
    }
    return 0;
}