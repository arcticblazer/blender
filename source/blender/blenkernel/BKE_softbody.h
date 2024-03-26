/* SPDX-License-Identifier: GPL-2.0-or-later
 * Copyright Blender Foundation. All rights reserved. */
#pragma once

/** \file
 * \ingroup bke
 */

#ifdef __cplusplus
extern "C" {
#endif

struct Depsgraph;
struct Object;
struct Scene;
struct SoftBody;

typedef struct BodyPoint{
  float x[3], v[3], a[3];
  float x_prev[3], v_prev[3], a_prev[3];
  float x_ini[3], v_ini[3], a_ini[3];

  float mass_inv; // 1/mass
} BodyPoint;

typedef struct BodyEdge{
  int u, v;
} BodyEdge;

typedef struct BodyTet{
  int verts[4];
  float initial_volume;
} BodyTet;

struct SoftBody *init_softbody(void);

void free_softbody_intern(struct SoftBody *sb);

void sbFree(struct Object *ob);

float get_tet_volume(BodyPoint *bpoint, BodyTet *curr_tet);

void mesh_to_softbody(struct Object *ob, float (*vertexCos)[3], int numVerts);

void sb_store_last_frame(struct Depsgraph *depsgraph, struct Object *object, float framenr);

void softbody_to_object(struct Object *ob, float (*vertexCos)[3], int numVerts);

void sbObjectStep(struct Depsgraph *depsgraph, struct Scene *scene, struct Object *ob, float cfra, float (*vertexCos)[3], int numVerts);


#ifdef __cplusplus
}
#endif
