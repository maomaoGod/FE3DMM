





//-----------------------------------------------------------------------------
//  (c) 2004-2008 by Basler Vision Technologies
//  Section: Vision Components
//  Project: GenApi
//-----------------------------------------------------------------------------
/*!
\file
\brief Interface to the Pylon1394 Stream Grabber parameters
*/

//-----------------------------------------------------------------------------
//  This file is generated automatically
//  Do not modify!
//-----------------------------------------------------------------------------



#ifndef Basler_IIDC1394StreamParams_PARAMS_H
#define Basler_IIDC1394StreamParams_PARAMS_H

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
namespace Basler_IIDC1394StreamParams
{

    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************
    
    //! Valid values for Status
    enum StatusEnums
    {
        Status_Closed,  //!<The low level stream grabber is closed.
        Status_Open,  //!<The low level stream grabber is open.
        Status_Locked,  //!<The low level stream grabber is locked.
        Status_Invalid   //!<The low level stream grabber is not valid.
        
    };


    //**************************************************************************************************
    // Parameter class
    //**************************************************************************************************
    

    //! Interface to the Pylon1394 Stream Grabber parameters
    class CIIDC1394StreamParams_Params
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            CIIDC1394StreamParams_Params(void);

            //! Destructor
            ~CIIDC1394StreamParams_Params(void);

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
        
    //! \name Root - IEEE1394 stream parameters
    //@{
    /*!
        \brief Number of buffers to be used.

        Maximum number of Buffers that are going to be used simultaneously. Raising this value may cause higher
	resource demands on a subsequent PrepareGrab call.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &MaxNumBuffer;
    
    //@}
    

    //! \name Root - IEEE1394 stream parameters
    //@{
    /*!
        \brief Buffer size in bytes

        Size of the greatest buffer to be used. Unit is bytes. Raising this value may cause higher resource demands on a subsequent PrepareGrab call. 
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &MaxBufferSize;
    
    //@}
    

    //! \name StreamGrabber - Stream Grabber related features
    //@{
    /*!
        \brief Status of the stream grabber

        The stream grabber is initially in the status Closed. In this state it can only be opened, other operations
	    are not allowed.
	    It switches to Open when the stream grabber is opened successfully.  A call to PrepareGrab locks the stream grabber and the camera. It is synchronized with the transport layer specific parameter of the camera.
	    Both are released by calling FinishGrab and the status switches back to Open. 
	    On call of the Close method the status returns to Closed.
	    In case of unrecoverable errors status turn invalid.
    
        \b Visibility = Invisible
    
    */
    GenApi::IEnumerationT<StatusEnums > &Status;
    
    //@}
    

    //! \name OutputThread - Parameter of the output thread.
    //@{
    /*!
        \brief Timeout value in milliseconds for the output thread

        
    
        \b Visibility = Expert
    
    */
    GenApi::IInteger &ThreadTimeout;
    
    //@}
    

    //! \name OutputThread - Parameter of the output thread.
    //@{
    /*!
        \brief If enabled the user can set a custom thread priority.

        
    
        \b Visibility = Guru
    
    */
    GenApi::IBoolean &ThreadPriorityOverride;
    
    //@}
    

    //! \name OutputThread - Parameter of the output thread.
    //@{
    /*!
        \brief The thread priority.

        This value sets the absolute thread priority. It is not changed until the stream grabber is re-opened again.
    
        \b Visibility = Guru
    
    */
    GenApi::IInteger &ThreadPriority;
    
    //@}
    


    private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
            CIIDC1394StreamParams_Params(CIIDC1394StreamParams_Params&);

            //! not implemented assignment operator
            CIIDC1394StreamParams_Params& operator=(CIIDC1394StreamParams_Params&);

        //! \endcond
    };


    //**************************************************************************************************
    // Parameter class implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS

    inline CIIDC1394StreamParams_Params::CIIDC1394StreamParams_Params(void)
        : MaxNumBuffer( *new GenApi::CIntegerRef() )
        , MaxBufferSize( *new GenApi::CIntegerRef() )
        , Status( *new GenApi::CEnumerationTRef<StatusEnums>() )
        , ThreadTimeout( *new GenApi::CIntegerRef() )
        , ThreadPriorityOverride( *new GenApi::CBooleanRef() )
        , ThreadPriority( *new GenApi::CIntegerRef() )
        
    {
    }

    inline CIIDC1394StreamParams_Params::~CIIDC1394StreamParams_Params(void)
    {
        delete static_cast < GenApi::CIntegerRef*> (&MaxNumBuffer );
        delete static_cast < GenApi::CIntegerRef*> (&MaxBufferSize );
        delete static_cast < GenApi::CEnumerationTRef<StatusEnums> *> (&Status );
        delete static_cast < GenApi::CIntegerRef*> (&ThreadTimeout );
        delete static_cast < GenApi::CBooleanRef*> (&ThreadPriorityOverride );
        delete static_cast < GenApi::CIntegerRef*> (&ThreadPriority );
        
    }

    inline void CIIDC1394StreamParams_Params::_Initialize(GenApi::INodeMap* _Ptr)
    {
        static_cast<GenApi::CIntegerRef*> (&MaxNumBuffer )->SetReference(_Ptr->GetNode("MaxNumBuffer"));
    static_cast<GenApi::CIntegerRef*> (&MaxBufferSize )->SetReference(_Ptr->GetNode("MaxBufferSize"));
    static_cast<GenApi::CEnumerationTRef<StatusEnums> *> (&Status )->SetReference(_Ptr->GetNode("Status"));
    static_cast<GenApi::CEnumerationTRef<StatusEnums> *> (&Status )->SetNumEnums(4);
    static_cast<GenApi::CEnumerationTRef<StatusEnums> *> (&Status )->SetEnumReference( Status_Closed, "Closed" );        static_cast<GenApi::CEnumerationTRef<StatusEnums> *> (&Status )->SetEnumReference( Status_Open, "Open" );        static_cast<GenApi::CEnumerationTRef<StatusEnums> *> (&Status )->SetEnumReference( Status_Locked, "Locked" );        static_cast<GenApi::CEnumerationTRef<StatusEnums> *> (&Status )->SetEnumReference( Status_Invalid, "Invalid" );        static_cast<GenApi::CIntegerRef*> (&ThreadTimeout )->SetReference(_Ptr->GetNode("ThreadTimeout"));
    static_cast<GenApi::CBooleanRef*> (&ThreadPriorityOverride )->SetReference(_Ptr->GetNode("ThreadPriorityOverride"));
    static_cast<GenApi::CIntegerRef*> (&ThreadPriority )->SetReference(_Ptr->GetNode("ThreadPriority"));
    
    }

    inline const char* CIIDC1394StreamParams_Params::_GetVendorName(void)
    {
        return "Basler";
    }

    inline const char* CIIDC1394StreamParams_Params::_GetModelName(void)
    {
        return "IIDC1394StreamParams";
    }

    //! \endcond

} // namespace Basler_IIDC1394StreamParams

#undef GENAPI_DEPRECATED_FEATURE
#endif // Basler_IIDC1394StreamParams_PARAMS_H
