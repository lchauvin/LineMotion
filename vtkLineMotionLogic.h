/*==========================================================================

  Portions (c) Copyright 2008 Brigham and Women's Hospital (BWH) All Rights Reserved.

  See Doc/copyright/copyright.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Program:   3D Slicer
  Module:    $HeadURL: $
  Date:      $Date: $
  Version:   $Revision: $

==========================================================================*/

// .NAME vtkLineMotionLogic - slicer logic class for Locator module 
// .SECTION Description
// This class manages the logic associated with tracking device for
// IGT. 


#ifndef __vtkLineMotionLogic_h
#define __vtkLineMotionLogic_h

#include "vtkLineMotionWin32Header.h"

#include "vtkSlicerBaseLogic.h"
#include "vtkSlicerModuleLogic.h"
#include "vtkSlicerApplication.h"
#include "vtkCallbackCommand.h"

#include "vtkMRMLSliceNode.h"

class vtkIGTLConnector;
class vtkMRMLFiducialListNode;
class vtkSlicerApplicationGUI;
class vtkActorCollection;

class VTK_LineMotion_EXPORT vtkLineMotionLogic : public vtkSlicerModuleLogic 
{
 public:
  //BTX
  enum {  // Events
    //LocatorUpdateEvent      = 50000,
    StatusUpdateEvent       = 50001,
  };
  //ETX

 public:
  
  static vtkLineMotionLogic *New();
  
  vtkTypeRevisionMacro(vtkLineMotionLogic,vtkObject);
  void PrintSelf(ostream&, vtkIndent);

  void RefreshLines(vtkMRMLFiducialListNode* , vtkActorCollection* , vtkCollection*, vtkSlicerApplicationGUI*);

 protected:
  
  vtkLineMotionLogic();
  ~vtkLineMotionLogic();

  void operator=(const vtkLineMotionLogic&);
  vtkLineMotionLogic(const vtkLineMotionLogic&);

  static void DataCallback(vtkObject*, unsigned long, void *, void *);
  void UpdateAll();

  vtkCallbackCommand *DataCallbackCommand;

 private:

};

#endif


  
