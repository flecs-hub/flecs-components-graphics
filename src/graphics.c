#include <include/graphics.h>
#include <string.h>

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
    ECS_SET_COMPONENT(handles, EcsColor);

    if (do_2d) {
        ECS_COMPONENT(world, EcsCanvas2D);
        ECS_SET_COMPONENT(handles, EcsCanvas2D);

        ECS_COMPONENT(world, EcsCamera2D);
        ECS_SET_COMPONENT(handles, EcsCamera2D);
    }
}
