#define NI_VERISTAND_MAINMODELFILE

/*
   c
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
#include "simplePathFollow.h"
#include "simplePathFollow_private.h"

/* Block signals (default storage) */
B_simplePathFollow_T simplePathFollow_B;

/* Block states (default storage) */
DW_simplePathFollow_T simplePathFollow_DW;

/* Real-time model */
RT_MODEL_simplePathFollow_T simplePathFollow_M_;
RT_MODEL_simplePathFollow_T *const simplePathFollow_M = &simplePathFollow_M_;

/* Forward declaration for local functions */
static void simplePathFollow_latlon2global(const real_T oriPoint[2], const
  real_T point[3], real_T *distX, real_T *distY);
static void simplePathFollow_global2vehXY(real_T globalX, real_T globalY, real_T
  vehX, real_T vehY, real_T vehYaw, real_T vehXY[3]);
static void simplePathFollow_pwchcore(const real_T x[235], const real_T y[235],
  const real_T s[235], const real_T dx[234], const real_T divdif[234], real_T
  pp_breaks[235], real_T pp_coefs[936]);
static void simplePathFollow_spline(const real_T x[235], const real_T y[235],
  real_T output_breaks[235], real_T output_coefs[936]);
static real_T simplePathFollow_ppval(const real_T pp_breaks[235], const real_T
  pp_coefs[936], real_T x);

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void simplePathFollow_latlon2global(const real_T oriPoint[2], const
  real_T point[3], real_T *distX, real_T *distY)
{
  *distX = cos(oriPoint[0] * 3.1415926535897931 / 180.0) * 6.378137E+6 * (point
    [1] - oriPoint[1]) * 3.1415926535897931 / 180.0;
  *distY = (point[0] - oriPoint[0]) * 6.356725E+6 * 3.1415926535897931 / 180.0;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void simplePathFollow_global2vehXY(real_T globalX, real_T globalY, real_T
  vehX, real_T vehY, real_T vehYaw, real_T vehXY[3])
{
  real_T alpha;
  real_T A[4];
  real_T B[2];
  int32_T r1;
  int32_T r2;
  real_T A_tmp;
  alpha = vehYaw * 3.1415926535897931 / 180.0;
  A_tmp = sin(alpha);
  A[0] = A_tmp;
  alpha = cos(alpha);
  A[2] = alpha;
  A[1] = alpha;
  A[3] = -A_tmp;
  B[0] = globalX - vehX;
  B[1] = globalY - vehY;
  if (fabs(alpha) > fabs(A_tmp)) {
    r1 = 1;
    r2 = 0;
  } else {
    r1 = 0;
    r2 = 1;
  }

  alpha = A[r2] / A[r1];
  A_tmp = A[2 + r1];
  alpha = (B[r2] - B[r1] * alpha) / (A[2 + r2] - A_tmp * alpha);
  vehXY[0] = (B[r1] - A_tmp * alpha) / A[r1];
  vehXY[1] = -alpha;
  vehXY[2] = -0.0;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void simplePathFollow_pwchcore(const real_T x[235], const real_T y[235],
  const real_T s[235], const real_T dx[234], const real_T divdif[234], real_T
  pp_breaks[235], real_T pp_coefs[936])
{
  real_T dzzdx;
  real_T dzdxdx;
  int32_T j;
  memcpy(&pp_breaks[0], &x[0], 235U * sizeof(real_T));
  for (j = 0; j < 234; j++) {
    dzzdx = (divdif[j] - s[j]) / dx[j];
    dzdxdx = (s[j + 1] - divdif[j]) / dx[j];
    pp_coefs[j] = (dzdxdx - dzzdx) / dx[j];
    pp_coefs[j + 234] = 2.0 * dzzdx - dzdxdx;
    pp_coefs[j + 468] = s[j];
    pp_coefs[j + 702] = y[j];
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void simplePathFollow_spline(const real_T x[235], const real_T y[235],
  real_T output_breaks[235], real_T output_coefs[936])
{
  real_T s[235];
  real_T dvdf[234];
  real_T dx[234];
  real_T d31;
  real_T dnnm2;
  real_T md[235];
  real_T r;
  int32_T k;
  for (k = 0; k < 234; k++) {
    d31 = x[k + 1] - x[k];
    dvdf[k] = (y[k + 1] - y[k]) / d31;
    dx[k] = d31;
  }

  d31 = x[2] - x[0];
  dnnm2 = x[234] - x[232];
  s[0] = ((2.0 * d31 + dx[0]) * dx[1] * dvdf[0] + dx[0] * dx[0] * dvdf[1]) / d31;
  s[234] = ((2.0 * dnnm2 + dx[233]) * dx[232] * dvdf[233] + dx[233] * dx[233] *
            dvdf[232]) / dnnm2;
  md[0] = dx[1];
  md[234] = dx[232];
  for (k = 0; k < 233; k++) {
    r = dx[k + 1];
    s[k + 1] = (r * dvdf[k] + dvdf[k + 1] * dx[k]) * 3.0;
    md[k + 1] = (r + dx[k]) * 2.0;
  }

  r = dx[1] / md[0];
  md[1] -= r * d31;
  s[1] -= r * s[0];
  for (k = 0; k < 232; k++) {
    r = dx[k + 2] / md[k + 1];
    md[k + 2] -= r * dx[k];
    s[k + 2] -= s[k + 1] * r;
  }

  r = dnnm2 / md[233];
  md[234] -= r * dx[232];
  s[234] -= r * s[233];
  s[234] /= md[234];
  for (k = 232; k >= 0; k--) {
    s[k + 1] = (s[k + 1] - s[k + 2] * dx[k]) / md[k + 1];
  }

  s[0] = (s[0] - d31 * s[1]) / md[0];
  simplePathFollow_pwchcore(x, y, s, dx, dvdf, output_breaks, output_coefs);
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static real_T simplePathFollow_ppval(const real_T pp_breaks[235], const real_T
  pp_coefs[936], real_T x)
{
  real_T v;
  real_T xloc;
  int32_T low_i;
  int32_T low_ip1;
  int32_T high_i;
  int32_T mid_i;
  if (rtIsNaN(x)) {
    v = x;
  } else {
    low_i = 0;
    low_ip1 = 2;
    high_i = 235;
    while (high_i > low_ip1) {
      mid_i = ((low_i + high_i) + 1) >> 1;
      if (x >= pp_breaks[mid_i - 1]) {
        low_i = mid_i - 1;
        low_ip1 = mid_i + 1;
      } else {
        high_i = mid_i;
      }
    }

    xloc = x - pp_breaks[low_i];
    v = ((xloc * pp_coefs[low_i] + pp_coefs[low_i + 234]) * xloc +
         pp_coefs[low_i + 468]) * xloc + pp_coefs[low_i + 702];
  }

  return v;
}

/* Model output function */
static void simplePathFollow_output(void)
{
  int32_T i;
  real_T rtb_ManualSwitch[3];
  real_T assign_temp_breaks[235];
  real_T tmp[3];
  real_T vehGlobal_idx_0;
  real_T vehGlobal_idx_1;
  const real_T *rtb_MultiportSwitch_0;

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  if (simplePathFollow_P.ManualSwitch_CurrentSetting == 1) {
    rtb_ManualSwitch[0] = simplePathFollow_P.Constant1_Value[0];
    rtb_ManualSwitch[1] = simplePathFollow_P.Constant1_Value[1];
    rtb_ManualSwitch[2] = simplePathFollow_P.Constant1_Value[2];
  } else {
    rtb_ManualSwitch[0] = simplePathFollow_B.vehLoIn1[0];
    rtb_ManualSwitch[1] = simplePathFollow_B.vehLoIn1[1];
    rtb_ManualSwitch[2] = simplePathFollow_B.vehLoIn1[2];
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */
  /* ManualSwitch: '<Root>/Manual Switch3' incorporates:
   *  Constant: '<Root>/Constant7'
   */
  if (simplePathFollow_P.ManualSwitch3_CurrentSetting == 1) {
    vehGlobal_idx_0 = simplePathFollow_P.Constant7_Value;
  } else {
    vehGlobal_idx_0 = simplePathFollow_B.missionFlagIn2;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch3' */

  /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant4'
   */
  switch ((int32_T)vehGlobal_idx_0) {
   case 1:
    rtb_MultiportSwitch_0 = &simplePathFollow_P.distXYS2N[0];
    break;

   case 2:
    rtb_MultiportSwitch_0 = &simplePathFollow_P.distXYN2S[0];
    break;

   default:
    rtb_MultiportSwitch_0 = &simplePathFollow_P.distXYS2N[0];
    break;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant'
   */
  simplePathFollow_latlon2global(simplePathFollow_P.oriPoint, rtb_ManualSwitch,
    &vehGlobal_idx_0, &vehGlobal_idx_1);
  for (i = 0; i < 235; i++) {
    simplePathFollow_global2vehXY(rtb_MultiportSwitch_0[i],
      rtb_MultiportSwitch_0[235 + i], vehGlobal_idx_0, vehGlobal_idx_1,
      rtb_ManualSwitch[2], tmp);
    simplePathFollow_B.vehXY[i] = tmp[0];
    simplePathFollow_B.vehXY[i + 235] = tmp[1];
    simplePathFollow_B.vehXY[i + 470] = tmp[2];
  }

  simplePathFollow_spline(&simplePathFollow_B.vehXY[0],
    &simplePathFollow_B.vehXY[235], assign_temp_breaks,
    simplePathFollow_B.assign_temp_coefs);

  /* ManualSwitch: '<Root>/Manual Switch2' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  if (simplePathFollow_P.ManualSwitch2_CurrentSetting == 1) {
    vehGlobal_idx_0 = simplePathFollow_B.vehLoIn1[6];
  } else {
    vehGlobal_idx_0 = simplePathFollow_P.Constant3_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch2' */

  /* MATLAB Function: '<Root>/MATLAB Function' */
  simplePathFollow_B.preOffset = simplePathFollow_ppval(assign_temp_breaks,
    simplePathFollow_B.assign_temp_coefs, vehGlobal_idx_0);

  /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
   *  Constant: '<Root>/Constant6'
   */
  if (simplePathFollow_P.ManualSwitch1_CurrentSetting == 1) {
    rtb_ManualSwitch[0] = simplePathFollow_B.vehLoIn1[3];
    rtb_ManualSwitch[1] = simplePathFollow_B.vehLoIn1[4];
    rtb_ManualSwitch[2] = simplePathFollow_B.vehLoIn1[5];
  } else {
    rtb_ManualSwitch[0] = simplePathFollow_P.Constant6_Value[0];
    rtb_ManualSwitch[1] = simplePathFollow_P.Constant6_Value[1];
    rtb_ManualSwitch[2] = simplePathFollow_P.Constant6_Value[2];
  }

  /* End of ManualSwitch: '<Root>/Manual Switch1' */

  /* Product: '<S66>/NProd Out' incorporates:
   *  Constant: '<Root>/Constant5'
   *  DiscreteIntegrator: '<S39>/Filter'
   *  Product: '<S33>/DProd Out'
   *  Sum: '<S39>/SumD'
   */
  simplePathFollow_B.NProdOut = (simplePathFollow_B.preOffset *
    rtb_ManualSwitch[2] - simplePathFollow_DW.Filter_DSTATE) *
    simplePathFollow_P.Constant5_Value;

  /* Sum: '<S87>/Sum' incorporates:
   *  DiscreteIntegrator: '<S57>/Integrator'
   *  Product: '<S73>/PProd Out'
   */
  vehGlobal_idx_0 = (simplePathFollow_B.preOffset * rtb_ManualSwitch[0] +
                     simplePathFollow_DW.Integrator_DSTATE) +
    simplePathFollow_B.NProdOut;

  /* Saturate: '<S78>/Saturation' */
  if (vehGlobal_idx_0 > simplePathFollow_P.PIDController_UpperSaturationLi) {
    simplePathFollow_B.Saturation =
      simplePathFollow_P.PIDController_UpperSaturationLi;
  } else if (vehGlobal_idx_0 <
             simplePathFollow_P.PIDController_LowerSaturationLi) {
    simplePathFollow_B.Saturation =
      simplePathFollow_P.PIDController_LowerSaturationLi;
  } else {
    simplePathFollow_B.Saturation = vehGlobal_idx_0;
  }

  /* End of Saturate: '<S78>/Saturation' */
  /* Product: '<S46>/IProd Out' */
  simplePathFollow_B.IProdOut = simplePathFollow_B.preOffset * rtb_ManualSwitch
    [1];
}

/* Model update function */
static void simplePathFollow_update(void)
{
  /* Update for DiscreteIntegrator: '<S57>/Integrator' */
  simplePathFollow_DW.Integrator_DSTATE += simplePathFollow_P.Integrator_gainval
    * simplePathFollow_B.IProdOut;

  /* Update for DiscreteIntegrator: '<S39>/Filter' */
  simplePathFollow_DW.Filter_DSTATE += simplePathFollow_P.Filter_gainval *
    simplePathFollow_B.NProdOut;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++simplePathFollow_M->Timing.clockTick0)) {
    ++simplePathFollow_M->Timing.clockTickH0;
  }

  simplePathFollow_M->Timing.t[0] = simplePathFollow_M->Timing.clockTick0 *
    simplePathFollow_M->Timing.stepSize0 +
    simplePathFollow_M->Timing.clockTickH0 *
    simplePathFollow_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void simplePathFollow_initialize(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<S57>/Integrator' */
  simplePathFollow_DW.Integrator_DSTATE =
    simplePathFollow_P.PIDController_InitialConditio_e;

  /* InitializeConditions for DiscreteIntegrator: '<S39>/Filter' */
  simplePathFollow_DW.Filter_DSTATE =
    simplePathFollow_P.PIDController_InitialConditionF;
}

/* Model terminate function */
static void simplePathFollow_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  simplePathFollow_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  simplePathFollow_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  simplePathFollow_initialize();
}

void MdlTerminate(void)
{
  simplePathFollow_terminate();
}

/* Registration function */
RT_MODEL_simplePathFollow_T *simplePathFollow(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)simplePathFollow_M, 0,
                sizeof(RT_MODEL_simplePathFollow_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = simplePathFollow_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    simplePathFollow_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    simplePathFollow_M->Timing.sampleTimes =
      (&simplePathFollow_M->Timing.sampleTimesArray[0]);
    simplePathFollow_M->Timing.offsetTimes =
      (&simplePathFollow_M->Timing.offsetTimesArray[0]);

    /* task periods */
    simplePathFollow_M->Timing.sampleTimes[0] = (0.05);

    /* task offsets */
    simplePathFollow_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(simplePathFollow_M, &simplePathFollow_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = simplePathFollow_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    simplePathFollow_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(simplePathFollow_M, 10.0);
  simplePathFollow_M->Timing.stepSize0 = 0.05;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    simplePathFollow_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(simplePathFollow_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(simplePathFollow_M->rtwLogInfo, (NULL));
    rtliSetLogT(simplePathFollow_M->rtwLogInfo, "tout");
    rtliSetLogX(simplePathFollow_M->rtwLogInfo, "");
    rtliSetLogXFinal(simplePathFollow_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(simplePathFollow_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(simplePathFollow_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(simplePathFollow_M->rtwLogInfo, 0);
    rtliSetLogDecimation(simplePathFollow_M->rtwLogInfo, 1);
    rtliSetLogY(simplePathFollow_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(simplePathFollow_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(simplePathFollow_M->rtwLogInfo, (NULL));
  }

  simplePathFollow_M->solverInfoPtr = (&simplePathFollow_M->solverInfo);
  simplePathFollow_M->Timing.stepSize = (0.05);
  rtsiSetFixedStepSize(&simplePathFollow_M->solverInfo, 0.05);
  rtsiSetSolverMode(&simplePathFollow_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  simplePathFollow_M->blockIO = ((void *) &simplePathFollow_B);
  (void) memset(((void *) &simplePathFollow_B), 0,
                sizeof(B_simplePathFollow_T));

  /* parameters */
  simplePathFollow_M->defaultParam = ((real_T *)&simplePathFollow_P);

  /* states (dwork) */
  simplePathFollow_M->dwork = ((void *) &simplePathFollow_DW);
  (void) memset((void *)&simplePathFollow_DW, 0,
                sizeof(DW_simplePathFollow_T));

  /* Initialize Sizes */
  simplePathFollow_M->Sizes.numContStates = (0);/* Number of continuous states */
  simplePathFollow_M->Sizes.numY = (0);/* Number of model outputs */
  simplePathFollow_M->Sizes.numU = (0);/* Number of model inputs */
  simplePathFollow_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  simplePathFollow_M->Sizes.numSampTimes = (1);/* Number of sample times */
  simplePathFollow_M->Sizes.numBlocks = (35);/* Number of blocks */
  simplePathFollow_M->Sizes.numBlockIO = (6);/* Number of block outputs */
  simplePathFollow_M->Sizes.numBlockPrms = (985);/* Sum of parameter "widths" */
  return simplePathFollow_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : simplePathFollow
 * Model version : 1.40
 * VeriStand Model Framework version : 2020.2.0.0 (2020 R2)
 * Source generated on : Tue Oct 20 03:39:32 2020
 *========================================================================*/

/* This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_simplePathFollow
#include "ni_modelframework_ex.h"
#include <stddef.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

unsigned char ReadSideDirtyFlag = 0, WriteSideDirtyFlag = 0;

/*========================================================================*
 * Function: NIRT_GetValueByDataType
 *
 * Abstract:
 *		Converting to and from double and datatypes used in the model
 *
 * Output Parameters
 *      ptr : address to the source
 *      subindex : index value if vector
 *      type   : the source's data type
 *      Complex : true if a complex data type
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
double NIRT_GetValueByDataType(void* ptr, int32_t subindex, int32_t type,
  int32_t Complex)
{
  switch (type)
  {
   case 0:
    return (double)(((real_T*)ptr)[subindex]);

   case 1:
    return (double)(((real32_T*)ptr)[subindex]);

   case 2:
    return (double)(((int8_T*)ptr)[subindex]);

   case 3:
    return (double)(((uint8_T*)ptr)[subindex]);

   case 4:
    return (double)(((int16_T*)ptr)[subindex]);

   case 5:
    return (double)(((uint16_T*)ptr)[subindex]);

   case 6:
    return (double)(((int32_T*)ptr)[subindex]);

   case 7:
    return (double)(((uint32_T*)ptr)[subindex]);

   case 8:
    return (double)(((boolean_T*)ptr)[subindex]);

   case 10:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 13:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 15:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 16:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 17:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 18:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 19:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 20:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 21:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 22:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 24:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 25:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 26:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 27:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 29:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 30:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 31:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 32:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 33:
    return (( double *)ptr)[subindex];

   case 34:
    return (( double *)ptr)[subindex];

   case 35:
    return (( double *)ptr)[subindex];

   case 36:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 37:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 38:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 39:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);
  }

  /* return ((double *)ptr)[subindex]; */
  return rtNaN;
}

/*========================================================================*
 * Function: NIRT_SetValueByDataType
 *
 * Abstract:
 *		Converting to and from double and datatypes used in the model
 *
 * Output Parameters
 *      ptr : address to the destination
 *      subindex : index value if vector
 *      value : value to set on the destination
 *      type   : the destination's data type
 *      Complex : true if a complex data type
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
int32_t NIRT_SetValueByDataType(void* ptr, int32_t subindex, double value,
  int32_t type, int32_t Complex)
{
  /* Complex is only used for R14.3 and down */
  switch (type)
  {
   case 0:
    ((real_T *)ptr)[subindex] = (real_T)value;
    return NI_OK;

   case 1:
    ((real32_T *)ptr)[subindex] = (real32_T)value;
    return NI_OK;

   case 2:
    ((int8_T *)ptr)[subindex] = (int8_T)value;
    return NI_OK;

   case 3:
    ((uint8_T *)ptr)[subindex] = (uint8_T)value;
    return NI_OK;

   case 4:
    ((int16_T *)ptr)[subindex] = (int16_T)value;
    return NI_OK;

   case 5:
    ((uint16_T *)ptr)[subindex] = (uint16_T)value;
    return NI_OK;

   case 6:
    ((int32_T *)ptr)[subindex] = (int32_T)value;
    return NI_OK;

   case 7:
    ((uint32_T *)ptr)[subindex] = (uint32_T)value;
    return NI_OK;

   case 8:
    ((boolean_T *)ptr)[subindex] = (boolean_T)value;
    return NI_OK;

   case 10:
    /* Type is renamed. Call SetValueByDataType on its contained type */
    return NIRT_SetValueByDataType(ptr, subindex, value, 6, Complex);

   case 13:
    /* Type is matrix. Call SetValueByDataType on its contained type */
    return NIRT_SetValueByDataType(ptr, subindex, value, 7, Complex);

   case 15:
    /* Type is enum. Call SetValueByDataType on its contained type */
    return NIRT_SetValueByDataType(ptr, subindex, value, 6, Complex);

   case 16:
    /* Type is enum. Call SetValueByDataType on its contained type */
    return NIRT_SetValueByDataType(ptr, subindex, value, 6, Complex);

   case 17:
    /* Type is renamed. Call SetValueByDataType on its contained type */
    return NIRT_SetValueByDataType(ptr, subindex, value, 3, Complex);

   case 18:
    /* Type is matrix. Call SetValueByDataType on its contained type */
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 19:
    /* Type is matrix. Call SetValueByDataType on its contained type */
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 20:
    /* Type is matrix. Call SetValueByDataType on its contained type */
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 21:
    /* Type is matrix. Call SetValueByDataType on its contained type */
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 22:
    /* Type is matrix. Call SetValueByDataType on its contained type */
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 23:
    /* Type is matrix. Call SetValueByDataType on its contained type */
    return NIRT_SetValueByDataType(ptr, subindex, value, 3, Complex);

   case 24:
    /* Type is matrix. Call SetValueByDataType on its contained type */
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 25:
    /* Type is matrix. Call SetValueByDataType on its contained type */
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 26:
    /* Type is matrix. Call SetValueByDataType on its contained type */
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 27:
    /* Type is matrix. Call SetValueByDataType on its contained type */
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 29:
    /* Type is matrix. Call SetValueByDataType on its contained type */
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 30:
    /* Type is matrix. Call SetValueByDataType on its contained type */
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 31:
    /* Type is matrix. Call SetValueByDataType on its contained type */
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 32:
    /* Type is matrix. Call SetValueByDataType on its contained type */
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 36:
    /* Type is matrix. Call SetValueByDataType on its contained type */
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 37:
    /* Type is matrix. Call SetValueByDataType on its contained type */
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 38:
    /* Type is matrix. Call SetValueByDataType on its contained type */
    return NIRT_SetValueByDataType(ptr, subindex, value, 3, Complex);

   case 39:
    /* Type is matrix. Call SetValueByDataType on its contained type */
    return NIRT_SetValueByDataType(ptr, subindex, value, 3, Complex);
  }

  /* No matching datatype conversion */
  return NI_ERROR;
}

extern simplePathFollow_rtModel *S;
extern _SITexportglobals SITexportglobals;

/*========================================================================*
 * Function: SetExternalInputs
 *
 * Abstract:
 *		Set data to model ports on the specified task
 *
 * Input Parameters
 *      data : data to set
 *      TaskSampleHit : task id
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
void SetExternalInputs(double* data, int_T* TaskSampleHit)
{
  int index = 0, count = 0;

  /* simplePathFollow/vehLo In1 */
  if (TaskSampleHit[0]) {
    for (count = 0; count < 7; count++) {
      NIRT_SetValueByDataType(&simplePathFollow_B.vehLoIn1, count, data[index++],
        21, 0);
    }
  } else {
    index += 7;
  }

  /* simplePathFollow/missionFlag In2 */
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&simplePathFollow_B.missionFlagIn2, 0, data[index++],
      38, 0);
  } else {
    index += 1;
  }
}                                      /* of SetExternalInputs */

int32_t NumInputPorts(void)
{
  return 8;
}

int32_t NumOutputPorts(void)
{
  return 2;
}

double ni_extout[2];

/*========================================================================*
 * Function: SetExternalOutputs
 *
 * Abstract:
 *		Set data to model ports on the specified task
 *
 * Input Parameters
 *      data : data to set
 *      TaskSampleHit : task id
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
void SetExternalOutputs(double* data, int_T* TaskSampleHit)
{
  int index = 0, count = 0;

  /* simplePathFollow/steerAngle Out1: Virtual Signal # 0 */
  if (TaskSampleHit[0]) {              /* sample and hold	*/
    ni_extout[index++] = NIRT_GetValueByDataType(&simplePathFollow_B.Saturation,
      0, 36, 0);
  } else {
    index += 1;
  }

  /* simplePathFollow/offset Out2: Virtual Signal # 0 */
  if (TaskSampleHit[0]) {              /* sample and hold	*/
    ni_extout[index++] = NIRT_GetValueByDataType(&simplePathFollow_B.preOffset,
      0, 0, 0);
  } else {
    index += 1;
  }

  if (data != NULL) {
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
  }

  UNUSED_PARAMETER(count);
}

/*========================================================================*
 * Function: NI_InitExternalOutputs
 *
 * Abstract:
 *		Initialize model ports
 *
 * Output Parameters
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
int32_t NI_InitExternalOutputs()
{
  int index = 0, count = 0;

  /* simplePathFollow/steerAngle Out1: Virtual Signal # 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&simplePathFollow_B.Saturation, 0,
    36, 0);

  /* simplePathFollow/offset Out2: Virtual Signal # 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&simplePathFollow_B.preOffset, 0,
    0, 0);
  UNUSED_PARAMETER(count);
  return NI_OK;
}

/* Undefine parameter macros. The undef allows us to access the real declarations.
   In the Simulink(R) generated code, the parameters are redefined to be the read-side of rtParameter.*/
#define _NI_UNDEFINE_PARAMS_DBL_BUFFER_
#include "ni_pglobals.h"

/* All elements by default (including scalars) have 2 dimensions [1,1] */
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0, "simplepathfollow/Constant2/Value", offsetof(P_simplePathFollow_T,
    distXYN2S[0]), 0, 470, 2, 0, 0 },

  { 1, "simplepathfollow/Constant4/Value", offsetof(P_simplePathFollow_T,
    distXYS2N[0]), 0, 470, 2, 2, 0 },

  { 2, "simplepathfollow/Constant/Value", offsetof(P_simplePathFollow_T,
    oriPoint[0]), 0, 2, 2, 4, 0 },

  { 3, "simplepathfollow/Constant7/Value", offsetof(P_simplePathFollow_T,
    Constant7_Value), 0, 1, 2, 6, 0 },

  { 4, "simplepathfollow/Constant3/Value", offsetof(P_simplePathFollow_T,
    Constant3_Value), 0, 1, 2, 8, 0 },

  { 5, "simplepathfollow/Constant6/Value", offsetof(P_simplePathFollow_T,
    Constant6_Value[0]), 0, 3, 2, 10, 0 },

  { 6, "simplepathfollow/Constant1/Value", offsetof(P_simplePathFollow_T,
    Constant1_Value[0]), 0, 3, 2, 12, 0 },

  { 7, "simplepathfollow/PID Controller/Integrator/Discrete/Integrator/gainval",
    offsetof(P_simplePathFollow_T, Integrator_gainval), 0, 1, 2, 14, 0 },

  { 8,
    "simplepathfollow/PID Controller/Filter/Disc. Forward Euler Filter/Filter/gainval",
    offsetof(P_simplePathFollow_T, Filter_gainval), 0, 1, 2, 16, 0 },

  { 9, "simplepathfollow/Constant5/Value", offsetof(P_simplePathFollow_T,
    Constant5_Value), 0, 1, 2, 18, 0 },

  { 10, "simplepathfollow/Manual Switch/CurrentSetting", offsetof
    (P_simplePathFollow_T, ManualSwitch_CurrentSetting), 3, 1, 2, 20, 0 },

  { 11, "simplepathfollow/Manual Switch3/CurrentSetting", offsetof
    (P_simplePathFollow_T, ManualSwitch3_CurrentSetting), 3, 1, 2, 22, 0 },

  { 12, "simplepathfollow/Manual Switch2/CurrentSetting", offsetof
    (P_simplePathFollow_T, ManualSwitch2_CurrentSetting), 3, 1, 2, 24, 0 },

  { 13, "simplepathfollow/Manual Switch1/CurrentSetting", offsetof
    (P_simplePathFollow_T, ManualSwitch1_CurrentSetting), 3, 1, 2, 26, 0 },
};

static int32_t NI_ParamListSize DataSection(".NIVS.paramlistsize") = 14;
static int32_t NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  1, 470,                              /* Parameter at index 0 */
  1, 470,                              /* Parameter at index 1 */
  1, 2,                                /* Parameter at index 2 */
  1, 1,                                /* Parameter at index 3 */
  1, 1,                                /* Parameter at index 4 */
  1, 3,                                /* Parameter at index 5 */
  1, 3,                                /* Parameter at index 6 */
  1, 1,                                /* Parameter at index 7 */
  1, 1,                                /* Parameter at index 8 */
  1, 1,                                /* Parameter at index 9 */
  1, 1,                                /* Parameter at index 10 */
  1, 1,                                /* Parameter at index 11 */
  1, 1,                                /* Parameter at index 12 */
  1, 1,                                /* Parameter at index 13 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "simplepathfollow/vehLo In1/(1, 1)", 0, "", offsetof(B_simplePathFollow_T,
    vehLoIn1) + (0*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 1, "simplepathfollow/vehLo In1/(2, 1)", 0, "", offsetof(B_simplePathFollow_T,
    vehLoIn1) + (1*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 2, "simplepathfollow/vehLo In1/(3, 1)", 0, "", offsetof(B_simplePathFollow_T,
    vehLoIn1) + (2*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 3, "simplepathfollow/vehLo In1/(4, 1)", 0, "", offsetof(B_simplePathFollow_T,
    vehLoIn1) + (3*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 4, "simplepathfollow/vehLo In1/(5, 1)", 0, "", offsetof(B_simplePathFollow_T,
    vehLoIn1) + (4*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 5, "simplepathfollow/vehLo In1/(6, 1)", 0, "", offsetof(B_simplePathFollow_T,
    vehLoIn1) + (5*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 6, "simplepathfollow/vehLo In1/(7, 1)", 0, "", offsetof(B_simplePathFollow_T,
    vehLoIn1) + (6*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 7, "simplepathfollow/PID Controller/N Gain/External Parameters/NProd Out", 0,
    "", offsetof(B_simplePathFollow_T, NProdOut) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 8, "simplepathfollow/PID Controller/Saturation/Enabled/Saturation", 0, "",
    offsetof(B_simplePathFollow_T, Saturation) + (0*sizeof(real_T)), BLOCKIO_SIG,
    36, 1, 2, 0, 0 },

  { 9, "simplepathfollow/PID Controller/I Gain/External Parameters/IProd Out", 0,
    "", offsetof(B_simplePathFollow_T, IProdOut) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 36, 1, 2, 0, 0 },

  { 10, "simplepathfollow/MATLAB Function", 0, "", offsetof(B_simplePathFollow_T,
    preOffset) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 11, "simplepathfollow/missionFlag In2", 0, "", offsetof(B_simplePathFollow_T,
    missionFlagIn2) + (0*sizeof(uint8_T)), BLOCKIO_SIG, 38, 1, 2, 0, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int32_t NI_SigListSize DataSection(".NIVS.siglistsize") = 12;
static int32_t NI_VirtualBlockSources[1];
static int32_t NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{ 1, 1
};

static int32_t NI_ExtListSize DataSection(".NIVS.extlistsize") = 4;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 1, "vehLo In1", 0, EXT_IN, 7, 7, 1 },

  { 2, "missionFlag In2", 0, EXT_IN, 1, 1, 1 },

  { 1, "steerAngle Out1", 0, EXT_OUT, 1, 1, 1 },

  { 2, "offset Out2", 0, EXT_OUT, 1, 1, 1 },

  { -1, "", 0, 0, 0, 0, 0 }
};

/* This Task List is generated to allow access to the task specs without
 * initializing the model.
 * 0th entry is for scheduler (base rate)
 * rest for multirate model's tasks.
 */
NI_Task NI_TaskList[] DataSection(".NIVS.tasklist") =
{
  { 0, 0.05, 0 }
};

int32_t NI_NumTasks DataSection(".NIVS.numtasks") = 1;
static const char* NI_CompiledModelName DataSection(".NIVS.compiledmodelname") =
  "simplePathFollow";
static const char* NI_CompiledModelVersion = "1.40";
static const char* NI_CompiledModelDateTime = "Tue Oct 20 03:39:32 2020";
static const char* NI_builder DataSection(".NIVS.builder") =
  "NI Model Framework 2020.2.0.0 (2020 R2) for Simulink Coder 9.0 (R2018b)";
static const char* NI_BuilderVersion DataSection(".NIVS.builderversion") =
  "2020.2.0.0";

/*========================================================================*
 * Function: NIRT_GetBuildInfo
 *
 * Abstract:
 *	Get the DLL versioning etc information.
 *
 * Output Parameters:
 *	detail	: String containing model build information.
 *	len		: the build info string length. If a value of "-1" is specified, the minimum buffer size of "detail" is returned as its value.
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetBuildInfo(char* detail, int32_t* len)
{
  int32_t msgLength = 0;
  char *msgBuffer = NULL;

  /* Message */
  const char msg[] =
    "%s\nModel Name: %s\nModel Version: %s\nVeriStand Model Framework Version: %s\nCompiled On: %s";

  /* There are no console properties to set for VxWorks, because the console is simply serial output data.
     Just do printf for VxWorks and ignore all console properties. */
#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hStdout, FOREGROUND_INTENSITY | FOREGROUND_BLUE |
    FOREGROUND_GREEN | FOREGROUND_RED);

#endif

  /* Print to screen */
  printf("\n*******************************************************************************\n");
  msgLength = printf(msg, NI_builder, NI_CompiledModelName,
                     NI_CompiledModelVersion, NI_BuilderVersion,
                     NI_CompiledModelDateTime);
  printf("\n*******************************************************************************\n");

#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN |
    FOREGROUND_RED);

#endif

  if (*len == -1) {
    /* Return the required minimum buffer size */
    *len = msgLength;
  } else {
    /* allocate the buffer */
    msgBuffer = (char*)calloc(msgLength + 1, sizeof(char));
    sprintf (msgBuffer, msg, NI_builder, NI_CompiledModelName,
             NI_CompiledModelVersion, NI_BuilderVersion,
             NI_CompiledModelDateTime);
    if (*len >= msgLength) {
      *len = msgLength + 1;
    }

    /* Copy into external buffer */
    strncpy(detail, msgBuffer, *len);

    /* Release memory */
    free(msgBuffer);
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetSignalSpec
 *
 * Abstract:
 *	If index == -1, lookup parameter by the ID.
 *	If ID_len == 0 or if ID == null, return number of parameters in model.
 *	Otherwise, lookup parameter by index, and return the information.
 *
 * Input/Output Parameters:
 *	index		: index of the signal (in/out)
 *	ID			: ID of signal to be looked up (in), ID of signal at index (out)
 *	ID_len		: length of input ID(in), length of ID (out)
 *	bnlen		: length of buffer blkname (in), length of output blkname (out)
 *	snlen		: length of buffer signame (in), length of output signame (out)
 *
 * Output Parameters:
 *	blkname		: Name of the source block for the signal
 *	portnum		: port number of the block that is the source of the signal (0 indexed)
 *	signame		: Name of the signal
 *	datatype	: same as with parameters. Currently assuming all data to be double.
 *	dims		: The port's dimension of length 'numdims'.
 *	numdims		: the port's number of dimensions. If a value of "-1" is specified, the minimum buffer size of "dims" is returned as its value.
 *
 * Returns:
 *	NI_OK if no error(if sigidx == -1, number of signals)
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetSignalSpec(int32_t* sidx, char* ID, int32_t* ID_len,
  char* blkname, int32_t *bnlen,
  int32_t *portnum, char* signame, int32_t *snlen, int32_t *dattype, int32_t*
  dims, int32_t* numdim)
{
  int32_t sigidx = *sidx;
  int32_t i = 0;
  char *addr = NULL;
  char *IDblk = 0;
  int32_t IDport = 0;
  if (sigidx < 0) {
    /* check if ID has been specified. */
    if ((ID != NULL) && (ID_len != NULL) && (*ID_len > 0)) {
      /* parse ID into blkname and port */
      addr = strrchr(ID, ':');
      if (addr == NULL) {
        return NI_SigListSize;
      }

      /* Calculate the char offset into the string after the port */
      i = addr - ID;

      /* malformed ID */
      if (i<=0) {
        return NI_SigListSize;
      }

      IDblk = ID;
      IDport = atoi(ID+i+1);

      /* lookup the table for matching ID */
      for (i=0; i<NI_SigListSize; i++) {
        /* 11 to accomodate ':','/', port number and null character */
        char *tempID = (char *)calloc(strlen(NI_SigList[i].blockname)+strlen
          (NI_SigList[i].signalname) + 11, sizeof(char));
        if (strlen(NI_SigList[i].signalname)>0) {
          sprintf(tempID,"%s:%d%s%s",NI_SigList[i].blockname,NI_SigList[i].
                  portno+1,"/",NI_SigList[i].signalname);
        } else {
          sprintf(tempID,"%s:%d",NI_SigList[i].blockname,NI_SigList[i].portno+1);
        }

        if (!strcmp(IDblk,tempID) && IDport==(NI_SigList[i].portno+1)) {
          break;
        }

        free(tempID);
      }

      if (i < NI_SigListSize) {
        sigidx = *sidx = i;
      } else {
        return NI_SigListSize;
      }
    } else {
      /* no index or ID specified. */
      return NI_SigListSize;
    }
  }

  if (sigidx>=0 && sigidx<NI_SigListSize) {
    if (ID != NULL) {
      /*  no need for return string to be null terminated! */
      /* 11 to accomodate ':','/', port number and null character */
      char *tempID = (char *)calloc(strlen(NI_SigList[sigidx].blockname)+strlen
        (NI_SigList[sigidx].signalname)+ 11, sizeof(char));
      if (strlen(NI_SigList[sigidx].signalname)>0) {
        sprintf(tempID,"%s:%d%s%s",NI_SigList[sigidx].blockname,
                NI_SigList[sigidx].portno+1,"/",NI_SigList[sigidx].signalname);
      } else {
        sprintf(tempID,"%s:%d",NI_SigList[sigidx].blockname,NI_SigList[sigidx].
                portno+1);
      }

      if ((int32_t)strlen(tempID)<*ID_len) {
        *ID_len = strlen(tempID);
      }

      strncpy(ID, tempID, *ID_len);
      free(tempID);
    }

    if (blkname != NULL) {
      /*  no need for return string to be null terminated! */
      if ((int32_t)strlen(NI_SigList[sigidx].blockname)<*bnlen) {
        *bnlen = strlen(NI_SigList[sigidx].blockname);
      }

      strncpy(blkname, NI_SigList[sigidx].blockname, *bnlen);
    }

    if (signame != NULL) {
      /* no need for return string to be null terminated! */
      if ((int32_t)strlen(NI_SigList[sigidx].signalname)<*snlen) {
        *snlen = strlen(NI_SigList[sigidx].signalname);
      }

      strncpy(signame, NI_SigList[sigidx].signalname, *snlen);
    }

    if (portnum != NULL) {
      *portnum = NI_SigList[sigidx].portno;
    }

    if (dattype != NULL) {
      *dattype = NI_SigList[sigidx].datatype;
    }

    if (numdim != NULL) {
      if (*numdim == -1) {
        *numdim = NI_SigList[sigidx].numofdims;
      } else if (dims != NULL) {
        for (i=0;i < *numdim; i++) {
          dims[i] = NI_SigDimList[NI_SigList[sigidx].dimListOffset +i];
        }
      }
    }

    return NI_OK;
  }

  return NI_SigListSize;
}

/*========================================================================*
 * Function: NIRT_GetParameterIndices
 *
 * Abstract:
 *	Returns an array of indices to tunable parameters
 *
 * Output Parameters:
 *	indices	: buffer to store the parameter indices of length "len"
 *	len		: returns the number of indices. If a value of "-1" is specified, the minimum buffer size of "indices" is returned as its value.
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetParameterIndices(int32_t* indices, int32_t* len)
{
  int32_t i;
  if ((len == NULL) || (indices == NULL)) {
    return NI_ERROR;
  }

  if (*len == -1) {
    *len = NI_ParamListSize;
  } else {
    for (i=0; (i < NI_ParamListSize) && (i < *len); i++) {
      indices[i] = NI_ParamList[i].idx;
    }

    *len = i;
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetParameterSpec
 *
 * Abstract:
 *	If index == -1, lookup parameter by the ID.
 *	If ID_len == 0 or if ID == null, return number of parameters in model.
 *	Otherwise, lookup parameter by index, and return the information.
 *
 * Input/Output Parameters:
 *	paramidx	: index of the parameter(in/out). If a value of "-1" is specified, the parameter's ID is used instead
 *	ID			: ID of parameter to be looked up (in), ID of parameter at index (out)
 *	ID_len		: length of input ID (in), length of ID (out)
 *	pnlen		: length of buffer paramname(in), length of the returned paramname (out)
 *	numdim		: length of buffer dimension(in), length of output dimension (out). If a value of "-1" is specified, the minimum buffer size of "dims" is returned as its value
 *
 * Output Parameters:
 *	paramname	: Name of the parameter
 *	datatype	: datatype of the parameter (currently assuming 0: double, .. )
 *	dims		: array of dimensions with length 'numdim'
 *
 * Returns:
 *	NI_OK if no error (if paramidx == -1, number of tunable parameters)
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetParameterSpec(int32_t* pidx, char* ID, int32_t*
  ID_len, char* paramname, int32_t *pnlen,
  int32_t *dattype, int32_t* dims, int32_t* numdim)
{
  int32_t i = 0;
  int32_t paramidx = *pidx;
  if (paramidx < 0) {
    /* check if ID has been specified. */
    if ((ID != NULL) && (ID_len != NULL) && (*ID_len > 0) ) {
      /*  lookup the table for matching ID */
      for (i=0; i < NI_ParamListSize; i++) {
        if (strcmp(ID,NI_ParamList[i].paramname) == 0) {
          /* found matching string */
          break;
        }
      }

      if (i < NI_ParamListSize) {
        /* note the index into the rtParamAttribs */
        paramidx = *pidx = i;
      } else {
        return NI_ParamListSize;
      }
    } else {
      /* no index or ID specified. */
      return NI_ParamListSize;
    }
  }

  if ((paramidx >= 0) && (paramidx<NI_ParamListSize)) {
    if (ID != NULL) {
      if ((int32_t)strlen(NI_ParamList[paramidx].paramname) < *ID_len) {
        *ID_len = strlen(NI_ParamList[paramidx].paramname);
      }

      strncpy(ID, NI_ParamList[paramidx].paramname, *ID_len);
    }

    if (paramname != NULL) {
      /* no need for return string to be null terminated! */
      if ((int32_t)strlen(NI_ParamList[paramidx].paramname) < *pnlen) {
        *pnlen = strlen(NI_ParamList[paramidx].paramname);
      }

      strncpy(paramname, NI_ParamList[paramidx].paramname, *pnlen);
    }

    if (dattype != NULL) {
      *dattype = NI_ParamList[paramidx].datatype;
    }

    if (numdim != NULL) {
      if (*numdim == -1) {
        *numdim = NI_ParamList[paramidx].numofdims;
      } else if (dims != NULL) {
        for (i = 0; i < *numdim; i++) {
          dims[i] = NI_ParamDimList[NI_ParamList[paramidx].dimListOffset + i];
        }
      }
    }

    return NI_OK;
  }

  return NI_ParamListSize;
}

/*========================================================================*
 * Function: NIRT_GetExtIOSpec
 *
 * Abstract:
 *	Returns the model's inport or outport specification
 *
 * Input Parameters:
 *	index	: index of the task
 *
 * Output Parameters:
 *	idx		: idx of the IO.
 *	name	: Name of the IO block
 *	tid		: task id
 *	type	: EXT_IN or EXT_OUT
 *	dims	: The port's dimension of length 'numdims'.
 *	numdims : the port's number of dimensions. If a value of "-1" is specified, the minimum buffer size of "dims" is returned as its value.
 *
 * Returns
 *	NI_OK if no error. (if index == -1, return number of tasks in the model)
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetExtIOSpec(int32_t index, int32_t *idx, char* name,
  int32_t* tid, int32_t *type, int32_t *dims, int32_t* numdims)
{
  if (index == -1) {
    return NI_ExtListSize;
  }

  if (idx != NULL) {
    *idx = NI_ExtList[index].idx;
  }

  if (name != NULL) {
    int32_t sz = strlen(name);
    strncpy(name, NI_ExtList[index].name, sz-1);
    name[sz-1]= 0;
  }

  if (tid != NULL) {
    *tid = NI_ExtList[index].TID;
  }

  if (type != NULL) {
    *type = NI_ExtList[index].type;
  }

  if (numdims != NULL) {
    if (*numdims == -1) {
      *numdims = 2;
    } else if (numdims != NULL) {
      /* Return port dimensions */
      dims[0] = NI_ExtList[index].dimX;
      dims[1] = NI_ExtList[index].dimY;
    }
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NI_ProbeOneSignal
 *
 * Abstract:
 *		Helper function to probe one signal. baseaddr must NOT be VIRTUAL_SIG
 *
 * Output Parameters
 *
 * Returns:
 *     Return value: Returns the last index value probed in a vector signal
 *========================================================================*/
static int32_t NI_ProbeOneSignal(int32_t idx, double *value, int32_t len,
  int32_t *count, int32_t vOffset, int32_t vLength)
{
  if (NI_SigList[idx].baseaddr == VIRTUAL_SIG) {
    SetSITErrorMessage("NI_ProbeOneSignal: Received request to probe a virtual signal, but was expecting a ground source. Ignoring virtual signal probe. Report this behavior to National Instruments.",
                       0);
    return 0;
  } else {
    char *ptr = (char*)((NI_SigList[idx].baseaddr == BLOCKIO_SIG) ? S->blockIO :
                        S->inputs) + (uintptr_t)NI_SigList[idx].addr;
    int32_t subindex = (vLength == -1) ? 0 : vOffset;
    int32_t sublength = (vLength == -1) ? NI_SigList[idx].width : (vLength +
      vOffset);
    while ((subindex < sublength) && (*count < len))
      value[(*count)++] = NIRT_GetValueByDataType(ptr, subindex++,
        NI_SigList[idx].datatype, NI_SigList[idx].IsComplex);
    return *count;
  }
}

/*========================================================================*
 * Function: NIRT_ProbeSignals
 *
 * Abstract:
 *	returns the latest signal values.
 *
 * Input Parameters:
 *	sigindices	: list of signal indices to be probed.
 *	numsigs		: length of sigindices array.
 *
 *		NOTE: (Implementation detail) the sigindices array that is passed in is delimited by a value of -1.
 *		Thus the # of valid indices in the sigindices table is min(numsigs, index of value -1) - 1.
 *		Reason for subtracting 1, the first index in the array is used for bookkeeping and should be copied
 *		into the 0th index in the signal values buffer.
 *		Also, the 1st index in the signal values buffer should contain the current timestamp. Hence valid
 *		signal data should be filled in starting from index 2. Any non-scalar signals should be added to the
 *		buffer in row-order.
 *
 * Input/Output Parameters
 *	num			: (in) length of sigvalues buffer (out) number of values returned in the buffer
 *
 * Output Parameters:
 *	value		: array of signal values
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_ProbeSignals(int32_t* sigindices, int32_t numsigs,
  double* value, int32_t* len)
{
  int32_t i = 0;
  int32_t idx = 0;
  int32_t count = 0;
  if (!SITexportglobals.inCriticalSection) {
    SetSITErrorMessage("SignalProbe should only be called between ScheduleTasks and PostOutputs",
                       1);
  }

  /* Get the index to the first signal */
  if ((*len > 1) && (numsigs > 0)) {
    value[count++] = sigindices[0];
    value[count++] = 0;
  }

  /* Get the second and other signals */
  for (i = 1; (i < numsigs) && (count < *len); i++) {
    idx = sigindices[i];
    if (idx < 0) {
      break;
    }

    if (idx < NI_SigListSize) {
      if (NI_SigList[idx].baseaddr == VIRTUAL_SIG) {
        int32_t vidx = NI_VirtualBlockSources[NI_SigList[idx].addr];
        NI_ProbeOneSignal(vidx, value, *len, &count, 0, -1);
      } else {
        NI_ProbeOneSignal(idx, value, *len, &count, 0, -1);
      }
    }
  }

  *len = count;
  return count;
}

int32_t NI_InitializeParamStruct()
{
  memcpy(&rtParameter[0], &simplePathFollow_P, sizeof(P_simplePathFollow_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka simplePathFollow_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int32_t NI_InitParamDoubleBuf()
{
  int32_t idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_simplePathFollow_T));
  return NI_OK;
}

static int32_t NI_SetParamTxStatus = NI_OK;

/*========================================================================*
 * Function: NIRT_SetParameter
 *
 * Abstract:
 *	Set parameter value. Called either in scheduler loop or a background loop.
 *
 * Input Parameters:
 *	index	: index of the parameter (as specified in Parameter Information)
 *	subindex: index in the flattened array, if parameter is n-D array
 *	val		: Value to set the parameter to
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetParameter(int32_t index, int32_t subindex, double
  value)
{
  char* ptr = NULL;

  /* Check bounds */
  if (index >= NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.", 1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  /* Commit parameter values */
  if (index < 0) {
    if (ReadSideDirtyFlag == 1) {
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
             (P_simplePathFollow_T));
      ReadSideDirtyFlag = 0;
      if (WriteSideDirtyFlag == 0) {
        /* No values to commit */
        return NI_OK;
      } else {
        SetSITErrorMessage("Parameters have been set inline and from the background loop at the same time. Parameters written from the background loop since the last commit have been lost.",
                           1);
        WriteSideDirtyFlag = 0;
        return NI_ERROR;
      }
    }

    /* If an error occurred and we have values to commit, then save to the write side and return error */
    if (NI_SetParamTxStatus == NI_ERROR) {
      /* fail the transaction.
         copy old list of parameters to the failed TX buffer */
      if (WriteSideDirtyFlag == 1) {
        memcpy(&rtParameter[READSIDE], &rtParameter[1-READSIDE], sizeof
               (P_simplePathFollow_T));
      }

      /* reset the status. */
      NI_SetParamTxStatus = NI_OK;
      WriteSideDirtyFlag = 0;
      return NI_ERROR;
    }

    /* If we have values to commit, then save to the write-side */
    if (WriteSideDirtyFlag == 1) {
      S->defaultParam = (double *)&rtParameter[1-READSIDE];
      WaitForSingleObject(SITexportglobals.flipCriticalSection, INFINITE);
      READSIDE = 1 - READSIDE;
      SITexportglobals.copyTaskBitfield = 0xFFFFFFFF;
      ReleaseSemaphore(SITexportglobals.flipCriticalSection, 1, NULL);

      /* Copy back the newly set parameters to the writeside. */
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
             (P_simplePathFollow_T));
      WriteSideDirtyFlag = 0;
    }

    return NI_OK;
  }

  /* verify that subindex is within bounds. */
  if (subindex >= NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_simplePathFollow_T));
    ReadSideDirtyFlag = 0;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[1-READSIDE]) + NI_ParamList[index].addr;
  WriteSideDirtyFlag = 1;

  /* Convert the incoming double datatype to the parameter's internal datatype and update value */
  return NIRT_SetValueByDataType(ptr, subindex, value, NI_ParamList[index].
    datatype, NI_ParamList[index].IsComplex);
}

