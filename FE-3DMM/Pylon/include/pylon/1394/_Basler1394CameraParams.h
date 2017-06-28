





//-----------------------------------------------------------------------------
//  (c) 2004-2008 by Basler Vision Technologies
//  Section: Vision Components
//  Project: GenApi
//-----------------------------------------------------------------------------
/*!
\file
\brief Basler 1394 camera interface
*/

//-----------------------------------------------------------------------------
//  This file is generated automatically
//  Do not modify!
//-----------------------------------------------------------------------------



#ifndef Basler_IIDC1394CameraParams_PARAMS_H
#define Basler_IIDC1394CameraParams_PARAMS_H

#ifdef __GNUC__
#define GENAPI_DEPRECATED_FEATURE __attribute__((deprecated))
#elif defined(_MSC_VER)
#define GENAPI_DEPRECATED_FEATURE __declspec(deprecated)
#else
#define GENAPI_DEPRECATED_FEATURE
#endif

#include <GenApi/IEnumerationT.h>
#include <GenApi/NodeMapRef.h>
#include <GenApi/DLLLoad.h>


// common node types
#include <GenApi/IBoolean.h>
#include <GenApi/ICategory.h>
#include <GenApi/ICommand.h>
#include <GenApi/IEnumeration.h>
#include <GenApi/IEnumEntry.h>
#include <GenApi/IFloat.h>
#include <GenApi/IInteger.h>
#include <GenApi/IString.h>
#include <GenApi/IRegister.h>


//! The namespace containing the device's control interface and related enumeration types
namespace Basler_IIDC1394CameraParams
{

    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************
    
    //! Valid values for GainAuto
    enum GainAutoEnums
    {
        GainAuto_Off,  //!<Disables the Gain Auto function.
        GainAuto_Once,  //!<Sets operation mode to 'once'.
        GainAuto_Continuous   //!<Sets operation mode to 'continuous'.
        
    };

    //! Valid values for GainSelector
    enum GainSelectorEnums
    {
        GainSelector_All,  //!<Selects all gain controls for adjustment
        GainSelector_Tap1,  //!<Selects the tap 1 gain control for adjustment
        GainSelector_Tap2   //!<Selects the tap 2 gain control for adjustment
        
    };

    //! Valid values for BlackLevelSelector
    enum BlackLevelSelectorEnums
    {
        BlackLevelSelector_All,  //!<Selects all black level controls for adjustment
        BlackLevelSelector_Tap1,  //!<Selects the tap 1 black level control for adjustment
        BlackLevelSelector_Tap2   //!<Selects the tap 2 black level control for adjustment
        
    };

    //! Valid values for GammaSelector
    enum GammaSelectorEnums
    {
        GammaSelector_User,  //!<Sets gamma to user defined curve
        GammaSelector_sRGB   //!<Sets gamma to fixed sRGB curve.
        
    };

    //! Valid values for PixelFormat
    enum PixelFormatEnums
    {
        PixelFormat_Mono8,  //!<Sets the pixel format to Mono 8
        PixelFormat_Mono1Packed,  //!<Sets the pixel format to Mono 1 Packed
        PixelFormat_Mono10,  //!<Sets the pixel format to Mono 10
        PixelFormat_Mono12,  //!<Sets the pixel format to Mono 12
        PixelFormat_Mono12Packed,  //!<Sets the pixel format to Mono 12 Packed
        PixelFormat_Mono16,  //!<Sets the pixel format to Mono 16
        PixelFormat_Mono2Packed,  //!<Sets the pixel format to Mono 2 Packed
        PixelFormat_Mono4Packed,  //!<Sets the pixel format to Mono 4 Packed
        PixelFormat_BayerGR8,  //!<Sets the pixel format to Bayer GR 8
        PixelFormat_BayerRG8,  //!<Sets the pixel format to Bayer RG 8
        PixelFormat_BayerGB8,  //!<Sets the pixel format to Bayer GB 8
        PixelFormat_BayerBG8,  //!<Sets the pixel format to Bayer BG 8
        PixelFormat_BayerGR10,  //!<Sets the pixel format to Bayer GR 10
        PixelFormat_BayerRG10,  //!<Sets the pixel format to Bayer RG 10
        PixelFormat_BayerGB10,  //!<Sets the pixel format to Bayer GB 10
        PixelFormat_BayerBG10,  //!<Sets the pixel format to Bayer BG 10
        PixelFormat_BayerGR12,  //!<Sets the pixel format to Bayer GR 12
        PixelFormat_BayerRG12,  //!<Sets the pixel format to Bayer RG 12
        PixelFormat_BayerGB12,  //!<Sets the pixel format to Bayer GB 12
        PixelFormat_BayerBG12,  //!<Sets the pixel format to Bayer BG 12
        PixelFormat_YUV422Packed,  //!<Sets the pixel format to YUV 422 Packed
        PixelFormat_YUV422_YUYV_Packed,  //!<Sets the pixel format to YUV 422 (YUYV) Packed
        PixelFormat_BayerGB12Packed,  //!<Sets the pixel format to Bayer GB 12 Packed
        PixelFormat_BayerGR12Packed,  //!<Sets the pixel format to Bayer GR 12 Packed
        PixelFormat_BayerRG12Packed,  //!<Sets the pixel format to Bayer RG 12 Packed
        PixelFormat_BayerBG12Packed,  //!<Sets the pixel format to Bayer BG 12 Packed
        PixelFormat_BayerGR16,  //!<Sets the pixel format to Bayer GR 16
        PixelFormat_BayerRG16,  //!<Sets the pixel format to Bayer RG 16
        PixelFormat_BayerGB16,  //!<Sets the pixel format to Bayer GB 16
        PixelFormat_BayerBG16   //!<Sets the pixel format to Bayer BG 16
        
    };

    //! Valid values for PixelSize
    enum PixelSizeEnums
    {
        PixelSize_Bpp1,  //!<Indicates that the depth of the pixel values in the acquired images is 1 bits per pixel
        PixelSize_Bpp2,  //!<Indicates that the depth of the pixel values in the acquired images is 2 bits per pixel
        PixelSize_Bpp4,  //!<Indicates that the depth of the pixel values in the acquired images is 4 bits per pixel
        PixelSize_Bpp8,  //!<Indicates that the depth of the pixel values in the acquired images is 8 bits per pixel
        PixelSize_Bpp10,  //!<Indicates that the depth of the pixel values in the acquired images is 10 bits per pixel
        PixelSize_Bpp12,  //!<Indicates that the depth of the pixel values in the acquired images is 12 bits per pixel
        PixelSize_Bpp16   //!<Indicates that the depth of the pixel values in the acquired images is 16 bits per pixel
        
    };

    //! Valid values for PixelColorFilter
    enum PixelColorFilterEnums
    {
        PixelColorFilter_Bayer_RG,  //!<Indicates that the Bayer filter has an RG/GB alignment to the pixels in the acquired images
        PixelColorFilter_Bayer_GB,  //!<Indicates that the Bayer filter has a GB/RG alignment to the pixels in the acquired images
        PixelColorFilter_Bayer_GR,  //!<Indicates that the Bayer filter has a GR/BG alignment to the pixels in the acquired images
        PixelColorFilter_Bayer_BG,  //!<Indicates that the Bayer filter has a BG/GR alignment to the pixels in the acquired images
        PixelColorFilter_None   //!<Indicates that no Bayer filter is present on the camera
        
    };

    //! Valid values for TestImageSelector
    enum TestImageSelectorEnums
    {
        TestImageSelector_Off,  //!<Sets the camera's test image generation capability to disabled
        TestImageSelector_Testimage1,  //!<Sets the camera to generate and transmit test images with a test image 1 pattern
        TestImageSelector_Testimage2,  //!<Sets the camera to generate and transmit test images with a test image 2 pattern
        TestImageSelector_Testimage3,  //!<Sets the camera to generate and transmit test images with a test image 3 pattern
        TestImageSelector_Testimage4,  //!<Sets the camera to generate and transmit test images with a test image 4 pattern
        TestImageSelector_Testimage5,  //!<Sets the camera to generate and transmit test images with a test image 5 pattern
        TestImageSelector_Testimage6   //!<Sets the camera to generate and transmit test images with a test image 6 pattern
        
    };

    //! Valid values for ColorTransformationSelector
    enum ColorTransformationSelectorEnums
    {
        ColorTransformationSelector_RGBtoRGB,  //!<Matrix color transformation from RGB to RGB.
        ColorTransformationSelector_RGBtoYUV,  //!<Matrix color transformation from YUV to RGB.
        ColorTransformationSelector_YUVtoRGB   //!<Matrix color transformation from RGB to YUV.
        
    };

    //! Valid values for LightSourceSelector
    enum LightSourceSelectorEnums
    {
        LightSourceSelector_Off,  //!<No matrix color transformation for specific light source is performed.
        LightSourceSelector_Custom,  //!<Allows using a custom defined color transformation matrix.
        LightSourceSelector_Daylight,  //!<The matrix is optimized for image acquisition with daylight of 5000 K.
        LightSourceSelector_Tungsten,  //!<The matrix is optimized for image acquisition with tungsten incandescent light (3100 K).
        LightSourceSelector_Daylight6500K,  //!<The matrix is optimized for image acquisition with daylight of 6500 K.
        LightSourceSelector_LightSource0,  //!<
        LightSourceSelector_LightSource1   //!<
        
    };

    //! Valid values for ColorTransformationValueSelector
    enum ColorTransformationValueSelectorEnums
    {
        ColorTransformationValueSelector_Gain00,  //!<Element in row 0 and column 0 of the color transformation matrix.
        ColorTransformationValueSelector_Gain01,  //!<Element in row 0 and column 1 of the color transformation matrix.
        ColorTransformationValueSelector_Gain02,  //!<Element in row 0 and column 2 of the color transformation matrix.
        ColorTransformationValueSelector_Gain10,  //!<Element in row 1 and column 0 of the color transformation matrix.
        ColorTransformationValueSelector_Gain11,  //!<Element in row 1 and column 1 of the color transformation matrix
        ColorTransformationValueSelector_Gain12,  //!<Element in row 1 and column 2 of the color transformation matrix.
        ColorTransformationValueSelector_Gain20,  //!<Element in row 2 and column 0 of the color transformation matrix.
        ColorTransformationValueSelector_Gain21,  //!<Element in row 2 and column 1 of the color transformation matrix.
        ColorTransformationValueSelector_Gain22   //!<Element in row 2 and column 2 of the color transformation matrix.
        
    };

    //! Valid values for ColorAdjustmentSelector
    enum ColorAdjustmentSelectorEnums
    {
        ColorAdjustmentSelector_Red,  //!<Selects red for the adjustment of colors with predominant red.
        ColorAdjustmentSelector_Yellow,  //!<Selects yellow for the adjustment of colors with predominant yellow.
        ColorAdjustmentSelector_Green,  //!<Selects green the adjustment of colors with predominant green.
        ColorAdjustmentSelector_Cyan,  //!<Selects cyan for the adjustment of colors with predominant cyan.
        ColorAdjustmentSelector_Blue,  //!<Selects blue for the adjustment of colors with predominant blue.
        ColorAdjustmentSelector_Magenta   //!<Selects magenta for the adjustment of colors with predominant magenta.
        
    };

    //! Valid values for BalanceWhiteAuto
    enum BalanceWhiteAutoEnums
    {
        BalanceWhiteAuto_Off,  //!<Disables the Balance White Auto function.
        BalanceWhiteAuto_Once,  //!<Sets operation mode to 'once'.
        BalanceWhiteAuto_Continuous   //!<Sets operation mode to 'continuous'.
        
    };

    //! Valid values for BalanceRatioSelector
    enum BalanceRatioSelectorEnums
    {
        BalanceRatioSelector_Red,  //!<Selects the red balance ratio control for adjustment
        BalanceRatioSelector_Green,  //!<Selects the green balance ratio control for adjustment
        BalanceRatioSelector_Blue   //!<Selects the blue balance ratio control for adjustment
        
    };

    //! Valid values for LegacyBinningVertical
    enum LegacyBinningVerticalEnums
    {
        LegacyBinningVertical_Off,  //!<Sets vertical binning to disabled
        LegacyBinningVertical_Two_Rows   //!<Sets vertical binning to 2 rows
        
    };

    //! Valid values for AcquisitionMode
    enum AcquisitionModeEnums
    {
        AcquisitionMode_SingleFrame,  //!<Sets the acquisition mode to single frame
        AcquisitionMode_Continuous   //!<Sets the acquisition mode to continuous
        
    };

    //! Valid values for TriggerControlImplementation
    enum TriggerControlImplementationEnums
    {
        TriggerControlImplementation_Legacy,  //!<
        TriggerControlImplementation_Standard   //!<
        
    };

    //! Valid values for TriggerSelector
    enum TriggerSelectorEnums
    {
        TriggerSelector_AcquisitionStart,  //!<Selects the acquisition start trigger for configuration
        TriggerSelector_FrameStart   //!<Selects the frame start trigger for configuration
        
    };

    //! Valid values for TriggerMode
    enum TriggerModeEnums
    {
        TriggerMode_Off,  //!<Sets the mode for the selected trigger to off
        TriggerMode_On   //!<Sets the mode for the selected trigger to on
        
    };

    //! Valid values for TriggerSource
    enum TriggerSourceEnums
    {
        TriggerSource_Software,  //!<Sets the software trigger as the signal source for the selected trigger
        TriggerSource_Line1,  //!<Sets the signal source for the selected trigger to line 1
        TriggerSource_Line2,  //!<Sets the signal source for the selected trigger to line 2
        TriggerSource_Line3,  //!<Sets the signal source for the selected trigger to line 3
        TriggerSource_Line4   //!<Sets the signal source for the selected trigger to line 4
        
    };

    //! Valid values for TriggerActivation
    enum TriggerActivationEnums
    {
        TriggerActivation_RisingEdge,  //!<Sets the selected trigger to become active on the rising edge of the source signal
        TriggerActivation_FallingEdge   //!<Sets the selected trigger to become active on the falling edge of the source signal
        
    };

    //! Valid values for ExposureAuto
    enum ExposureAutoEnums
    {
        ExposureAuto_Off,  //!<Disables the Exposure Auto function.
        ExposureAuto_Once,  //!<Sets operation mode to 'once'.
        ExposureAuto_Continuous   //!<Sets operation mode to 'continuous'.
        
    };

    //! Valid values for ExposureMode
    enum ExposureModeEnums
    {
        ExposureMode_Timed,  //!<Sets the exposure mode to timed
        ExposureMode_TriggerWidth   //!<Sets the exposure mode to trigger width
        
    };

    //! Valid values for AcquisitionStatusSelector
    enum AcquisitionStatusSelectorEnums
    {
        AcquisitionStatusSelector_AcquisitionTriggerWait,  //!<Device is currently waiting for a trigger for the capture of one or many frames.
        AcquisitionStatusSelector_AcquisitionActive,  //!<Device is currently doing an acquisition of one or many frames.
        AcquisitionStatusSelector_AcquisitionTransfer,  //!<Device is currently transferring an acquisition of one or many frames.
        AcquisitionStatusSelector_FrameTriggerWait,  //!<Device is currently waiting for a Frame trigger.
        AcquisitionStatusSelector_FrameActive,  //!<Device is currently doing the capture of a frame.
        AcquisitionStatusSelector_FrameTransfer,  //!<Device is currently transferring a frame.
        AcquisitionStatusSelector_ExposureActive   //!<Device is doing the exposure of a frame.
        
    };

    //! Valid values for LineSelector
    enum LineSelectorEnums
    {
        LineSelector_Line1,  //!<Selects line 1 for configuration
        LineSelector_Line2,  //!<Selects line 2 for configuration
        LineSelector_Out1,  //!<Selects output line 1 for configuration
        LineSelector_Out2,  //!<Selects output line 2 for configuration
        LineSelector_Out3,  //!<Selects output line 3 for configuration
        LineSelector_Out4   //!<Selects output line 4 for configuration
        
    };

    //! Valid values for LineMode
    enum LineModeEnums
    {
        LineMode_Input,  //!<Sets the mode for the selected line to input
        LineMode_Output   //!<Sets the mode for the selected line to output
        
    };

    //! Valid values for LineSource
    enum LineSourceEnums
    {
        LineSource_ExposureActive,  //!<Sets the source signal for the selected output line to exposure active
        LineSource_TimerActive,  //!<
        LineSource_UserOutput,  //!<
        LineSource_TriggerReady,  //!<
        LineSource_SerialTx,  //!<
        LineSource_AcquisitionTriggerReady   //!<
        
    };

    //! Valid values for LineLogic
    enum LineLogicEnums
    {
        LineLogic_Positive,  //!<
        LineLogic_Negative   //!<
        
    };

    //! Valid values for LineFormat
    enum LineFormatEnums
    {
        LineFormat_OptoCoupled   //!<Sets the electrical configuration of the selected line to opto-coupled
        
    };

    //! Valid values for UserOutputSelector
    enum UserOutputSelectorEnums
    {
        UserOutputSelector_UserOutput1,  //!<Selects user settable output signal 1 for configuration
        UserOutputSelector_UserOutput2,  //!<Selects user settable output signal 2 for configuration
        UserOutputSelector_UserOutput3,  //!<Selects user settable output signal 3 for configuration
        UserOutputSelector_UserOutput4   //!<Selects user settable output signal 4 for configuration
        
    };

    //! Valid values for TimerSelector
    enum TimerSelectorEnums
    {
        TimerSelector_Timer1,  //!<Selects timer 1 for configuration
        TimerSelector_Timer2,  //!<Selects timer 2 for configuration
        TimerSelector_Timer3,  //!<Selects timer 3 for configuration
        TimerSelector_Timer4   //!<Selects timer 4 for configuration
        
    };

    //! Valid values for TimerTriggerSource
    enum TimerTriggerSourceEnums
    {
        TimerTriggerSource_ExposureStart   //!<Sets the source signal for the selected timer to exposure active
        
    };

    //! Valid values for TimerTriggerActivation
    enum TimerTriggerActivationEnums
    {
        TimerTriggerActivation_RisingEdge,  //!<Sets the type of signal change that will start the timer to rising edge
        TimerTriggerActivation_FallingEdge   //!<Sets the type of signal change that will start the timer to falling edge
        
    };

    //! Valid values for TimerSequenceEntrySelector
    enum TimerSequenceEntrySelectorEnums
    {
        TimerSequenceEntrySelector_Entry1,  //!<
        TimerSequenceEntrySelector_Entry2,  //!<
        TimerSequenceEntrySelector_Entry3,  //!<
        TimerSequenceEntrySelector_Entry4,  //!<
        TimerSequenceEntrySelector_Entry5,  //!<
        TimerSequenceEntrySelector_Entry6,  //!<
        TimerSequenceEntrySelector_Entry7,  //!<
        TimerSequenceEntrySelector_Entry8,  //!<
        TimerSequenceEntrySelector_Entry9,  //!<
        TimerSequenceEntrySelector_Entry10,  //!<
        TimerSequenceEntrySelector_Entry11,  //!<
        TimerSequenceEntrySelector_Entry12,  //!<
        TimerSequenceEntrySelector_Entry13,  //!<
        TimerSequenceEntrySelector_Entry14,  //!<
        TimerSequenceEntrySelector_Entry15,  //!<
        TimerSequenceEntrySelector_Entry16   //!<
        
    };

    //! Valid values for TimerSequenceTimerSelector
    enum TimerSequenceTimerSelectorEnums
    {
        TimerSequenceTimerSelector_Timer1,  //!<
        TimerSequenceTimerSelector_Timer2,  //!<
        TimerSequenceTimerSelector_Timer3,  //!<
        TimerSequenceTimerSelector_Timer4   //!<
        
    };

    //! Valid values for CounterSelector
    enum CounterSelectorEnums
    {
        CounterSelector_Counter1,  //!<Selects counter 1 for configuration
        CounterSelector_Counter2   //!<Selects counter 2 for configuration
        
    };

    //! Valid values for CounterEventSource
    enum CounterEventSourceEnums
    {
        CounterEventSource_FrameTrigger,  //!<Counts the number of Frame Trigger
        CounterEventSource_FrameStart   //!<Counts the number of Frame Start
        
    };

    //! Valid values for CounterResetSource
    enum CounterResetSourceEnums
    {
        CounterResetSource_Off,  //!<Disables counter reset
        CounterResetSource_Software,  //!<Selects software command as the source for counter reset
        CounterResetSource_Line1,  //!<Selects line 1 as the source for counter reset
        CounterResetSource_Line2   //!<Selects line 2 as the source for counter reset
        
    };

    //! Valid values for LUTSelector
    enum LUTSelectorEnums
    {
        LUTSelector_Luminance   //!<Selects the luminance LUT for configuration
        
    };

    //! Valid values for UserSetSelector
    enum UserSetSelectorEnums
    {
        UserSetSelector_Default,  //!<Selects the default configuration set
        UserSetSelector_UserSet1,  //!<Selects user set 1
        UserSetSelector_UserSet2,  //!<Selects user set 2
        UserSetSelector_UserSet3   //!<Selects user set 3
        
    };

    //! Valid values for UserSetDefaultSelector
    enum UserSetDefaultSelectorEnums
    {
        UserSetDefaultSelector_Default,  //!<Selects the default user set as the default startup set
        UserSetDefaultSelector_UserSet1,  //!<Selects user set 1 as the default startup set
        UserSetDefaultSelector_UserSet2,  //!<Selects user set 2 as the default startup set
        UserSetDefaultSelector_UserSet3   //!<Selects user set 3 as the default startup set
        
    };

    //! Valid values for DefaultSetSelector
    enum DefaultSetSelectorEnums
    {
        DefaultSetSelector_Standard,  //!<Standard factory set
        DefaultSetSelector_HighGain,  //!<High gain factory set
        DefaultSetSelector_AutoFunctions,  //!<Factory set using auto functions
        DefaultSetSelector_Color,  //!<Factory set enabling color adjustments
        DefaultSetSelector_Custom0,  //!<customer factory set 0
        DefaultSetSelector_Custom1   //!<customer factory set 1
        
    };

    //! Valid values for AutoFunctionProfile
    enum AutoFunctionProfileEnums
    {
        AutoFunctionProfile_GainMinimum,  //!<Keep gain at minimum
        AutoFunctionProfile_ExposureMinimum   //!<Exposure Time at minimum
        
    };

    //! Valid values for AutoFunctionAOISelector
    enum AutoFunctionAOISelectorEnums
    {
        AutoFunctionAOISelector_AOI1,  //!<Selects Auto Function AOI 1
        AutoFunctionAOISelector_AOI2   //!<Selects Auto Function AOI 2
        
    };

    //! Valid values for UserDefinedValueSelector
    enum UserDefinedValueSelectorEnums
    {
        UserDefinedValueSelector_Value1,  //!<
        UserDefinedValueSelector_Value2,  //!<
        UserDefinedValueSelector_Value3,  //!<
        UserDefinedValueSelector_Value4,  //!<
        UserDefinedValueSelector_Value5   //!<
        
    };

    //! Valid values for DeviceScanType
    enum DeviceScanTypeEnums
    {
        DeviceScanType_Areascan,  //!<Indicates that the device has an area scan type of sensor
        DeviceScanType_Linescan   //!<Indicates that the device has an Line scan type of sensor
        
    };

    //! Valid values for TemperatureSelector
    enum TemperatureSelectorEnums
    {
        TemperatureSelector_Sensorboard,  //!<Temperature on sensor board
        TemperatureSelector_Coreboard,  //!<Temperature on core board
        TemperatureSelector_Framegrabberboard,  //!<Temperature on framegrabber board
        TemperatureSelector_Case   //!<Temperature on the camera case
        
    };

    //! Valid values for ParameterSelector
    enum ParameterSelectorEnums
    {
        ParameterSelector_Gain,  //!<Selects the gain limits for configuration
        ParameterSelector_Brightness,  //!<Selects the brightness limits for configuration
        ParameterSelector_ExposureTime   //!<Selects the exposure time limits for configuration
        
    };

    //! Valid values for ExpertFeatureAccessSelector
    enum ExpertFeatureAccessSelectorEnums
    {
        ExpertFeatureAccessSelector_ExpertFeature1_Legacy,  //!<Selects the Expert Feature 1 for configuration
        ExpertFeatureAccessSelector_ExpertFeature1,  //!<Selects the Expert Feature 1 for configuration
        ExpertFeatureAccessSelector_ExpertFeature2,  //!<Selects the Expert Feature 2 for configuration
        ExpertFeatureAccessSelector_ExpertFeature3,  //!<Selects the Expert Feature 3 for configuration
        ExpertFeatureAccessSelector_ExpertFeature4,  //!<Selects the Expert Feature 4 for configuration
        ExpertFeatureAccessSelector_ExpertFeature5   //!<Selects the Expert Feature 5 for configuration
        
    };

    //! Valid values for ChunkSelector
    enum ChunkSelectorEnums
    {
        ChunkSelector_Image,  //!<Selects the image chunk for enabling.
        ChunkSelector_OffsetX,  //!<Selects the X offset chunk for enabling.
        ChunkSelector_OffsetY,  //!<Selects the Y offset chunk for enabling.
        ChunkSelector_Width,  //!<Selects the width chunk for enabling.
        ChunkSelector_Height,  //!<Selects the height chunk for enabling.
        ChunkSelector_PixelFormat,  //!<Selects the pixel format chunk for enabling.
        ChunkSelector_DynamicRangeMax,  //!<Selects the dynamic range max chunk for enabling.
        ChunkSelector_DynamicRangeMin,  //!<Selects the dynamic range min chunk for enabling.
        ChunkSelector_Timestamp,  //!<Selects the timestamp chunk for enabling.
        ChunkSelector_LineStatusAll,  //!<Selects the line status all chunk for enabling.
        ChunkSelector_Framecounter,  //!<Selects the frame counter chunk for enabling.
        ChunkSelector_Triggerinputcounter,  //!<Selects the trigger input counter chunk for enabling.
        ChunkSelector_PayloadCRC16,  //!<Selects the CRC checksum chunk for configuration
        ChunkSelector_Stride,  //!<Selects the stride chunk for enabling.
        ChunkSelector_ExposureTime   //!<
        
    };

