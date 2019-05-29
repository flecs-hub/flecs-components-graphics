#ifndef FLECS_COMPONENTS_GRAPHICS_H
#define FLECS_COMPONENTS_GRAPHICS_H

#include <flecs-components-graphics/bake_config.h>

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

typedef EcsColor EcsLineColor;

typedef uint16_t EcsLineWidth;

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

typedef struct FlecsComponentsGraphics {
    ECS_DECLARE_COMPONENT(EcsColor);
    ECS_DECLARE_COMPONENT(EcsLineColor);
    ECS_DECLARE_COMPONENT(EcsLineWidth);
    ECS_DECLARE_COMPONENT(EcsCanvas2D);
    ECS_DECLARE_COMPONENT(EcsCamera2D);
} FlecsComponentsGraphics;

void FlecsComponentsGraphicsImport(
    ecs_world_t *world,
    int flags);

#define FlecsComponentsGraphicsImportHandles(handles)\
    ECS_IMPORT_COMPONENT(handles, EcsColor);\
    ECS_IMPORT_COMPONENT(handles, EcsLineColor);\
    ECS_IMPORT_COMPONENT(handles, EcsLineWidth);\
    ECS_IMPORT_COMPONENT(handles, EcsCanvas2D);\
    ECS_IMPORT_COMPONENT(handles, EcsCamera2D);

#ifdef __cplusplus
}
#endif

#endif
