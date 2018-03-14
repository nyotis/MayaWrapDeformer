/****************************************************************************
 *  Wrap Deformer -*- C++ -*- .cpp
 * 
<<<<<<< Updated upstream
 *  Created by Nikos Yotis on June 2011 for Prime Focus.
=======
 *  Created by Nikolaos Giotis, June 2011 for Prime Focus World VFX.
>>>>>>> Stashed changes
 *  Copyright 2011 __Prime Focus__. All rights reserved.
 *
 */

 /*
[ Description ]

   [[ Primer ]]

   - Implement one Dependency Graph Node as a base for PfWrapDeformer 
     (PfWrapDeformer is a subset of this dependency graph node). 
     The user feeds a target mesh and controls the paintable weighted values 
     interactively, more info see the built-in MGlobal::executeCommand.     
 
   - The data comes in the nodes through the input plugs (instantiations of 
     the nodes attributes) and goes out through the output plugs. At no time 
     should a node require any additional external data beyond what is 
     available through its plugs. 

   - The resolution of the input mesh is not modified, only the positions of 
     the points is changed. MPxDeformerNode handles this. 

   [[ Remarks ]]
   

   - Use paintable weights so that the user can paint the weights on the 
     PFWrapdeformer node. this way the transitional influence has a smooth 
     fall off. once this is set, use MEnu Modify -> Paint Attributes Tool  
   - since Maya API separates data from functions (non O/O design), prefer 
     functors (aka function objects) over pointers to functions

   [[ Example of use ]]



   [[ Revision History ]]
 
 
   [[ Extension ]]

******************************************************************************/

//== INCLUDES =================================================================

#include "./PfWrapDeformer.h"

#include <cstring>
#include <iostream>
#include <cmath>

#include <maya/MString.h> 
#include <maya/MFnPlugin.h>

#include <maya/MPxNode.h> 
#include <maya/MTypeId.h> 
#include <maya/MPlug.h>

#include <maya/MArrayDataHandle.h>   
  // MArrayDataHandle is a smart pointer into a data block

//=============================================================================
//
//  CLASS PfWrapDeformer - IMPLEMENTATION
//
//=============================================================================

//************************************** Create a DeformerNode ****************

   // In the constructor of MPxDeformerNode _DO NOT_ call any of the MPxNode 
   // member functions. keep MPxDeformerNode's constructor minimal and assign 
   // most of the initialization work to MPxNode's postConstructor       

PfWrapDeformer:: PfWrapDeformer() {}
PfWrapDeformer::~PfWrapDeformer() {}

   // make instances of this node
void* PfWrapDeformer::creator() {
   return new PfWrapDeformer();
}

// TBD
