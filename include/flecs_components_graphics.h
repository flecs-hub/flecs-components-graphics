#ifndef FLECS_COMPONENTS_GRAPHICS_H
#define FLECS_COMPONENTS_GRAPHICS_H

#include <flecs-components-graphics/bake_config.h>

#ifdef __cplusplus
extern "C" {
#endif

ECS_STRUCT(ecs_vert2_t, {
    float x;
    float y;
});

ECS_STRUCT(ecs_vert3_t, {
    float x;
    float y;
    float z;
});

ECS_STRUCT(ecs_poly8_t, {
    ecs_vert2_t verts[8];
    int8_t verts_count;
});

ECS_STRUCT(ecs_rect_t, {
    int32_t width;
    int32_t height;
    int32_t x;
    int32_t y;
});

ECS_STRUCT(ecs_rgb_t, {
    float r;
    float g;
    float b;
});

ECS_STRUCT(ecs_rgba_t, {
    float r;
    float g;
    float b;
    float a;
});

typedef struct FlecsComponentsGraphics {
    ECS_DECLARE_COMPONENT(ecs_vert2_t);
    ECS_DECLARE_COMPONENT(ecs_vert3_t);
    ECS_DECLARE_COMPONENT(ecs_poly8_t);
    ECS_DECLARE_COMPONENT(ecs_rect_t);
    ECS_DECLARE_COMPONENT(ecs_rgb_t);
    ECS_DECLARE_COMPONENT(ecs_rgba_t);
} FlecsComponentsGraphics;

FLECS_COMPONENTS_GRAPHICS_EXPORT
void FlecsComponentsGraphicsImport(
    ecs_world_t *world);

#define FlecsComponentsGraphicsImportHandles(handles)\
    ECS_IMPORT_COMPONENT(handles, ecs_vert2_t);\
    ECS_IMPORT_COMPONENT(handles, ecs_vert3_t);\
    ECS_IMPORT_COMPONENT(handles, ecs_poly8_t);\
    ECS_IMPORT_COMPONENT(handles, ecs_rect_t);\
    ECS_IMPORT_COMPONENT(handles, ecs_rgb_t);\
    ECS_IMPORT_COMPONENT(handles, ecs_rgba_t);

#ifdef __cplusplus
}
#endif

#endif
