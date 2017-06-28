





//-----------------------------------------------------------------------------
//  (c) 2004-2008 by Basler Vision Technologies
//  Section: Vision Components
//  Project: GenApi
//-----------------------------------------------------------------------------
/*!
\file
\brief Interface to the Pylon1394 Event Grabber parameters
*/

//-----------------------------------------------------------------------------
//  This file is generated automatically
//  Do not modify!
//-----------------------------------------------------------------------------



#ifndef Basler_IIDC1394EventParams_PARAMS_H
#define Basler_IIDC1394EventParams_PARAMS_H

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
namespace Basler_IIDC1394EventParams
{

    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************
    

    //**************************************************************************************************
    // Parameter class
    //**************************************************************************************************
    

    //! Interface to the Pylon1394 Event Grabber parameters
    class CIIDC1394EventParams_Params
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            CIIDC1394EventParams_Params(void);

            //! Destructor
            ~CIIDC1394EventParams_Params(void);

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
        
    //! \name Root - IEEE1394 event parameters
    //@{
    /*!
        \brief Number of buffers to be used.

        Number of Buffers that are going to be used receiving events. .
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &NumBuffer;
    
    //@}
    


    private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
            CIIDC1394EventParams_Params(CIIDC1394EventParams_Params&);

            //! not implemented assignment operator
            CIIDC1394EventParams_Params& operator=(CIIDC1394EventParams_Params&);

        //! \endcond
    };


    //**************************************************************************************************
    // Parameter class implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS

    inline CIIDC1394EventParams_Params::CIIDC1394EventParams_Params(void)
        : NumBuffer( *new GenApi::CIntegerRef() )
        
    {
    }

    inline CIIDC1394EventParams_Params::~CIIDC1394EventParams_Params(void)
    {
        delete static_cast < GenApi::CIntegerRef*> (&NumBuffer );
        
    }

    inline void CIIDC1394EventParams_Params::_Initialize(GenApi::INodeMap* _Ptr)
    {
        static_cast<GenApi::CIntegerRef*> (&NumBuffer )->SetReference(_Ptr->GetNode("NumBuffer"));
    
    }

    inline const char* CIIDC1394EventParams_Params::_GetVendorName(void)
    {
        return "Basler";
    }

    inline const char* CIIDC1394EventParams_Params::_GetModelName(void)
    {
        return "IIDC1394EventParams";
    }

    //! \endcond

} // namespace Basler_IIDC1394EventParams

#undef GENAPI_DEPRECATED_FEATURE
#endif // Basler_IIDC1394EventParams_PARAMS_H
