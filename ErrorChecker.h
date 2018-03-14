<<<<<<< Updated upstream
/* 
   http://www.vfxplatform.com/
   LLVM support
*/
=======
// http://www.vfxplatform.com/
// hope for CLANG support anytime soon 

#ifndef _ERRORCHECKER_H_
#define _ERRORCHECKER_H_
 
// includes, maya
#include <maya/MStatus.h>
 
class ErrorChecker {
public:
 
   static void checkErrorGL(const char* file = "-" , const int line = -1);
   static void checkFrameBufferStatus();
      // this version prints an error and terminates the program, 
      // no exception is thrown.
   inline static void condition( bool val, const char* file, const int line );

   inline static void mayaStatus( const MStatus& status, const char* file, const int line );

};
 
// includes, system
#include <iostream>
 
//   this version prints an error and terminates the program, no exception is thrown.
/* static */ 
inline void ErrorChecker::condition( bool val, const char* file, const int line ) {
   
   if ( ! val) {
      std::cerr << "Condition failed: " << file << " in line " << line << std::endl;
 
      // exit(EXIT_FAILURE);
   }
}
 
/* static */ 
inline void ErrorChecker::mayaStatus( const MStatus& status, const char* file, const int line ) {
   
   if ( MS::kSuccess != status) { 
      std::cerr << "Maya status error: " << file << " in line " << line << std::endl;
      // exit(EXIT_FAILURE);
   }
}
 
#define CHECK_ERROR_GL() ErrorChecker::checkErrorGL( __FILE__, __LINE__)
#define CONDITION( val) ErrorChecker::condition( val, __FILE__, __LINE__)
#define CHECK_MAYA( val) ErrorChecker::mayaStatus( val, __FILE__, __LINE__)
#endif // _ERRORCHECKER_H_
>>>>>>> Stashed changes
