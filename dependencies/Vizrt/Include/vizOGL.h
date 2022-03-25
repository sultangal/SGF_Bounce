/*! @file
 * @brief this file is part of the plugin library.
 *
 * these function declarations are for vizrt internal use only.
 * their sole purpose is the forwarding of OpenGL calls through
 * the viz engine.
 */

/* ============================================================================= *
 *                                                                               *
 *  Copyright 2006,2013 Vizrt Austria GmbH                                       *
 *  All Rights Reserved.                                                         *
 *                                                                               *
 *  This is PROPRIETARY SOURCE CODE ofVizrt Austria GmbH;                        *
 *  the contents of this file may not be disclosed to third parties, copied or   *
 *  duplicated in any form, in whole or in part, without the prior written       *
 *  permission of Vizrt Austria GmbH                                             *
 *                                                                               *
 * ============================================================================= */

/*  CAUTION:
 *  --------
 *  This file contains no user-modifiable data
 *  Under no circumstances change anything in this file without an
 *  explicit order from Vizrt Austria GmbH
 *
 */

#ifndef __vizOGLAccess_h__
#define __vizOGLAccess_h__


#include "evPlugin_DynInterface.h"

#include <GL/gl.h>
#include <GL/glu.h>



#ifdef __cplusplus
extern "C" {
#endif
    #define VIZGLFUNC(v)    vizGL_##v

    VIZENGINE_API void VIZGLFUNC(glAccum) (GLenum, GLfloat);
    VIZENGINE_API void VIZGLFUNC(glAlphaFunc) (GLenum, GLclampf);
    VIZENGINE_API void VIZGLFUNC(glArrayElement) (GLenum);
    VIZENGINE_API void VIZGLFUNC(glBegin) (GLenum);
    VIZENGINE_API void VIZGLFUNC(glBindTexture) (GLenum, GLuint);
    VIZENGINE_API void VIZGLFUNC(glBindBuffer) (GLenum, GLuint);
    VIZENGINE_API void VIZGLFUNC(glBufferData) (GLenum, GLsizei, const GLvoid*, GLenum);
    VIZENGINE_API void VIZGLFUNC(glBitmap) (GLsizei, GLsizei, GLfloat, GLfloat, GLfloat, GLfloat, const GLubyte*);
    VIZENGINE_API void VIZGLFUNC(glBlendFunc) (GLenum, GLenum);
    VIZENGINE_API void VIZGLFUNC(glBlendFuncSeparateEXT) (GLenum, GLenum, GLenum, GLenum);
    VIZENGINE_API void VIZGLFUNC(glBlendEquationEXT) (int);
    VIZENGINE_API void VIZGLFUNC(glCallList) (GLuint);
    VIZENGINE_API void VIZGLFUNC(glCallLists) (GLsizei, GLenum, const GLvoid*);
    VIZENGINE_API void VIZGLFUNC(glClear) (GLbitfield);
    VIZENGINE_API void VIZGLFUNC(glClearAccum) (GLfloat, GLfloat, GLfloat, GLfloat);
    VIZENGINE_API void VIZGLFUNC(glClearColor) (GLclampf, GLclampf, GLclampf, GLclampf);
    VIZENGINE_API void VIZGLFUNC(glClearDepth) (GLclampd);
    VIZENGINE_API void VIZGLFUNC(glClearStencil) (GLint);
    VIZENGINE_API void VIZGLFUNC(glClipPlane)(GLenum, const GLdouble*);
    VIZENGINE_API void VIZGLFUNC(glClientActiveTexture) (int unit);
    VIZENGINE_API void VIZGLFUNC(glColor3ub) (GLubyte, GLubyte, GLubyte);
    VIZENGINE_API void VIZGLFUNC(glColor4ub) (GLubyte, GLubyte, GLubyte, GLubyte);
    VIZENGINE_API void VIZGLFUNC(glColor3f) (GLfloat, GLfloat, GLfloat);
    VIZENGINE_API void VIZGLFUNC(glColor4f) (GLfloat, GLfloat, GLfloat, GLfloat);
    VIZENGINE_API void VIZGLFUNC(glColor3fv) (const GLfloat*);
    VIZENGINE_API void VIZGLFUNC(glColor4fv) (const GLfloat*);
    VIZENGINE_API void VIZGLFUNC(glColor4ubv) (const GLubyte*);
    VIZENGINE_API void VIZGLFUNC(glColorMask) (GLboolean, GLboolean, GLboolean, GLboolean);
    VIZENGINE_API void VIZGLFUNC(glColorMaterial) (GLenum, GLenum);
    VIZENGINE_API void VIZGLFUNC(glColorPointer) (GLint, GLenum, GLsizei, const GLvoid*);
    VIZENGINE_API void VIZGLFUNC(glCopyTexSubImage2D) (GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
    VIZENGINE_API void VIZGLFUNC(glDeleteLists) (GLuint, GLsizei);
    VIZENGINE_API void VIZGLFUNC(glDeleteTextures) (GLsizei, const GLuint*);
    VIZENGINE_API void VIZGLFUNC(glDeleteBuffers) (GLsizei, const GLuint*);
    VIZENGINE_API void VIZGLFUNC(glDepthFunc) (GLenum);
    VIZENGINE_API void VIZGLFUNC(glDepthRange) (GLclampd, GLclampd);
    VIZENGINE_API void VIZGLFUNC(glDepthMask) (GLboolean);
    VIZENGINE_API void VIZGLFUNC(glDisable) (GLenum);
    VIZENGINE_API void VIZGLFUNC(glDisableClientState) (GLenum);
    VIZENGINE_API void VIZGLFUNC(glDrawArrays) (GLenum, GLint, GLsizei);
    VIZENGINE_API void VIZGLFUNC(glDrawBuffer) (GLenum);
    VIZENGINE_API void VIZGLFUNC(glDrawElements) (GLenum, GLsizei, GLenum, const GLvoid*);
    VIZENGINE_API void VIZGLFUNC(glDrawPixels) (GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
    VIZENGINE_API void VIZGLFUNC(glEnable) (GLenum);
    VIZENGINE_API void VIZGLFUNC(glEnableClientState) (GLenum);
    VIZENGINE_API void VIZGLFUNC(glEnd) ();
    VIZENGINE_API void VIZGLFUNC(glEndList) ();
    VIZENGINE_API void VIZGLFUNC(glFinish) ();
    VIZENGINE_API void VIZGLFUNC(glFlush) ();
    VIZENGINE_API void VIZGLFUNC(glFrontFace) (GLenum);
    VIZENGINE_API GLboolean VIZGLFUNC(glIsList) (GLuint);
    VIZENGINE_API GLboolean VIZGLFUNC(glIsTexture) (GLuint);
    VIZENGINE_API GLuint VIZGLFUNC(glGenLists) (GLsizei);
    VIZENGINE_API void VIZGLFUNC( glGenTextures ) (GLsizei, GLuint*);
    VIZENGINE_API void VIZGLFUNC( glGenBuffers ) (GLsizei, GLuint*);
    VIZENGINE_API GLenum VIZGLFUNC(glGetError) (void);
    VIZENGINE_API void VIZGLFUNC( glGetIntegerv ) (GLenum, GLint*);
    VIZENGINE_API void VIZGLFUNC( glGetFloatv ) (GLenum, GLfloat*);
    VIZENGINE_API void VIZGLFUNC(glGetTexImage) (GLenum, GLint, GLenum, GLenum, GLvoid*);
    VIZENGINE_API void VIZGLFUNC(glGetTexLevelParameteriv) (GLenum, GLint, GLenum, GLint*);
    VIZENGINE_API const GLubyte* VIZGLFUNC(glGetString) (GLenum);
    VIZENGINE_API void VIZGLFUNC(glHint) (GLenum, GLenum);
    VIZENGINE_API void VIZGLFUNC(glLightf) (GLenum, GLenum, GLfloat);
    VIZENGINE_API void VIZGLFUNC(glLightfv) (GLenum, GLenum, const GLfloat*);
    VIZENGINE_API void VIZGLFUNC(glLightModel) (GLenum, GLfloat);
    VIZENGINE_API void VIZGLFUNC(glLineStipple) (GLint, GLushort);
    VIZENGINE_API void VIZGLFUNC(glLineWidth) (GLfloat);
    VIZENGINE_API void VIZGLFUNC(glListBase) (GLuint);
    VIZENGINE_API void VIZGLFUNC(glLoadIdentity) ();
    VIZENGINE_API void VIZGLFUNC(glLoadMatrixf) (const GLfloat*);
    VIZENGINE_API void VIZGLFUNC(glLogicOp) (GLenum);
    VIZENGINE_API void VIZGLFUNC(glMaterialfv) (GLenum, GLenum, const GLfloat*);
    VIZENGINE_API void VIZGLFUNC(glMatrixMode) (GLenum);
    VIZENGINE_API void VIZGLFUNC(glMultMatrixf) (const GLfloat*);
    VIZENGINE_API void VIZGLFUNC(glNewList) (GLuint, GLenum);
    VIZENGINE_API void VIZGLFUNC(glNormal3f) (GLfloat, GLfloat, GLfloat);
    VIZENGINE_API void VIZGLFUNC(glNormal3sv) (const GLshort*);
    VIZENGINE_API void VIZGLFUNC(glNormalPointer) (GLenum, GLsizei, const GLvoid*);
    VIZENGINE_API void VIZGLFUNC(glPixelStorei) (GLenum, GLint);
    VIZENGINE_API void VIZGLFUNC(glPixelZoom) (GLfloat, GLfloat);
    VIZENGINE_API void VIZGLFUNC(glPointSize) (GLfloat);
    VIZENGINE_API void VIZGLFUNC(glPolygonMode) (GLenum, GLenum);
    VIZENGINE_API void VIZGLFUNC(glPopMatrix) ();
    VIZENGINE_API void VIZGLFUNC(glPushMatrix) ();
    VIZENGINE_API void VIZGLFUNC(glPushName) (GLuint);
    VIZENGINE_API void VIZGLFUNC(glPopName) ();
    VIZENGINE_API void VIZGLFUNC(glInitNames) ();
    VIZENGINE_API void VIZGLFUNC(glRasterPos2d) (GLdouble, GLdouble);
    VIZENGINE_API void VIZGLFUNC(glRasterPos2dv) (const GLdouble*);
    VIZENGINE_API void VIZGLFUNC(glRasterPos2f) (GLfloat, GLfloat);
    VIZENGINE_API void VIZGLFUNC(glRasterPos2i) (GLint, GLint);
    VIZENGINE_API void VIZGLFUNC(glRasterPos3f) (GLfloat, GLfloat, GLfloat);
    VIZENGINE_API void VIZGLFUNC(glReadBuffer) (GLenum);
    VIZENGINE_API void VIZGLFUNC(glReadPixels) (GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLvoid*);
    VIZENGINE_API void VIZGLFUNC(glRectf) (GLfloat, GLfloat, GLfloat, GLfloat);
    VIZENGINE_API void VIZGLFUNC(glRotatef) (GLfloat, GLfloat, GLfloat, GLfloat);
    VIZENGINE_API void VIZGLFUNC(glSampleMask) (GLfloat, GLboolean);
    VIZENGINE_API void VIZGLFUNC(glScalef) (GLfloat, GLfloat, GLfloat);
    VIZENGINE_API void VIZGLFUNC(glScissor) (GLint, GLint, GLsizei, GLsizei);
    VIZENGINE_API void VIZGLFUNC(glShadeModel) (GLenum);
    VIZENGINE_API void VIZGLFUNC(glStencilFunc) (GLenum, GLint, GLuint);
    VIZENGINE_API void VIZGLFUNC(glStencilMask) (GLuint);
    VIZENGINE_API void VIZGLFUNC(glStencilOp) (GLenum, GLenum, GLenum);
    VIZENGINE_API void VIZGLFUNC(glTexCoord2f) (GLfloat, GLfloat);
    VIZENGINE_API void VIZGLFUNC(glTexCoord2fv) (const GLfloat*);
    VIZENGINE_API void VIZGLFUNC(glTexCoord2sv) (const GLshort*);
    VIZENGINE_API void VIZGLFUNC(glTexCoord2s) (GLshort, GLshort);
    VIZENGINE_API void VIZGLFUNC(glTexCoordPointer) (GLint, GLenum, GLsizei, const GLvoid*);
    VIZENGINE_API void VIZGLFUNC(glTexEnvfv) (GLenum, GLenum, const GLfloat*);
    VIZENGINE_API void VIZGLFUNC(glGetTexEnvfv) (GLenum, GLenum, GLfloat*);
    VIZENGINE_API void VIZGLFUNC(glGetTexEnviv) (GLenum, GLenum, GLint*);
    VIZENGINE_API void VIZGLFUNC(glTexEnvf) (GLenum, GLenum, GLfloat);
    VIZENGINE_API void VIZGLFUNC(glTexEnvi) (GLenum, GLenum, GLint);
    VIZENGINE_API void VIZGLFUNC(glTexGenfv) (GLenum, GLenum, const GLfloat*);
    VIZENGINE_API void VIZGLFUNC(glTexGeni) (GLenum, GLenum, GLint);
    VIZENGINE_API void VIZGLFUNC(glTexImage2D) (GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid*);
    VIZENGINE_API void VIZGLFUNC(glTexImage3D) (GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid*);
    VIZENGINE_API void VIZGLFUNC(glTexParameterf) (GLenum, GLenum, GLfloat);
    VIZENGINE_API void VIZGLFUNC(glTexParameterfv) (GLenum, GLenum, GLfloat*);
    VIZENGINE_API void VIZGLFUNC(glTexParameteri) (GLenum, GLenum, GLint);
    VIZENGINE_API void VIZGLFUNC(glTexParameteriv) (GLenum, GLenum, GLint*);
    VIZENGINE_API void VIZGLFUNC(glTexSubImage2D) (GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
    VIZENGINE_API void VIZGLFUNC(glTranslatef) (GLfloat, GLfloat, GLfloat);
    VIZENGINE_API void VIZGLFUNC(glVertex2f) (GLfloat, GLfloat);
    VIZENGINE_API void VIZGLFUNC(glVertex2i) (GLint, GLint);
    VIZENGINE_API void VIZGLFUNC(glVertex3f) (GLfloat, GLfloat, GLfloat);
    VIZENGINE_API void VIZGLFUNC(glVertex3fv) (const GLfloat*);
    VIZENGINE_API void VIZGLFUNC(glVertexPointer) (GLint, GLenum, GLsizei, const GLvoid*);
    VIZENGINE_API void VIZGLFUNC(glViewport) (GLint, GLint, GLsizei, GLsizei);
    VIZENGINE_API void VIZGLFUNC(glPopAttrib) ();
    VIZENGINE_API void VIZGLFUNC(glPushAttrib) (GLbitfield);
    VIZENGINE_API void VIZGLFUNC(glEnableClientState) (GLenum);
    VIZENGINE_API void VIZGLFUNC(glDisableClientState) (GLenum);
    VIZENGINE_API void VIZGLFUNC(glDrawElements) (GLenum, GLsizei, GLenum, const GLvoid*);
    VIZENGINE_API void VIZGLFUNC(glActiveTexture) (int unit);
    VIZENGINE_API void VIZGLFUNC(glClientActiveTexture) (int unit);
    VIZENGINE_API GLint VIZGLFUNC( glGetUniformLocationARB ) (GLuint, const char*);
    VIZENGINE_API void VIZGLFUNC( glUniform1i ) (GLint, GLint);
    VIZENGINE_API void VIZGLFUNC(glUniform1f) (GLint, GLfloat);
    VIZENGINE_API void VIZGLFUNC(glUniform1fv) (GLint, GLint, GLfloat*);
    VIZENGINE_API void VIZGLFUNC(glUniform2f) (GLint, GLfloat, GLfloat);
    VIZENGINE_API void VIZGLFUNC( glUniform2fv ) (GLint, GLint, GLfloat*);
    VIZENGINE_API void VIZGLFUNC(glUniform3f) (GLint, GLfloat, GLfloat, GLfloat);
    VIZENGINE_API void VIZGLFUNC( glUniform3fv ) (GLint, GLint, GLfloat*);
    VIZENGINE_API void VIZGLFUNC(glUniform4f) (GLint, GLfloat, GLfloat, GLfloat, GLfloat);
    VIZENGINE_API void VIZGLFUNC( glUniform4fv ) (GLint, GLint, GLfloat*);
    VIZENGINE_API void VIZGLFUNC(glUniformMatrix4fv) (GLint, GLsizei, GLboolean, GLfloat* );
    VIZENGINE_API void VIZGLFUNC(glAttachShader) (GLuint, GLuint);
    VIZENGINE_API void VIZGLFUNC(glDetachShader) (GLuint, GLuint);
    VIZENGINE_API GLuint VIZGLFUNC( glCreateProgram ) ();
    VIZENGINE_API void VIZGLFUNC( glDeleteProgram ) (GLuint);
    VIZENGINE_API void VIZGLFUNC(glLinkProgram) (GLuint);
    VIZENGINE_API void VIZGLFUNC(glUseProgram) (GLuint);
    VIZENGINE_API GLuint VIZGLFUNC(glCreateShader) (GLenum);
    VIZENGINE_API void VIZGLFUNC( glDeleteShader ) (GLuint);
    VIZENGINE_API void VIZGLFUNC( glShaderSourceARB ) (GLuint, GLsizei, const char**, const GLint*);
    VIZENGINE_API void VIZGLFUNC(glCompileShader) (GLuint);
    VIZENGINE_API void VIZGLFUNC(glGetShaderiv)(GLuint, GLenum, GLint* );
    VIZENGINE_API void VIZGLFUNC(glGetShaderInfoLog)(GLuint, GLsizei, GLsizei*, char*);
    VIZENGINE_API void VIZGLFUNC(glProgramParameteriEXT)(GLuint, GLenum, GLint);
    VIZENGINE_API void VIZGLFUNC(glGetProgramiv)(GLuint, GLenum, GLint*);
    VIZENGINE_API void VIZGLFUNC(glGetProgramInfoLog)(GLuint, GLsizei, GLsizei*, char*);
    VIZENGINE_API void VIZGLFUNC(glGenRenderbuffersEXT)(GLsizei, GLuint*);
    VIZENGINE_API void VIZGLFUNC(glDeleteRenderbuffersEXT)(GLsizei, GLuint*);
    VIZENGINE_API void VIZGLFUNC(glBindRenderbufferEXT)(GLenum, GLuint);
    VIZENGINE_API void VIZGLFUNC(glRenderbufferStorageEXT)(GLenum, GLenum, GLsizei, GLsizei);
    VIZENGINE_API void* VIZGLFUNC(glMapBuffer)(GLenum, GLenum);
    VIZENGINE_API void VIZGLFUNC(glUnmapBuffer)(GLenum);


    VIZENGINE_API int VIZGLFUNC(gluBuild2DMipmaps) (GLenum, GLint, GLint, GLint, GLenum, GLenum, const void*);
    VIZENGINE_API void VIZGLFUNC(gluDeleteTess) (GLUtesselator*);
    VIZENGINE_API const GLubyte* VIZGLFUNC(gluErrorString) (GLenum);
    VIZENGINE_API GLUquadric* VIZGLFUNC(gluNewQuadric) ();
    VIZENGINE_API GLUtesselator* VIZGLFUNC(gluNewTess) ();
    VIZENGINE_API void VIZGLFUNC(gluOrtho2D) (GLdouble, GLdouble, GLdouble, GLdouble);
    VIZENGINE_API void VIZGLFUNC(gluPerspective) (GLdouble, GLdouble, GLdouble, GLdouble);
    VIZENGINE_API void VIZGLFUNC(gluQuadricDrawStyle) (GLUquadric*, GLenum);
    VIZENGINE_API int VIZGLFUNC(gluScaleImage) (GLenum, GLint, GLint, GLenum, const void*, GLint, GLint, GLenum, void*);
    VIZENGINE_API void VIZGLFUNC(gluSphere) (GLUquadric*, GLdouble, GLint, GLint);
    VIZENGINE_API void VIZGLFUNC(gluTessBeginContour) (GLUtesselator*);
    VIZENGINE_API void VIZGLFUNC(gluTessBeginPolygon) (GLUtesselator*, void*);
    VIZENGINE_API void VIZGLFUNC(gluTessCallback) (GLUtesselator*, GLenum, void (__stdcall *)());
    VIZENGINE_API void VIZGLFUNC(gluTessEndContour) (GLUtesselator*);
    VIZENGINE_API void VIZGLFUNC(gluTessEndPolygon) (GLUtesselator*);
    VIZENGINE_API void VIZGLFUNC(gluTessVertex) (GLUtesselator*, GLdouble*, void*);
    VIZENGINE_API int VIZGLFUNC(gluUnProject) (GLdouble, GLdouble, GLdouble, const GLdouble*, const GLdouble*, const GLint*, GLdouble*, GLdouble*, GLdouble*);
    VIZENGINE_API int VIZGLFUNC(gluProject) (GLdouble, GLdouble, GLdouble, const GLdouble*, const GLdouble*, const GLint*, GLdouble*, GLdouble*, GLdouble*);
#ifdef __cplusplus
};
#endif

#endif
