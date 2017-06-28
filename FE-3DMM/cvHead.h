#ifndef __CV_HEAD_H
#define __CV_HEAD_H

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgproc/imgproc_c.h"

#define FATHER_FOLDER "OpenCV/"
using namespace cv;
#if _WIN32

	#if _MSC_VER==1800
		#if _DEBUG
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_calib3d249d.lib") 
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_contrib249d.lib") 
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_core249d.lib")
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_features2d249d.lib") 
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_flann249d.lib") 
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_gpu249d.lib")
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_highgui249d.lib")
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_imgproc249d.lib")
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_legacy249d.lib")
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_ml249d.lib")
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_nonfree249d.lib")
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_objdetect249d.lib")
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_ocl249d.lib")
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_photo249d.lib")
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_stitching249d.lib")
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_superres249d.lib")
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_ts249d.lib")
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_video249d.lib")
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_videostab249d.lib")
		#else
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_calib3d249.lib") 
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_contrib249.lib") 
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_core249.lib")
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_features2d249.lib") 
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_flann249.lib") 
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_gpu249.lib")
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_highgui249.lib")
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_imgproc249.lib")
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_legacy249.lib")
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_ml249.lib")
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_nonfree249.lib")
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_objdetect249.lib")
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_ocl249.lib")
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_photo249.lib")
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_stitching249.lib")
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_superres249.lib")
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_ts249.lib")
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_video249.lib")
			#pragma  comment(lib,FATHER_FOLDER"CV24986/vc12/lib/opencv_videostab249.lib")
		#endif


	#endif

	#if _MSC_VER==1600
		#if _DEBUG
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_calib3d249d.lib") 
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_contrib249d.lib") 
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_core249d.lib")
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_features2d249d.lib") 
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_flann249d.lib") 
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_gpu249d.lib")
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_highgui249d.lib")
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_imgproc249d.lib")
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_legacy249d.lib")
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_ml249d.lib")
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_nonfree249d.lib")
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_objdetect249d.lib")
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_ocl249d.lib")
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_photo249d.lib")
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_stitching249d.lib")
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_superres249d.lib")
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_ts249d.lib")
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_video249d.lib")
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_videostab249d.lib")
			#else
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_calib3d249.lib") 
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_contrib249.lib") 
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_core249.lib")
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_features2d249.lib") 
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_flann249.lib") 
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_gpu249.lib")
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_highgui249.lib")
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_imgproc249.lib")
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_legacy249.lib")
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_ml249.lib")
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_nonfree249.lib")
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_objdetect249.lib")
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_ocl249.lib")
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_photo249.lib")
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_stitching249.lib")
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_superres249.lib")
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_ts249.lib")
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_video249.lib")
			#pragma  comment(lib,"CV24986/vc10/lib/opencv_videostab249.lib")
			#endif
	#endif
#endif


#if _WIN64
	#if _MSC_VER==1800
		#if _DEBUG
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_calib3d249d.lib") 
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_contrib249d.lib") 
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_core249d.lib")
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_features2d249d.lib") 
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_flann249d.lib") 
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_gpu249d.lib")
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_highgui249d.lib")
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_imgproc249d.lib")
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_legacy249d.lib")
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_ml249d.lib")
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_nonfree249d.lib")
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_objdetect249d.lib")
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_ocl249d.lib")
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_photo249d.lib")
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_stitching249d.lib")
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_superres249d.lib")
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_ts249d.lib")
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_video249d.lib")
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_videostab249d.lib")
		#else
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_calib3d249.lib") 
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_contrib249.lib") 
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_core249.lib")
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_features2d249.lib") 
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_flann249.lib") 
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_gpu249.lib")
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_highgui249.lib")
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_imgproc249.lib")
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_legacy249.lib")
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_ml249.lib")
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_nonfree249.lib")
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_objdetect249.lib")
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_ocl249.lib")
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_photo249.lib")
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_stitching249.lib")
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_superres249.lib")
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_ts249.lib")
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_video249.lib")
			#pragma  comment(lib,"CV24964/vc12/lib/opencv_videostab249.lib")
		#endif
	#endif

	#if _MSC_VER==1600
		#if _DEBUG
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_calib3d249d.lib") 
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_contrib249d.lib") 
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_core249d.lib")
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_features2d249d.lib") 
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_flann249d.lib") 
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_gpu249d.lib")
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_highgui249d.lib")
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_imgproc249d.lib")
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_legacy249d.lib")
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_ml249d.lib")
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_nonfree249d.lib")
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_objdetect249d.lib")
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_ocl249d.lib")
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_photo249d.lib")
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_stitching249d.lib")
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_superres249d.lib")
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_ts249d.lib")
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_video249d.lib")
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_videostab249d.lib")
		#else
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_calib3d249.lib") 
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_contrib249.lib") 
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_core249.lib")
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_features2d249.lib") 
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_flann249.lib") 
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_gpu249.lib")
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_highgui249.lib")
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_imgproc249.lib")
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_legacy249.lib")
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_ml249.lib")
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_nonfree249.lib")
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_objdetect249.lib")
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_ocl249.lib")
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_photo249.lib")
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_stitching249.lib")
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_superres249.lib")
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_ts249.lib")
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_video249.lib")
			#pragma  comment(lib,"CV24964/vc10/lib/opencv_videostab249.lib")
		#endif
	#endif
#endif

#endif