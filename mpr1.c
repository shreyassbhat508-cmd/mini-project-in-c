#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 20
#define COLS 40
#define MAX_OBJECTS 50

typedef enum { LINE, RECTANGLE, TRIANGLE, CIRCLE } ShapeType;

typedef struct {
    int x1, y1;
    int x2, y2;
    int x3, y3; // Used for triangle
    int radius; // Used for circle
    ShapeType type;
} GraphicObject;

// Global variables for canvas and object tracking
char canvas[ROWS][COLS];
GraphicObject objects[MAX_OBJECTS];
int object_count = 0;

// Canvas functions
void clearCanvas() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas() {
    printf("\n--- CANVAS (%dx%d) ---\n", COLS, ROWS);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            putchar(canvas[i][j]);
        }
        putchar('\n');
    }
    printf("---------------------\n");
}

// Helper safely plotting points
void plot(int x, int y) {
    if (x >= 0 && x < COLS && y >= 0 && y < ROWS) {
        canvas[y][x] = '*';
    }
}

// Bresenham's Line Generation Algorithm
void drawLine(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;

    while (1) {
        plot(x0, y0);
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

void drawRectangle(int x1, int y1, int x2, int y2) {
    drawLine(x1, y1, x2, y1); // Top
    drawLine(x1, y2, x2, y2); // Bottom
    drawLine(x1, y1, x1, y2); // Left
    drawLine(x2, y1, x2, y2); // Right
}

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    drawLine(x1, y1, x2, y2);
    drawLine(x2, y2, x3, y3);
    drawLine(x3, y3, x1, y1);
}

// Midpoint Circle Algorithm
void drawCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 3 - 2 * r;
    
    while (y >= x) {
        plot(xc + x, yc + y); plot(xc - x, yc + y);
        plot(xc + x, yc - y); plot(xc - x, yc - y);
        plot(xc + y, yc + x); plot(xc - y, yc + x);
        plot(xc + y, yc - x); plot(xc - y, yc - x);
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
    }
}

// Renders all current active objects onto the canvas layout
void renderAll() {
    clearCanvas();
    for (int i = 0; i < object_count; i++) {
        switch (objects[i].type) {
            case LINE:
                drawLine(objects[i].x1, objects[i].y1, objects[i].x2, objects[i].y2);
                break;
            case RECTANGLE:
                drawRectangle(objects[i].x1, objects[i].y1, objects[i].x2, objects[i].y2);
                break;
            case TRIANGLE:
                drawTriangle(objects[i].x1, objects[i].y1, objects[i].x2, objects[i].y2, objects[i].x3, objects[i].y3);
                break;
            case CIRCLE:
                drawCircle(objects[i].x1, objects[i].y1, objects[i].radius);
                break;
        }
    }
}

// Object Management Prompts
void inputObjectDetails(GraphicObject *obj) {
    printf("Select Shape Type:\n0. Line\n1. Rectangle\n2. Triangle\n3. Circle\nChoice: ");
    int type;
    scanf("%d", &type);
    obj->type = (ShapeType)type;

    if (obj->type == LINE || obj->type == RECTANGLE) {
        printf("Enter coordinate 1 (x1 y1) [0-%d, 0-%d]: ", COLS-1, ROWS-1);
        scanf("%d %d", &obj->x1, &obj->y1);
        printf("Enter coordinate 2 (x2 y2) [0-%d, 0-%d]: ", COLS-1, ROWS-1);
        scanf("%d %d", &obj->x2, &obj->y2);
    } else if (obj->type == TRIANGLE) {
        printf("Enter Vertex 1 (x1 y1): "); scanf("%d %d", &obj->x1, &obj->y1);
        printf("Enter Vertex 2 (x2 y2): "); scanf("%d %d", &obj->x2, &obj->y2);
        printf("Enter Vertex 3 (x3 y3): "); scanf("%d %d", &obj->x3, &obj->y3);
    } else if (obj->type == CIRCLE) {
        printf("Enter Center coordinate (xc yc): ");
        scanf("%d %d", &obj->x1, &obj->y1);
        printf("Enter Radius: ");
        scanf("%d", &obj->radius);
    }
}

void addObject() {
    if (object_count >= MAX_OBJECTS) {
        printf("Error: Object limit reached!\n");
        return;
    }
    printf("\n--- Add New Object ---\n");
    inputObjectDetails(&objects[object_count]);
    object_count++;
    renderAll();
}

void listObjects() {
    printf("\n--- Current Objects List ---\n");
    if (object_count == 0) {
        printf("No objects found.\n");
        return;
    }
    for (int i = 0; i < object_count; i++) {
        printf("ID: %d | ", i);
        switch (objects[i].type) {
            case LINE: printf("Line [(%d,%d) to (%d,%d)]\n", objects[i].x1, objects[i].y1, objects[i].x2, objects[i].y2); break;
            case RECTANGLE: printf("Rectangle [(%d,%d) to (%d,%d)]\n", objects[i].x1, objects[i].y1, objects[i].x2, objects[i].y2); break;
            case TRIANGLE: printf("Triangle [(%d,%d), (%d,%d), (%d,%d)]\n", objects[i].x1, objects[i].y1, objects[i].x2, objects[i].y2, objects[i].x3, objects[i].y3); break;
            case CIRCLE: printf("Circle [Center:(%d,%d), Radius:%d]\n", objects[i].x1, objects[i].y1, objects[i].radius); break;
        }
    }
}

void deleteObject() {
    listObjects();
    if (object_count == 0) return;

    int id;
    printf("Enter Object ID to delete: ");
    scanf("%d", &id);

    if (id < 0 || id >= object_count) {
        printf("Invalid ID!\n");
        return;
    }

    // Shift remaining items backward
    for (int i = id; i < object_count - 1; i++) {
        objects[i] = objects[i + 1];
    }
    object_count--;
    renderAll();
    printf("Object deleted successfully.\n");
}

void modifyObject() {
    listObjects();
    if (object_count == 0) return;

    int id;
    printf("Enter Object ID to modify: ");
    scanf("%d", &id);

    if (id < 0 || id >= object_count) {
        printf("Invalid ID!\n");
        return;
    }

    printf("\n--- Enter New Details for Object ID %d ---\n", id);
    inputObjectDetails(&objects[id]);
    renderAll();
    printf("Object updated successfully.\n");
}

int main() {
    int choice;
    clearCanvas();

    while (1) {
        printf("\n===== 2D GRAPHICS EDITOR =====\n");
        printf("1. Display Canvas\n");
        printf("2. Add Object\n");
        printf("3. Delete Object\n");
        printf("4. Modify Object\n");
        printf("5. List Objects\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: displayCanvas(); break;
            case 2: addObject(); break;
            case 3: deleteObject(); break;
            case 4: modifyObject(); break;
            case 5: listObjects(); break;
            case 6: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
