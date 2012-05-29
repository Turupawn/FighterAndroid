# 
# COSOperator.cpp was removed from IRROTHEROBJ
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

IRRMESHLOADER = irr/CBSPMeshFileLoader.cpp irr/CMD2MeshFileLoader.cpp irr/CMD3MeshFileLoader.cpp irr/CMS3DMeshFileLoader.cpp irr/CB3DMeshFileLoader.cpp irr/C3DSMeshFileLoader.cpp irr/COgreMeshFileLoader.cpp irr/COBJMeshFileLoader.cpp irr/CColladaFileLoader.cpp irr/CCSMLoader.cpp irr/CDMFLoader.cpp irr/CLMTSMeshFileLoader.cpp irr/CMY3DMeshFileLoader.cpp irr/COCTLoader.cpp irr/CXMeshFileLoader.cpp irr/CIrrMeshFileLoader.cpp irr/CSTLMeshFileLoader.cpp irr/CLWOMeshFileLoader.cpp irr/CPLYMeshFileLoader.cpp
IRRMESHWRITER = irr/CColladaMeshWriter.cpp irr/CIrrMeshWriter.cpp irr/CSTLMeshWriter.cpp irr/COBJMeshWriter.cpp irr/CPLYMeshWriter.cpp
IRRMESHOBJ = $(IRRMESHLOADER) $(IRRMESHWRITER) irr/CSkinnedMesh.cpp irr/CBoneSceneNode.cpp irr/CMeshSceneNode.cpp irr/CAnimatedMeshSceneNode.cpp irr/CAnimatedMeshMD2.cpp irr/CAnimatedMeshMD3.cpp irr/CQ3LevelMesh.cpp irr/CQuake3ShaderSceneNode.cpp
IRROBJ = irr/CBillboardSceneNode.cpp irr/CCameraSceneNode.cpp irr/CDummyTransformationSceneNode.cpp irr/CEmptySceneNode.cpp irr/CGeometryCreator.cpp irr/CLightSceneNode.cpp irr/CMeshManipulator.cpp irr/CMetaTriangleSelector.cpp irr/COctreeSceneNode.cpp irr/COctreeTriangleSelector.cpp irr/CSceneCollisionManager.cpp irr/CSceneManager.cpp irr/CShadowVolumeSceneNode.cpp irr/CSkyBoxSceneNode.cpp irr/CSkyDomeSceneNode.cpp irr/CTerrainSceneNode.cpp irr/CTerrainTriangleSelector.cpp irr/CVolumeLightSceneNode.cpp irr/CCubeSceneNode.cpp irr/CSphereSceneNode.cpp irr/CTextSceneNode.cpp irr/CTriangleBBSelector.cpp irr/CTriangleSelector.cpp irr/CWaterSurfaceSceneNode.cpp irr/CMeshCache.cpp irr/CDefaultSceneNodeAnimatorFactory.cpp irr/CDefaultSceneNodeFactory.cpp
IRRPARTICLEOBJ = irr/CParticleAnimatedMeshSceneNodeEmitter.cpp irr/CParticleBoxEmitter.cpp irr/CParticleCylinderEmitter.cpp irr/CParticleMeshEmitter.cpp irr/CParticlePointEmitter.cpp irr/CParticleRingEmitter.cpp irr/CParticleSphereEmitter.cpp irr/CParticleAttractionAffector.cpp irr/CParticleFadeOutAffector.cpp irr/CParticleGravityAffector.cpp irr/CParticleRotationAffector.cpp irr/CParticleSystemSceneNode.cpp irr/CParticleScaleAffector.cpp
IRRANIMOBJ = irr/CSceneNodeAnimatorCameraFPS.cpp irr/CSceneNodeAnimatorCameraMaya.cpp irr/CSceneNodeAnimatorCollisionResponse.cpp irr/CSceneNodeAnimatorDelete.cpp irr/CSceneNodeAnimatorFlyCircle.cpp irr/CSceneNodeAnimatorFlyStraight.cpp irr/CSceneNodeAnimatorFollowSpline.cpp irr/CSceneNodeAnimatorRotation.cpp irr/CSceneNodeAnimatorTexture.cpp
IRRDRVROBJ = irr/CNullDriver.cpp irr/COGLESDriver.cpp irr/COGLESTexture.cpp irr/COGLESExtensionHandler.cpp
IRRIMAGEOBJ = irr/CColorConverter.cpp irr/CImage.cpp irr/CImageLoaderBMP.cpp irr/CImageLoaderJPG.cpp irr/CImageLoaderPCX.cpp irr/CImageLoaderPNG.cpp irr/CImageLoaderPSD.cpp irr/CImageLoaderTGA.cpp irr/CImageLoaderPPM.cpp irr/CImageLoaderWAL.cpp irr/CImageLoaderRGB.cpp irr/CImageWriterBMP.cpp irr/CImageWriterJPG.cpp irr/CImageWriterPCX.cpp irr/CImageWriterPNG.cpp irr/CImageWriterPPM.cpp irr/CImageWriterPSD.cpp irr/CImageWriterTGA.cpp
IRRVIDEOOBJ = irr/CVideoModeList.cpp irr/CFPSCounter.cpp $(IRRDRVROBJ) $(IRRIMAGEOBJ)
IRRSWRENDEROBJ = irr/CSoftwareDriver.cpp irr/CSoftwareTexture.cpp irr/CTRFlat.cpp irr/CTRFlatWire.cpp irr/CTRGouraud.cpp irr/CTRGouraudWire.cpp irr/CTRTextureFlat.cpp irr/CTRTextureFlatWire.cpp irr/CTRTextureGouraud.cpp irr/CTRTextureGouraudAdd.cpp irr/CTRTextureGouraudNoZ.cpp irr/CTRTextureGouraudWire.cpp irr/CZBuffer.cpp irr/CTRTextureGouraudVertexAlpha2.cpp irr/CTRTextureGouraudNoZ2.cpp irr/CTRTextureLightMap2_M2.cpp irr/CTRTextureLightMap2_M4.cpp irr/CTRTextureLightMap2_M1.cpp irr/CSoftwareDriver2.cpp irr/CSoftwareTexture2.cpp irr/CTRTextureGouraud2.cpp irr/CTRGouraud2.cpp irr/CTRGouraudAlpha2.cpp irr/CTRGouraudAlphaNoZ2.cpp irr/CTRTextureDetailMap2.cpp irr/CTRTextureGouraudAdd2.cpp irr/CTRTextureGouraudAddNoZ2.cpp irr/CTRTextureWire2.cpp irr/CTRTextureLightMap2_Add.cpp irr/CTRTextureLightMapGouraud2_M4.cpp irr/IBurningShader.cpp irr/CTRTextureBlend.cpp irr/CTRTextureGouraudAlpha.cpp irr/CTRTextureGouraudAlphaNoZ.cpp irr/CDepthBuffer.cpp irr/CBurningShader_Raster_Reference.cpp
IRRIOOBJ = irr/CFileList.cpp irr/CFileSystem.cpp irr/CLimitReadFile.cpp irr/CMemoryFile.cpp irr/CReadFile.cpp irr/CWriteFile.cpp irr/CXMLReader.cpp irr/CXMLWriter.cpp irr/CZipReader.cpp irr/CPakReader.cpp irr/CNPKReader.cpp irr/CTarReader.cpp irr/CMountPointReader.cpp irr/irrXML.cpp irr/CAttributes.cpp irr/lzma/LzmaDec.c
IRROTHEROBJ = irr/CIrrDeviceConsole.cpp irr/CIrrDeviceStub.cpp irr/CLogger.cpp irr/Irrlicht.cpp irr/os.cpp
IRRGUIOBJ = irr/CGUIButton.cpp irr/CGUICheckBox.cpp irr/CGUIComboBox.cpp irr/CGUIContextMenu.cpp irr/CGUIEditBox.cpp irr/CGUIEnvironment.cpp irr/CGUIFileOpenDialog.cpp irr/CGUIFont.cpp irr/CGUIImage.cpp irr/CGUIInOutFader.cpp irr/CGUIListBox.cpp irr/CGUIMenu.cpp irr/CGUIMeshViewer.cpp irr/CGUIMessageBox.cpp irr/CGUIModalScreen.cpp irr/CGUIScrollBar.cpp irr/CGUISpinBox.cpp irr/CGUISkin.cpp irr/CGUIStaticText.cpp irr/CGUITabControl.cpp irr/CGUITable.cpp irr/CGUIToolBar.cpp irr/CGUIWindow.cpp irr/CGUIColorSelectDialog.cpp irr/CDefaultGUIElementFactory.cpp irr/CGUISpriteBank.cpp irr/CGUIImageList.cpp irr/CGUITreeView.cpp

