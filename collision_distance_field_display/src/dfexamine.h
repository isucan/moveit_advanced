/*
 * Copyright (c) 2013, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/* Author: Acorn Pooley */
#ifndef COLLISION_DISTANCE_FIELD_DISPLAY__DFEXAMINE
#define COLLISION_DISTANCE_FIELD_DISPLAY__DFEXAMINE

#include <Eigen/Geometry>


namespace Ogre
{
class SceneNode;
}

namespace collision_detection
{
class StaticDistanceField;
}

namespace moveit_rviz_plugin
{
class ShapesDisplay;
}


class moveit_rviz_plugin::CollisionDistanceFieldDisplay::DFExamine
{
public:
  DFExamine(
        const char *descrip,
        const char *link_name,
        Ogre::SceneNode* parent,
        const Eigen::Affine3d& transform_to_node,
        const collision_detection::StaticDistanceField *df,
        int idx,
        const Eigen::Vector4f& color,
        const Eigen::Vector4f& near_color,
        double size);

private:
  ShapesDisplay spheres_;
};

#endif
