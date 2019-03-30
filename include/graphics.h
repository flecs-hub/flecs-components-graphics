#ifndef FLECS_COMPONENTS_GRAPHICS_H
#define FLECS_COMPONENTS_GRAPHICS_H

#include "bake_config.h"

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
    float r;
    float g;
    float b;
    float a;
} EcsColor;

typedef struct EcsCanvas2D {
    EcsRect window;
    EcsRect window_actual;
    EcsRect viewport;
    const char *title;
    EcsColor background_color;
} EcsCanvas2D;

typedef struct EcsCamera2D {
    EcsVec2 position;
    EcsVec2 zoom;
    bool enabled;
} EcsCamera2D;

typedef struct EcsComponentsGraphicsHandles {
    ECS_DECLARE_COMPONENT(EcsColor);
    ECS_DECLARE_COMPONENT(EcsCanvas2D);
    ECS_DECLARE_COMPONENT(EcsCamera2D);
} EcsComponentsGraphicsHandles;

void EcsComponentsGraphics(
    ecs_world_t *world,
    int flags,
    void *handles_out);

#define EcsComponentsGraphics_ImportHandles(handles)\
    ECS_IMPORT_COMPONENT(handles, EcsColor);\
    ECS_IMPORT_COMPONENT(handles, EcsCanvas2D);\
    ECS_IMPORT_COMPONENT(handles, EcsCamera2D);

#ifdef __cplusplus
}
#endif

#endif
