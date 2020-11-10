/*
 * simplePathFollow.h
 *
 * Code generation for model "simplePathFollow".
 *
 * Model version              : 1.40
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Tue Oct 20 03:39:33 2020
 *
 * Target selection: VeriStand.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_simplePathFollow_h_
#define RTW_HEADER_simplePathFollow_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef simplePathFollow_COMMON_INCLUDES_
# define simplePathFollow_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* simplePathFollow_COMMON_INCLUDES_ */

#include "simplePathFollow_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetCtrlRateMdlRefTiming
# define rtmGetCtrlRateMdlRefTiming(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTiming
# define rtmSetCtrlRateMdlRefTiming(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateMdlRefTimingPtr
# define rtmGetCtrlRateMdlRefTimingPtr(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTimingPtr
# define rtmSetCtrlRateMdlRefTimingPtr(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateNumTicksToNextHit
# define rtmGetCtrlRateNumTicksToNextHit(rtm) ()
#endif

#ifndef rtmSetCtrlRateNumTicksToNextHit
# define rtmSetCtrlRateNumTicksToNextHit(rtm, val) ()
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ()
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ()
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ()
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ()
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
# define rtmGetSelf(rtm)               ()
#endif

#ifndef rtmSetSelf
# define rtmSetSelf(rtm, val)          ()
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGettimingBridge
# define rtmGettimingBridge(rtm)       ()
#endif

#ifndef rtmSettimingBridge
# define rtmSettimingBridge(rtm, val)  ()
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) 0
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define simplePathFollow_rtModel       RT_MODEL_simplePathFollow_T

/* Block signals (default storage) */
typedef struct {
  real_T assign_temp_coefs[936];
  real_T vehXY[705];
  real_T vehLoIn1[7];                  /* '<Root>/vehLo In1' */
  real_T NProdOut;                     /* '<S66>/NProd Out' */
  real_T Saturation;                   /* '<S78>/Saturation' */
  real_T IProdOut;                     /* '<S46>/IProd Out' */
  real_T preOffset;                    /* '<Root>/MATLAB Function' */
  uint8_T missionFlagIn2;              /* '<Root>/missionFlag In2' */
} B_simplePathFollow_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S57>/Integrator' */
  real_T Filter_DSTATE;                /* '<S39>/Filter' */
  real_T vehLoIn1_DWORK1[7];           /* '<Root>/vehLo In1' */
  real_T missionFlagIn2_DWORK1;        /* '<Root>/missionFlag In2' */
  real_T steerAngleOut1_DWORK1;        /* '<Root>/steerAngle Out1' */
  real_T offsetOut2_DWORK1;            /* '<Root>/offset Out2' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  uint8_T vehLoIn1_DWORK2[17];         /* '<Root>/vehLo In1' */
  uint8_T missionFlagIn2_DWORK2[17];   /* '<Root>/missionFlag In2' */
  uint8_T steerAngleOut1_DWORK2[17];   /* '<Root>/steerAngle Out1' */
  uint8_T offsetOut2_DWORK2[17];       /* '<Root>/offset Out2' */
} DW_simplePathFollow_T;

/* Backward compatible GRT Identifiers */
#define rtB                            simplePathFollow_B
#define BlockIO                        B_simplePathFollow_T
#define rtP                            simplePathFollow_P
#define Parameters                     P_simplePathFollow_T
#define rtDWork                        simplePathFollow_DW
#define D_Work                         DW_simplePathFollow_T

