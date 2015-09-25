#ifndef UIPUSHBUTTON_GLOBAL_H
#define UIPUSHBUTTON_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(UIPUSHBUTTON_LIBRARY)
#  define UIPUSHBUTTONSHARED_EXPORT Q_DECL_EXPORT
#else
#  define UIPUSHBUTTONSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // UIPUSHBUTTON_GLOBAL_H
#include <QPushButton>
