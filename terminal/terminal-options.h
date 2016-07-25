/*-
 * Copyright (c) 2004-2008 os-cillation e.K.
 *
 * Written by Benedikt Meurer <benny@xfce.org>.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __TERMINAL_OPTIONS_H__
#define __TERMINAL_OPTIONS_H__

#include <glib.h>

G_BEGIN_DECLS

typedef struct _TerminalTabAttr    TerminalTabAttr;
typedef struct _TerminalWindowAttr TerminalWindowAttr;
typedef enum   _TerminalVisibility TerminalVisibility;
typedef enum   _TerminalZoomLevel  TerminalZoomLevel;

enum _TerminalVisibility
{
  TERMINAL_VISIBILITY_DEFAULT,
  TERMINAL_VISIBILITY_SHOW,
  TERMINAL_VISIBILITY_HIDE
};

enum _TerminalZoomLevel
{
  TERMINAL_ZOOM_LEVEL_XXX_SMALL = -4,
  TERMINAL_ZOOM_LEVEL_XX_SMALL  = -3,
  TERMINAL_ZOOM_LEVEL_X_SMALL   = -2,
  TERMINAL_ZOOM_LEVEL_SMALL     = -1,
  TERMINAL_ZOOM_LEVEL_MEDIUM    = 0,
  TERMINAL_ZOOM_LEVEL_LARGE     = +1,
  TERMINAL_ZOOM_LEVEL_X_LARGE   = +2,
  TERMINAL_ZOOM_LEVEL_XX_LARGE  = +3,
  TERMINAL_ZOOM_LEVEL_XXX_LARGE = +4,
  TERMINAL_ZOOM_LEVEL_MINIMUM   = TERMINAL_ZOOM_LEVEL_XXX_SMALL,
  TERMINAL_ZOOM_LEVEL_MAXIMUM   = TERMINAL_ZOOM_LEVEL_XXX_LARGE,
  TERMINAL_ZOOM_LEVEL_DEFAULT   = TERMINAL_ZOOM_LEVEL_MEDIUM,
};

struct _TerminalTabAttr
{
  gchar    **command;
  gchar     *directory;
  gchar     *title;
  guint      hold : 1;
};

struct _TerminalWindowAttr
{
  GSList              *tabs;
  guint                drop_down : 1;
  gchar               *display;
  gchar               *geometry;
  gchar               *role;
  gchar               *startup_id;
  gchar               *sm_client_id;
  gchar               *icon;
  gchar               *font;
  guint                fullscreen : 1;
  TerminalVisibility   menubar;
  TerminalVisibility   borders;
  TerminalVisibility   toolbar;
  TerminalZoomLevel    zoom;
  guint                maximize : 1;
  guint                reuse_last_window : 1;
};

void                terminal_options_parse     (gint                 argc,
                                                gchar              **argv,
                                                gboolean            *show_help,
                                                gboolean            *show_version,
                                                gboolean            *show_colors,
                                                gboolean            *disable_server);

GSList             *terminal_window_attr_parse (gint                 argc,
                                                gchar              **argv,
                                                gboolean             can_reuse_tab,
                                                GError             **error);

TerminalWindowAttr *terminal_window_attr_new   (void);

void                terminal_window_attr_free  (TerminalWindowAttr  *attr);

G_END_DECLS

#endif /* !__TERMINAL_OPTIONS_H__ */