TINYXMLOBJ = Fighter/src/TinyXml/tinystr.cpp Fighter/src/TinyXml/tinyxml.cpp Fighter/src/TinyXml/tinyxmlerror.cpp Fighter/src/TinyXml/tinyxmlparser.cpp

FIGHTEROBJ = Fighter/src/Fighter.cpp Fighter/src/Stage/Stage.cpp Fighter/src/Sonido/Sonido.cpp Fighter/src/Sonido/Reproduccion.cpp Fighter/src/Personaje/Proyectil.cpp Fighter/src/Personaje/Movimiento.cpp Fighter/src/Personaje/ModificadorImagen.cpp Fighter/src/Personaje/Modificador.cpp Fighter/src/Personaje/Imagen.cpp Fighter/src/Personaje/Condicion.cpp Fighter/src/Personaje/Personaje.cpp Fighter/src/Personaje/ModificadorString.cpp Fighter/src/Personaje/ModificadorHitboxes.cpp Fighter/src/Personaje/ModificadorBarra.cpp Fighter/src/Personaje/HitBox.cpp Fighter/src/Personaje/Barra.cpp Fighter/src/Personaje/Paleta.cpp Fighter/src/Personaje/ModificadorPorVariable.cpp Fighter/src/Personaje/ModificadorEntero.cpp Fighter/src/Personaje/InputMovimiento.cpp Fighter/src/Personaje/Frame.cpp Fighter/src/Personaje/Animacion.cpp Fighter/src/Menu/MenuTexto.cpp Fighter/src/Menu/MenuImagen.cpp Fighter/src/Menu/MenuContenedor.cpp Fighter/src/Menu/MenuBoton.cpp Fighter/src/Menu/Elemento.cpp Fighter/src/Menu/MenuLista.cpp Fighter/src/Menu/Menu.cpp Fighter/src/Menu/MenuCharSelect.cpp Fighter/src/Menu/MenuBarra.cpp Fighter/src/Input/Receiver.cpp Fighter/src/Input/Input.cpp Fighter/src/Input/Boton.cpp Fighter/src/IA/Transicion.cpp Fighter/src/IA/IA.cpp Fighter/src/IA/Estado.cpp Fighter/src/IA/Automata.cpp Fighter/src/Grafico/Grafico.cpp