/*========================================================================*
 * Function: NIRT_SetVectorParameter
 *
 * Abstract:
 *	Sets the value to a parameter array.
 *
 * Input Parameters:
 *	index		: index of the parameter as returned by NIRT_GetParameterSpec()
 *	paramvalues	: array of values to set
 *	paramlength	: Length of parameter values.
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetVectorParameter( uint32_t index, const double
  * paramvalues, uint32_t paramlength)
{
  uint32_t i = 0;
  int32_t retval = NI_OK;
  char* ptr = NULL;

  /* verify that index is within bounds*/
  if (index >= (uint32_t)NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  /* verify that subindex is within bounds. */
  if (paramlength != (uint32_t)NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter length is incorrect.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  /* If we have pending modified parameters, then copy to write-side */
  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_simplePathFollow_T));
    ReadSideDirtyFlag = 0;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char*)(&rtParameter[1-READSIDE]) + NI_ParamList[index].addr;
  while (i < paramlength) {
    /* Convert the incoming double datatype to the parameter's internal datatype and update value */
    retval = retval & NIRT_SetValueByDataType(ptr, i, paramvalues[i],
      NI_ParamList[index].datatype, NI_ParamList[index].IsComplex);
    i++;
  }

  WriteSideDirtyFlag = 1;
  return retval;
}

