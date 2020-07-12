#include <flecs_components_graphics.h>
#include <string.h>

void FlecsComponentsGraphicsImport(
    ecs_world_t *world)
{
    ECS_MODULE(world, FlecsComponentsGraphics);

    ecs_set_name_prefix(world, "ecs");

    ECS_IMPORT(world, FlecsMeta);

    ECS_META(world, ecs_vert2_t);
    ECS_META(world, ecs_vert3_t);
    ECS_META(world, ecs_poly8_t);
    ECS_META(world, ecs_rect_t);
    ECS_META(world, ecs_rgb_t);
    ECS_META(world, ecs_rgba_t);

    ECS_EXPORT_COMPONENT(ecs_vert2_t);
    ECS_EXPORT_COMPONENT(ecs_vert3_t);
    ECS_EXPORT_COMPONENT(ecs_rect_t);
    ECS_EXPORT_COMPONENT(ecs_rgb_t);
    ECS_EXPORT_COMPONENT(ecs_rgba_t);
}