/* Parameters (default storage) */
struct P_simplePathFollow_T_ {
  real_T distXYN2S[470];               /* Variable: distXYN2S
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T distXYS2N[470];               /* Variable: distXYS2N
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T oriPoint[2];                  /* Variable: oriPoint
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T PIDController_InitialConditionF;/* Mask Parameter: PIDController_InitialConditionF
                                          * Referenced by: '<S39>/Filter'
                                          */
  real_T PIDController_InitialConditio_e;/* Mask Parameter: PIDController_InitialConditio_e
                                          * Referenced by: '<S57>/Integrator'
                                          */
  real_T PIDController_LowerSaturationLi;/* Mask Parameter: PIDController_LowerSaturationLi
                                          * Referenced by: '<S78>/Saturation'
                                          */
  real_T PIDController_UpperSaturationLi;/* Mask Parameter: PIDController_UpperSaturationLi
                                          * Referenced by: '<S78>/Saturation'
                                          */
  real_T Constant7_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Constant3_Value;              /* Expression: 4
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant6_Value[3];           /* Expression: [-15 0 0]
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Constant1_Value[3];           /* Expression: [30.517272880310000 1.143494394616000e+02 15.355142769000000]
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T vehLoIn1_P1;                  /* Expression: width
                                        * Referenced by: '<Root>/vehLo In1'
                                        */
  real_T vehLoIn1_P2;                  /* Expression: dtype
                                        * Referenced by: '<Root>/vehLo In1'
                                        */
  real_T vehLoIn1_P3;                  /* Expression: portnum
                                        * Referenced by: '<Root>/vehLo In1'
                                        */
  real_T vehLoIn1_P4;                  /* Expression: stime
                                        * Referenced by: '<Root>/vehLo In1'
                                        */
  real_T vehLoIn1_P5;                  /* Expression: stype
                                        * Referenced by: '<Root>/vehLo In1'
                                        */
  real_T vehLoIn1_P6;                  /* Expression: btype
                                        * Referenced by: '<Root>/vehLo In1'
                                        */
  real_T missionFlagIn2_P1;            /* Expression: width
                                        * Referenced by: '<Root>/missionFlag In2'
                                        */
  real_T missionFlagIn2_P2;            /* Expression: dtype
                                        * Referenced by: '<Root>/missionFlag In2'
                                        */
  real_T missionFlagIn2_P3;            /* Expression: portnum
                                        * Referenced by: '<Root>/missionFlag In2'
                                        */
  real_T missionFlagIn2_P4;            /* Expression: stime
                                        * Referenced by: '<Root>/missionFlag In2'
                                        */
  real_T missionFlagIn2_P5;            /* Expression: stype
                                        * Referenced by: '<Root>/missionFlag In2'
                                        */
  real_T missionFlagIn2_P6;            /* Expression: btype
                                        * Referenced by: '<Root>/missionFlag In2'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S57>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S39>/Filter'
                                        */
  real_T Constant5_Value;              /* Expression: 100
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T steerAngleOut1_P1;            /* Expression: width
                                        * Referenced by: '<Root>/steerAngle Out1'
                                        */
  real_T steerAngleOut1_P2;            /* Expression: dtype
                                        * Referenced by: '<Root>/steerAngle Out1'
                                        */
  real_T steerAngleOut1_P3;            /* Expression: portnum
                                        * Referenced by: '<Root>/steerAngle Out1'
                                        */
  real_T steerAngleOut1_P4;            /* Expression: stime
                                        * Referenced by: '<Root>/steerAngle Out1'
                                        */
  real_T steerAngleOut1_P5;            /* Expression: stype
                                        * Referenced by: '<Root>/steerAngle Out1'
                                        */
  real_T steerAngleOut1_P6;            /* Expression: btype
                                        * Referenced by: '<Root>/steerAngle Out1'
                                        */
  real_T offsetOut2_P1;                /* Expression: width
                                        * Referenced by: '<Root>/offset Out2'
                                        */
  real_T offsetOut2_P2;                /* Expression: dtype
                                        * Referenced by: '<Root>/offset Out2'
                                        */
  real_T offsetOut2_P3;                /* Expression: portnum
                                        * Referenced by: '<Root>/offset Out2'
                                        */
  real_T offsetOut2_P4;                /* Expression: stime
                                        * Referenced by: '<Root>/offset Out2'
                                        */
  real_T offsetOut2_P5;                /* Expression: stype
                                        * Referenced by: '<Root>/offset Out2'
                                        */
  real_T offsetOut2_P6;                /* Expression: btype
                                        * Referenced by: '<Root>/offset Out2'
                                        */
  uint8_T ManualSwitch_CurrentSetting; /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  uint8_T ManualSwitch3_CurrentSetting;/* Computed Parameter: ManualSwitch3_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch3'
                                        */
  uint8_T ManualSwitch2_CurrentSetting;/* Computed Parameter: ManualSwitch2_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch2'
                                        */
  uint8_T ManualSwitch1_CurrentSetting;/* Computed Parameter: ManualSwitch1_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_simplePathFollow_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;
  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  void *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[1];
    time_T offsetTimesArray[1];
    int_T sampleTimeTaskIDArray[1];
    int_T sampleHitArray[1];
    int_T perTaskSampleHitsArray[1];
    time_T tArray[1];
  } Timing;
};

/* Block parameters (default storage) */
extern P_simplePathFollow_T simplePathFollow_P;

/* Block signals (default storage) */
extern B_simplePathFollow_T simplePathFollow_B;

/* Block states (default storage) */
extern DW_simplePathFollow_T simplePathFollow_DW;

/*====================*
 * External functions *
 *====================*/
extern simplePathFollow_rtModel *simplePathFollow(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_simplePathFollow_T *const simplePathFollow_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'simplePathFollow'
 * '<S1>'   : 'simplePathFollow/MATLAB Function'
 * '<S2>'   : 'simplePathFollow/PID Controller'
 * '<S3>'   : 'simplePathFollow/PID Controller/Anti-windup'
 * '<S4>'   : 'simplePathFollow/PID Controller/D Gain'
 * '<S5>'   : 'simplePathFollow/PID Controller/Filter'
 * '<S6>'   : 'simplePathFollow/PID Controller/Filter ICs'
 * '<S7>'   : 'simplePathFollow/PID Controller/I Gain'
 * '<S8>'   : 'simplePathFollow/PID Controller/Ideal P Gain'
 * '<S9>'   : 'simplePathFollow/PID Controller/Ideal P Gain Fdbk'
 * '<S10>'  : 'simplePathFollow/PID Controller/Integrator'
 * '<S11>'  : 'simplePathFollow/PID Controller/Integrator ICs'
 * '<S12>'  : 'simplePathFollow/PID Controller/N Copy'
 * '<S13>'  : 'simplePathFollow/PID Controller/N Gain'
 * '<S14>'  : 'simplePathFollow/PID Controller/P Copy'
 * '<S15>'  : 'simplePathFollow/PID Controller/Parallel P Gain'
 * '<S16>'  : 'simplePathFollow/PID Controller/Reset Signal'
 * '<S17>'  : 'simplePathFollow/PID Controller/Saturation'
 * '<S18>'  : 'simplePathFollow/PID Controller/Saturation Fdbk'
 * '<S19>'  : 'simplePathFollow/PID Controller/Sum'
 * '<S20>'  : 'simplePathFollow/PID Controller/Sum Fdbk'
 * '<S21>'  : 'simplePathFollow/PID Controller/Tracking Mode'
 * '<S22>'  : 'simplePathFollow/PID Controller/Tracking Mode Sum'
 * '<S23>'  : 'simplePathFollow/PID Controller/postSat Signal'
 * '<S24>'  : 'simplePathFollow/PID Controller/preSat Signal'
 * '<S25>'  : 'simplePathFollow/PID Controller/Anti-windup/Back Calculation'
 * '<S26>'  : 'simplePathFollow/PID Controller/Anti-windup/Cont. Clamping Ideal'
 * '<S27>'  : 'simplePathFollow/PID Controller/Anti-windup/Cont. Clamping Parallel'
 * '<S28>'  : 'simplePathFollow/PID Controller/Anti-windup/Disabled'
 * '<S29>'  : 'simplePathFollow/PID Controller/Anti-windup/Disc. Clamping Ideal'
 * '<S30>'  : 'simplePathFollow/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S31>'  : 'simplePathFollow/PID Controller/Anti-windup/Passthrough'
 * '<S32>'  : 'simplePathFollow/PID Controller/D Gain/Disabled'
 * '<S33>'  : 'simplePathFollow/PID Controller/D Gain/External Parameters'
 * '<S34>'  : 'simplePathFollow/PID Controller/D Gain/Internal Parameters'
 * '<S35>'  : 'simplePathFollow/PID Controller/Filter/Cont. Filter'
 * '<S36>'  : 'simplePathFollow/PID Controller/Filter/Differentiator'
 * '<S37>'  : 'simplePathFollow/PID Controller/Filter/Disabled'
 * '<S38>'  : 'simplePathFollow/PID Controller/Filter/Disc. Backward Euler Filter'
 * '<S39>'  : 'simplePathFollow/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S40>'  : 'simplePathFollow/PID Controller/Filter/Disc. Trapezoidal Filter'
 * '<S41>'  : 'simplePathFollow/PID Controller/Filter ICs/Disabled'
 * '<S42>'  : 'simplePathFollow/PID Controller/Filter ICs/External IC'
 * '<S43>'  : 'simplePathFollow/PID Controller/Filter ICs/Internal IC - Differentiator'
 * '<S44>'  : 'simplePathFollow/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S45>'  : 'simplePathFollow/PID Controller/I Gain/Disabled'
 * '<S46>'  : 'simplePathFollow/PID Controller/I Gain/External Parameters'
 * '<S47>'  : 'simplePathFollow/PID Controller/I Gain/Internal Parameters'
 * '<S48>'  : 'simplePathFollow/PID Controller/Ideal P Gain/External Parameters'
 * '<S49>'  : 'simplePathFollow/PID Controller/Ideal P Gain/Internal Parameters'
 * '<S50>'  : 'simplePathFollow/PID Controller/Ideal P Gain/Passthrough'
 * '<S51>'  : 'simplePathFollow/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S52>'  : 'simplePathFollow/PID Controller/Ideal P Gain Fdbk/External Parameters'
 * '<S53>'  : 'simplePathFollow/PID Controller/Ideal P Gain Fdbk/Internal Parameters'
 * '<S54>'  : 'simplePathFollow/PID Controller/Ideal P Gain Fdbk/Passthrough'
 * '<S55>'  : 'simplePathFollow/PID Controller/Integrator/Continuous'
 * '<S56>'  : 'simplePathFollow/PID Controller/Integrator/Disabled'
 * '<S57>'  : 'simplePathFollow/PID Controller/Integrator/Discrete'
 * '<S58>'  : 'simplePathFollow/PID Controller/Integrator ICs/Disabled'
 * '<S59>'  : 'simplePathFollow/PID Controller/Integrator ICs/External IC'
 * '<S60>'  : 'simplePathFollow/PID Controller/Integrator ICs/Internal IC'
 * '<S61>'  : 'simplePathFollow/PID Controller/N Copy/Disabled'
 * '<S62>'  : 'simplePathFollow/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S63>'  : 'simplePathFollow/PID Controller/N Copy/External Parameters'
 * '<S64>'  : 'simplePathFollow/PID Controller/N Copy/Internal Parameters'
 * '<S65>'  : 'simplePathFollow/PID Controller/N Gain/Disabled'
 * '<S66>'  : 'simplePathFollow/PID Controller/N Gain/External Parameters'
 * '<S67>'  : 'simplePathFollow/PID Controller/N Gain/Internal Parameters'
 * '<S68>'  : 'simplePathFollow/PID Controller/N Gain/Passthrough'
 * '<S69>'  : 'simplePathFollow/PID Controller/P Copy/Disabled'
 * '<S70>'  : 'simplePathFollow/PID Controller/P Copy/External Parameters Ideal'
 * '<S71>'  : 'simplePathFollow/PID Controller/P Copy/Internal Parameters Ideal'
 * '<S72>'  : 'simplePathFollow/PID Controller/Parallel P Gain/Disabled'
 * '<S73>'  : 'simplePathFollow/PID Controller/Parallel P Gain/External Parameters'
 * '<S74>'  : 'simplePathFollow/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S75>'  : 'simplePathFollow/PID Controller/Parallel P Gain/Passthrough'
 * '<S76>'  : 'simplePathFollow/PID Controller/Reset Signal/Disabled'
 * '<S77>'  : 'simplePathFollow/PID Controller/Reset Signal/External Reset'
 * '<S78>'  : 'simplePathFollow/PID Controller/Saturation/Enabled'
 * '<S79>'  : 'simplePathFollow/PID Controller/Saturation/Passthrough'
 * '<S80>'  : 'simplePathFollow/PID Controller/Saturation Fdbk/Disabled'
 * '<S81>'  : 'simplePathFollow/PID Controller/Saturation Fdbk/Enabled'
 * '<S82>'  : 'simplePathFollow/PID Controller/Saturation Fdbk/Passthrough'
 * '<S83>'  : 'simplePathFollow/PID Controller/Sum/Passthrough_I'
 * '<S84>'  : 'simplePathFollow/PID Controller/Sum/Passthrough_P'
 * '<S85>'  : 'simplePathFollow/PID Controller/Sum/Sum_PD'
 * '<S86>'  : 'simplePathFollow/PID Controller/Sum/Sum_PI'
 * '<S87>'  : 'simplePathFollow/PID Controller/Sum/Sum_PID'
 * '<S88>'  : 'simplePathFollow/PID Controller/Sum Fdbk/Disabled'
 * '<S89>'  : 'simplePathFollow/PID Controller/Sum Fdbk/Enabled'
 * '<S90>'  : 'simplePathFollow/PID Controller/Sum Fdbk/Passthrough'
 * '<S91>'  : 'simplePathFollow/PID Controller/Tracking Mode/Disabled'
 * '<S92>'  : 'simplePathFollow/PID Controller/Tracking Mode/Enabled'
 * '<S93>'  : 'simplePathFollow/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S94>'  : 'simplePathFollow/PID Controller/Tracking Mode Sum/Tracking Mode'
 * '<S95>'  : 'simplePathFollow/PID Controller/postSat Signal/Feedback_Path'
 * '<S96>'  : 'simplePathFollow/PID Controller/postSat Signal/Forward_Path'
 * '<S97>'  : 'simplePathFollow/PID Controller/preSat Signal/Feedback_Path'
 * '<S98>'  : 'simplePathFollow/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_simplePathFollow_h_ */

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : simplePathFollow
 * Model version : 1.40
 * VeriStand Model Framework version : 2020.2.0.0 (2020 R2)
 * Source generated on : Tue Oct 20 03:39:32 2020
 *========================================================================*/
#if !defined(NI_HEADER_simplePathFollow_h_)
#define NI_HEADER_simplePathFollow_h_
#ifdef NI_ROOTMODEL_simplePathFollow

/* main model definitions enabled by makefile */
#include "ni_pglobals.h"
#ifndef NI_VERISTAND_MODELDATAFILE
#ifdef NI_VERISTAND_MAINMODELFILE

/* simplePathFollow.c definitions */
int READSIDE = 0;
int tid = 0;

#ifdef MULTITASKING

/* multi-rate model */
P_simplePathFollow_T rtParameter[NUMST+!TID01EQ];
P_simplePathFollow_T *param_lookup[NUMST][2] = {
  { &rtParameter[0], &rtParameter[1] },
};

#else

/* single-rate model */
P_simplePathFollow_T rtParameter[2];

#endif

#else

extern int READSIDE;

#ifdef MULTITASKING

/* multi-rate model */
extern int tid;
extern P_simplePathFollow_T* param_lookup[NUMST][2];

#else

/* single-rate model */
extern P_simplePathFollow_T rtParameter[];

#endif
#endif

/* Declare parameter macros */
#define _NI_DEFINE_PARAMS_DBL_BUFFER_
#include "ni_pglobals.h"
#endif
#endif
#endif                                 /* NI_HEADER_simplePathFollow_h_ */
