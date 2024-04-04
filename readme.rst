Soft-body simulation using Extended Position Based Dynamics
===========================================================

This repo is to store and not lose, by far the coolest and my most loved project, implmenting soft body simulations using Extended Position Based Dynamics.

The project comprised of 2 parts:

Volumetric Remesher
-------------------

[Main code for the remesher can be found in the file `MOD_weld.cc<https://github.com/arcticblazer/blender/blob/main/source/blender/modifiers/intern/MOD_weld.cc>`__ ]

Blender represents and stores objects as 2D surface meshes. However volumetric data about the object is required to apply the simulation algorithm. 

Thus a volumetric remesher was implemented to convert the 2D surface meshes to 3D volumetric tetrahedral meshes. 

This was done by implementing Delaunay Triangulation method extended to 3D

.. figure:: https://archive.blender.org/wiki/2024/w/images/1/16/Suzanne_tetrahedralized.jpg
   :width: 600
   :figwidth: 600
   :align: center

   Blender bunny tetrahedralized and represented with individual tetrahedrons scaled down to a factor of 0.8

Extended Position Based Dynamics (XPBD) Framework
-------------------------------------------------

[Main code for the simulation framework can be found in `softbody.cc<https://github.com/arcticblazer/blender/blob/main/source/blender/blenkernel/intern/softbody.cc>`__ and `xpbd.cc<https://github.com/arcticblazer/blender/blob/main/source/blender/simulation/intern/xpbd.cc>`__ ]

Taking the remeshed object as input, a framework for Extended Position Based Dynamics (XPBD) simulation was implemented. [`Link to the research paper<https://mmacklin.com/xpbd.pdf>`__]

XPBD works by enforcing multiple constraint functions, all of which were decoupled from one another. 

The framework allows for extendability in the form of ability to implement just the constraint function.

In addition, distance and volume conservation constraint functions were also applied.

.. figure:: https://archive.blender.org/wiki/2024/w/images/0/04/Screencast-12-08-22-092938-am-ist_KrOxvmSo.gif
   :alt: A tetrahetraized cube bouncing on ground with stiffness coefficient = 0.8
   :width: 600

   A tetrahetraized cube bouncing on ground with stiffness coefficient = 0.8


-------

More details about it can be found in my `Final Report <https://archive.blender.org/wiki/2024/wiki/User:AarnavDhanuka/GSoC2022/FinalReport.html>`__