    //! Valid values for ChunkPixelFormat
    enum ChunkPixelFormatEnums
    {
        ChunkPixelFormat_Mono8,  //!<Indicates that the pixel data in the acquired image is in the Mono 8 format
        ChunkPixelFormat_Mono8Signed,  //!<Indicates that the pixel data in the acquired image is in the Mono 8 signed format
        ChunkPixelFormat_Mono10,  //!<Indicates that the pixel data in the acquired image is in the Mono 10 format
        ChunkPixelFormat_Mono10Packed,  //!<Indicates that the pixel data in the acquired image is in the Mono 10 Packed format
        ChunkPixelFormat_Mono12,  //!<Indicates that the pixel data in the acquired image is in the Mono 12 format
        ChunkPixelFormat_Mono12Packed,  //!<Indicates that the pixel data in the acquired image is in the Mono 12 Packed format
        ChunkPixelFormat_Mono16,  //!<Indicates that the pixel data in the acquired image is in the Mono 16 format
        ChunkPixelFormat_BayerGR8,  //!<Indicates that the pixel data in the acquired image is in the Bayer GR 8 format
        ChunkPixelFormat_BayerRG8,  //!<Indicates that the pixel data in the acquired image is in the Bayer RG 8 format
        ChunkPixelFormat_BayerGB8,  //!<Indicates that the pixel data in the acquired image is in the Bayer GB 8 format
        ChunkPixelFormat_BayerBG8,  //!<Indicates that the pixel data in the acquired image is in the Bayer BG 8 format
        ChunkPixelFormat_BayerGR10,  //!<Indicates that the pixel data in the acquired image is in the Bayer GR 10 format
        ChunkPixelFormat_BayerRG10,  //!<Indicates that the pixel data in the acquired image is in the Bayer RG 10 format
        ChunkPixelFormat_BayerGB10,  //!<Indicates that the pixel data in the acquired image is in the Bayer GB 10 format
        ChunkPixelFormat_BayerBG10,  //!<Indicates that the pixel data in the acquired image is in the Bayer BG 10 format
        ChunkPixelFormat_BayerGR12,  //!<Indicates that the pixel data in the acquired image is in the Bayer GR 12 format
        ChunkPixelFormat_BayerRG12,  //!<Indicates that the pixel data in the acquired image is in the Bayer RG 12 format
        ChunkPixelFormat_BayerGB12,  //!<Indicates that the pixel data in the acquired image is in the Bayer GB 12 format
        ChunkPixelFormat_BayerBG12,  //!<Indicates that the pixel data in the acquired image is in the Bayer BG 12 format
        ChunkPixelFormat_BayerGR16,  //!<Indicates that the pixel data in the acquired image is in the Bayer GR 16 format
        ChunkPixelFormat_BayerRG16,  //!<Indicates that the pixel data in the acquired image is in the Bayer RG 16 format
        ChunkPixelFormat_BayerGB16,  //!<Indicates that the pixel data in the acquired image is in the Bayer GB 16 format
        ChunkPixelFormat_BayerBG16,  //!<Indicates that the pixel data in the acquired image is in the Bayer BG 16 format
        ChunkPixelFormat_RGB8Packed,  //!<Indicates that the pixel data in the acquired image is in the RGB 8 Packed format
        ChunkPixelFormat_BGR8Packed,  //!<Indicates that the pixel data in the acquired image is in the BGR 8 Packed format
        ChunkPixelFormat_RGBA8Packed,  //!<Indicates that the pixel data in the acquired image is in the RGBA 8 Packed format
        ChunkPixelFormat_BGRA8Packed,  //!<Indicates that the pixel data in the acquired image is in the BGRA 8 Packed format
        ChunkPixelFormat_RGB10Packed,  //!<Indicates that the pixel data in the acquired image is in the RGB 10 Packed format
        ChunkPixelFormat_BGR10Packed,  //!<Indicates that the pixel data in the acquired image is in the BGR 10 Packed format
        ChunkPixelFormat_RGB12Packed,  //!<Indicates that the pixel data in the acquired image is in the RGB 12 Packed format
        ChunkPixelFormat_BGR12Packed,  //!<Indicates that the pixel data in the acquired image is in the BGR 12 Packed format
        ChunkPixelFormat_RGB10V1Packed,  //!<Indicates that the pixel data in the acquired image is in the RGB 10V1 Packed format
        ChunkPixelFormat_RGB10V2Packed,  //!<Indicates that the pixel data in the acquired image is in the RGB 10V2 Packed format
        ChunkPixelFormat_YUV411Packed,  //!<Indicates that the pixel data in the acquired image is in the YUV 411 Packed format
        ChunkPixelFormat_YUV422Packed,  //!<Indicates that the pixel data in the acquired image is in the YUV 422 Packed format
        ChunkPixelFormat_YUV444Packed,  //!<Indicates that the pixel data in the acquired image is in the YUV 444 Packed format
        ChunkPixelFormat_RGB8Planar,  //!<Indicates that the pixel data in the acquired image is in the RGB 8 Planar format
        ChunkPixelFormat_RGB10Planar,  //!<Indicates that the pixel data in the acquired image is in the RGB 10 Planar format
        ChunkPixelFormat_RGB12Planar,  //!<Indicates that the pixel data in the acquired image is in the RGB 12 Planar format
        ChunkPixelFormat_RGB16Planar,  //!<Indicates that the pixel data in the acquired image is in the RGB 16 Planar format
        ChunkPixelFormat_YUV422_YUYV_Packed,  //!<Indicates that the pixel data in the acquired image is in the YUV 422 (YUYV) Packed format
        ChunkPixelFormat_BayerGB12Packed,  //!<Indicates that the pixel data in the acquired image is in the Bayer GB 12 Packed format
        ChunkPixelFormat_BayerGR12Packed,  //!<Indicates that the pixel data in the acquired image is in the Bayer GR 12 Packed format
        ChunkPixelFormat_BayerRG12Packed,  //!<Indicates that the pixel data in the acquired image is in the Bayer RG 12 Packed format
        ChunkPixelFormat_BayerBG12Packed,  //!<Indicates that the pixel data in the acquired image is in the Bayer BG 12 Packed format
        ChunkPixelFormat_RGB12V1Packed   //!<Indicates that the pixel data in the acquired image is in RGB 12 Packed 
        
    };

    //! Valid values for EventSelector
    enum EventSelectorEnums
    {
        EventSelector_ExposureEnd,  //!<Selects the end of exposure event for enabling.
        EventSelector_FrameStartOvertrigger,  //!<Selects the frame start overtrigger event for enabling.
        EventSelector_AcquisitionStartOvertrigger,  //!<Selects the acquisition start overtrigger event for enabling.
        EventSelector_FrameStart,  //!<Selects the frame start trigger event for enabling.
        EventSelector_AcquisitionStart,  //!<Selects the acquisition start trigger event for enabling.
        EventSelector_EventOverrun   //!<Selects the event overrun event for enabling.
        
    };

    //! Valid values for EventNotification
    enum EventNotificationEnums
    {
        EventNotification_Off,  //!<Sets event notification to off
        EventNotification_GenICamEvent,  //!<Sets the event notification type to GenICam event
        EventNotification_On   //!<Sets the enables the event notification.
        
    };

    //! Valid values for FileSelector
    enum FileSelectorEnums
    {
        FileSelector_UserData,  //!<Selects the file 'User Data'
        FileSelector_UserSet1,  //!<Selects the file 'User Set 1'
        FileSelector_UserSet2,  //!<Selects the file 'User Set 2'
        FileSelector_UserSet3,  //!<Selects the file 'User Set 3'
        FileSelector_UserGainShading1,  //!<Selects the file 'User Gain Shading 1'
        FileSelector_UserGainShading2   //!<Selects the file 'User Gain Shading 2'
        
    };

    //! Valid values for FileOperationSelector
    enum FileOperationSelectorEnums
    {
        FileOperationSelector_Open,  //!<Opens the file selected by FileSelector
        FileOperationSelector_Close,  //!<Closes the file selected by FileSelector
        FileOperationSelector_Read,  //!<Reads data from the selected file
        FileOperationSelector_Write   //!<Writes data to the selected file
        
    };

    //! Valid values for FileOpenMode
    enum FileOpenModeEnums
    {
        FileOpenMode_Read,  //!<Selects read-only open mode
        FileOpenMode_Write   //!<Selects write-only open mode
        
    };

    //! Valid values for FileOperationStatus
    enum FileOperationStatusEnums
    {
        FileOperationStatus_Success,  //!<Successful file operation
        FileOperationStatus_Failure   //!<Failing file operation
        
    };

    //! Valid values for ServiceBoardIdSelector
    enum ServiceBoardIdSelectorEnums
    {
        ServiceBoardIdSelector_Coreboard,  //!<
        ServiceBoardIdSelector_Sensorboard,  //!<
        ServiceBoardIdSelector_Framegrabberboard,  //!<
        ServiceBoardIdSelector_Global   //!<
        
    };


    //**************************************************************************************************
    // Parameter class
    //**************************************************************************************************
    

    //! Basler 1394 camera interface
    class CIIDC1394CameraParams_Params
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            CIIDC1394CameraParams_Params(void);

            //! Destructor
            ~CIIDC1394CameraParams_Params(void);

            //! Initializes the references
            void _Initialize(GenApi::INodeMap*);

            //! Return the vendor of the camera
            const char* _GetVendorName(void);

            //! Returns the camera model name
            const char* _GetModelName(void);
        
        //! \endcond

    //----------------------------------------------------------------------------------------------------------------
    // References to features
    //----------------------------------------------------------------------------------------------------------------
    public:
        
    //! \name AnalogControls - This category includes items that control the analog characteristics of the video signal
    //@{
    /*!
        \brief Gain Auto is the 'automatic' counterpart of the manual gain feature.

        The gain auto function automatically adjusts the Auto Gain Raw parameter value within set limits, until a target average gray value for the pixel data from Auto Function AOI1 is reached.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<GainAutoEnums > &GainAuto;
    
    //@}
    

    //! \name AnalogControls - This category includes items that control the analog characteristics of the video signal
    //@{
    /*!
        \brief This is an integer value that sets the selected gain control in device specific units

        Sets the 'raw' value of the selected gain control. The 'raw' value is an integer value that sets the selected gain control in units specific to the camera.
    
        \b Visibility = Beginner
        
    
        \b Selected by : GainSelector
    
    */
    GenApi::IInteger &GainRaw;
    
    //@}
    

    //! \name AnalogControls - This category includes items that control the analog characteristics of the video signal
    //@{
    /*!
        \brief Selects the gain control to configure. Once a gain control has been selected, all changes to the gain settings will be applied to the selected control.

        This enumeration selects the gain control to configure. Once a gain control has been selected, all changes to the gain settings will be applied to the selected control.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<GainSelectorEnums > &GainSelector;
    
    //@}
    

    //! \name AnalogControls - This category includes items that control the analog characteristics of the video signal
    //@{
    /*!
        \brief Sets the value of the selected black level control as an integer

        This value sets the selected black level control as an integer.
    
        \b Visibility = Beginner
        
    
        \b Selected by : BlackLevelSelector
    
    */
    GenApi::IInteger &BlackLevelRaw;
    
    //@}
    

    //! \name AnalogControls - This category includes items that control the analog characteristics of the video signal
    //@{
    /*!
        \brief Selcts a black level control to configure. Once a black level control has been selected, all changes to the black level settings will be applied to the selected control.

        This enumeration selects the black level control to configure. Once a black level control has been selected, all changes to the black level settings will be applied to the selected control.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<BlackLevelSelectorEnums > &BlackLevelSelector;
    
    //@}
    

    //! \name AnalogControls - This category includes items that control the analog characteristics of the video signal
    //@{
    /*!
        \brief Enables the gamma correction

        This boolean value enables the gamma correction.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IBoolean &GammaEnable;
    
    //@}
    

    //! \name AnalogControls - This category includes items that control the analog characteristics of the video signal
    //@{
    /*!
        \brief 

        This enumeration selects the type of gamma to apply.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<GammaSelectorEnums > &GammaSelector;
    
    //@}
    

    //! \name AnalogControls - This category includes items that control the analog characteristics of the video signal
    //@{
    /*!
        \brief This feature is used to perform gamma correction of pixel intensity.

        This feature is used to perform gamma correction of pixel  intensity. This is typically used to compensate for non-linearity of the display system (such as CRT).
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IFloat &Gamma;
    
    //@}
    

    //! \name AnalogControls - This category includes items that control the analog characteristics of the video signal
    //@{
    /*!
        \brief Sets the value of the selected digital shift control

        This value sets the selected digital shift control
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &DigitalShift;
    
    //@}
    

    //! \name AnalogControls - This category includes items that control the analog characteristics of the video signal
    //@{
    /*!
        \brief Sets the substrate voltage

        This value sets the substrate voltage
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &SubstrateVoltage;
    
    //@}
    

    //! \name ImageFormat - This category includes items that control the size of the acquired image and the format of the transferred pixel data
    //@{
    /*!
        \brief Sets the format of the pixel data transmitted for acquired images

        This enumeration sets the format of the pixel data transmitted for acquired images. 
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<PixelFormatEnums > &PixelFormat;
    
    //@}
    

    //! \name ImageFormat - This category includes items that control the size of the acquired image and the format of the transferred pixel data
    //@{
    /*!
        \brief Indicates the depth of the pixel values in the image in bits per pixel

        This is a read only feature. This enumeration provides a list of values that indicate the depth of the pixel values in the acquired images in bits per pixel. This value will always be coherent with the pixel format setting.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<PixelSizeEnums > &PixelSize;
    
    //@}
    

    //! \name ImageFormat - This category includes items that control the size of the acquired image and the format of the transferred pixel data
    //@{
    /*!
        \brief Indicates the alignment of the camera's Bayer filter to the pixels in the acquired images

         This is a read only feature. This enumeration provides a list of values that indicate the alignment of the camera's Bayer filter to the pixels in the acquired images.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<PixelColorFilterEnums > &PixelColorFilter;
    
    //@}
    

    //! \name ImageFormat - This category includes items that control the size of the acquired image and the format of the transferred pixel data
    //@{
    /*!
        \brief Enables color improved RGB raw output

        Enables color improvement of RGB data and provides for their output as RGB raw data. Only available for cameras with an RGB Bayer filter.
Note: Make sure to also select a suitable raw pixel data output format.
    
        \b Visibility = Expert
    
    */
    GenApi::IBoolean &ProcessedRawEnable;
    
    //@}
    

    //! \name ImageFormat - This category includes items that control the size of the acquired image and the format of the transferred pixel data
    //@{
    /*!
        \brief Enables the horizontal flipping of the image.

        This feature is used to flip horizontally the image sent by the device. The AOI is applied after the flipping.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IBoolean &ReverseX;
    
    //@}
    

    //! \name ImageFormat - This category includes items that control the size of the acquired image and the format of the transferred pixel data
    //@{
    /*!
        \brief Enables the vertical flipping of the image.

        This feature is used to flip vertically the image sent by the device. The AOI is applied after the flipping.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IBoolean &ReverseY;
    
    //@}
    

    //! \name ImageFormat - This category includes items that control the size of the acquired image and the format of the transferred pixel data
    //@{
    /*!
        \brief Indicates the minimum possible pixel value that could be transferred from the camera

        This a read only feature. It indicates the minimum possible pixel value that could be transferred from the camera.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &PixelDynamicRangeMin;
    
    //@}
    

    //! \name ImageFormat - This category includes items that control the size of the acquired image and the format of the transferred pixel data
    //@{
    /*!
        \brief Indicates the maximum possible pixel value that could be transferred from the camera

        This a read only feature. It indicates the maximum possible pixel value that could be transferred from the camera.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &PixelDynamicRangeMax;
    
    //@}
    

    //! \name ImageFormat - This category includes items that control the size of the acquired image and the format of the transferred pixel data
    //@{
    /*!
        \brief Selecting a test image from the list will enable the test image

        This enumeration provides a list of the available test images. Selecting a test image from the list will enable the test image.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<TestImageSelectorEnums > &TestImageSelector;
    
    //@}
    

    //! \name DeviceInformation - This category includes information that describes the device and its sensor
    //@{
    /*!
        \brief Indicates the width of the camera's sensor in pixels

        This is a read only element. It is an integer that indicates the actual width of the camera's sensor in pixels.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &SensorWidth;
    
    //@}
    

    //! \name DeviceInformation - This category includes information that describes the device and its sensor
    //@{
    /*!
        \brief Indicates the height of the camera's sensor in pixels.

        This is a read only element. It is an integer that indicates the actual height of the camera's sensor in pixels.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &SensorHeight;
    
    //@}
    

    //! \name DeviceInformation - This category includes information that describes the device and its sensor
    //@{
    /*!
        \brief Indicates the maximum allowed width of the image in pixels

        This is a read only element. It is an integer that indicates maximum allowed width of the image in pixels taking into account any function that may limit the allowed width.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &WidthMax;
    
    //@}
    

    //! \name DeviceInformation - This category includes information that describes the device and its sensor
    //@{
    /*!
        \brief Indicates the maximum allowed height of the image in pixels

        This is a read only element. It is an integer that indicates maximum allowed height of the image in pixels taking into account any function that may limit the allowed height.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &HeightMax;
    
    //@}
    

    //! \name ColorImprovementsControl - This category includes items that control color improvement
    //@{
    /*!
        \brief Selects the matrix color transformation between color spaces

        Selects the matrix color transformation between color spaces.
Generally, the related color spaces are used for internal processing: The color signals provided by the sensor are transformed to the RGB color space to allow further transformations (to account for the type of light source, for color adjustment, for white balance, etc.).
The color transformation selected here does not refer to the color space selected for the transmission of image data out of the camera.

    
        \b Visibility = Guru
    
    */
    GenApi::IEnumerationT<ColorTransformationSelectorEnums > &ColorTransformationSelector;
    
    //@}
    

    //! \name ColorImprovementsControl - This category includes items that control color improvement
    //@{
    /*!
        \brief Selects the type of light source to be considered for matrix color transformation

        Selects the color transformation mode to select the type of light source to be considered for matrix color transformation.
    
        \b Visibility = Expert
    
        \b Selected by : ColorTransformationSelector
    
    */
    GenApi::IEnumerationT<LightSourceSelectorEnums > &LightSourceSelector;
    
    //@}
    

    //! \name ColorImprovementsControl - This category includes items that control color improvement
    //@{
    /*!
        \brief Defines the extent to which the selected light source will be considered (float)

        Sets a floating point value to define the extent to which the selected light source will be considered in color matrix transformation.
If the value is set to 1 the selected light source will be fully considered. If the value is set to 0 the selected light source will not be considered.
    
        \b Visibility = Guru
    
    */
    GenApi::IFloat &ColorTransformationMatrixFactor;
    
    //@}
    

    //! \name ColorImprovementsControl - This category includes items that control color improvement
    //@{
    /*!
        \brief Defines the extent to which the selected light source will be considered (integer)

        Sets an integer value to define the extent to which the selected light source will be considered in color matrix transformation. If the value is set to 65536 the selected light source will be fully considered. If the value is set to 0 the selected light source will not be considered.
    
        \b Visibility = Guru
    
    */
    GenApi::IInteger &ColorTransformationMatrixFactorRaw;
    
    //@}
    

    //! \name ColorImprovementsControl - This category includes items that control color improvement
    //@{
    /*!
        \brief Selects the element to be entered in the color transformation matrix.

        Selects the element to be entered in the 3 x 3 color transformation matrix for custom matrix color transformation.
Note: Depending on the camera model, some elements in the color transformation matrix may be preset and can not be changed.

    
        \b Visibility = Guru
    
        \b Selected by : ColorTransformationSelector
    
    */
    GenApi::IEnumerationT<ColorTransformationValueSelectorEnums > &ColorTransformationValueSelector;
    
    //@}
    

    //! \name ColorImprovementsControl - This category includes items that control color improvement
    //@{
    /*!
        \brief Sets a floating point value for the selected element in the color transformation matrix

        Sets a floating point value for the selected element in the color transformation matrix.
    
        \b Visibility = Guru
    
        \b Selected by : ColorTransformationSelector, ColorTransformationValueSelector
    
    */
    GenApi::IFloat &ColorTransformationValue;
    
    //@}
    

    //! \name ColorImprovementsControl - This category includes items that control color improvement
    //@{
    /*!
        \brief Sets an integer value for the selected element in the color transformation matrix

        Sets an integer value for the selected element in the color transformation matrix.
    
        \b Visibility = Guru
    
        \b Selected by : ColorTransformationValueSelector
    
    */
    GenApi::IInteger &ColorTransformationValueRaw;
    
    //@}
    

    //! \name ColorImprovementsControl - This category includes items that control color improvement
    //@{
    /*!
        \brief Enables color adjustment

        Enables color adjustment.
    
        \b Visibility = Expert
    
    */
    GenApi::IBoolean &ColorAdjustmentEnable;
    
    //@}
    

    //! \name ColorImprovementsControl - This category includes items that control color improvement
    //@{
    /*!
        \brief Allows returning to previous settings

        Allows returning to the color adjustment settings extant before the latest changes of the settings.
This allows you undoing the latest unwanted changes of the color adjustment settings and returning to the preceding settings.
    
        \b Visibility = Expert
    
    */
    GenApi::ICommand &ColorAdjustmentReset;
    
    //@}
    

    //! \name ColorImprovementsControl - This category includes items that control color improvement
    //@{
    /*!
        \brief Selects the color for color adjustment

        Selects the color for color adjustment.
Those colors in the image will be adjusted where the selected color predominates.
    
        \b Visibility = Expert
    
    */
    GenApi::IEnumerationT<ColorAdjustmentSelectorEnums > &ColorAdjustmentSelector;
    
    //@}
    

    //! \name ColorImprovementsControl - This category includes items that control color improvement
    //@{
    /*!
        \brief Adjustment of hue of the selected color (float)

        Sets a floating point value for the adjustment of hue of the selected color.
    
        \b Visibility = Expert
    
        \b Selected by : ColorAdjustmentSelector
    
    */
    GenApi::IFloat &ColorAdjustmentHue;
    
    //@}
    

    //! \name ColorImprovementsControl - This category includes items that control color improvement
    //@{
    /*!
        \brief Adjustment of hue of the selected color (integer)

        Sets an integer value for the adjustment of hue of the selected color.
    
        \b Visibility = Expert
    
        \b Selected by : ColorAdjustmentSelector
    
    */
    GenApi::IInteger &ColorAdjustmentHueRaw;
    
    //@}
    

    //! \name ColorImprovementsControl - This category includes items that control color improvement
    //@{
    /*!
        \brief Adjustment of saturation of the selected color (float)

        Sets a floating point value for the adjustment of saturation of the selected color.
    
        \b Visibility = Expert
    
        \b Selected by : ColorAdjustmentSelector
    
    */
    GenApi::IFloat &ColorAdjustmentSaturation;
    
    //@}
    

    //! \name ColorImprovementsControl - This category includes items that control color improvement
    //@{
    /*!
        \brief Adjustment of saturation of the selected color (integer)

        Sets an integer value for the adjustment of saturation of the selected color.
    
        \b Visibility = Expert
    
        \b Selected by : ColorAdjustmentSelector
    
    */
    GenApi::IInteger &ColorAdjustmentSaturationRaw;
    
    //@}
    

    //! \name ColorImprovementsControl - This category includes items that control color improvement
    //@{
    /*!
        \brief Allows returning to previous settings

        Allows returning to the color adjustment settings extant before the latest changes of the settings.
This allows you undoing the latest unwanted changes of the color adjustment settings and returning to the preceding settings.
    
        \b Visibility = Expert
    
    */
    GenApi::ICommand &BalanceWhiteReset;
    
    //@}
    

    //! \name ColorImprovementsControl - This category includes items that control color improvement
    //@{
    /*!
        \brief Balance White Auto is the 'automatic' counterpart of the manual white balance feature.

        The automatic white balance is a two-step process: First, the Balance Ratio Abs parameter values for red, green, and blue are each set to 1.5. Then, assuming a 'grey world' model, the Balance Ratio Abs parameter values are adjusted such that the average gray values for the 'red' and 'blue' pixels match the average gray value for the 'green' pixels.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<BalanceWhiteAutoEnums > &BalanceWhiteAuto;
    
    //@}
    

    //! \name ColorImprovementsControl - This category includes items that control color improvement
    //@{
    /*!
        \brief Selects a balance ratio to configure. Once a balance ratio control has been selected, all changes to the balance ratio settings will be applied to the selected control.

        This enumeration selects a balance ratio control to configuration. Once a balance ratio control has been selected, all changes to the balance ratio settings will be applied to the selected control.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<BalanceRatioSelectorEnums > &BalanceRatioSelector;
    
    //@}
    

    //! \name ColorImprovementsControl - This category includes items that control color improvement
    //@{
    /*!
        \brief Sets the value of the selected balance ratio control as a float

        This value sets the selected balance ratio control as a float value.
    
        \b Visibility = Beginner
        
    
        \b Selected by : BalanceRatioSelector
    
    */
    GenApi::IFloat &BalanceRatioAbs;
    
    //@}
    

    //! \name ColorImprovementsControl - This category includes items that control color improvement
    //@{
    /*!
        \brief Sets the value of the selected balance ratio control as an integer

        This value sets the selected balance ratio control as an integer.
    
        \b Visibility = Beginner
        
    
        \b Selected by : BalanceRatioSelector
    
    */
    GenApi::IInteger &BalanceRatioRaw;
    
    //@}
    

    //! \name AOI - This category includes items used to set the size and position of the area of interest
    //@{
    /*!
        \brief Sets the width of the area of interest in pixels

        This value sets the width of the area of interest in pixels.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &Width;
    
    //@}
    

    //! \name AOI - This category includes items used to set the size and position of the area of interest
    //@{
    /*!
        \brief Sets the height of the area of interest in pixels

        This value sets the height of the area of interest in pixels.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &Height;
    
    //@}
    

    //! \name AOI - This category includes items used to set the size and position of the area of interest
    //@{
    /*!
        \brief Sets the X offset (left offset) of the area of interest in pixels

        This value sets the X offset (left offset) for the area of interest in pixels, i.e., the distance in pixels between the left side of the sensor and the left side of the image area.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &OffsetX;
    
    //@}
    

    //! \name AOI - This category includes items used to set the size and position of the area of interest
    //@{
    /*!
        \brief Sets the Y offset (top offset) for the area of interest in pixels

        This value sets the Y offset (top offset) for the area of interest, i.e., the distance in pixels between the top of the sensor and the top of the image area.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &OffsetY;
    
    //@}
    

    //! \name AOI - This category includes items used to set the size and position of the area of interest
    //@{
    /*!
        \brief Sets the number of adjacent vertical pixes to be summed

        Sets the number of binned adjacent vertical pixels. Their charges will be summed and reported out of the camera as a single pixel.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &BinningVertical;
    
    //@}
    

    //! \name AOI - This category includes items used to set the size and position of the area of interest
    //@{
    /*!
        \brief Sets the number of adjacent horizontal pixes to be summed

        Sets the number of binned adjacent horizontal pixels. Their charges will be summed and reported out of the camera as a single pixel.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &BinningHorizontal;
    
    //@}
    

    //! \name AOI - This category includes items used to set the size and position of the area of interest
    //@{
    /*!
        \brief Sets the vertical binning feature

        This enumeration sets the vertical binning feature.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<LegacyBinningVerticalEnums > &LegacyBinningVertical;
    
    //@}
    

    //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition
    //@{
    /*!
        \brief When enabled, the maximum frame rate does not depend on the image transfer rate out of the camera.

        When enabled, the maximum frame rate onyl depends on sensor timing and timing of the trigger sequence, and not on the image transfer rate out of the camera.

Note: The maximum number of triggers within a burst sequence is limited. If the maximum number is exceeded, images may be damaged or lost.
    
        \b Visibility = Guru
    
    */
    GenApi::IBoolean &EnableBurstAcquisition;
    
    //@}
    

    //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition
    //@{
    /*!
        \brief Sets the image acquisition mode

        This enumeration sets the image acquisition mode. 
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<AcquisitionModeEnums > &AcquisitionMode;
    
    //@}
    

    //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition
    //@{
    /*!
        \brief Starts the acquisition of images

        This command starts the acquisition of images. If the camera is set for single frame acquisition, it will start acquisition of one frame. If the camera is set for continuous frame acquisition, it will start continuous acquisition of frames.
    
        \b Visibility = Beginner
        
    
        \b Selected by : AcquisitionMode
    
    */
    GenApi::ICommand &AcquisitionStart;
    
    //@}
    

    //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition
    //@{
    /*!
        \brief Stops the acquisition of images

        If the camera is set for continuous image acquisition and acquisition has been started, this command stops the acquisition of images.
    
        \b Visibility = Beginner
        
    
        \b Selected by : AcquisitionMode
    
    */
    GenApi::ICommand &AcquisitionStop;
    
    //@}
    

    //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition
    //@{
    /*!
        \brief Sets the number of frames acquired in the multiframe acquisition mode

        This value sets the number of frames acquired in the multiframe acquisition mode
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &AcquisitionFrameCount;
    
    //@}
    

    //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition
    //@{
    /*!
        \brief 

        
    
        \b Visibility = Expert
    
    */
    GenApi::IEnumerationT<TriggerControlImplementationEnums > &TriggerControlImplementation;
    
    //@}
    

    //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition
    //@{
    /*!
        \brief Selects the trigger type to configure. Once a trigger type has been selected, all changes to the trigger settings will be applied to the selected trigger.

        This enumeration selects the trigger type to configure. Once a trigger type has been selected, all changes to the trigger settings will be applied to the selected trigger.
    
        \b Visibility = Beginner
        
    
        \b Selected by : TriggerControlImplementation
    
    */
    GenApi::IEnumerationT<TriggerSelectorEnums > &TriggerSelector;
    
    //@}
    

    //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition
    //@{
    /*!
        \brief Sets the mode for the selected trigger

        This enumeration sets the trigger mode for the selected trigger.
    
        \b Visibility = Beginner
        
    
        \b Selected by : TriggerSelector
    
    */
    GenApi::IEnumerationT<TriggerModeEnums > &TriggerMode;
    
    //@}
    

    //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition
    //@{
    /*!
        \brief Generates a software trigger signal that is used when the trigger source is set to 'software'

        This command generates a software trigger signal. The software trigger signal will be used if the trigger source is set to 'software'.
    
        \b Visibility = Beginner
        
    
        \b Selected by : TriggerSelector
    
    */
    GenApi::ICommand &TriggerSoftware;
    
    //@}
    

    //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition
    //@{
    /*!
        \brief Sets the signal source for the selected trigger

        This enumeration sets the signal source for the selected trigger.
    
        \b Visibility = Beginner
        
    
        \b Selected by : TriggerSelector
    
    */
    GenApi::IEnumerationT<TriggerSourceEnums > &TriggerSource;
    
    //@}
    

    //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition
    //@{
    /*!
        \brief Sets the signal transition needed to activate the selected trigger

        This enumeration sets the signal transition needed to activate the selected trigger.
    
        \b Visibility = Beginner
        
    
        \b Selected by : TriggerSelector
    
    */
    GenApi::IEnumerationT<TriggerActivationEnums > &TriggerActivation;
    
    //@}
    

    //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition
    //@{
    /*!
        \brief Sets the trigger delay time in microseconds.

        This float value sets the absolute trigger delay in microseconds to apply after the trigger reception before effectively activating it.
    
        \b Visibility = Expert
    
        \b Selected by : TriggerSelector
    
    */
    GenApi::IFloat &TriggerDelayAbs;
    
    //@}
    

