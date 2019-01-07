#ifndef REFLECS_COMPONENTS_GRAPHICS_H
#define REFLECS_COMPONENTS_GRAPHICS_H

#include "bake_config.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct EcsRect {
    int32_t width;
    int32_t height;
    int32_t x;
    int32_t y;
} EcsRect;

typedef struct EcsColor {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
} EcsColor;

typedef struct EcsCanvas2D {
    EcsRect window;
    EcsRect viewport;
    const char *title;
    EcsColor background_color;
} EcsCanvas2D;

typedef struct EcsComponentsGraphicsHandles {
    EcsHandle Color;
    EcsHandle Canvas2D;
} EcsComponentsGraphicsHandles;

void EcsComponentsGraphics(
    EcsWorld *world,
    int flags,
    void *handles_out);

#define EcsComponentsGraphics_DeclareHandles(handles)\
    EcsDeclareHandle(handles, Color);\
    EcsDeclareHandle(handles, Canvas2D);

#ifdef __cplusplus
}
#endif

#endif
