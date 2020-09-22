#include <flecs_components_graphics.h>
#include <string.h>

void FlecsComponentsGraphicsImport(
    ecs_world_t *world)
{
    ECS_MODULE(world, FlecsComponentsGraphics);

    ecs_set_name_prefix(world, "ecs");

    ECS_IMPORT(world, FlecsMeta);

    ECS_COMPONENT(world, EcsCamera);
    ECS_COMPONENT(world, EcsDirectionalLight);

    ECS_EXPORT_COMPONENT(EcsCamera);
    ECS_EXPORT_COMPONENT(EcsDirectionalLight);
}