    //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition
    //@{
    /*!
        \brief Exposure Auto is the 'automatic' counterpart to manually setting an 'absolute' exposure time.

        The exposure auto function automatically adjusts the Auto Exposure Time Abs parameter value within set limits, until a target average gray value for the pixel data of the related Auto Function AOI is reached.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<ExposureAutoEnums > &ExposureAuto;
    
    //@}
    

    //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition
    //@{
    /*!
        \brief Sets the 'raw' exposure time.  Actual exposure time = raw exposure setting  x  exposure time base abs setting

        This value sets an integer that will be used as a multiplier for the exposure timebase. The actual exposure time equals the current exposure time raw setting times the current exposure time base abs setting.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &ExposureTimeRaw;
    
    //@}
    

    //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition
    //@{
    /*!
        \brief Directly sets the camera's exposure time in microseconds

        This float value sets the camera's exposure time in microseconds.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IFloat &ExposureTimeAbs;
    
    //@}
    

    //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition
    //@{
    /*!
        \brief Sets the time base (in microseconds) that is used when the exposure time is set with the 'exposure time raw' setting

        This float value sets the time base (in microseconds) that is used when the exposure time is set with the 'raw' setting.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IFloat &ExposureTimeBaseAbs;
    
    //@}
    

    //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition
    //@{
    /*!
        \brief Enables the use of the exposure time base

        This value enables the use of the exposure time base.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IBoolean &ExposureTimeBaseAbsEnable;
    
    //@}
    

    //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition
    //@{
    /*!
        \brief If the acquisition frame rate feature is enabled, this value sets the camera's acquisition frame rate in frames per second

        Sets the 'absolute' value of the acquisition frame rate. The 'absolute' value is a float value that sets the acquisition frame rate in frames per second.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IFloat &AcquisitionFrameRateAbs;
    
    //@}
    

    //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition
    //@{
    /*!
        \brief Enables setting the camera's acquisition frame rate to a specified value

        This boolean value enables setting  the camera's acquisition frame rate to a specified value.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IBoolean &AcquisitionFrameRateEnable;
    
    //@}
    

    //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition
    //@{
    /*!
        \brief Indicates the maximum allowed frame acquisition rate (in frames per second) given the current settings for the area of interest, exposure time, and bandwidth

        Indicates the 'absolute' value of the maximum allowed acquisition frame rate. The 'absolute' value is a float value that indicates the maximum allowed acquisition frame rate in frames per second given the current settings for the area of interest, exposure time, and bandwidth.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IFloat &ResultingFrameRateAbs;
    
    //@}
    

    //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition
    //@{
    /*!
        \brief Sets the exposure mode

        This enumeration sets the exposure mode.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<ExposureModeEnums > &ExposureMode;
    
    //@}
    

    //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition
    //@{
    /*!
        \brief Indicates the sensor readout time given the current settings.

        Indicates the sensor readout time given the current settings.
    
        \b Visibility = Expert
    
    */
    GenApi::IFloat &ReadoutTimeAbs;
    
    //@}
    

    //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition
    //@{
    /*!
        \brief This enumeration is used to select which internal acquisition signal to read using AcquisitionStatus.

        This enumeration is used to select which internal acquisition signal to read using AcquisitionStatus.
    
        \b Visibility = Expert
    
    */
    GenApi::IEnumerationT<AcquisitionStatusSelectorEnums > &AcquisitionStatusSelector;
    
    //@}
    

    //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition
    //@{
    /*!
        \brief Reads the selected acquisition status

        This feature is used to read the state (True or False) of the internal acquisition signal selected using AcquisitionStatusSelector.
    
        \b Visibility = Expert
    
        \b Selected by : AcquisitionStatusSelector
    
    */
    GenApi::IBoolean &AcquisitionStatus;
    
    //@}
    

    //! \name DigitalIO - This category includes items used to control the operation of the camera's digital I/O lines
    //@{
    /*!
        \brief Selects the I/O line to configure. Once a line has been selected, all changes to the line settings will be applied to the selected line.

        This enumeration selects the I/O line to configure. Once a line has been selected, all changes to the line settings will be applied to the selected line.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<LineSelectorEnums > &LineSelector;
    
    //@}
    

    //! \name DigitalIO - This category includes items used to control the operation of the camera's digital I/O lines
    //@{
    /*!
        \brief Enables the signal inverter function for the selected input or output line.

        This boolean value enables the signal inverter function for the selected input or output line.
    
        \b Visibility = Beginner
        
    
        \b Selected by : LineSelector
    
    */
    GenApi::IBoolean &LineInverter;
    
    //@}
    

    //! \name DigitalIO - This category includes items used to control the operation of the camera's digital I/O lines
    //@{
    /*!
        \brief Enables the termination resistor for the selected input line.

        This boolean value enables the termination resistor for the selected input line.
    
        \b Visibility = Beginner
        
    
        \b Selected by : LineSelector
    
    */
    GenApi::IBoolean &LineTermination;
    
    //@}
    

    //! \name DigitalIO - This category includes items used to control the operation of the camera's digital I/O lines
    //@{
    /*!
        \brief Sets the raw value of the selected line debouncer time

        Sets the raw value of the selected line debouncer time
    
        \b Visibility = Invisible
    
        \b Selected by : LineSelector
    
    */
    GenApi::IInteger &LineDebouncerTimeRaw;
    
    //@}
    

    //! \name DigitalIO - This category includes items used to control the operation of the camera's digital I/O lines
    //@{
    /*!
        \brief Sets the absolute value of the selected line debouncer time in microseconds

        Sets the absolute value of the selected line debouncer time in microseconds
    
        \b Visibility = Beginner
        
    
        \b Selected by : LineSelector
    
    */
    GenApi::IFloat &LineDebouncerTimeAbs;
    
    //@}
    

    //! \name DigitalIO - This category includes items used to control the operation of the camera's digital I/O lines
    //@{
    /*!
        \brief Indicates the current logical state for the selected line

        This boolean value indicates the current logical state for the selected line at the time of polling.
    
        \b Visibility = Beginner
        
    
        \b Selected by : LineSelector
    
    */
    GenApi::IBoolean &LineStatus;
    
    //@}
    

    //! \name DigitalIO - This category includes items used to control the operation of the camera's digital I/O lines
    //@{
    /*!
        \brief A single bitfield indicating the current logical state of all available line signals at time of polling

        This integer value is a single bitfield that indicates the current logical state of all available lines at time of polling.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &LineStatusAll;
    
    //@}
    

    //! \name DigitalIO - This category includes items used to control the operation of the camera's digital I/O lines
    //@{
    /*!
        \brief Sets the state of the selected user settable output signal

        This boolean value sets the state of the selected user settable output signal.
    
        \b Visibility = Beginner
        
    
        \b Selected by : UserOutputSelector
    
    */
    GenApi::IBoolean &UserOutputValue;
    
    //@}
    

    //! \name DigitalIO - This category includes items used to control the operation of the camera's digital I/O lines
    //@{
    /*!
        \brief A single bitfield that sets the state of all user settable output signals in one access

        This integer value is a single bitfield that sets the state of all user settable output signals in one access.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &UserOutputValueAll;
    
    //@}
    

    //! \name DigitalIO - This category includes items used to control the operation of the camera's digital I/O lines
    //@{
    /*!
        \brief Sets the mode for the selected line

        This feature controls whether the physical Line is used to Input or Output a signal. When a Line supports input and output mode, the default state is Input to avoid possible electrical contention. Line Mode can take any of the following values: Input: The selected physical line is used to input an electrical signal. Output: The selected physical line is used to output an electrical signal.
    
        \b Visibility = Beginner
        
    
        \b Selected by : LineSelector
    
    */
    GenApi::IEnumerationT<LineModeEnums > &LineMode;
    
    //@}
    

    //! \name DigitalIO - This category includes items used to control the operation of the camera's digital I/O lines
    //@{
    /*!
        \brief Sets the source signal for the selected line (if the selected line is an output)

        This enumeration selects the internally generated camera signal (source signal) for the selected line when the selected line is an output. 
    
        \b Visibility = Beginner
        
    
        \b Selected by : LineSelector
    
    */
    GenApi::IEnumerationT<LineSourceEnums > &LineSource;
    
    //@}
    

    //! \name DigitalIO - This category includes items used to control the operation of the camera's digital I/O lines
    //@{
    /*!
        \brief 

        
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<LineLogicEnums > &LineLogic;
    
    //@}
    

    //! \name DigitalIO - This category includes items used to control the operation of the camera's digital I/O lines
    //@{
    /*!
        \brief Sets the electrical configuration of the selected line

        This feature controls the current electrical format of the selected physical input or output Line. Line Format can take any of the following values: No Connect: The Line is not connected. Tri-state: The Line is currently in Tri-state mode (Not driven). TTL: The Line is currently accepting or sending TTL level signals. LVDS: The Line is currently accepting or sending LVDS level signals. RS-422: The Line is currently accepting or sending RS-422 level signals. Opto-coupled: The Line is Opto-coupled. 
    
        \b Visibility = Beginner
        
    
        \b Selected by : LineSelector
    
    */
    GenApi::IEnumerationT<LineFormatEnums > &LineFormat;
    
    //@}
    

    //! \name DigitalIO - This category includes items used to control the operation of the camera's digital I/O lines
    //@{
    /*!
        \brief Selects the user settable output signal to configure. Once a user settable output signal has been selected, all changes to the user settable output signal settings will be applied to the selected user settable output signal.

        This enumeration selects the user settable output signal to configure. Once a user settable output signal has been selected, all changes to the user settable output signal settings will be applied to the selected user settable output signal.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<UserOutputSelectorEnums > &UserOutputSelector;
    
    //@}
    

    //! \name TimerControls - This category includes items used to control the operation of the camera's timers
    //@{
    /*!
        \brief Sets the time base (in microseconds) that is used when a timer duration is set with the 'timer duration raw' setting

        This float value sets the time base (in microseconds) that is used when a timer duration is set with the 'raw' setting.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IFloat &TimerDurationTimebaseAbs;
    
    //@}
    

    //! \name TimerControls - This category includes items used to control the operation of the camera's timers
    //@{
    /*!
        \brief Sets the time base (in microseconds) that is used when a timer delay is set with the 'timer delay raw' setting

        This float value sets the time base (in microseconds) that is used when a timer delay is set with the 'raw' setting.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IFloat &TimerDelayTimebaseAbs;
    
    //@}
    

    //! \name TimerControls - This category includes items used to control the operation of the camera's timers
    //@{
    /*!
        \brief Selects the timer to configure.  Once a timer has been selected, all changes to the timer settings will be applied to the selected timer.

        This enumeration selects the timer to configure. . Once a timer has been selected, all changes to the timer settings will be applied to the selected timer.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<TimerSelectorEnums > &TimerSelector;
    
    //@}
    

    //! \name TimerControls - This category includes items used to control the operation of the camera's timers
    //@{
    /*!
        \brief Directly sets the duration for the selected timer in microseconds

        This float value sets the duration for the selected timer in microseconds.
    
        \b Visibility = Beginner
        
    
        \b Selected by : TimerSelector
    
    */
    GenApi::IFloat &TimerDurationAbs;
    
    //@}
    

    //! \name TimerControls - This category includes items used to control the operation of the camera's timers
    //@{
    /*!
        \brief Sets the 'raw' duration for the selected timer.  Actual duration = raw timer duration setting  x  timer duration time base abs setting

        This value sets an integer that will be used as a multiplier for the timer duration timebase. The actual duration time equals the current timer duration raw setting times the current timer duration time base abs setting.
    
        \b Visibility = Beginner
        
    
        \b Selected by : TimerSelector
    
    */
    GenApi::IInteger &TimerDurationRaw;
    
    //@}
    

    //! \name TimerControls - This category includes items used to control the operation of the camera's timers
    //@{
    /*!
        \brief Directly sets the delay for the selected timer in microseconds

        This float value sets the delay for the selected timer in microseconds.
    
        \b Visibility = Beginner
        
    
        \b Selected by : TimerSelector
    
    */
    GenApi::IFloat &TimerDelayAbs;
    
    //@}
    

    //! \name TimerControls - This category includes items used to control the operation of the camera's timers
    //@{
    /*!
        \brief Sets the 'raw' delay for the selected timer.  Actual delay = raw timer delay setting  x  timer delay time base abs setting

        This value sets an integer that will be used as a multiplier for the timer delay timebase. The actual delay time equals the current timer delay raw setting times the current timer delay time base abs setting.
    
        \b Visibility = Beginner
        
    
        \b Selected by : TimerSelector
    
    */
    GenApi::IInteger &TimerDelayRaw;
    
    //@}
    

    //! \name TimerControls - This category includes items used to control the operation of the camera's timers
    //@{
    /*!
        \brief Sets the internal camera signal used to trigger the selected timer

        This enumeration sets the internal camera signal used to trigger the selected timer.
    
        \b Visibility = Beginner
        
    
        \b Selected by : TimerSelector
    
    */
    GenApi::IEnumerationT<TimerTriggerSourceEnums > &TimerTriggerSource;
    
    //@}
    

    //! \name TimerControls - This category includes items used to control the operation of the camera's timers
    //@{
    /*!
        \brief Sets the type of signal transistion that will start the timer

        This enumeration sets the type of signal transistion that will start the timer.
    
        \b Visibility = Beginner
        
    
        \b Selected by : TimerSelector
    
    */
    GenApi::IEnumerationT<TimerTriggerActivationEnums > &TimerTriggerActivation;
    
    //@}
    

    //! \name TimerSequence - 
    //@{
    /*!
        \brief 

        
    
        \b Visibility = Guru
    
    */
    GenApi::IBoolean &TimerSequenceEnable;
    
    //@}
    

    //! \name TimerSequence - 
    //@{
    /*!
        \brief 

        
    
        \b Visibility = Guru
    
    */
    GenApi::IInteger &TimerSequenceLastEntryIndex;
    
    //@}
    

    //! \name TimerSequence - 
    //@{
    /*!
        \brief 

        
    
        \b Visibility = Guru
    
    */
    GenApi::IInteger &TimerSequenceCurrentEntryIndex;
    
    //@}
    

    //! \name TimerSequence - 
    //@{
    /*!
        \brief 

        
    
        \b Visibility = Guru
    
    */
    GenApi::IEnumerationT<TimerSequenceEntrySelectorEnums > &TimerSequenceEntrySelector;
    
    //@}
    

    //! \name TimerSequence - 
    //@{
    /*!
        \brief 

        
    
        \b Visibility = Guru
    
        \b Selected by : TimerSequenceEntrySelector
    
    */
    GenApi::IEnumerationT<TimerSequenceTimerSelectorEnums > &TimerSequenceTimerSelector;
    
    //@}
    

    //! \name TimerSequence - 
    //@{
    /*!
        \brief 

        
    
        \b Visibility = Guru
    
        \b Selected by : TimerSequenceTimerSelector
    
    */
    GenApi::IBoolean &TimerSequenceTimerEnable;
    
    //@}
    

    //! \name TimerSequence - 
    //@{
    /*!
        \brief 

        
    
        \b Visibility = Guru
    
        \b Selected by : TimerSequenceTimerSelector
    
    */
    GenApi::IBoolean &TimerSequenceTimerInverter;
    
    //@}
    

    //! \name TimerSequence - 
    //@{
    /*!
        \brief 

        
    
        \b Visibility = Guru
    
        \b Selected by : TimerSequenceTimerSelector
    
    */
    GenApi::IInteger &TimerSequenceTimerDelayRaw;
    
    //@}
    

    //! \name TimerSequence - 
    //@{
    /*!
        \brief 

        
    
        \b Visibility = Guru
    
        \b Selected by : TimerSequenceTimerSelector
    
    */
    GenApi::IInteger &TimerSequenceTimerDurationRaw;
    
    //@}
    

    //! \name TimerControls - This category includes items used to control the operation of the camera's timers
    //@{
    /*!
        \brief Selects the counter to configure.  Once a counter has been selected, all changes to the counter settings will be applied to the selected counter.

        This enumeration selects the counter to configure. Once a counter has been selected, all changes to the counter settings will be applied to the selected counter.
    
        \b Visibility = Expert
    
    */
    GenApi::IEnumerationT<CounterSelectorEnums > &CounterSelector;
    
    //@}
    

    //! \name TimerControls - This category includes items used to control the operation of the camera's timers
    //@{
    /*!
        \brief Selects the event that will be the source to increment the counter

        This enumeration selects the event that will be the source to increment the counter.
    
        \b Visibility = Expert
    
        \b Selected by : CounterSelector
    
    */
    GenApi::IEnumerationT<CounterEventSourceEnums > &CounterEventSource;
    
    //@}
    

    //! \name TimerControls - This category includes items used to control the operation of the camera's timers
    //@{
    /*!
        \brief Selects the source of the reset for the selected counter.

        This enumeration selects the source of the reset for the selected counter.
    
        \b Visibility = Expert
    
        \b Selected by : CounterSelector
    
    */
    GenApi::IEnumerationT<CounterResetSourceEnums > &CounterResetSource;
    
    //@}
    

    //! \name TimerControls - This category includes items used to control the operation of the camera's timers
    //@{
    /*!
        \brief Immediately resets the selected counter

        This command will immediately reset the selected counter. Note that the counter starts counting immediately after the reset.
    
        \b Visibility = Expert
    
        \b Selected by : CounterSelector
    
    */
    GenApi::ICommand &CounterReset;
    
    //@}
    

    //! \name LUTControls - This category includes items used to control the operation of the camera's lookup table (LUT)
    //@{
    /*!
        \brief Enables the selected LUT

        This boolean value enables the selected LUT.
    
        \b Visibility = Beginner
        
    
        \b Selected by : LUTSelector
    
    */
    GenApi::IBoolean &LUTEnable;
    
    //@}
    

    //! \name LUTControls - This category includes items used to control the operation of the camera's lookup table (LUT)
    //@{
    /*!
        \brief Sets the LUT element to access 

        This value sets the LUT element to access. This value is used to index into a LUT array.
    
        \b Visibility = Beginner
        
    
        \b Selected by : LUTSelector
    
    */
    GenApi::IInteger &LUTIndex;
    
    //@}
    

    //! \name LUTControls - This category includes items used to control the operation of the camera's lookup table (LUT)
    //@{
    /*!
        \brief Sets the value of the LUT element at the LUT index

        This value sets the value of the LUT element at the LUT index.
    
        \b Visibility = Beginner
        
    
        \b Selected by : LUTIndex, LUTSelector
    
    */
    GenApi::IInteger &LUTValue;
    
    //@}
    

    //! \name LUTControls - This category includes items used to control the operation of the camera's lookup table (LUT)
    //@{
    /*!
        \brief Accesses the entire content of the selected LUT in one chunk access

        
    
        \b Visibility = Beginner
        
    
        \b Selected by : LUTSelector
    
    */
    GenApi::IRegister &LUTValueAll;
    
    //@}
    

    //! \name LUTControls - This category includes items used to control the operation of the camera's lookup table (LUT)
    //@{
    /*!
        \brief Selects the lookup table (LUT) to configure. Once a LUT has been selected, all changes to the LUT settings will be applied to the selected LUT.

        This enumeration the lookup table (LUT) to configure. Once a LUT has been selected, all changes to the LUT settings will be applied to the selected LUT.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<LUTSelectorEnums > &LUTSelector;
    
    //@}
    

    //! \name TransportLayer - This category includes items related to the IIDC 1394 transport specification
    //@{
    /*!
        \brief Size of the payload in bytes

        Size of the payload in bytes. This is the total number of bytes sent in the payload. Image data + chunk data if present. No packet headers.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &PayloadSize;
    
    //@}
    

    //! \name TransportLayer - This category includes items related to the IIDC 1394 transport specification
    //@{
    /*!
        \brief Indicates the recommended packet size in bytes. If a smaller packet size is used, the camera's maximum allowed frame rate will be reduced.

        This value indicates the recommended packet size in bytes. If a smaller packet size is used, the camera's maximum allowed frame rate will be reduced.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &RecommendedPacketSize;
    
    //@}
    

    //! \name TransportLayer - This category includes items related to the IIDC 1394 transport specification
    //@{
    /*!
        \brief Sets the packet size in bytes

         This value sets the packet size in bytes.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &PacketSize;
    
    //@}
    

    //! \name UserSets - This category includes items that control the configuration sets feature that is used to save sets of parameters in the camera
    //@{
    /*!
        \brief Loads the selected configuration into the camera's volatile memory and makes it the active configuration set. Once the selected set is loaded, the parameters in the selected set will control the camera.

        This command loads the selected configuration set from the non-volatile memory in the camera to the volatile memory and makes the selected set the active configuration set. Once the selected set is loaded, the parameters in the selected set will control the camera.
    
        \b Visibility = Beginner
        
    
        \b Selected by : UserSetSelector
    
    */
    GenApi::ICommand &UserSetLoad;
    
    //@}
    

    //! \name UserSets - This category includes items that control the configuration sets feature that is used to save sets of parameters in the camera
    //@{
    /*!
        \brief Saves the current active configuration set into the selected user set. 

        This command copies the parameters in the current active configuration set into the selected user set in the camera's non-volatile memory.
    
        \b Visibility = Beginner
        
    
        \b Selected by : UserSetSelector
    
    */
    GenApi::ICommand &UserSetSave;
    
    //@}
    

    //! \name UserSets - This category includes items that control the configuration sets feature that is used to save sets of parameters in the camera
    //@{
    /*!
        \brief Selects the configuration set to load, save, or configure. Once a configuration set has been selected, all changes to the configuration set settings will be applied to the selected configuration set.

        This enumeration selects the configuration set to load, save or configure. Possible values for the User Set Selector are: Default: Selects a configuration set that contains factory settings. User Set 1: Selects the first user set. When the Default configuration set is selected and loaded using User Set Load, the device must be in default factory settings state and must make sure the mandatory continuous acquisition use case works directly. Default User Set is read-only and cannot be modified.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<UserSetSelectorEnums > &UserSetSelector;
    
    //@}
    

    //! \name UserSets - This category includes items that control the configuration sets feature that is used to save sets of parameters in the camera
    //@{
    /*!
        \brief Sets the configuration set to be used as the default startup set. The configuration set that has been selected as the default startup set will be loaded as the active set whenever the camera is powered on or reset.

        This enumeration sets the configuration set to be used as the default startup set. The configuration set that has been selected as the default startup set will be loaded as the active set whenever the camera is powered on or reset.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<UserSetDefaultSelectorEnums > &UserSetDefaultSelector;
    
    //@}
    

    //! \name UserSets - This category includes items that control the configuration sets feature that is used to save sets of parameters in the camera
    //@{
    /*!
        \brief Selects the which factory setting will be used as default set.

        Selects the which factory setting will be used as default set.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<DefaultSetSelectorEnums > &DefaultSetSelector;
    
    //@}
    

    //! \name AutoFunctions - This category includes items that parameterize the Auto Functions
    //@{
    /*!
        \brief Target average gray value for Gain Auto and Exposure Auto

        The target average gray value may range from nearly black to nearly white. Note that this range of gray values applies to 8 bit and to 16 bit (12 bit effective) output modes. Accordingly, also for 16 bit output modes, black is represented by 0 and white by 255.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &AutoTargetValue;
    
    //@}
    

    //! \name AutoFunctions - This category includes items that parameterize the Auto Functions
    //@{
    /*!
        \brief Gray value adjustment damping for Gain Auto and Exposure Auto

        The gray value adjustment damping parameter controls the rate by which pixel gray values are changed when Exposure Auto and/or Gain Auto are enabled.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IFloat &GrayValueAdjustmentDampingAbs;
    
    //@}
    

    //! \name AutoFunctions - This category includes items that parameterize the Auto Functions
    //@{
    /*!
        \brief Gray value adjustment damping for Gain Auto and Exposure Auto

        The gray value adjustment damping parameter controls the rate by which pixel gray values are changed when Exposure Auto and/or Gain Auto are enabled.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &GrayValueAdjustmentDampingRaw;
    
    //@}
    

    //! \name AutoFunctions - This category includes items that parameterize the Auto Functions
    //@{
    /*!
        \brief Lower limit of the Auto Gain (Raw) parameter

        Lower limit of the Auto Gain (Raw) parameter
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &AutoGainRawLowerLimit;
    
    //@}
    

    //! \name AutoFunctions - This category includes items that parameterize the Auto Functions
    //@{
    /*!
        \brief Upper limit of the Auto Gain (Raw) parameter

        Upper limit of the Auto Gain (Raw) parameter
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &AutoGainRawUpperLimit;
    
    //@}
    

    //! \name AutoFunctions - This category includes items that parameterize the Auto Functions
    //@{
    /*!
        \brief Lower limit of the Auto Exposure Time (Abs) parameter

        Lower limit of the Auto Exposure Time (Abs) parameter
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IFloat &AutoExposureTimeAbsLowerLimit;
    
    //@}
    

    //! \name AutoFunctions - This category includes items that parameterize the Auto Functions
    //@{
    /*!
        \brief Upper limit of the Auto Exposure Time (Abs) parameter

        Upper limit of the Auto Exposure Time (Abs) parameter
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IFloat &AutoExposureTimeAbsUpperLimit;
    
    //@}
    

    //! \name AutoFunctions - This category includes items that parameterize the Auto Functions
    //@{
    /*!
        \brief Selects the strategy for controlling gain and shutter simultaneously.

        Selects the profile for controlling gain and shutter simultaneously.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<AutoFunctionProfileEnums > &AutoFunctionProfile;
    
    //@}
    

    //! \name AutoFunctionAOIs - Portion of the sensor array used for auto function control
    //@{
    /*!
        \brief Sets the width of the auto function area of interest in pixels

        This value sets the width of the auto function area of interest in pixels.
    
        \b Visibility = Beginner
        
    
        \b Selected by : AutoFunctionAOISelector
    
    */
    GenApi::IInteger &AutoFunctionAOIWidth;
    
    //@}
    

    //! \name AutoFunctionAOIs - Portion of the sensor array used for auto function control
    //@{
    /*!
        \brief Sets the height of the auto function area of interest in pixels

        This value sets the height of the auto function area of interest in pixels.
    
        \b Visibility = Beginner
        
    
        \b Selected by : AutoFunctionAOISelector
    
    */
    GenApi::IInteger &AutoFunctionAOIHeight;
    
    //@}
    

    //! \name AutoFunctionAOIs - Portion of the sensor array used for auto function control
    //@{
    /*!
        \brief Sets the starting column of the auto function area of interest in pixels

        This value sets the starting column of the auto function area of interest in pixels.
    
        \b Visibility = Beginner
        
    
        \b Selected by : AutoFunctionAOISelector
    
    */
    GenApi::IInteger &AutoFunctionAOIOffsetX;
    
    //@}
    

    //! \name AutoFunctionAOIs - Portion of the sensor array used for auto function control
    //@{
    /*!
        \brief Sets the starting line of the auto function area of interest in pixels

        This value sets the starting line of the auto function area of interest in pixels.
    
        \b Visibility = Beginner
        
    
        \b Selected by : AutoFunctionAOISelector
    
    */
    GenApi::IInteger &AutoFunctionAOIOffsetY;
    
    //@}
    

    //! \name AutoFunctionAOIs - Portion of the sensor array used for auto function control
    //@{
    /*!
        \brief 

        
    
        \b Visibility = Beginner
        
    
        \b Selected by : AutoFunctionAOISelector
    
    */
    GenApi::IBoolean &AutoFunctionAOIUsageIntensity;
    
    //@}
    

    //! \name AutoFunctionAOIs - Portion of the sensor array used for auto function control
    //@{
    /*!
        \brief 

        
    
        \b Visibility = Beginner
        
    
        \b Selected by : AutoFunctionAOISelector
    
    */
    GenApi::IBoolean &AutoFunctionAOIUsageWhiteBalance;
    
    //@}
    

    //! \name AutoFunctionAOIs - Portion of the sensor array used for auto function control
    //@{
    /*!
        \brief 

        
    
        \b Visibility = Beginner
        
    
        \b Selected by : AutoFunctionAOISelector
    
    */
    GenApi::IBoolean &AutoFunctionAOIUsageRedLightCorrection;
    
    //@}
    

    //! \name AutoFunctionAOIs - Portion of the sensor array used for auto function control
    //@{
    /*!
        \brief Selects the Auto Function AOI.

        Selects the Auto Function AOI.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<AutoFunctionAOISelectorEnums > &AutoFunctionAOISelector;
    
    //@}
    

    //! \name UserDefinedValues - 
    //@{
    /*!
        \brief 

        
    
        \b Visibility = Guru
    
    */
    GenApi::IEnumerationT<UserDefinedValueSelectorEnums > &UserDefinedValueSelector;
    
    //@}
    

    //! \name UserDefinedValues - 
    //@{
    /*!
        \brief 

        
    
        \b Visibility = Guru
    
        \b Selected by : UserDefinedValueSelector
    
    */
    GenApi::IInteger &UserDefinedValue;
    
    //@}
    

