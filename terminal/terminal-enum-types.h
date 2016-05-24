


#ifndef __TERMINAL_ENUM_TYPES_H__
#define __TERMINAL_ENUM_TYPES_H__
#include <gtk/gtk.h>
G_BEGIN_DECLS
/* enumerations from "terminal-preferences.h" */
GType terminal_scrollbar_get_type (void);
#define TERMINAL_TYPE_SCROLLBAR (terminal_scrollbar_get_type())
GType terminal_title_get_type (void);
#define TERMINAL_TYPE_TITLE (terminal_title_get_type())
GType terminal_background_get_type (void);
#define TERMINAL_TYPE_BACKGROUND (terminal_background_get_type())
GType terminal_background_style_get_type (void);
#define TERMINAL_TYPE_BACKGROUND_STYLE (terminal_background_style_get_type())
GType terminal_erase_binding_get_type (void);
#define TERMINAL_TYPE_ERASE_BINDING (terminal_erase_binding_get_type())
GType terminal_cursor_shape_get_type (void);
#define TERMINAL_TYPE_CURSOR_SHAPE (terminal_cursor_shape_get_type())
G_END_DECLS

#endif /* !__TERMINAL_ENUM_TYPES_H__ */



