/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2013, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Willow Garage nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

/* Author: Acorn Pooley */

#ifndef MOVEIT_COLLISION_DETECTION_DISTANCE_FIELD__BIT_ARRAY
#define MOVEIT_COLLISION_DETECTION_DISTANCE_FIELD__BIT_ARRAY

#include <stdint.h>
#include <string>

namespace collision_detection
{

// very simple bit array with no bounds checking.
class BitArray
{
public:
  BitArray();
  ~BitArray();

  // Set how many bits there should be.
  // All bits are set to <value>.
  void reset(int nbits, bool value = false);

  // set a bit
  void setBit(int bit_index, bool value = true);

  // clear a bit
  void clrBit(int bit_index);

  // get the value of a bit
  bool getBit(int bit_index) const;

private:
  uint32_t *bits_;
};

}

inline collision_detection::BitArray::BitArray()
  : bits_(NULL)
{
}

inline collision_detection::BitArray::~BitArray()
{
  delete[] bits_;
}

// Set how many bits there should be.
// All bits are set to <value>.
inline void collision_detection::BitArray::reset(int nbits, bool value)
{
  delete[] bits_;
  bits_ = NULL;
  if (nbits)
  {
    int nwords = (nbits + 0x1f) >> 5;
    bits_ = new uint32_t[nwords];
    std::memset(bits_, value ? 0xff : 0x00, sizeof(uint32_t) * nwords);
  }
}

inline void collision_detection::BitArray::setBit(int bit_index, bool value)
{
  int idx = bit_index >> 5;
  uint32_t bit = 1 << (bit_index & 0x1f);
  if (value)
    bits_[idx] |= bit;
  else
    bits_[idx] &= ~bit;
}

inline void collision_detection::BitArray::clrBit(int bit_index)
{
  setBit(bit_index, false);
}

inline bool collision_detection::BitArray::getBit(int bit_index) const
{
  int idx = bit_index >> 5;
  uint32_t bit = 1 << (bit_index & 0x1f);
  return bits_[idx] & bit;
}

#endif