    //! \name DeviceInformation - This category includes information that describes the device and its sensor
    //@{
    /*!
        \brief 

        
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IString &DeviceVendorName;
    
    //@}
    

    //! \name DeviceInformation - This category includes information that describes the device and its sensor
    //@{
    /*!
        \brief 

        
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IString &DeviceModelName;
    
    //@}
    

    //! \name DeviceInformation - This category includes information that describes the device and its sensor
    //@{
    /*!
        \brief Indicates the serial number of the device

        This is a read only element. It is an integer that indicates the serial number of the device.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &DeviceSerialNumber;
    
    //@}
    

    //! \name DeviceInformation - This category includes information that describes the device and its sensor
    //@{
    /*!
        \brief Indicates the version of the device's firmware/software

        This is a read only element. It is a string that indicates the version of the device's firmware and software.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IString &DeviceFirmwareVersion;
    
    //@}
    

    //! \name DeviceInformation - This category includes information that describes the device and its sensor
    //@{
    /*!
        \brief A device ID that is user programmable

        This is a read/write element. It is a user programmable string.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IString &DeviceUserID;
    
    //@}
    

    //! \name DeviceInformation - This category includes information that describes the device and its sensor
    //@{
    /*!
        \brief Indicates the scan type of the device's sensor

        This enumeration lists the possible scan types for the sensor in the device.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<DeviceScanTypeEnums > &DeviceScanType;
    
    //@}
    

    //! \name DeviceInformation - This category includes information that describes the device and its sensor
    //@{
    /*!
        \brief Immediately resets and reboots the device

        This is a command that immediately resets and reboots the device.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::ICommand &DeviceReset;
    
    //@}
    

    //! \name DeviceInformation - This category includes information that describes the device and its sensor
    //@{
    /*!
        \brief Lists the temperature sources available for readout

        Lists the temperature sources available for readout
    
        \b Visibility = Expert
    
    */
    GenApi::IEnumerationT<TemperatureSelectorEnums > &TemperatureSelector;
    
    //@}
    

    //! \name DeviceInformation - This category includes information that describes the device and its sensor
    //@{
    /*!
        \brief Shows the current temperature of the selected target in degrees celcius

        Shows the current temperature of the selected target in degrees celcius
    
        \b Visibility = Expert
    
        \b Selected by : TemperatureSelector
    
    */
    GenApi::IFloat &TemperatureAbs;
    
    //@}
    

    //! \name RemoveParamLimits - This category includes items that allow removing the limits of camera parameters
    //@{
    /*!
        \brief Removes the factory-set limits of the selected parameter.

        Removes the factory-set limits of the selected parameter. Having removed the factory-set limits you may set the parameter within extended limits. These are only defined by technical restrictions. Note:  Inferior image quality may result.
    
        \b Visibility = Guru
    
        \b Selected by : ParameterSelector
    
    */
    GenApi::IBoolean &RemoveLimits;
    
    //@}
    

    //! \name RemoveParamLimits - This category includes items that allow removing the limits of camera parameters
    //@{
    /*!
        \brief Selects the parameter to configure. Once a parameter has been selected, all changes made using the Remove Limits feature will be applied to the selected parameter

        This enumeration selects the parameter to configure. Selects the parameter to configure. Once a parameter has been selected, all changes made using the Remove Limits feature will be applied to the selected parameter
    
        \b Visibility = Guru
    
    */
    GenApi::IEnumerationT<ParameterSelectorEnums > &ParameterSelector;
    
    //@}
    

    //! \name ExpertFeatureAccess - 
    //@{
    /*!
        \brief Selects the feature to configure. Once a feature has been selected, all changes made using the feature enable feature will be applied to the selected feature

        Selects the feature to configure. Once a feature has been selected, all changes made using the feature enable feature will be applied to the selected feature
    
        \b Visibility = Guru
    
    */
    GenApi::IEnumerationT<ExpertFeatureAccessSelectorEnums > &ExpertFeatureAccessSelector;
    
    //@}
    

    //! \name ExpertFeatureAccess - 
    //@{
    /*!
        \brief Sets the key to access the selected feature

        Sets the key to access the selected feature
    
        \b Visibility = Guru
    
        \b Selected by : ExpertFeatureAccessSelector
    
    */
    GenApi::IInteger &ExpertFeatureAccessKey;
    
    //@}
    

    //! \name ExpertFeatureAccess - 
    //@{
    /*!
        \brief Enable the selected Feature

        Enable the selected Feature
    
        \b Visibility = Guru
    
        \b Selected by : ExpertFeatureAccessSelector
    
    */
    GenApi::IBoolean &ExpertFeatureEnable;
    
    //@}
    

    //! \name ChunkDataStreams - This category includes items that control the chunk features available on the camera.
    //@{
    /*!
        \brief Enables the chunk mode

        This boolean value enables the camera's chunk mode.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IBoolean &ChunkModeActive;
    
    //@}
    

    //! \name ChunkDataStreams - This category includes items that control the chunk features available on the camera.
    //@{
    /*!
        \brief Enables the inclusion of the selected chunk in the payload data

        This boolean value enables the inclusion of the selected chunk in the payload data.
    
        \b Visibility = Beginner
        
    
        \b Selected by : ChunkSelector
    
    */
    GenApi::IBoolean &ChunkEnable;
    
    //@}
    

    //! \name ChunkDataStreams - This category includes items that control the chunk features available on the camera.
    //@{
    /*!
        \brief Selects chunks for enabling.

        This enumeration selects chunks for enabling.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<ChunkSelectorEnums > &ChunkSelector;
    
    //@}
    

    //! \name ChunkData - This category includes items related to the chunk data that can be appended to the image data
    //@{
    /*!
        \brief Indicates the number of bytes of data between the beginning of one line in the acquired image and the beginning of the next line in the acquired image

        This value indicates the number of bytes of data between the beginning of one line in the acquired image and the beginning of the next line in the acquired image.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &ChunkStride;
    
    //@}
    

    //! \name ChunkData - This category includes items related to the chunk data that can be appended to the image data
    //@{
    /*!
        \brief Indicates the X offset of the area of interest represented in the acquired image

        This value Indicates the X offset of the area of interest represented in the acquired image.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &ChunkOffsetX;
    
    //@}
    

    //! \name ChunkData - This category includes items related to the chunk data that can be appended to the image data
    //@{
    /*!
        \brief Indicates the Y offset of the area of interest represented in the acquired image

        This value Indicates the Y offset of the area of interest represented in the acquired image.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &ChunkOffsetY;
    
    //@}
    

    //! \name ChunkData - This category includes items related to the chunk data that can be appended to the image data
    //@{
    /*!
        \brief Indicates the widtth of the area of interest represented in the acquired image.

        This value Indicates the width of the area of interest represented in the acquired image.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &ChunkWidth;
    
    //@}
    

    //! \name ChunkData - This category includes items related to the chunk data that can be appended to the image data
    //@{
    /*!
        \brief Indicates the height of the area of interest represented in the acquired image.

        This value Indicates the height of the area of interest represented in the acquired image.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &ChunkHeight;
    
    //@}
    

    //! \name ChunkData - This category includes items related to the chunk data that can be appended to the image data
    //@{
    /*!
        \brief Indicates the minimum possible pixel value in the acquired image

        This value indicates the minimum possible pixel value in the acquired image.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &ChunkDynamicRangeMin;
    
    //@}
    

    //! \name ChunkData - This category includes items related to the chunk data that can be appended to the image data
    //@{
    /*!
        \brief Indicates the maximum possible pixel value in the acquired image

        This value indicates indicates the maximum possible pixel value acquired in the image
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &ChunkDynamicRangeMax;
    
    //@}
    

    //! \name ChunkData - This category includes items related to the chunk data that can be appended to the image data
    //@{
    /*!
        \brief Indicates the format of the pixel data in the acquired image

        This enumeration lists the pixel formats that can be indicated by the pixel format chunk.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<ChunkPixelFormatEnums > &ChunkPixelFormat;
    
    //@}
    

    //! \name ChunkData - This category includes items related to the chunk data that can be appended to the image data
    //@{
    /*!
        \brief Indicates the value of the timestamp when the image was acquired

        This integer indicates the value of the timestamp when the image was acquired.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &ChunkTimestamp;
    
    //@}
    

    //! \name ChunkData - This category includes items related to the chunk data that can be appended to the image data
    //@{
    /*!
        \brief Indicates the value of the frame counter when the image was acquired

        This integer indicates the value of the frame counter when the image was acquired.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &ChunkFramecounter;
    
    //@}
    

    //! \name ChunkData - This category includes items related to the chunk data that can be appended to the image data
    //@{
    /*!
        \brief A bit field that indicates the status of all of the camera's input and output lines when the image was acquired

        This value is a bit field that indicates the status of all of the camera's input and output lines when the image was acquired.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &ChunkLineStatusAll;
    
    //@}
    

    //! \name ChunkData - This category includes items related to the chunk data that can be appended to the image data
    //@{
    /*!
        \brief Indicates the value of the trigger input counter when the image was acquired

        This integer indicates the value of the trigger input counter when the image was acquired.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &ChunkTriggerinputcounter;
    
    //@}
    

    //! \name ChunkData - This category includes items related to the chunk data that can be appended to the image data
    //@{
    /*!
        \brief 

        
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IFloat &ChunkExposureTime;
    
    //@}
    

    //! \name EventsGeneration - This category includes items that control event generation by the camera.
    //@{
    /*!
        \brief Selects the type of event for enabling.

        This enumeration selects the type of event for enabling.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<EventSelectorEnums > &EventSelector;
    
    //@}
    

    //! \name EventsGeneration - This category includes items that control event generation by the camera.
    //@{
    /*!
        \brief Sets the notification type that will be sent to the host application for the selected event 

        This enumeration sets the notification type that will be sent to the host application for the selected event.
    
        \b Visibility = Beginner
        
    
        \b Selected by : EventSelector
    
    */
    GenApi::IEnumerationT<EventNotificationEnums > &EventNotification;
    
    //@}
    

    //! \name ExposureEndEventData - This category includes items available for an exposure end event
    //@{
    /*!
        \brief Indicates the stream channel index for an exposure end event

        This enumeration value indicates the stream channel index for an exposure end event.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &ExposureEndEventStreamChannelIndex;
    
    //@}
    

    //! \name ExposureEndEventData - This category includes items available for an exposure end event
    //@{
    /*!
        \brief Indicates the frame ID for an exposure end event

        This enumeration value indicates the frame ID for an exposure end event.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &ExposureEndEventFrameID;
    
    //@}
    

    //! \name ExposureEndEventData - This category includes items available for an exposure end event
    //@{
    /*!
        \brief Indicates the time stamp for an exposure end event

        This enumeration value indicates the time stamp for an exposure end event.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &ExposureEndEventTimestamp;
    
    //@}
    

    //! \name LineStartOvertriggerEventData - This category includes items available for an line start overtrigger event
    //@{
    /*!
        \brief Indicates the stream channel index for an line start overtrigger event

        This enumeration Indicates the stream channel index for an line start overtrigger event
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &LineStartOvertriggerEventStreamChannelIndex;
    
    //@}
    

    //! \name LineStartOvertriggerEventData - This category includes items available for an line start overtrigger event
    //@{
    /*!
        \brief Indicates the time stamp for an line start overtrigger event

        This enumeration value indicates the time stamp for an line start overtrigger event.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &LineStartOvertriggerEventTimestamp;
    
    //@}
    

    //! \name FrameStartOvertriggerEventData - This category includes items available for an frame start overtrigger event
    //@{
    /*!
        \brief Indicates the stream channel index for an frame start overtrigger event

        This enumeration Indicates the stream channel index for an frame start overtrigger event
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &FrameStartOvertriggerEventStreamChannelIndex;
    
    //@}
    

    //! \name FrameStartOvertriggerEventData - This category includes items available for an frame start overtrigger event
    //@{
    /*!
        \brief Indicates the time stamp for an frame start overtrigger event

        This enumeration value indicates the time stamp for an frame start overtrigger event.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &FrameStartOvertriggerEventTimestamp;
    
    //@}
    

    //! \name FrameStartEventData - This category includes items available for an frame start  event
    //@{
    /*!
        \brief Indicates the stream channel index for an frame start  event

        This enumeration Indicates the stream channel index for an frame start  event
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &FrameStartEventStreamChannelIndex;
    
    //@}
    

    //! \name FrameStartEventData - This category includes items available for an frame start  event
    //@{
    /*!
        \brief Indicates the time stamp for an frame start  event

        This enumeration value indicates the time stamp for an frame start  event.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &FrameStartEventTimestamp;
    
    //@}
    

    //! \name AcquisitionStartEventData - This category includes items available for an acquisition start  event
    //@{
    /*!
        \brief Indicates the stream channel index for an acquisition start  event

        This enumeration Indicates the stream channel index for an acquisition start  event
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &AcquisitionStartEventStreamChannelIndex;
    
    //@}
    

    //! \name AcquisitionStartEventData - This category includes items available for an acquisition start  event
    //@{
    /*!
        \brief Indicates the time stamp for an acquisition start  event

        This enumeration value indicates the time stamp for an acquisition start  event.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &AcquisitionStartEventTimestamp;
    
    //@}
    

    //! \name AcquisitionStartOvertriggerEventData - This category includes items available for an acquisition start overtrigger event
    //@{
    /*!
        \brief Indicates the stream channel index for an acquisition start overtrigger event

        This enumeration Indicates the stream channel index for an acquisition start overtrigger event
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &AcquisitionStartOvertriggerEventStreamChannelIndex;
    
    //@}
    

    //! \name AcquisitionStartOvertriggerEventData - This category includes items available for an acquisition start overtrigger event
    //@{
    /*!
        \brief Indicates the time stamp for an Acquisition start overtrigger event

        This enumeration value indicates the time stamp for an Acquisition start overtrigger event.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &AcquisitionStartOvertriggerEventTimestamp;
    
    //@}
    

    //! \name FrameTimeoutEventData - This category includes items available for an frame timeout event
    //@{
    /*!
        \brief Indicates the stream channel index for an frame timeout event

        This enumeration Indicates the stream channel index for an frame timeout event
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &FrameTimeoutEventStreamChannelIndex;
    
    //@}
    

    //! \name FrameTimeoutEventData - This category includes items available for an frame timeout event
    //@{
    /*!
        \brief Indicates the time stamp for an frame timeout event

        This enumeration value indicates the time stamp for an frame timeout event.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &FrameTimeoutEventTimestamp;
    
    //@}
    

    //! \name EventOverrunEventData - This category includes items available for an event overrun event
    //@{
    /*!
        \brief Indicates the stream channel index for an event overrun event

        This enumeration value indicates the stream channel index for an event overrun event
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &EventOverrunEventStreamChannelIndex;
    
    //@}
    

    //! \name EventOverrunEventData - This category includes items available for an event overrun event
    //@{
    /*!
        \brief Indicates the frame ID for an event overrun event

        This enumeration value indicates the frame ID for an event overrun event
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &EventOverrunEventFrameID;
    
    //@}
    

    //! \name EventOverrunEventData - This category includes items available for an event overrun event
    //@{
    /*!
        \brief Indicates the time stamp for an event overrun event

        This enumeration value indicates the time stamp for an event overrun event
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &EventOverrunEventTimestamp;
    
    //@}
    

    //! \name CriticalTemperatureEventData - This category includes items available for a critical temperature event
    //@{
    /*!
        \brief Indicates the stream channel index for a critical temperature event

        This enumeration Indicates the stream channel index for a critical temperature event.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &CriticalTemperatureEventStreamChannelIndex;
    
    //@}
    

    //! \name CriticalTemperatureEventData - This category includes items available for a critical temperature event
    //@{
    /*!
        \brief Indicates the time stamp for a critical temperature event

        This enumeration value indicates the time stamp for a critical temperature event.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &CriticalTemperatureEventTimestamp;
    
    //@}
    

    //! \name OverTemperatureEventData - This category includes items available for an over temperature event
    //@{
    /*!
        \brief Indicates the stream channel index for an over temperature event

        This enumeration Indicates the stream channel index for an over temperature event.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &OverTemperatureEventStreamChannelIndex;
    
    //@}
    

    //! \name OverTemperatureEventData - This category includes items available for an over temperature event
    //@{
    /*!
        \brief Indicates the time stamp for an over temperature event

        This enumeration value indicates the time stamp for an over temperature event.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &OverTemperatureEventTimestamp;
    
    //@}
    

    //! \name TransportLayer - This category includes items related to the IIDC 1394 transport specification
    //@{
    /*!
        \brief  Indicates whether a live grab is under way

        
    
        \b Visibility = Invisible
    
    */
    GenApi::IInteger &TLParamsLocked;
    
    //@}
    

    //! \name FileAccessControl - This category includes items used to conduct file operations
    //@{
    /*!
        \brief This feature selects the target file in the device

        The File Selector feature selects the target file in the device.
    
        \b Visibility = Guru
    
    */
    GenApi::IEnumerationT<FileSelectorEnums > &FileSelector;
    
    //@}
    

    //! \name FileAccessControl - This category includes items used to conduct file operations
    //@{
    /*!
        \brief Selects the target operation for the selected file

        The File Operation Selector feature selects the target operation for the selected file in the device. This Operation is executed when the FileOperationExecute feature is called.
    
        \b Visibility = Guru
    
        \b Selected by : FileSelector
    
    */
    GenApi::IEnumerationT<FileOperationSelectorEnums > &FileOperationSelector;
    
    //@}
    

    //! \name FileAccessControl - This category includes items used to conduct file operations
    //@{
    /*!
        \brief Selects the access mode in which a file is opened

        The File Open Mode feature selects the access mode in which a file is opened in the device.
    
        \b Visibility = Guru
    
        \b Selected by : FileSelector
    
    */
    GenApi::IEnumerationT<FileOpenModeEnums > &FileOpenMode;
    
    //@}
    

    //! \name FileAccessControl - This category includes items used to conduct file operations
    //@{
    /*!
        \brief Defines the intermediate access buffer

        The File Access Buffer feature defines the intermediate access buffer that allows the exchange of data between the device file storage and the application.
    
        \b Visibility = Guru
    
        \b Selected by : FileSelector
    
    */
    GenApi::IRegister &FileAccessBuffer;
    
    //@}
    

    //! \name FileAccessControl - This category includes items used to conduct file operations
    //@{
    /*!
        \brief Controls the mapping between the device file storage and the FileAccessBuffer

        This feature controls the mapping between the device file storage and the FileAccessBuffer.
    
        \b Visibility = Guru
    
        \b Selected by : FileSelector, FileOperationSelector
    
    */
    GenApi::IInteger &FileAccessOffset;
    
    //@}
    

    //! \name FileAccessControl - This category includes items used to conduct file operations
    //@{
    /*!
        \brief Controls the mapping between the device file storage and the FileAccessBuffer

        This feature controls the mapping between the device file storage and the FileAccessBuffer.
    
        \b Visibility = Guru
    
        \b Selected by : FileSelector, FileOperationSelector
    
    */
    GenApi::IInteger &FileAccessLength;
    
    //@}
    

    //! \name FileAccessControl - This category includes items used to conduct file operations
    //@{
    /*!
        \brief Represents the file operation execution status

        The File Operation Status feature represents the file operation execution status.
    
        \b Visibility = Guru
    
        \b Selected by : FileSelector, FileOperationSelector
    
    */
    GenApi::IEnumerationT<FileOperationStatusEnums > &FileOperationStatus;
    
    //@}
    

    //! \name FileAccessControl - This category includes items used to conduct file operations
    //@{
    /*!
        \brief Represents the file operation result

        The File Operation Result feature represents the file operation result. For Read or Write operations, the number of successfully read/written bytes is returned.
    
        \b Visibility = Guru
    
        \b Selected by : FileSelector, FileOperationSelector
    
    */
    GenApi::IInteger &FileOperationResult;
    
    //@}
    

    //! \name FileAccessControl - This category includes items used to conduct file operations
    //@{
    /*!
        \brief Represents the size of the selected file

        The File Size feature represents the size of the selected file in bytes.
    
        \b Visibility = Guru
    
        \b Selected by : FileSelector
    
    */
    GenApi::IInteger &FileSize;
    
    //@}
    

    //! \name FileAccessControl - This category includes items used to conduct file operations
    //@{
    /*!
        \brief Executes the selected operation

        The File Operation Execute feature is the command that executes the operation selected by FileOperationSelector on the selected file.
    
        \b Visibility = Guru
    
        \b Selected by : FileSelector, FileOperationSelector
    
    */
    GenApi::ICommand &FileOperationExecute;
    
    //@}
    


    private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
            CIIDC1394CameraParams_Params(CIIDC1394CameraParams_Params&);

            //! not implemented assignment operator
            CIIDC1394CameraParams_Params& operator=(CIIDC1394CameraParams_Params&);