/*========================================================================*
 * Function: NIRT_SetScalarParameterInline
 *
 * Abstract:
 *	Sets the value to a parameter immediately without the need of a commit request.
 *
 * Input Parameters:
 *	index		: index of the parameter as returned by NIRT_GetParameterSpec()
 *	subindex	: offset of the element within the parameter
 *	paramvalue	: Value to set the parameter to
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetScalarParameterInline( uint32_t index, uint32_t
  subindex, double paramvalue)
{
  char* ptr = NULL;
  if (index >= (uint32_t)NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  /* verify that subindex is within bounds. */
  if (subindex >= (uint32_t)NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[READSIDE]) + NI_ParamList[index].addr;
  ReadSideDirtyFlag = 1;

  /* Convert the incoming double datatype to the parameter's internal datatype and update value */
  return NIRT_SetValueByDataType(ptr, subindex, paramvalue, NI_ParamList[index].
    datatype, NI_ParamList[index].IsComplex);
}

/*========================================================================*
 * Function: NIRT_GetParameter
 *
 * Abstract:
 *	Get the current value of a parameter.
 *
 * Input Parameters:
 *	index	: index of the parameter
 *	subindex: element index into the flattened array if an array
 *
 * Output Parameters:
 *	val		: value of the parameter
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetParameter(int32_t index, int32_t subindex, double
  *value)
{
  char* ptr = NULL;

  /* Check index boundaries */
  if (index >= NI_ParamListSize || index < 0 || (subindex>=NI_ParamList[index].
       width)) {
    return NI_ERROR;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[READSIDE]) + NI_ParamList[index].addr;

  /* Convert the parameter's internal datatype to double and return its value */
  *value = NIRT_GetValueByDataType(ptr, subindex, NI_ParamList[index].datatype,
    NI_ParamList[index].IsComplex);
  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetVectorParameter
 *
 * Abstract:
 *	Get the current value of a vector parameter.
 *
 * Input Parameters:
 *	index: index of the parameter
 *	paramLength: length of the parameter
 *
 * Output Parameters:
 *	paramValues: an array of the parameter's value
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetVectorParameter(uint32_t index, double* paramvalues,
  uint32_t paramlength)
{
  char* ptr = NULL;
  uint32_t i = 0;
  if (index >= (uint32_t)NI_ParamListSize || index < 0 || (paramlength !=
       (uint32_t)NI_ParamList[index].width)) {
    return NI_ERROR;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[READSIDE]) + NI_ParamList[index].addr;
  while (i<paramlength) {
    /* Convert the parameter's internal datatype to double and return its value */
    paramvalues[i] = NIRT_GetValueByDataType(ptr, i, NI_ParamList[index].
      datatype, NI_ParamList[index].IsComplex);
    i++;
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetSimState
 *
 * Abstract:
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetSimState(int32_t* numContStates, char
  * contStatesNames, double* contStates, int32_t* numDiscStates, char
  * discStatesNames, double* discStates, int32_t* numClockTicks, char
  * clockTicksNames, int32_t* clockTicks)
{
  int32_t count = 0;
  int32_t idx = 0;
  if ((numContStates != NULL) && (numDiscStates != NULL) && (numClockTicks !=
       NULL)) {
    if (*numContStates < 0 || *numDiscStates < 0 || *numClockTicks < 0) {
      *numContStates = 0;
      *numDiscStates = 82;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if ((discStates != NULL) && (discStatesNames != NULL)) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType
      (&simplePathFollow_DW.Integrator_DSTATE, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&simplePathFollow_DW.Integrator_DSTATE");
    discStates[idx] = NIRT_GetValueByDataType(&simplePathFollow_DW.Filter_DSTATE,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&simplePathFollow_DW.Filter_DSTATE");
    for (count = 0; count < 7; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&simplePathFollow_DW.vehLoIn1_DWORK1, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&simplePathFollow_DW.vehLoIn1_DWORK1");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&simplePathFollow_DW.missionFlagIn2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&simplePathFollow_DW.missionFlagIn2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&simplePathFollow_DW.steerAngleOut1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&simplePathFollow_DW.steerAngleOut1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&simplePathFollow_DW.offsetOut2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&simplePathFollow_DW.offsetOut2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&simplePathFollow_DW.Scope_PWORK,
      0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&simplePathFollow_DW.Scope_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&simplePathFollow_DW.Scope1_PWORK,
      0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&simplePathFollow_DW.Scope1_PWORK");
    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&simplePathFollow_DW.vehLoIn1_DWORK2, count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&simplePathFollow_DW.vehLoIn1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&simplePathFollow_DW.missionFlagIn2_DWORK2, count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&simplePathFollow_DW.missionFlagIn2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&simplePathFollow_DW.steerAngleOut1_DWORK2, count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&simplePathFollow_DW.steerAngleOut1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&simplePathFollow_DW.offsetOut2_DWORK2, count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&simplePathFollow_DW.offsetOut2_DWORK2");
    }
  }

  if ((clockTicks != NULL) && (clockTicksNames != NULL)) {
    clockTicks[0] = S->Timing.clockTick0;
    strcpy(clockTicksNames, "clockTick0");
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_SetSimState
 *
 * Abstract:
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetSimState(double* contStates, double* discStates,
  int32_t* clockTicks)
{
  int32_t count = 0;
  int32_t idx = 0;
  if (discStates != NULL) {
    idx = 0;
    NIRT_SetValueByDataType(&simplePathFollow_DW.Integrator_DSTATE, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&simplePathFollow_DW.Filter_DSTATE, 0,
      discStates[idx++], 0, 0);
    for (count = 0; count < 7; count++) {
      NIRT_SetValueByDataType(&simplePathFollow_DW.vehLoIn1_DWORK1, count,
        discStates[idx++], 24, 0);
    }

    NIRT_SetValueByDataType(&simplePathFollow_DW.missionFlagIn2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&simplePathFollow_DW.steerAngleOut1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&simplePathFollow_DW.offsetOut2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&simplePathFollow_DW.Scope_PWORK, 0, discStates[idx
      ++], 11, 0);
    NIRT_SetValueByDataType(&simplePathFollow_DW.Scope1_PWORK, 0, discStates[idx
      ++], 11, 0);
    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&simplePathFollow_DW.vehLoIn1_DWORK2, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&simplePathFollow_DW.missionFlagIn2_DWORK2, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&simplePathFollow_DW.steerAngleOut1_DWORK2, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&simplePathFollow_DW.offsetOut2_DWORK2, count,
        discStates[idx++], 23, 0);
    }
  }

  if (clockTicks != NULL) {
    S->Timing.clockTick0 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 /* of NI_ROOTMODEL_simplePathFollow */