ZLIBOBJ = irr/zlib/adler32.c irr/zlib/compress.c irr/zlib/crc32.c irr/zlib/deflate.c irr/zlib/inffast.c irr/zlib/inflate.c irr/zlib/inftrees.c irr/zlib/trees.c irr/zlib/uncompr.c irr/zlib/zutil.c
JPEGLIBOBJ = irr/jpeglib/jcapimin.c irr/jpeglib/jcapistd.c irr/jpeglib/jccoefct.c irr/jpeglib/jccolor.c irr/jpeglib/jcdctmgr.c irr/jpeglib/jchuff.c irr/jpeglib/jcinit.c irr/jpeglib/jcmainct.c irr/jpeglib/jcmarker.c irr/jpeglib/jcmaster.c irr/jpeglib/jcomapi.c irr/jpeglib/jcparam.c irr/jpeglib/jcprepct.c irr/jpeglib/jcsample.c irr/jpeglib/jctrans.c irr/jpeglib/jdapimin.c irr/jpeglib/jdapistd.c irr/jpeglib/jdatadst.c irr/jpeglib/jdatasrc.c irr/jpeglib/jdcoefct.c irr/jpeglib/jdcolor.c irr/jpeglib/jddctmgr.c irr/jpeglib/jdhuff.c irr/jpeglib/jdinput.c irr/jpeglib/jdmainct.c irr/jpeglib/jdmarker.c irr/jpeglib/jdmaster.c irr/jpeglib/jdmerge.c irr/jpeglib/jdpostct.c irr/jpeglib/jdsample.c irr/jpeglib/jdtrans.c irr/jpeglib/jerror.c irr/jpeglib/jfdctflt.c irr/jpeglib/jfdctfst.c irr/jpeglib/jfdctint.c irr/jpeglib/jidctflt.c irr/jpeglib/jidctfst.c irr/jpeglib/jidctint.c irr/jpeglib/jmemmgr.c irr/jpeglib/jmemnobs.c irr/jpeglib/jquant1.c irr/jpeglib/jquant2.c irr/jpeglib/jutils.c irr/jpeglib/jcarith.c irr/jpeglib/jdarith.c irr/jpeglib/jaricom.c
LIBPNGOBJ = irr/libpng/png.c irr/libpng/pngerror.c irr/libpng/pngget.c irr/libpng/pngmem.c irr/libpng/pngpread.c irr/libpng/pngread.c irr/libpng/pngrio.c irr/libpng/pngrtran.c irr/libpng/pngrutil.c irr/libpng/pngset.c irr/libpng/pngtrans.c irr/libpng/pngwio.c irr/libpng/pngwrite.c irr/libpng/pngwtran.c irr/libpng/pngwutil.c
LIBAESGM = irr/aesGladman/aescrypt.cpp irr/aesGladman/aeskey.cpp irr/aesGladman/aestab.cpp irr/aesGladman/fileenc.cpp irr/aesGladman/hmac.cpp irr/aesGladman/prng.cpp irr/aesGladman/pwd2key.cpp irr/aesGladman/sha1.cpp irr/aesGladman/sha2.cpp
BZIP2OBJ = irr/bzip2/blocksort.c irr/bzip2/huffman.c irr/bzip2/crctable.c irr/bzip2/randtable.c irr/bzip2/bzcompress.c irr/bzip2/decompress.c irr/bzip2/bzlib.c
ANDROID = importgl.cpp app-android.cpp android-activity.cpp android-receiver.cpp irr/CIrrDeviceAndroid.cpp