        //! \endcond
    };


    //**************************************************************************************************
    // Parameter class implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS

    inline CIIDC1394CameraParams_Params::CIIDC1394CameraParams_Params(void)
        : GainAuto( *new GenApi::CEnumerationTRef<GainAutoEnums>() )
        , GainRaw( *new GenApi::CIntegerRef() )
        , GainSelector( *new GenApi::CEnumerationTRef<GainSelectorEnums>() )
        , BlackLevelRaw( *new GenApi::CIntegerRef() )
        , BlackLevelSelector( *new GenApi::CEnumerationTRef<BlackLevelSelectorEnums>() )
        , GammaEnable( *new GenApi::CBooleanRef() )
        , GammaSelector( *new GenApi::CEnumerationTRef<GammaSelectorEnums>() )
        , Gamma( *new GenApi::CFloatRef() )
        , DigitalShift( *new GenApi::CIntegerRef() )
        , SubstrateVoltage( *new GenApi::CIntegerRef() )
        , PixelFormat( *new GenApi::CEnumerationTRef<PixelFormatEnums>() )
        , PixelSize( *new GenApi::CEnumerationTRef<PixelSizeEnums>() )
        , PixelColorFilter( *new GenApi::CEnumerationTRef<PixelColorFilterEnums>() )
        , ProcessedRawEnable( *new GenApi::CBooleanRef() )
        , ReverseX( *new GenApi::CBooleanRef() )
        , ReverseY( *new GenApi::CBooleanRef() )
        , PixelDynamicRangeMin( *new GenApi::CIntegerRef() )
        , PixelDynamicRangeMax( *new GenApi::CIntegerRef() )
        , TestImageSelector( *new GenApi::CEnumerationTRef<TestImageSelectorEnums>() )
        , SensorWidth( *new GenApi::CIntegerRef() )
        , SensorHeight( *new GenApi::CIntegerRef() )
        , WidthMax( *new GenApi::CIntegerRef() )
        , HeightMax( *new GenApi::CIntegerRef() )
        , ColorTransformationSelector( *new GenApi::CEnumerationTRef<ColorTransformationSelectorEnums>() )
        , LightSourceSelector( *new GenApi::CEnumerationTRef<LightSourceSelectorEnums>() )
        , ColorTransformationMatrixFactor( *new GenApi::CFloatRef() )
        , ColorTransformationMatrixFactorRaw( *new GenApi::CIntegerRef() )
        , ColorTransformationValueSelector( *new GenApi::CEnumerationTRef<ColorTransformationValueSelectorEnums>() )
        , ColorTransformationValue( *new GenApi::CFloatRef() )
        , ColorTransformationValueRaw( *new GenApi::CIntegerRef() )
        , ColorAdjustmentEnable( *new GenApi::CBooleanRef() )
        , ColorAdjustmentReset( *new GenApi::CCommandRef() )
        , ColorAdjustmentSelector( *new GenApi::CEnumerationTRef<ColorAdjustmentSelectorEnums>() )
        , ColorAdjustmentHue( *new GenApi::CFloatRef() )
        , ColorAdjustmentHueRaw( *new GenApi::CIntegerRef() )
        , ColorAdjustmentSaturation( *new GenApi::CFloatRef() )
        , ColorAdjustmentSaturationRaw( *new GenApi::CIntegerRef() )
        , BalanceWhiteReset( *new GenApi::CCommandRef() )
        , BalanceWhiteAuto( *new GenApi::CEnumerationTRef<BalanceWhiteAutoEnums>() )
        , BalanceRatioSelector( *new GenApi::CEnumerationTRef<BalanceRatioSelectorEnums>() )
        , BalanceRatioAbs( *new GenApi::CFloatRef() )
        , BalanceRatioRaw( *new GenApi::CIntegerRef() )
        , Width( *new GenApi::CIntegerRef() )
        , Height( *new GenApi::CIntegerRef() )
        , OffsetX( *new GenApi::CIntegerRef() )
        , OffsetY( *new GenApi::CIntegerRef() )
        , BinningVertical( *new GenApi::CIntegerRef() )
        , BinningHorizontal( *new GenApi::CIntegerRef() )
        , LegacyBinningVertical( *new GenApi::CEnumerationTRef<LegacyBinningVerticalEnums>() )
        , EnableBurstAcquisition( *new GenApi::CBooleanRef() )
        , AcquisitionMode( *new GenApi::CEnumerationTRef<AcquisitionModeEnums>() )
        , AcquisitionStart( *new GenApi::CCommandRef() )
        , AcquisitionStop( *new GenApi::CCommandRef() )
        , AcquisitionFrameCount( *new GenApi::CIntegerRef() )
        , TriggerControlImplementation( *new GenApi::CEnumerationTRef<TriggerControlImplementationEnums>() )
        , TriggerSelector( *new GenApi::CEnumerationTRef<TriggerSelectorEnums>() )
        , TriggerMode( *new GenApi::CEnumerationTRef<TriggerModeEnums>() )
        , TriggerSoftware( *new GenApi::CCommandRef() )
        , TriggerSource( *new GenApi::CEnumerationTRef<TriggerSourceEnums>() )
        , TriggerActivation( *new GenApi::CEnumerationTRef<TriggerActivationEnums>() )
        , TriggerDelayAbs( *new GenApi::CFloatRef() )
        , ExposureAuto( *new GenApi::CEnumerationTRef<ExposureAutoEnums>() )
        , ExposureTimeRaw( *new GenApi::CIntegerRef() )
        , ExposureTimeAbs( *new GenApi::CFloatRef() )
        , ExposureTimeBaseAbs( *new GenApi::CFloatRef() )
        , ExposureTimeBaseAbsEnable( *new GenApi::CBooleanRef() )
        , AcquisitionFrameRateAbs( *new GenApi::CFloatRef() )
        , AcquisitionFrameRateEnable( *new GenApi::CBooleanRef() )
        , ResultingFrameRateAbs( *new GenApi::CFloatRef() )
        , ExposureMode( *new GenApi::CEnumerationTRef<ExposureModeEnums>() )
        , ReadoutTimeAbs( *new GenApi::CFloatRef() )
        , AcquisitionStatusSelector( *new GenApi::CEnumerationTRef<AcquisitionStatusSelectorEnums>() )
        , AcquisitionStatus( *new GenApi::CBooleanRef() )
        , LineSelector( *new GenApi::CEnumerationTRef<LineSelectorEnums>() )
        , LineInverter( *new GenApi::CBooleanRef() )
        , LineTermination( *new GenApi::CBooleanRef() )
        , LineDebouncerTimeRaw( *new GenApi::CIntegerRef() )
        , LineDebouncerTimeAbs( *new GenApi::CFloatRef() )
        , LineStatus( *new GenApi::CBooleanRef() )
        , LineStatusAll( *new GenApi::CIntegerRef() )
        , UserOutputValue( *new GenApi::CBooleanRef() )
        , UserOutputValueAll( *new GenApi::CIntegerRef() )
        , LineMode( *new GenApi::CEnumerationTRef<LineModeEnums>() )
        , LineSource( *new GenApi::CEnumerationTRef<LineSourceEnums>() )
        , LineLogic( *new GenApi::CEnumerationTRef<LineLogicEnums>() )
        , LineFormat( *new GenApi::CEnumerationTRef<LineFormatEnums>() )
        , UserOutputSelector( *new GenApi::CEnumerationTRef<UserOutputSelectorEnums>() )
        , TimerDurationTimebaseAbs( *new GenApi::CFloatRef() )
        , TimerDelayTimebaseAbs( *new GenApi::CFloatRef() )
        , TimerSelector( *new GenApi::CEnumerationTRef<TimerSelectorEnums>() )
        , TimerDurationAbs( *new GenApi::CFloatRef() )
        , TimerDurationRaw( *new GenApi::CIntegerRef() )
        , TimerDelayAbs( *new GenApi::CFloatRef() )
        , TimerDelayRaw( *new GenApi::CIntegerRef() )
        , TimerTriggerSource( *new GenApi::CEnumerationTRef<TimerTriggerSourceEnums>() )
        , TimerTriggerActivation( *new GenApi::CEnumerationTRef<TimerTriggerActivationEnums>() )
        , TimerSequenceEnable( *new GenApi::CBooleanRef() )
        , TimerSequenceLastEntryIndex( *new GenApi::CIntegerRef() )
        , TimerSequenceCurrentEntryIndex( *new GenApi::CIntegerRef() )
        , TimerSequenceEntrySelector( *new GenApi::CEnumerationTRef<TimerSequenceEntrySelectorEnums>() )
        , TimerSequenceTimerSelector( *new GenApi::CEnumerationTRef<TimerSequenceTimerSelectorEnums>() )
        , TimerSequenceTimerEnable( *new GenApi::CBooleanRef() )
        , TimerSequenceTimerInverter( *new GenApi::CBooleanRef() )
        , TimerSequenceTimerDelayRaw( *new GenApi::CIntegerRef() )
        , TimerSequenceTimerDurationRaw( *new GenApi::CIntegerRef() )
        , CounterSelector( *new GenApi::CEnumerationTRef<CounterSelectorEnums>() )
        , CounterEventSource( *new GenApi::CEnumerationTRef<CounterEventSourceEnums>() )
        , CounterResetSource( *new GenApi::CEnumerationTRef<CounterResetSourceEnums>() )
        , CounterReset( *new GenApi::CCommandRef() )
        , LUTEnable( *new GenApi::CBooleanRef() )
        , LUTIndex( *new GenApi::CIntegerRef() )
        , LUTValue( *new GenApi::CIntegerRef() )
        , LUTValueAll( *new GenApi::CRegisterRef() )
        , LUTSelector( *new GenApi::CEnumerationTRef<LUTSelectorEnums>() )
        , PayloadSize( *new GenApi::CIntegerRef() )
        , RecommendedPacketSize( *new GenApi::CIntegerRef() )
        , PacketSize( *new GenApi::CIntegerRef() )
        , UserSetLoad( *new GenApi::CCommandRef() )
        , UserSetSave( *new GenApi::CCommandRef() )
        , UserSetSelector( *new GenApi::CEnumerationTRef<UserSetSelectorEnums>() )
        , UserSetDefaultSelector( *new GenApi::CEnumerationTRef<UserSetDefaultSelectorEnums>() )
        , DefaultSetSelector( *new GenApi::CEnumerationTRef<DefaultSetSelectorEnums>() )
        , AutoTargetValue( *new GenApi::CIntegerRef() )
        , GrayValueAdjustmentDampingAbs( *new GenApi::CFloatRef() )
        , GrayValueAdjustmentDampingRaw( *new GenApi::CIntegerRef() )
        , AutoGainRawLowerLimit( *new GenApi::CIntegerRef() )
        , AutoGainRawUpperLimit( *new GenApi::CIntegerRef() )
        , AutoExposureTimeAbsLowerLimit( *new GenApi::CFloatRef() )
        , AutoExposureTimeAbsUpperLimit( *new GenApi::CFloatRef() )
        , AutoFunctionProfile( *new GenApi::CEnumerationTRef<AutoFunctionProfileEnums>() )
        , AutoFunctionAOIWidth( *new GenApi::CIntegerRef() )
        , AutoFunctionAOIHeight( *new GenApi::CIntegerRef() )
        , AutoFunctionAOIOffsetX( *new GenApi::CIntegerRef() )
        , AutoFunctionAOIOffsetY( *new GenApi::CIntegerRef() )
        , AutoFunctionAOIUsageIntensity( *new GenApi::CBooleanRef() )
        , AutoFunctionAOIUsageWhiteBalance( *new GenApi::CBooleanRef() )
        , AutoFunctionAOIUsageRedLightCorrection( *new GenApi::CBooleanRef() )
        , AutoFunctionAOISelector( *new GenApi::CEnumerationTRef<AutoFunctionAOISelectorEnums>() )
        , UserDefinedValueSelector( *new GenApi::CEnumerationTRef<UserDefinedValueSelectorEnums>() )
        , UserDefinedValue( *new GenApi::CIntegerRef() )
        , DeviceVendorName( *new GenApi::CStringRef() )
        , DeviceModelName( *new GenApi::CStringRef() )
        , DeviceSerialNumber( *new GenApi::CIntegerRef() )
        , DeviceFirmwareVersion( *new GenApi::CStringRef() )
        , DeviceUserID( *new GenApi::CStringRef() )
        , DeviceScanType( *new GenApi::CEnumerationTRef<DeviceScanTypeEnums>() )
        , DeviceReset( *new GenApi::CCommandRef() )
        , TemperatureSelector( *new GenApi::CEnumerationTRef<TemperatureSelectorEnums>() )
        , TemperatureAbs( *new GenApi::CFloatRef() )
        , RemoveLimits( *new GenApi::CBooleanRef() )
        , ParameterSelector( *new GenApi::CEnumerationTRef<ParameterSelectorEnums>() )
        , ExpertFeatureAccessSelector( *new GenApi::CEnumerationTRef<ExpertFeatureAccessSelectorEnums>() )
        , ExpertFeatureAccessKey( *new GenApi::CIntegerRef() )
        , ExpertFeatureEnable( *new GenApi::CBooleanRef() )
        , ChunkModeActive( *new GenApi::CBooleanRef() )
        , ChunkEnable( *new GenApi::CBooleanRef() )
        , ChunkSelector( *new GenApi::CEnumerationTRef<ChunkSelectorEnums>() )
        , ChunkStride( *new GenApi::CIntegerRef() )
        , ChunkOffsetX( *new GenApi::CIntegerRef() )
        , ChunkOffsetY( *new GenApi::CIntegerRef() )
        , ChunkWidth( *new GenApi::CIntegerRef() )
        , ChunkHeight( *new GenApi::CIntegerRef() )
        , ChunkDynamicRangeMin( *new GenApi::CIntegerRef() )
        , ChunkDynamicRangeMax( *new GenApi::CIntegerRef() )
        , ChunkPixelFormat( *new GenApi::CEnumerationTRef<ChunkPixelFormatEnums>() )
        , ChunkTimestamp( *new GenApi::CIntegerRef() )
        , ChunkFramecounter( *new GenApi::CIntegerRef() )
        , ChunkLineStatusAll( *new GenApi::CIntegerRef() )
        , ChunkTriggerinputcounter( *new GenApi::CIntegerRef() )
        , ChunkExposureTime( *new GenApi::CFloatRef() )
        , EventSelector( *new GenApi::CEnumerationTRef<EventSelectorEnums>() )
        , EventNotification( *new GenApi::CEnumerationTRef<EventNotificationEnums>() )
        , ExposureEndEventStreamChannelIndex( *new GenApi::CIntegerRef() )
        , ExposureEndEventFrameID( *new GenApi::CIntegerRef() )
        , ExposureEndEventTimestamp( *new GenApi::CIntegerRef() )
        , LineStartOvertriggerEventStreamChannelIndex( *new GenApi::CIntegerRef() )
        , LineStartOvertriggerEventTimestamp( *new GenApi::CIntegerRef() )
        , FrameStartOvertriggerEventStreamChannelIndex( *new GenApi::CIntegerRef() )
        , FrameStartOvertriggerEventTimestamp( *new GenApi::CIntegerRef() )
        , FrameStartEventStreamChannelIndex( *new GenApi::CIntegerRef() )
        , FrameStartEventTimestamp( *new GenApi::CIntegerRef() )
        , AcquisitionStartEventStreamChannelIndex( *new GenApi::CIntegerRef() )
        , AcquisitionStartEventTimestamp( *new GenApi::CIntegerRef() )
        , AcquisitionStartOvertriggerEventStreamChannelIndex( *new GenApi::CIntegerRef() )
        , AcquisitionStartOvertriggerEventTimestamp( *new GenApi::CIntegerRef() )
        , FrameTimeoutEventStreamChannelIndex( *new GenApi::CIntegerRef() )
        , FrameTimeoutEventTimestamp( *new GenApi::CIntegerRef() )
        , EventOverrunEventStreamChannelIndex( *new GenApi::CIntegerRef() )
        , EventOverrunEventFrameID( *new GenApi::CIntegerRef() )
        , EventOverrunEventTimestamp( *new GenApi::CIntegerRef() )
        , CriticalTemperatureEventStreamChannelIndex( *new GenApi::CIntegerRef() )
        , CriticalTemperatureEventTimestamp( *new GenApi::CIntegerRef() )
        , OverTemperatureEventStreamChannelIndex( *new GenApi::CIntegerRef() )
        , OverTemperatureEventTimestamp( *new GenApi::CIntegerRef() )
        , TLParamsLocked( *new GenApi::CIntegerRef() )
        , FileSelector( *new GenApi::CEnumerationTRef<FileSelectorEnums>() )
        , FileOperationSelector( *new GenApi::CEnumerationTRef<FileOperationSelectorEnums>() )
        , FileOpenMode( *new GenApi::CEnumerationTRef<FileOpenModeEnums>() )
        , FileAccessBuffer( *new GenApi::CRegisterRef() )
        , FileAccessOffset( *new GenApi::CIntegerRef() )
        , FileAccessLength( *new GenApi::CIntegerRef() )
        , FileOperationStatus( *new GenApi::CEnumerationTRef<FileOperationStatusEnums>() )
        , FileOperationResult( *new GenApi::CIntegerRef() )
        , FileSize( *new GenApi::CIntegerRef() )
        , FileOperationExecute( *new GenApi::CCommandRef() )
        
    {
    }

    inline CIIDC1394CameraParams_Params::~CIIDC1394CameraParams_Params(void)
    {
        delete static_cast < GenApi::CEnumerationTRef<GainAutoEnums> *> (&GainAuto );
        delete static_cast < GenApi::CIntegerRef*> (&GainRaw );
        delete static_cast < GenApi::CEnumerationTRef<GainSelectorEnums> *> (&GainSelector );
        delete static_cast < GenApi::CIntegerRef*> (&BlackLevelRaw );
        delete static_cast < GenApi::CEnumerationTRef<BlackLevelSelectorEnums> *> (&BlackLevelSelector );
        delete static_cast < GenApi::CBooleanRef*> (&GammaEnable );
        delete static_cast < GenApi::CEnumerationTRef<GammaSelectorEnums> *> (&GammaSelector );
        delete static_cast < GenApi::CFloatRef*> (&Gamma );
        delete static_cast < GenApi::CIntegerRef*> (&DigitalShift );
        delete static_cast < GenApi::CIntegerRef*> (&SubstrateVoltage );
        delete static_cast < GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat );
        delete static_cast < GenApi::CEnumerationTRef<PixelSizeEnums> *> (&PixelSize );
        delete static_cast < GenApi::CEnumerationTRef<PixelColorFilterEnums> *> (&PixelColorFilter );
        delete static_cast < GenApi::CBooleanRef*> (&ProcessedRawEnable );
        delete static_cast < GenApi::CBooleanRef*> (&ReverseX );
        delete static_cast < GenApi::CBooleanRef*> (&ReverseY );
        delete static_cast < GenApi::CIntegerRef*> (&PixelDynamicRangeMin );
        delete static_cast < GenApi::CIntegerRef*> (&PixelDynamicRangeMax );
        delete static_cast < GenApi::CEnumerationTRef<TestImageSelectorEnums> *> (&TestImageSelector );
        delete static_cast < GenApi::CIntegerRef*> (&SensorWidth );
        delete static_cast < GenApi::CIntegerRef*> (&SensorHeight );
        delete static_cast < GenApi::CIntegerRef*> (&WidthMax );
        delete static_cast < GenApi::CIntegerRef*> (&HeightMax );
        delete static_cast < GenApi::CEnumerationTRef<ColorTransformationSelectorEnums> *> (&ColorTransformationSelector );
        delete static_cast < GenApi::CEnumerationTRef<LightSourceSelectorEnums> *> (&LightSourceSelector );
        delete static_cast < GenApi::CFloatRef*> (&ColorTransformationMatrixFactor );
        delete static_cast < GenApi::CIntegerRef*> (&ColorTransformationMatrixFactorRaw );
        delete static_cast < GenApi::CEnumerationTRef<ColorTransformationValueSelectorEnums> *> (&ColorTransformationValueSelector );
        delete static_cast < GenApi::CFloatRef*> (&ColorTransformationValue );
        delete static_cast < GenApi::CIntegerRef*> (&ColorTransformationValueRaw );
        delete static_cast < GenApi::CBooleanRef*> (&ColorAdjustmentEnable );
        delete static_cast < GenApi::CCommandRef*> (&ColorAdjustmentReset );
        delete static_cast < GenApi::CEnumerationTRef<ColorAdjustmentSelectorEnums> *> (&ColorAdjustmentSelector );
        delete static_cast < GenApi::CFloatRef*> (&ColorAdjustmentHue );
        delete static_cast < GenApi::CIntegerRef*> (&ColorAdjustmentHueRaw );
        delete static_cast < GenApi::CFloatRef*> (&ColorAdjustmentSaturation );
        delete static_cast < GenApi::CIntegerRef*> (&ColorAdjustmentSaturationRaw );
        delete static_cast < GenApi::CCommandRef*> (&BalanceWhiteReset );
        delete static_cast < GenApi::CEnumerationTRef<BalanceWhiteAutoEnums> *> (&BalanceWhiteAuto );
        delete static_cast < GenApi::CEnumerationTRef<BalanceRatioSelectorEnums> *> (&BalanceRatioSelector );
        delete static_cast < GenApi::CFloatRef*> (&BalanceRatioAbs );
        delete static_cast < GenApi::CIntegerRef*> (&BalanceRatioRaw );
        delete static_cast < GenApi::CIntegerRef*> (&Width );
        delete static_cast < GenApi::CIntegerRef*> (&Height );
        delete static_cast < GenApi::CIntegerRef*> (&OffsetX );
        delete static_cast < GenApi::CIntegerRef*> (&OffsetY );
        delete static_cast < GenApi::CIntegerRef*> (&BinningVertical );
        delete static_cast < GenApi::CIntegerRef*> (&BinningHorizontal );
        delete static_cast < GenApi::CEnumerationTRef<LegacyBinningVerticalEnums> *> (&LegacyBinningVertical );
        delete static_cast < GenApi::CBooleanRef*> (&EnableBurstAcquisition );
        delete static_cast < GenApi::CEnumerationTRef<AcquisitionModeEnums> *> (&AcquisitionMode );
        delete static_cast < GenApi::CCommandRef*> (&AcquisitionStart );
        delete static_cast < GenApi::CCommandRef*> (&AcquisitionStop );
        delete static_cast < GenApi::CIntegerRef*> (&AcquisitionFrameCount );
        delete static_cast < GenApi::CEnumerationTRef<TriggerControlImplementationEnums> *> (&TriggerControlImplementation );
        delete static_cast < GenApi::CEnumerationTRef<TriggerSelectorEnums> *> (&TriggerSelector );
        delete static_cast < GenApi::CEnumerationTRef<TriggerModeEnums> *> (&TriggerMode );
        delete static_cast < GenApi::CCommandRef*> (&TriggerSoftware );
        delete static_cast < GenApi::CEnumerationTRef<TriggerSourceEnums> *> (&TriggerSource );
        delete static_cast < GenApi::CEnumerationTRef<TriggerActivationEnums> *> (&TriggerActivation );
        delete static_cast < GenApi::CFloatRef*> (&TriggerDelayAbs );
        delete static_cast < GenApi::CEnumerationTRef<ExposureAutoEnums> *> (&ExposureAuto );
        delete static_cast < GenApi::CIntegerRef*> (&ExposureTimeRaw );
        delete static_cast < GenApi::CFloatRef*> (&ExposureTimeAbs );
        delete static_cast < GenApi::CFloatRef*> (&ExposureTimeBaseAbs );
        delete static_cast < GenApi::CBooleanRef*> (&ExposureTimeBaseAbsEnable );
        delete static_cast < GenApi::CFloatRef*> (&AcquisitionFrameRateAbs );
        delete static_cast < GenApi::CBooleanRef*> (&AcquisitionFrameRateEnable );
        delete static_cast < GenApi::CFloatRef*> (&ResultingFrameRateAbs );
        delete static_cast < GenApi::CEnumerationTRef<ExposureModeEnums> *> (&ExposureMode );
        delete static_cast < GenApi::CFloatRef*> (&ReadoutTimeAbs );
        delete static_cast < GenApi::CEnumerationTRef<AcquisitionStatusSelectorEnums> *> (&AcquisitionStatusSelector );
        delete static_cast < GenApi::CBooleanRef*> (&AcquisitionStatus );
        delete static_cast < GenApi::CEnumerationTRef<LineSelectorEnums> *> (&LineSelector );
        delete static_cast < GenApi::CBooleanRef*> (&LineInverter );
        delete static_cast < GenApi::CBooleanRef*> (&LineTermination );
        delete static_cast < GenApi::CIntegerRef*> (&LineDebouncerTimeRaw );
        delete static_cast < GenApi::CFloatRef*> (&LineDebouncerTimeAbs );
        delete static_cast < GenApi::CBooleanRef*> (&LineStatus );
        delete static_cast < GenApi::CIntegerRef*> (&LineStatusAll );
        delete static_cast < GenApi::CBooleanRef*> (&UserOutputValue );
        delete static_cast < GenApi::CIntegerRef*> (&UserOutputValueAll );
        delete static_cast < GenApi::CEnumerationTRef<LineModeEnums> *> (&LineMode );
        delete static_cast < GenApi::CEnumerationTRef<LineSourceEnums> *> (&LineSource );
        delete static_cast < GenApi::CEnumerationTRef<LineLogicEnums> *> (&LineLogic );
        delete static_cast < GenApi::CEnumerationTRef<LineFormatEnums> *> (&LineFormat );
        delete static_cast < GenApi::CEnumerationTRef<UserOutputSelectorEnums> *> (&UserOutputSelector );
        delete static_cast < GenApi::CFloatRef*> (&TimerDurationTimebaseAbs );
        delete static_cast < GenApi::CFloatRef*> (&TimerDelayTimebaseAbs );
        delete static_cast < GenApi::CEnumerationTRef<TimerSelectorEnums> *> (&TimerSelector );
        delete static_cast < GenApi::CFloatRef*> (&TimerDurationAbs );
        delete static_cast < GenApi::CIntegerRef*> (&TimerDurationRaw );
        delete static_cast < GenApi::CFloatRef*> (&TimerDelayAbs );
        delete static_cast < GenApi::CIntegerRef*> (&TimerDelayRaw );
        delete static_cast < GenApi::CEnumerationTRef<TimerTriggerSourceEnums> *> (&TimerTriggerSource );
        delete static_cast < GenApi::CEnumerationTRef<TimerTriggerActivationEnums> *> (&TimerTriggerActivation );
        delete static_cast < GenApi::CBooleanRef*> (&TimerSequenceEnable );
        delete static_cast < GenApi::CIntegerRef*> (&TimerSequenceLastEntryIndex );
        delete static_cast < GenApi::CIntegerRef*> (&TimerSequenceCurrentEntryIndex );
        delete static_cast < GenApi::CEnumerationTRef<TimerSequenceEntrySelectorEnums> *> (&TimerSequenceEntrySelector );
        delete static_cast < GenApi::CEnumerationTRef<TimerSequenceTimerSelectorEnums> *> (&TimerSequenceTimerSelector );
        delete static_cast < GenApi::CBooleanRef*> (&TimerSequenceTimerEnable );
        delete static_cast < GenApi::CBooleanRef*> (&TimerSequenceTimerInverter );
        delete static_cast < GenApi::CIntegerRef*> (&TimerSequenceTimerDelayRaw );
        delete static_cast < GenApi::CIntegerRef*> (&TimerSequenceTimerDurationRaw );
        delete static_cast < GenApi::CEnumerationTRef<CounterSelectorEnums> *> (&CounterSelector );
        delete static_cast < GenApi::CEnumerationTRef<CounterEventSourceEnums> *> (&CounterEventSource );
        delete static_cast < GenApi::CEnumerationTRef<CounterResetSourceEnums> *> (&CounterResetSource );
        delete static_cast < GenApi::CCommandRef*> (&CounterReset );
        delete static_cast < GenApi::CBooleanRef*> (&LUTEnable );
        delete static_cast < GenApi::CIntegerRef*> (&LUTIndex );
        delete static_cast < GenApi::CIntegerRef*> (&LUTValue );
        delete static_cast < GenApi::CRegisterRef*> (&LUTValueAll );
        delete static_cast < GenApi::CEnumerationTRef<LUTSelectorEnums> *> (&LUTSelector );
        delete static_cast < GenApi::CIntegerRef*> (&PayloadSize );
        delete static_cast < GenApi::CIntegerRef*> (&RecommendedPacketSize );
        delete static_cast < GenApi::CIntegerRef*> (&PacketSize );
        delete static_cast < GenApi::CCommandRef*> (&UserSetLoad );
        delete static_cast < GenApi::CCommandRef*> (&UserSetSave );
        delete static_cast < GenApi::CEnumerationTRef<UserSetSelectorEnums> *> (&UserSetSelector );
        delete static_cast < GenApi::CEnumerationTRef<UserSetDefaultSelectorEnums> *> (&UserSetDefaultSelector );
        delete static_cast < GenApi::CEnumerationTRef<DefaultSetSelectorEnums> *> (&DefaultSetSelector );
        delete static_cast < GenApi::CIntegerRef*> (&AutoTargetValue );
        delete static_cast < GenApi::CFloatRef*> (&GrayValueAdjustmentDampingAbs );
        delete static_cast < GenApi::CIntegerRef*> (&GrayValueAdjustmentDampingRaw );
        delete static_cast < GenApi::CIntegerRef*> (&AutoGainRawLowerLimit );
        delete static_cast < GenApi::CIntegerRef*> (&AutoGainRawUpperLimit );
        delete static_cast < GenApi::CFloatRef*> (&AutoExposureTimeAbsLowerLimit );
        delete static_cast < GenApi::CFloatRef*> (&AutoExposureTimeAbsUpperLimit );
        delete static_cast < GenApi::CEnumerationTRef<AutoFunctionProfileEnums> *> (&AutoFunctionProfile );
        delete static_cast < GenApi::CIntegerRef*> (&AutoFunctionAOIWidth );
        delete static_cast < GenApi::CIntegerRef*> (&AutoFunctionAOIHeight );
        delete static_cast < GenApi::CIntegerRef*> (&AutoFunctionAOIOffsetX );
        delete static_cast < GenApi::CIntegerRef*> (&AutoFunctionAOIOffsetY );
        delete static_cast < GenApi::CBooleanRef*> (&AutoFunctionAOIUsageIntensity );
        delete static_cast < GenApi::CBooleanRef*> (&AutoFunctionAOIUsageWhiteBalance );
        delete static_cast < GenApi::CBooleanRef*> (&AutoFunctionAOIUsageRedLightCorrection );
        delete static_cast < GenApi::CEnumerationTRef<AutoFunctionAOISelectorEnums> *> (&AutoFunctionAOISelector );
        delete static_cast < GenApi::CEnumerationTRef<UserDefinedValueSelectorEnums> *> (&UserDefinedValueSelector );
        delete static_cast < GenApi::CIntegerRef*> (&UserDefinedValue );
        delete static_cast < GenApi::CStringRef*> (&DeviceVendorName );
        delete static_cast < GenApi::CStringRef*> (&DeviceModelName );
        delete static_cast < GenApi::CIntegerRef*> (&DeviceSerialNumber );
        delete static_cast < GenApi::CStringRef*> (&DeviceFirmwareVersion );
        delete static_cast < GenApi::CStringRef*> (&DeviceUserID );
        delete static_cast < GenApi::CEnumerationTRef<DeviceScanTypeEnums> *> (&DeviceScanType );
        delete static_cast < GenApi::CCommandRef*> (&DeviceReset );
        delete static_cast < GenApi::CEnumerationTRef<TemperatureSelectorEnums> *> (&TemperatureSelector );
        delete static_cast < GenApi::CFloatRef*> (&TemperatureAbs );
        delete static_cast < GenApi::CBooleanRef*> (&RemoveLimits );
        delete static_cast < GenApi::CEnumerationTRef<ParameterSelectorEnums> *> (&ParameterSelector );
        delete static_cast < GenApi::CEnumerationTRef<ExpertFeatureAccessSelectorEnums> *> (&ExpertFeatureAccessSelector );
        delete static_cast < GenApi::CIntegerRef*> (&ExpertFeatureAccessKey );
        delete static_cast < GenApi::CBooleanRef*> (&ExpertFeatureEnable );
        delete static_cast < GenApi::CBooleanRef*> (&ChunkModeActive );
        delete static_cast < GenApi::CBooleanRef*> (&ChunkEnable );
        delete static_cast < GenApi::CEnumerationTRef<ChunkSelectorEnums> *> (&ChunkSelector );
        delete static_cast < GenApi::CIntegerRef*> (&ChunkStride );
        delete static_cast < GenApi::CIntegerRef*> (&ChunkOffsetX );
        delete static_cast < GenApi::CIntegerRef*> (&ChunkOffsetY );
        delete static_cast < GenApi::CIntegerRef*> (&ChunkWidth );
        delete static_cast < GenApi::CIntegerRef*> (&ChunkHeight );
        delete static_cast < GenApi::CIntegerRef*> (&ChunkDynamicRangeMin );
        delete static_cast < GenApi::CIntegerRef*> (&ChunkDynamicRangeMax );
        delete static_cast < GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat );
        delete static_cast < GenApi::CIntegerRef*> (&ChunkTimestamp );
        delete static_cast < GenApi::CIntegerRef*> (&ChunkFramecounter );
        delete static_cast < GenApi::CIntegerRef*> (&ChunkLineStatusAll );
        delete static_cast < GenApi::CIntegerRef*> (&ChunkTriggerinputcounter );
        delete static_cast < GenApi::CFloatRef*> (&ChunkExposureTime );
        delete static_cast < GenApi::CEnumerationTRef<EventSelectorEnums> *> (&EventSelector );
        delete static_cast < GenApi::CEnumerationTRef<EventNotificationEnums> *> (&EventNotification );
        delete static_cast < GenApi::CIntegerRef*> (&ExposureEndEventStreamChannelIndex );
        delete static_cast < GenApi::CIntegerRef*> (&ExposureEndEventFrameID );
        delete static_cast < GenApi::CIntegerRef*> (&ExposureEndEventTimestamp );
        delete static_cast < GenApi::CIntegerRef*> (&LineStartOvertriggerEventStreamChannelIndex );
        delete static_cast < GenApi::CIntegerRef*> (&LineStartOvertriggerEventTimestamp );
        delete static_cast < GenApi::CIntegerRef*> (&FrameStartOvertriggerEventStreamChannelIndex );
        delete static_cast < GenApi::CIntegerRef*> (&FrameStartOvertriggerEventTimestamp );
        delete static_cast < GenApi::CIntegerRef*> (&FrameStartEventStreamChannelIndex );
        delete static_cast < GenApi::CIntegerRef*> (&FrameStartEventTimestamp );
        delete static_cast < GenApi::CIntegerRef*> (&AcquisitionStartEventStreamChannelIndex );
        delete static_cast < GenApi::CIntegerRef*> (&AcquisitionStartEventTimestamp );
        delete static_cast < GenApi::CIntegerRef*> (&AcquisitionStartOvertriggerEventStreamChannelIndex );
        delete static_cast < GenApi::CIntegerRef*> (&AcquisitionStartOvertriggerEventTimestamp );
        delete static_cast < GenApi::CIntegerRef*> (&FrameTimeoutEventStreamChannelIndex );
        delete static_cast < GenApi::CIntegerRef*> (&FrameTimeoutEventTimestamp );
        delete static_cast < GenApi::CIntegerRef*> (&EventOverrunEventStreamChannelIndex );
        delete static_cast < GenApi::CIntegerRef*> (&EventOverrunEventFrameID );
        delete static_cast < GenApi::CIntegerRef*> (&EventOverrunEventTimestamp );
        delete static_cast < GenApi::CIntegerRef*> (&CriticalTemperatureEventStreamChannelIndex );
        delete static_cast < GenApi::CIntegerRef*> (&CriticalTemperatureEventTimestamp );
        delete static_cast < GenApi::CIntegerRef*> (&OverTemperatureEventStreamChannelIndex );
        delete static_cast < GenApi::CIntegerRef*> (&OverTemperatureEventTimestamp );
        delete static_cast < GenApi::CIntegerRef*> (&TLParamsLocked );
        delete static_cast < GenApi::CEnumerationTRef<FileSelectorEnums> *> (&FileSelector );
        delete static_cast < GenApi::CEnumerationTRef<FileOperationSelectorEnums> *> (&FileOperationSelector );
        delete static_cast < GenApi::CEnumerationTRef<FileOpenModeEnums> *> (&FileOpenMode );
        delete static_cast < GenApi::CRegisterRef*> (&FileAccessBuffer );
        delete static_cast < GenApi::CIntegerRef*> (&FileAccessOffset );
        delete static_cast < GenApi::CIntegerRef*> (&FileAccessLength );
        delete static_cast < GenApi::CEnumerationTRef<FileOperationStatusEnums> *> (&FileOperationStatus );
        delete static_cast < GenApi::CIntegerRef*> (&FileOperationResult );
        delete static_cast < GenApi::CIntegerRef*> (&FileSize );
        delete static_cast < GenApi::CCommandRef*> (&FileOperationExecute );
        
    }

    inline void CIIDC1394CameraParams_Params::_Initialize(GenApi::INodeMap* _Ptr)
    {
        static_cast<GenApi::CEnumerationTRef<GainAutoEnums> *> (&GainAuto )->SetReference(_Ptr->GetNode("GainAuto"));
    static_cast<GenApi::CEnumerationTRef<GainAutoEnums> *> (&GainAuto )->SetNumEnums(3);
    static_cast<GenApi::CEnumerationTRef<GainAutoEnums> *> (&GainAuto )->SetEnumReference( GainAuto_Off, "Off" );        static_cast<GenApi::CEnumerationTRef<GainAutoEnums> *> (&GainAuto )->SetEnumReference( GainAuto_Once, "Once" );        static_cast<GenApi::CEnumerationTRef<GainAutoEnums> *> (&GainAuto )->SetEnumReference( GainAuto_Continuous, "Continuous" );        static_cast<GenApi::CIntegerRef*> (&GainRaw )->SetReference(_Ptr->GetNode("GainRaw"));
    static_cast<GenApi::CEnumerationTRef<GainSelectorEnums> *> (&GainSelector )->SetReference(_Ptr->GetNode("GainSelector"));
    static_cast<GenApi::CEnumerationTRef<GainSelectorEnums> *> (&GainSelector )->SetNumEnums(3);
    static_cast<GenApi::CEnumerationTRef<GainSelectorEnums> *> (&GainSelector )->SetEnumReference( GainSelector_All, "All" );        static_cast<GenApi::CEnumerationTRef<GainSelectorEnums> *> (&GainSelector )->SetEnumReference( GainSelector_Tap1, "Tap1" );        static_cast<GenApi::CEnumerationTRef<GainSelectorEnums> *> (&GainSelector )->SetEnumReference( GainSelector_Tap2, "Tap2" );        static_cast<GenApi::CIntegerRef*> (&BlackLevelRaw )->SetReference(_Ptr->GetNode("BlackLevelRaw"));
    static_cast<GenApi::CEnumerationTRef<BlackLevelSelectorEnums> *> (&BlackLevelSelector )->SetReference(_Ptr->GetNode("BlackLevelSelector"));
    static_cast<GenApi::CEnumerationTRef<BlackLevelSelectorEnums> *> (&BlackLevelSelector )->SetNumEnums(3);
    static_cast<GenApi::CEnumerationTRef<BlackLevelSelectorEnums> *> (&BlackLevelSelector )->SetEnumReference( BlackLevelSelector_All, "All" );        static_cast<GenApi::CEnumerationTRef<BlackLevelSelectorEnums> *> (&BlackLevelSelector )->SetEnumReference( BlackLevelSelector_Tap1, "Tap1" );        static_cast<GenApi::CEnumerationTRef<BlackLevelSelectorEnums> *> (&BlackLevelSelector )->SetEnumReference( BlackLevelSelector_Tap2, "Tap2" );        static_cast<GenApi::CBooleanRef*> (&GammaEnable )->SetReference(_Ptr->GetNode("GammaEnable"));
    static_cast<GenApi::CEnumerationTRef<GammaSelectorEnums> *> (&GammaSelector )->SetReference(_Ptr->GetNode("GammaSelector"));
    static_cast<GenApi::CEnumerationTRef<GammaSelectorEnums> *> (&GammaSelector )->SetNumEnums(2);
    static_cast<GenApi::CEnumerationTRef<GammaSelectorEnums> *> (&GammaSelector )->SetEnumReference( GammaSelector_User, "User" );        static_cast<GenApi::CEnumerationTRef<GammaSelectorEnums> *> (&GammaSelector )->SetEnumReference( GammaSelector_sRGB, "sRGB" );        static_cast<GenApi::CFloatRef*> (&Gamma )->SetReference(_Ptr->GetNode("Gamma"));
    static_cast<GenApi::CIntegerRef*> (&DigitalShift )->SetReference(_Ptr->GetNode("DigitalShift"));
    static_cast<GenApi::CIntegerRef*> (&SubstrateVoltage )->SetReference(_Ptr->GetNode("SubstrateVoltage"));
    static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetReference(_Ptr->GetNode("PixelFormat"));
    static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetNumEnums(30);
    static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_Mono8, "Mono8" );        static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_Mono1Packed, "Mono1Packed" );        static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_Mono10, "Mono10" );        static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_Mono12, "Mono12" );        static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_Mono12Packed, "Mono12Packed" );        static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_Mono16, "Mono16" );        static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_Mono2Packed, "Mono2Packed" );        static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_Mono4Packed, "Mono4Packed" );        static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerGR8, "BayerGR8" );        static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerRG8, "BayerRG8" );        static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerGB8, "BayerGB8" );        static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerBG8, "BayerBG8" );        static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerGR10, "BayerGR10" );        static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerRG10, "BayerRG10" );        static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerGB10, "BayerGB10" );        static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerBG10, "BayerBG10" );        static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerGR12, "BayerGR12" );        static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerRG12, "BayerRG12" );        static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerGB12, "BayerGB12" );        static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerBG12, "BayerBG12" );        static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_YUV422Packed, "YUV422Packed" );        static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_YUV422_YUYV_Packed, "YUV422_YUYV_Packed" );        static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerGB12Packed, "BayerGB12Packed" );        static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerGR12Packed, "BayerGR12Packed" );        static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerRG12Packed, "BayerRG12Packed" );        static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerBG12Packed, "BayerBG12Packed" );        static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerGR16, "BayerGR16" );        static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerRG16, "BayerRG16" );        static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerGB16, "BayerGB16" );        static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerBG16, "BayerBG16" );        static_cast<GenApi::CEnumerationTRef<PixelSizeEnums> *> (&PixelSize )->SetReference(_Ptr->GetNode("PixelSize"));
    static_cast<GenApi::CEnumerationTRef<PixelSizeEnums> *> (&PixelSize )->SetNumEnums(7);
    static_cast<GenApi::CEnumerationTRef<PixelSizeEnums> *> (&PixelSize )->SetEnumReference( PixelSize_Bpp1, "Bpp1" );        static_cast<GenApi::CEnumerationTRef<PixelSizeEnums> *> (&PixelSize )->SetEnumReference( PixelSize_Bpp2, "Bpp2" );        static_cast<GenApi::CEnumerationTRef<PixelSizeEnums> *> (&PixelSize )->SetEnumReference( PixelSize_Bpp4, "Bpp4" );        static_cast<GenApi::CEnumerationTRef<PixelSizeEnums> *> (&PixelSize )->SetEnumReference( PixelSize_Bpp8, "Bpp8" );        static_cast<GenApi::CEnumerationTRef<PixelSizeEnums> *> (&PixelSize )->SetEnumReference( PixelSize_Bpp10, "Bpp10" );        static_cast<GenApi::CEnumerationTRef<PixelSizeEnums> *> (&PixelSize )->SetEnumReference( PixelSize_Bpp12, "Bpp12" );        static_cast<GenApi::CEnumerationTRef<PixelSizeEnums> *> (&PixelSize )->SetEnumReference( PixelSize_Bpp16, "Bpp16" );        static_cast<GenApi::CEnumerationTRef<PixelColorFilterEnums> *> (&PixelColorFilter )->SetReference(_Ptr->GetNode("PixelColorFilter"));
    static_cast<GenApi::CEnumerationTRef<PixelColorFilterEnums> *> (&PixelColorFilter )->SetNumEnums(5);
    static_cast<GenApi::CEnumerationTRef<PixelColorFilterEnums> *> (&PixelColorFilter )->SetEnumReference( PixelColorFilter_Bayer_RG, "Bayer_RG" );        static_cast<GenApi::CEnumerationTRef<PixelColorFilterEnums> *> (&PixelColorFilter )->SetEnumReference( PixelColorFilter_Bayer_GB, "Bayer_GB" );        static_cast<GenApi::CEnumerationTRef<PixelColorFilterEnums> *> (&PixelColorFilter )->SetEnumReference( PixelColorFilter_Bayer_GR, "Bayer_GR" );        static_cast<GenApi::CEnumerationTRef<PixelColorFilterEnums> *> (&PixelColorFilter )->SetEnumReference( PixelColorFilter_Bayer_BG, "Bayer_BG" );        static_cast<GenApi::CEnumerationTRef<PixelColorFilterEnums> *> (&PixelColorFilter )->SetEnumReference( PixelColorFilter_None, "None" );        static_cast<GenApi::CBooleanRef*> (&ProcessedRawEnable )->SetReference(_Ptr->GetNode("ProcessedRawEnable"));
    static_cast<GenApi::CBooleanRef*> (&ReverseX )->SetReference(_Ptr->GetNode("ReverseX"));
    static_cast<GenApi::CBooleanRef*> (&ReverseY )->SetReference(_Ptr->GetNode("ReverseY"));
    static_cast<GenApi::CIntegerRef*> (&PixelDynamicRangeMin )->SetReference(_Ptr->GetNode("PixelDynamicRangeMin"));
    static_cast<GenApi::CIntegerRef*> (&PixelDynamicRangeMax )->SetReference(_Ptr->GetNode("PixelDynamicRangeMax"));
    static_cast<GenApi::CEnumerationTRef<TestImageSelectorEnums> *> (&TestImageSelector )->SetReference(_Ptr->GetNode("TestImageSelector"));
    static_cast<GenApi::CEnumerationTRef<TestImageSelectorEnums> *> (&TestImageSelector )->SetNumEnums(7);
    static_cast<GenApi::CEnumerationTRef<TestImageSelectorEnums> *> (&TestImageSelector )->SetEnumReference( TestImageSelector_Off, "Off" );        static_cast<GenApi::CEnumerationTRef<TestImageSelectorEnums> *> (&TestImageSelector )->SetEnumReference( TestImageSelector_Testimage1, "Testimage1" );        static_cast<GenApi::CEnumerationTRef<TestImageSelectorEnums> *> (&TestImageSelector )->SetEnumReference( TestImageSelector_Testimage2, "Testimage2" );        static_cast<GenApi::CEnumerationTRef<TestImageSelectorEnums> *> (&TestImageSelector )->SetEnumReference( TestImageSelector_Testimage3, "Testimage3" );        static_cast<GenApi::CEnumerationTRef<TestImageSelectorEnums> *> (&TestImageSelector )->SetEnumReference( TestImageSelector_Testimage4, "Testimage4" );        static_cast<GenApi::CEnumerationTRef<TestImageSelectorEnums> *> (&TestImageSelector )->SetEnumReference( TestImageSelector_Testimage5, "Testimage5" );        static_cast<GenApi::CEnumerationTRef<TestImageSelectorEnums> *> (&TestImageSelector )->SetEnumReference( TestImageSelector_Testimage6, "Testimage6" );        static_cast<GenApi::CIntegerRef*> (&SensorWidth )->SetReference(_Ptr->GetNode("SensorWidth"));
    static_cast<GenApi::CIntegerRef*> (&SensorHeight )->SetReference(_Ptr->GetNode("SensorHeight"));
    static_cast<GenApi::CIntegerRef*> (&WidthMax )->SetReference(_Ptr->GetNode("WidthMax"));
    static_cast<GenApi::CIntegerRef*> (&HeightMax )->SetReference(_Ptr->GetNode("HeightMax"));
    static_cast<GenApi::CEnumerationTRef<ColorTransformationSelectorEnums> *> (&ColorTransformationSelector )->SetReference(_Ptr->GetNode("ColorTransformationSelector"));
    static_cast<GenApi::CEnumerationTRef<ColorTransformationSelectorEnums> *> (&ColorTransformationSelector )->SetNumEnums(3);
    static_cast<GenApi::CEnumerationTRef<ColorTransformationSelectorEnums> *> (&ColorTransformationSelector )->SetEnumReference( ColorTransformationSelector_RGBtoRGB, "RGBtoRGB" );        static_cast<GenApi::CEnumerationTRef<ColorTransformationSelectorEnums> *> (&ColorTransformationSelector )->SetEnumReference( ColorTransformationSelector_RGBtoYUV, "RGBtoYUV" );        static_cast<GenApi::CEnumerationTRef<ColorTransformationSelectorEnums> *> (&ColorTransformationSelector )->SetEnumReference( ColorTransformationSelector_YUVtoRGB, "YUVtoRGB" );        static_cast<GenApi::CEnumerationTRef<LightSourceSelectorEnums> *> (&LightSourceSelector )->SetReference(_Ptr->GetNode("LightSourceSelector"));
    static_cast<GenApi::CEnumerationTRef<LightSourceSelectorEnums> *> (&LightSourceSelector )->SetNumEnums(7);
    static_cast<GenApi::CEnumerationTRef<LightSourceSelectorEnums> *> (&LightSourceSelector )->SetEnumReference( LightSourceSelector_Off, "Off" );        static_cast<GenApi::CEnumerationTRef<LightSourceSelectorEnums> *> (&LightSourceSelector )->SetEnumReference( LightSourceSelector_Custom, "Custom" );        static_cast<GenApi::CEnumerationTRef<LightSourceSelectorEnums> *> (&LightSourceSelector )->SetEnumReference( LightSourceSelector_Daylight, "Daylight" );        static_cast<GenApi::CEnumerationTRef<LightSourceSelectorEnums> *> (&LightSourceSelector )->SetEnumReference( LightSourceSelector_Tungsten, "Tungsten" );        static_cast<GenApi::CEnumerationTRef<LightSourceSelectorEnums> *> (&LightSourceSelector )->SetEnumReference( LightSourceSelector_Daylight6500K, "Daylight6500K" );        static_cast<GenApi::CEnumerationTRef<LightSourceSelectorEnums> *> (&LightSourceSelector )->SetEnumReference( LightSourceSelector_LightSource0, "LightSource0" );        static_cast<GenApi::CEnumerationTRef<LightSourceSelectorEnums> *> (&LightSourceSelector )->SetEnumReference( LightSourceSelector_LightSource1, "LightSource1" );        static_cast<GenApi::CFloatRef*> (&ColorTransformationMatrixFactor )->SetReference(_Ptr->GetNode("ColorTransformationMatrixFactor"));
    static_cast<GenApi::CIntegerRef*> (&ColorTransformationMatrixFactorRaw )->SetReference(_Ptr->GetNode("ColorTransformationMatrixFactorRaw"));
    static_cast<GenApi::CEnumerationTRef<ColorTransformationValueSelectorEnums> *> (&ColorTransformationValueSelector )->SetReference(_Ptr->GetNode("ColorTransformationValueSelector"));
    static_cast<GenApi::CEnumerationTRef<ColorTransformationValueSelectorEnums> *> (&ColorTransformationValueSelector )->SetNumEnums(9);
    static_cast<GenApi::CEnumerationTRef<ColorTransformationValueSelectorEnums> *> (&ColorTransformationValueSelector )->SetEnumReference( ColorTransformationValueSelector_Gain00, "Gain00" );        static_cast<GenApi::CEnumerationTRef<ColorTransformationValueSelectorEnums> *> (&ColorTransformationValueSelector )->SetEnumReference( ColorTransformationValueSelector_Gain01, "Gain01" );        static_cast<GenApi::CEnumerationTRef<ColorTransformationValueSelectorEnums> *> (&ColorTransformationValueSelector )->SetEnumReference( ColorTransformationValueSelector_Gain02, "Gain02" );        static_cast<GenApi::CEnumerationTRef<ColorTransformationValueSelectorEnums> *> (&ColorTransformationValueSelector )->SetEnumReference( ColorTransformationValueSelector_Gain10, "Gain10" );        static_cast<GenApi::CEnumerationTRef<ColorTransformationValueSelectorEnums> *> (&ColorTransformationValueSelector )->SetEnumReference( ColorTransformationValueSelector_Gain11, "Gain11" );        static_cast<GenApi::CEnumerationTRef<ColorTransformationValueSelectorEnums> *> (&ColorTransformationValueSelector )->SetEnumReference( ColorTransformationValueSelector_Gain12, "Gain12" );        static_cast<GenApi::CEnumerationTRef<ColorTransformationValueSelectorEnums> *> (&ColorTransformationValueSelector )->SetEnumReference( ColorTransformationValueSelector_Gain20, "Gain20" );        static_cast<GenApi::CEnumerationTRef<ColorTransformationValueSelectorEnums> *> (&ColorTransformationValueSelector )->SetEnumReference( ColorTransformationValueSelector_Gain21, "Gain21" );        static_cast<GenApi::CEnumerationTRef<ColorTransformationValueSelectorEnums> *> (&ColorTransformationValueSelector )->SetEnumReference( ColorTransformationValueSelector_Gain22, "Gain22" );        static_cast<GenApi::CFloatRef*> (&ColorTransformationValue )->SetReference(_Ptr->GetNode("ColorTransformationValue"));
    static_cast<GenApi::CIntegerRef*> (&ColorTransformationValueRaw )->SetReference(_Ptr->GetNode("ColorTransformationValueRaw"));
    static_cast<GenApi::CBooleanRef*> (&ColorAdjustmentEnable )->SetReference(_Ptr->GetNode("ColorAdjustmentEnable"));
    static_cast<GenApi::CCommandRef*> (&ColorAdjustmentReset )->SetReference(_Ptr->GetNode("ColorAdjustmentReset"));
    static_cast<GenApi::CEnumerationTRef<ColorAdjustmentSelectorEnums> *> (&ColorAdjustmentSelector )->SetReference(_Ptr->GetNode("ColorAdjustmentSelector"));
    static_cast<GenApi::CEnumerationTRef<ColorAdjustmentSelectorEnums> *> (&ColorAdjustmentSelector )->SetNumEnums(6);
    static_cast<GenApi::CEnumerationTRef<ColorAdjustmentSelectorEnums> *> (&ColorAdjustmentSelector )->SetEnumReference( ColorAdjustmentSelector_Red, "Red" );        static_cast<GenApi::CEnumerationTRef<ColorAdjustmentSelectorEnums> *> (&ColorAdjustmentSelector )->SetEnumReference( ColorAdjustmentSelector_Yellow, "Yellow" );        static_cast<GenApi::CEnumerationTRef<ColorAdjustmentSelectorEnums> *> (&ColorAdjustmentSelector )->SetEnumReference( ColorAdjustmentSelector_Green, "Green" );        static_cast<GenApi::CEnumerationTRef<ColorAdjustmentSelectorEnums> *> (&ColorAdjustmentSelector )->SetEnumReference( ColorAdjustmentSelector_Cyan, "Cyan" );        static_cast<GenApi::CEnumerationTRef<ColorAdjustmentSelectorEnums> *> (&ColorAdjustmentSelector )->SetEnumReference( ColorAdjustmentSelector_Blue, "Blue" );        static_cast<GenApi::CEnumerationTRef<ColorAdjustmentSelectorEnums> *> (&ColorAdjustmentSelector )->SetEnumReference( ColorAdjustmentSelector_Magenta, "Magenta" );        static_cast<GenApi::CFloatRef*> (&ColorAdjustmentHue )->SetReference(_Ptr->GetNode("ColorAdjustmentHue"));
    static_cast<GenApi::CIntegerRef*> (&ColorAdjustmentHueRaw )->SetReference(_Ptr->GetNode("ColorAdjustmentHueRaw"));
    static_cast<GenApi::CFloatRef*> (&ColorAdjustmentSaturation )->SetReference(_Ptr->GetNode("ColorAdjustmentSaturation"));
    static_cast<GenApi::CIntegerRef*> (&ColorAdjustmentSaturationRaw )->SetReference(_Ptr->GetNode("ColorAdjustmentSaturationRaw"));
    static_cast<GenApi::CCommandRef*> (&BalanceWhiteReset )->SetReference(_Ptr->GetNode("BalanceWhiteReset"));
    static_cast<GenApi::CEnumerationTRef<BalanceWhiteAutoEnums> *> (&BalanceWhiteAuto )->SetReference(_Ptr->GetNode("BalanceWhiteAuto"));
    static_cast<GenApi::CEnumerationTRef<BalanceWhiteAutoEnums> *> (&BalanceWhiteAuto )->SetNumEnums(3);
    static_cast<GenApi::CEnumerationTRef<BalanceWhiteAutoEnums> *> (&BalanceWhiteAuto )->SetEnumReference( BalanceWhiteAuto_Off, "Off" );        static_cast<GenApi::CEnumerationTRef<BalanceWhiteAutoEnums> *> (&BalanceWhiteAuto )->SetEnumReference( BalanceWhiteAuto_Once, "Once" );        static_cast<GenApi::CEnumerationTRef<BalanceWhiteAutoEnums> *> (&BalanceWhiteAuto )->SetEnumReference( BalanceWhiteAuto_Continuous, "Continuous" );        static_cast<GenApi::CEnumerationTRef<BalanceRatioSelectorEnums> *> (&BalanceRatioSelector )->SetReference(_Ptr->GetNode("BalanceRatioSelector"));
    static_cast<GenApi::CEnumerationTRef<BalanceRatioSelectorEnums> *> (&BalanceRatioSelector )->SetNumEnums(3);
    static_cast<GenApi::CEnumerationTRef<BalanceRatioSelectorEnums> *> (&BalanceRatioSelector )->SetEnumReference( BalanceRatioSelector_Red, "Red" );        static_cast<GenApi::CEnumerationTRef<BalanceRatioSelectorEnums> *> (&BalanceRatioSelector )->SetEnumReference( BalanceRatioSelector_Green, "Green" );        static_cast<GenApi::CEnumerationTRef<BalanceRatioSelectorEnums> *> (&BalanceRatioSelector )->SetEnumReference( BalanceRatioSelector_Blue, "Blue" );        static_cast<GenApi::CFloatRef*> (&BalanceRatioAbs )->SetReference(_Ptr->GetNode("BalanceRatioAbs"));
    static_cast<GenApi::CIntegerRef*> (&BalanceRatioRaw )->SetReference(_Ptr->GetNode("BalanceRatioRaw"));
    static_cast<GenApi::CIntegerRef*> (&Width )->SetReference(_Ptr->GetNode("Width"));
    static_cast<GenApi::CIntegerRef*> (&Height )->SetReference(_Ptr->GetNode("Height"));
    static_cast<GenApi::CIntegerRef*> (&OffsetX )->SetReference(_Ptr->GetNode("OffsetX"));
    static_cast<GenApi::CIntegerRef*> (&OffsetY )->SetReference(_Ptr->GetNode("OffsetY"));
    static_cast<GenApi::CIntegerRef*> (&BinningVertical )->SetReference(_Ptr->GetNode("BinningVertical"));
    static_cast<GenApi::CIntegerRef*> (&BinningHorizontal )->SetReference(_Ptr->GetNode("BinningHorizontal"));
    static_cast<GenApi::CEnumerationTRef<LegacyBinningVerticalEnums> *> (&LegacyBinningVertical )->SetReference(_Ptr->GetNode("LegacyBinningVertical"));
    static_cast<GenApi::CEnumerationTRef<LegacyBinningVerticalEnums> *> (&LegacyBinningVertical )->SetNumEnums(2);
    static_cast<GenApi::CEnumerationTRef<LegacyBinningVerticalEnums> *> (&LegacyBinningVertical )->SetEnumReference( LegacyBinningVertical_Off, "Off" );        static_cast<GenApi::CEnumerationTRef<LegacyBinningVerticalEnums> *> (&LegacyBinningVertical )->SetEnumReference( LegacyBinningVertical_Two_Rows, "Two_Rows" );        static_cast<GenApi::CBooleanRef*> (&EnableBurstAcquisition )->SetReference(_Ptr->GetNode("EnableBurstAcquisition"));
    static_cast<GenApi::CEnumerationTRef<AcquisitionModeEnums> *> (&AcquisitionMode )->SetReference(_Ptr->GetNode("AcquisitionMode"));
    static_cast<GenApi::CEnumerationTRef<AcquisitionModeEnums> *> (&AcquisitionMode )->SetNumEnums(2);
    static_cast<GenApi::CEnumerationTRef<AcquisitionModeEnums> *> (&AcquisitionMode )->SetEnumReference( AcquisitionMode_SingleFrame, "SingleFrame" );        static_cast<GenApi::CEnumerationTRef<AcquisitionModeEnums> *> (&AcquisitionMode )->SetEnumReference( AcquisitionMode_Continuous, "Continuous" );        static_cast<GenApi::CCommandRef*> (&AcquisitionStart )->SetReference(_Ptr->GetNode("AcquisitionStart"));
    static_cast<GenApi::CCommandRef*> (&AcquisitionStop )->SetReference(_Ptr->GetNode("AcquisitionStop"));
    static_cast<GenApi::CIntegerRef*> (&AcquisitionFrameCount )->SetReference(_Ptr->GetNode("AcquisitionFrameCount"));
    static_cast<GenApi::CEnumerationTRef<TriggerControlImplementationEnums> *> (&TriggerControlImplementation )->SetReference(_Ptr->GetNode("TriggerControlImplementation"));
    static_cast<GenApi::CEnumerationTRef<TriggerControlImplementationEnums> *> (&TriggerControlImplementation )->SetNumEnums(2);
    static_cast<GenApi::CEnumerationTRef<TriggerControlImplementationEnums> *> (&TriggerControlImplementation )->SetEnumReference( TriggerControlImplementation_Legacy, "Legacy" );        static_cast<GenApi::CEnumerationTRef<TriggerControlImplementationEnums> *> (&TriggerControlImplementation )->SetEnumReference( TriggerControlImplementation_Standard, "Standard" );        static_cast<GenApi::CEnumerationTRef<TriggerSelectorEnums> *> (&TriggerSelector )->SetReference(_Ptr->GetNode("TriggerSelector"));
    static_cast<GenApi::CEnumerationTRef<TriggerSelectorEnums> *> (&TriggerSelector )->SetNumEnums(2);
    static_cast<GenApi::CEnumerationTRef<TriggerSelectorEnums> *> (&TriggerSelector )->SetEnumReference( TriggerSelector_AcquisitionStart, "AcquisitionStart" );        static_cast<GenApi::CEnumerationTRef<TriggerSelectorEnums> *> (&TriggerSelector )->SetEnumReference( TriggerSelector_FrameStart, "FrameStart" );        static_cast<GenApi::CEnumerationTRef<TriggerModeEnums> *> (&TriggerMode )->SetReference(_Ptr->GetNode("TriggerMode"));
    static_cast<GenApi::CEnumerationTRef<TriggerModeEnums> *> (&TriggerMode )->SetNumEnums(2);
    static_cast<GenApi::CEnumerationTRef<TriggerModeEnums> *> (&TriggerMode )->SetEnumReference( TriggerMode_Off, "Off" );        static_cast<GenApi::CEnumerationTRef<TriggerModeEnums> *> (&TriggerMode )->SetEnumReference( TriggerMode_On, "On" );        static_cast<GenApi::CCommandRef*> (&TriggerSoftware )->SetReference(_Ptr->GetNode("TriggerSoftware"));
    static_cast<GenApi::CEnumerationTRef<TriggerSourceEnums> *> (&TriggerSource )->SetReference(_Ptr->GetNode("TriggerSource"));
    static_cast<GenApi::CEnumerationTRef<TriggerSourceEnums> *> (&TriggerSource )->SetNumEnums(5);
    static_cast<GenApi::CEnumerationTRef<TriggerSourceEnums> *> (&TriggerSource )->SetEnumReference( TriggerSource_Software, "Software" );        static_cast<GenApi::CEnumerationTRef<TriggerSourceEnums> *> (&TriggerSource )->SetEnumReference( TriggerSource_Line1, "Line1" );        static_cast<GenApi::CEnumerationTRef<TriggerSourceEnums> *> (&TriggerSource )->SetEnumReference( TriggerSource_Line2, "Line2" );        static_cast<GenApi::CEnumerationTRef<TriggerSourceEnums> *> (&TriggerSource )->SetEnumReference( TriggerSource_Line3, "Line3" );        static_cast<GenApi::CEnumerationTRef<TriggerSourceEnums> *> (&TriggerSource )->SetEnumReference( TriggerSource_Line4, "Line4" );        static_cast<GenApi::CEnumerationTRef<TriggerActivationEnums> *> (&TriggerActivation )->SetReference(_Ptr->GetNode("TriggerActivation"));
    static_cast<GenApi::CEnumerationTRef<TriggerActivationEnums> *> (&TriggerActivation )->SetNumEnums(2);
    static_cast<GenApi::CEnumerationTRef<TriggerActivationEnums> *> (&TriggerActivation )->SetEnumReference( TriggerActivation_RisingEdge, "RisingEdge" );        static_cast<GenApi::CEnumerationTRef<TriggerActivationEnums> *> (&TriggerActivation )->SetEnumReference( TriggerActivation_FallingEdge, "FallingEdge" );        static_cast<GenApi::CFloatRef*> (&TriggerDelayAbs )->SetReference(_Ptr->GetNode("TriggerDelayAbs"));
    static_cast<GenApi::CEnumerationTRef<ExposureAutoEnums> *> (&ExposureAuto )->SetReference(_Ptr->GetNode("ExposureAuto"));
    static_cast<GenApi::CEnumerationTRef<ExposureAutoEnums> *> (&ExposureAuto )->SetNumEnums(3);
    static_cast<GenApi::CEnumerationTRef<ExposureAutoEnums> *> (&ExposureAuto )->SetEnumReference( ExposureAuto_Off, "Off" );        static_cast<GenApi::CEnumerationTRef<ExposureAutoEnums> *> (&ExposureAuto )->SetEnumReference( ExposureAuto_Once, "Once" );        static_cast<GenApi::CEnumerationTRef<ExposureAutoEnums> *> (&ExposureAuto )->SetEnumReference( ExposureAuto_Continuous, "Continuous" );        static_cast<GenApi::CIntegerRef*> (&ExposureTimeRaw )->SetReference(_Ptr->GetNode("ExposureTimeRaw"));
    static_cast<GenApi::CFloatRef*> (&ExposureTimeAbs )->SetReference(_Ptr->GetNode("ExposureTimeAbs"));
    static_cast<GenApi::CFloatRef*> (&ExposureTimeBaseAbs )->SetReference(_Ptr->GetNode("ExposureTimeBaseAbs"));
    static_cast<GenApi::CBooleanRef*> (&ExposureTimeBaseAbsEnable )->SetReference(_Ptr->GetNode("ExposureTimeBaseAbsEnable"));
    static_cast<GenApi::CFloatRef*> (&AcquisitionFrameRateAbs )->SetReference(_Ptr->GetNode("AcquisitionFrameRateAbs"));
    static_cast<GenApi::CBooleanRef*> (&AcquisitionFrameRateEnable )->SetReference(_Ptr->GetNode("AcquisitionFrameRateEnable"));
    static_cast<GenApi::CFloatRef*> (&ResultingFrameRateAbs )->SetReference(_Ptr->GetNode("ResultingFrameRateAbs"));
    static_cast<GenApi::CEnumerationTRef<ExposureModeEnums> *> (&ExposureMode )->SetReference(_Ptr->GetNode("ExposureMode"));
    static_cast<GenApi::CEnumerationTRef<ExposureModeEnums> *> (&ExposureMode )->SetNumEnums(2);
    static_cast<GenApi::CEnumerationTRef<ExposureModeEnums> *> (&ExposureMode )->SetEnumReference( ExposureMode_Timed, "Timed" );        static_cast<GenApi::CEnumerationTRef<ExposureModeEnums> *> (&ExposureMode )->SetEnumReference( ExposureMode_TriggerWidth, "TriggerWidth" );        static_cast<GenApi::CFloatRef*> (&ReadoutTimeAbs )->SetReference(_Ptr->GetNode("ReadoutTimeAbs"));
    static_cast<GenApi::CEnumerationTRef<AcquisitionStatusSelectorEnums> *> (&AcquisitionStatusSelector )->SetReference(_Ptr->GetNode("AcquisitionStatusSelector"));
    static_cast<GenApi::CEnumerationTRef<AcquisitionStatusSelectorEnums> *> (&AcquisitionStatusSelector )->SetNumEnums(7);
    static_cast<GenApi::CEnumerationTRef<AcquisitionStatusSelectorEnums> *> (&AcquisitionStatusSelector )->SetEnumReference( AcquisitionStatusSelector_AcquisitionTriggerWait, "AcquisitionTriggerWait" );        static_cast<GenApi::CEnumerationTRef<AcquisitionStatusSelectorEnums> *> (&AcquisitionStatusSelector )->SetEnumReference( AcquisitionStatusSelector_AcquisitionActive, "AcquisitionActive" );        static_cast<GenApi::CEnumerationTRef<AcquisitionStatusSelectorEnums> *> (&AcquisitionStatusSelector )->SetEnumReference( AcquisitionStatusSelector_AcquisitionTransfer, "AcquisitionTransfer" );        static_cast<GenApi::CEnumerationTRef<AcquisitionStatusSelectorEnums> *> (&AcquisitionStatusSelector )->SetEnumReference( AcquisitionStatusSelector_FrameTriggerWait, "FrameTriggerWait" );        static_cast<GenApi::CEnumerationTRef<AcquisitionStatusSelectorEnums> *> (&AcquisitionStatusSelector )->SetEnumReference( AcquisitionStatusSelector_FrameActive, "FrameActive" );        static_cast<GenApi::CEnumerationTRef<AcquisitionStatusSelectorEnums> *> (&AcquisitionStatusSelector )->SetEnumReference( AcquisitionStatusSelector_FrameTransfer, "FrameTransfer" );        static_cast<GenApi::CEnumerationTRef<AcquisitionStatusSelectorEnums> *> (&AcquisitionStatusSelector )->SetEnumReference( AcquisitionStatusSelector_ExposureActive, "ExposureActive" );        static_cast<GenApi::CBooleanRef*> (&AcquisitionStatus )->SetReference(_Ptr->GetNode("AcquisitionStatus"));
    static_cast<GenApi::CEnumerationTRef<LineSelectorEnums> *> (&LineSelector )->SetReference(_Ptr->GetNode("LineSelector"));
    static_cast<GenApi::CEnumerationTRef<LineSelectorEnums> *> (&LineSelector )->SetNumEnums(6);
    static_cast<GenApi::CEnumerationTRef<LineSelectorEnums> *> (&LineSelector )->SetEnumReference( LineSelector_Line1, "Line1" );        static_cast<GenApi::CEnumerationTRef<LineSelectorEnums> *> (&LineSelector )->SetEnumReference( LineSelector_Line2, "Line2" );        static_cast<GenApi::CEnumerationTRef<LineSelectorEnums> *> (&LineSelector )->SetEnumReference( LineSelector_Out1, "Out1" );        static_cast<GenApi::CEnumerationTRef<LineSelectorEnums> *> (&LineSelector )->SetEnumReference( LineSelector_Out2, "Out2" );        static_cast<GenApi::CEnumerationTRef<LineSelectorEnums> *> (&LineSelector )->SetEnumReference( LineSelector_Out3, "Out3" );        static_cast<GenApi::CEnumerationTRef<LineSelectorEnums> *> (&LineSelector )->SetEnumReference( LineSelector_Out4, "Out4" );        static_cast<GenApi::CBooleanRef*> (&LineInverter )->SetReference(_Ptr->GetNode("LineInverter"));
    static_cast<GenApi::CBooleanRef*> (&LineTermination )->SetReference(_Ptr->GetNode("LineTermination"));
    static_cast<GenApi::CIntegerRef*> (&LineDebouncerTimeRaw )->SetReference(_Ptr->GetNode("LineDebouncerTimeRaw"));
    static_cast<GenApi::CFloatRef*> (&LineDebouncerTimeAbs )->SetReference(_Ptr->GetNode("LineDebouncerTimeAbs"));
    static_cast<GenApi::CBooleanRef*> (&LineStatus )->SetReference(_Ptr->GetNode("LineStatus"));
    static_cast<GenApi::CIntegerRef*> (&LineStatusAll )->SetReference(_Ptr->GetNode("LineStatusAll"));
    static_cast<GenApi::CBooleanRef*> (&UserOutputValue )->SetReference(_Ptr->GetNode("UserOutputValue"));
    static_cast<GenApi::CIntegerRef*> (&UserOutputValueAll )->SetReference(_Ptr->GetNode("UserOutputValueAll"));
    static_cast<GenApi::CEnumerationTRef<LineModeEnums> *> (&LineMode )->SetReference(_Ptr->GetNode("LineMode"));
    static_cast<GenApi::CEnumerationTRef<LineModeEnums> *> (&LineMode )->SetNumEnums(2);
    static_cast<GenApi::CEnumerationTRef<LineModeEnums> *> (&LineMode )->SetEnumReference( LineMode_Input, "Input" );        static_cast<GenApi::CEnumerationTRef<LineModeEnums> *> (&LineMode )->SetEnumReference( LineMode_Output, "Output" );        static_cast<GenApi::CEnumerationTRef<LineSourceEnums> *> (&LineSource )->SetReference(_Ptr->GetNode("LineSource"));
    static_cast<GenApi::CEnumerationTRef<LineSourceEnums> *> (&LineSource )->SetNumEnums(6);
    static_cast<GenApi::CEnumerationTRef<LineSourceEnums> *> (&LineSource )->SetEnumReference( LineSource_ExposureActive, "ExposureActive" );        static_cast<GenApi::CEnumerationTRef<LineSourceEnums> *> (&LineSource )->SetEnumReference( LineSource_TimerActive, "TimerActive" );        static_cast<GenApi::CEnumerationTRef<LineSourceEnums> *> (&LineSource )->SetEnumReference( LineSource_UserOutput, "UserOutput" );        static_cast<GenApi::CEnumerationTRef<LineSourceEnums> *> (&LineSource )->SetEnumReference( LineSource_TriggerReady, "TriggerReady" );        static_cast<GenApi::CEnumerationTRef<LineSourceEnums> *> (&LineSource )->SetEnumReference( LineSource_SerialTx, "SerialTx" );        static_cast<GenApi::CEnumerationTRef<LineSourceEnums> *> (&LineSource )->SetEnumReference( LineSource_AcquisitionTriggerReady, "AcquisitionTriggerReady" );        static_cast<GenApi::CEnumerationTRef<LineLogicEnums> *> (&LineLogic )->SetReference(_Ptr->GetNode("LineLogic"));
    static_cast<GenApi::CEnumerationTRef<LineLogicEnums> *> (&LineLogic )->SetNumEnums(2);
    static_cast<GenApi::CEnumerationTRef<LineLogicEnums> *> (&LineLogic )->SetEnumReference( LineLogic_Positive, "Positive" );        static_cast<GenApi::CEnumerationTRef<LineLogicEnums> *> (&LineLogic )->SetEnumReference( LineLogic_Negative, "Negative" );        static_cast<GenApi::CEnumerationTRef<LineFormatEnums> *> (&LineFormat )->SetReference(_Ptr->GetNode("LineFormat"));
    static_cast<GenApi::CEnumerationTRef<LineFormatEnums> *> (&LineFormat )->SetNumEnums(1);
    static_cast<GenApi::CEnumerationTRef<LineFormatEnums> *> (&LineFormat )->SetEnumReference( LineFormat_OptoCoupled, "OptoCoupled" );        static_cast<GenApi::CEnumerationTRef<UserOutputSelectorEnums> *> (&UserOutputSelector )->SetReference(_Ptr->GetNode("UserOutputSelector"));
    static_cast<GenApi::CEnumerationTRef<UserOutputSelectorEnums> *> (&UserOutputSelector )->SetNumEnums(4);
    static_cast<GenApi::CEnumerationTRef<UserOutputSelectorEnums> *> (&UserOutputSelector )->SetEnumReference( UserOutputSelector_UserOutput1, "UserOutput1" );        static_cast<GenApi::CEnumerationTRef<UserOutputSelectorEnums> *> (&UserOutputSelector )->SetEnumReference( UserOutputSelector_UserOutput2, "UserOutput2" );        static_cast<GenApi::CEnumerationTRef<UserOutputSelectorEnums> *> (&UserOutputSelector )->SetEnumReference( UserOutputSelector_UserOutput3, "UserOutput3" );        static_cast<GenApi::CEnumerationTRef<UserOutputSelectorEnums> *> (&UserOutputSelector )->SetEnumReference( UserOutputSelector_UserOutput4, "UserOutput4" );        static_cast<GenApi::CFloatRef*> (&TimerDurationTimebaseAbs )->SetReference(_Ptr->GetNode("TimerDurationTimebaseAbs"));
    static_cast<GenApi::CFloatRef*> (&TimerDelayTimebaseAbs )->SetReference(_Ptr->GetNode("TimerDelayTimebaseAbs"));
    static_cast<GenApi::CEnumerationTRef<TimerSelectorEnums> *> (&TimerSelector )->SetReference(_Ptr->GetNode("TimerSelector"));
    static_cast<GenApi::CEnumerationTRef<TimerSelectorEnums> *> (&TimerSelector )->SetNumEnums(4);
    static_cast<GenApi::CEnumerationTRef<TimerSelectorEnums> *> (&TimerSelector )->SetEnumReference( TimerSelector_Timer1, "Timer1" );        static_cast<GenApi::CEnumerationTRef<TimerSelectorEnums> *> (&TimerSelector )->SetEnumReference( TimerSelector_Timer2, "Timer2" );        static_cast<GenApi::CEnumerationTRef<TimerSelectorEnums> *> (&TimerSelector )->SetEnumReference( TimerSelector_Timer3, "Timer3" );        static_cast<GenApi::CEnumerationTRef<TimerSelectorEnums> *> (&TimerSelector )->SetEnumReference( TimerSelector_Timer4, "Timer4" );        static_cast<GenApi::CFloatRef*> (&TimerDurationAbs )->SetReference(_Ptr->GetNode("TimerDurationAbs"));
    static_cast<GenApi::CIntegerRef*> (&TimerDurationRaw )->SetReference(_Ptr->GetNode("TimerDurationRaw"));
    static_cast<GenApi::CFloatRef*> (&TimerDelayAbs )->SetReference(_Ptr->GetNode("TimerDelayAbs"));
    static_cast<GenApi::CIntegerRef*> (&TimerDelayRaw )->SetReference(_Ptr->GetNode("TimerDelayRaw"));
    static_cast<GenApi::CEnumerationTRef<TimerTriggerSourceEnums> *> (&TimerTriggerSource )->SetReference(_Ptr->GetNode("TimerTriggerSource"));
    static_cast<GenApi::CEnumerationTRef<TimerTriggerSourceEnums> *> (&TimerTriggerSource )->SetNumEnums(1);
    static_cast<GenApi::CEnumerationTRef<TimerTriggerSourceEnums> *> (&TimerTriggerSource )->SetEnumReference( TimerTriggerSource_ExposureStart, "ExposureStart" );        static_cast<GenApi::CEnumerationTRef<TimerTriggerActivationEnums> *> (&TimerTriggerActivation )->SetReference(_Ptr->GetNode("TimerTriggerActivation"));
    static_cast<GenApi::CEnumerationTRef<TimerTriggerActivationEnums> *> (&TimerTriggerActivation )->SetNumEnums(2);
    static_cast<GenApi::CEnumerationTRef<TimerTriggerActivationEnums> *> (&TimerTriggerActivation )->SetEnumReference( TimerTriggerActivation_RisingEdge, "RisingEdge" );        static_cast<GenApi::CEnumerationTRef<TimerTriggerActivationEnums> *> (&TimerTriggerActivation )->SetEnumReference( TimerTriggerActivation_FallingEdge, "FallingEdge" );        static_cast<GenApi::CBooleanRef*> (&TimerSequenceEnable )->SetReference(_Ptr->GetNode("TimerSequenceEnable"));
    static_cast<GenApi::CIntegerRef*> (&TimerSequenceLastEntryIndex )->SetReference(_Ptr->GetNode("TimerSequenceLastEntryIndex"));
    static_cast<GenApi::CIntegerRef*> (&TimerSequenceCurrentEntryIndex )->SetReference(_Ptr->GetNode("TimerSequenceCurrentEntryIndex"));
    static_cast<GenApi::CEnumerationTRef<TimerSequenceEntrySelectorEnums> *> (&TimerSequenceEntrySelector )->SetReference(_Ptr->GetNode("TimerSequenceEntrySelector"));
    static_cast<GenApi::CEnumerationTRef<TimerSequenceEntrySelectorEnums> *> (&TimerSequenceEntrySelector )->SetNumEnums(16);
    static_cast<GenApi::CEnumerationTRef<TimerSequenceEntrySelectorEnums> *> (&TimerSequenceEntrySelector )->SetEnumReference( TimerSequenceEntrySelector_Entry1, "Entry1" );        static_cast<GenApi::CEnumerationTRef<TimerSequenceEntrySelectorEnums> *> (&TimerSequenceEntrySelector )->SetEnumReference( TimerSequenceEntrySelector_Entry2, "Entry2" );        static_cast<GenApi::CEnumerationTRef<TimerSequenceEntrySelectorEnums> *> (&TimerSequenceEntrySelector )->SetEnumReference( TimerSequenceEntrySelector_Entry3, "Entry3" );        static_cast<GenApi::CEnumerationTRef<TimerSequenceEntrySelectorEnums> *> (&TimerSequenceEntrySelector )->SetEnumReference( TimerSequenceEntrySelector_Entry4, "Entry4" );        static_cast<GenApi::CEnumerationTRef<TimerSequenceEntrySelectorEnums> *> (&TimerSequenceEntrySelector )->SetEnumReference( TimerSequenceEntrySelector_Entry5, "Entry5" );        static_cast<GenApi::CEnumerationTRef<TimerSequenceEntrySelectorEnums> *> (&TimerSequenceEntrySelector )->SetEnumReference( TimerSequenceEntrySelector_Entry6, "Entry6" );        static_cast<GenApi::CEnumerationTRef<TimerSequenceEntrySelectorEnums> *> (&TimerSequenceEntrySelector )->SetEnumReference( TimerSequenceEntrySelector_Entry7, "Entry7" );        static_cast<GenApi::CEnumerationTRef<TimerSequenceEntrySelectorEnums> *> (&TimerSequenceEntrySelector )->SetEnumReference( TimerSequenceEntrySelector_Entry8, "Entry8" );        static_cast<GenApi::CEnumerationTRef<TimerSequenceEntrySelectorEnums> *> (&TimerSequenceEntrySelector )->SetEnumReference( TimerSequenceEntrySelector_Entry9, "Entry9" );        static_cast<GenApi::CEnumerationTRef<TimerSequenceEntrySelectorEnums> *> (&TimerSequenceEntrySelector )->SetEnumReference( TimerSequenceEntrySelector_Entry10, "Entry10" );        static_cast<GenApi::CEnumerationTRef<TimerSequenceEntrySelectorEnums> *> (&TimerSequenceEntrySelector )->SetEnumReference( TimerSequenceEntrySelector_Entry11, "Entry11" );        static_cast<GenApi::CEnumerationTRef<TimerSequenceEntrySelectorEnums> *> (&TimerSequenceEntrySelector )->SetEnumReference( TimerSequenceEntrySelector_Entry12, "Entry12" );        static_cast<GenApi::CEnumerationTRef<TimerSequenceEntrySelectorEnums> *> (&TimerSequenceEntrySelector )->SetEnumReference( TimerSequenceEntrySelector_Entry13, "Entry13" );        static_cast<GenApi::CEnumerationTRef<TimerSequenceEntrySelectorEnums> *> (&TimerSequenceEntrySelector )->SetEnumReference( TimerSequenceEntrySelector_Entry14, "Entry14" );        static_cast<GenApi::CEnumerationTRef<TimerSequenceEntrySelectorEnums> *> (&TimerSequenceEntrySelector )->SetEnumReference( TimerSequenceEntrySelector_Entry15, "Entry15" );        static_cast<GenApi::CEnumerationTRef<TimerSequenceEntrySelectorEnums> *> (&TimerSequenceEntrySelector )->SetEnumReference( TimerSequenceEntrySelector_Entry16, "Entry16" );        static_cast<GenApi::CEnumerationTRef<TimerSequenceTimerSelectorEnums> *> (&TimerSequenceTimerSelector )->SetReference(_Ptr->GetNode("TimerSequenceTimerSelector"));
    static_cast<GenApi::CEnumerationTRef<TimerSequenceTimerSelectorEnums> *> (&TimerSequenceTimerSelector )->SetNumEnums(4);
    static_cast<GenApi::CEnumerationTRef<TimerSequenceTimerSelectorEnums> *> (&TimerSequenceTimerSelector )->SetEnumReference( TimerSequenceTimerSelector_Timer1, "Timer1" );        static_cast<GenApi::CEnumerationTRef<TimerSequenceTimerSelectorEnums> *> (&TimerSequenceTimerSelector )->SetEnumReference( TimerSequenceTimerSelector_Timer2, "Timer2" );        static_cast<GenApi::CEnumerationTRef<TimerSequenceTimerSelectorEnums> *> (&TimerSequenceTimerSelector )->SetEnumReference( TimerSequenceTimerSelector_Timer3, "Timer3" );        static_cast<GenApi::CEnumerationTRef<TimerSequenceTimerSelectorEnums> *> (&TimerSequenceTimerSelector )->SetEnumReference( TimerSequenceTimerSelector_Timer4, "Timer4" );        static_cast<GenApi::CBooleanRef*> (&TimerSequenceTimerEnable )->SetReference(_Ptr->GetNode("TimerSequenceTimerEnable"));
    static_cast<GenApi::CBooleanRef*> (&TimerSequenceTimerInverter )->SetReference(_Ptr->GetNode("TimerSequenceTimerInverter"));
    static_cast<GenApi::CIntegerRef*> (&TimerSequenceTimerDelayRaw )->SetReference(_Ptr->GetNode("TimerSequenceTimerDelayRaw"));
    static_cast<GenApi::CIntegerRef*> (&TimerSequenceTimerDurationRaw )->SetReference(_Ptr->GetNode("TimerSequenceTimerDurationRaw"));
    static_cast<GenApi::CEnumerationTRef<CounterSelectorEnums> *> (&CounterSelector )->SetReference(_Ptr->GetNode("CounterSelector"));
    static_cast<GenApi::CEnumerationTRef<CounterSelectorEnums> *> (&CounterSelector )->SetNumEnums(2);
    static_cast<GenApi::CEnumerationTRef<CounterSelectorEnums> *> (&CounterSelector )->SetEnumReference( CounterSelector_Counter1, "Counter1" );        static_cast<GenApi::CEnumerationTRef<CounterSelectorEnums> *> (&CounterSelector )->SetEnumReference( CounterSelector_Counter2, "Counter2" );        static_cast<GenApi::CEnumerationTRef<CounterEventSourceEnums> *> (&CounterEventSource )->SetReference(_Ptr->GetNode("CounterEventSource"));
    static_cast<GenApi::CEnumerationTRef<CounterEventSourceEnums> *> (&CounterEventSource )->SetNumEnums(2);
    static_cast<GenApi::CEnumerationTRef<CounterEventSourceEnums> *> (&CounterEventSource )->SetEnumReference( CounterEventSource_FrameTrigger, "FrameTrigger" );        static_cast<GenApi::CEnumerationTRef<CounterEventSourceEnums> *> (&CounterEventSource )->SetEnumReference( CounterEventSource_FrameStart, "FrameStart" );        static_cast<GenApi::CEnumerationTRef<CounterResetSourceEnums> *> (&CounterResetSource )->SetReference(_Ptr->GetNode("CounterResetSource"));
    static_cast<GenApi::CEnumerationTRef<CounterResetSourceEnums> *> (&CounterResetSource )->SetNumEnums(4);
    static_cast<GenApi::CEnumerationTRef<CounterResetSourceEnums> *> (&CounterResetSource )->SetEnumReference( CounterResetSource_Off, "Off" );        static_cast<GenApi::CEnumerationTRef<CounterResetSourceEnums> *> (&CounterResetSource )->SetEnumReference( CounterResetSource_Software, "Software" );        static_cast<GenApi::CEnumerationTRef<CounterResetSourceEnums> *> (&CounterResetSource )->SetEnumReference( CounterResetSource_Line1, "Line1" );        static_cast<GenApi::CEnumerationTRef<CounterResetSourceEnums> *> (&CounterResetSource )->SetEnumReference( CounterResetSource_Line2, "Line2" );        static_cast<GenApi::CCommandRef*> (&CounterReset )->SetReference(_Ptr->GetNode("CounterReset"));
    static_cast<GenApi::CBooleanRef*> (&LUTEnable )->SetReference(_Ptr->GetNode("LUTEnable"));
    static_cast<GenApi::CIntegerRef*> (&LUTIndex )->SetReference(_Ptr->GetNode("LUTIndex"));
    static_cast<GenApi::CIntegerRef*> (&LUTValue )->SetReference(_Ptr->GetNode("LUTValue"));
    static_cast<GenApi::CRegisterRef*> (&LUTValueAll )->SetReference(_Ptr->GetNode("LUTValueAll"));
    static_cast<GenApi::CEnumerationTRef<LUTSelectorEnums> *> (&LUTSelector )->SetReference(_Ptr->GetNode("LUTSelector"));
    static_cast<GenApi::CEnumerationTRef<LUTSelectorEnums> *> (&LUTSelector )->SetNumEnums(1);
    static_cast<GenApi::CEnumerationTRef<LUTSelectorEnums> *> (&LUTSelector )->SetEnumReference( LUTSelector_Luminance, "Luminance" );        static_cast<GenApi::CIntegerRef*> (&PayloadSize )->SetReference(_Ptr->GetNode("PayloadSize"));
    static_cast<GenApi::CIntegerRef*> (&RecommendedPacketSize )->SetReference(_Ptr->GetNode("RecommendedPacketSize"));
    static_cast<GenApi::CIntegerRef*> (&PacketSize )->SetReference(_Ptr->GetNode("PacketSize"));
    static_cast<GenApi::CCommandRef*> (&UserSetLoad )->SetReference(_Ptr->GetNode("UserSetLoad"));
    static_cast<GenApi::CCommandRef*> (&UserSetSave )->SetReference(_Ptr->GetNode("UserSetSave"));
    static_cast<GenApi::CEnumerationTRef<UserSetSelectorEnums> *> (&UserSetSelector )->SetReference(_Ptr->GetNode("UserSetSelector"));
    static_cast<GenApi::CEnumerationTRef<UserSetSelectorEnums> *> (&UserSetSelector )->SetNumEnums(4);
    static_cast<GenApi::CEnumerationTRef<UserSetSelectorEnums> *> (&UserSetSelector )->SetEnumReference( UserSetSelector_Default, "Default" );        static_cast<GenApi::CEnumerationTRef<UserSetSelectorEnums> *> (&UserSetSelector )->SetEnumReference( UserSetSelector_UserSet1, "UserSet1" );        static_cast<GenApi::CEnumerationTRef<UserSetSelectorEnums> *> (&UserSetSelector )->SetEnumReference( UserSetSelector_UserSet2, "UserSet2" );        static_cast<GenApi::CEnumerationTRef<UserSetSelectorEnums> *> (&UserSetSelector )->SetEnumReference( UserSetSelector_UserSet3, "UserSet3" );        static_cast<GenApi::CEnumerationTRef<UserSetDefaultSelectorEnums> *> (&UserSetDefaultSelector )->SetReference(_Ptr->GetNode("UserSetDefaultSelector"));
    static_cast<GenApi::CEnumerationTRef<UserSetDefaultSelectorEnums> *> (&UserSetDefaultSelector )->SetNumEnums(4);
    static_cast<GenApi::CEnumerationTRef<UserSetDefaultSelectorEnums> *> (&UserSetDefaultSelector )->SetEnumReference( UserSetDefaultSelector_Default, "Default" );        static_cast<GenApi::CEnumerationTRef<UserSetDefaultSelectorEnums> *> (&UserSetDefaultSelector )->SetEnumReference( UserSetDefaultSelector_UserSet1, "UserSet1" );        static_cast<GenApi::CEnumerationTRef<UserSetDefaultSelectorEnums> *> (&UserSetDefaultSelector )->SetEnumReference( UserSetDefaultSelector_UserSet2, "UserSet2" );        static_cast<GenApi::CEnumerationTRef<UserSetDefaultSelectorEnums> *> (&UserSetDefaultSelector )->SetEnumReference( UserSetDefaultSelector_UserSet3, "UserSet3" );        static_cast<GenApi::CEnumerationTRef<DefaultSetSelectorEnums> *> (&DefaultSetSelector )->SetReference(_Ptr->GetNode("DefaultSetSelector"));
    static_cast<GenApi::CEnumerationTRef<DefaultSetSelectorEnums> *> (&DefaultSetSelector )->SetNumEnums(6);
    static_cast<GenApi::CEnumerationTRef<DefaultSetSelectorEnums> *> (&DefaultSetSelector )->SetEnumReference( DefaultSetSelector_Standard, "Standard" );        static_cast<GenApi::CEnumerationTRef<DefaultSetSelectorEnums> *> (&DefaultSetSelector )->SetEnumReference( DefaultSetSelector_HighGain, "HighGain" );        static_cast<GenApi::CEnumerationTRef<DefaultSetSelectorEnums> *> (&DefaultSetSelector )->SetEnumReference( DefaultSetSelector_AutoFunctions, "AutoFunctions" );        static_cast<GenApi::CEnumerationTRef<DefaultSetSelectorEnums> *> (&DefaultSetSelector )->SetEnumReference( DefaultSetSelector_Color, "Color" );        static_cast<GenApi::CEnumerationTRef<DefaultSetSelectorEnums> *> (&DefaultSetSelector )->SetEnumReference( DefaultSetSelector_Custom0, "Custom0" );        static_cast<GenApi::CEnumerationTRef<DefaultSetSelectorEnums> *> (&DefaultSetSelector )->SetEnumReference( DefaultSetSelector_Custom1, "Custom1" );        static_cast<GenApi::CIntegerRef*> (&AutoTargetValue )->SetReference(_Ptr->GetNode("AutoTargetValue"));
    static_cast<GenApi::CFloatRef*> (&GrayValueAdjustmentDampingAbs )->SetReference(_Ptr->GetNode("GrayValueAdjustmentDampingAbs"));
    static_cast<GenApi::CIntegerRef*> (&GrayValueAdjustmentDampingRaw )->SetReference(_Ptr->GetNode("GrayValueAdjustmentDampingRaw"));
    static_cast<GenApi::CIntegerRef*> (&AutoGainRawLowerLimit )->SetReference(_Ptr->GetNode("AutoGainRawLowerLimit"));
    static_cast<GenApi::CIntegerRef*> (&AutoGainRawUpperLimit )->SetReference(_Ptr->GetNode("AutoGainRawUpperLimit"));
    static_cast<GenApi::CFloatRef*> (&AutoExposureTimeAbsLowerLimit )->SetReference(_Ptr->GetNode("AutoExposureTimeAbsLowerLimit"));
    static_cast<GenApi::CFloatRef*> (&AutoExposureTimeAbsUpperLimit )->SetReference(_Ptr->GetNode("AutoExposureTimeAbsUpperLimit"));
    static_cast<GenApi::CEnumerationTRef<AutoFunctionProfileEnums> *> (&AutoFunctionProfile )->SetReference(_Ptr->GetNode("AutoFunctionProfile"));
    static_cast<GenApi::CEnumerationTRef<AutoFunctionProfileEnums> *> (&AutoFunctionProfile )->SetNumEnums(2);
    static_cast<GenApi::CEnumerationTRef<AutoFunctionProfileEnums> *> (&AutoFunctionProfile )->SetEnumReference( AutoFunctionProfile_GainMinimum, "GainMinimum" );        static_cast<GenApi::CEnumerationTRef<AutoFunctionProfileEnums> *> (&AutoFunctionProfile )->SetEnumReference( AutoFunctionProfile_ExposureMinimum, "ExposureMinimum" );        static_cast<GenApi::CIntegerRef*> (&AutoFunctionAOIWidth )->SetReference(_Ptr->GetNode("AutoFunctionAOIWidth"));
    static_cast<GenApi::CIntegerRef*> (&AutoFunctionAOIHeight )->SetReference(_Ptr->GetNode("AutoFunctionAOIHeight"));
    static_cast<GenApi::CIntegerRef*> (&AutoFunctionAOIOffsetX )->SetReference(_Ptr->GetNode("AutoFunctionAOIOffsetX"));
    static_cast<GenApi::CIntegerRef*> (&AutoFunctionAOIOffsetY )->SetReference(_Ptr->GetNode("AutoFunctionAOIOffsetY"));
    static_cast<GenApi::CBooleanRef*> (&AutoFunctionAOIUsageIntensity )->SetReference(_Ptr->GetNode("AutoFunctionAOIUsageIntensity"));
    static_cast<GenApi::CBooleanRef*> (&AutoFunctionAOIUsageWhiteBalance )->SetReference(_Ptr->GetNode("AutoFunctionAOIUsageWhiteBalance"));
    static_cast<GenApi::CBooleanRef*> (&AutoFunctionAOIUsageRedLightCorrection )->SetReference(_Ptr->GetNode("AutoFunctionAOIUsageRedLightCorrection"));
    static_cast<GenApi::CEnumerationTRef<AutoFunctionAOISelectorEnums> *> (&AutoFunctionAOISelector )->SetReference(_Ptr->GetNode("AutoFunctionAOISelector"));
    static_cast<GenApi::CEnumerationTRef<AutoFunctionAOISelectorEnums> *> (&AutoFunctionAOISelector )->SetNumEnums(2);
    static_cast<GenApi::CEnumerationTRef<AutoFunctionAOISelectorEnums> *> (&AutoFunctionAOISelector )->SetEnumReference( AutoFunctionAOISelector_AOI1, "AOI1" );        static_cast<GenApi::CEnumerationTRef<AutoFunctionAOISelectorEnums> *> (&AutoFunctionAOISelector )->SetEnumReference( AutoFunctionAOISelector_AOI2, "AOI2" );        static_cast<GenApi::CEnumerationTRef<UserDefinedValueSelectorEnums> *> (&UserDefinedValueSelector )->SetReference(_Ptr->GetNode("UserDefinedValueSelector"));
    static_cast<GenApi::CEnumerationTRef<UserDefinedValueSelectorEnums> *> (&UserDefinedValueSelector )->SetNumEnums(5);
    static_cast<GenApi::CEnumerationTRef<UserDefinedValueSelectorEnums> *> (&UserDefinedValueSelector )->SetEnumReference( UserDefinedValueSelector_Value1, "Value1" );        static_cast<GenApi::CEnumerationTRef<UserDefinedValueSelectorEnums> *> (&UserDefinedValueSelector )->SetEnumReference( UserDefinedValueSelector_Value2, "Value2" );        static_cast<GenApi::CEnumerationTRef<UserDefinedValueSelectorEnums> *> (&UserDefinedValueSelector )->SetEnumReference( UserDefinedValueSelector_Value3, "Value3" );        static_cast<GenApi::CEnumerationTRef<UserDefinedValueSelectorEnums> *> (&UserDefinedValueSelector )->SetEnumReference( UserDefinedValueSelector_Value4, "Value4" );        static_cast<GenApi::CEnumerationTRef<UserDefinedValueSelectorEnums> *> (&UserDefinedValueSelector )->SetEnumReference( UserDefinedValueSelector_Value5, "Value5" );        static_cast<GenApi::CIntegerRef*> (&UserDefinedValue )->SetReference(_Ptr->GetNode("UserDefinedValue"));
    static_cast<GenApi::CStringRef*> (&DeviceVendorName )->SetReference(_Ptr->GetNode("DeviceVendorName"));
    static_cast<GenApi::CStringRef*> (&DeviceModelName )->SetReference(_Ptr->GetNode("DeviceModelName"));
    static_cast<GenApi::CIntegerRef*> (&DeviceSerialNumber )->SetReference(_Ptr->GetNode("DeviceSerialNumber"));
    static_cast<GenApi::CStringRef*> (&DeviceFirmwareVersion )->SetReference(_Ptr->GetNode("DeviceFirmwareVersion"));
    static_cast<GenApi::CStringRef*> (&DeviceUserID )->SetReference(_Ptr->GetNode("DeviceUserID"));
    static_cast<GenApi::CEnumerationTRef<DeviceScanTypeEnums> *> (&DeviceScanType )->SetReference(_Ptr->GetNode("DeviceScanType"));
    static_cast<GenApi::CEnumerationTRef<DeviceScanTypeEnums> *> (&DeviceScanType )->SetNumEnums(2);
    static_cast<GenApi::CEnumerationTRef<DeviceScanTypeEnums> *> (&DeviceScanType )->SetEnumReference( DeviceScanType_Areascan, "Areascan" );        static_cast<GenApi::CEnumerationTRef<DeviceScanTypeEnums> *> (&DeviceScanType )->SetEnumReference( DeviceScanType_Linescan, "Linescan" );        static_cast<GenApi::CCommandRef*> (&DeviceReset )->SetReference(_Ptr->GetNode("DeviceReset"));
    static_cast<GenApi::CEnumerationTRef<TemperatureSelectorEnums> *> (&TemperatureSelector )->SetReference(_Ptr->GetNode("TemperatureSelector"));
    static_cast<GenApi::CEnumerationTRef<TemperatureSelectorEnums> *> (&TemperatureSelector )->SetNumEnums(4);
    static_cast<GenApi::CEnumerationTRef<TemperatureSelectorEnums> *> (&TemperatureSelector )->SetEnumReference( TemperatureSelector_Sensorboard, "Sensorboard" );        static_cast<GenApi::CEnumerationTRef<TemperatureSelectorEnums> *> (&TemperatureSelector )->SetEnumReference( TemperatureSelector_Coreboard, "Coreboard" );        static_cast<GenApi::CEnumerationTRef<TemperatureSelectorEnums> *> (&TemperatureSelector )->SetEnumReference( TemperatureSelector_Framegrabberboard, "Framegrabberboard" );        static_cast<GenApi::CEnumerationTRef<TemperatureSelectorEnums> *> (&TemperatureSelector )->SetEnumReference( TemperatureSelector_Case, "Case" );        static_cast<GenApi::CFloatRef*> (&TemperatureAbs )->SetReference(_Ptr->GetNode("TemperatureAbs"));
    static_cast<GenApi::CBooleanRef*> (&RemoveLimits )->SetReference(_Ptr->GetNode("RemoveLimits"));
    static_cast<GenApi::CEnumerationTRef<ParameterSelectorEnums> *> (&ParameterSelector )->SetReference(_Ptr->GetNode("ParameterSelector"));
    static_cast<GenApi::CEnumerationTRef<ParameterSelectorEnums> *> (&ParameterSelector )->SetNumEnums(3);
    static_cast<GenApi::CEnumerationTRef<ParameterSelectorEnums> *> (&ParameterSelector )->SetEnumReference( ParameterSelector_Gain, "Gain" );        static_cast<GenApi::CEnumerationTRef<ParameterSelectorEnums> *> (&ParameterSelector )->SetEnumReference( ParameterSelector_Brightness, "Brightness" );        static_cast<GenApi::CEnumerationTRef<ParameterSelectorEnums> *> (&ParameterSelector )->SetEnumReference( ParameterSelector_ExposureTime, "ExposureTime" );        static_cast<GenApi::CEnumerationTRef<ExpertFeatureAccessSelectorEnums> *> (&ExpertFeatureAccessSelector )->SetReference(_Ptr->GetNode("ExpertFeatureAccessSelector"));
    static_cast<GenApi::CEnumerationTRef<ExpertFeatureAccessSelectorEnums> *> (&ExpertFeatureAccessSelector )->SetNumEnums(6);
    static_cast<GenApi::CEnumerationTRef<ExpertFeatureAccessSelectorEnums> *> (&ExpertFeatureAccessSelector )->SetEnumReference( ExpertFeatureAccessSelector_ExpertFeature1_Legacy, "ExpertFeature1_Legacy" );        static_cast<GenApi::CEnumerationTRef<ExpertFeatureAccessSelectorEnums> *> (&ExpertFeatureAccessSelector )->SetEnumReference( ExpertFeatureAccessSelector_ExpertFeature1, "ExpertFeature1" );        static_cast<GenApi::CEnumerationTRef<ExpertFeatureAccessSelectorEnums> *> (&ExpertFeatureAccessSelector )->SetEnumReference( ExpertFeatureAccessSelector_ExpertFeature2, "ExpertFeature2" );        static_cast<GenApi::CEnumerationTRef<ExpertFeatureAccessSelectorEnums> *> (&ExpertFeatureAccessSelector )->SetEnumReference( ExpertFeatureAccessSelector_ExpertFeature3, "ExpertFeature3" );        static_cast<GenApi::CEnumerationTRef<ExpertFeatureAccessSelectorEnums> *> (&ExpertFeatureAccessSelector )->SetEnumReference( ExpertFeatureAccessSelector_ExpertFeature4, "ExpertFeature4" );        static_cast<GenApi::CEnumerationTRef<ExpertFeatureAccessSelectorEnums> *> (&ExpertFeatureAccessSelector )->SetEnumReference( ExpertFeatureAccessSelector_ExpertFeature5, "ExpertFeature5" );        static_cast<GenApi::CIntegerRef*> (&ExpertFeatureAccessKey )->SetReference(_Ptr->GetNode("ExpertFeatureAccessKey"));
    static_cast<GenApi::CBooleanRef*> (&ExpertFeatureEnable )->SetReference(_Ptr->GetNode("ExpertFeatureEnable"));
    static_cast<GenApi::CBooleanRef*> (&ChunkModeActive )->SetReference(_Ptr->GetNode("ChunkModeActive"));
    static_cast<GenApi::CBooleanRef*> (&ChunkEnable )->SetReference(_Ptr->GetNode("ChunkEnable"));
    static_cast<GenApi::CEnumerationTRef<ChunkSelectorEnums> *> (&ChunkSelector )->SetReference(_Ptr->GetNode("ChunkSelector"));
    static_cast<GenApi::CEnumerationTRef<ChunkSelectorEnums> *> (&ChunkSelector )->SetNumEnums(15);
    static_cast<GenApi::CEnumerationTRef<ChunkSelectorEnums> *> (&ChunkSelector )->SetEnumReference( ChunkSelector_Image, "Image" );        static_cast<GenApi::CEnumerationTRef<ChunkSelectorEnums> *> (&ChunkSelector )->SetEnumReference( ChunkSelector_OffsetX, "OffsetX" );        static_cast<GenApi::CEnumerationTRef<ChunkSelectorEnums> *> (&ChunkSelector )->SetEnumReference( ChunkSelector_OffsetY, "OffsetY" );        static_cast<GenApi::CEnumerationTRef<ChunkSelectorEnums> *> (&ChunkSelector )->SetEnumReference( ChunkSelector_Width, "Width" );        static_cast<GenApi::CEnumerationTRef<ChunkSelectorEnums> *> (&ChunkSelector )->SetEnumReference( ChunkSelector_Height, "Height" );        static_cast<GenApi::CEnumerationTRef<ChunkSelectorEnums> *> (&ChunkSelector )->SetEnumReference( ChunkSelector_PixelFormat, "PixelFormat" );        static_cast<GenApi::CEnumerationTRef<ChunkSelectorEnums> *> (&ChunkSelector )->SetEnumReference( ChunkSelector_DynamicRangeMax, "DynamicRangeMax" );        static_cast<GenApi::CEnumerationTRef<ChunkSelectorEnums> *> (&ChunkSelector )->SetEnumReference( ChunkSelector_DynamicRangeMin, "DynamicRangeMin" );        static_cast<GenApi::CEnumerationTRef<ChunkSelectorEnums> *> (&ChunkSelector )->SetEnumReference( ChunkSelector_Timestamp, "Timestamp" );        static_cast<GenApi::CEnumerationTRef<ChunkSelectorEnums> *> (&ChunkSelector )->SetEnumReference( ChunkSelector_LineStatusAll, "LineStatusAll" );        static_cast<GenApi::CEnumerationTRef<ChunkSelectorEnums> *> (&ChunkSelector )->SetEnumReference( ChunkSelector_Framecounter, "Framecounter" );        static_cast<GenApi::CEnumerationTRef<ChunkSelectorEnums> *> (&ChunkSelector )->SetEnumReference( ChunkSelector_Triggerinputcounter, "Triggerinputcounter" );        static_cast<GenApi::CEnumerationTRef<ChunkSelectorEnums> *> (&ChunkSelector )->SetEnumReference( ChunkSelector_PayloadCRC16, "PayloadCRC16" );        static_cast<GenApi::CEnumerationTRef<ChunkSelectorEnums> *> (&ChunkSelector )->SetEnumReference( ChunkSelector_Stride, "Stride" );        static_cast<GenApi::CEnumerationTRef<ChunkSelectorEnums> *> (&ChunkSelector )->SetEnumReference( ChunkSelector_ExposureTime, "ExposureTime" );        static_cast<GenApi::CIntegerRef*> (&ChunkStride )->SetReference(_Ptr->GetNode("ChunkStride"));
    static_cast<GenApi::CIntegerRef*> (&ChunkOffsetX )->SetReference(_Ptr->GetNode("ChunkOffsetX"));
    static_cast<GenApi::CIntegerRef*> (&ChunkOffsetY )->SetReference(_Ptr->GetNode("ChunkOffsetY"));
    static_cast<GenApi::CIntegerRef*> (&ChunkWidth )->SetReference(_Ptr->GetNode("ChunkWidth"));
    static_cast<GenApi::CIntegerRef*> (&ChunkHeight )->SetReference(_Ptr->GetNode("ChunkHeight"));
    static_cast<GenApi::CIntegerRef*> (&ChunkDynamicRangeMin )->SetReference(_Ptr->GetNode("ChunkDynamicRangeMin"));
    static_cast<GenApi::CIntegerRef*> (&ChunkDynamicRangeMax )->SetReference(_Ptr->GetNode("ChunkDynamicRangeMax"));
    static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetReference(_Ptr->GetNode("ChunkPixelFormat"));
    static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetNumEnums(46);
    static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_Mono8, "Mono8" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_Mono8Signed, "Mono8Signed" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_Mono10, "Mono10" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_Mono10Packed, "Mono10Packed" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_Mono12, "Mono12" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_Mono12Packed, "Mono12Packed" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_Mono16, "Mono16" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_BayerGR8, "BayerGR8" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_BayerRG8, "BayerRG8" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_BayerGB8, "BayerGB8" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_BayerBG8, "BayerBG8" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_BayerGR10, "BayerGR10" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_BayerRG10, "BayerRG10" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_BayerGB10, "BayerGB10" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_BayerBG10, "BayerBG10" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_BayerGR12, "BayerGR12" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_BayerRG12, "BayerRG12" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_BayerGB12, "BayerGB12" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_BayerBG12, "BayerBG12" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_BayerGR16, "BayerGR16" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_BayerRG16, "BayerRG16" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_BayerGB16, "BayerGB16" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_BayerBG16, "BayerBG16" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_RGB8Packed, "RGB8Packed" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_BGR8Packed, "BGR8Packed" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_RGBA8Packed, "RGBA8Packed" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_BGRA8Packed, "BGRA8Packed" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_RGB10Packed, "RGB10Packed" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_BGR10Packed, "BGR10Packed" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_RGB12Packed, "RGB12Packed" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_BGR12Packed, "BGR12Packed" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_RGB10V1Packed, "RGB10V1Packed" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_RGB10V2Packed, "RGB10V2Packed" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_YUV411Packed, "YUV411Packed" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_YUV422Packed, "YUV422Packed" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_YUV444Packed, "YUV444Packed" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_RGB8Planar, "RGB8Planar" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_RGB10Planar, "RGB10Planar" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_RGB12Planar, "RGB12Planar" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_RGB16Planar, "RGB16Planar" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_YUV422_YUYV_Packed, "YUV422_YUYV_Packed" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_BayerGB12Packed, "BayerGB12Packed" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_BayerGR12Packed, "BayerGR12Packed" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_BayerRG12Packed, "BayerRG12Packed" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_BayerBG12Packed, "BayerBG12Packed" );        static_cast<GenApi::CEnumerationTRef<ChunkPixelFormatEnums> *> (&ChunkPixelFormat )->SetEnumReference( ChunkPixelFormat_RGB12V1Packed, "RGB12V1Packed" );        static_cast<GenApi::CIntegerRef*> (&ChunkTimestamp )->SetReference(_Ptr->GetNode("ChunkTimestamp"));
    static_cast<GenApi::CIntegerRef*> (&ChunkFramecounter )->SetReference(_Ptr->GetNode("ChunkFramecounter"));
    static_cast<GenApi::CIntegerRef*> (&ChunkLineStatusAll )->SetReference(_Ptr->GetNode("ChunkLineStatusAll"));
    static_cast<GenApi::CIntegerRef*> (&ChunkTriggerinputcounter )->SetReference(_Ptr->GetNode("ChunkTriggerinputcounter"));
    static_cast<GenApi::CFloatRef*> (&ChunkExposureTime )->SetReference(_Ptr->GetNode("ChunkExposureTime"));
    static_cast<GenApi::CEnumerationTRef<EventSelectorEnums> *> (&EventSelector )->SetReference(_Ptr->GetNode("EventSelector"));
    static_cast<GenApi::CEnumerationTRef<EventSelectorEnums> *> (&EventSelector )->SetNumEnums(6);
    static_cast<GenApi::CEnumerationTRef<EventSelectorEnums> *> (&EventSelector )->SetEnumReference( EventSelector_ExposureEnd, "ExposureEnd" );        static_cast<GenApi::CEnumerationTRef<EventSelectorEnums> *> (&EventSelector )->SetEnumReference( EventSelector_FrameStartOvertrigger, "FrameStartOvertrigger" );        static_cast<GenApi::CEnumerationTRef<EventSelectorEnums> *> (&EventSelector )->SetEnumReference( EventSelector_AcquisitionStartOvertrigger, "AcquisitionStartOvertrigger" );        static_cast<GenApi::CEnumerationTRef<EventSelectorEnums> *> (&EventSelector )->SetEnumReference( EventSelector_FrameStart, "FrameStart" );        static_cast<GenApi::CEnumerationTRef<EventSelectorEnums> *> (&EventSelector )->SetEnumReference( EventSelector_AcquisitionStart, "AcquisitionStart" );        static_cast<GenApi::CEnumerationTRef<EventSelectorEnums> *> (&EventSelector )->SetEnumReference( EventSelector_EventOverrun, "EventOverrun" );        static_cast<GenApi::CEnumerationTRef<EventNotificationEnums> *> (&EventNotification )->SetReference(_Ptr->GetNode("EventNotification"));
    static_cast<GenApi::CEnumerationTRef<EventNotificationEnums> *> (&EventNotification )->SetNumEnums(3);
    static_cast<GenApi::CEnumerationTRef<EventNotificationEnums> *> (&EventNotification )->SetEnumReference( EventNotification_Off, "Off" );        static_cast<GenApi::CEnumerationTRef<EventNotificationEnums> *> (&EventNotification )->SetEnumReference( EventNotification_GenICamEvent, "GenICamEvent" );        static_cast<GenApi::CEnumerationTRef<EventNotificationEnums> *> (&EventNotification )->SetEnumReference( EventNotification_On, "On" );        static_cast<GenApi::CIntegerRef*> (&ExposureEndEventStreamChannelIndex )->SetReference(_Ptr->GetNode("ExposureEndEventStreamChannelIndex"));
    static_cast<GenApi::CIntegerRef*> (&ExposureEndEventFrameID )->SetReference(_Ptr->GetNode("ExposureEndEventFrameID"));
    static_cast<GenApi::CIntegerRef*> (&ExposureEndEventTimestamp )->SetReference(_Ptr->GetNode("ExposureEndEventTimestamp"));
    static_cast<GenApi::CIntegerRef*> (&LineStartOvertriggerEventStreamChannelIndex )->SetReference(_Ptr->GetNode("LineStartOvertriggerEventStreamChannelIndex"));
    static_cast<GenApi::CIntegerRef*> (&LineStartOvertriggerEventTimestamp )->SetReference(_Ptr->GetNode("LineStartOvertriggerEventTimestamp"));
    static_cast<GenApi::CIntegerRef*> (&FrameStartOvertriggerEventStreamChannelIndex )->SetReference(_Ptr->GetNode("FrameStartOvertriggerEventStreamChannelIndex"));
    static_cast<GenApi::CIntegerRef*> (&FrameStartOvertriggerEventTimestamp )->SetReference(_Ptr->GetNode("FrameStartOvertriggerEventTimestamp"));
    static_cast<GenApi::CIntegerRef*> (&FrameStartEventStreamChannelIndex )->SetReference(_Ptr->GetNode("FrameStartEventStreamChannelIndex"));
    static_cast<GenApi::CIntegerRef*> (&FrameStartEventTimestamp )->SetReference(_Ptr->GetNode("FrameStartEventTimestamp"));
    static_cast<GenApi::CIntegerRef*> (&AcquisitionStartEventStreamChannelIndex )->SetReference(_Ptr->GetNode("AcquisitionStartEventStreamChannelIndex"));
    static_cast<GenApi::CIntegerRef*> (&AcquisitionStartEventTimestamp )->SetReference(_Ptr->GetNode("AcquisitionStartEventTimestamp"));
    static_cast<GenApi::CIntegerRef*> (&AcquisitionStartOvertriggerEventStreamChannelIndex )->SetReference(_Ptr->GetNode("AcquisitionStartOvertriggerEventStreamChannelIndex"));
    static_cast<GenApi::CIntegerRef*> (&AcquisitionStartOvertriggerEventTimestamp )->SetReference(_Ptr->GetNode("AcquisitionStartOvertriggerEventTimestamp"));
    static_cast<GenApi::CIntegerRef*> (&FrameTimeoutEventStreamChannelIndex )->SetReference(_Ptr->GetNode("FrameTimeoutEventStreamChannelIndex"));
    static_cast<GenApi::CIntegerRef*> (&FrameTimeoutEventTimestamp )->SetReference(_Ptr->GetNode("FrameTimeoutEventTimestamp"));
    static_cast<GenApi::CIntegerRef*> (&EventOverrunEventStreamChannelIndex )->SetReference(_Ptr->GetNode("EventOverrunEventStreamChannelIndex"));
    static_cast<GenApi::CIntegerRef*> (&EventOverrunEventFrameID )->SetReference(_Ptr->GetNode("EventOverrunEventFrameID"));
    static_cast<GenApi::CIntegerRef*> (&EventOverrunEventTimestamp )->SetReference(_Ptr->GetNode("EventOverrunEventTimestamp"));
    static_cast<GenApi::CIntegerRef*> (&CriticalTemperatureEventStreamChannelIndex )->SetReference(_Ptr->GetNode("CriticalTemperatureEventStreamChannelIndex"));
    static_cast<GenApi::CIntegerRef*> (&CriticalTemperatureEventTimestamp )->SetReference(_Ptr->GetNode("CriticalTemperatureEventTimestamp"));
    static_cast<GenApi::CIntegerRef*> (&OverTemperatureEventStreamChannelIndex )->SetReference(_Ptr->GetNode("OverTemperatureEventStreamChannelIndex"));
    static_cast<GenApi::CIntegerRef*> (&OverTemperatureEventTimestamp )->SetReference(_Ptr->GetNode("OverTemperatureEventTimestamp"));
    static_cast<GenApi::CIntegerRef*> (&TLParamsLocked )->SetReference(_Ptr->GetNode("TLParamsLocked"));
    static_cast<GenApi::CEnumerationTRef<FileSelectorEnums> *> (&FileSelector )->SetReference(_Ptr->GetNode("FileSelector"));
    static_cast<GenApi::CEnumerationTRef<FileSelectorEnums> *> (&FileSelector )->SetNumEnums(6);
    static_cast<GenApi::CEnumerationTRef<FileSelectorEnums> *> (&FileSelector )->SetEnumReference( FileSelector_UserData, "UserData" );        static_cast<GenApi::CEnumerationTRef<FileSelectorEnums> *> (&FileSelector )->SetEnumReference( FileSelector_UserSet1, "UserSet1" );        static_cast<GenApi::CEnumerationTRef<FileSelectorEnums> *> (&FileSelector )->SetEnumReference( FileSelector_UserSet2, "UserSet2" );        static_cast<GenApi::CEnumerationTRef<FileSelectorEnums> *> (&FileSelector )->SetEnumReference( FileSelector_UserSet3, "UserSet3" );        static_cast<GenApi::CEnumerationTRef<FileSelectorEnums> *> (&FileSelector )->SetEnumReference( FileSelector_UserGainShading1, "UserGainShading1" );        static_cast<GenApi::CEnumerationTRef<FileSelectorEnums> *> (&FileSelector )->SetEnumReference( FileSelector_UserGainShading2, "UserGainShading2" );        static_cast<GenApi::CEnumerationTRef<FileOperationSelectorEnums> *> (&FileOperationSelector )->SetReference(_Ptr->GetNode("FileOperationSelector"));
    static_cast<GenApi::CEnumerationTRef<FileOperationSelectorEnums> *> (&FileOperationSelector )->SetNumEnums(4);
    static_cast<GenApi::CEnumerationTRef<FileOperationSelectorEnums> *> (&FileOperationSelector )->SetEnumReference( FileOperationSelector_Open, "Open" );        static_cast<GenApi::CEnumerationTRef<FileOperationSelectorEnums> *> (&FileOperationSelector )->SetEnumReference( FileOperationSelector_Close, "Close" );        static_cast<GenApi::CEnumerationTRef<FileOperationSelectorEnums> *> (&FileOperationSelector )->SetEnumReference( FileOperationSelector_Read, "Read" );        static_cast<GenApi::CEnumerationTRef<FileOperationSelectorEnums> *> (&FileOperationSelector )->SetEnumReference( FileOperationSelector_Write, "Write" );        static_cast<GenApi::CEnumerationTRef<FileOpenModeEnums> *> (&FileOpenMode )->SetReference(_Ptr->GetNode("FileOpenMode"));
    static_cast<GenApi::CEnumerationTRef<FileOpenModeEnums> *> (&FileOpenMode )->SetNumEnums(2);
    static_cast<GenApi::CEnumerationTRef<FileOpenModeEnums> *> (&FileOpenMode )->SetEnumReference( FileOpenMode_Read, "Read" );        static_cast<GenApi::CEnumerationTRef<FileOpenModeEnums> *> (&FileOpenMode )->SetEnumReference( FileOpenMode_Write, "Write" );        static_cast<GenApi::CRegisterRef*> (&FileAccessBuffer )->SetReference(_Ptr->GetNode("FileAccessBuffer"));
    static_cast<GenApi::CIntegerRef*> (&FileAccessOffset )->SetReference(_Ptr->GetNode("FileAccessOffset"));
    static_cast<GenApi::CIntegerRef*> (&FileAccessLength )->SetReference(_Ptr->GetNode("FileAccessLength"));
    static_cast<GenApi::CEnumerationTRef<FileOperationStatusEnums> *> (&FileOperationStatus )->SetReference(_Ptr->GetNode("FileOperationStatus"));
    static_cast<GenApi::CEnumerationTRef<FileOperationStatusEnums> *> (&FileOperationStatus )->SetNumEnums(2);
    static_cast<GenApi::CEnumerationTRef<FileOperationStatusEnums> *> (&FileOperationStatus )->SetEnumReference( FileOperationStatus_Success, "Success" );        static_cast<GenApi::CEnumerationTRef<FileOperationStatusEnums> *> (&FileOperationStatus )->SetEnumReference( FileOperationStatus_Failure, "Failure" );        static_cast<GenApi::CIntegerRef*> (&FileOperationResult )->SetReference(_Ptr->GetNode("FileOperationResult"));
    static_cast<GenApi::CIntegerRef*> (&FileSize )->SetReference(_Ptr->GetNode("FileSize"));
    static_cast<GenApi::CCommandRef*> (&FileOperationExecute )->SetReference(_Ptr->GetNode("FileOperationExecute"));
    
    }

    inline const char* CIIDC1394CameraParams_Params::_GetVendorName(void)
    {
        return "Basler";
    }

    inline const char* CIIDC1394CameraParams_Params::_GetModelName(void)
    {
        return "IIDC1394CameraParams";
    }

    //! \endcond

} // namespace Basler_IIDC1394CameraParams

#undef GENAPI_DEPRECATED_FEATURE
#endif // Basler_IIDC1394CameraParams_PARAMS_H
