#include <include/graphics.h>
#include <string.h>

void EcsAddContainerToCanvas(EcsRows *rows) {
    for (void *row = rows->first; row < rows->last; row = ecs_next(rows, row)) {
        EcsEntity e = ecs_entity(rows, row, 0);
        ecs_add(rows->world, e, EcsRoot_h);
        ecs_add(rows->world, e, EcsContainer_h);
    }
}

void EcsComponentsGraphics(
    EcsWorld *world,
    int flags,
    void *handles_out)
{
    EcsComponentsGraphicsHandles *handles = handles_out;
    bool do_2d = !flags || flags & ECS_2D;
    // bool do_3d = !flags || flags & ECS_3D;

    memset(handles, 0, sizeof(EcsComponentsGraphicsHandles));

    ECS_COMPONENT(world, EcsColor);
    handles->Color = EcsColor_h;

    if (do_2d) {
        ECS_COMPONENT(world, EcsCanvas2D);
        handles->Canvas2D = EcsCanvas2D_h;

        ECS_COMPONENT(world, EcsCamera2D);
        handles->Camera2D = EcsCamera2D_h;
    }

    /* System that automatically adds EcsRoot and EcsContainer to canvas */
    ECS_SYSTEM(world, EcsAddContainerToCanvas, EcsOnAdd, EcsCanvas2D);
    ecs_add(world, EcsAddContainerToCanvas_h, EcsHidden_h);
}
