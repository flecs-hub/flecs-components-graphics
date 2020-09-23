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
    ECS_COMPONENT(world, EcsColor);
    ECS_COMPONENT(world, EcsSpecular);
    ECS_COMPONENT(world, EcsEmissive);

    ECS_EXPORT_COMPONENT(EcsCamera);
    ECS_EXPORT_COMPONENT(EcsDirectionalLight);
    ECS_EXPORT_COMPONENT(EcsColor);
    ECS_EXPORT_COMPONENT(EcsSpecular);
    ECS_EXPORT_COMPONENT(EcsEmissive);
}
