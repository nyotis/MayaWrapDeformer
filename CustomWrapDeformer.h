#ifndef CUSTOMWRAPDEFORMER_H
#define CUSTOMWRAPDEFORMER_H

//== INCLUDES ==================================================================

#include <maya/MDataBlock.h>
#include <maya/MDataHandle.h>
#include <maya/MGlobal.h>
#include <maya/MItGeometry.h>
#include <maya/MMatrix.h>
#include <maya/MPointArray.h>
#include <maya/MStatus.h>
#include <maya/MTypeId.h> 

#include <maya/MPxDeformerNode.h> 
#include <maya/MFnMesh.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MFnTypedAttribute.h>
//Each class in Maya has its own header file
//==============================================================================

typedef unsigned int uint;

//==============================================================================
//
//  CLASS CustomWrapDeformer
//
//==============================================================================

//== CLASS DEFINITION ==========================================================

class CustomWrapDeformer: public MPxDeformerNode {
public:
                  CustomWrapDeformer();
   virtual       ~CustomWrapDeformer();
   static void*   creator();    // whenever attribute needs to be re-evaluated
   static MStatus initialize(); // initialize executes whenever plug-in loads

      // brains of CustomWrapDeformer, it determines all output.
      // best practices in Maya suggest [1], [2] to implement the deform function and let MPxDeformerNode internally handle the compute function
      
<<<<<<< Updated upstream
        // [1] (david gould)
        // [2] MAYA API guide

   virtual MStatus deform(MDataBlock& data, 
                          MItGeometry& iterGeo, 
                          const MMatrix& localToWorldMatrix, 
                          uint geomIndex);
=======
   virtual MStatus deform( MDataBlock& data, 
                           MItGeometry& iterGeo, 
                           const MMatrix& localToWorldMatrix, 
                           uint geomIndex );
   // brains of CustomWrapDeformer, it determines all output.
   // best practices in Maya suggest [1], [2] to implement the deform function 
   // and let MPxDeformerNode internally handle the compute function
      
   // [1] (david gould)
   // [2] MAYA API guide
>>>>>>> Stashed changes
   
      // node attribute objects (all static allocated in CustomWrapDeformer.cpp) 
   static MObject input_poly;          // holds a reference to the wrap-base 
   static MObject initialized_data;    // pre-allocates data 
   static MObject distance_multiplier; // introduces the Shrink functionality
   static MObject distance_addition;   // introduces the Expand functionality
   static MObject global_scale;  
   
    // assign to each vertex of the wrap-base a distance and a direction 
    // to wrap-influence's closest vertex
   
      // length of UV vector
   static MObject distances; 
      // normalized vector holding XYZ directions 
      // towards influence's closest vertex 
   static MObject directions;  
   
   static MObject uv_coordinates; // UV coords at influence's closest vertex
   static MObject normals_xyz;    // XYZ normals vectors at influence's closest
                                  // UV vertex
  
      // Each node needs to be registered (it requires a unique identifier
      // within range 0x00000000-0x00000007 -> local use only) 
   static MTypeId id; 

};

//==============================================================================
#endif // CUSTOMWRAPDEFORMER_H defined
//==============================================================================
