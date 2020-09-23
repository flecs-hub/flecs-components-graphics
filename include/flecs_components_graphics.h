#ifndef FLECS_COMPONENTS_GRAPHICS_H
#define FLECS_COMPONENTS_GRAPHICS_H

#include <flecs-components-graphics/bake_config.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ecs_rgb_t {
    float r;
    float g;
    float b;
} ecs_rgb_t;

typedef struct ecs_rgba_t {
    float r;
    float g;
    float b;
    float a;
} ecs_rgba_t;

typedef struct EcsCamera {
    vec3 position;
    vec3 lookat;
    vec3 up;
    float fov;
} EcsCamera;

typedef struct EcsDirectionalLight {
    vec3 position;
    vec3 direction;
    vec3 color;
} EcsDirectionalLight;

typedef struct EcsColor {
    ecs_rgba_t value;
} EcsColor;

typedef struct EcsSpecular {
    float specular_power;
    float shininess;
} EcsSpecular;

typedef struct EcsEmissive {
    float value;
} EcsEmissive;

typedef struct FlecsComponentsGraphics {
    ECS_DECLARE_COMPONENT(EcsCamera);
    ECS_DECLARE_COMPONENT(EcsDirectionalLight);
    ECS_DECLARE_COMPONENT(EcsColor);
    ECS_DECLARE_COMPONENT(EcsSpecular);
    ECS_DECLARE_COMPONENT(EcsEmissive);
} FlecsComponentsGraphics;

FLECS_COMPONENTS_GRAPHICS_EXPORT
void FlecsComponentsGraphicsImport(
    ecs_world_t *world);

#define FlecsComponentsGraphicsImportHandles(handles)\
    ECS_IMPORT_COMPONENT(handles, EcsCamera);\
    ECS_IMPORT_COMPONENT(handles, EcsDirectionalLight);\
    ECS_IMPORT_COMPONENT(handles, EcsColor);\
    ECS_IMPORT_COMPONENT(handles, EcsSpecular);\
    ECS_IMPORT_COMPONENT(handles, EcsEmissive);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

namespace flecs {
namespace components {

class graphics : FlecsComponentsGraphics {
public:
    struct rgb_t : ecs_rgb_t {
        operator float*() {
            return reinterpret_cast<float*>(this);
        }
    };

    struct rgba_t : ecs_rgba_t {
        operator float*() {
            return reinterpret_cast<float*>(this);
        }
    };

    struct Camera : EcsCamera {
        Camera() {
            this->set_position(0, 0, 0);
            this->set_lookat(0, 1, 1);
            this->set_up(0, -1, 0);
            this->set_fov(30);
        }

        void set_position(float x, float y, float z) {
            this->position[0] = x;
            this->position[1] = y;
            this->position[2] = z;
        }

        void set_lookat(float x, float y, float z) {
            this->lookat[0] = x;
            this->lookat[1] = y;
            this->lookat[2] = z;
        }

        void set_up(float x, float y, float z) {
            this->up[0] = x;
            this->up[1] = y;
            this->up[2] = z;
        }

        void set_fov(float value) {
            this->fov = value;
        }
    };

    struct DirectionalLight : EcsDirectionalLight {
        DirectionalLight() {
            this->set_position(0, 0, 0);
            this->set_direction(0, 1, 1);
            this->set_color(1, 1, 1);
        }

        void set_position(float x, float y, float z) {
            this->position[0] = x;
            this->position[1] = y;
            this->position[2] = z;
        }

        void set_direction(float x, float y, float z) {
            this->direction[0] = x;
            this->direction[1] = y;
            this->direction[2] = z;
        }

        void set_color(float r, float g, float b) {
            this->color[0] = r;
            this->color[1] = g;
            this->color[2] = b;
        }
    };

    using Color = EcsColor;
    using Specular = EcsSpecular;
    using Emissive = EcsEmissive;

    graphics(flecs::world& ecs) {
        FlecsComponentsGraphicsImport(ecs.c_ptr());

        ecs.module<flecs::components::graphics>();
        ecs.pod_component<Camera>("flecs::components::graphics::Camera");
        ecs.pod_component<DirectionalLight>("flecs::components::graphics::DirectionalLight");
        ecs.pod_component<Color>("flecs::components::graphics::Color");
        ecs.pod_component<Specular>("flecs::components::graphics::Specular");
        ecs.pod_component<Emissive>("flecs::components::graphics::Emissive");
    }
};

}
}

#endif

#endif