APP_STL := gnustl_static

LOCAL_CPP_EXTENSION := .cpp .cc

LOCAL_MODULE := irrlicht

LOCAL_ARM_MODE   := arm 
LOCAL_CFLAGS := -O3 -DANDROID_NDK -DDISABLE_IMPORTGL -I/home/userr/ProyectosActuales/IrrlichtTest/include -I/home/userr/ProyectosActuales/IrrlichtTest/jni/Fighter/include -I/home/userr/ProyectosActuales/IrrlichtTest/jni/engine/utilities/tinyxml
LOCAL_SRC_FILES := \
     $(ANDROID) \
     $(IRRVIDEOOBJ) \
     $(IRRMESHOBJ) $(IRROBJ) $(IRRPARTICLEOBJ) $(IRRANIMOBJ) \
     $(IRRSWRENDEROBJ) $(IRRIOOBJ) $(IRROTHEROBJ) \
     $(IRRGUIOBJ) $(ZLIBOBJ) $(JPEGLIBOBJ) $(LIBPNGOBJ) $(LIBAESGM) \
     $(BZIP2OBJ) $(TINYXMLOBJ)  $(FIGHTEROBJ)


LOCAL_LDLIBS := -lGLESv1_CM -ldl -llog

include $(BUILD_SHARED_LIBRARY)
